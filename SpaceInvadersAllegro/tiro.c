#include "tiro.h"
#include "alien.h"
#include "bunker.h"
void desenha_tiro(ALLEGRO_BITMAP *b, int x, int *y, int continua){
		if(continua == 1){
            *y-=10;
            al_draw_bitmap(b, x, *y, 0);
        }
}

int verifica_colisao(int x_tiro, int y_tiro, ALIEN a[], BUNKER b[], int *pont, AIRCRAFT *nave, int *lives){

	int i,j;
	int colidiu = 0;
	for(i=0;i<QTD_BUNKER;i++){
		if(x_tiro >= (b[i].x_bunker-30) && x_tiro <= (b[i].x_bunker+35)){
			if(y_tiro <= (b[i].y_bunker+40) && y_tiro >= b[i].y_bunker){

				if(b[i].ativo == 1){
					colidiu = 1;
				}
				b[i].estado++;
				if(b[i].estado == 6){
					b[i].ativo = 0;
				}
			}
		}
	}


	for(i=0;i<QTDE_ALIEN;i++){
		if(x_tiro > (a[i].x_alien-35) && x_tiro < (a[i].x_alien)){
			if(y_tiro <= (a[i].y_alien+30) && y_tiro >= a[i].y_alien){

				if(a[i].ativo == 1){
					colidiu = 1;
					*pont += a[i].pontuacao;
						desenha_explosao(a,a[i].x_alien,a[i].y_alien, i);
				}
				a[i].ativo = 0;
			}
		}

	}

	/// a partir daqui verifica se tem colisão dos aliens com os bunkers
	for(i=0;i<QTD_BUNKER;i++){
		if(b[i].ativo == 1){
			for(j=0;j<QTDE_ALIEN;j++){
				if(a[j].ativo == 1){
					if(((a[j].y_alien+30) > b[i].y_bunker)){
						if( (  (a[j].x_alien+30)  > b[i].x_bunker  && (a[j].x_alien)  < (b[i].x_bunker+ 77)) )
							b[i].ativo = 0;
					}
				}
			}

		}
	}
	for(j=0;j<QTDE_ALIEN;j++){
		if(a[j].ativo == 1){
			if(((a[j].y_alien+30) > 440)){
				if( (  (a[j].x_alien+30)  > nave->x_aircraft  && (a[j].x_alien)  < (nave->x_aircraft + 51)) )
					*lives = 0;
			}
		}
	}




	return colidiu;
}

int verifica_colisao_boss(int x_tiro, int y_tiro, BOSS *b, int *pont){
	ALLEGRO_BITMAP *bmp = NULL;
	bmp = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/explosao3.png");
	int i;
	int colidiu = 0;
		if(x_tiro > (b->x_boss-30) && x_tiro < (b->x_boss+30)){
			if(y_tiro <= b->y_boss && y_tiro >= 0){

				if(b->boss_ativo == 1){
					colidiu = 1;
					al_draw_bitmap(bmp,b->x_boss+15,b->y_boss,0);
					*pont += 400;
				}
				b->boss_ativo = 0;
			}
		}

	return colidiu;
}

void desenha_explosao(ALIEN al[], int x, int y, int t){
	al_draw_bitmap(al[0].bitmap3, x, y,0);
	al_draw_bitmap(al[0].bitmap4, x, y,0);
	al_draw_bitmap(al[0].bitmap5, x, y,0);
}
