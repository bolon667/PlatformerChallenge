#include "../inc/levels.h"

#include "../inc/maps.h"
#include "../inc/messages.h"
#include "../inc/global.h"
#include "../inc/enums.h"

#include "../res/resources.h"
#include "../res/images.h"
#include "../res/gfx.h"
#include "../res/sprites.h"
#include "../inc/camera.h"
#include "../inc/messages.h"
#include "../inc/customScripts.h"


const EntityMerged const EntitySimple_default = {0, 0, FALSE, {0,0}, {0,0}, {0,0}, {16, 16}, FALSE, NULL, 0, NULL, FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, NULL, 1, FALSE, FALSE, 1, 0, };
const Trigger const EntitySimple_defaultTrigger = {FALSE, {0, 0}, {0, 0, 0, 0}, 0, 1, 1, 1, 1, FALSE, FALSE, };
const EntityMerged const BarierDead_default = {1, 0, FALSE, {0,0}, {0,0}, {0,0}, {16, 16}, FALSE, NULL, 0, NULL, FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, &spr_barier1, 1, FALSE, FALSE, 1, 0, };
const Trigger const BarierDead_defaultTrigger = {FALSE, {0, 0}, {0, 0, 16, 80}, TRIGGER_TYPE_restartLevel, 1, 1, 1, 1, FALSE, FALSE, };
const EntityMerged const Coin_default = {2, 0, FALSE, {0,0}, {0,0}, {0,0}, {16, 16}, FALSE, NULL, 0, NULL, FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, &spr_coin, 1, FALSE, FALSE, 1, 0, };
const EntityMerged const BarierDeadMove_default = {3, 0, FALSE, {0,0}, {0,0}, {0,0}, {16, 16}, FALSE, NULL, 0, NULL, FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, &spr_barier1, 1, FALSE, FALSE, 1, 0, };
const Trigger const BarierDeadMove_defaultTrigger = {FALSE, {0, 0}, {0, 0, 16, 80}, TRIGGER_TYPE_restartLevel, 1, 1, 1, 1, FALSE, FALSE, };
const EntityMerged const KillerBox_default = {4, 0, FALSE, {0,0}, {0,0}, {0,0}, {16, 16}, FALSE, NULL, 0, NULL, FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, &spr_killer_box, 1, FALSE, FALSE, 1, 0, };
const Trigger const KillerBox_defaultTrigger = {FALSE, {0, 0}, {0, 0, 24, 24}, TRIGGER_TYPE_restartLevel, 1, 1, 1, 1, FALSE, FALSE, };
const EntityMerged const JokeEngie_default = {5, 0, FALSE, {0,0}, {0,0}, {0,0}, {16, 16}, FALSE, NULL, 0, NULL, FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, &spr_engieJoke, 1, FALSE, FALSE, 1, 0, };
const EntityMerged const sgsk_boss_default = {6, 0, FALSE, {0,0}, {0,0}, {0,0}, {16, 16}, FALSE, NULL, 0, NULL, FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, &spr_sgdk_boss, 100, FALSE, FALSE, 0, 0, };
const Trigger const sgsk_boss_defaultTrigger = {FALSE, {0, 0}, {0, 0, 48, 64}, TRIGGER_TYPE_restartLevel, 1, 1, 1, 1, FALSE, FALSE, };
const EntityMerged const Boss_bullet_default = {7, 0, FALSE, {0,0}, {0,0}, {0,0}, {16, 16}, FALSE, NULL, 0, NULL, FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, &spr_sonic_ball, 1, FALSE, FALSE, 1, 0, };
const Trigger const Boss_bullet_defaultTrigger = {FALSE, {0, 0}, {0, 0, 32, 32}, TRIGGER_TYPE_restartLevel, 1, 1, 1, 1, FALSE, FALSE, };
const EntityMerged const Boss_Bullet_jump_default = {8, 0, FALSE, {0,0}, {0,0}, {0,0}, {16, 16}, FALSE, NULL, 0, NULL, FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, &spr_sonic_ball, 1, FALSE, FALSE, 0, 0, };
const Trigger const Boss_Bullet_jump_defaultTrigger = {FALSE, {0, 0}, {0, 0, 32, 32}, TRIGGER_TYPE_restartLevel, 1, 1, 1, 1, FALSE, FALSE, };
const EntityMerged const DungeonMaster_default = {9, 0, FALSE, {0,0}, {0,0}, {0,0}, {24, 24}, FALSE, NULL, 0, NULL, FALSE, {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL}, 0, NULL, NULL, &spr_killer_box, 1, FALSE, FALSE, 1, 0, };


const EntityBulletMerged const Bullet231_default = {0, FALSE, FALSE, {0,0}, {0,0}, {0,0}, {0,0}, FALSE, {0, 0, 8, 8}, NULL, NULL, NULL, &spr_coin, 1, 1, FALSE, FALSE, };


EntityMerged* addNew_EntitySimple(Vect2D_s16 posInt, Vect2D_f16 spd){
    Trigger* foundTrigger = NULL;
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
        return NULL;
    }

    for(u16 i=0; i<curEntityAll->EntityMerged_size; i++){
        if(!curEntityAll->EntityMerged_arr[i].alive){
            //Copying template of default values
            memcpy(&curEntityAll->EntityMerged_arr[i], &EntitySimple_default, sizeof(EntityMerged));
            //Changing pos
            curEntityAll->EntityMerged_arr[i].posInt = posInt;
            curEntityAll->EntityMerged_arr[i].pos = (Vect2D_f32){FIX32(posInt.x), FIX32(posInt.y)};
            //Changing spd
            curEntityAll->EntityMerged_arr[i].spd = spd;
            //Changing making entity ALIVE
            curEntityAll->EntityMerged_arr[i].alive = TRUE;
            //Adding trigger to entity
            curEntityAll->EntityMerged_arr[i].trigger = foundTrigger;
            KDebug_Alert("Success for EntitySimple!");
            return &curEntityAll->EntityMerged_arr[i];
        }
    }
    KDebug_Alert("Fail for EntitySimple...");
    return NULL;
}

    
    
EntityMerged* addNew_BarierDead(Vect2D_s16 posInt, Vect2D_f16 spd){
    Trigger* foundTrigger = NULL;
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
        return NULL;
    }

    for(u16 i=0; i<curEntityAll->EntityMerged_size; i++){
        if(!curEntityAll->EntityMerged_arr[i].alive){
            //Copying template of default values
            memcpy(&curEntityAll->EntityMerged_arr[i], &BarierDead_default, sizeof(EntityMerged));
            //Changing pos
            curEntityAll->EntityMerged_arr[i].posInt = posInt;
            curEntityAll->EntityMerged_arr[i].pos = (Vect2D_f32){FIX32(posInt.x), FIX32(posInt.y)};
            //Changing spd
            curEntityAll->EntityMerged_arr[i].spd = spd;
            //Changing making entity ALIVE
            curEntityAll->EntityMerged_arr[i].alive = TRUE;
            //Adding trigger to entity
            curEntityAll->EntityMerged_arr[i].trigger = foundTrigger;
            KDebug_Alert("Success for BarierDead!");
            return &curEntityAll->EntityMerged_arr[i];
        }
    }
    KDebug_Alert("Fail for BarierDead...");
    return NULL;
}

    
    
EntityMerged* addNew_Coin(Vect2D_s16 posInt, Vect2D_f16 spd){
    KDebug_Alert("new Coin");
    for(u16 i=0; i<curEntityAll->EntityMerged_size; i++){
        if(!curEntityAll->EntityMerged_arr[i].alive){
            //Copying template of default values
            memcpy(&curEntityAll->EntityMerged_arr[i], &Coin_default, sizeof(EntityMerged));
            //Changing pos
            curEntityAll->EntityMerged_arr[i].posInt = posInt;
            curEntityAll->EntityMerged_arr[i].pos = (Vect2D_f32){FIX32(posInt.x), FIX32(posInt.y)};
            //Changing spd
            curEntityAll->EntityMerged_arr[i].spd = spd;
            //Changing making entity ALIVE
            curEntityAll->EntityMerged_arr[i].alive = TRUE;
            KDebug_Alert("Success for Coin!");
            return &curEntityAll->EntityMerged_arr[i];
        }
    }
    KDebug_Alert("Fail for Coin...");
    return NULL;
}

EntityMerged* addNew_BarierDeadMove(Vect2D_s16 posInt, Vect2D_f16 spd){
    Trigger* foundTrigger = NULL;
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
        return NULL;
    }

    for(u16 i=0; i<curEntityAll->EntityMerged_size; i++){
        if(!curEntityAll->EntityMerged_arr[i].alive){
            //Copying template of default values
            memcpy(&curEntityAll->EntityMerged_arr[i], &BarierDeadMove_default, sizeof(EntityMerged));
            //Changing pos
            curEntityAll->EntityMerged_arr[i].posInt = posInt;
            curEntityAll->EntityMerged_arr[i].pos = (Vect2D_f32){FIX32(posInt.x), FIX32(posInt.y)};
            //Changing spd
            curEntityAll->EntityMerged_arr[i].spd = spd;
            //Changing making entity ALIVE
            curEntityAll->EntityMerged_arr[i].alive = TRUE;
            //Adding trigger to entity
            curEntityAll->EntityMerged_arr[i].trigger = foundTrigger;
            KDebug_Alert("Success for BarierDeadMove!");
            return &curEntityAll->EntityMerged_arr[i];
        }
    }
    KDebug_Alert("Fail for BarierDeadMove...");
    return NULL;
}

    
    
EntityMerged* addNew_KillerBox(Vect2D_s16 posInt, Vect2D_f16 spd){
    Trigger* foundTrigger = NULL;
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
        return NULL;
    }

    for(u16 i=0; i<curEntityAll->EntityMerged_size; i++){
        if(!curEntityAll->EntityMerged_arr[i].alive){
            //Copying template of default values
            memcpy(&curEntityAll->EntityMerged_arr[i], &KillerBox_default, sizeof(EntityMerged));
            //Changing pos
            curEntityAll->EntityMerged_arr[i].posInt = posInt;
            curEntityAll->EntityMerged_arr[i].pos = (Vect2D_f32){FIX32(posInt.x), FIX32(posInt.y)};
            //Changing spd
            curEntityAll->EntityMerged_arr[i].spd = spd;
            //Changing making entity ALIVE
            curEntityAll->EntityMerged_arr[i].alive = TRUE;
            //Adding trigger to entity
            curEntityAll->EntityMerged_arr[i].trigger = foundTrigger;
            KDebug_Alert("Success for KillerBox!");
            return &curEntityAll->EntityMerged_arr[i];
        }
    }
    KDebug_Alert("Fail for KillerBox...");
    return NULL;
}

    
    
EntityMerged* addNew_JokeEngie(Vect2D_s16 posInt, Vect2D_f16 spd){
    KDebug_Alert("new JokeEngie");
    for(u16 i=0; i<curEntityAll->EntityMerged_size; i++){
        if(!curEntityAll->EntityMerged_arr[i].alive){
            //Copying template of default values
            memcpy(&curEntityAll->EntityMerged_arr[i], &JokeEngie_default, sizeof(EntityMerged));
            //Changing pos
            curEntityAll->EntityMerged_arr[i].posInt = posInt;
            curEntityAll->EntityMerged_arr[i].pos = (Vect2D_f32){FIX32(posInt.x), FIX32(posInt.y)};
            //Changing spd
            curEntityAll->EntityMerged_arr[i].spd = spd;
            //Changing making entity ALIVE
            curEntityAll->EntityMerged_arr[i].alive = TRUE;
            KDebug_Alert("Success for JokeEngie!");
            return &curEntityAll->EntityMerged_arr[i];
        }
    }
    KDebug_Alert("Fail for JokeEngie...");
    return NULL;
}

EntityMerged* addNew_sgsk_boss(Vect2D_s16 posInt, Vect2D_f16 spd){
    Trigger* foundTrigger = NULL;
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
        return NULL;
    }

    for(u16 i=0; i<curEntityAll->EntityMerged_size; i++){
        if(!curEntityAll->EntityMerged_arr[i].alive){
            //Copying template of default values
            memcpy(&curEntityAll->EntityMerged_arr[i], &sgsk_boss_default, sizeof(EntityMerged));
            //Changing pos
            curEntityAll->EntityMerged_arr[i].posInt = posInt;
            curEntityAll->EntityMerged_arr[i].pos = (Vect2D_f32){FIX32(posInt.x), FIX32(posInt.y)};
            //Changing spd
            curEntityAll->EntityMerged_arr[i].spd = spd;
            //Changing making entity ALIVE
            curEntityAll->EntityMerged_arr[i].alive = TRUE;
            //Adding trigger to entity
            curEntityAll->EntityMerged_arr[i].trigger = foundTrigger;
            KDebug_Alert("Success for sgsk_boss!");
            return &curEntityAll->EntityMerged_arr[i];
        }
    }
    KDebug_Alert("Fail for sgsk_boss...");
    return NULL;
}

    
    
EntityMerged* addNew_Boss_bullet(Vect2D_s16 posInt, Vect2D_f16 spd){
    Trigger* foundTrigger = NULL;
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
        return NULL;
    }

    for(u16 i=0; i<curEntityAll->EntityMerged_size; i++){
        if(!curEntityAll->EntityMerged_arr[i].alive){
            //Copying template of default values
            memcpy(&curEntityAll->EntityMerged_arr[i], &Boss_bullet_default, sizeof(EntityMerged));
            //Changing pos
            curEntityAll->EntityMerged_arr[i].posInt = posInt;
            curEntityAll->EntityMerged_arr[i].pos = (Vect2D_f32){FIX32(posInt.x), FIX32(posInt.y)};
            //Changing spd
            curEntityAll->EntityMerged_arr[i].spd = spd;
            //Changing making entity ALIVE
            curEntityAll->EntityMerged_arr[i].alive = TRUE;
            //Adding trigger to entity
            curEntityAll->EntityMerged_arr[i].trigger = foundTrigger;
            KDebug_Alert("Success for Boss_bullet!");
            return &curEntityAll->EntityMerged_arr[i];
        }
    }
    KDebug_Alert("Fail for Boss_bullet...");
    return NULL;
}

    
    
EntityMerged* addNew_Boss_Bullet_jump(Vect2D_s16 posInt, Vect2D_f16 spd){
    Trigger* foundTrigger = NULL;
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
        return NULL;
    }

    for(u16 i=0; i<curEntityAll->EntityMerged_size; i++){
        if(!curEntityAll->EntityMerged_arr[i].alive){
            //Copying template of default values
            memcpy(&curEntityAll->EntityMerged_arr[i], &Boss_Bullet_jump_default, sizeof(EntityMerged));
            //Changing pos
            curEntityAll->EntityMerged_arr[i].posInt = posInt;
            curEntityAll->EntityMerged_arr[i].pos = (Vect2D_f32){FIX32(posInt.x), FIX32(posInt.y)};
            //Changing spd
            curEntityAll->EntityMerged_arr[i].spd = spd;
            //Changing making entity ALIVE
            curEntityAll->EntityMerged_arr[i].alive = TRUE;
            //Adding trigger to entity
            curEntityAll->EntityMerged_arr[i].trigger = foundTrigger;
            KDebug_Alert("Success for Boss_Bullet_jump!");
            return &curEntityAll->EntityMerged_arr[i];
        }
    }
    KDebug_Alert("Fail for Boss_Bullet_jump...");
    return NULL;
}

    
    
EntityMerged* addNew_DungeonMaster(Vect2D_s16 posInt, Vect2D_f16 spd){
    KDebug_Alert("new DungeonMaster");
    for(u16 i=0; i<curEntityAll->EntityMerged_size; i++){
        if(!curEntityAll->EntityMerged_arr[i].alive){
            //Copying template of default values
            memcpy(&curEntityAll->EntityMerged_arr[i], &DungeonMaster_default, sizeof(EntityMerged));
            //Changing pos
            curEntityAll->EntityMerged_arr[i].posInt = posInt;
            curEntityAll->EntityMerged_arr[i].pos = (Vect2D_f32){FIX32(posInt.x), FIX32(posInt.y)};
            //Changing spd
            curEntityAll->EntityMerged_arr[i].spd = spd;
            //Changing making entity ALIVE
            curEntityAll->EntityMerged_arr[i].alive = TRUE;
            KDebug_Alert("Success for DungeonMaster!");
            return &curEntityAll->EntityMerged_arr[i];
        }
    }
    KDebug_Alert("Fail for DungeonMaster...");
    return NULL;
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


EntityMerged* addNew_EntityMerged(EntityMerged* entity){
	Trigger* foundTrigger = NULL;
	// If entity have trigger
	if(entity->trigger != NULL){
		
		//Find first dead Trigger
		for(u16 i=0; i<curEntityAll->Trigger_size; i++){
			
			//If trigger found
			if(!curEntityAll->Trigger_arr[i].alive){
				KLog_S1("Adding trigger to slot: ", i);
				//Saving reference to trigger in var foundTrigger.
				foundTrigger = &curEntityAll->Trigger_arr[i]; 
				//And adding entity trigger to local trigger storage
				// KLog_S1("entity->trigger->pos.x: ", entity->trigger->pos.x);
				// KLog_S1("entity->trigger->pos.y: ", entity->trigger->pos.y);
				memcpy(&curEntityAll->Trigger_arr[i], entity->trigger, sizeof(Trigger));
				break;
			}
		}
	} else {
		KLog_S1("Cant add a trigger: ", curEntityAll->Trigger_size);
	}
	
	//Find first dead EntityMerged
    for(u16 i=0; i<curEntityAll->EntityMerged_size; i++){
		//If EntityMerged found
        if(!curEntityAll->EntityMerged_arr[i].alive){
			KLog_S1("Adding EntityMerged to slot: ", i);
            //Copying entity data from chunk to local entity storage
            memcpy(&curEntityAll->EntityMerged_arr[i], entity, sizeof(EntityMerged));

			
            //Adding trigger to entity
			if(foundTrigger != NULL){
				curEntityAll->EntityMerged_arr[i].trigger = foundTrigger;
			}
            
			//After you found entity, no need to waste resource on useless loop iterations.
			break;
        }
    }

    return NULL;
}

    
    

void entityCheckForBullet(EntityMerged* entity){
	//WARNING
	//If you wanna make an enemy which not desappearing after death, then, make sure that enemy does not call this function, otherwise you will get a MEMORY LEAK!!!
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

void entityCheckForBulletBySize(EntityMerged* entity){
	entity->damaged = FALSE;
	AABB entityTriggerBounds = newAABB(
		entity->posInt.x,
		entity->posInt.x + entity->size.x,
		entity->posInt.y,
		entity->posInt.y + entity->size.y
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

void deleteEntityMergedTriggerByInstId(u16 instId){
	for(u16 i = 0; i < curEntityAll->EntityMerged_size; i++){
		EntityMerged* curEntityMerged = &curEntityAll->EntityMerged_arr[i];
		if(!curEntityMerged->alive){
			continue;
		}
		if(curEntityMerged->instId == instId){
			curEntityMerged->trigger->alive = FALSE;
			break;
		}
	}
}

EntityMerged* getEntityMergedByInstId(u16 instId){
	for(u16 i = 0; i < curEntityAll->EntityMerged_size; i++){
		EntityMerged* curEntityMerged = &curEntityAll->EntityMerged_arr[i];
		if(!curEntityMerged->alive){
			continue;
		}
		if(curEntityMerged->instId == instId){
			return curEntityMerged;
		}
	}
	return NULL;
}

u16 getEntityMergedIndInArrByInstId(u16 instId){
	for(u16 i = 0; i < curEntityAll->EntityMerged_size; i++){
		EntityMerged* curEntityMerged = &curEntityAll->EntityMerged_arr[i];
		if(!curEntityMerged->alive){
			continue;
		}
		if(curEntityMerged->instId == instId){
			return i;
		}
	}
	return NULL;
}

u16 getTriggerParrentIndInArr(Trigger* trigger){
	for(u16 i = 0; i < curEntityAll->EntityMerged_size; i++){
		EntityMerged* curEntityMerged = &curEntityAll->EntityMerged_arr[i];
		if(!curEntityMerged->alive){
			continue;
		}
		if(curEntityMerged->trigger == trigger){
			return i;
		}
	}
	return NULL;
}

// EntityMerged* getRandomEntityMergedByDefId(u16 instId){
// 	//DefId = EntityType
// 	//May be will add that in the future
// 	for(u16 i = 0; i < curEntityAll->EntityMerged_size; i++){
// 		EntityMerged* curEntityMerged = &curEntityAll->EntityMerged_arr[i];
// 		if(!curEntityMerged->alive){
// 			continue;
// 		}
// 		if(curEntityMerged->instId == instId){
// 			return curEntityMerged;
// 		}
// 	}
// 	return NULL;
// }


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
			newStartPos.x = LevelFull_arr[levelNum].lvl->sizeinPx.x-playerBody.aabb.max.x-trigger->rect.max.x;
			newStartPos.y = playerBody.globalPosition.y-trigger->val3;
			break;
		case 1: //Right
			newStartPos.x = trigger->rect.max.x;
			newStartPos.y = playerBody.globalPosition.y-trigger->val3;
			break;
		case 2: //Up
			newStartPos.x = playerBody.globalPosition.x-trigger->val3;
			newStartPos.y = LevelFull_arr[levelNum].lvl->sizeinPx.y-playerBody.aabb.max.y-trigger->rect.max.y;
			break;
		case 3: //Down
			newStartPos.x = playerBody.globalPosition.x-trigger->val3;
			newStartPos.y = trigger->rect.max.y;
			break;
	}
					
	
	loadLevel(levelNum, (Vect2D_s16)newStartPos);
}
void triggerTypeFunc_deleteEntityMerged(Trigger* trigger, AABB* triggerBounds) {
trigger->alive = FALSE;
deleteEntityMergedTriggerByInstId(trigger->val1);
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
void triggerTypeFunc_printMessageNoStopV1(Trigger* trigger, AABB* triggerBounds) {
if(!trigger->activated && trigger->prevActivated){
	//just deactivated
	VDP_setWindowVPos(FALSE, 0);
}

if(trigger->activated && !trigger->prevActivated){
	//just activated
	for(s16 i=0; i<curMessagePacks[trigger->val1].len; i++){
		printMessageNoStop(curMessagePacks[trigger->val1].messages[i].str, FALSE, 1);
	}
}
					
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
void triggerTypeFunc_solidObject(Trigger* trigger, AABB* triggerBounds) {
// if((playerBody.globalPosition.y+playerBody.aabb.min.y) < (trigger->pos.y+trigger->rect.max.y)) {
// 		playerBody.globalPosition.y = trigger->pos.y+trigger->rect.max.y-playerBody.aabb.min.y+1;
// 		playerBody.velocity.fixY = 0;
// 	}
// else if((playerBody.globalPosition.y+playerBody.aabb.max.y) > (trigger->pos.y+trigger->rect.min.y)) {
// 		playerBody.globalPosition.y = trigger->pos.y-playerBody.aabb.max.y+1;
// 		playerBody.curAmountOfJumps = playerBody.maxAmountOfJumps;
// 		playerBody.velocity.fixY = 0;
// 		playerBody.onGround = TRUE;
// 	}
// if((playerBody.globalPosition.x+playerBody.aabb.max.x) > (trigger->pos.x+trigger->rect.min.x)) {
// 		playerBody.globalPosition.x = trigger->pos.x+trigger->rect.min.x-playerBody.aabb.max.x-1;
// 		playerBody.velocity.x = 0;
// 	}
if((playerBounds.max.x > triggerBounds->min.x) && (playerBounds.min.x < triggerBounds->max.x)) {
	KLog_S1("playerBounds.max.x: ", playerBounds.max.x);
	KLog_S1("triggerBounds->min.x: ", triggerBounds->min.x);
	if(playerBounds.max.x > triggerBounds->min.x){
		playerBody.globalPosition.x = triggerBounds->min.x-playerBody.aabb.max.x;
		playerBody.velocity.fixX = 0;
	}
	if(playerBounds.min.x < triggerBounds->max.x) {
		playerBody.globalPosition.x = triggerBounds->max.x;
  		playerBody.velocity.fixX = 0;
	}
	
}
// else if(playerBounds.min.x < triggerBounds->max.x) {
//  	playerBody.globalPosition.x = triggerBounds->max.x+playerBody.aabb.min.x;
//  	playerBody.velocity.fixX = 0;
// }

//This crap not working properly


}
void triggerTypeFunc_solidObjectOneWayUpTransferSpeed(Trigger* trigger, AABB* triggerBounds) {
const Vect2D_s16 const playerCenterPos = {playerBody.globalPosition.x+((playerBody.aabb.min.x + playerBody.aabb.max.x)>>1), playerBody.globalPosition.y+((playerBody.aabb.min.y + playerBody.aabb.max.y)>>1)};

if(trigger->val1 == -1){
	trigger->val1 = getTriggerParrentIndInArr(trigger);
}

if(playerCenterPos.y < triggerBounds->min.y){
	if(playerBody.velocity.fixX >= 0){
		const EntityMerged* parrent = &curEntityAll->EntityMerged_arr[trigger->val1];
		playerBody.velocity.bufferFixX += parrent->spd.x >> 4;
		playerBody.velocity.bufferFixY += parrent->spd.y >> 4;

		playerBody.globalPosition.y = trigger->pos.y-playerBody.aabb.max.y+1;
		playerBody.curAmountOfJumps = playerBody.maxAmountOfJumps;
		playerBody.onGround = TRUE;
	}
}
	


}
void triggerTypeFunc_solidObjectTransferSpeed(Trigger* trigger, AABB* triggerBounds) {
const Vect2D_s16 const playerCenterPos = {playerBody.globalPosition.x+((playerBody.aabb.min.x + playerBody.aabb.max.x)>>1), playerBody.globalPosition.y+((playerBody.aabb.min.y + playerBody.aabb.max.y)>>1)};

if(playerCenterPos.x > triggerBounds->max.x) {
	playerBody.globalPosition.x = triggerBounds->max.x - playerBody.aabb.min.x;
  	playerBody.velocity.fixX = 0;
}
else if(playerCenterPos.x < triggerBounds->min.x){
	playerBody.globalPosition.x = triggerBounds->min.x-playerBody.aabb.max.x;
	playerBody.velocity.fixX = 0;
}
if(playerCenterPos.y < triggerBounds->min.y){
	playerBody.globalPosition.y = trigger->pos.y-playerBody.aabb.max.y+1;
	playerBody.curAmountOfJumps = playerBody.maxAmountOfJumps;
	playerBody.onGround = TRUE;
}
else if(playerCenterPos.y > triggerBounds->max.y) {
	playerBody.globalPosition.y = trigger->pos.y+trigger->rect.max.y-playerBody.aabb.min.y+1;
	playerBody.velocity.fixY = 0;
}

//Transfer speed

//If, object index in EnetityMertged_arr is not found, then find it 
if(trigger->val1 == -1){
	trigger->val1 = getTriggerParrentIndInArr(trigger);
}

const EntityMerged* parrent = &curEntityAll->EntityMerged_arr[trigger->val1];
playerBody.velocity.bufferFixX += parrent->spd.x >> 4;
playerBody.velocity.bufferFixY += parrent->spd.y >> 4;

}
void(* triggerTypeFuncArr[])(Trigger*, AABB*) = {triggerTypeFunc_changeLevel, triggerTypeFunc_changeLevelv2, triggerTypeFunc_deleteEntityMerged, triggerTypeFunc_executeScript, triggerTypeFunc_forceDownPlayer, triggerTypeFunc_forceLeftPlayer, triggerTypeFunc_forceRightPlayer, triggerTypeFunc_forceUpPlayer, triggerTypeFunc_gotSomething, triggerTypeFunc_hurt, triggerTypeFunc_printMessageNoStopV1, triggerTypeFunc_restartLevel, triggerTypeFunc_showMessage, triggerTypeFunc_solidObject, triggerTypeFunc_solidObjectOneWayUpTransferSpeed, triggerTypeFunc_solidObjectTransferSpeed, };


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
	//KLog_S1("-----------", 0);
	//KLog_S1("trigger->activated: ", trigger->activated);
	//KLog_S1("trigger->prevActivated: ", trigger->prevActivated);
	trigger->prevActivated = trigger->activated;
	if((playerBounds.min.x < triggerBounds.max.x) && (playerBounds.max.x > triggerBounds.min.x) && (playerBounds.min.y < triggerBounds.max.y) && (playerBounds.max.y > triggerBounds.min.y)){
		trigger->activated = TRUE;
			// KLog_S1("trigger->type: ", trigger->type);
			// KLog_S1("trigger->val1: ", trigger->val1);
			// KLog_S1("trigger->val2: ", trigger->val2);
			// KLog_S1("trigger->val3: ", trigger->val3);
		triggerTypeFuncArr[trigger->type](trigger, &triggerBounds);
	} else {
		trigger->activated = FALSE;
		if(trigger->prevActivated) {
			triggerTypeFuncArr[trigger->type](trigger, &triggerBounds);
		}
	}
	
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
	
	if(!entity->trigger->alive){
		SPR_releaseSprite(entity->spr);
		if(entity->debugSpr1) SPR_releaseSprite(entity->debugSpr1);
if(entity->debugSpr2) SPR_releaseSprite(entity->debugSpr2);

		entity->alive = FALSE;
	}
    s16 posX_OnCam = entity->posInt.x-cameraPosition.x;
	s16 posY_OnCam = entity->posInt.y-cameraPosition.y;

	//$updatePosition_Entity_always$
	if ((posX_OnCam < -entity->size.x) || (posX_OnCam > 320) || (posY_OnCam < -entity->size.y) || (posY_OnCam > 224)) {
		if(entity->onScreen) {
			if(entity->sprDef) {
				entity->trigger->alive = FALSE;
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

			if(curLocalVariables->val3 == 123){
				entity->pos.y += 100;
			}
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

				entity->trigger->alive = FALSE;
				entity->alive = FALSE;
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
void showDungeonMaster(EntityMerged* entity){
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
			if(!entity->activated) {
entity->slaves_arr[0] = addNew_JokeEngie((Vect2D_s16){-112+entity->posInt.x, -73+entity->posInt.y}, (Vect2D_f16){0, 0});
entity->slaves_arr[1] = addNew_Coin((Vect2D_s16){25+entity->posInt.x, -115+entity->posInt.y}, (Vect2D_f16){0, 0});
entity->slaves_arr[2] = addNew_Coin((Vect2D_s16){91+entity->posInt.x, -72+entity->posInt.y}, (Vect2D_f16){0, 0});
entity->slaves_arr[3] = addNew_Coin((Vect2D_s16){41+entity->posInt.x, -67+entity->posInt.y}, (Vect2D_f16){0, 0});
entity->slaves_arr[4] = addNew_Coin((Vect2D_s16){76+entity->posInt.x, -23+entity->posInt.y}, (Vect2D_f16){0, 0});
entity->slaves_arr[5] = addNew_Coin((Vect2D_s16){78+entity->posInt.x, 37+entity->posInt.y}, (Vect2D_f16){0, 0});
entity->slaves_arr[6] = addNew_Coin((Vect2D_s16){25+entity->posInt.x, 46+entity->posInt.y}, (Vect2D_f16){0, 0});
entity->activated = TRUE;
}
entity->debugSpr1 = SPR_addSprite(&spr_debugLeftTopCorner, posX_OnCam, posY_OnCam, TILE_ATTR(PAL3, 11, FALSE, FALSE));
entity->debugSpr2 = SPR_addSprite(&spr_debugRightBottom, posX_OnCam, posY_OnCam, TILE_ATTR(PAL3, 11, FALSE, FALSE));

		}
        if(entity->sprDef) SPR_setPosition(entity->spr, posX_OnCam, posY_OnCam);
		if(entity->debugSpr1) SPR_setPosition(entity->debugSpr1, (entity->trigger->pos.x-cameraPosition.x)+entity->trigger->rect.min.x, (entity->trigger->pos.y-cameraPosition.y)+entity->trigger->rect.min.y);
if(entity->debugSpr2) SPR_setPosition(entity->debugSpr2, (entity->trigger->pos.x-cameraPosition.x)+entity->trigger->rect.max.x-8, (entity->trigger->pos.y-cameraPosition.y)+entity->trigger->rect.max.y-8);


		
		EntityMerged* curSlave;
		entity->timer += 10;
		for(u16 curSlaveInd=0; curSlaveInd<entity->slave_amount; curSlaveInd++){
			curSlave = entity->slaves_arr[curSlaveInd];
			curSlave->posInt.x = entity->posInt.x + fix16ToInt(sinFix16(entity->timer+(curSlaveInd*100))*50)-30;
			curSlave->posInt.y = entity->posInt.x + fix16ToInt(cosFix16(entity->timer+(curSlaveInd*100))*50)-100;
			curSlave->trigger->pos.x = curSlave->posInt.x;
			curSlave->trigger->pos.y = curSlave->posInt.y;

		}
		
		entity->onScreen = TRUE;
    }
}
void(* showEntityFuncArr[])(EntityMerged*) = {showEntitySimple, showBarierDead, showCoin, showBarierDeadMove, showKillerBox, showJokeEngie, showsgsk_boss, showBoss_bullet, showBoss_Bullet_jump, showDungeonMaster, };


void showEntityBulletMerged(EntityBulletMerged* entity){
	showEntityBulletFuncArr[entity->entityType](entity);
}

void showEntityMerged(EntityMerged* entity){
	showEntityFuncArr[entity->entityType](entity);
}


void showEntityAll(){
	for(u16 i=0; i<curEntityAll->EntityBulletMerged_size; i++){
		showEntityBulletMerged(&curEntityAll->EntityBulletMerged_arr[i]);
	}
	for(u16 i=0; i<curEntityAll->EntityMerged_size; i++){
		showEntityMerged(&curEntityAll->EntityMerged_arr[i]);
	}
}
