void showsgsk_boss(EntityMerged* entity){
    if(!entity->alive){
		return;
	}
	if(!entity->trigger->alive){
		SPR_releaseSprite(entity->spr);
		//$showTriggerRects_releaseSprite$

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
				//$showTriggerRects_releaseSprite$
			}
		}
		entity->onScreen = FALSE;
		
	}
    else
    {
		if(!entity->onScreen) {
			if(entity->sprDef) entity->spr = SPR_addSprite(entity->sprDef, posX_OnCam, posY_OnCam, TILE_ATTR(PAL0, 11, FALSE, FALSE));
			//$showTriggerRects_addSprite$
			VDP_setWindowVPos(FALSE, 1);
		}
        if(entity->sprDef) SPR_setPosition(entity->spr, posX_OnCam, posY_OnCam);
		//$showTriggerRects_moveSprite$
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