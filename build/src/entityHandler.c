#include "../inc/levels.h"

#include "../inc/maps.h"
#include "../inc/messages.h"
#include "../inc/global.h"
#include "../inc/enums.h"

#include "../res/resources.h"
#include "../res/gfx.h"
#include "../res/sprites.h"
#include "../inc/camera.h"
#include "../inc/messages.h"
#include "../inc/customScripts.h"


const EntityMerged const EntitySimple_default = {0, FALSE, {0,0}, {0,0}, {0,0}, {16, 16}, FALSE, NULL, 0, NULL, NULL, NULL, NULL, 1, FALSE, FALSE, 1, 0, };
const Trigger const EntitySimple_defaultTrigger = {FALSE, {0, 0}, {0, 0, 0, 0}, 0, 1, 1, 1, 1, };
const EntityMerged const BarierDead_default = {1, FALSE, {0,0}, {0,0}, {0,0}, {16, 16}, FALSE, NULL, 0, NULL, NULL, NULL, &spr_barier1, 1, FALSE, FALSE, 1, 0, };
const Trigger const BarierDead_defaultTrigger = {FALSE, {0, 0}, {0, 0, 16, 80}, TRIGGER_TYPE_restartLevel, 1, 1, 1, 1, };
const EntityMerged const Coin_default = {2, FALSE, {0,0}, {0,0}, {0,0}, {16, 16}, FALSE, NULL, 0, NULL, NULL, NULL, &spr_coin, 1, FALSE, FALSE, 1, 0, };
const EntityMerged const BarierDeadMove_default = {3, FALSE, {0,0}, {0,0}, {0,0}, {16, 16}, FALSE, NULL, 0, NULL, NULL, NULL, &spr_barier1, 1, FALSE, FALSE, 1, 0, };
const Trigger const BarierDeadMove_defaultTrigger = {FALSE, {0, 0}, {0, 0, 16, 80}, TRIGGER_TYPE_restartLevel, 1, 1, 1, 1, };
const EntityMerged const KillerBox_default = {4, FALSE, {0,0}, {0,0}, {0,0}, {16, 16}, FALSE, NULL, 0, NULL, NULL, NULL, &spr_killer_box, 1, FALSE, FALSE, 1, 0, };
const Trigger const KillerBox_defaultTrigger = {FALSE, {0, 0}, {0, 0, 24, 24}, TRIGGER_TYPE_restartLevel, 1, 1, 1, 1, };
const EntityMerged const JokeEngie_default = {5, FALSE, {0,0}, {0,0}, {0,0}, {16, 16}, FALSE, NULL, 0, NULL, NULL, NULL, &spr_engieJoke, 1, FALSE, FALSE, 1, 0, };
const EntityMerged const sgsk_boss_default = {6, FALSE, {0,0}, {0,0}, {0,0}, {16, 16}, FALSE, NULL, 0, NULL, NULL, NULL, &spr_sgdk_boss, 100, FALSE, FALSE, 0, 0, };
const Trigger const sgsk_boss_defaultTrigger = {FALSE, {0, 0}, {0, 0, 48, 64}, TRIGGER_TYPE_restartLevel, 1, 1, 1, 1, };
const EntityMerged const Boss_bullet_default = {7, FALSE, {0,0}, {0,0}, {0,0}, {16, 16}, FALSE, NULL, 0, NULL, NULL, NULL, &spr_sonic_ball, 1, FALSE, FALSE, 1, 0, };
const Trigger const Boss_bullet_defaultTrigger = {FALSE, {0, 0}, {0, 0, 32, 32}, TRIGGER_TYPE_restartLevel, 1, 1, 1, 1, };
const EntityMerged const Boss_Bullet_jump_default = {8, FALSE, {0,0}, {0,0}, {0,0}, {16, 16}, FALSE, NULL, 0, NULL, NULL, NULL, &spr_sonic_ball, 1, FALSE, FALSE, 0, 0, };
const Trigger const Boss_Bullet_jump_defaultTrigger = {FALSE, {0, 0}, {0, 0, 32, 32}, TRIGGER_TYPE_restartLevel, 1, 1, 1, 1, };


const EntityBulletMerged const Bullet231_default = {0, FALSE, FALSE, {0,0}, {0,0}, {0,0}, {0,0}, FALSE, {0,0,8,8}, NULL, NULL, NULL, &spr_coin, 1, 1, FALSE, FALSE, };


EntityMerged* addNew_EntitySimple(Vect2D_s16 posInt, Vect2D_f16 spd){
    Trigger* foundTrigger = NULL;
    //find first free index in arr
    
    KDebug_Alert("new Trigger");
    for(u16 i=0; i<curEntityAll->Trigger_size; i++){
        if(!curEntityAll->Trigger_arr[i].alive){
            memcpy(&curEntityAll->Trigger_arr[i], &EntitySimple_defaultTrigger, sizeof(Trigger));
            curEntityAll->Trigger_arr[i].pos = posInt;
            curEntityAll->Trigger_arr[i].alive = TRUE;
            KDebug_Alert("Success for Trigger!");
            foundTrigger = &curEntityAll->Trigger_arr[i];
            break;
        }
    }
    if(foundTrigger == NULL) {
        KDebug_Alert("Fail for Trigger and for EntitySimple...");
        return;
    }

    //find first free index in arr
    KDebug_Alert("new EntitySimple");
    for(u16 i=0; i<curEntityAll->EntityMerged_size; i++){
        if(!curEntityAll->EntityMerged_arr[i].alive){
            memcpy(&curEntityAll->EntityMerged_arr[i], &EntitySimple_default, sizeof(EntityMerged));
            curEntityAll->EntityMerged_arr[i].posInt = posInt;
            curEntityAll->EntityMerged_arr[i].pos = (Vect2D_f32){FIX32(posInt.x), FIX32(posInt.y)};
            curEntityAll->EntityMerged_arr[i].spd = spd;
            curEntityAll->EntityMerged_arr[i].alive = TRUE;
            KDebug_Alert("Success for EntitySimple!");
            return;
        }
    }
    KDebug_Alert("Fail for EntitySimple...");
    return;
}
EntityMerged* addNew_BarierDead(Vect2D_s16 posInt, Vect2D_f16 spd){
    Trigger* foundTrigger = NULL;
    //find first free index in arr
    
    KDebug_Alert("new Trigger");
    for(u16 i=0; i<curEntityAll->Trigger_size; i++){
        if(!curEntityAll->Trigger_arr[i].alive){
            memcpy(&curEntityAll->Trigger_arr[i], &BarierDead_defaultTrigger, sizeof(Trigger));
            curEntityAll->Trigger_arr[i].pos = posInt;
            curEntityAll->Trigger_arr[i].alive = TRUE;
            KDebug_Alert("Success for Trigger!");
            foundTrigger = &curEntityAll->Trigger_arr[i];
            break;
        }
    }
    if(foundTrigger == NULL) {
        KDebug_Alert("Fail for Trigger and for BarierDead...");
        return;
    }

    //find first free index in arr
    KDebug_Alert("new BarierDead");
    for(u16 i=0; i<curEntityAll->EntityMerged_size; i++){
        if(!curEntityAll->EntityMerged_arr[i].alive){
            memcpy(&curEntityAll->EntityMerged_arr[i], &BarierDead_default, sizeof(EntityMerged));
            curEntityAll->EntityMerged_arr[i].posInt = posInt;
            curEntityAll->EntityMerged_arr[i].pos = (Vect2D_f32){FIX32(posInt.x), FIX32(posInt.y)};
            curEntityAll->EntityMerged_arr[i].spd = spd;
            curEntityAll->EntityMerged_arr[i].alive = TRUE;
            KDebug_Alert("Success for BarierDead!");
            return;
        }
    }
    KDebug_Alert("Fail for BarierDead...");
    return;
}
EntityMerged* addNew_Coin(Vect2D_s16 posInt, Vect2D_f16 spd){
    Trigger* foundTrigger = NULL;
    //$addNewTrigger$

    //find first free index in arr
    KDebug_Alert("new Coin");
    for(u16 i=0; i<curEntityAll->EntityMerged_size; i++){
        if(!curEntityAll->EntityMerged_arr[i].alive){
            memcpy(&curEntityAll->EntityMerged_arr[i], &Coin_default, sizeof(EntityMerged));
            curEntityAll->EntityMerged_arr[i].posInt = posInt;
            curEntityAll->EntityMerged_arr[i].pos = (Vect2D_f32){FIX32(posInt.x), FIX32(posInt.y)};
            curEntityAll->EntityMerged_arr[i].spd = spd;
            curEntityAll->EntityMerged_arr[i].alive = TRUE;
            KDebug_Alert("Success for Coin!");
            return;
        }
    }
    KDebug_Alert("Fail for Coin...");
    return;
}
EntityMerged* addNew_BarierDeadMove(Vect2D_s16 posInt, Vect2D_f16 spd){
    Trigger* foundTrigger = NULL;
    //find first free index in arr
    
    KDebug_Alert("new Trigger");
    for(u16 i=0; i<curEntityAll->Trigger_size; i++){
        if(!curEntityAll->Trigger_arr[i].alive){
            memcpy(&curEntityAll->Trigger_arr[i], &BarierDeadMove_defaultTrigger, sizeof(Trigger));
            curEntityAll->Trigger_arr[i].pos = posInt;
            curEntityAll->Trigger_arr[i].alive = TRUE;
            KDebug_Alert("Success for Trigger!");
            foundTrigger = &curEntityAll->Trigger_arr[i];
            break;
        }
    }
    if(foundTrigger == NULL) {
        KDebug_Alert("Fail for Trigger and for BarierDeadMove...");
        return;
    }

    //find first free index in arr
    KDebug_Alert("new BarierDeadMove");
    for(u16 i=0; i<curEntityAll->EntityMerged_size; i++){
        if(!curEntityAll->EntityMerged_arr[i].alive){
            memcpy(&curEntityAll->EntityMerged_arr[i], &BarierDeadMove_default, sizeof(EntityMerged));
            curEntityAll->EntityMerged_arr[i].posInt = posInt;
            curEntityAll->EntityMerged_arr[i].pos = (Vect2D_f32){FIX32(posInt.x), FIX32(posInt.y)};
            curEntityAll->EntityMerged_arr[i].spd = spd;
            curEntityAll->EntityMerged_arr[i].alive = TRUE;
            KDebug_Alert("Success for BarierDeadMove!");
            return;
        }
    }
    KDebug_Alert("Fail for BarierDeadMove...");
    return;
}
EntityMerged* addNew_KillerBox(Vect2D_s16 posInt, Vect2D_f16 spd){
    Trigger* foundTrigger = NULL;
    //find first free index in arr
    
    KDebug_Alert("new Trigger");
    for(u16 i=0; i<curEntityAll->Trigger_size; i++){
        if(!curEntityAll->Trigger_arr[i].alive){
            memcpy(&curEntityAll->Trigger_arr[i], &KillerBox_defaultTrigger, sizeof(Trigger));
            curEntityAll->Trigger_arr[i].pos = posInt;
            curEntityAll->Trigger_arr[i].alive = TRUE;
            KDebug_Alert("Success for Trigger!");
            foundTrigger = &curEntityAll->Trigger_arr[i];
            break;
        }
    }
    if(foundTrigger == NULL) {
        KDebug_Alert("Fail for Trigger and for KillerBox...");
        return;
    }

    //find first free index in arr
    KDebug_Alert("new KillerBox");
    for(u16 i=0; i<curEntityAll->EntityMerged_size; i++){
        if(!curEntityAll->EntityMerged_arr[i].alive){
            memcpy(&curEntityAll->EntityMerged_arr[i], &KillerBox_default, sizeof(EntityMerged));
            curEntityAll->EntityMerged_arr[i].posInt = posInt;
            curEntityAll->EntityMerged_arr[i].pos = (Vect2D_f32){FIX32(posInt.x), FIX32(posInt.y)};
            curEntityAll->EntityMerged_arr[i].spd = spd;
            curEntityAll->EntityMerged_arr[i].alive = TRUE;
            KDebug_Alert("Success for KillerBox!");
            return;
        }
    }
    KDebug_Alert("Fail for KillerBox...");
    return;
}
EntityMerged* addNew_JokeEngie(Vect2D_s16 posInt, Vect2D_f16 spd){
    Trigger* foundTrigger = NULL;
    //$addNewTrigger$

    //find first free index in arr
    KDebug_Alert("new JokeEngie");
    for(u16 i=0; i<curEntityAll->EntityMerged_size; i++){
        if(!curEntityAll->EntityMerged_arr[i].alive){
            memcpy(&curEntityAll->EntityMerged_arr[i], &JokeEngie_default, sizeof(EntityMerged));
            curEntityAll->EntityMerged_arr[i].posInt = posInt;
            curEntityAll->EntityMerged_arr[i].pos = (Vect2D_f32){FIX32(posInt.x), FIX32(posInt.y)};
            curEntityAll->EntityMerged_arr[i].spd = spd;
            curEntityAll->EntityMerged_arr[i].alive = TRUE;
            KDebug_Alert("Success for JokeEngie!");
            return;
        }
    }
    KDebug_Alert("Fail for JokeEngie...");
    return;
}
EntityMerged* addNew_sgsk_boss(Vect2D_s16 posInt, Vect2D_f16 spd){
    Trigger* foundTrigger = NULL;
    //find first free index in arr
    
    KDebug_Alert("new Trigger");
    for(u16 i=0; i<curEntityAll->Trigger_size; i++){
        if(!curEntityAll->Trigger_arr[i].alive){
            memcpy(&curEntityAll->Trigger_arr[i], &sgsk_boss_defaultTrigger, sizeof(Trigger));
            curEntityAll->Trigger_arr[i].pos = posInt;
            curEntityAll->Trigger_arr[i].alive = TRUE;
            KDebug_Alert("Success for Trigger!");
            foundTrigger = &curEntityAll->Trigger_arr[i];
            break;
        }
    }
    if(foundTrigger == NULL) {
        KDebug_Alert("Fail for Trigger and for sgsk_boss...");
        return;
    }

    //find first free index in arr
    KDebug_Alert("new sgsk_boss");
    for(u16 i=0; i<curEntityAll->EntityMerged_size; i++){
        if(!curEntityAll->EntityMerged_arr[i].alive){
            memcpy(&curEntityAll->EntityMerged_arr[i], &sgsk_boss_default, sizeof(EntityMerged));
            curEntityAll->EntityMerged_arr[i].posInt = posInt;
            curEntityAll->EntityMerged_arr[i].pos = (Vect2D_f32){FIX32(posInt.x), FIX32(posInt.y)};
            curEntityAll->EntityMerged_arr[i].spd = spd;
            curEntityAll->EntityMerged_arr[i].alive = TRUE;
            KDebug_Alert("Success for sgsk_boss!");
            return;
        }
    }
    KDebug_Alert("Fail for sgsk_boss...");
    return;
}
EntityMerged* addNew_Boss_bullet(Vect2D_s16 posInt, Vect2D_f16 spd){
    Trigger* foundTrigger = NULL;
    //find first free index in arr
    
    KDebug_Alert("new Trigger");
    for(u16 i=0; i<curEntityAll->Trigger_size; i++){
        if(!curEntityAll->Trigger_arr[i].alive){
            memcpy(&curEntityAll->Trigger_arr[i], &Boss_bullet_defaultTrigger, sizeof(Trigger));
            curEntityAll->Trigger_arr[i].pos = posInt;
            curEntityAll->Trigger_arr[i].alive = TRUE;
            KDebug_Alert("Success for Trigger!");
            foundTrigger = &curEntityAll->Trigger_arr[i];
            break;
        }
    }
    if(foundTrigger == NULL) {
        KDebug_Alert("Fail for Trigger and for Boss_bullet...");
        return;
    }

    //find first free index in arr
    KDebug_Alert("new Boss_bullet");
    for(u16 i=0; i<curEntityAll->EntityMerged_size; i++){
        if(!curEntityAll->EntityMerged_arr[i].alive){
            memcpy(&curEntityAll->EntityMerged_arr[i], &Boss_bullet_default, sizeof(EntityMerged));
            curEntityAll->EntityMerged_arr[i].posInt = posInt;
            curEntityAll->EntityMerged_arr[i].pos = (Vect2D_f32){FIX32(posInt.x), FIX32(posInt.y)};
            curEntityAll->EntityMerged_arr[i].spd = spd;
            curEntityAll->EntityMerged_arr[i].alive = TRUE;
            curEntityAll->EntityMerged_arr[i].trigger = foundTrigger;
            KDebug_Alert("Success for Boss_bullet!");
            return;
        }
    }
    KDebug_Alert("Fail for Boss_bullet...");
    return;
}
EntityMerged* addNew_Boss_Bullet_jump(Vect2D_s16 posInt, Vect2D_f16 spd){
    Trigger* foundTrigger = NULL;
    //find first free index in arr
    
    KDebug_Alert("new Trigger");
    for(u16 i=0; i<curEntityAll->Trigger_size; i++){
        if(!curEntityAll->Trigger_arr[i].alive){
            memcpy(&curEntityAll->Trigger_arr[i], &Boss_Bullet_jump_defaultTrigger, sizeof(Trigger));
            curEntityAll->Trigger_arr[i].pos = posInt;
            curEntityAll->Trigger_arr[i].alive = TRUE;
            KDebug_Alert("Success for Trigger!");
            foundTrigger = &curEntityAll->Trigger_arr[i];
            break;
        }
    }
    if(foundTrigger == NULL) {
        KDebug_Alert("Fail for Trigger and for Boss_Bullet_jump...");
        return;
    }

    //find first free index in arr
    KDebug_Alert("new Boss_Bullet_jump");
    for(u16 i=0; i<curEntityAll->EntityMerged_size; i++){
        if(!curEntityAll->EntityMerged_arr[i].alive){
            memcpy(&curEntityAll->EntityMerged_arr[i], &Boss_Bullet_jump_default, sizeof(EntityMerged));
            curEntityAll->EntityMerged_arr[i].posInt = posInt;
            curEntityAll->EntityMerged_arr[i].pos = (Vect2D_f32){FIX32(posInt.x), FIX32(posInt.y)};
            curEntityAll->EntityMerged_arr[i].spd = spd;
            curEntityAll->EntityMerged_arr[i].alive = TRUE;
            curEntityAll->EntityMerged_arr[i].trigger = foundTrigger;
            KDebug_Alert("Success for Boss_Bullet_jump!");
            return;
        }
    }
    KDebug_Alert("Fail for Boss_Bullet_jump...");
    return;
}


EntityBulletMerged* addNew_Bullet231(Vect2D_s16 posInt, Vect2D_f16 spd){
    //$addNewTrigger$
    //find first free index in arr
    KDebug_Alert("new Bullet231");
    for(u16 i=0; i<curEntityAll->EntityBulletMerged_size; i++){
        if(!curEntityAll->EntityBulletMerged_arr[i].alive){
            memcpy(&curEntityAll->EntityBulletMerged_arr[i], &Bullet231_default, sizeof(EntityBulletMerged));
            curEntityAll->EntityBulletMerged_arr[i].posInt = posInt;
            curEntityAll->EntityBulletMerged_arr[i].pos = (Vect2D_f32){FIX32(posInt.x), FIX32(posInt.y)};
            curEntityAll->EntityBulletMerged_arr[i].spd = spd;
            curEntityAll->EntityBulletMerged_arr[i].alive = TRUE;
            KDebug_Alert("Success for Bullet231!");
            return &curEntityAll->EntityBulletMerged_arr[i];
        }
    }
    KDebug_Alert("Fail for Bullet231...");
    return NULL;
}


void entityCheckForBullet(EntityMerged* entity){
	entity->damaged = FALSE;
	AABB entityTriggerBounds = newAABB(
		entity->trigger->pos.x + entity->trigger->rect.min.x,
		entity->trigger->pos.x + entity->trigger->rect.max.x,
		entity->trigger->pos.y + entity->trigger->rect.min.y,
		entity->trigger->pos.y + entity->trigger->rect.max.y
	);
	for(u16 i = 0; i < curEntityAll->EntityBulletMerged_size; i++){
		EntityBulletMerged* curBullet = &curEntityAll->EntityBulletMerged_arr[i];
		if(!curBullet->alive){
			continue;
		}
		AABB bulletBounds = newAABB(
			curBullet->posInt.x + curBullet->aabb.min.x,
			curBullet->posInt.x + curBullet->aabb.max.x,
			curBullet->posInt.y + curBullet->aabb.min.y,
			curBullet->posInt.y + curBullet->aabb.max.y
		);
		if((bulletBounds.min.x < entityTriggerBounds.max.x) && (bulletBounds.max.x > entityTriggerBounds.min.x)){
			if((bulletBounds.min.y < entityTriggerBounds.max.y) && (bulletBounds.max.y > entityTriggerBounds.min.y)){
				entity->hp -= curBullet->damage;
				entity->damaged = TRUE;
				curBullet->preDeath = TRUE;
				return;
			}
		}
	}
}

/*
void addNewBullet(Bullet entity){
	for(u16 i = 0; i < curEntityAll->Bullet_size; i++){
		if(!curEntityAll->Bullet_arr[i].alive){
			curEntityAll->Bullet_arr[i] = entity;
			break;
		}
	}
}
*/

/*
void showBullet(Bullet* entity){
    if(!entity->alive){
		return;
	}
	if(entity->preDeath){
		if(entity->spr)	SPR_releaseSprite(entity->spr);
		if(entity->spr2) SPR_releaseSprite(entity->spr2);
		if(entity->spr3) SPR_releaseSprite(entity->spr3);
		entity->alive = FALSE;
		return;
	}

    s16 posX_OnCam = entity->posInt.x-cameraPosition.x;
	s16 posY_OnCam = entity->posInt.y-cameraPosition.y;

	//$updatePosition_Entity_always$
	if ((posX_OnCam < -entity->size.x) || (posX_OnCam > 320) || (posY_OnCam < -entity->size.y) || (posY_OnCam > 224)) {
		if(entity->onScreen) {
			entity->preDeath = TRUE;
			return;
		}
		entity->onScreen = FALSE;
		
	}
    else
    {
		if(!entity->onScreen) {
			if(entity->sprDef) {
				entity->spr = SPR_addSprite(entity->sprDef, posX_OnCam, posY_OnCam, TILE_ATTR(ENEMY_PALETTE, 15, FALSE, FALSE));
				
			}
			entity->spr2 = SPR_addSprite(&spr_debugLeftTopCorner, posX_OnCam, posY_OnCam, TILE_ATTR(PAL3, 11, FALSE, FALSE));
			entity->spr3 = SPR_addSprite(&spr_debugRightBottom, posX_OnCam, posY_OnCam, TILE_ATTR(PAL3, 11, FALSE, FALSE));
			
		}
        if(entity->sprDef){
			SPR_setPosition(entity->spr, posX_OnCam, posY_OnCam);
			
			
			//Update position
			entity->pos.x += entity->spd.x;
			entity->pos.y += entity->spd.y;
			entity->posInt.x = fix16ToInt(entity->pos.x);
			entity->posInt.y = fix16ToInt(entity->pos.y);

		}
		SPR_setPosition(entity->spr2, posX_OnCam, posY_OnCam);
		SPR_setPosition(entity->spr3, posX_OnCam+entity->size.x-8, posY_OnCam+entity->size.y-8);
		entity->lifeTime--;
		if(entity->lifeTime < 0){
			entity->preDeath = TRUE;
			return;
		}
		
		entity->onScreen = TRUE;
    }
}
*/

void triggerTypeFunc_changeLevel(Trigger* trigger, AABB* triggerBounds) {
PAL_fadeOutAll(3,FALSE);
levelNum = trigger->val1;
loadLevel(levelNum, (Vect2D_s16)getLevelPos(trigger->val2));
}
void triggerTypeFunc_changeLevelv2(Trigger* trigger, AABB* triggerBounds) {
if(!(trigger->activated && !trigger->prevActivated)){
	return;
}
PAL_fadeOutAll(3,FALSE);
//val1 = level_num
//val2 = side_id
//val3 = side_offset
	
	Vect2D_s16 newStartPos;
	levelNum = trigger->val1;
	switch(trigger->val2) // position mode
	{
		case 0: //Left
			newStartPos.x = LevelFull_arr[levelNum].lvl->sizeinPx.x-playerBody.aabb.max.x;
			newStartPos.y = playerBody.globalPosition.y-trigger->val3;
			break;
		case 1: //Right
			newStartPos.x = 0;
			newStartPos.y = playerBody.globalPosition.y-trigger->val3;
			break;
		case 2: //Up
			newStartPos.x = playerBody.globalPosition.x-trigger->val3;
			newStartPos.y = LevelFull_arr[levelNum].lvl->sizeinPx.y-playerBody.aabb.max.y;
			break;
		case 3: //Down
			newStartPos.x = playerBody.globalPosition.x-trigger->val3;
			newStartPos.y = 0;
			break;
	}
					
	
	loadLevel(levelNum, (Vect2D_s16)newStartPos);
}
void triggerTypeFunc_executeScript(Trigger* trigger, AABB* triggerBounds) {
customScriptArr[trigger->val1]();
}
void triggerTypeFunc_forceDownPlayer(Trigger* trigger, AABB* triggerBounds) {
if((playerBody.globalPosition.y+playerBody.aabb.min.y) < (trigger->pos.y+trigger->rect.max.y)) {
		playerBody.globalPosition.y = trigger->pos.y+trigger->rect.max.y-playerBody.aabb.min.y+1;
		playerBody.velocity.fixY = 0;
	}
}
void triggerTypeFunc_forceLeftPlayer(Trigger* trigger, AABB* triggerBounds) {
if((playerBody.globalPosition.x+playerBody.aabb.max.x) > (trigger->pos.x+trigger->rect.min.x)) {
		playerBody.globalPosition.x = trigger->pos.x+trigger->rect.min.x-playerBody.aabb.max.x-1;
	}
}
void triggerTypeFunc_forceRightPlayer(Trigger* trigger, AABB* triggerBounds) {
if((playerBody.globalPosition.x+playerBody.aabb.min.x) < (trigger->pos.x+trigger->rect.max.x)) {
		playerBody.globalPosition.x = trigger->pos.x+trigger->rect.max.x-playerBody.aabb.min.x;
	}
}
void triggerTypeFunc_forceUpPlayer(Trigger* trigger, AABB* triggerBounds) {
if((playerBody.globalPosition.y+playerBody.aabb.max.y) > (trigger->pos.y+trigger->rect.min.y)) {
		playerBody.globalPosition.y = trigger->pos.y-playerBody.aabb.max.y+1;
		playerBody.curAmountOfJumps = playerBody.maxAmountOfJumps;
		playerBody.velocity.fixY = 0;
		playerBody.onGround = TRUE;
	}
}
void triggerTypeFunc_gotSomething(Trigger* trigger, AABB* triggerBounds) {
trigger->alive = FALSE;
}
void triggerTypeFunc_hurt(Trigger* trigger, AABB* triggerBounds) {

}
void triggerTypeFunc_restartLevel(Trigger* trigger, AABB* triggerBounds) {
PAL_fadeOutAll(3,FALSE);
loadLevel(levelNum, (Vect2D_s16)getLevelPos(trigger->val1));
}
void triggerTypeFunc_showMessage(Trigger* trigger, AABB* triggerBounds) {
trigger->alive = FALSE;
					KLog_S1("curMessagePacks->len: ", curMessagePacks[trigger->val1].len);
					for(s16 i=0; i<curMessagePacks[trigger->val1].len; i++){
						printMessage(curMessagePacks[trigger->val1].messages[i].str);
					}
}
void(* triggerTypeFuncArr[])(Trigger*, AABB*) = {triggerTypeFunc_changeLevel, triggerTypeFunc_changeLevelv2, triggerTypeFunc_executeScript, triggerTypeFunc_forceDownPlayer, triggerTypeFunc_forceLeftPlayer, triggerTypeFunc_forceRightPlayer, triggerTypeFunc_forceUpPlayer, triggerTypeFunc_gotSomething, triggerTypeFunc_hurt, triggerTypeFunc_restartLevel, triggerTypeFunc_showMessage, };


void checkTriggerForPlayer(Trigger* trigger){
	if(!trigger->alive){
		return;
	}
	AABB triggerBounds = newAABB(
		trigger->pos.x + trigger->rect.min.x,
		trigger->pos.x + trigger->rect.max.x,
		trigger->pos.y + trigger->rect.min.y,
		trigger->pos.y + trigger->rect.max.y
	);
	trigger->prevActivated = trigger->activated;
	if((playerBounds.min.x < triggerBounds.max.x) && (playerBounds.max.x > triggerBounds.min.x)){
		if((playerBounds.min.y < triggerBounds.max.y) && (playerBounds.max.y > triggerBounds.min.y)){
			
			trigger->activated = TRUE;
			
			KLog_S1("trigger->activated: ", trigger->activated);
			KLog_S1("trigger->prevActivated: ", trigger->prevActivated);
			KLog_S1("trigger->type: ", trigger->type);
			KLog_S1("trigger->val1: ", trigger->val1);
			KLog_S1("trigger->val2: ", trigger->val2);
			KLog_S1("trigger->val3: ", trigger->val3);
			//KLog_S1("trigger->value: ", trigger->value);
			triggerTypeFuncArr[trigger->type](trigger, &triggerBounds);
			return;
		}
	}
	trigger->activated = FALSE;
}

void showBullet231(EntityBulletMerged* entity){
    if(!entity->alive){
		return;
	}
	if(entity->preDeath){
		if(entity->spr)	SPR_releaseSprite(entity->spr);
		if(entity->debugSpr1) SPR_releaseSprite(entity->debugSpr1);
if(entity->debugSpr2) SPR_releaseSprite(entity->debugSpr2);


		entity->alive = FALSE;
		return;
	}
    s16 posX_OnCam = entity->posInt.x-cameraPosition.x;
	s16 posY_OnCam = entity->posInt.y-cameraPosition.y;

	//$updatePosition_Entity_always$
	if ((posX_OnCam < -entity->size.x) || (posX_OnCam > 320) || (posY_OnCam < -entity->size.y) || (posY_OnCam > 224)) {
		if(entity->onScreen) {
			entity->preDeath = TRUE;
			return;
		}
		entity->onScreen = FALSE;
	}
    else
    {
		if(!entity->onScreen) {
			if(entity->sprDef) entity->spr = SPR_addSprite(entity->sprDef, posX_OnCam, posY_OnCam, TILE_ATTR(ENEMY_PALETTE, 11, FALSE, FALSE));
			entity->debugSpr1 = SPR_addSprite(&spr_debugLeftTopCorner, posX_OnCam, posY_OnCam, TILE_ATTR(PAL3, 11, FALSE, FALSE));
entity->debugSpr2 = SPR_addSprite(&spr_debugRightBottom, posX_OnCam, posY_OnCam, TILE_ATTR(PAL3, 11, FALSE, FALSE));

		}
        if(entity->sprDef) {
			SPR_setPosition(entity->spr, posX_OnCam, posY_OnCam);

			//Update position
			entity->pos.x += entity->spd.x;
			entity->pos.y += entity->spd.y;
			entity->posInt.x = fix32ToInt(entity->pos.x);
			entity->posInt.y = fix32ToInt(entity->pos.y);
		}
		if(entity->debugSpr1) SPR_setPosition(entity->debugSpr1, (entity->posInt.x-cameraPosition.x)+entity->aabb.min.x, (entity->posInt.y-cameraPosition.y)+entity->aabb.min.y);
if(entity->debugSpr2) SPR_setPosition(entity->debugSpr2, (entity->posInt.x-cameraPosition.x)+entity->aabb.max.x-8, (entity->posInt.y-cameraPosition.y)+entity->aabb.max.y-8);

		
		entity->onScreen = TRUE;
    }
}
void(* showEntityBulletFuncArr[])(EntityBulletMerged*) = {showBullet231, };


void showEntitySimple(EntityMerged* entity){
    if(!entity->alive){
		return;
	}
    s16 posX_OnCam = entity->posInt.x-cameraPosition.x;
	s16 posY_OnCam = entity->posInt.y-cameraPosition.y;

	//$updatePosition_Entity_always$
	if ((posX_OnCam < -entity->size.x) || (posX_OnCam > 320) || (posY_OnCam < -entity->size.y) || (posY_OnCam > 224)) {
		if(entity->onScreen) {
			if(entity->sprDef) {
				SPR_releaseSprite(entity->spr);
				if(entity->debugSpr1) SPR_releaseSprite(entity->debugSpr1);
if(entity->debugSpr2) SPR_releaseSprite(entity->debugSpr2);

			}
		}
		entity->onScreen = FALSE;
		
	}
    else
    {
		if(!entity->onScreen) {
			if(entity->sprDef) entity->spr = SPR_addSprite(entity->sprDef, posX_OnCam, posY_OnCam, TILE_ATTR(ENEMY_PALETTE, 0, FALSE, FALSE));
			entity->debugSpr1 = SPR_addSprite(&spr_debugLeftTopCorner, posX_OnCam, posY_OnCam, TILE_ATTR(PAL3, 11, FALSE, FALSE));
entity->debugSpr2 = SPR_addSprite(&spr_debugRightBottom, posX_OnCam, posY_OnCam, TILE_ATTR(PAL3, 11, FALSE, FALSE));

		}
        if(entity->sprDef) SPR_setPosition(entity->spr, posX_OnCam, posY_OnCam);
		if(entity->debugSpr1) SPR_setPosition(entity->debugSpr1, (entity->trigger->pos.x-cameraPosition.x)+entity->trigger->rect.min.x, (entity->trigger->pos.y-cameraPosition.y)+entity->trigger->rect.min.y);
if(entity->debugSpr2) SPR_setPosition(entity->debugSpr2, (entity->trigger->pos.x-cameraPosition.x)+entity->trigger->rect.max.x-8, (entity->trigger->pos.y-cameraPosition.y)+entity->trigger->rect.max.y-8);

		
		entity->onScreen = TRUE;
    }
}
void showBarierDead(EntityMerged* entity){
    if(!entity->alive){
		return;
	}
    s16 posX_OnCam = entity->posInt.x-cameraPosition.x;
	s16 posY_OnCam = entity->posInt.y-cameraPosition.y;

	//$updatePosition_Entity_always$
	if ((posX_OnCam < -entity->size.x) || (posX_OnCam > 320) || (posY_OnCam < -entity->size.y) || (posY_OnCam > 224)) {
		if(entity->onScreen) {
			if(entity->sprDef) {
				SPR_releaseSprite(entity->spr);
				if(entity->debugSpr1) SPR_releaseSprite(entity->debugSpr1);
if(entity->debugSpr2) SPR_releaseSprite(entity->debugSpr2);

			}
		}
		entity->onScreen = FALSE;
		
	}
    else
    {
		if(!entity->onScreen) {
			if(entity->sprDef) entity->spr = SPR_addSprite(entity->sprDef, posX_OnCam, posY_OnCam, TILE_ATTR(ENEMY_PALETTE, 11, FALSE, FALSE));
			entity->debugSpr1 = SPR_addSprite(&spr_debugLeftTopCorner, posX_OnCam, posY_OnCam, TILE_ATTR(PAL3, 11, FALSE, FALSE));
entity->debugSpr2 = SPR_addSprite(&spr_debugRightBottom, posX_OnCam, posY_OnCam, TILE_ATTR(PAL3, 11, FALSE, FALSE));

		}
        if(entity->sprDef) SPR_setPosition(entity->spr, posX_OnCam, posY_OnCam);
		if(entity->debugSpr1) SPR_setPosition(entity->debugSpr1, (entity->trigger->pos.x-cameraPosition.x)+entity->trigger->rect.min.x, (entity->trigger->pos.y-cameraPosition.y)+entity->trigger->rect.min.y);
if(entity->debugSpr2) SPR_setPosition(entity->debugSpr2, (entity->trigger->pos.x-cameraPosition.x)+entity->trigger->rect.max.x-8, (entity->trigger->pos.y-cameraPosition.y)+entity->trigger->rect.max.y-8);

		
		entity->onScreen = TRUE;
    }
}
void showCoin(EntityMerged* entity){
    if(!entity->alive){
		return;
	}
    s16 posX_OnCam = entity->posInt.x-cameraPosition.x;
	s16 posY_OnCam = entity->posInt.y-cameraPosition.y;

	//$updatePosition_Entity_always$
	if ((posX_OnCam < -entity->size.x) || (posX_OnCam > 320) || (posY_OnCam < -entity->size.y) || (posY_OnCam > 224)) {
		if(entity->onScreen) {
			if(entity->sprDef) {
				SPR_releaseSprite(entity->spr);
				if(entity->debugSpr1) SPR_releaseSprite(entity->debugSpr1);
if(entity->debugSpr2) SPR_releaseSprite(entity->debugSpr2);

			}
		}
		entity->onScreen = FALSE;
		
	}
    else
    {
		if(!entity->onScreen) {
			if(entity->sprDef) entity->spr = SPR_addSprite(entity->sprDef, posX_OnCam, posY_OnCam, TILE_ATTR(ENEMY_PALETTE, 11, FALSE, FALSE));
			entity->debugSpr1 = SPR_addSprite(&spr_debugLeftTopCorner, posX_OnCam, posY_OnCam, TILE_ATTR(PAL3, 11, FALSE, FALSE));
entity->debugSpr2 = SPR_addSprite(&spr_debugRightBottom, posX_OnCam, posY_OnCam, TILE_ATTR(PAL3, 11, FALSE, FALSE));

		}
        if(entity->sprDef) SPR_setPosition(entity->spr, posX_OnCam, posY_OnCam);
		if(entity->debugSpr1) SPR_setPosition(entity->debugSpr1, (entity->trigger->pos.x-cameraPosition.x)+entity->trigger->rect.min.x, (entity->trigger->pos.y-cameraPosition.y)+entity->trigger->rect.min.y);
if(entity->debugSpr2) SPR_setPosition(entity->debugSpr2, (entity->trigger->pos.x-cameraPosition.x)+entity->trigger->rect.max.x-8, (entity->trigger->pos.y-cameraPosition.y)+entity->trigger->rect.max.y-8);

		
		entity->onScreen = TRUE;
    }
}
void showBarierDeadMove(EntityMerged* entity){
    if(!entity->alive){
		return;
	}
    s16 posX_OnCam = entity->posInt.x-cameraPosition.x;
	s16 posY_OnCam = entity->posInt.y-cameraPosition.y;

	//$updatePosition_Entity_always$
	if ((posX_OnCam < -entity->size.x) || (posX_OnCam > 320) || (posY_OnCam < -entity->size.y) || (posY_OnCam > 224)) {
		if(entity->onScreen) {
			if(entity->sprDef) {
				SPR_releaseSprite(entity->spr);
				if(entity->debugSpr1) SPR_releaseSprite(entity->debugSpr1);
if(entity->debugSpr2) SPR_releaseSprite(entity->debugSpr2);

			}
		}
		entity->onScreen = FALSE;
		
	}
    else
    {
		if(!entity->onScreen) {
			if(entity->sprDef) entity->spr = SPR_addSprite(entity->sprDef, posX_OnCam, posY_OnCam, TILE_ATTR(ENEMY_PALETTE, 11, FALSE, FALSE));
			entity->spd.x = FIX32(2);
			entity->debugSpr1 = SPR_addSprite(&spr_debugLeftTopCorner, posX_OnCam, posY_OnCam, TILE_ATTR(PAL3, 11, FALSE, FALSE));
entity->debugSpr2 = SPR_addSprite(&spr_debugRightBottom, posX_OnCam, posY_OnCam, TILE_ATTR(PAL3, 11, FALSE, FALSE));

		}
        if(entity->sprDef) {
			SPR_setPosition(entity->spr, posX_OnCam, posY_OnCam);
			Vect2D_s16 pos1_int = getLevelPos(1);
			Vect2D_s16 pos2_int = getLevelPos(2);

			if(entity->posInt.x > pos2_int.x) {
				entity->spd.x = FIX32(-2);
			}
			if(entity->posInt.x < pos1_int.x) {
				entity->spd.x = FIX32(2);
			}

			//Update position
			entity->pos.x += entity->spd.x;
			entity->pos.y += entity->spd.y;
			entity->posInt.x = fix32ToInt(entity->pos.x);
			entity->posInt.y = fix32ToInt(entity->pos.y);
			entity->trigger->pos.x = entity->posInt.x;
			entity->trigger->pos.y = entity->posInt.y;
		
		}
		if(entity->debugSpr1) SPR_setPosition(entity->debugSpr1, (entity->trigger->pos.x-cameraPosition.x)+entity->trigger->rect.min.x, (entity->trigger->pos.y-cameraPosition.y)+entity->trigger->rect.min.y);
if(entity->debugSpr2) SPR_setPosition(entity->debugSpr2, (entity->trigger->pos.x-cameraPosition.x)+entity->trigger->rect.max.x-8, (entity->trigger->pos.y-cameraPosition.y)+entity->trigger->rect.max.y-8);

		
		entity->onScreen = TRUE;
    }
}
void showKillerBox(EntityMerged* entity){
    if(!entity->alive){
		return;
	}
    s16 posX_OnCam = entity->posInt.x-cameraPosition.x;
	s16 posY_OnCam = entity->posInt.y-cameraPosition.y;

	//$updatePosition_Entity_always$
	if ((posX_OnCam < -entity->size.x) || (posX_OnCam > 320) || (posY_OnCam < -entity->size.y) || (posY_OnCam > 224)) {
		if(entity->onScreen) {
			if(entity->sprDef) {
				SPR_releaseSprite(entity->spr);
				if(entity->debugSpr1) SPR_releaseSprite(entity->debugSpr1);
if(entity->debugSpr2) SPR_releaseSprite(entity->debugSpr2);

			}
		}
		entity->onScreen = FALSE;
		
	}
    else
    {
		if(!entity->onScreen) {
			if(entity->sprDef) entity->spr = SPR_addSprite(entity->sprDef, posX_OnCam, posY_OnCam, TILE_ATTR(PAL0, 11, FALSE, FALSE));
			entity->debugSpr1 = SPR_addSprite(&spr_debugLeftTopCorner, posX_OnCam, posY_OnCam, TILE_ATTR(PAL3, 11, FALSE, FALSE));
entity->debugSpr2 = SPR_addSprite(&spr_debugRightBottom, posX_OnCam, posY_OnCam, TILE_ATTR(PAL3, 11, FALSE, FALSE));

		}
		entity->timer++;
        if(entity->sprDef) SPR_setPosition(entity->spr, posX_OnCam, posY_OnCam);
		if(entity->timer == 30){
			if(entity->sprDef) {
				SPR_releaseSprite(entity->spr);
				if(entity->debugSpr1) SPR_releaseSprite(entity->debugSpr1);
if(entity->debugSpr2) SPR_releaseSprite(entity->debugSpr2);

			}
			entity->trigger->alive = FALSE;
		}
		if(entity->timer == 80){
			entity->timer = 0;
			if(entity->sprDef) entity->spr = SPR_addSprite(entity->sprDef, posX_OnCam, posY_OnCam, TILE_ATTR(PAL0, 11, FALSE, FALSE));
			entity->debugSpr1 = SPR_addSprite(&spr_debugLeftTopCorner, posX_OnCam, posY_OnCam, TILE_ATTR(PAL3, 11, FALSE, FALSE));
entity->debugSpr2 = SPR_addSprite(&spr_debugRightBottom, posX_OnCam, posY_OnCam, TILE_ATTR(PAL3, 11, FALSE, FALSE));

			entity->trigger->alive = TRUE;
		}
		if(entity->debugSpr1) SPR_setPosition(entity->debugSpr1, (entity->trigger->pos.x-cameraPosition.x)+entity->trigger->rect.min.x, (entity->trigger->pos.y-cameraPosition.y)+entity->trigger->rect.min.y);
if(entity->debugSpr2) SPR_setPosition(entity->debugSpr2, (entity->trigger->pos.x-cameraPosition.x)+entity->trigger->rect.max.x-8, (entity->trigger->pos.y-cameraPosition.y)+entity->trigger->rect.max.y-8);

		
		entity->onScreen = TRUE;
    }
}
void showJokeEngie(EntityMerged* entity){
    if(!entity->alive){
		return;
	}
    s16 posX_OnCam = entity->posInt.x-cameraPosition.x;
	s16 posY_OnCam = entity->posInt.y-cameraPosition.y;

	//$updatePosition_Entity_always$
	if ((posX_OnCam < -entity->size.x) || (posX_OnCam > 320) || (posY_OnCam < -entity->size.y) || (posY_OnCam > 224)) {
		if(entity->onScreen) {
			if(entity->sprDef) {
				SPR_releaseSprite(entity->spr);
				if(entity->debugSpr1) SPR_releaseSprite(entity->debugSpr1);
if(entity->debugSpr2) SPR_releaseSprite(entity->debugSpr2);

			}
		}
		entity->onScreen = FALSE;
		
	}
    else
    {
		if(!entity->onScreen) {
			if(entity->sprDef) entity->spr = SPR_addSprite(entity->sprDef, posX_OnCam, posY_OnCam, TILE_ATTR(ENEMY_PALETTE, 11, FALSE, FALSE));
			entity->debugSpr1 = SPR_addSprite(&spr_debugLeftTopCorner, posX_OnCam, posY_OnCam, TILE_ATTR(PAL3, 11, FALSE, FALSE));
entity->debugSpr2 = SPR_addSprite(&spr_debugRightBottom, posX_OnCam, posY_OnCam, TILE_ATTR(PAL3, 11, FALSE, FALSE));

		}
        if(entity->sprDef) SPR_setPosition(entity->spr, posX_OnCam, posY_OnCam);
		if(entity->debugSpr1) SPR_setPosition(entity->debugSpr1, (entity->trigger->pos.x-cameraPosition.x)+entity->trigger->rect.min.x, (entity->trigger->pos.y-cameraPosition.y)+entity->trigger->rect.min.y);
if(entity->debugSpr2) SPR_setPosition(entity->debugSpr2, (entity->trigger->pos.x-cameraPosition.x)+entity->trigger->rect.max.x-8, (entity->trigger->pos.y-cameraPosition.y)+entity->trigger->rect.max.y-8);

		
		entity->onScreen = TRUE;
    }
}
void showsgsk_boss(EntityMerged* entity){
    if(!entity->alive){
		return;
	}
	if(!entity->trigger->alive){
		SPR_releaseSprite(entity->spr);
		if(entity->debugSpr1) SPR_releaseSprite(entity->debugSpr1);
if(entity->debugSpr2) SPR_releaseSprite(entity->debugSpr2);


		entity->alive = FALSE;
		return;
	}
    s16 posX_OnCam = entity->posInt.x-cameraPosition.x;
	s16 posY_OnCam = entity->posInt.y-cameraPosition.y;

	//$updatePosition_Entity_always$
	if ((posX_OnCam < -entity->size.x) || (posX_OnCam > 320) || (posY_OnCam < -entity->size.y) || (posY_OnCam > 224)) {
		if(entity->onScreen) {
			if(entity->sprDef) {
				SPR_releaseSprite(entity->spr);
				if(entity->debugSpr1) SPR_releaseSprite(entity->debugSpr1);
if(entity->debugSpr2) SPR_releaseSprite(entity->debugSpr2);

			}
		}
		entity->onScreen = FALSE;
		
	}
    else
    {
		if(!entity->onScreen) {
			if(entity->sprDef) entity->spr = SPR_addSprite(entity->sprDef, posX_OnCam, posY_OnCam, TILE_ATTR(PAL0, 11, FALSE, FALSE));
			entity->debugSpr1 = SPR_addSprite(&spr_debugLeftTopCorner, posX_OnCam, posY_OnCam, TILE_ATTR(PAL3, 11, FALSE, FALSE));
entity->debugSpr2 = SPR_addSprite(&spr_debugRightBottom, posX_OnCam, posY_OnCam, TILE_ATTR(PAL3, 11, FALSE, FALSE));

			VDP_setWindowVPos(FALSE, 1);
		}
        if(entity->sprDef) SPR_setPosition(entity->spr, posX_OnCam, posY_OnCam);
		if(entity->debugSpr1) SPR_setPosition(entity->debugSpr1, (entity->trigger->pos.x-cameraPosition.x)+entity->trigger->rect.min.x, (entity->trigger->pos.y-cameraPosition.y)+entity->trigger->rect.min.y);
if(entity->debugSpr2) SPR_setPosition(entity->debugSpr2, (entity->trigger->pos.x-cameraPosition.x)+entity->trigger->rect.max.x-8, (entity->trigger->pos.y-cameraPosition.y)+entity->trigger->rect.max.y-8);

		entityCheckForBullet(entity);
		if(entity->damaged){
			char str_hp[5] = "     ";
			intToStr(entity->hp, str_hp, 1);
			VDP_drawTextBG(WINDOW, "     ", 0, 0);
			VDP_drawTextBG(WINDOW, str_hp, 0, 0);
			
		}

		entity->timer++;

		if(entity->timer > 120){
			entity->timer = 0;
			entity->state++;
		}
		Vect2D_s16 bullet_pos;
		switch(entity->state){
			case 0: //idle state
				break;
			case 1: 
				{
					bullet_pos = entity->posInt;
					bullet_pos.y += 32;
					if((entity->timer % 50) == 0){
						addNew_Boss_bullet(bullet_pos, (Vect2D_f16){FIX32(-2), 0});
					}
					
					break;
				}
				
			case 2: 
			{
				bullet_pos = entity->posInt;
				bullet_pos.y += 32;
				if((entity->timer % 50) == 0){
					addNew_Boss_Bullet_jump(bullet_pos, (Vect2D_f16){FIX32(-2), 0});
				}
				break;
			}
			case 3:
				bullet_pos = entity->posInt;
				bullet_pos.y += 32;
				if((entity->timer % 20) == 0){
					addNew_Boss_Bullet_jump(bullet_pos, (Vect2D_f16){FIX32(-4), 0});
				}
				break; 
			case 4:
				bullet_pos = entity->posInt;
				bullet_pos.y += 50;
				if((entity->timer % 20) == 0){
					addNew_Boss_Bullet_jump(bullet_pos, (Vect2D_f16){FIX32(-6), 0});
				}
				if((entity->timer % 50) == 0){
					addNew_Boss_bullet(bullet_pos, (Vect2D_f16){FIX32(-2), 0});
				}
				break; 
			case 5:
				bullet_pos = entity->posInt;
				bullet_pos.y += 50;
				if((entity->timer % 20) == 0){
					addNew_Boss_Bullet_jump(bullet_pos, (Vect2D_f16){FIX32(-6), 0});
				}
				if((entity->timer % 50) == 0){
					addNew_Boss_bullet(bullet_pos, (Vect2D_f16){FIX32(-2), 0});
				}
				break; 
			case 6:
				bullet_pos = entity->posInt;
				if((entity->timer % 100) == 0){
					addNew_Boss_bullet(bullet_pos, (Vect2D_f16){FIX32(-1), 0});
				}
				if((entity->timer % 10) == 0){
					addNew_Boss_Bullet_jump(bullet_pos, (Vect2D_f16){FIX32(-2), 0});
				}
				bullet_pos.y += 32;
				
				break; 
			case 7:
				entity->state = 0;
				break;
		}

		if(entity->hp < 0){
			entity->trigger->alive = FALSE;
			for(s16 i=0; i<curMessagePacks[0].len; i++){
				printMessage(curMessagePacks[0].messages[i].str);
			}
		}
		
		entity->onScreen = TRUE;
    }
}
void showBoss_bullet(EntityMerged* entity){
    if(!entity->alive){
		return;
	}
	if(!entity->trigger->alive){
		entity->alive = FALSE;
		SPR_releaseSprite(entity->spr);
		if(entity->debugSpr1) SPR_releaseSprite(entity->debugSpr1);
if(entity->debugSpr2) SPR_releaseSprite(entity->debugSpr2);

		return;
	}
    s16 posX_OnCam = entity->posInt.x-cameraPosition.x;
	s16 posY_OnCam = entity->posInt.y-cameraPosition.y;

	//$updatePosition_Entity_always$
	if ((posX_OnCam < -entity->size.x) || (posX_OnCam > 320) || (posY_OnCam < -entity->size.y) || (posY_OnCam > 224)) {
		entity->trigger->alive = FALSE;
		return;
		entity->onScreen = FALSE;
		
	}
    else
    {
		if(!entity->onScreen) {
			if(entity->sprDef) entity->spr = SPR_addSprite(entity->sprDef, posX_OnCam, posY_OnCam, TILE_ATTR(PAL2, 11, FALSE, FALSE));
			entity->debugSpr1 = SPR_addSprite(&spr_debugLeftTopCorner, posX_OnCam, posY_OnCam, TILE_ATTR(PAL3, 11, FALSE, FALSE));
entity->debugSpr2 = SPR_addSprite(&spr_debugRightBottom, posX_OnCam, posY_OnCam, TILE_ATTR(PAL3, 11, FALSE, FALSE));

		}
        if(entity->sprDef) SPR_setPosition(entity->spr, posX_OnCam, posY_OnCam);
		if(entity->debugSpr1) SPR_setPosition(entity->debugSpr1, (entity->trigger->pos.x-cameraPosition.x)+entity->trigger->rect.min.x, (entity->trigger->pos.y-cameraPosition.y)+entity->trigger->rect.min.y);
if(entity->debugSpr2) SPR_setPosition(entity->debugSpr2, (entity->trigger->pos.x-cameraPosition.x)+entity->trigger->rect.max.x-8, (entity->trigger->pos.y-cameraPosition.y)+entity->trigger->rect.max.y-8);


		//Update position
		entity->pos.x += entity->spd.x;
		entity->pos.y += entity->spd.y;
		entity->posInt.x = fix32ToInt(entity->pos.x);
		entity->posInt.y = fix32ToInt(entity->pos.y);
		entity->trigger->pos.x = entity->posInt.x;
		entity->trigger->pos.y = entity->posInt.y;
		entity->onScreen = TRUE;
    }
}
void showBoss_Bullet_jump(EntityMerged* entity){
    if(!entity->alive){
		return;
	}
	if(!entity->trigger->alive){
		entity->alive = FALSE;
		SPR_releaseSprite(entity->spr);
		if(entity->debugSpr1) SPR_releaseSprite(entity->debugSpr1);
if(entity->debugSpr2) SPR_releaseSprite(entity->debugSpr2);

		return;
	}
    s16 posX_OnCam = entity->posInt.x-cameraPosition.x;
	s16 posY_OnCam = entity->posInt.y-cameraPosition.y;

	//$updatePosition_Entity_always$
	if ((posX_OnCam < -entity->size.x) || (posX_OnCam > 320) || (posY_OnCam < -entity->size.y) || (posY_OnCam > 224)) {
		entity->trigger->alive = FALSE;
		return;
		entity->onScreen = FALSE;
		
	}
    else
    {
		if(!entity->onScreen) {
			if(entity->sprDef) entity->spr = SPR_addSprite(entity->sprDef, posX_OnCam, posY_OnCam, TILE_ATTR(PAL2, 11, FALSE, FALSE));
			entity->debugSpr1 = SPR_addSprite(&spr_debugLeftTopCorner, posX_OnCam, posY_OnCam, TILE_ATTR(PAL3, 11, FALSE, FALSE));
entity->debugSpr2 = SPR_addSprite(&spr_debugRightBottom, posX_OnCam, posY_OnCam, TILE_ATTR(PAL3, 11, FALSE, FALSE));

		}
        if(entity->sprDef) SPR_setPosition(entity->spr, posX_OnCam, posY_OnCam);
		if(entity->debugSpr1) SPR_setPosition(entity->debugSpr1, (entity->trigger->pos.x-cameraPosition.x)+entity->trigger->rect.min.x, (entity->trigger->pos.y-cameraPosition.y)+entity->trigger->rect.min.y);
if(entity->debugSpr2) SPR_setPosition(entity->debugSpr2, (entity->trigger->pos.x-cameraPosition.x)+entity->trigger->rect.max.x-8, (entity->trigger->pos.y-cameraPosition.y)+entity->trigger->rect.max.y-8);

		entity->timer++;
		if(entity->timer > 120){
			entity->trigger->alive = FALSE;
			return;
		}
		//Update position
		entity->pos.x += entity->spd.x;
		entity->pos.y += entity->spd.y;
		entity->posInt.x = fix32ToInt(entity->pos.x);
		entity->posInt.y = fix32ToInt(entity->pos.y);
		entity->trigger->pos.x = entity->posInt.x;
		entity->trigger->pos.y = entity->posInt.y;
		entity->onScreen = TRUE;

		entity->spd.y += 100; //+ gravity
		checkCollisions_forEntityMerged(entity);
	
		if(entity->onGround){
			entity->spd.y = FIX32(-4);
		}
    }
}
void(* showEntityFuncArr[])(EntityMerged*) = {showEntitySimple, showBarierDead, showCoin, showBarierDeadMove, showKillerBox, showJokeEngie, showsgsk_boss, showBoss_bullet, showBoss_Bullet_jump, };


void showEntityBulletMerged(EntityBulletMerged* entity){
	showEntityBulletFuncArr[entity->entityType](entity);
}

void showEntityMerged(EntityMerged* entity){
	showEntityFuncArr[entity->entityType](entity);
}

void showEntityAll(){
	if(playerBody.animModeChangable){
		playerBody.animMode = 0;
	}
	
	for(u16 i=0; i<curEntityAll->EntityBulletMerged_size; i++){
		showEntityBulletMerged(&curEntityAll->EntityBulletMerged_arr[i]);
	}
	for(u16 i=0; i<curEntityAll->Trigger_size; i++){
		checkTriggerForPlayer(&curEntityAll->Trigger_arr[i]);
	}
	for(u16 i=0; i<curEntityAll->EntityMerged_size; i++){
		showEntityMerged(&curEntityAll->EntityMerged_arr[i]);
	}
}

