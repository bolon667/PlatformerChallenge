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
				//$showTriggerRects_releaseSprite$
			}
		}
		entity->onScreen = FALSE;
		
	}
    else
    {
		if(!entity->onScreen) {
			if(entity->sprDef) entity->spr = SPR_addSprite(entity->sprDef, posX_OnCam, posY_OnCam, TILE_ATTR(ENEMY_PALETTE, 11, FALSE, FALSE));
			//$showTriggerRects_addSprite$
		}
        if(entity->sprDef) SPR_setPosition(entity->spr, posX_OnCam, posY_OnCam);
		//$showTriggerRects_moveSprite$

		
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