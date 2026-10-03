#!/usr/bin/env python3
"""Render Pokemon Stadium's Numus songs to WAV (or MIDI) without the game.

Timing: the player advances `channel_frame` by `channel_tempo` every vsync and
a note occupies `duration << 8` of those units (src/libnumus/player.c:1598,
1792), with `channel_tempo = arg * 0x6000 / 120 / 60`.  That reduces to
`seconds = 1.25 * duration / arg`, so `tempo` is BPM and a quarter note is 48
ticks, just like MIDI.

`tempo` is a *song-wide* command: Ftempo walks every channel sharing the
song (line 132), and in practice only channel 0 ever issues one.  So the walk
runs in ticks and the tempo map is merged across all channels before anything
is converted to seconds. Do it per channel and every channel but the first
plays at the wrong speed.

Pitch: MusBankInitialize (line 2147) rewrites each `detune` entry in place as
`s8/100 + (basenote - 0x30)`, and a note plays at `2 ^ ((detune[wave] + note +
transpose) / 12)` times the sample rate, clamped to 2.0 (line 1859).

Volume and pitchbend ride their own streams, one entry per duration tick
(__MusIntProcessContinuousVolume / ...PitchBend, lines 2048 and 2077): a byte
below 0x80 sets the value for one tick, one at or above 0x80 sets it and is
followed by a repeat count.  Most songs leave `volume` at 0 and drive it
entirely from that stream, so without it they render silent.  Pitchbend is
`value - 64` in 1/32 semitone steps.

Envelope: the 7-byte `defa` record (attack, decay, sustain, release). The
speeds are counted in *ticks*, not vsync frames: __MusIntProcessEnvelope
(line 1910) measures elapsed time as `(channel_frame - note_start) >> 8`, the
same unit note durations use, and the release scales by the tempo as well
(line 1918). Treat them as frames and every envelope is stretched by BPM/75. 
How long a note actually sounds is not its duration:
__MusIntInitEnvelope (line 1888) releases at `note_start + cutoff` when
`cutoff` is set, else at `note_end - endit`.  Without that every note rings
until the next one and the mix loses its dynamics.

Not modelled: vibrato, wobble, sweep, portamento, distortion, reverb and drum
redirection.  The result is the arrangement with the game's own samples, not a
bit-exact capture of the RSP mixer.

usage:
  python3 tools/audio/render_mus.py -n 11              # song 11 from the ROM
  python3 tools/audio/render_mus.py --song edited.bin  # preview a song file
  python3 tools/audio/render_mus.py -n 11 --midi       # MIDI instead of WAV
"""

import argparse
import math
import struct
import sys
import wave
from pathlib import Path

from mus_seq import (ARCHIVE1, COMMANDS, archive_files, decompress, fx_blobs,
                     parse_fx, parse_song, songs, varint)
from numus_audio import decode_frames

RATE = 32000                    # synth output rate (src/373A0.c config)
PPQ = 48                        # ticks per quarter note
DEFAULT_TEMPO = 120
DEFAULT_SECONDS = 90
FRAME = 1 / 60                  # one vsync, the envelope's time unit
OUT = Path("build/assets/audio/SEQ/render")


class Bank:
    """An expanded Numus bank plus its wave-table bytes, decoded on demand."""

    def __init__(self, img, waves):
        self.img = img
        self.waves = waves
        self.count = struct.unpack_from(">I", img, 0x20)[0]
        basenote, detune, wave_list = struct.unpack_from(">III", img, 0x24)
        self.detune = [self._s8(img[detune + 4 * i]) / 100.0
                       + self._s8(img[basenote + i]) - 0x30
                       for i in range(self.count)]
        self.descs = list(struct.unpack_from(">%dI" % self.count, img, wave_list))
        self.cache = {}

    @staticmethod
    def _s8(v):
        return v - 0x100 if v & 0x80 else v

    def sample(self, wave):
        """(pcm, loop_start, loop_end) for one wave, decoded once."""
        if wave not in self.cache:
            desc = self.descs[wave]
            base, length = struct.unpack_from(">II", self.img, desc)
            loop_off, book_off = struct.unpack_from(">II", self.img, desc + 0x0C)
            order, npred = struct.unpack_from(">ii", self.img, book_off)
            book = list(struct.unpack_from(">%dh" % min(order * npred * 16, 64),
                                           self.img, book_off + 8))
            data = self.waves[base & 0x00FFFFFF:(base & 0x00FFFFFF) + length]
            pcm = decode_frames(book, data, wrap_out=False)
            loop = (-1, -1)
            if loop_off:
                start, end, _ = struct.unpack_from(">III", self.img, loop_off)
                if start != 0xFFFFFFFF:
                    loop = (start, end)
            self.cache[wave] = (pcm, loop[0], loop[1])
        return self.cache[wave]


def rom_bank(rom):
    """The BGM bank every song in archive 1 plays through.

    Its wave-table region runs from `wave_tables_offset` to the first song --
    0xE9BD0 bytes, far past any fixed guess."""
    file0, waves, offs = archive_files(rom, ARCHIVE1)
    return Bank(decompress(rom, file0), rom[waves:offs[0]])


def fx_bank(rom, blob, cache={}):
    """The sample bank an fx bank plays through -- its package's, not BGM's."""
    key = blob["bank"]
    if key not in cache:
        cache[key] = Bank(decompress(rom, blob["bank"]),
                          rom[blob["waves"]:blob["waves_end"]])
    return cache[key]


class Continuous:
    """A volume or pitchbend stream: one value per duration tick, run-length
    coded (src/libnumus/player.c:2048)."""

    def __init__(self, img, start, bend=False):
        self.img = img
        self.pos = start
        self.bend = bend
        self.value = 0.0
        self.left = 0              # ticks the current value still covers
        self.live = bool(start)

    def advance(self, ticks):
        """Step the stream `ticks` entries on and return the value there."""
        if not self.live:
            return None
        for _ in range(ticks):
            self.left -= 1
            if self.left > 0:
                continue
            if self.pos >= len(self.img):
                self.live = False
                break
            tmp = self.img[self.pos]
            self.pos += 1
            self.value = (tmp & 0x7F) if tmp >= 0x80 else tmp
            if self.bend:
                self.value -= 64.0
            if tmp < 0x80:
                self.left = 1
                continue
            tmp = self.img[self.pos]
            self.pos += 1
            if tmp >= 0x80:
                self.left = ((tmp & 0x7F) << 8) + self.img[self.pos] + 2
                self.pos += 1
            else:
                self.left = tmp + 2
        return self.value

    def state(self):
        return (self.pos, self.value, self.left, self.live)

    def restore(self, saved):
        self.pos, self.value, self.left, self.live = saved


def events(img, start, end, env_table, tick_cap, volume_at=0, bend_at=0):
    """Run one channel, yielding (time, wave, note, velocity, duration_s,
    volume, pan, envelope).  Time is in seconds, so tempo changes mid-song
    land in the right place."""
    out = []
    tick = 0
    tempos = []                 # (tick, bpm), merged song-wide by the caller
    pos = start
    velocity_on = False
    velocity = 127
    fixed_length = 0
    ignore = False
    transpose = 0
    cutoff = 0                  # gate from the note start, in ticks
    endit = 0                   # or trim this much off its end
    wave_index = 0
    volume = 127
    pan = 64
    envelope = None
    stack = []
    vol_stream = Continuous(img, volume_at)
    bend_stream = Continuous(img, bend_at, bend=True)
    if vol_stream.live:
        volume = vol_stream.advance(1)
    while pos < end and tick < tick_cap:
        b = img[pos]
        if b >= 0x80:
            name, width = COMMANDS[b & 0x7F]
            pos += 1
            if name is None or name in ("stop", "goto"):
                break
            if width is None:
                value, pos = varint(img, pos)
                args = [value]
            else:
                args = list(img[pos:pos + width])
                pos += width
            if name == "velon":
                velocity_on = True
            elif name in ("veloff", "velocity"):
                velocity_on = False
                if name == "velocity":
                    velocity = args[0]
            elif name == "length":
                fixed_length = args[0]
            elif name == "ignore":
                ignore = True
            elif name == "trans":
                transpose = args[0] - 256 if args[0] > 127 else args[0]
            elif name == "cutoff":      # Fcutoff/Fendit each clear the other
                cutoff, endit = (args[0] << 8) | args[1], 0
            elif name == "endit":
                endit, cutoff = args[0], 0
            elif name == "tempo":
                tempos.append((tick, max(args[0], 1)))
            elif name == "wave":
                wave_index = args[0]
            elif name == "volume":
                volume = args[0]
            elif name == "pan":
                pan = args[0] // 2
            elif name == "defa":
                envelope = args
            elif name == "envelope" and env_table:
                envelope = list(img[env_table + 7 * args[0]:
                                    env_table + 7 * args[0] + 7])
            elif name == "for":
                stack.append([pos, 4 if args[0] == 0xFF else args[0],
                              vol_stream.state(), bend_stream.state()])
            elif name == "next" and stack:
                stack[-1][1] -= 1
                if stack[-1][1] > 0:
                    pos = stack[-1][0]
                    vol_stream.restore(stack[-1][2])    # Fnext rewinds these too
                    bend_stream.restore(stack[-1][3])
                else:
                    stack.pop()
            continue

        pos += 1
        if velocity_on:
            velocity = img[pos]
            pos += 1
        if fixed_length and not ignore:
            duration = fixed_length
        else:
            ignore = False
            duration, pos = varint(img, pos)
        streamed = vol_stream.advance(duration)
        bend = bend_stream.advance(duration)
        if b != 0x60:
            level = streamed * 2 if streamed is not None else volume
            note = b + transpose + (bend / 32.0 if bend is not None else 0.0)
            gate = cutoff if cutoff else max(duration - endit, 1)
            out.append((tick, wave_index, note, velocity, duration, gate,
                        level, pan, envelope))
        tick += duration
    return out, tick, tempos


def clock(tempos):
    """A tick -> seconds function for a merged song-wide tempo map."""
    points = [(0, 0.0, DEFAULT_TEMPO)]      # (tick, seconds at it, bpm from it)
    for tick, bpm in sorted(tempos):
        last_tick, last_secs, last_bpm = points[-1]
        if tick == last_tick:
            points[-1] = (tick, last_secs, bpm)
        else:
            points.append((tick, last_secs + 1.25 * (tick - last_tick) / last_bpm,
                           bpm))

    def at(tick):
        base_tick, base_secs, bpm = points[0]
        for point in points:
            if point[0] > tick:
                break
            base_tick, base_secs, bpm = point
        return base_secs + 1.25 * (tick - base_tick) / bpm
    return at


def in_seconds(channels, tempos, seconds_cap):
    """Convert tick-domain notes to seconds with one shared clock."""
    at = clock(tempos)
    out, end = [], 0.0
    for notes in channels:
        timed = []
        for tick, wave, note, velocity, duration, gate, level, pan, envelope in notes:
            time = at(tick)
            if time > seconds_cap:
                break
            # the envelope runs for the gate, but the timeline for the
            # duration; envelope speeds are ticks, so they scale with tempo
            timed.append((time, wave, note, velocity, at(tick + gate) - time,
                          level, pan, shape(envelope, at(tick + 1) - time)))
            end = max(end, at(tick + duration))
        out.append(timed)
    return out, end


def shape(envelope, seconds_per_tick):
    """defa = [speed, unused, attack, max, decay, sustain, release] -> the same
    envelope in seconds, given how long a tick lasts at this tempo."""
    if not envelope:
        return None
    _, _, attack, peak, decay, sustain, release = envelope[:7]
    return (max(attack, 1) * seconds_per_tick, peak / 255.0,
            max(decay, 1) * seconds_per_tick, sustain / 255.0,
            max(release, 1) * seconds_per_tick)


def envelope_gain(envelope, t, length):
    """Attack to peak, decay to sustain, hold, then release (phases 1-4)."""
    if not envelope:
        return 1.0 if t < length else 0.0
    attack, peak, decay, sustain, release = envelope
    if t < attack:
        return peak * t / attack
    if t < attack + decay:
        return peak + (sustain - peak) * (t - attack) / decay
    if t < length:
        return sustain
    left = t - length
    return sustain * max(0.0, 1.0 - left / release) if left < release else 0.0


def mix(channels, bank, duration, seconds_cap=DEFAULT_SECONDS):
    """Play every note of every channel into one stereo pair at RATE."""
    total = int(min(duration, seconds_cap) * RATE)
    left = [0.0] * total
    right = [0.0] * total
    for notes in channels:
        for time, wave, note, velocity, length, volume, pan, envelope in notes:
            if wave >= bank.count:
                continue
            pcm, loop_start, loop_end = bank.sample(wave)
            if not pcm:
                continue
            step = 2.0 ** ((bank.detune[wave] + note) / 12.0)
            if step > 2.0:
                continue                    # the player mutes these (line 1881)
            gain = (volume / 255.0) * (velocity / 127.0) * 0.25
            lgain = gain * (1.0 - pan / 127.0)
            rgain = gain * (pan / 127.0)
            tail = envelope[4] if envelope else 8 * FRAME
            start_at = int(time * RATE)
            count = int(min(length + tail, max(seconds_cap - time, 0.0)) * RATE)
            # a loop is only usable if the descriptor's points are inside the
            # decoded sample; several banks carry stale ones
            looped = 0 <= loop_start < loop_end <= len(pcm) - 1
            span = loop_end - loop_start if looped else 0
            last = (loop_end if looped else len(pcm) - 1) - 1
            position = 0.0
            for k in range(count):
                out = start_at + k
                if out >= total:
                    break
                if position >= last:
                    if not looped:
                        break
                    position = loop_start + (position - last) % span
                index = int(position)
                a = pcm[index]
                value = (a + (pcm[index + 1] - a) * (position - index)) / 32768.0
                value *= envelope_gain(envelope, k / RATE, length)
                left[out] += value * lgain
                right[out] += value * rgain
                position += step
    return left, right


def render(img, bank, seconds_cap=DEFAULT_SECONDS):
    """One expanded song image -> (left, right) float buffers at RATE."""
    song = parse_song(img)
    starts = sorted(set(o for o in song["data"] + song["volume"]
                        + song["pitchbend"] if o) | {len(img)})
    tick_cap = int(seconds_cap * 200)       # 200 ticks/s is past any real tempo
    channels, tempos = [], []
    for channel, start in enumerate(song["data"]):
        if not start:
            continue
        stop = min(b for b in starts if b > start)
        notes, _, found = events(img, start, stop, song["env_table"], tick_cap,
                                 song["volume"][channel], song["pitchbend"][channel])
        channels.append(notes)
        tempos += found
    timed, end_time = in_seconds(channels, tempos, seconds_cap)
    return mix(timed, bank, end_time + 2.0, seconds_cap)


def render_fx(img, bank, gap=0.25, seconds_cap=DEFAULT_SECONDS):
    """One fx bank -> its effects played back to back, `gap` seconds apart.

    An effect is a single channel stream, so they are laid out in sequence
    rather than mixed; auditioning a bank is the point."""
    fx = parse_fx(img)
    order = sorted(set(fx["sequences"]) | {len(img)})
    tick_cap = int(seconds_cap * 200)
    timed, time = [], 0.0
    for start in fx["sequences"]:
        stop = min(b for b in order if b > start)
        notes, played, tempos = events(img, start, stop, 0, tick_cap)
        # each effect carries its own tempo, so give each its own clock
        seconds, end = in_seconds([notes], tempos, seconds_cap)
        timed.append([(t + time,) + tuple(rest) for t, *rest in seconds[0]])
        time += end + gap
        if time > seconds_cap:
            break
    return mix(timed, bank, min(time + 1.0, seconds_cap), seconds_cap)


def write_wav(path, left, right):
    # the mix is deliberately quiet so summed channels never clip; normalise to
    # -1 dBFS at the end, which keeps the dynamics and spares you the volume knob
    peak = max(max(map(abs, left), default=0.0), max(map(abs, right), default=0.0))
    scale = (0.89 / peak) if peak else 1.0
    frames = bytearray()
    for l, r in zip(left, right):
        frames += struct.pack("<hh", int(max(-1.0, min(1.0, l * scale)) * 32767),
                              int(max(-1.0, min(1.0, r * scale)) * 32767))
    with wave.open(str(path), "wb") as w:
        w.setnchannels(2)
        w.setsampwidth(2)
        w.setframerate(RATE)
        w.writeframes(bytes(frames))


def varlen(value):
    """MIDI variable-length quantity."""
    out = bytearray([value & 0x7F])
    value >>= 7
    while value:
        out.insert(0, 0x80 | (value & 0x7F))
        value >>= 7
    return bytes(out)


def write_midi(path, img, seconds_cap):
    """The same walk, emitted as a type 1 MIDI file."""
    song = parse_song(img)
    starts = sorted(set(o for o in song["data"] + song["volume"]
                        + song["pitchbend"] if o) | {len(img)})
    tick_cap = int(seconds_cap * 200)
    walked, tempos = [], []
    for channel, start in enumerate(song["data"]):
        if not start:
            continue
        stop = min(b for b in starts if b > start)
        notes, _, found = events(img, start, stop, song["env_table"], tick_cap,
                                 song["volume"][channel], song["pitchbend"][channel])
        walked.append(notes)
        tempos += found
    tempo = tempos[0][1] if tempos else DEFAULT_TEMPO

    tracks = []
    for notes in walked:
        if not notes:
            continue
        port = (len(tracks)) % 16
        timed = []
        for tick, wave, note, velocity, duration, gate, _, _, _ in notes:
            note = int(round(note))
            if 0 <= note < 128:
                timed.append((tick, 0x90 | port, note, min(max(velocity, 1), 127)))
                timed.append((tick + gate, 0x80 | port, note, 0))
        timed.sort(key=lambda e: e[0])
        chunks, last = [], 0
        for tick, status, note, velocity in timed:
            chunks.append(varlen(tick - last) + bytes([status, note, velocity]))
            last = tick
        body = b"".join(chunks) + b"\x00\xFF\x2F\x00"
        tracks.append(b"MTrk" + struct.pack(">I", len(body)) + body)
    head = struct.pack(">I", int(60000000 / (tempo or DEFAULT_TEMPO)))[1:]
    meta = b"\x00\xFF\x51\x03" + head + b"\x00\xFF\x2F\x00"
    tracks.insert(0, b"MTrk" + struct.pack(">I", len(meta)) + meta)
    path.write_bytes(b"MThd" + struct.pack(">IHHH", 6, 1, len(tracks), PPQ)
                     + b"".join(tracks))


def song_name(index, offset, titles):
    """`NN_ADDR`, or `NN_Title` when a USF map supplied one."""
    title = titles.get(index)
    if not title:
        return "%02d_%08X" % (index, offset)
    title = title.split(" ", 1)[1] if title[:2].isdigit() else title  # drop the rip's own number
    safe = "".join(c if c.isalnum() or c in " -_" else "_" for c in title)
    return "%02d_%s" % (index, safe.strip().replace(" ", "_"))


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("-r", "--rom", default="baseroms/us/baserom.z64")
    ap.add_argument("-n", "--index", type=int, help="song index in archive 1")
    ap.add_argument("-s", "--song", help="an expanded song image instead (.bin)")
    ap.add_argument("-f", "--fx", type=int, metavar="N",
                    help="render fx bank N, its effects back to back")
    ap.add_argument("--all", action="store_true",
                    help="every song and every fx bank")
    ap.add_argument("-o", "--out", default=str(OUT))
    ap.add_argument("-t", "--seconds", type=float, default=DEFAULT_SECONDS)
    ap.add_argument("--midi", action="store_true", help="write MIDI, not WAV")
    ap.add_argument("--names", help="usf_map.py JSON, to name songs in the output")
    args = ap.parse_args()

    rom = Path(args.rom).read_bytes()
    bank = rom_bank(rom)
    titles = {}
    if args.names:
        import json
        titles = {e["index"]: e["title"]
                  for e in json.loads(Path(args.names).read_text(encoding="utf-8"))}
    out = Path(args.out)
    out.mkdir(parents=True, exist_ok=True)

    # (name, image, bank, is_fx); fx banks play through their own package's bank
    jobs = []
    if args.song:
        jobs = [(Path(args.song).stem, Path(args.song).read_bytes(), bank, False)]
    elif args.fx is not None:
        blob = fx_blobs(rom)[args.fx]
        jobs = [("fx%03d_%08X" % (args.fx, blob["offset"]),
                 decompress(rom, blob["offset"]), fx_bank(rom, blob), True)]
    elif args.index is not None:
        off = songs(rom)[args.index][0]
        jobs = [(song_name(args.index, off, titles),
                 decompress(rom, off), bank, False)]
    else:
        jobs = [(song_name(i, off, titles), decompress(rom, off), bank, False)
                for i, (off, _) in enumerate(songs(rom))]
        if args.all:
            for i, blob in enumerate(fx_blobs(rom)):
                jobs.append(("fx%03d_%08X" % (i, blob["offset"]),
                             decompress(rom, blob["offset"]),
                             fx_bank(rom, blob), True))

    for n, (name, img, job_bank, is_fx) in enumerate(jobs, 1):
        if args.midi:
            if is_fx:
                continue                    # MIDI export is songs only
            path = out / (name + ".mid")
            write_midi(path, img, args.seconds)
            print("[%d/%d] %s  (midi)" % (n, len(jobs), path.name))
            continue
        if is_fx:
            left, right = render_fx(img, job_bank, seconds_cap=args.seconds)
        else:
            left, right = render(img, job_bank, args.seconds)
        path = out / (name + ".wav")
        write_wav(path, left, right)
        print("[%d/%d] %s  %.1fs" % (n, len(jobs), path.name, len(left) / RATE))
    print("wrote %s" % out)


if __name__ == "__main__":
    sys.exit(main())
