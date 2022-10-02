#!/usr/bin/env python3

def apply(config, args):
    config['baseimg'] = 'baserom.z64'
    config['myimg'] = 'pokemonstadium.z64'
    config['mapfile'] = 'build/pokemonstadium.map'
    config['source_directories'] = ['.']
