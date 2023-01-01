#!/usr/bin/env python3

def apply(config, args):
    config['baseimg'] = 'baserom.z64'
    config['myimg'] = 'build/pokestadium.z64'
    config['mapfile'] = 'build/pokestadium.map'
    config['source_directories'] = ['.']
