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