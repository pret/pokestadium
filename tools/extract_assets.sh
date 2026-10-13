#!/usr/bin/env bash

: "${PYTHON:=python3}"
: "${VERSION:=us}"
export VERSION

# The US releases share every asset; the others lack some (the Japanese release has no
# Gallery) or pack them differently, so unpack what they have and go on past the rest.
case "$VERSION" in
    us|us_rev1|us_rev2) set -e ;;
esac

# Unpack assets from ROM extraction.

# TODO: The packed bins do not depend on their extracted contents yet so modifying these files will do nothing. Add dependencies

# Unpack/move any multi or single asset bins.
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/n64_logo_texture.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/fonts.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/backgrounds.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/battle_headers.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/common_menu0_ui.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/common_menu1_ui.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/common_menu2_ui.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/area_select_ui.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/menu_select_ui.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/stadium_select_ui.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/title_ui.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/52F6D0.bin # unused UI
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/battle_portraits.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/stadium_models.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/5C7A70.bin # unk FRAGMENT
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/pokedex_area_model.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/sushi_go_round.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/order_select_ui.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/cup_ball_select_ui.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/trade_select_ui.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/kids_club_select_ui.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/gym_leader_castle_clear_gfx.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rental_rules_ui.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/sushi_go_round_sprites.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/kids_club_game_ui.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/gallery_ui.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/album_ui.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/6A9750.bin # print UI
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/snap_select_ui.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/cup_clear_ui.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/gb_pak_select_ui.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/victory_palace_plate_text.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/run_rattata_run_flag_gfx.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/kanto_gb_map.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/6CA730.bin # unused 15 type BGs
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/6E2F90.bin # blank file
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/battle_ui.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/transfer_pak_error_ui.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/6EB340.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/6EC4D0.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/badge_ui.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/gym_leader_castle_ui.bin
# 70D3A0 needs special processing. not a normal asset bin
# 7820E0 isnt a normal asset bin either
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/textdata.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/798CD0.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/snap_mode_ui.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/copyright.bin

# Late assets
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_0.bin assets/${VERSION}/rom_parts/0.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_1.bin assets/${VERSION}/rom_parts/1.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_2.bin assets/${VERSION}/rom_parts/2.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_3.bin assets/${VERSION}/rom_parts/3.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_4.bin assets/${VERSION}/rom_parts/4.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_5.bin assets/${VERSION}/rom_parts/5.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_6.bin assets/${VERSION}/rom_parts/6.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_7.bin assets/${VERSION}/rom_parts/7.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_8.bin assets/${VERSION}/rom_parts/8.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_9.bin assets/${VERSION}/rom_parts/9.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_10.bin assets/${VERSION}/rom_parts/10.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_11.bin assets/${VERSION}/rom_parts/11.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_12.bin assets/${VERSION}/rom_parts/12.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_13.bin assets/${VERSION}/rom_parts/13.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_14.bin assets/${VERSION}/rom_parts/14.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_15.bin assets/${VERSION}/rom_parts/15.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_16.bin assets/${VERSION}/rom_parts/16.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_17.bin assets/${VERSION}/rom_parts/17.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_18.bin assets/${VERSION}/rom_parts/18.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_19.bin assets/${VERSION}/rom_parts/19.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_20.bin assets/${VERSION}/rom_parts/20.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_21.bin assets/${VERSION}/rom_parts/21.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_22.bin assets/${VERSION}/rom_parts/22.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_23.bin assets/${VERSION}/rom_parts/23.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_24.bin assets/${VERSION}/rom_parts/24.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_25.bin assets/${VERSION}/rom_parts/25.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_26.bin assets/${VERSION}/rom_parts/26.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_27.bin assets/${VERSION}/rom_parts/27.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_28.bin assets/${VERSION}/rom_parts/28.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_29.bin assets/${VERSION}/rom_parts/29.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_30.bin assets/${VERSION}/rom_parts/30.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_31.bin assets/${VERSION}/rom_parts/31.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_32.bin assets/${VERSION}/rom_parts/32.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_33.bin assets/${VERSION}/rom_parts/33.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_34.bin assets/${VERSION}/rom_parts/34.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_35.bin assets/${VERSION}/rom_parts/35.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_36.bin assets/${VERSION}/rom_parts/36.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_37.bin assets/${VERSION}/rom_parts/37.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_38.bin assets/${VERSION}/rom_parts/38.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_39.bin assets/${VERSION}/rom_parts/39.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_40.bin assets/${VERSION}/rom_parts/40.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_41.bin assets/${VERSION}/rom_parts/41.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_42.bin assets/${VERSION}/rom_parts/42.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_43.bin assets/${VERSION}/rom_parts/43.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_44.bin assets/${VERSION}/rom_parts/44.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_45.bin assets/${VERSION}/rom_parts/45.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_46.bin assets/${VERSION}/rom_parts/46.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_47.bin assets/${VERSION}/rom_parts/47.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_48.bin assets/${VERSION}/rom_parts/48.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_49.bin assets/${VERSION}/rom_parts/49.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_50.bin assets/${VERSION}/rom_parts/50.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_51.bin assets/${VERSION}/rom_parts/51.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/rom_part_52.bin assets/${VERSION}/rom_parts/52.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/pokemon_icons.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/898000.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/8CC000.bin
"$PYTHON" tools/unpack_asset.py assets/${VERSION}/pokemon_models.bin

# Next, decompress all the PERS-SZP files with a Yay0. TODO: Roll these up
# into recursive calls. All of the files within an asset bin SHOULD be the
# same type, but it in theory it isnt guaranteed to be. Does the game ensure
# that? If so, we should be able to safely roll these up.
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/n64_logo_texture/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/fonts/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/fonts/1.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/fonts/2.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/fonts/3.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/fonts/4.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/fonts/5.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_headers/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_headers/1.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_headers/2.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_headers/3.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_headers/4.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_headers/5.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_headers/6.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_headers/7.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_headers/8.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_headers/9.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_headers/10.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_headers/11.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_headers/12.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/common_menu0_ui/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/common_menu1_ui/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/common_menu2_ui/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/area_select_ui/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/menu_select_ui/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/stadium_select_ui/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/title_ui/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/52F6D0/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/1.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/2.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/3.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/4.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/5.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/6.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/7.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/8.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/9.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/10.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/11.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/12.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/13.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/14.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/15.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/16.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/17.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/18.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/19.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/20.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/21.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/22.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/23.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/24.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/25.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/26.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/27.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/28.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/29.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/30.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/31.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/32.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/33.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/34.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/35.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/36.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/37.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/38.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/39.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/40.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/41.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/42.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/43.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/44.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/45.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/46.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/47.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/48.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/49.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/50.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/51.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/52.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_portraits/53.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/stadium_models/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/stadium_models/1.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/stadium_models/2.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/stadium_models/3.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/stadium_models/4.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/stadium_models/5.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/stadium_models/6.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/stadium_models/7.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/stadium_models/8.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/stadium_models/9.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/stadium_models/10.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/stadium_models/11.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/stadium_models/12.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/stadium_models/13.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/stadium_models/14.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/stadium_models/15.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/stadium_models/16.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/stadium_models/17.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/5C7A70/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokedex_area_model/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/sushi_go_round/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/order_select_ui/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/cup_ball_select_ui/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/trade_select_ui/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/kids_club_select_ui/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/gym_leader_castle_clear_gfx/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/rental_rules_ui/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/sushi_go_round_sprites/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/kids_club_game_ui/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/gallery_ui/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/album_ui/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/6A9750/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/snap_select_ui/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/cup_clear_ui/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/gb_pak_select_ui/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/victory_palace_plate_text/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/run_rattata_run_flag_gfx/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/kanto_gb_map/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/6E2F90/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/battle_ui/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/transfer_pak_error_ui/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/6EB340/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/6EB340/1.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/6EB340/2.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/6EB340/3.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/6EC4D0/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/badge_ui/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/gym_leader_castle_ui/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/798CD0/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/snap_mode_ui/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/copyright/0.bin

# Decompress PERS-SZP files in late asset(s).
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/1.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/2.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/3.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/4.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/5.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/6.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/7.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/8.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/9.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/10.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/11.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/12.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/13.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/14.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/15.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/16.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/17.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/18.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/19.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/20.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/21.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/22.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/23.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/24.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/25.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/26.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/27.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/28.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/29.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/30.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/31.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/32.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/33.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/34.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/35.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/36.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/37.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/38.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/39.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/40.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/41.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/42.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/43.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/44.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/45.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/46.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/47.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/48.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/49.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/50.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/51.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/52.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/53.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/54.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/55.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/56.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/57.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/58.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/59.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/60.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/61.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/8CC000/62.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/0.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/1.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/2.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/3.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/4.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/5.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/6.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/7.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/8.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/9.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/10.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/11.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/12.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/13.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/14.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/15.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/16.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/17.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/18.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/19.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/20.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/21.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/22.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/23.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/24.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/25.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/26.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/27.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/28.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/29.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/30.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/31.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/32.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/33.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/34.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/35.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/36.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/37.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/38.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/39.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/40.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/41.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/42.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/43.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/44.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/45.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/46.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/47.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/48.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/49.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/50.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/51.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/52.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/53.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/54.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/55.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/56.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/57.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/58.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/59.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/60.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/61.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/62.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/63.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/64.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/65.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/66.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/67.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/68.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/69.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/70.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/71.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/72.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/73.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/74.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/75.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/76.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/77.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/78.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/79.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/80.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/81.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/82.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/83.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/84.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/85.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/86.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/87.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/88.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/89.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/90.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/91.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/92.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/93.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/94.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/95.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/96.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/97.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/98.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/99.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/100.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/101.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/102.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/103.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/104.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/105.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/106.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/107.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/108.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/109.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/110.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/111.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/112.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/113.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/114.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/115.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/116.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/117.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/118.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/119.bin
#tools/decompress_persszp.py assets/${VERSION}/920000/120.bin this file is just randomly not compressed. Thanks for breaking the uniform asset pattern, HAL.
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/121.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/122.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/123.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/124.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/125.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/126.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/127.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/128.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/129.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/130.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/131.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/132.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/133.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/134.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/135.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/136.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/137.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/138.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/139.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/140.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/141.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/142.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/143.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/144.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/145.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/146.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/147.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/148.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/149.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/150.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/151.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/152.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/153.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/154.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/155.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/156.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/157.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/158.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/159.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/160.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/161.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/162.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/163.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/164.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/165.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/166.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/167.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/168.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/169.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/170.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/171.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/172.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/173.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/174.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/175.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/176.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/177.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/178.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/179.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/180.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/181.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/182.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/183.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/184.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/185.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/186.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/187.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/188.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/189.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/190.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/191.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/192.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/193.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/194.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/195.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/196.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/197.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/198.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/199.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/200.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/201.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/202.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/203.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/204.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/205.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/206.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/207.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/208.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/209.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/210.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/211.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/212.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/213.bin
"$PYTHON" tools/decompress_persszp.py assets/${VERSION}/pokemon_models/214.bin

# Extract all PRESJPEG files.
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/backgrounds/0.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/backgrounds/1.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/backgrounds/2.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/backgrounds/3.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/backgrounds/4.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/backgrounds/5.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/backgrounds/6.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/backgrounds/7.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/backgrounds/8.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/backgrounds/9.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/backgrounds/10.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/backgrounds/11.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/backgrounds/12.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/backgrounds/13.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/backgrounds/14.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/backgrounds/15.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/backgrounds/16.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/backgrounds/17.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/backgrounds/18.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/backgrounds/19.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/backgrounds/20.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/6CA730/0.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/6CA730/1.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/6CA730/2.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/6CA730/3.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/6CA730/4.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/6CA730/5.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/6CA730/6.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/6CA730/7.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/6CA730/8.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/6CA730/9.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/6CA730/10.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/6CA730/11.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/6CA730/12.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/6CA730/13.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/6CA730/14.bin
"$PYTHON" tools/extract_presjpeg.py assets/${VERSION}/6CA730/15.bin

# Decompress raw Yay0s
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/0.bin assets/${VERSION}/rom_parts/0.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/1.bin assets/${VERSION}/rom_parts/1.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/2.bin assets/${VERSION}/rom_parts/2.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/3.bin assets/${VERSION}/rom_parts/3.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/4.bin assets/${VERSION}/rom_parts/4.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/5.bin assets/${VERSION}/rom_parts/5.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/6.bin assets/${VERSION}/rom_parts/6.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/7.bin assets/${VERSION}/rom_parts/7.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/8.bin assets/${VERSION}/rom_parts/8.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/9.bin assets/${VERSION}/rom_parts/9.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/10.bin assets/${VERSION}/rom_parts/10.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/11.bin assets/${VERSION}/rom_parts/11.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/12.bin assets/${VERSION}/rom_parts/12.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/13.bin assets/${VERSION}/rom_parts/13.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/14.bin assets/${VERSION}/rom_parts/14.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/15.bin assets/${VERSION}/rom_parts/15.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/16.bin assets/${VERSION}/rom_parts/16.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/17.bin assets/${VERSION}/rom_parts/17.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/18.bin assets/${VERSION}/rom_parts/18.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/19.bin assets/${VERSION}/rom_parts/19.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/20.bin assets/${VERSION}/rom_parts/20.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/21.bin assets/${VERSION}/rom_parts/21.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/22.bin assets/${VERSION}/rom_parts/22.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/23.bin assets/${VERSION}/rom_parts/23.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/24.bin assets/${VERSION}/rom_parts/24.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/25.bin assets/${VERSION}/rom_parts/25.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/26.bin assets/${VERSION}/rom_parts/26.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/27.bin assets/${VERSION}/rom_parts/27.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/28.bin assets/${VERSION}/rom_parts/28.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/29.bin assets/${VERSION}/rom_parts/29.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/30.bin assets/${VERSION}/rom_parts/30.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/31.bin assets/${VERSION}/rom_parts/31.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/32.bin assets/${VERSION}/rom_parts/32.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/33.bin assets/${VERSION}/rom_parts/33.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/34.bin assets/${VERSION}/rom_parts/34.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/35.bin assets/${VERSION}/rom_parts/35.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/36.bin assets/${VERSION}/rom_parts/36.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/37.bin assets/${VERSION}/rom_parts/37.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/38.bin assets/${VERSION}/rom_parts/38.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/39.bin assets/${VERSION}/rom_parts/39.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/40.bin assets/${VERSION}/rom_parts/40.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/41.bin assets/${VERSION}/rom_parts/41.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/42.bin assets/${VERSION}/rom_parts/42.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/43.bin assets/${VERSION}/rom_parts/43.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/44.bin assets/${VERSION}/rom_parts/44.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/45.bin assets/${VERSION}/rom_parts/45.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/46.bin assets/${VERSION}/rom_parts/46.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/47.bin assets/${VERSION}/rom_parts/47.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/48.bin assets/${VERSION}/rom_parts/48.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/49.bin assets/${VERSION}/rom_parts/49.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/50.bin assets/${VERSION}/rom_parts/50.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/51.bin assets/${VERSION}/rom_parts/51.bin
"$PYTHON" tools/decompress_yay0.py assets/${VERSION}/rom_parts/52.bin assets/${VERSION}/rom_parts/52.bin

exit 0
