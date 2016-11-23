#include "alien.h"
#include "tiro.h"
#include "aircraft.h"
void inicializa_alien0(ALIEN a[]){
    int i;
    int x = 50;
    for(i=0;i<QTDE_ALIEN;i++){
        a[i].pontuacao = 10;
        a[i].ativo = 1;
        a[i].bitmap1 = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/alien1.png");
        a[i].bitmap2 = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/alien11.png");
        a[i].bitmap3 = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/explosao1.png");
        a[i].bitmap4 = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/explosao2.png");
        a[i].bitmap5 = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/explosao3.png");
        a[i].bitmap_tiro = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/alien_shot.png");
        a[i].x_alien = x;
        a[i].y_alien = 210;
        a[i].x_tiro_alien = -5;
        a[i].y_tiro_alien = -5;
        a[i].continua_tiro = 0;
        x += 45;
    }
}

void inicializa_alien1(ALIEN a[]){
    int i;
    int x = 50;
    for(i=0;i<QTDE_ALIEN;i++){
        a[i].pontuacao = 10;
        a[i].ativo = 1;
        a[i].bitmap1 = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/alien1.png");
        a[i].bitmap2 = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/alien11.png");
        a[i].bitmap3 = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/explosao1.png");
        a[i].bitmap4 = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/explosao2.png");
        a[i].bitmap5 = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/explosao3.png");
        a[i].bitmap_tiro = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/alien_shot.png");
        a[i].x_alien = x;
        a[i].y_alien = 170;
        a[i].x_tiro_alien = -200;
        a[i].y_tiro_alien = -200;
        a[i].continua_tiro = 0;
        x += 45;
    }
}

void inicializa_alien2(ALIEN a[]){
    int i;
    int x = 50;
    for(i=0;i<QTDE_ALIEN;i++){
        a[i].pontuacao = 20;
        a[i].ativo = 1;
        a[i].bitmap1 = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/alien2.png");
        a[i].bitmap2 = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/alien22.png");
        a[i].bitmap3 = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/explosao1.png");
        a[i].bitmap4 = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/explosao2.png");
        a[i].bitmap5 = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/explosao3.png");
        a[i].bitmap_tiro = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/alien_shot.png");
        a[i].x_alien = x;
        a[i].y_alien = 130;
        a[i].x_tiro_alien = -200;
        a[i].y_tiro_alien = -200;
        a[i].continua_tiro = 0;
        x += 45;
    }
}

void inicializa_alien3(ALIEN a[]){
 	int i;
    int x = 50;
    for(i=0;i<QTDE_ALIEN;i++){
        a[i].pontuacao = 40;
        a[i].ativo = 1;
        a[i].bitmap1 = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/alien3.png");
        a[i].bitmap2 = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/alien33.png");
        a[i].bitmap3 = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/explosao1.png");
        a[i].bitmap4 = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/explosao2.png");
        a[i].bitmap5 = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/explosao3.png");
        a[i].bitmap_tiro = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/alien_shot.png");
        a[i].x_alien = x;
        a[i].y_alien = 90;
        a[i].x_tiro_alien = -200;
        a[i].y_tiro_alien = -200;
        a[i].continua_tiro = 0;
        x += 45;
    }
}

void destroi_aliens(ALIEN a[]){
    int i;
    for(i=0;i<QTDE_ALIEN;i++){
        al_destroy_bitmap(a[i].bitmap1);
        al_destroy_bitmap(a[i].bitmap2);
    }

}


void desenha_aliens(ALIEN a[], int qual_alien, int move, int *est){

    int i,j;
    for(i=0;i<QTDE_ALIEN;i++){
    		if(qual_alien == 1){
    				if(move == 1){
	    				 if(*est == 1)
	    				 	a[i].x_alien += 30;
	    				 if(*est == -1){
			    		 	a[i].x_alien -= 30;
			    		 }
		    			 if(a[0].x_alien > 230){
	    				 	for(j=0; j<QTDE_ALIEN;j++){
	    				 		a[j].y_alien += 15;
	    				 		a[j].x_alien += 30;
	    				 	}
	    				 	*est = -1;
	    				 	a[0].x_alien -= 60;
	    				 }
	    				 if(a[0].x_alien < 0){
	    				 	for(j=0; j<QTDE_ALIEN;j++){
	    				 		a[j].y_alien += 15;
	    				 		a[j].x_alien -= 30;
	    				 	}
	    				 	*est = 1;
	    				 	a[0].x_alien += 60;

	    				 }
                         if(a[i].ativo == 1)
	    				   al_draw_bitmap(a[i].bitmap1,a[i].x_alien,a[i].y_alien,0);
       				}
       				if(move == 0){
                        if(a[i].ativo == 1)
       					    al_draw_bitmap(a[i].bitmap1,a[i].x_alien,a[i].y_alien,0);
       				}
    		}
    		if(qual_alien == 2){
    				if(move == 1){
	    				 if(*est == 1)
	    				 	a[i].x_alien += 30;
	    				 if(*est == -1){
	    				 	a[i].x_alien -= 30;
	    				 }
	    				 if(a[0].x_alien > 230){
	    				 	for(j=0;j<QTDE_ALIEN;j++){
	    				 		a[j].y_alien += 15;
	    				 		a[j].x_alien += 30;
	    				 	}
	    				 	*est = -1;
	    				 	a[0].x_alien -= 60;

	    				 }
	    				 if(a[0].x_alien < 0){
	    				 	for(j=0; j<QTDE_ALIEN;j++){
	    				 		a[j].y_alien += 15;
	    				 		a[j].x_alien -= 30;
	    				 	}
	    				 	*est = 1;
	    				 	a[0].x_alien += 60;

	    				}
                        if(a[i].ativo == 1)
	    				   al_draw_bitmap(a[i].bitmap2,a[i].x_alien,a[i].y_alien,0);
    				}
    				if(move == 0){
                        if(a[i].ativo == 1)
    				        al_draw_bitmap(a[i].bitmap2,a[i].x_alien,a[i].y_alien,0);
    				}
    		}
    }
}

int verifica_aliens_mortos(ALIEN a[], ALIEN a1[], ALIEN a2[], ALIEN a3[]){

    int i, t = 1;
    for(i=0;i<QTDE_ALIEN;i++){
        if(a[i].ativo == 1)
            t = 0;
        if(a1[i].ativo == 1)
            t = 0;
        if(a2[i].ativo == 1)
            t = 0;
        if(a3[i].ativo == 1)
            t = 0;
    }
    return t;

}

void alien_atira(ALIEN a[], int escolhe_alien){

    a[escolhe_alien].x_tiro_alien = (a[escolhe_alien].x_alien+16);
    a[escolhe_alien].y_tiro_alien = (a[escolhe_alien].y_alien+15);
    a[escolhe_alien].continua_tiro = 1;

}

void desenha_tiro_alien(ALIEN a[], int escolhe_alien){
    if(a[escolhe_alien].continua_tiro == 1){
        al_draw_bitmap(a[escolhe_alien].bitmap_tiro, a[escolhe_alien].x_tiro_alien, a[escolhe_alien].y_tiro_alien,0);
        a[escolhe_alien].y_tiro_alien += 10;
    }

}

void verifica_colisao_tiro_alien(ALIEN a[], int i, BUNKER b[], AIRCRAFT *nave, int *lives){

    int j;
    for(j=0;j<QTD_BUNKER;j++){
        if((a[i].x_tiro_alien) >= (b[j].x_bunker-30) && (a[i].x_tiro_alien) <= (b[j].x_bunker+60)){
            if((a[i].y_tiro_alien) >= (b[j].y_bunker) && (a[i].y_tiro_alien) <= (b[j].y_bunker+10)){
                
                if(b[j].ativo == 1){
                    a[i].continua_tiro = 0;
                    b[j].estado++;
                    a[i].y_tiro_alien = -2;
                }

                
                if(b[j].estado == 6){ 
                    b[j].ativo = 0;
                }
            }
        }
    }

    if((a[i].x_tiro_alien) >= (nave->x_aircraft-30) && (a[i].x_tiro_alien) <= (nave->x_aircraft+70)){
            if((a[i].y_tiro_alien) >= nave->y_aircraft && (a[i].y_tiro_alien) <= nave->y_aircraft+10){
                    nave->x_aircraft = DELTA_X_TELA;
                    *lives = *lives-1;
               
                }
            }
        


}