#include "../inc/levels.h"

#include "../inc/maps.h"
#include "../inc/camera.h"
#include "../inc/global.h"
#include "../inc/player.h"

#include "../res/resources.h"
#include "../res/gfx.h"
#include "../res/sprites.h"
#include "../res/sounds.h"
#include "../res/music.h"
#include "../res/images.h"

void moveBack1(){
    backXScroll++;
    backYScroll++;

    VDP_setHorizontalScroll(BG_B, backXScroll);
    VDP_setVerticalScroll(BG_B, backYScroll);
}
void emptyScript(){};
void (* customScriptArr[])(void) = {moveBack1, };
