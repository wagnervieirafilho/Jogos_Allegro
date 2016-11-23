#include "boss.h"
int desenha_boss_bitmap(ALLEGRO_DISPLAY *display, ALLEGRO_BITMAP *b, BOSS *bs){

    int a,c;

    srand( (unsigned)time(NULL) );
    srand( (unsigned)time(NULL) );

    a = 2*(rand()%501);
    c = 2*(rand()%501);
    if(bs->boss_ativo == 1){
        if(bs->estado_boss == DIREITA){
            if(bs->x_boss<=LARGURA_TELA+a){
                bs->x_boss+=4;
                al_draw_bitmap(b, bs->x_boss, bs->y_boss, 0);

                return DIREITA;
            }

            if(bs->x_boss > LARGURA_TELA+a){
                return ESQUERDA;
            }

        }

        if(bs->estado_boss == ESQUERDA){
            if(bs->x_boss >= -c){
                bs->x_boss-=4;
               al_draw_bitmap(b, bs->x_boss, bs->y_boss, 0);

                return ESQUERDA;
            }
            if(bs->x_boss < -c){
                return DIREITA;
            }

        }
    }
    else{
        if(bs->estado_boss == DIREITA){
            if(bs->x_boss <= LARGURA_TELA+a){
                bs->x_boss+=4;
                //al_draw_bitmap(b, *x, y, 0);

                return DIREITA;
            }

            if(bs->x_boss > LARGURA_TELA+a){
                return ESQUERDA;
            }

        }

        if(bs->estado_boss == ESQUERDA){
            if(bs->x_boss >= -c){
                bs->x_boss-=4;
               //al_draw_bitmap(b, *x, y, 0);

                return ESQUERDA;
            }
            if(bs->x_boss < -c){
                return DIREITA;
            }

        }
    }



 }


void inicializa_boss(BOSS *b){
	b->x_boss = -50;
	b->y_boss = 40;
	b->estado_boss = DIREITA;
	b->boss_ativo = 1;
}