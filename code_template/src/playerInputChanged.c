#include "../inc/player.h"
#include "../inc/playerInputChanged.h"

#include "../inc/global.h"
#include "../inc/maps.h"

#include "../res/sounds.h"
#include "../res/sprites.h"
#include "../res/resources.h"

void playerInputChanged() {
	input.prevState = input.state;
	input.state = JOY_readJoypad(JOY_1);

	//We only read data from the joypad 1
		//Update x velocity
		if (input.state & BUTTON_RIGHT) {
			playerBody.input.x = 1;
		}else if (input.state & BUTTON_LEFT) {
			playerBody.input.x = -1;
		} else {
			playerBody.input.x = 0;
		}

		if (input.state & BUTTON_UP) {
			playerBody.input.y = 1;
		}else if (input.state & BUTTON_DOWN) {
			playerBody.input.y = -1;
		} else {
			playerBody.input.y = 0;
		}

		if ((input.state & (BUTTON_A | BUTTON_B)) && !(input.prevState & (BUTTON_A | BUTTON_B))) {
			if (playerBody.climbingStair) {
					playerBody.climbingStair = FALSE;
			} else {
				currentJumpBufferTime = jumpBufferTime;
			}
		}
		if((input.state & BUTTON_C) && !(input.prevState & BUTTON_C)){
			if(TRUE){ //curPlayerAnim != 0
			playerBody.attack = TRUE;
			Vect2D_s16 pos;
			if(facingRight){
				pos = playerBody.globalPosition;
			} else {
				pos = playerBody.globalPosition;
				pos.x += 32;
			}
			addNew_Bullet231((Vect2D_s16)playerBody.globalPosition, (Vect2D_f16){FIX32(4), 0});
			}
		} else if((input.prevState & BUTTON_C) && !(input.state & BUTTON_C)) {
			//If the button is released we remove half of the velocity
			playerBody.velocity.fixY = fix16Mul(playerBody.velocity.fixY, FIX16(.5));
		}
	
}