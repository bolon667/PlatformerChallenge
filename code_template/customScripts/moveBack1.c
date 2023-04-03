void moveBack1(){
    backXScroll++;
    backYScroll++;

    VDP_setHorizontalScroll(BG_B, backXScroll);
    VDP_setVerticalScroll(BG_B, backYScroll);
}