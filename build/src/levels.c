#include "../inc/levels.h"

#include "../inc/maps.h"
#include "../inc/enums.h"
#include "../inc/global.h"
#include "../inc/player.h"
#include "../inc/customScripts.h"

#include "../res/resources.h"
#include "../res/gfx.h"
#include "../res/sprites.h"
#include "../res/sounds.h"
#include "../res/music.h"
#include "../res/palette.h"
#include "../res/images.h"

u16 levelNum = 0;
Level* curLvlData;
EntityAllPlayer* curEntityAll;
MessagePack* curMessagePacks;
LocalVariableMerged* curLocalVariables;

u16 palette_full[64];

const Vect2D_s16 const Position_arr_Level_0[] = {{40, 160}, };
const Trigger const Trigger_arr_Level_0[] = {{TRUE, {198, 175}, {0, 0, 16, 80}, TRIGGER_TYPE_restartLevel, 0, 0, 0, 1, FALSE, FALSE, }, {TRUE, {115, 98}, {0, 0, 10, 100}, TRIGGER_TYPE_showMessage, 0, 0, 0, 1, FALSE, FALSE, }, };
const EntityMerged const EntityMerged_arr_Level_0[] = {{1,0, TRUE, {198, 175}, {FIX32(198), FIX32(175)}, {0, 0}, {32, 32}, FALSE, &Trigger_arr_Level_0[0],0,NULL,FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, &spr_barier1, 1, FALSE, FALSE, 1, 0, }, {0,1, TRUE, {115, 98}, {FIX32(115), FIX32(98)}, {0, 0}, {32, 32}, FALSE, &Trigger_arr_Level_0[1],1,NULL,FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, NULL, 1, FALSE, FALSE, 1, 0, }, {9,2, TRUE, {189, 109}, {FIX32(189), FIX32(109)}, {0, 0}, {32, 32}, FALSE, NULL,2,NULL,FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 7, NULL, NULL, &spr_killer_box, 1, FALSE, FALSE, 1, 0, }, };
const LocalVariableMerged const LocalVariable_arr_Level_0[] = {0, 0, 0, };
const EntityAll const EntityAll_arr_Level_0[] = {10, 10, NULL, 3, &EntityMerged_arr_Level_0, 2, &Trigger_arr_Level_0, };
const Message const msgArr_Level_0_msgPack_0[] = {{"Hello. This is a test game created on Platformer Studio For SGDK.", 65}, {"In this game, you need to dodge obstacles. That all :).", 55}, {"Also, at the end, the boss will be waiting for you.", 51}, {"Good luck :)", 12}, };
const MessagePack const MessagePack_Level_0[] = {{msgArr_Level_0_msgPack_0, 4, "0"}, };
const Level const lvl_Level_0 = {&map_Level_0__IntGrid, NULL, &tileset_Level_0__IntGrid, NULL, &pal_Level_0__IntGrid, NULL, NULL, &img_back3, &Position_arr_Level_0, 1, collisionMap, {400, 272}, {25, 17}, {5, 4}, &mus_05_Cycle_Partition, sizeof(mus_05_Cycle_Partition), NULL, moveBack1, NULL, NULL, NULL, &pal_player, &pal_engieJoke, 0, CUSTOM_SCRIPT_updatePlayer, CUSTOM_SCRIPT_updateCamera, 0, 1, 0, 0, 0, 1};
const Vect2D_s16 const Position_arr_Level_1[] = {{12, 162}, {308, 152}, {237, 128}, };
const Trigger const Trigger_arr_Level_1[] = {{TRUE, {177, 153}, {0, 0, 16, 80}, TRIGGER_TYPE_restartLevel, 0, 0, 0, 1, FALSE, FALSE, }, };
const EntityMerged const EntityMerged_arr_Level_1[] = {{1,0, TRUE, {177, 153}, {FIX32(177), FIX32(153)}, {0, 0}, {32, 32}, FALSE, &Trigger_arr_Level_1[0],0,NULL,FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, &spr_barier1, 1, FALSE, FALSE, 1, 0, }, };
const LocalVariableMerged const LocalVariable_arr_Level_1[] = {0, 0, 0, };
const EntityAll const EntityAll_arr_Level_1[] = {10, 10, NULL, 1, &EntityMerged_arr_Level_1, 1, &Trigger_arr_Level_1, };
const MessagePack const MessagePack_Level_1[] = {};
const Level const lvl_Level_1 = {&map_Level_1__IntGrid, NULL, &tileset_Level_1__IntGrid, NULL, &pal_Level_1__IntGrid, NULL, NULL, &img_back3, &Position_arr_Level_1, 3, collisionMap1, {352, 272}, {22, 17}, {5, 4}, NULL, 0, NULL, moveBack1, NULL, NULL, NULL, &pal_player, &pal_engieJoke, 0, CUSTOM_SCRIPT_updatePlayer, CUSTOM_SCRIPT_updateCamera, 0, 1, 0, 0, 0, 1};
const Vect2D_s16 const Position_arr_Level_2[] = {{3, 167}, {104, 155}, {234, 155}, };
const Trigger const Trigger_arr_Level_2[] = {{TRUE, {169, 157}, {0, 0, 16, 80}, TRIGGER_TYPE_restartLevel, 0, 0, 0, 1, FALSE, FALSE, }, };
const EntityMerged const EntityMerged_arr_Level_2[] = {{3,0, TRUE, {169, 157}, {FIX32(169), FIX32(157)}, {0, 0}, {32, 32}, FALSE, &Trigger_arr_Level_2[0],0,NULL,FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, &spr_barier1, 1, FALSE, FALSE, 1, 0, }, };
const LocalVariableMerged const LocalVariable_arr_Level_2[] = {0, 0, 0, };
const EntityAll const EntityAll_arr_Level_2[] = {10, 10, NULL, 1, &EntityMerged_arr_Level_2, 1, &Trigger_arr_Level_2, };
const MessagePack const MessagePack_Level_2[] = {};
const Level const lvl_Level_2 = {&map_Level_2__IntGrid, NULL, &tileset_Level_2__IntGrid, NULL, &pal_Level_2__IntGrid, NULL, NULL, &img_back3, &Position_arr_Level_2, 3, collisionMap2, {352, 272}, {22, 17}, {5, 4}, NULL, 0, NULL, moveBack1, NULL, NULL, NULL, &pal_player, &pal_engieJoke, 0, CUSTOM_SCRIPT_updatePlayer, CUSTOM_SCRIPT_updateCamera, 0, 1, 0, 0, 0, 1};
const Vect2D_s16 const Position_arr_Level_3[] = {{24, 168}, {53, 255}, {314, 261}, };
const Trigger const Trigger_arr_Level_3[] = {{TRUE, {64, 208}, {0, 0, 16, 80}, TRIGGER_TYPE_restartLevel, 0, 0, 0, 1, FALSE, FALSE, }, {TRUE, {72, 360}, {0, 0, 16, 80}, TRIGGER_TYPE_restartLevel, 0, 0, 0, 1, FALSE, FALSE, }, {TRUE, {264, 152}, {0, 0, 16, 80}, TRIGGER_TYPE_restartLevel, 0, 0, 0, 1, FALSE, FALSE, }, };
const EntityMerged const EntityMerged_arr_Level_3[] = {{3,0, TRUE, {64, 208}, {FIX32(64), FIX32(208)}, {0, 0}, {32, 32}, FALSE, &Trigger_arr_Level_3[0],0,NULL,FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, &spr_barier1, 1, FALSE, FALSE, 1, 0, }, {3,1, TRUE, {72, 360}, {FIX32(72), FIX32(360)}, {0, 0}, {32, 32}, FALSE, &Trigger_arr_Level_3[1],1,NULL,FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, &spr_barier1, 1, FALSE, FALSE, 1, 0, }, {3,2, TRUE, {264, 152}, {FIX32(264), FIX32(152)}, {0, 0}, {32, 32}, FALSE, &Trigger_arr_Level_3[2],2,NULL,FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, &spr_barier1, 1, FALSE, FALSE, 1, 0, }, };
const LocalVariableMerged const LocalVariable_arr_Level_3[] = {0, 0, 0, };
const EntityAll const EntityAll_arr_Level_3[] = {10, 10, NULL, 3, &EntityMerged_arr_Level_3, 3, &Trigger_arr_Level_3, };
const MessagePack const MessagePack_Level_3[] = {};
const Level const lvl_Level_3 = {&map_Level_3__IntGrid, NULL, &tileset_Level_3__IntGrid, NULL, &pal_Level_3__IntGrid, NULL, NULL, &img_back3, &Position_arr_Level_3, 3, collisionMap3, {352, 448}, {22, 28}, {5, 6}, NULL, 0, NULL, moveBack1, NULL, NULL, NULL, &pal_player, &pal_engieJoke, 0, CUSTOM_SCRIPT_updatePlayer, CUSTOM_SCRIPT_updateCamera, 0, 1, 0, 0, 0, 1};
const Vect2D_s16 const Position_arr_Level_4[] = {{160, 181}, {58, 148}, {1022, 130}, };
const Trigger const Trigger_arr_Level_4[] = {{TRUE, {78, 152}, {0, 0, 16, 80}, TRIGGER_TYPE_restartLevel, 0, 0, 0, 1, FALSE, FALSE, }, {TRUE, {79, 71}, {0, 0, 16, 80}, TRIGGER_TYPE_restartLevel, 0, 0, 0, 1, FALSE, FALSE, }, };
const EntityMerged const EntityMerged_arr_Level_4[] = {{3,0, TRUE, {78, 152}, {FIX32(78), FIX32(152)}, {0, 0}, {32, 32}, FALSE, &Trigger_arr_Level_4[0],0,NULL,FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, &spr_barier1, 1, FALSE, FALSE, 1, 0, }, {3,1, TRUE, {79, 71}, {FIX32(79), FIX32(71)}, {0, 0}, {32, 32}, FALSE, &Trigger_arr_Level_4[1],1,NULL,FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, &spr_barier1, 1, FALSE, FALSE, 1, 0, }, {5,2, TRUE, {428, 103}, {FIX32(428), FIX32(103)}, {0, 0}, {32, 32}, FALSE, NULL,2,NULL,FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, &spr_engieJoke, 1, FALSE, FALSE, 1, 0, }, };
const LocalVariableMerged const LocalVariable_arr_Level_4[] = {0, 0, 0, };
const EntityAll const EntityAll_arr_Level_4[] = {10, 10, NULL, 3, &EntityMerged_arr_Level_4, 2, &Trigger_arr_Level_4, };
const MessagePack const MessagePack_Level_4[] = {};
const Level const lvl_Level_4 = {&map_Level_4__IntGrid, NULL, &tileset_Level_4__IntGrid, NULL, &pal_Level_4__IntGrid, NULL, NULL, &img_back3, &Position_arr_Level_4, 3, collisionMap4, {1040, 272}, {65, 17}, {13, 4}, NULL, 0, NULL, moveBack1, NULL, NULL, NULL, &pal_player, &pal_engieJoke, 0, CUSTOM_SCRIPT_updatePlayer, CUSTOM_SCRIPT_updateCamera, 0, 1, 0, 0, 0, 1};
const Vect2D_s16 const Position_arr_Level_5[] = {{50, 404}, {213, 243}, {499, 231}, };
const Trigger const Trigger_arr_Level_5[] = {{TRUE, {255, 251}, {0, 0, 16, 80}, TRIGGER_TYPE_restartLevel, 0, 0, 0, 1, FALSE, FALSE, }, {TRUE, {420, 128}, {0, 0, 16, 80}, TRIGGER_TYPE_restartLevel, 0, 0, 0, 1, FALSE, FALSE, }, {TRUE, {476, 7}, {0, 0, 16, 80}, TRIGGER_TYPE_restartLevel, 0, 0, 0, 1, FALSE, FALSE, }, };
const EntityMerged const EntityMerged_arr_Level_5[] = {{3,0, TRUE, {255, 251}, {FIX32(255), FIX32(251)}, {0, 0}, {32, 32}, FALSE, &Trigger_arr_Level_5[0],0,NULL,FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, &spr_barier1, 1, FALSE, FALSE, 1, 0, }, {3,1, TRUE, {420, 128}, {FIX32(420), FIX32(128)}, {0, 0}, {32, 32}, FALSE, &Trigger_arr_Level_5[1],1,NULL,FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, &spr_barier1, 1, FALSE, FALSE, 1, 0, }, {3,2, TRUE, {476, 7}, {FIX32(476), FIX32(7)}, {0, 0}, {32, 32}, FALSE, &Trigger_arr_Level_5[2],2,NULL,FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, &spr_barier1, 1, FALSE, FALSE, 1, 0, }, };
const LocalVariableMerged const LocalVariable_arr_Level_5[] = {0, 0, 0, };
const EntityAll const EntityAll_arr_Level_5[] = {10, 10, NULL, 3, &EntityMerged_arr_Level_5, 3, &Trigger_arr_Level_5, };
const MessagePack const MessagePack_Level_5[] = {};
const Level const lvl_Level_5 = {&map_Level_5__IntGrid, NULL, &tileset_Level_5__IntGrid, NULL, &pal_Level_5__IntGrid, NULL, NULL, &img_back3, &Position_arr_Level_5, 3, collisionMap5, {560, 496}, {35, 31}, {7, 7}, NULL, 0, NULL, moveBack1, NULL, NULL, NULL, &pal_player, &pal_engieJoke, 0, CUSTOM_SCRIPT_updatePlayer, CUSTOM_SCRIPT_updateCamera, 0, 1, 0, 0, 0, 1};
const Vect2D_s16 const Position_arr_Level_6[] = {{413, 506}, };
const Trigger const Trigger_arr_Level_6[] = {};
const EntityMerged const EntityMerged_arr_Level_6[] = {};
const LocalVariableMerged const LocalVariable_arr_Level_6[] = {0, 0, 0, };
const EntityAll const EntityAll_arr_Level_6[] = {10, 10, NULL, 0, &EntityMerged_arr_Level_6, 0, &Trigger_arr_Level_6, };
const MessagePack const MessagePack_Level_6[] = {};
const Level const lvl_Level_6 = {&map_Level_6__IntGrid, NULL, &tileset_Level_6__IntGrid, NULL, &pal_Level_6__IntGrid, NULL, NULL, &img_back3, &Position_arr_Level_6, 1, collisionMap6, {560, 592}, {35, 37}, {7, 8}, NULL, 0, NULL, moveBack1, NULL, NULL, NULL, &pal_player, &pal_engieJoke, 0, CUSTOM_SCRIPT_updatePlayer, CUSTOM_SCRIPT_updateCamera, 0, 1, 0, 0, 0, 1};
const Vect2D_s16 const Position_arr_Level_7[] = {{15, 204}, };
const Trigger const Trigger_arr_Level_7[] = {{TRUE, {72, 216}, {0, 0, 24, 24}, TRIGGER_TYPE_restartLevel, 0, 0, 0, 1, FALSE, FALSE, }, {TRUE, {144, 216}, {0, 0, 24, 24}, TRIGGER_TYPE_restartLevel, 0, 0, 0, 1, FALSE, FALSE, }, {TRUE, {168, 216}, {0, 0, 24, 24}, TRIGGER_TYPE_restartLevel, 0, 0, 0, 1, FALSE, FALSE, }, {TRUE, {240, 216}, {0, 0, 24, 24}, TRIGGER_TYPE_restartLevel, 0, 0, 0, 1, FALSE, FALSE, }, {TRUE, {264, 216}, {0, 0, 24, 24}, TRIGGER_TYPE_restartLevel, 0, 0, 0, 1, FALSE, FALSE, }, {TRUE, {336, 216}, {0, 0, 24, 24}, TRIGGER_TYPE_restartLevel, 0, 0, 0, 1, FALSE, FALSE, }, {TRUE, {360, 216}, {0, 0, 24, 24}, TRIGGER_TYPE_restartLevel, 0, 0, 0, 1, FALSE, FALSE, }, {TRUE, {432, 216}, {0, 0, 24, 24}, TRIGGER_TYPE_restartLevel, 0, 0, 0, 1, FALSE, FALSE, }, {TRUE, {456, 216}, {0, 0, 24, 24}, TRIGGER_TYPE_restartLevel, 0, 0, 0, 1, FALSE, FALSE, }, {TRUE, {528, 216}, {0, 0, 24, 24}, TRIGGER_TYPE_restartLevel, 0, 0, 0, 1, FALSE, FALSE, }, };
const EntityMerged const EntityMerged_arr_Level_7[] = {{4,0, TRUE, {72, 216}, {FIX32(72), FIX32(216)}, {0, 0}, {32, 32}, FALSE, &Trigger_arr_Level_7[0],0,NULL,FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, &spr_killer_box, 1, FALSE, FALSE, 1, 0, }, {4,1, TRUE, {144, 216}, {FIX32(144), FIX32(216)}, {0, 0}, {32, 32}, FALSE, &Trigger_arr_Level_7[1],1,NULL,FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, &spr_killer_box, 1, FALSE, FALSE, 1, 0, }, {4,2, TRUE, {168, 216}, {FIX32(168), FIX32(216)}, {0, 0}, {32, 32}, FALSE, &Trigger_arr_Level_7[2],2,NULL,FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, &spr_killer_box, 1, FALSE, FALSE, 1, 0, }, {4,3, TRUE, {240, 216}, {FIX32(240), FIX32(216)}, {0, 0}, {32, 32}, FALSE, &Trigger_arr_Level_7[3],3,NULL,FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, &spr_killer_box, 1, FALSE, FALSE, 1, 0, }, {4,4, TRUE, {264, 216}, {FIX32(264), FIX32(216)}, {0, 0}, {32, 32}, FALSE, &Trigger_arr_Level_7[4],4,NULL,FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, &spr_killer_box, 1, FALSE, FALSE, 1, 0, }, {4,5, TRUE, {336, 216}, {FIX32(336), FIX32(216)}, {0, 0}, {32, 32}, FALSE, &Trigger_arr_Level_7[5],5,NULL,FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, &spr_killer_box, 1, FALSE, FALSE, 1, 0, }, {4,6, TRUE, {360, 216}, {FIX32(360), FIX32(216)}, {0, 0}, {32, 32}, FALSE, &Trigger_arr_Level_7[6],6,NULL,FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, &spr_killer_box, 1, FALSE, FALSE, 1, 0, }, {4,7, TRUE, {432, 216}, {FIX32(432), FIX32(216)}, {0, 0}, {32, 32}, FALSE, &Trigger_arr_Level_7[7],7,NULL,FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, &spr_killer_box, 1, FALSE, FALSE, 1, 0, }, {4,8, TRUE, {456, 216}, {FIX32(456), FIX32(216)}, {0, 0}, {32, 32}, FALSE, &Trigger_arr_Level_7[8],8,NULL,FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, &spr_killer_box, 1, FALSE, FALSE, 1, 0, }, {4,9, TRUE, {528, 216}, {FIX32(528), FIX32(216)}, {0, 0}, {32, 32}, FALSE, &Trigger_arr_Level_7[9],9,NULL,FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, &spr_killer_box, 1, FALSE, FALSE, 1, 0, }, };
const LocalVariableMerged const LocalVariable_arr_Level_7[] = {0, 0, 0, };
const EntityAll const EntityAll_arr_Level_7[] = {10, 10, NULL, 10, &EntityMerged_arr_Level_7, 10, &Trigger_arr_Level_7, };
const MessagePack const MessagePack_Level_7[] = {};
const Level const lvl_Level_7 = {&map_Level_7__IntGrid, NULL, &tileset_Level_7__IntGrid, NULL, &pal_Level_7__IntGrid, NULL, NULL, &img_back3, &Position_arr_Level_7, 1, collisionMap7, {640, 304}, {40, 19}, {8, 4}, NULL, 0, NULL, moveBack1, NULL, NULL, NULL, &pal_player, &pal_engieJoke, 0, CUSTOM_SCRIPT_updatePlayer, CUSTOM_SCRIPT_updateCamera, 0, 1, 0, 0, 0, 1};
const Vect2D_s16 const Position_arr_Level_8[] = {{25, 205}, };
const Trigger const Trigger_arr_Level_8[] = {};
const EntityMerged const EntityMerged_arr_Level_8[] = {};
const LocalVariableMerged const LocalVariable_arr_Level_8[] = {0, 0, 0, };
const EntityAll const EntityAll_arr_Level_8[] = {10, 10, NULL, 0, &EntityMerged_arr_Level_8, 0, &Trigger_arr_Level_8, };
const MessagePack const MessagePack_Level_8[] = {};
const Level const lvl_Level_8 = {&map_Level_8__IntGrid, NULL, &tileset_Level_8__IntGrid, NULL, &pal_Level_8__IntGrid, NULL, NULL, &img_back3, &Position_arr_Level_8, 1, collisionMap8, {496, 1136}, {31, 71}, {7, 15}, NULL, 0, NULL, moveBack1, NULL, NULL, NULL, &pal_player, &pal_engieJoke, 0, CUSTOM_SCRIPT_updatePlayer, CUSTOM_SCRIPT_updateCamera, 0, 1, 0, 0, 0, 1};
const Vect2D_s16 const Position_arr_Level_9[] = {{163, 484}, };
const Trigger const Trigger_arr_Level_9[] = {{TRUE, {825, 429}, {0, 0, 10, 100}, 0, 10, 0, 0, 1, FALSE, FALSE, }, {TRUE, {281, 335}, {0, 0, 10, 200}, TRIGGER_TYPE_showMessage, 0, 0, 0, 1, FALSE, FALSE, }, };
const EntityMerged const EntityMerged_arr_Level_9[] = {{0,0, TRUE, {825, 429}, {FIX32(825), FIX32(429)}, {0, 0}, {32, 32}, FALSE, &Trigger_arr_Level_9[0],0,NULL,FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, NULL, 1, FALSE, FALSE, 1, 0, }, {0,1, TRUE, {281, 335}, {FIX32(281), FIX32(335)}, {0, 0}, {32, 32}, FALSE, &Trigger_arr_Level_9[1],1,NULL,FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, NULL, 1, FALSE, FALSE, 1, 0, }, };
const LocalVariableMerged const LocalVariable_arr_Level_9[] = {0, 0, 0, };
const EntityAll const EntityAll_arr_Level_9[] = {10, 10, NULL, 2, &EntityMerged_arr_Level_9, 2, &Trigger_arr_Level_9, };
const Message const msgArr_Level_9_msgPack_0[] = {{"Now. It's boss time.", 20}, };
const MessagePack const MessagePack_Level_9[] = {{msgArr_Level_9_msgPack_0, 1, "0"}, };
const Level const lvl_Level_9 = {&map_Level_9__IntGrid, NULL, &tileset_Level_9__IntGrid, NULL, &pal_Level_9__IntGrid, NULL, NULL, &img_back4, &Position_arr_Level_9, 1, collisionMap9, {880, 560}, {55, 35}, {11, 7}, &mus_04, sizeof(mus_04), NULL, moveBack1, NULL, NULL, NULL, &pal_player, &pal_engieJoke, 0, CUSTOM_SCRIPT_updatePlayer, CUSTOM_SCRIPT_updateCamera, 0, 1, 0, 0, 0, 1};
const Vect2D_s16 const Position_arr_Level_10[] = {{55, 149}, };
const Trigger const Trigger_arr_Level_10[] = {{TRUE, {269, 144}, {0, 0, 48, 64}, TRIGGER_TYPE_restartLevel, 0, 0, 0, 1, FALSE, FALSE, }, };
const EntityMerged const EntityMerged_arr_Level_10[] = {{6,0, TRUE, {269, 144}, {FIX32(269), FIX32(144)}, {0, 0}, {32, 32}, FALSE, &Trigger_arr_Level_10[0],0,NULL,FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, &spr_sgdk_boss, 50, FALSE, FALSE, 0, 0, }, };
const LocalVariableMerged const LocalVariable_arr_Level_10[] = {0, 0, 0, };
const EntityAll const EntityAll_arr_Level_10[] = {10, 10, NULL, 1, &EntityMerged_arr_Level_10, 1, &Trigger_arr_Level_10, };
const Message const msgArr_Level_10_msgPack_0[] = {{"Congrats! You completed my game!", 32}, };
const MessagePack const MessagePack_Level_10[] = {{msgArr_Level_10_msgPack_0, 1, "0"}, };
const Level const lvl_Level_10 = {&map_noBg, NULL, &tileset_noBg, NULL, &pal_noBg, NULL, NULL, &img_boss_bg, &Position_arr_Level_10, 1, collisionMap10, {320, 224}, {20, 14}, {4, 3}, NULL, 0, NULL, moveBack1, NULL, NULL, NULL, &pal_player, &pal_back4, 0, CUSTOM_SCRIPT_updatePlayer, CUSTOM_SCRIPT_updateCamera, 0, 1, 0, 0, 0, 1};
const LevelFull const LevelFull_arr[] = {{&lvl_Level_0, &EntityAll_arr_Level_0, &MessagePack_Level_0, &LocalVariable_arr_Level_0}, {&lvl_Level_1, &EntityAll_arr_Level_1, &MessagePack_Level_1, &LocalVariable_arr_Level_1}, {&lvl_Level_2, &EntityAll_arr_Level_2, &MessagePack_Level_2, &LocalVariable_arr_Level_2}, {&lvl_Level_3, &EntityAll_arr_Level_3, &MessagePack_Level_3, &LocalVariable_arr_Level_3}, {&lvl_Level_4, &EntityAll_arr_Level_4, &MessagePack_Level_4, &LocalVariable_arr_Level_4}, {&lvl_Level_5, &EntityAll_arr_Level_5, &MessagePack_Level_5, &LocalVariable_arr_Level_5}, {&lvl_Level_6, &EntityAll_arr_Level_6, &MessagePack_Level_6, &LocalVariable_arr_Level_6}, {&lvl_Level_7, &EntityAll_arr_Level_7, &MessagePack_Level_7, &LocalVariable_arr_Level_7}, {&lvl_Level_8, &EntityAll_arr_Level_8, &MessagePack_Level_8, &LocalVariable_arr_Level_8}, {&lvl_Level_9, &EntityAll_arr_Level_9, &MessagePack_Level_9, &LocalVariable_arr_Level_9}, {&lvl_Level_10, &EntityAll_arr_Level_10, &MessagePack_Level_10, &LocalVariable_arr_Level_10}, };


Vect2D_s16 getLevelPos(u16 posNum) {
	return LevelFull_arr[levelNum].lvl->posArr[posNum];
}

void updateRoomSize(Level* lvl){
	roomSize = newAABB(0, lvl->sizeinPx.x, 0, lvl->sizeinPx.y);
}

u16 getTileValue(s16 x, s16 y) {
	if (x >= curLvlData->sizeinTiles.x || x < 0 || y < 0 || y >= curLvlData->sizeinTiles.y)
		return 0;

	//If the position is inside the collision map return the value of the tile from it
	return curLvlData->collArr[x+(y*curLvlData->sizeinTiles.x)];
}

