#include "../inc/player.h"
#include "../inc/playerInputChanged.h"

#include "../inc/global.h"
#include "../inc/maps.h"

#include "../res/sounds.h"
#include "../res/sprites.h"
#include "../res/resources.h"

void playerInputChanged() {
	u16 joy = input.joy;
	u16 state = input.state;
	u16 changed = input.changed;

	//We only read data from the joypad 1
	if (joy == JOY_1) {
		//Update x velocity
		if (state & BUTTON_RIGHT) {
			playerBody.input.x = 1;
		}else if (state & BUTTON_LEFT) {
			playerBody.input.x = -1;
		}else if ((changed & BUTTON_RIGHT) | (changed & BUTTON_LEFT)) {
			playerBody.input.x = 0;
		}

		//Jump button via jumpbuffer
		//Also used to stop climbing the stairs
		

		//Down and up buttons are only used when it is climbing stair
		//NOTE: Up direction is -1 and down direction is 1, this is because the Mega Drive draws the screen from top to bottom
		if (state & BUTTON_DOWN) {
			playerBody.input.y = 1;
			// if (changed & BUTTON_DOWN) {
				
			// 	if (playerBody.climbingStair) {
			// 		playerBody.velocity.fixY = FIX16(playerBody.climbingSpeed);
			// 	}else if (playerBody.onStair) {
			// 		playerBody.velocity.fixY = FIX16(playerBody.climbingSpeed);
			// 		playerBody.climbingStair = TRUE;
			// 	}
			// }else {
			// 	playerBody.input.y = 0;
			// 	if (playerBody.climbingStair) {
			// 		playerBody.velocity.fixY = 0;
			// 	}
			// }
		} 
		if (changed & (BUTTON_A | BUTTON_B | BUTTON_C)) {
			if((state & BUTTON_C)){
				if(curPlayerAnim != 0){
					playerBody.attack = TRUE;
					Vect2D_s16 pos;
					if(facingRight){
						pos = playerBody.globalPosition;
					} else {
						pos = playerBody.globalPosition;
						pos.x += 32;
					}
					//addNewBullet((Bullet){TRUE, FALSE, pos, {FIX16(pos.x), FIX16(pos.y)}, {0,0}, {32,32}, {0,0,32,32}, FALSE, 50, NULL, NULL, 3});
				}
				addNew_Bullet231((Vect2D_s16)playerBody.globalPosition, (Vect2D_f16){FIX32(4), 0});
			}
			if ((state & (BUTTON_A | BUTTON_B))  && !(state & BUTTON_DOWN)) {
				if (playerBody.climbingStair) {
					playerBody.climbingStair = FALSE;
				}else {
					currentJumpBufferTime = jumpBufferTime;
				}
			}else if (playerBody.jumping && playerBody.velocity.fixY < 0) {
				//If the button is released we remove half of the velocity
				playerBody.velocity.fixY = fix16Mul(playerBody.velocity.fixY, FIX16(.5));
			}
		}
		if (changed & BUTTON_UP) {
			if (state & BUTTON_UP) {
				playerBody.input.y = -1;
				if (collidingAgainstStair && !playerBody.onStair) {
					playerBody.climbingStair = TRUE;
					playerBody.velocity.fixY = FIX16(-playerBody.climbingSpeed);
				}
			}else {
				playerBody.input.y = 0;
				if (playerBody.climbingStair) {
					playerBody.velocity.fixY = 0;
				}
			}
		}
	}
}