#include "bunker.h"
void desenha_bunker(BUNKER b[]){
    int i;
    for(i=0;i<QTD_BUNKER;i++){
        if(b[i].ativo == 1){
            if(b[i].estado == 0){
                al_draw_bitmap(b[i].bitmap_bunker1, b[i].x_bunker, b[i].y_bunker, 0);
            }
            if(b[i].estado == 1){
                al_draw_bitmap(b[i].bitmap_bunker2, b[i].x_bunker, b[i].y_bunker, 0);
            }
            if(b[i].estado == 2){
                al_draw_bitmap(b[i].bitmap_bunker3, b[i].x_bunker, b[i].y_bunker, 0);
            }
            if(b[i].estado == 3){
                al_draw_bitmap(b[i].bitmap_bunker4, b[i].x_bunker, b[i].y_bunker, 0);
            }
            if(b[i].estado == 4){
                al_draw_bitmap(b[i].bitmap_bunker5, b[i].x_bunker, b[i].y_bunker, 0);
            }
            if(b[i].estado == 5){
                al_draw_bitmap(b[i].bitmap_bunker6, b[i].x_bunker, b[i].y_bunker, 0);
            }
        }
     
    }
}

void inicializa_bunker(BUNKER b[]){
	int i;
    int x = 55;
    for(i=0;i<QTD_BUNKER;i++){
        b[i].bitmap_bunker1 = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/bunker.png");
        b[i].bitmap_bunker2 = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/bunker1.png");
        b[i].bitmap_bunker3 = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/bunker2.png");
        b[i].bitmap_bunker4 = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/bunker3.png");
        b[i].bitmap_bunker5 = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/bunker4.png");
        b[i].bitmap_bunker6 = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/bunker5.png");
        b[i].x_bunker = x;
        b[i].y_bunker = 370;
        b[i].estado = 0;
        b[i].ativo = 1;
        x += 165;
    }
}
