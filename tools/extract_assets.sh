#!/usr/bin/env bash

# Unpack assets from ROM extraction.

# TODO: The packed bins do not depend on their extracted contents yet so modifying these files will do nothing. Add dependencies

# Unpack/move any multi or single asset bins.
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

# Late assets
tools/unpack_asset.py assets/us/rom_part_0.bin assets/us/rom_parts/0.bin
tools/unpack_asset.py assets/us/rom_part_1.bin assets/us/rom_parts/1.bin
tools/unpack_asset.py assets/us/rom_part_2.bin assets/us/rom_parts/2.bin
tools/unpack_asset.py assets/us/rom_part_3.bin assets/us/rom_parts/3.bin
tools/unpack_asset.py assets/us/rom_part_4.bin assets/us/rom_parts/4.bin
tools/unpack_asset.py assets/us/rom_part_5.bin assets/us/rom_parts/5.bin
tools/unpack_asset.py assets/us/rom_part_6.bin assets/us/rom_parts/6.bin
tools/unpack_asset.py assets/us/rom_part_7.bin assets/us/rom_parts/7.bin
tools/unpack_asset.py assets/us/rom_part_8.bin assets/us/rom_parts/8.bin
tools/unpack_asset.py assets/us/rom_part_9.bin assets/us/rom_parts/9.bin
tools/unpack_asset.py assets/us/rom_part_10.bin assets/us/rom_parts/10.bin
tools/unpack_asset.py assets/us/rom_part_11.bin assets/us/rom_parts/11.bin
tools/unpack_asset.py assets/us/rom_part_12.bin assets/us/rom_parts/12.bin
tools/unpack_asset.py assets/us/rom_part_13.bin assets/us/rom_parts/13.bin
tools/unpack_asset.py assets/us/rom_part_14.bin assets/us/rom_parts/14.bin
tools/unpack_asset.py assets/us/rom_part_15.bin assets/us/rom_parts/15.bin
tools/unpack_asset.py assets/us/rom_part_16.bin assets/us/rom_parts/16.bin
tools/unpack_asset.py assets/us/rom_part_17.bin assets/us/rom_parts/17.bin
tools/unpack_asset.py assets/us/rom_part_18.bin assets/us/rom_parts/18.bin
tools/unpack_asset.py assets/us/rom_part_19.bin assets/us/rom_parts/19.bin
tools/unpack_asset.py assets/us/rom_part_20.bin assets/us/rom_parts/20.bin
tools/unpack_asset.py assets/us/rom_part_21.bin assets/us/rom_parts/21.bin
tools/unpack_asset.py assets/us/rom_part_22.bin assets/us/rom_parts/22.bin
tools/unpack_asset.py assets/us/rom_part_23.bin assets/us/rom_parts/23.bin
tools/unpack_asset.py assets/us/rom_part_24.bin assets/us/rom_parts/24.bin
tools/unpack_asset.py assets/us/rom_part_25.bin assets/us/rom_parts/25.bin
tools/unpack_asset.py assets/us/rom_part_26.bin assets/us/rom_parts/26.bin
tools/unpack_asset.py assets/us/rom_part_27.bin assets/us/rom_parts/27.bin
tools/unpack_asset.py assets/us/rom_part_28.bin assets/us/rom_parts/28.bin
tools/unpack_asset.py assets/us/rom_part_29.bin assets/us/rom_parts/29.bin
tools/unpack_asset.py assets/us/rom_part_30.bin assets/us/rom_parts/30.bin
tools/unpack_asset.py assets/us/rom_part_31.bin assets/us/rom_parts/31.bin
tools/unpack_asset.py assets/us/rom_part_32.bin assets/us/rom_parts/32.bin
tools/unpack_asset.py assets/us/rom_part_33.bin assets/us/rom_parts/33.bin
tools/unpack_asset.py assets/us/rom_part_34.bin assets/us/rom_parts/34.bin
tools/unpack_asset.py assets/us/rom_part_35.bin assets/us/rom_parts/35.bin
tools/unpack_asset.py assets/us/rom_part_36.bin assets/us/rom_parts/36.bin
tools/unpack_asset.py assets/us/rom_part_37.bin assets/us/rom_parts/37.bin
tools/unpack_asset.py assets/us/rom_part_38.bin assets/us/rom_parts/38.bin
tools/unpack_asset.py assets/us/rom_part_39.bin assets/us/rom_parts/39.bin
tools/unpack_asset.py assets/us/rom_part_40.bin assets/us/rom_parts/40.bin
tools/unpack_asset.py assets/us/rom_part_41.bin assets/us/rom_parts/41.bin
tools/unpack_asset.py assets/us/rom_part_42.bin assets/us/rom_parts/42.bin
tools/unpack_asset.py assets/us/rom_part_43.bin assets/us/rom_parts/43.bin
tools/unpack_asset.py assets/us/rom_part_44.bin assets/us/rom_parts/44.bin
tools/unpack_asset.py assets/us/rom_part_45.bin assets/us/rom_parts/45.bin
tools/unpack_asset.py assets/us/rom_part_46.bin assets/us/rom_parts/46.bin
tools/unpack_asset.py assets/us/rom_part_47.bin assets/us/rom_parts/47.bin
tools/unpack_asset.py assets/us/rom_part_48.bin assets/us/rom_parts/48.bin
tools/unpack_asset.py assets/us/rom_part_49.bin assets/us/rom_parts/49.bin
tools/unpack_asset.py assets/us/rom_part_50.bin assets/us/rom_parts/50.bin
tools/unpack_asset.py assets/us/rom_part_51.bin assets/us/rom_parts/51.bin
tools/unpack_asset.py assets/us/rom_part_52.bin assets/us/rom_parts/52.bin
tools/unpack_asset.py assets/us/pokemon_icons.bin
tools/unpack_asset.py assets/us/898000.bin
tools/unpack_asset.py assets/us/8CC000.bin
tools/unpack_asset.py assets/us/pokemon_models.bin

# Next, decompress all the PERS-SZP files with a Yay0. TODO: Roll these up
# into recursive calls. All of the files within an asset bin SHOULD be the
# same type, but it in theory it isnt guaranteed to be. Does the game ensure
# that? If so, we should be able to safely roll these up.
tools/decompress_persszp.py assets/us/n64_logo_texture/0.bin
tools/decompress_persszp.py assets/us/fonts/0.bin
tools/decompress_persszp.py assets/us/fonts/1.bin
tools/decompress_persszp.py assets/us/fonts/2.bin
tools/decompress_persszp.py assets/us/fonts/3.bin
tools/decompress_persszp.py assets/us/fonts/4.bin
tools/decompress_persszp.py assets/us/fonts/5.bin
tools/decompress_persszp.py assets/us/battle_headers/0.bin
tools/decompress_persszp.py assets/us/battle_headers/1.bin
tools/decompress_persszp.py assets/us/battle_headers/2.bin
tools/decompress_persszp.py assets/us/battle_headers/3.bin
tools/decompress_persszp.py assets/us/battle_headers/4.bin
tools/decompress_persszp.py assets/us/battle_headers/5.bin
tools/decompress_persszp.py assets/us/battle_headers/6.bin
tools/decompress_persszp.py assets/us/battle_headers/7.bin
tools/decompress_persszp.py assets/us/battle_headers/8.bin
tools/decompress_persszp.py assets/us/battle_headers/9.bin
tools/decompress_persszp.py assets/us/battle_headers/10.bin
tools/decompress_persszp.py assets/us/battle_headers/11.bin
tools/decompress_persszp.py assets/us/battle_headers/12.bin
tools/decompress_persszp.py assets/us/common_menu0_ui/0.bin
tools/decompress_persszp.py assets/us/common_menu1_ui/0.bin
tools/decompress_persszp.py assets/us/common_menu2_ui/0.bin
tools/decompress_persszp.py assets/us/area_select_ui/0.bin
tools/decompress_persszp.py assets/us/menu_select_ui/0.bin
tools/decompress_persszp.py assets/us/stadium_select_ui/0.bin
tools/decompress_persszp.py assets/us/title_ui/0.bin
tools/decompress_persszp.py assets/us/52F6D0/0.bin
tools/decompress_persszp.py assets/us/battle_portraits/0.bin
tools/decompress_persszp.py assets/us/battle_portraits/1.bin
tools/decompress_persszp.py assets/us/battle_portraits/2.bin
tools/decompress_persszp.py assets/us/battle_portraits/3.bin
tools/decompress_persszp.py assets/us/battle_portraits/4.bin
tools/decompress_persszp.py assets/us/battle_portraits/5.bin
tools/decompress_persszp.py assets/us/battle_portraits/6.bin
tools/decompress_persszp.py assets/us/battle_portraits/7.bin
tools/decompress_persszp.py assets/us/battle_portraits/8.bin
tools/decompress_persszp.py assets/us/battle_portraits/9.bin
tools/decompress_persszp.py assets/us/battle_portraits/10.bin
tools/decompress_persszp.py assets/us/battle_portraits/11.bin
tools/decompress_persszp.py assets/us/battle_portraits/12.bin
tools/decompress_persszp.py assets/us/battle_portraits/13.bin
tools/decompress_persszp.py assets/us/battle_portraits/14.bin
tools/decompress_persszp.py assets/us/battle_portraits/15.bin
tools/decompress_persszp.py assets/us/battle_portraits/16.bin
tools/decompress_persszp.py assets/us/battle_portraits/17.bin
tools/decompress_persszp.py assets/us/battle_portraits/18.bin
tools/decompress_persszp.py assets/us/battle_portraits/19.bin
tools/decompress_persszp.py assets/us/battle_portraits/20.bin
tools/decompress_persszp.py assets/us/battle_portraits/21.bin
tools/decompress_persszp.py assets/us/battle_portraits/22.bin
tools/decompress_persszp.py assets/us/battle_portraits/23.bin
tools/decompress_persszp.py assets/us/battle_portraits/24.bin
tools/decompress_persszp.py assets/us/battle_portraits/25.bin
tools/decompress_persszp.py assets/us/battle_portraits/26.bin
tools/decompress_persszp.py assets/us/battle_portraits/27.bin
tools/decompress_persszp.py assets/us/battle_portraits/28.bin
tools/decompress_persszp.py assets/us/battle_portraits/29.bin
tools/decompress_persszp.py assets/us/battle_portraits/30.bin
tools/decompress_persszp.py assets/us/battle_portraits/31.bin
tools/decompress_persszp.py assets/us/battle_portraits/32.bin
tools/decompress_persszp.py assets/us/battle_portraits/33.bin
tools/decompress_persszp.py assets/us/battle_portraits/34.bin
tools/decompress_persszp.py assets/us/battle_portraits/35.bin
tools/decompress_persszp.py assets/us/battle_portraits/36.bin
tools/decompress_persszp.py assets/us/battle_portraits/37.bin
tools/decompress_persszp.py assets/us/battle_portraits/38.bin
tools/decompress_persszp.py assets/us/battle_portraits/39.bin
tools/decompress_persszp.py assets/us/battle_portraits/40.bin
tools/decompress_persszp.py assets/us/battle_portraits/41.bin
tools/decompress_persszp.py assets/us/battle_portraits/42.bin
tools/decompress_persszp.py assets/us/battle_portraits/43.bin
tools/decompress_persszp.py assets/us/battle_portraits/44.bin
tools/decompress_persszp.py assets/us/battle_portraits/45.bin
tools/decompress_persszp.py assets/us/battle_portraits/46.bin
tools/decompress_persszp.py assets/us/battle_portraits/47.bin
tools/decompress_persszp.py assets/us/battle_portraits/48.bin
tools/decompress_persszp.py assets/us/battle_portraits/49.bin
tools/decompress_persszp.py assets/us/battle_portraits/50.bin
tools/decompress_persszp.py assets/us/battle_portraits/51.bin
tools/decompress_persszp.py assets/us/battle_portraits/52.bin
tools/decompress_persszp.py assets/us/battle_portraits/53.bin
tools/decompress_persszp.py assets/us/stadium_models/0.bin
tools/decompress_persszp.py assets/us/stadium_models/1.bin
tools/decompress_persszp.py assets/us/stadium_models/2.bin
tools/decompress_persszp.py assets/us/stadium_models/3.bin
tools/decompress_persszp.py assets/us/stadium_models/4.bin
tools/decompress_persszp.py assets/us/stadium_models/5.bin
tools/decompress_persszp.py assets/us/stadium_models/6.bin
tools/decompress_persszp.py assets/us/stadium_models/7.bin
tools/decompress_persszp.py assets/us/stadium_models/8.bin
tools/decompress_persszp.py assets/us/stadium_models/9.bin
tools/decompress_persszp.py assets/us/stadium_models/10.bin
tools/decompress_persszp.py assets/us/stadium_models/11.bin
tools/decompress_persszp.py assets/us/stadium_models/12.bin
tools/decompress_persszp.py assets/us/stadium_models/13.bin
tools/decompress_persszp.py assets/us/stadium_models/14.bin
tools/decompress_persszp.py assets/us/stadium_models/15.bin
tools/decompress_persszp.py assets/us/stadium_models/16.bin
tools/decompress_persszp.py assets/us/stadium_models/17.bin
tools/decompress_persszp.py assets/us/5C7A70/0.bin
tools/decompress_persszp.py assets/us/pokedex_area_model/0.bin
tools/decompress_persszp.py assets/us/sushi_go_round/0.bin
tools/decompress_persszp.py assets/us/order_select_ui/0.bin
tools/decompress_persszp.py assets/us/cup_ball_select_ui/0.bin
tools/decompress_persszp.py assets/us/trade_select_ui/0.bin
tools/decompress_persszp.py assets/us/kids_club_select_ui/0.bin
tools/decompress_persszp.py assets/us/gym_leader_castle_clear_gfx/0.bin
tools/decompress_persszp.py assets/us/rental_rules_ui/0.bin
tools/decompress_persszp.py assets/us/sushi_go_round_sprites/0.bin
tools/decompress_persszp.py assets/us/kids_club_game_ui/0.bin
tools/decompress_persszp.py assets/us/gallery_ui/0.bin
tools/decompress_persszp.py assets/us/album_ui/0.bin
tools/decompress_persszp.py assets/us/6A9750/0.bin
tools/decompress_persszp.py assets/us/snap_select_ui/0.bin
tools/decompress_persszp.py assets/us/cup_clear_ui/0.bin
tools/decompress_persszp.py assets/us/gb_pak_select_ui/0.bin
tools/decompress_persszp.py assets/us/victory_palace_plate_text/0.bin
tools/decompress_persszp.py assets/us/run_rattata_run_flag_gfx/0.bin
tools/decompress_persszp.py assets/us/kanto_gb_map/0.bin
tools/decompress_persszp.py assets/us/6E2F90/0.bin
tools/decompress_persszp.py assets/us/battle_ui/0.bin
tools/decompress_persszp.py assets/us/transfer_pak_error_ui/0.bin
tools/decompress_persszp.py assets/us/6EB340/0.bin
tools/decompress_persszp.py assets/us/6EB340/1.bin
tools/decompress_persszp.py assets/us/6EB340/2.bin
tools/decompress_persszp.py assets/us/6EB340/3.bin
tools/decompress_persszp.py assets/us/6EC4D0/0.bin
tools/decompress_persszp.py assets/us/badge_ui/0.bin
tools/decompress_persszp.py assets/us/gym_leader_castle_ui/0.bin
tools/decompress_persszp.py assets/us/798CD0/0.bin
tools/decompress_persszp.py assets/us/snap_mode_ui/0.bin
tools/decompress_persszp.py assets/us/copyright/0.bin

# Decompress PERS-SZP files in late asset(s).
tools/decompress_persszp.py assets/us/8CC000/0.bin
tools/decompress_persszp.py assets/us/8CC000/1.bin
tools/decompress_persszp.py assets/us/8CC000/2.bin
tools/decompress_persszp.py assets/us/8CC000/3.bin
tools/decompress_persszp.py assets/us/8CC000/4.bin
tools/decompress_persszp.py assets/us/8CC000/5.bin
tools/decompress_persszp.py assets/us/8CC000/6.bin
tools/decompress_persszp.py assets/us/8CC000/7.bin
tools/decompress_persszp.py assets/us/8CC000/8.bin
tools/decompress_persszp.py assets/us/8CC000/9.bin
tools/decompress_persszp.py assets/us/8CC000/10.bin
tools/decompress_persszp.py assets/us/8CC000/11.bin
tools/decompress_persszp.py assets/us/8CC000/12.bin
tools/decompress_persszp.py assets/us/8CC000/13.bin
tools/decompress_persszp.py assets/us/8CC000/14.bin
tools/decompress_persszp.py assets/us/8CC000/15.bin
tools/decompress_persszp.py assets/us/8CC000/16.bin
tools/decompress_persszp.py assets/us/8CC000/17.bin
tools/decompress_persszp.py assets/us/8CC000/18.bin
tools/decompress_persszp.py assets/us/8CC000/19.bin
tools/decompress_persszp.py assets/us/8CC000/20.bin
tools/decompress_persszp.py assets/us/8CC000/21.bin
tools/decompress_persszp.py assets/us/8CC000/22.bin
tools/decompress_persszp.py assets/us/8CC000/23.bin
tools/decompress_persszp.py assets/us/8CC000/24.bin
tools/decompress_persszp.py assets/us/8CC000/25.bin
tools/decompress_persszp.py assets/us/8CC000/26.bin
tools/decompress_persszp.py assets/us/8CC000/27.bin
tools/decompress_persszp.py assets/us/8CC000/28.bin
tools/decompress_persszp.py assets/us/8CC000/29.bin
tools/decompress_persszp.py assets/us/8CC000/30.bin
tools/decompress_persszp.py assets/us/8CC000/31.bin
tools/decompress_persszp.py assets/us/8CC000/32.bin
tools/decompress_persszp.py assets/us/8CC000/33.bin
tools/decompress_persszp.py assets/us/8CC000/34.bin
tools/decompress_persszp.py assets/us/8CC000/35.bin
tools/decompress_persszp.py assets/us/8CC000/36.bin
tools/decompress_persszp.py assets/us/8CC000/37.bin
tools/decompress_persszp.py assets/us/8CC000/38.bin
tools/decompress_persszp.py assets/us/8CC000/39.bin
tools/decompress_persszp.py assets/us/8CC000/40.bin
tools/decompress_persszp.py assets/us/8CC000/41.bin
tools/decompress_persszp.py assets/us/8CC000/42.bin
tools/decompress_persszp.py assets/us/8CC000/43.bin
tools/decompress_persszp.py assets/us/8CC000/44.bin
tools/decompress_persszp.py assets/us/8CC000/45.bin
tools/decompress_persszp.py assets/us/8CC000/46.bin
tools/decompress_persszp.py assets/us/8CC000/47.bin
tools/decompress_persszp.py assets/us/8CC000/48.bin
tools/decompress_persszp.py assets/us/8CC000/49.bin
tools/decompress_persszp.py assets/us/8CC000/50.bin
tools/decompress_persszp.py assets/us/8CC000/51.bin
tools/decompress_persszp.py assets/us/8CC000/52.bin
tools/decompress_persszp.py assets/us/8CC000/53.bin
tools/decompress_persszp.py assets/us/8CC000/54.bin
tools/decompress_persszp.py assets/us/8CC000/55.bin
tools/decompress_persszp.py assets/us/8CC000/56.bin
tools/decompress_persszp.py assets/us/8CC000/57.bin
tools/decompress_persszp.py assets/us/8CC000/58.bin
tools/decompress_persszp.py assets/us/8CC000/59.bin
tools/decompress_persszp.py assets/us/8CC000/60.bin
tools/decompress_persszp.py assets/us/8CC000/61.bin
tools/decompress_persszp.py assets/us/8CC000/62.bin
tools/decompress_persszp.py assets/us/pokemon_models/0.bin
tools/decompress_persszp.py assets/us/pokemon_models/1.bin
tools/decompress_persszp.py assets/us/pokemon_models/2.bin
tools/decompress_persszp.py assets/us/pokemon_models/3.bin
tools/decompress_persszp.py assets/us/pokemon_models/4.bin
tools/decompress_persszp.py assets/us/pokemon_models/5.bin
tools/decompress_persszp.py assets/us/pokemon_models/6.bin
tools/decompress_persszp.py assets/us/pokemon_models/7.bin
tools/decompress_persszp.py assets/us/pokemon_models/8.bin
tools/decompress_persszp.py assets/us/pokemon_models/9.bin
tools/decompress_persszp.py assets/us/pokemon_models/10.bin
tools/decompress_persszp.py assets/us/pokemon_models/11.bin
tools/decompress_persszp.py assets/us/pokemon_models/12.bin
tools/decompress_persszp.py assets/us/pokemon_models/13.bin
tools/decompress_persszp.py assets/us/pokemon_models/14.bin
tools/decompress_persszp.py assets/us/pokemon_models/15.bin
tools/decompress_persszp.py assets/us/pokemon_models/16.bin
tools/decompress_persszp.py assets/us/pokemon_models/17.bin
tools/decompress_persszp.py assets/us/pokemon_models/18.bin
tools/decompress_persszp.py assets/us/pokemon_models/19.bin
tools/decompress_persszp.py assets/us/pokemon_models/20.bin
tools/decompress_persszp.py assets/us/pokemon_models/21.bin
tools/decompress_persszp.py assets/us/pokemon_models/22.bin
tools/decompress_persszp.py assets/us/pokemon_models/23.bin
tools/decompress_persszp.py assets/us/pokemon_models/24.bin
tools/decompress_persszp.py assets/us/pokemon_models/25.bin
tools/decompress_persszp.py assets/us/pokemon_models/26.bin
tools/decompress_persszp.py assets/us/pokemon_models/27.bin
tools/decompress_persszp.py assets/us/pokemon_models/28.bin
tools/decompress_persszp.py assets/us/pokemon_models/29.bin
tools/decompress_persszp.py assets/us/pokemon_models/30.bin
tools/decompress_persszp.py assets/us/pokemon_models/31.bin
tools/decompress_persszp.py assets/us/pokemon_models/32.bin
tools/decompress_persszp.py assets/us/pokemon_models/33.bin
tools/decompress_persszp.py assets/us/pokemon_models/34.bin
tools/decompress_persszp.py assets/us/pokemon_models/35.bin
tools/decompress_persszp.py assets/us/pokemon_models/36.bin
tools/decompress_persszp.py assets/us/pokemon_models/37.bin
tools/decompress_persszp.py assets/us/pokemon_models/38.bin
tools/decompress_persszp.py assets/us/pokemon_models/39.bin
tools/decompress_persszp.py assets/us/pokemon_models/40.bin
tools/decompress_persszp.py assets/us/pokemon_models/41.bin
tools/decompress_persszp.py assets/us/pokemon_models/42.bin
tools/decompress_persszp.py assets/us/pokemon_models/43.bin
tools/decompress_persszp.py assets/us/pokemon_models/44.bin
tools/decompress_persszp.py assets/us/pokemon_models/45.bin
tools/decompress_persszp.py assets/us/pokemon_models/46.bin
tools/decompress_persszp.py assets/us/pokemon_models/47.bin
tools/decompress_persszp.py assets/us/pokemon_models/48.bin
tools/decompress_persszp.py assets/us/pokemon_models/49.bin
tools/decompress_persszp.py assets/us/pokemon_models/50.bin
tools/decompress_persszp.py assets/us/pokemon_models/51.bin
tools/decompress_persszp.py assets/us/pokemon_models/52.bin
tools/decompress_persszp.py assets/us/pokemon_models/53.bin
tools/decompress_persszp.py assets/us/pokemon_models/54.bin
tools/decompress_persszp.py assets/us/pokemon_models/55.bin
tools/decompress_persszp.py assets/us/pokemon_models/56.bin
tools/decompress_persszp.py assets/us/pokemon_models/57.bin
tools/decompress_persszp.py assets/us/pokemon_models/58.bin
tools/decompress_persszp.py assets/us/pokemon_models/59.bin
tools/decompress_persszp.py assets/us/pokemon_models/60.bin
tools/decompress_persszp.py assets/us/pokemon_models/61.bin
tools/decompress_persszp.py assets/us/pokemon_models/62.bin
tools/decompress_persszp.py assets/us/pokemon_models/63.bin
tools/decompress_persszp.py assets/us/pokemon_models/64.bin
tools/decompress_persszp.py assets/us/pokemon_models/65.bin
tools/decompress_persszp.py assets/us/pokemon_models/66.bin
tools/decompress_persszp.py assets/us/pokemon_models/67.bin
tools/decompress_persszp.py assets/us/pokemon_models/68.bin
tools/decompress_persszp.py assets/us/pokemon_models/69.bin
tools/decompress_persszp.py assets/us/pokemon_models/70.bin
tools/decompress_persszp.py assets/us/pokemon_models/71.bin
tools/decompress_persszp.py assets/us/pokemon_models/72.bin
tools/decompress_persszp.py assets/us/pokemon_models/73.bin
tools/decompress_persszp.py assets/us/pokemon_models/74.bin
tools/decompress_persszp.py assets/us/pokemon_models/75.bin
tools/decompress_persszp.py assets/us/pokemon_models/76.bin
tools/decompress_persszp.py assets/us/pokemon_models/77.bin
tools/decompress_persszp.py assets/us/pokemon_models/78.bin
tools/decompress_persszp.py assets/us/pokemon_models/79.bin
tools/decompress_persszp.py assets/us/pokemon_models/80.bin
tools/decompress_persszp.py assets/us/pokemon_models/81.bin
tools/decompress_persszp.py assets/us/pokemon_models/82.bin
tools/decompress_persszp.py assets/us/pokemon_models/83.bin
tools/decompress_persszp.py assets/us/pokemon_models/84.bin
tools/decompress_persszp.py assets/us/pokemon_models/85.bin
tools/decompress_persszp.py assets/us/pokemon_models/86.bin
tools/decompress_persszp.py assets/us/pokemon_models/87.bin
tools/decompress_persszp.py assets/us/pokemon_models/88.bin
tools/decompress_persszp.py assets/us/pokemon_models/89.bin
tools/decompress_persszp.py assets/us/pokemon_models/90.bin
tools/decompress_persszp.py assets/us/pokemon_models/91.bin
tools/decompress_persszp.py assets/us/pokemon_models/92.bin
tools/decompress_persszp.py assets/us/pokemon_models/93.bin
tools/decompress_persszp.py assets/us/pokemon_models/94.bin
tools/decompress_persszp.py assets/us/pokemon_models/95.bin
tools/decompress_persszp.py assets/us/pokemon_models/96.bin
tools/decompress_persszp.py assets/us/pokemon_models/97.bin
tools/decompress_persszp.py assets/us/pokemon_models/98.bin
tools/decompress_persszp.py assets/us/pokemon_models/99.bin
tools/decompress_persszp.py assets/us/pokemon_models/100.bin
tools/decompress_persszp.py assets/us/pokemon_models/101.bin
tools/decompress_persszp.py assets/us/pokemon_models/102.bin
tools/decompress_persszp.py assets/us/pokemon_models/103.bin
tools/decompress_persszp.py assets/us/pokemon_models/104.bin
tools/decompress_persszp.py assets/us/pokemon_models/105.bin
tools/decompress_persszp.py assets/us/pokemon_models/106.bin
tools/decompress_persszp.py assets/us/pokemon_models/107.bin
tools/decompress_persszp.py assets/us/pokemon_models/108.bin
tools/decompress_persszp.py assets/us/pokemon_models/109.bin
tools/decompress_persszp.py assets/us/pokemon_models/110.bin
tools/decompress_persszp.py assets/us/pokemon_models/111.bin
tools/decompress_persszp.py assets/us/pokemon_models/112.bin
tools/decompress_persszp.py assets/us/pokemon_models/113.bin
tools/decompress_persszp.py assets/us/pokemon_models/114.bin
tools/decompress_persszp.py assets/us/pokemon_models/115.bin
tools/decompress_persszp.py assets/us/pokemon_models/116.bin
tools/decompress_persszp.py assets/us/pokemon_models/117.bin
tools/decompress_persszp.py assets/us/pokemon_models/118.bin
tools/decompress_persszp.py assets/us/pokemon_models/119.bin
#tools/decompress_persszp.py assets/us/920000/120.bin this file is just randomly not compressed. Thanks for breaking the uniform asset pattern, HAL.
tools/decompress_persszp.py assets/us/pokemon_models/121.bin
tools/decompress_persszp.py assets/us/pokemon_models/122.bin
tools/decompress_persszp.py assets/us/pokemon_models/123.bin
tools/decompress_persszp.py assets/us/pokemon_models/124.bin
tools/decompress_persszp.py assets/us/pokemon_models/125.bin
tools/decompress_persszp.py assets/us/pokemon_models/126.bin
tools/decompress_persszp.py assets/us/pokemon_models/127.bin
tools/decompress_persszp.py assets/us/pokemon_models/128.bin
tools/decompress_persszp.py assets/us/pokemon_models/129.bin
tools/decompress_persszp.py assets/us/pokemon_models/130.bin
tools/decompress_persszp.py assets/us/pokemon_models/131.bin
tools/decompress_persszp.py assets/us/pokemon_models/132.bin
tools/decompress_persszp.py assets/us/pokemon_models/133.bin
tools/decompress_persszp.py assets/us/pokemon_models/134.bin
tools/decompress_persszp.py assets/us/pokemon_models/135.bin
tools/decompress_persszp.py assets/us/pokemon_models/136.bin
tools/decompress_persszp.py assets/us/pokemon_models/137.bin
tools/decompress_persszp.py assets/us/pokemon_models/138.bin
tools/decompress_persszp.py assets/us/pokemon_models/139.bin
tools/decompress_persszp.py assets/us/pokemon_models/140.bin
tools/decompress_persszp.py assets/us/pokemon_models/141.bin
tools/decompress_persszp.py assets/us/pokemon_models/142.bin
tools/decompress_persszp.py assets/us/pokemon_models/143.bin
tools/decompress_persszp.py assets/us/pokemon_models/144.bin
tools/decompress_persszp.py assets/us/pokemon_models/145.bin
tools/decompress_persszp.py assets/us/pokemon_models/146.bin
tools/decompress_persszp.py assets/us/pokemon_models/147.bin
tools/decompress_persszp.py assets/us/pokemon_models/148.bin
tools/decompress_persszp.py assets/us/pokemon_models/149.bin
tools/decompress_persszp.py assets/us/pokemon_models/150.bin
tools/decompress_persszp.py assets/us/pokemon_models/151.bin
tools/decompress_persszp.py assets/us/pokemon_models/152.bin
tools/decompress_persszp.py assets/us/pokemon_models/153.bin
tools/decompress_persszp.py assets/us/pokemon_models/154.bin
tools/decompress_persszp.py assets/us/pokemon_models/155.bin
tools/decompress_persszp.py assets/us/pokemon_models/156.bin
tools/decompress_persszp.py assets/us/pokemon_models/157.bin
tools/decompress_persszp.py assets/us/pokemon_models/158.bin
tools/decompress_persszp.py assets/us/pokemon_models/159.bin
tools/decompress_persszp.py assets/us/pokemon_models/160.bin
tools/decompress_persszp.py assets/us/pokemon_models/161.bin
tools/decompress_persszp.py assets/us/pokemon_models/162.bin
tools/decompress_persszp.py assets/us/pokemon_models/163.bin
tools/decompress_persszp.py assets/us/pokemon_models/164.bin
tools/decompress_persszp.py assets/us/pokemon_models/165.bin
tools/decompress_persszp.py assets/us/pokemon_models/166.bin
tools/decompress_persszp.py assets/us/pokemon_models/167.bin
tools/decompress_persszp.py assets/us/pokemon_models/168.bin
tools/decompress_persszp.py assets/us/pokemon_models/169.bin
tools/decompress_persszp.py assets/us/pokemon_models/170.bin
tools/decompress_persszp.py assets/us/pokemon_models/171.bin
tools/decompress_persszp.py assets/us/pokemon_models/172.bin
tools/decompress_persszp.py assets/us/pokemon_models/173.bin
tools/decompress_persszp.py assets/us/pokemon_models/174.bin
tools/decompress_persszp.py assets/us/pokemon_models/175.bin
tools/decompress_persszp.py assets/us/pokemon_models/176.bin
tools/decompress_persszp.py assets/us/pokemon_models/177.bin
tools/decompress_persszp.py assets/us/pokemon_models/178.bin
tools/decompress_persszp.py assets/us/pokemon_models/179.bin
tools/decompress_persszp.py assets/us/pokemon_models/180.bin
tools/decompress_persszp.py assets/us/pokemon_models/181.bin
tools/decompress_persszp.py assets/us/pokemon_models/182.bin
tools/decompress_persszp.py assets/us/pokemon_models/183.bin
tools/decompress_persszp.py assets/us/pokemon_models/184.bin
tools/decompress_persszp.py assets/us/pokemon_models/185.bin
tools/decompress_persszp.py assets/us/pokemon_models/186.bin
tools/decompress_persszp.py assets/us/pokemon_models/187.bin
tools/decompress_persszp.py assets/us/pokemon_models/188.bin
tools/decompress_persszp.py assets/us/pokemon_models/189.bin
tools/decompress_persszp.py assets/us/pokemon_models/190.bin
tools/decompress_persszp.py assets/us/pokemon_models/191.bin
tools/decompress_persszp.py assets/us/pokemon_models/192.bin
tools/decompress_persszp.py assets/us/pokemon_models/193.bin
tools/decompress_persszp.py assets/us/pokemon_models/194.bin
tools/decompress_persszp.py assets/us/pokemon_models/195.bin
tools/decompress_persszp.py assets/us/pokemon_models/196.bin
tools/decompress_persszp.py assets/us/pokemon_models/197.bin
tools/decompress_persszp.py assets/us/pokemon_models/198.bin
tools/decompress_persszp.py assets/us/pokemon_models/199.bin
tools/decompress_persszp.py assets/us/pokemon_models/200.bin
tools/decompress_persszp.py assets/us/pokemon_models/201.bin
tools/decompress_persszp.py assets/us/pokemon_models/202.bin
tools/decompress_persszp.py assets/us/pokemon_models/203.bin
tools/decompress_persszp.py assets/us/pokemon_models/204.bin
tools/decompress_persszp.py assets/us/pokemon_models/205.bin
tools/decompress_persszp.py assets/us/pokemon_models/206.bin
tools/decompress_persszp.py assets/us/pokemon_models/207.bin
tools/decompress_persszp.py assets/us/pokemon_models/208.bin
tools/decompress_persszp.py assets/us/pokemon_models/209.bin
tools/decompress_persszp.py assets/us/pokemon_models/210.bin
tools/decompress_persszp.py assets/us/pokemon_models/211.bin
tools/decompress_persszp.py assets/us/pokemon_models/212.bin
tools/decompress_persszp.py assets/us/pokemon_models/213.bin
tools/decompress_persszp.py assets/us/pokemon_models/214.bin

# Extract all PRESJPEG files.
tools/extract_presjpeg.py assets/us/backgrounds/0.bin
tools/extract_presjpeg.py assets/us/backgrounds/1.bin
tools/extract_presjpeg.py assets/us/backgrounds/2.bin
tools/extract_presjpeg.py assets/us/backgrounds/3.bin
tools/extract_presjpeg.py assets/us/backgrounds/4.bin
tools/extract_presjpeg.py assets/us/backgrounds/5.bin
tools/extract_presjpeg.py assets/us/backgrounds/6.bin
tools/extract_presjpeg.py assets/us/backgrounds/7.bin
tools/extract_presjpeg.py assets/us/backgrounds/8.bin
tools/extract_presjpeg.py assets/us/backgrounds/9.bin
tools/extract_presjpeg.py assets/us/backgrounds/10.bin
tools/extract_presjpeg.py assets/us/backgrounds/11.bin
tools/extract_presjpeg.py assets/us/backgrounds/12.bin
tools/extract_presjpeg.py assets/us/backgrounds/13.bin
tools/extract_presjpeg.py assets/us/backgrounds/14.bin
tools/extract_presjpeg.py assets/us/backgrounds/15.bin
tools/extract_presjpeg.py assets/us/backgrounds/16.bin
tools/extract_presjpeg.py assets/us/backgrounds/17.bin
tools/extract_presjpeg.py assets/us/backgrounds/18.bin
tools/extract_presjpeg.py assets/us/backgrounds/19.bin
tools/extract_presjpeg.py assets/us/backgrounds/20.bin
tools/extract_presjpeg.py assets/us/6CA730/0.bin
tools/extract_presjpeg.py assets/us/6CA730/1.bin
tools/extract_presjpeg.py assets/us/6CA730/2.bin
tools/extract_presjpeg.py assets/us/6CA730/3.bin
tools/extract_presjpeg.py assets/us/6CA730/4.bin
tools/extract_presjpeg.py assets/us/6CA730/5.bin
tools/extract_presjpeg.py assets/us/6CA730/6.bin
tools/extract_presjpeg.py assets/us/6CA730/7.bin
tools/extract_presjpeg.py assets/us/6CA730/8.bin
tools/extract_presjpeg.py assets/us/6CA730/9.bin
tools/extract_presjpeg.py assets/us/6CA730/10.bin
tools/extract_presjpeg.py assets/us/6CA730/11.bin
tools/extract_presjpeg.py assets/us/6CA730/12.bin
tools/extract_presjpeg.py assets/us/6CA730/13.bin
tools/extract_presjpeg.py assets/us/6CA730/14.bin
tools/extract_presjpeg.py assets/us/6CA730/15.bin

# Decompress raw Yay0s
tools/decompress_yay0.py assets/us/rom_parts/0.bin assets/us/rom_parts/0.bin
tools/decompress_yay0.py assets/us/rom_parts/1.bin assets/us/rom_parts/1.bin
tools/decompress_yay0.py assets/us/rom_parts/2.bin assets/us/rom_parts/2.bin
tools/decompress_yay0.py assets/us/rom_parts/3.bin assets/us/rom_parts/3.bin
tools/decompress_yay0.py assets/us/rom_parts/4.bin assets/us/rom_parts/4.bin
tools/decompress_yay0.py assets/us/rom_parts/5.bin assets/us/rom_parts/5.bin
tools/decompress_yay0.py assets/us/rom_parts/6.bin assets/us/rom_parts/6.bin
tools/decompress_yay0.py assets/us/rom_parts/7.bin assets/us/rom_parts/7.bin
tools/decompress_yay0.py assets/us/rom_parts/8.bin assets/us/rom_parts/8.bin
tools/decompress_yay0.py assets/us/rom_parts/9.bin assets/us/rom_parts/9.bin
tools/decompress_yay0.py assets/us/rom_parts/10.bin assets/us/rom_parts/10.bin
tools/decompress_yay0.py assets/us/rom_parts/11.bin assets/us/rom_parts/11.bin
tools/decompress_yay0.py assets/us/rom_parts/12.bin assets/us/rom_parts/12.bin
tools/decompress_yay0.py assets/us/rom_parts/13.bin assets/us/rom_parts/13.bin
tools/decompress_yay0.py assets/us/rom_parts/14.bin assets/us/rom_parts/14.bin
tools/decompress_yay0.py assets/us/rom_parts/15.bin assets/us/rom_parts/15.bin
tools/decompress_yay0.py assets/us/rom_parts/16.bin assets/us/rom_parts/16.bin
tools/decompress_yay0.py assets/us/rom_parts/17.bin assets/us/rom_parts/17.bin
tools/decompress_yay0.py assets/us/rom_parts/18.bin assets/us/rom_parts/18.bin
tools/decompress_yay0.py assets/us/rom_parts/19.bin assets/us/rom_parts/19.bin
tools/decompress_yay0.py assets/us/rom_parts/20.bin assets/us/rom_parts/20.bin
tools/decompress_yay0.py assets/us/rom_parts/21.bin assets/us/rom_parts/21.bin
tools/decompress_yay0.py assets/us/rom_parts/22.bin assets/us/rom_parts/22.bin
tools/decompress_yay0.py assets/us/rom_parts/23.bin assets/us/rom_parts/23.bin
tools/decompress_yay0.py assets/us/rom_parts/24.bin assets/us/rom_parts/24.bin
tools/decompress_yay0.py assets/us/rom_parts/25.bin assets/us/rom_parts/25.bin
tools/decompress_yay0.py assets/us/rom_parts/26.bin assets/us/rom_parts/26.bin
tools/decompress_yay0.py assets/us/rom_parts/27.bin assets/us/rom_parts/27.bin
tools/decompress_yay0.py assets/us/rom_parts/28.bin assets/us/rom_parts/28.bin
tools/decompress_yay0.py assets/us/rom_parts/29.bin assets/us/rom_parts/29.bin
tools/decompress_yay0.py assets/us/rom_parts/30.bin assets/us/rom_parts/30.bin
tools/decompress_yay0.py assets/us/rom_parts/31.bin assets/us/rom_parts/31.bin
tools/decompress_yay0.py assets/us/rom_parts/32.bin assets/us/rom_parts/32.bin
tools/decompress_yay0.py assets/us/rom_parts/33.bin assets/us/rom_parts/33.bin
tools/decompress_yay0.py assets/us/rom_parts/34.bin assets/us/rom_parts/34.bin
tools/decompress_yay0.py assets/us/rom_parts/35.bin assets/us/rom_parts/35.bin
tools/decompress_yay0.py assets/us/rom_parts/36.bin assets/us/rom_parts/36.bin
tools/decompress_yay0.py assets/us/rom_parts/37.bin assets/us/rom_parts/37.bin
tools/decompress_yay0.py assets/us/rom_parts/38.bin assets/us/rom_parts/38.bin
tools/decompress_yay0.py assets/us/rom_parts/39.bin assets/us/rom_parts/39.bin
tools/decompress_yay0.py assets/us/rom_parts/40.bin assets/us/rom_parts/40.bin
tools/decompress_yay0.py assets/us/rom_parts/41.bin assets/us/rom_parts/41.bin
tools/decompress_yay0.py assets/us/rom_parts/42.bin assets/us/rom_parts/42.bin
tools/decompress_yay0.py assets/us/rom_parts/43.bin assets/us/rom_parts/43.bin
tools/decompress_yay0.py assets/us/rom_parts/44.bin assets/us/rom_parts/44.bin
tools/decompress_yay0.py assets/us/rom_parts/45.bin assets/us/rom_parts/45.bin
tools/decompress_yay0.py assets/us/rom_parts/46.bin assets/us/rom_parts/46.bin
tools/decompress_yay0.py assets/us/rom_parts/47.bin assets/us/rom_parts/47.bin
tools/decompress_yay0.py assets/us/rom_parts/48.bin assets/us/rom_parts/48.bin
tools/decompress_yay0.py assets/us/rom_parts/49.bin assets/us/rom_parts/49.bin
tools/decompress_yay0.py assets/us/rom_parts/50.bin assets/us/rom_parts/50.bin
tools/decompress_yay0.py assets/us/rom_parts/51.bin assets/us/rom_parts/51.bin
tools/decompress_yay0.py assets/us/rom_parts/52.bin assets/us/rom_parts/52.bin
