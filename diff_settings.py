#!/usr/bin/env python3

def apply(config, args):
    config['baseimg'] = 'baseroms/us/baserom.z64'
    config['myimg'] = 'build/pokestadium-us.z64'
    config['mapfile'] = 'build/pokestadium-us.map'
    config['source_directories'] = ['.']
