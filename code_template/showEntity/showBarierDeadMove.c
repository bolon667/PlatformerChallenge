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
				//$showTriggerRects_releaseSprite$
			}
		}
		entity->onScreen = FALSE;
		
	}
    else
    {
		if(!entity->onScreen) {
			if(entity->sprDef) entity->spr = SPR_addSprite(entity->sprDef, posX_OnCam, posY_OnCam, TILE_ATTR(ENEMY_PALETTE, 11, FALSE, FALSE));
			entity->spd.x = FIX32(2);
			//$showTriggerRects_addSprite$
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
		//$showTriggerRects_moveSprite$
		
		entity->onScreen = TRUE;
    }
}