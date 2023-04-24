#pragma once
#include "../inc/levels.h"

#include "../inc/maps.h"
#include "../inc/camera.h"
#include "../inc/global.h"
#include "../inc/player.h"
#include "../inc/updatePlayer.h"
#include "../inc/enums.h"
#include "../inc/levels.h"

#include "../res/resources.h"
#include "../res/gfx.h"
#include "../res/sprites.h"
#include "../res/sounds.h"
#include "../res/music.h"
#include "../res/images.h"

void freeCam1() {

    if (playerBody.input.x > 0) {
		playerBody.globalPosition.x += 2;
        // if(playerBody.globalPosition.x > (curLvlData->sizeinPx.x-320)){
        //     playerBody.globalPosition.x = curLvlData->sizeinPx.x-320;
        // }
	}else if (playerBody.input.x < 0) {
		playerBody.globalPosition.x -= 2;
        // if(playerBody.globalPosition.x < 0){
        //     playerBody.globalPosition.x = 0;
        // }
	}

    if (playerBody.input.y > 0) {
		playerBody.globalPosition.y += 2;
        // if(playerBody.globalPosition.y > (curLvlData->sizeinPx.y-224)){
        //     playerBody.globalPosition.y = curLvlData->sizeinPx.y-224;
        // }
	}else if (playerBody.input.y < 0) {
		playerBody.globalPosition.y -= 2;
        // if(playerBody.globalPosition.y < 0){
        //     playerBody.globalPosition.y = 0;
        // }
	}
    
    u16 maxCameraPosX = curLvlData->sizeinPx.x - 320;
	u16 maxCameraPosY = curLvlData->sizeinPx.y - 224;


	playerBody.globalPosition.x = clamp(playerBody.globalPosition.x, 0, maxCameraPosX); // 768 - 320 = 448 (level width - screen width)
	playerBody.globalPosition.y = clamp(playerBody.globalPosition.y, 0, maxCameraPosY); // 768 - 224 = 544 (level height - screen height)

    if((cameraPosition.x != playerBody.globalPosition.x) || (cameraPosition.y != playerBody.globalPosition.y)){

        if(bga) MAP_scrollTo(bga, playerBody.globalPosition.x, playerBody.globalPosition.y);
	    if(bgb) MAP_scrollTo(bgb, playerBody.globalPosition.x, playerBody.globalPosition.y);
    }

    cameraPosition.x = playerBody.globalPosition.x;
    cameraPosition.y = playerBody.globalPosition.y;

    

    VDP_showFPS(FALSE);
}
void moveBack1(){
    backXScroll++;
    backYScroll++;

    VDP_setHorizontalScroll(BG_B, backXScroll);
    VDP_setVerticalScroll(BG_B, backYScroll);
}
void showFPSWindow(){
	VDP_showFPS(FALSE);
}

void testMainMenu() {
    Vect2D_s16 pos1_int = getLevelPos(1);
	Vect2D_s16 pos2_int = getLevelPos(2);   
    if(curLocalVariables->val1 == 0){
        playerBody.globalPosition.x += 2;
        if(playerBody.globalPosition.x > pos2_int.x-320) {
            curLocalVariables->val1 = 1;
        }
    } else {
         playerBody.globalPosition.x -= 2;
         if(playerBody.globalPosition.x < pos1_int.x) {
            curLocalVariables->val1 = 0;
        }
    }
    
    u16 maxCameraPosX = curLvlData->sizeinPx.x - 320;
	u16 maxCameraPosY = curLvlData->sizeinPx.y - 224;

	playerBody.globalPosition.x = clamp(playerBody.globalPosition.x, 0, maxCameraPosX); // 768 - 320 = 448 (level width - screen width)
	playerBody.globalPosition.y = clamp(playerBody.globalPosition.y, 0, maxCameraPosY); // 768 - 224 = 544 (level height - screen height)

    if((cameraPosition.x != playerBody.globalPosition.x) || (cameraPosition.y != playerBody.globalPosition.y)){

        if(bga) MAP_scrollTo(bga, playerBody.globalPosition.x, playerBody.globalPosition.y);
	    if(bgb) MAP_scrollTo(bgb, playerBody.globalPosition.x, playerBody.globalPosition.y);
    }

    cameraPosition.x = playerBody.globalPosition.x;
    cameraPosition.y = playerBody.globalPosition.y;

    u16 joy1 = JOY_readJoypad(0);

    if(joy1 & BUTTON_START){
        levelNum = 0;
        loadLevel(levelNum,0);
    }
    
}
void turnOnWindowMode1(){
	VDP_setWindowVPos(FALSE, 1);
}

void uselessScript(){
    
}
void emptyScript(){};
void (* customScriptArr[])(void) = {updatePlayer, updateCamera, freeCam1, moveBack1, showFPSWindow, testMainMenu, turnOnWindowMode1, uselessScript, };
