void showBoss_Bullet_jump(EntityMerged* entity){
    if(!entity->alive){
		return;
	}
	if(!entity->trigger->alive){
		entity->alive = FALSE;
		SPR_releaseSprite(entity->spr);
		//$showTriggerRects_releaseSprite$
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
			//$showTriggerRects_addSprite$
		}
        if(entity->sprDef) SPR_setPosition(entity->spr, posX_OnCam, posY_OnCam);
		//$showTriggerRects_moveSprite$
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