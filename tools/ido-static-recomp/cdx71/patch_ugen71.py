#!/usr/bin/env python3
"""Add the u-code injection hook to the traced 7.1 ugen.

usage: patch_ugen71.py <build/7.1-traced/ugen.traced.c>   (edits the file in place)

Input is the output of `decomp-workbench instrument-ugen --emit-provenance` with the
7.1 addresses patched in (see build-traced.sh). The hook wraps f_readuinstr, ugen's
u-code reader, so a run can dump, overwrite, delete, insert or replace u-code records
before ugen's tree builder sees them. With no DKWB_U* variable set it is a pass-through
and the output is byte-identical to the stock ugen (see gate.sh).

Record layout as read into ugen's buffer (32 bytes for every non-string op):
  byte 0 = opcode, byte 1 = mtype (high 3 bits) | dtype (low 5 bits),
  w2 = size (CVT: from-dtype in the high byte), w3 = register / offset / amount,
  w4 = constant (LDC). Numbers measured on 7.1 are listed in README-cdx71.md.
"""
import sys
from pathlib import Path

HOOK = r"""
/* ---- DKWB u-code injection hook (cdx71/patch_ugen71.py) ----
 * The record index n counts real records in read order over the whole ugen run
 * (deterministic for a given input). Synthetic records do not advance it.
 *   DKWB_UDUMP=1                  print each record: [U] n=<n> op=<opc> w=<8 words>
 *   DKWB_UPATCH='n:i=v,j=v;m:...' overwrite word i of record n (numbers in C syntax)
 *   DKWB_UDELETE='n:;m:'          drop records n, m
 *   DKWB_UINSERT='n:w0,w1,..'     feed one synthetic record before record n
 *   DKWB_UREPLACE='n:k:w0,..[/w0,..]...;m:...'
 *                                 replace records n..n+k-1 with the listed records
 *                                 (k=0: insert them before n)
 * Words not given are 0. Up to 63 synthetic records per entry. */
#define DKWB_U_WORDS 8
#define DKWB_U_QMAX 64
static int dkwb_u_ready = 0, dkwb_u_dump = 0;
static const char *dkwb_u_patch, *dkwb_u_delete, *dkwb_u_insert, *dkwb_u_replace;
static uint32_t dkwb_u_n = 0;
static uint32_t dkwb_u_q[DKWB_U_QMAX][DKWB_U_WORDS];
static int dkwb_u_qh = 0, dkwb_u_qt = 0;
static uint32_t dkwb_u_held[DKWB_U_WORDS];
static int dkwb_u_have_held = 0;

/* find entry "n:" for record n in a ';'-separated spec; *body points past the colon */
static int dkwb_u_find(const char *spec, uint32_t n, const char **body) {
    const char *c = spec;
    while (c != NULL && *c != '\0') {
        char *end;
        unsigned long k = strtoul(c, &end, 0);
        if (end != c && *end == ':' && k == n) { *body = end + 1; return 1; }
        c = strchr(c, ';');
        if (c != NULL) c++;
    }
    return 0;
}
/* parse "w0,w1,.../w0,..." up to ';' into the queue */
static void dkwb_u_enqueue(const char *body) {
    while (*body != '\0' && *body != ';' && dkwb_u_qt < DKWB_U_QMAX) {
        int i;
        for (i = 0; i < DKWB_U_WORDS; i++) dkwb_u_q[dkwb_u_qt][i] = 0;
        for (i = 0; i < DKWB_U_WORDS && *body != '\0' && *body != '/' && *body != ';'; i++) {
            char *end;
            dkwb_u_q[dkwb_u_qt][i] = (uint32_t)strtoul(body, &end, 0);
            if (end == body) break;
            body = end;
            if (*body == ',') body++;
        }
        while (*body != '\0' && *body != '/' && *body != ';') body++;
        dkwb_u_qt++;
        if (*body == '/') body++;
    }
}
static void dkwb_u_store(uint8_t *mem, uint32_t a0, const uint32_t *w) {
    int i;
    for (i = 0; i < DKWB_U_WORDS; i++) MEM_U32(a0 + 4 * i) = w[i];
}
static void dkwb_u_load(uint8_t *mem, uint32_t a0, uint32_t *w) {
    int i;
    for (i = 0; i < DKWB_U_WORDS; i++) w[i] = MEM_U32(a0 + 4 * i);
}
static void dkwb_u_print(uint8_t *mem, uint32_t a0, const char *tag) {
    int i;
    fprintf(stderr, "[U] n=%u%s op=%u w=", (unsigned)dkwb_u_n, tag, (unsigned)MEM_U8(a0));
    for (i = 0; i < DKWB_U_WORDS; i++)
        fprintf(stderr, "%08x%s", (unsigned)MEM_U32(a0 + 4 * i), i + 1 < DKWB_U_WORDS ? " " : "\n");
}
/* read the next real record, applying DKWB_UDELETE and DKWB_UPATCH */
static void dkwb_u_read_real(uint8_t *mem, uint32_t sp, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3) {
    const char *body;
    for (;;) {
        f_readuinstr_stock(mem, sp, a0, a1, a2, a3);
        dkwb_u_n++;
        if (dkwb_u_delete == NULL || !dkwb_u_find(dkwb_u_delete, dkwb_u_n, &body)) break;
        if (dkwb_u_dump) dkwb_u_print(mem, a0, " DELETED");
    }
    if (dkwb_u_patch != NULL && dkwb_u_find(dkwb_u_patch, dkwb_u_n, &body)) {
        while (*body != '\0' && *body != ';') {
            char *end;
            unsigned long idx = strtoul(body, &end, 0);
            uint32_t v;
            if (end == body || *end != '=') break;
            v = (uint32_t)strtoul(end + 1, &end, 0);
            if (idx < DKWB_U_WORDS) MEM_U32(a0 + 4 * idx) = v;
            body = end;
            if (*body == ',') body++;
        }
    }
}
static void f_readuinstr(uint8_t *mem, uint32_t sp, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3) {
    const char *body;
    if (!dkwb_u_ready) {
        dkwb_u_ready = 1;
        dkwb_u_dump = getenv("DKWB_UDUMP") != NULL;
        dkwb_u_patch = getenv("DKWB_UPATCH");
        dkwb_u_delete = getenv("DKWB_UDELETE");
        dkwb_u_insert = getenv("DKWB_UINSERT");
        dkwb_u_replace = getenv("DKWB_UREPLACE");
    }
    if (dkwb_u_patch == NULL && dkwb_u_delete == NULL && dkwb_u_insert == NULL
            && dkwb_u_replace == NULL && !dkwb_u_dump) {
        f_readuinstr_stock(mem, sp, a0, a1, a2, a3);
        return;
    }
    /* 1. pending synthetic records */
    if (dkwb_u_qh < dkwb_u_qt) {
        dkwb_u_store(mem, a0, dkwb_u_q[dkwb_u_qh++]);
        if (dkwb_u_qh == dkwb_u_qt) dkwb_u_qh = dkwb_u_qt = 0;
        if (dkwb_u_dump) dkwb_u_print(mem, a0, " SYNTH");
        return;
    }
    /* 2. a real record held back by DKWB_UINSERT / k=0 replace */
    if (dkwb_u_have_held) {
        dkwb_u_store(mem, a0, dkwb_u_held);
        dkwb_u_have_held = 0;
        if (dkwb_u_dump) dkwb_u_print(mem, a0, "");
        return;
    }
    /* 3. replace / insert keyed on the index of the next real record */
    if (dkwb_u_replace != NULL && dkwb_u_find(dkwb_u_replace, dkwb_u_n + 1, &body)) {
        char *end;
        unsigned long k = strtoul(body, &end, 0), i;
        body = (*end == ':') ? end + 1 : end;
        if (k == 0) {
            dkwb_u_read_real(mem, sp, a0, a1, a2, a3);
            dkwb_u_load(mem, a0, dkwb_u_held);
            dkwb_u_have_held = 1;
        } else {
            for (i = 0; i < k; i++) {
                dkwb_u_read_real(mem, sp, a0, a1, a2, a3);
                if (dkwb_u_dump) dkwb_u_print(mem, a0, " REPLACED");
            }
        }
        dkwb_u_enqueue(body);
        if (dkwb_u_qh < dkwb_u_qt) {
            dkwb_u_store(mem, a0, dkwb_u_q[dkwb_u_qh++]);
            if (dkwb_u_qh == dkwb_u_qt) dkwb_u_qh = dkwb_u_qt = 0;
            if (dkwb_u_dump) dkwb_u_print(mem, a0, " SYNTH");
            return;
        }
        if (dkwb_u_have_held) {
            dkwb_u_store(mem, a0, dkwb_u_held);
            dkwb_u_have_held = 0;
            if (dkwb_u_dump) dkwb_u_print(mem, a0, "");
            return;
        }
        /* k>0 with an empty list = deletion: fall through to the next real record */
    }
    if (dkwb_u_insert != NULL && dkwb_u_find(dkwb_u_insert, dkwb_u_n + 1, &body)) {
        dkwb_u_read_real(mem, sp, a0, a1, a2, a3);
        dkwb_u_load(mem, a0, dkwb_u_held);
        dkwb_u_have_held = 1;
        dkwb_u_enqueue(body);
        dkwb_u_store(mem, a0, dkwb_u_q[dkwb_u_qh++]);
        if (dkwb_u_qh == dkwb_u_qt) dkwb_u_qh = dkwb_u_qt = 0;
        if (dkwb_u_dump) dkwb_u_print(mem, a0, " INSERTED");
        return;
    }
    dkwb_u_read_real(mem, sp, a0, a1, a2, a3);
    if (dkwb_u_dump) dkwb_u_print(mem, a0, "");
}
"""

SIG = "static void f_readuinstr(uint8_t *mem, uint32_t sp, uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3)"


def main() -> None:
    path = Path(sys.argv[1])
    src = path.read_text()
    if "DKWB u-code injection hook" in src:
        raise SystemExit(f"{path}: hook already present")
    decl, defn = SIG + ";\n", SIG + " {\n"
    for needle in (decl, defn):
        if src.count(needle) != 1:
            raise SystemExit(f"{path}: anchor count {src.count(needle)} for {needle!r}")
    stock = SIG.replace("f_readuinstr(", "f_readuinstr_stock(")
    src = src.replace(decl, decl + stock + ";\n", 1)
    src = src.replace(defn, stock + " {\n", 1)
    src += HOOK
    path.write_text(src)
    print(f"patched {path}: f_readuinstr -> injection wrapper around f_readuinstr_stock")


if __name__ == "__main__":
    main()
