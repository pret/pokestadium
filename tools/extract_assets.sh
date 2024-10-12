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
tools/unpack_asset.py assets/us/920000.bin

# Next, decompress all the PERS-SZP files with a Yay0. TODO: Roll these up
# into recursive calls. All of the files within an asset bin SHOULD be the
# same type, but it in theory it isnt guaranteed to be. Does the game ensure
# that? If so, we should be able to safely roll these up.
tools/decompress_persszp.py assets/us/n64_logo_texture/0/file.bin
tools/decompress_persszp.py assets/us/fonts/0/file.bin
tools/decompress_persszp.py assets/us/fonts/1/file.bin
tools/decompress_persszp.py assets/us/fonts/2/file.bin
tools/decompress_persszp.py assets/us/fonts/3/file.bin
tools/decompress_persszp.py assets/us/fonts/4/file.bin
tools/decompress_persszp.py assets/us/fonts/5/file.bin
tools/decompress_persszp.py assets/us/battle_headers/0/file.bin
tools/decompress_persszp.py assets/us/battle_headers/1/file.bin
tools/decompress_persszp.py assets/us/battle_headers/2/file.bin
tools/decompress_persszp.py assets/us/battle_headers/3/file.bin
tools/decompress_persszp.py assets/us/battle_headers/4/file.bin
tools/decompress_persszp.py assets/us/battle_headers/5/file.bin
tools/decompress_persszp.py assets/us/battle_headers/6/file.bin
tools/decompress_persszp.py assets/us/battle_headers/7/file.bin
tools/decompress_persszp.py assets/us/battle_headers/8/file.bin
tools/decompress_persszp.py assets/us/battle_headers/9/file.bin
tools/decompress_persszp.py assets/us/battle_headers/10/file.bin
tools/decompress_persszp.py assets/us/battle_headers/11/file.bin
tools/decompress_persszp.py assets/us/battle_headers/12/file.bin
tools/decompress_persszp.py assets/us/common_menu0_ui/0/file.bin
tools/decompress_persszp.py assets/us/common_menu1_ui/0/file.bin
tools/decompress_persszp.py assets/us/common_menu2_ui/0/file.bin
tools/decompress_persszp.py assets/us/area_select_ui/0/file.bin
tools/decompress_persszp.py assets/us/menu_select_ui/0/file.bin
tools/decompress_persszp.py assets/us/stadium_select_ui/0/file.bin
tools/decompress_persszp.py assets/us/title_ui/0/file.bin
tools/decompress_persszp.py assets/us/52F6D0/0/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/0/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/1/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/2/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/3/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/4/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/5/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/6/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/7/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/8/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/9/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/10/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/11/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/12/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/13/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/14/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/15/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/16/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/17/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/18/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/19/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/20/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/21/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/22/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/23/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/24/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/25/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/26/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/27/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/28/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/29/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/30/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/31/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/32/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/33/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/34/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/35/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/36/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/37/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/38/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/39/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/40/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/41/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/42/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/43/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/44/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/45/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/46/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/47/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/48/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/49/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/50/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/51/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/52/file.bin
tools/decompress_persszp.py assets/us/battle_portraits/53/file.bin
tools/decompress_persszp.py assets/us/stadium_models/0/file.bin
tools/decompress_persszp.py assets/us/stadium_models/1/file.bin
tools/decompress_persszp.py assets/us/stadium_models/2/file.bin
tools/decompress_persszp.py assets/us/stadium_models/3/file.bin
tools/decompress_persszp.py assets/us/stadium_models/4/file.bin
tools/decompress_persszp.py assets/us/stadium_models/5/file.bin
tools/decompress_persszp.py assets/us/stadium_models/6/file.bin
tools/decompress_persszp.py assets/us/stadium_models/7/file.bin
tools/decompress_persszp.py assets/us/stadium_models/8/file.bin
tools/decompress_persszp.py assets/us/stadium_models/9/file.bin
tools/decompress_persszp.py assets/us/stadium_models/10/file.bin
tools/decompress_persszp.py assets/us/stadium_models/11/file.bin
tools/decompress_persszp.py assets/us/stadium_models/12/file.bin
tools/decompress_persszp.py assets/us/stadium_models/13/file.bin
tools/decompress_persszp.py assets/us/stadium_models/14/file.bin
tools/decompress_persszp.py assets/us/stadium_models/15/file.bin
tools/decompress_persszp.py assets/us/stadium_models/16/file.bin
tools/decompress_persszp.py assets/us/stadium_models/17/file.bin
tools/decompress_persszp.py assets/us/5C7A70/0/file.bin
tools/decompress_persszp.py assets/us/pokedex_area_model/0/file.bin
tools/decompress_persszp.py assets/us/sushi_go_round/0/file.bin
tools/decompress_persszp.py assets/us/order_select_ui/0/file.bin
tools/decompress_persszp.py assets/us/cup_ball_select_ui/0/file.bin
tools/decompress_persszp.py assets/us/trade_select_ui/0/file.bin
tools/decompress_persszp.py assets/us/kids_club_select_ui/0/file.bin
tools/decompress_persszp.py assets/us/gym_leader_castle_clear_gfx/0/file.bin
tools/decompress_persszp.py assets/us/rental_rules_ui/0/file.bin
tools/decompress_persszp.py assets/us/sushi_go_round_sprites/0/file.bin
tools/decompress_persszp.py assets/us/kids_club_game_ui/0/file.bin
tools/decompress_persszp.py assets/us/gallery_ui/0/file.bin
tools/decompress_persszp.py assets/us/album_ui/0/file.bin
tools/decompress_persszp.py assets/us/6A9750/0/file.bin
tools/decompress_persszp.py assets/us/snap_select_ui/0/file.bin
tools/decompress_persszp.py assets/us/cup_clear_ui/0/file.bin
tools/decompress_persszp.py assets/us/gb_pak_select_ui/0/file.bin
tools/decompress_persszp.py assets/us/victory_palace_plate_text/0/file.bin
tools/decompress_persszp.py assets/us/run_rattata_run_flag_gfx/0/file.bin
tools/decompress_persszp.py assets/us/kanto_gb_map/0/file.bin
tools/decompress_persszp.py assets/us/6E2F90/0/file.bin
tools/decompress_persszp.py assets/us/battle_ui/0/file.bin
tools/decompress_persszp.py assets/us/transfer_pak_error_ui/0/file.bin
tools/decompress_persszp.py assets/us/6EB340/0/file.bin
tools/decompress_persszp.py assets/us/6EB340/1/file.bin
tools/decompress_persszp.py assets/us/6EB340/2/file.bin
tools/decompress_persszp.py assets/us/6EB340/3/file.bin
tools/decompress_persszp.py assets/us/6EC4D0/0/file.bin
tools/decompress_persszp.py assets/us/badge_ui/0/file.bin
tools/decompress_persszp.py assets/us/gym_leader_castle_ui/0/file.bin
tools/decompress_persszp.py assets/us/798CD0/0/file.bin
tools/decompress_persszp.py assets/us/snap_mode_ui/0/file.bin
tools/decompress_persszp.py assets/us/copyright/0/file.bin

# Decompress PERS-SZP files in late asset(s).
tools/decompress_persszp.py assets/us/8CC000/0/file.bin
tools/decompress_persszp.py assets/us/8CC000/1/file.bin
tools/decompress_persszp.py assets/us/8CC000/2/file.bin
tools/decompress_persszp.py assets/us/8CC000/3/file.bin
tools/decompress_persszp.py assets/us/8CC000/4/file.bin
tools/decompress_persszp.py assets/us/8CC000/5/file.bin
tools/decompress_persszp.py assets/us/8CC000/6/file.bin
tools/decompress_persszp.py assets/us/8CC000/7/file.bin
tools/decompress_persszp.py assets/us/8CC000/8/file.bin
tools/decompress_persszp.py assets/us/8CC000/9/file.bin
tools/decompress_persszp.py assets/us/8CC000/10/file.bin
tools/decompress_persszp.py assets/us/8CC000/11/file.bin
tools/decompress_persszp.py assets/us/8CC000/12/file.bin
tools/decompress_persszp.py assets/us/8CC000/13/file.bin
tools/decompress_persszp.py assets/us/8CC000/14/file.bin
tools/decompress_persszp.py assets/us/8CC000/15/file.bin
tools/decompress_persszp.py assets/us/8CC000/16/file.bin
tools/decompress_persszp.py assets/us/8CC000/17/file.bin
tools/decompress_persszp.py assets/us/8CC000/18/file.bin
tools/decompress_persszp.py assets/us/8CC000/19/file.bin
tools/decompress_persszp.py assets/us/8CC000/20/file.bin
tools/decompress_persszp.py assets/us/8CC000/21/file.bin
tools/decompress_persszp.py assets/us/8CC000/22/file.bin
tools/decompress_persszp.py assets/us/8CC000/23/file.bin
tools/decompress_persszp.py assets/us/8CC000/24/file.bin
tools/decompress_persszp.py assets/us/8CC000/25/file.bin
tools/decompress_persszp.py assets/us/8CC000/26/file.bin
tools/decompress_persszp.py assets/us/8CC000/27/file.bin
tools/decompress_persszp.py assets/us/8CC000/28/file.bin
tools/decompress_persszp.py assets/us/8CC000/29/file.bin
tools/decompress_persszp.py assets/us/8CC000/30/file.bin
tools/decompress_persszp.py assets/us/8CC000/31/file.bin
tools/decompress_persszp.py assets/us/8CC000/32/file.bin
tools/decompress_persszp.py assets/us/8CC000/33/file.bin
tools/decompress_persszp.py assets/us/8CC000/34/file.bin
tools/decompress_persszp.py assets/us/8CC000/35/file.bin
tools/decompress_persszp.py assets/us/8CC000/36/file.bin
tools/decompress_persszp.py assets/us/8CC000/37/file.bin
tools/decompress_persszp.py assets/us/8CC000/38/file.bin
tools/decompress_persszp.py assets/us/8CC000/39/file.bin
tools/decompress_persszp.py assets/us/8CC000/40/file.bin
tools/decompress_persszp.py assets/us/8CC000/41/file.bin
tools/decompress_persszp.py assets/us/8CC000/42/file.bin
tools/decompress_persszp.py assets/us/8CC000/43/file.bin
tools/decompress_persszp.py assets/us/8CC000/44/file.bin
tools/decompress_persszp.py assets/us/8CC000/45/file.bin
tools/decompress_persszp.py assets/us/8CC000/46/file.bin
tools/decompress_persszp.py assets/us/8CC000/47/file.bin
tools/decompress_persszp.py assets/us/8CC000/48/file.bin
tools/decompress_persszp.py assets/us/8CC000/49/file.bin
tools/decompress_persszp.py assets/us/8CC000/50/file.bin
tools/decompress_persszp.py assets/us/8CC000/51/file.bin
tools/decompress_persszp.py assets/us/8CC000/52/file.bin
tools/decompress_persszp.py assets/us/8CC000/53/file.bin
tools/decompress_persszp.py assets/us/8CC000/54/file.bin
tools/decompress_persszp.py assets/us/8CC000/55/file.bin
tools/decompress_persszp.py assets/us/8CC000/56/file.bin
tools/decompress_persszp.py assets/us/8CC000/57/file.bin
tools/decompress_persszp.py assets/us/8CC000/58/file.bin
tools/decompress_persszp.py assets/us/8CC000/59/file.bin
tools/decompress_persszp.py assets/us/8CC000/60/file.bin
tools/decompress_persszp.py assets/us/8CC000/61/file.bin
tools/decompress_persszp.py assets/us/8CC000/62/file.bin
tools/decompress_persszp.py assets/us/920000/0/file.bin
tools/decompress_persszp.py assets/us/920000/1/file.bin
tools/decompress_persszp.py assets/us/920000/2/file.bin
tools/decompress_persszp.py assets/us/920000/3/file.bin
tools/decompress_persszp.py assets/us/920000/4/file.bin
tools/decompress_persszp.py assets/us/920000/5/file.bin
tools/decompress_persszp.py assets/us/920000/6/file.bin
tools/decompress_persszp.py assets/us/920000/7/file.bin
tools/decompress_persszp.py assets/us/920000/8/file.bin
tools/decompress_persszp.py assets/us/920000/9/file.bin
tools/decompress_persszp.py assets/us/920000/10/file.bin
tools/decompress_persszp.py assets/us/920000/11/file.bin
tools/decompress_persszp.py assets/us/920000/12/file.bin
tools/decompress_persszp.py assets/us/920000/13/file.bin
tools/decompress_persszp.py assets/us/920000/14/file.bin
tools/decompress_persszp.py assets/us/920000/15/file.bin
tools/decompress_persszp.py assets/us/920000/16/file.bin
tools/decompress_persszp.py assets/us/920000/17/file.bin
tools/decompress_persszp.py assets/us/920000/18/file.bin
tools/decompress_persszp.py assets/us/920000/19/file.bin
tools/decompress_persszp.py assets/us/920000/20/file.bin
tools/decompress_persszp.py assets/us/920000/21/file.bin
tools/decompress_persszp.py assets/us/920000/22/file.bin
tools/decompress_persszp.py assets/us/920000/23/file.bin
tools/decompress_persszp.py assets/us/920000/24/file.bin
tools/decompress_persszp.py assets/us/920000/25/file.bin
tools/decompress_persszp.py assets/us/920000/26/file.bin
tools/decompress_persszp.py assets/us/920000/27/file.bin
tools/decompress_persszp.py assets/us/920000/28/file.bin
tools/decompress_persszp.py assets/us/920000/29/file.bin
tools/decompress_persszp.py assets/us/920000/30/file.bin
tools/decompress_persszp.py assets/us/920000/31/file.bin
tools/decompress_persszp.py assets/us/920000/32/file.bin
tools/decompress_persszp.py assets/us/920000/33/file.bin
tools/decompress_persszp.py assets/us/920000/34/file.bin
tools/decompress_persszp.py assets/us/920000/35/file.bin
tools/decompress_persszp.py assets/us/920000/36/file.bin
tools/decompress_persszp.py assets/us/920000/37/file.bin
tools/decompress_persszp.py assets/us/920000/38/file.bin
tools/decompress_persszp.py assets/us/920000/39/file.bin
tools/decompress_persszp.py assets/us/920000/40/file.bin
tools/decompress_persszp.py assets/us/920000/41/file.bin
tools/decompress_persszp.py assets/us/920000/42/file.bin
tools/decompress_persszp.py assets/us/920000/43/file.bin
tools/decompress_persszp.py assets/us/920000/44/file.bin
tools/decompress_persszp.py assets/us/920000/45/file.bin
tools/decompress_persszp.py assets/us/920000/46/file.bin
tools/decompress_persszp.py assets/us/920000/47/file.bin
tools/decompress_persszp.py assets/us/920000/48/file.bin
tools/decompress_persszp.py assets/us/920000/49/file.bin
tools/decompress_persszp.py assets/us/920000/50/file.bin
tools/decompress_persszp.py assets/us/920000/51/file.bin
tools/decompress_persszp.py assets/us/920000/52/file.bin
tools/decompress_persszp.py assets/us/920000/53/file.bin
tools/decompress_persszp.py assets/us/920000/54/file.bin
tools/decompress_persszp.py assets/us/920000/55/file.bin
tools/decompress_persszp.py assets/us/920000/56/file.bin
tools/decompress_persszp.py assets/us/920000/57/file.bin
tools/decompress_persszp.py assets/us/920000/58/file.bin
tools/decompress_persszp.py assets/us/920000/59/file.bin
tools/decompress_persszp.py assets/us/920000/60/file.bin
tools/decompress_persszp.py assets/us/920000/61/file.bin
tools/decompress_persszp.py assets/us/920000/62/file.bin
tools/decompress_persszp.py assets/us/920000/63/file.bin
tools/decompress_persszp.py assets/us/920000/64/file.bin
tools/decompress_persszp.py assets/us/920000/65/file.bin
tools/decompress_persszp.py assets/us/920000/66/file.bin
tools/decompress_persszp.py assets/us/920000/67/file.bin
tools/decompress_persszp.py assets/us/920000/68/file.bin
tools/decompress_persszp.py assets/us/920000/69/file.bin
tools/decompress_persszp.py assets/us/920000/70/file.bin
tools/decompress_persszp.py assets/us/920000/71/file.bin
tools/decompress_persszp.py assets/us/920000/72/file.bin
tools/decompress_persszp.py assets/us/920000/73/file.bin
tools/decompress_persszp.py assets/us/920000/74/file.bin
tools/decompress_persszp.py assets/us/920000/75/file.bin
tools/decompress_persszp.py assets/us/920000/76/file.bin
tools/decompress_persszp.py assets/us/920000/77/file.bin
tools/decompress_persszp.py assets/us/920000/78/file.bin
tools/decompress_persszp.py assets/us/920000/79/file.bin
tools/decompress_persszp.py assets/us/920000/80/file.bin
tools/decompress_persszp.py assets/us/920000/81/file.bin
tools/decompress_persszp.py assets/us/920000/82/file.bin
tools/decompress_persszp.py assets/us/920000/83/file.bin
tools/decompress_persszp.py assets/us/920000/84/file.bin
tools/decompress_persszp.py assets/us/920000/85/file.bin
tools/decompress_persszp.py assets/us/920000/86/file.bin
tools/decompress_persszp.py assets/us/920000/87/file.bin
tools/decompress_persszp.py assets/us/920000/88/file.bin
tools/decompress_persszp.py assets/us/920000/89/file.bin
tools/decompress_persszp.py assets/us/920000/90/file.bin
tools/decompress_persszp.py assets/us/920000/91/file.bin
tools/decompress_persszp.py assets/us/920000/92/file.bin
tools/decompress_persszp.py assets/us/920000/93/file.bin
tools/decompress_persszp.py assets/us/920000/94/file.bin
tools/decompress_persszp.py assets/us/920000/95/file.bin
tools/decompress_persszp.py assets/us/920000/96/file.bin
tools/decompress_persszp.py assets/us/920000/97/file.bin
tools/decompress_persszp.py assets/us/920000/98/file.bin
tools/decompress_persszp.py assets/us/920000/99/file.bin
tools/decompress_persszp.py assets/us/920000/100/file.bin
tools/decompress_persszp.py assets/us/920000/101/file.bin
tools/decompress_persszp.py assets/us/920000/102/file.bin
tools/decompress_persszp.py assets/us/920000/103/file.bin
tools/decompress_persszp.py assets/us/920000/104/file.bin
tools/decompress_persszp.py assets/us/920000/105/file.bin
tools/decompress_persszp.py assets/us/920000/106/file.bin
tools/decompress_persszp.py assets/us/920000/107/file.bin
tools/decompress_persszp.py assets/us/920000/108/file.bin
tools/decompress_persszp.py assets/us/920000/109/file.bin
tools/decompress_persszp.py assets/us/920000/110/file.bin
tools/decompress_persszp.py assets/us/920000/111/file.bin
tools/decompress_persszp.py assets/us/920000/112/file.bin
tools/decompress_persszp.py assets/us/920000/113/file.bin
tools/decompress_persszp.py assets/us/920000/114/file.bin
tools/decompress_persszp.py assets/us/920000/115/file.bin
tools/decompress_persszp.py assets/us/920000/116/file.bin
tools/decompress_persszp.py assets/us/920000/117/file.bin
tools/decompress_persszp.py assets/us/920000/118/file.bin
tools/decompress_persszp.py assets/us/920000/119/file.bin
#tools/decompress_persszp.py assets/us/920000/120/file.bin this file is just randomly not compressed. Thanks for breaking the uniform asset pattern, HAL.
tools/decompress_persszp.py assets/us/920000/121/file.bin
tools/decompress_persszp.py assets/us/920000/122/file.bin
tools/decompress_persszp.py assets/us/920000/123/file.bin
tools/decompress_persszp.py assets/us/920000/124/file.bin
tools/decompress_persszp.py assets/us/920000/125/file.bin
tools/decompress_persszp.py assets/us/920000/126/file.bin
tools/decompress_persszp.py assets/us/920000/127/file.bin
tools/decompress_persszp.py assets/us/920000/128/file.bin
tools/decompress_persszp.py assets/us/920000/129/file.bin
tools/decompress_persszp.py assets/us/920000/130/file.bin
tools/decompress_persszp.py assets/us/920000/131/file.bin
tools/decompress_persszp.py assets/us/920000/132/file.bin
tools/decompress_persszp.py assets/us/920000/133/file.bin
tools/decompress_persszp.py assets/us/920000/134/file.bin
tools/decompress_persszp.py assets/us/920000/135/file.bin
tools/decompress_persszp.py assets/us/920000/136/file.bin
tools/decompress_persszp.py assets/us/920000/137/file.bin
tools/decompress_persszp.py assets/us/920000/138/file.bin
tools/decompress_persszp.py assets/us/920000/139/file.bin
tools/decompress_persszp.py assets/us/920000/140/file.bin
tools/decompress_persszp.py assets/us/920000/141/file.bin
tools/decompress_persszp.py assets/us/920000/142/file.bin
tools/decompress_persszp.py assets/us/920000/143/file.bin
tools/decompress_persszp.py assets/us/920000/144/file.bin
tools/decompress_persszp.py assets/us/920000/145/file.bin
tools/decompress_persszp.py assets/us/920000/146/file.bin
tools/decompress_persszp.py assets/us/920000/147/file.bin
tools/decompress_persszp.py assets/us/920000/148/file.bin
tools/decompress_persszp.py assets/us/920000/149/file.bin
tools/decompress_persszp.py assets/us/920000/150/file.bin
tools/decompress_persszp.py assets/us/920000/151/file.bin
tools/decompress_persszp.py assets/us/920000/152/file.bin
tools/decompress_persszp.py assets/us/920000/153/file.bin
tools/decompress_persszp.py assets/us/920000/154/file.bin
tools/decompress_persszp.py assets/us/920000/155/file.bin
tools/decompress_persszp.py assets/us/920000/156/file.bin
tools/decompress_persszp.py assets/us/920000/157/file.bin
tools/decompress_persszp.py assets/us/920000/158/file.bin
tools/decompress_persszp.py assets/us/920000/159/file.bin
tools/decompress_persszp.py assets/us/920000/160/file.bin
tools/decompress_persszp.py assets/us/920000/161/file.bin
tools/decompress_persszp.py assets/us/920000/162/file.bin
tools/decompress_persszp.py assets/us/920000/163/file.bin
tools/decompress_persszp.py assets/us/920000/164/file.bin
tools/decompress_persszp.py assets/us/920000/165/file.bin
tools/decompress_persszp.py assets/us/920000/166/file.bin
tools/decompress_persszp.py assets/us/920000/167/file.bin
tools/decompress_persszp.py assets/us/920000/168/file.bin
tools/decompress_persszp.py assets/us/920000/169/file.bin
tools/decompress_persszp.py assets/us/920000/170/file.bin
tools/decompress_persszp.py assets/us/920000/171/file.bin
tools/decompress_persszp.py assets/us/920000/172/file.bin
tools/decompress_persszp.py assets/us/920000/173/file.bin
tools/decompress_persszp.py assets/us/920000/174/file.bin
tools/decompress_persszp.py assets/us/920000/175/file.bin
tools/decompress_persszp.py assets/us/920000/176/file.bin
tools/decompress_persszp.py assets/us/920000/177/file.bin
tools/decompress_persszp.py assets/us/920000/178/file.bin
tools/decompress_persszp.py assets/us/920000/179/file.bin
tools/decompress_persszp.py assets/us/920000/180/file.bin
tools/decompress_persszp.py assets/us/920000/181/file.bin
tools/decompress_persszp.py assets/us/920000/182/file.bin
tools/decompress_persszp.py assets/us/920000/183/file.bin
tools/decompress_persszp.py assets/us/920000/184/file.bin
tools/decompress_persszp.py assets/us/920000/185/file.bin
tools/decompress_persszp.py assets/us/920000/186/file.bin
tools/decompress_persszp.py assets/us/920000/187/file.bin
tools/decompress_persszp.py assets/us/920000/188/file.bin
tools/decompress_persszp.py assets/us/920000/189/file.bin
tools/decompress_persszp.py assets/us/920000/190/file.bin
tools/decompress_persszp.py assets/us/920000/191/file.bin
tools/decompress_persszp.py assets/us/920000/192/file.bin
tools/decompress_persszp.py assets/us/920000/193/file.bin
tools/decompress_persszp.py assets/us/920000/194/file.bin
tools/decompress_persszp.py assets/us/920000/195/file.bin
tools/decompress_persszp.py assets/us/920000/196/file.bin
tools/decompress_persszp.py assets/us/920000/197/file.bin
tools/decompress_persszp.py assets/us/920000/198/file.bin
tools/decompress_persszp.py assets/us/920000/199/file.bin
tools/decompress_persszp.py assets/us/920000/200/file.bin
tools/decompress_persszp.py assets/us/920000/201/file.bin
tools/decompress_persszp.py assets/us/920000/202/file.bin
tools/decompress_persszp.py assets/us/920000/203/file.bin
tools/decompress_persszp.py assets/us/920000/204/file.bin
tools/decompress_persszp.py assets/us/920000/205/file.bin
tools/decompress_persszp.py assets/us/920000/206/file.bin
tools/decompress_persszp.py assets/us/920000/207/file.bin
tools/decompress_persszp.py assets/us/920000/208/file.bin
tools/decompress_persszp.py assets/us/920000/209/file.bin
tools/decompress_persszp.py assets/us/920000/210/file.bin
tools/decompress_persszp.py assets/us/920000/211/file.bin
tools/decompress_persszp.py assets/us/920000/212/file.bin
tools/decompress_persszp.py assets/us/920000/213/file.bin
tools/decompress_persszp.py assets/us/920000/214/file.bin

# Extract all PRESJPEG files.
tools/extract_presjpeg.py assets/us/backgrounds/0/file.bin
tools/extract_presjpeg.py assets/us/backgrounds/1/file.bin
tools/extract_presjpeg.py assets/us/backgrounds/2/file.bin
tools/extract_presjpeg.py assets/us/backgrounds/3/file.bin
tools/extract_presjpeg.py assets/us/backgrounds/4/file.bin
tools/extract_presjpeg.py assets/us/backgrounds/5/file.bin
tools/extract_presjpeg.py assets/us/backgrounds/6/file.bin
tools/extract_presjpeg.py assets/us/backgrounds/7/file.bin
tools/extract_presjpeg.py assets/us/backgrounds/8/file.bin
tools/extract_presjpeg.py assets/us/backgrounds/9/file.bin
tools/extract_presjpeg.py assets/us/backgrounds/10/file.bin
tools/extract_presjpeg.py assets/us/backgrounds/11/file.bin
tools/extract_presjpeg.py assets/us/backgrounds/12/file.bin
tools/extract_presjpeg.py assets/us/backgrounds/13/file.bin
tools/extract_presjpeg.py assets/us/backgrounds/14/file.bin
tools/extract_presjpeg.py assets/us/backgrounds/15/file.bin
tools/extract_presjpeg.py assets/us/backgrounds/16/file.bin
tools/extract_presjpeg.py assets/us/backgrounds/17/file.bin
tools/extract_presjpeg.py assets/us/backgrounds/18/file.bin
tools/extract_presjpeg.py assets/us/backgrounds/19/file.bin
tools/extract_presjpeg.py assets/us/backgrounds/20/file.bin
tools/extract_presjpeg.py assets/us/6CA730/0/file.bin
tools/extract_presjpeg.py assets/us/6CA730/1/file.bin
tools/extract_presjpeg.py assets/us/6CA730/2/file.bin
tools/extract_presjpeg.py assets/us/6CA730/3/file.bin
tools/extract_presjpeg.py assets/us/6CA730/4/file.bin
tools/extract_presjpeg.py assets/us/6CA730/5/file.bin
tools/extract_presjpeg.py assets/us/6CA730/6/file.bin
tools/extract_presjpeg.py assets/us/6CA730/7/file.bin
tools/extract_presjpeg.py assets/us/6CA730/8/file.bin
tools/extract_presjpeg.py assets/us/6CA730/9/file.bin
tools/extract_presjpeg.py assets/us/6CA730/10/file.bin
tools/extract_presjpeg.py assets/us/6CA730/11/file.bin
tools/extract_presjpeg.py assets/us/6CA730/12/file.bin
tools/extract_presjpeg.py assets/us/6CA730/13/file.bin
tools/extract_presjpeg.py assets/us/6CA730/14/file.bin
tools/extract_presjpeg.py assets/us/6CA730/15/file.bin

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
