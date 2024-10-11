#!/usr/bin/env bash

# Unpack assets from ROM extraction.

# TODO: The packed bins do not depend on their extracted contents yet so modifying these files will do nothing. Add dependencies

tools/unpack_asset.py assets/us/n64_logo_texture.bin
tools/unpack_asset.py assets/us/fonts.bin
tools/unpack_asset.py assets/us/backgrounds.bin
tools/unpack_asset.py assets/us/battle_headers.bin
tools/unpack_asset.py assets/us/common_menu0_ui.bin
tools/unpack_asset.py assets/us/common_menu1_ui.bin
tools/unpack_asset.py assets/us/common_menu2_ui.bin
tools/unpack_asset.py assets/us/area_select_ui.bin
tools/unpack_asset.py assets/us/menu_select_ui.bin
tools/unpack_asset.py assets/us/stadium_select_ui.bin
tools/unpack_asset.py assets/us/title_ui.bin
tools/unpack_asset.py assets/us/52F6D0.bin # unused UI
tools/unpack_asset.py assets/us/battle_portraits.bin
tools/unpack_asset.py assets/us/stadium_models.bin
tools/unpack_asset.py assets/us/5C7A70.bin # unk FRAGMENT
tools/unpack_asset.py assets/us/pokedex_area_model.bin
tools/unpack_asset.py assets/us/sushi_go_round.bin
tools/unpack_asset.py assets/us/order_select_ui.bin
tools/unpack_asset.py assets/us/cup_ball_select_ui.bin
tools/unpack_asset.py assets/us/trade_select_ui.bin
tools/unpack_asset.py assets/us/kids_club_select_ui.bin
tools/unpack_asset.py assets/us/gym_leader_castle_clear_gfx.bin
tools/unpack_asset.py assets/us/rental_rules_ui.bin
tools/unpack_asset.py assets/us/sushi_go_round_sprites.bin
tools/unpack_asset.py assets/us/kids_club_game_ui.bin
tools/unpack_asset.py assets/us/gallery_ui.bin
tools/unpack_asset.py assets/us/album_ui.bin
tools/unpack_asset.py assets/us/6A9750.bin # print UI
tools/unpack_asset.py assets/us/snap_select_ui.bin
tools/unpack_asset.py assets/us/cup_clear_ui.bin
tools/unpack_asset.py assets/us/gb_pak_select_ui.bin
tools/unpack_asset.py assets/us/victory_palace_plate_text.bin
tools/unpack_asset.py assets/us/run_rattata_run_flag_gfx.bin
tools/unpack_asset.py assets/us/kanto_gb_map.bin
tools/unpack_asset.py assets/us/6CA730.bin # unused 15 type BGs
tools/unpack_asset.py assets/us/6E2F90.bin # blank file
tools/unpack_asset.py assets/us/battle_ui.bin
tools/unpack_asset.py assets/us/transfer_pak_error_ui.bin
tools/unpack_asset.py assets/us/6EB340.bin
tools/unpack_asset.py assets/us/6EC4D0.bin
tools/unpack_asset.py assets/us/badge_ui.bin
tools/unpack_asset.py assets/us/gym_leader_castle_ui.bin
# 70D3A0 needs special processing. not a normal asset bin
# 7820E0 isnt a normal asset bin either
tools/unpack_asset.py assets/us/textdata.bin
tools/unpack_asset.py assets/us/798CD0.bin
tools/unpack_asset.py assets/us/snap_mode_ui.bin
tools/unpack_asset.py assets/us/copyright.bin
