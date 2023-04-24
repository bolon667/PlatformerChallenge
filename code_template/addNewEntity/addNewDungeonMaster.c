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
