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