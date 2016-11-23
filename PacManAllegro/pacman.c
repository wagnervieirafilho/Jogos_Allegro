#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "principal.h"
#include "pacman.h"

void inicializa_atributos_pacman(PACMAN *p, int vidas, int x, int y){
	p->VIDAS = vidas;
	p->x = x;
	p->y = y;
	p->which_one = 1;
	p->sentido = DIREITA;
	p->velocidade = 3;
}

void desenha_pacman(ALLEGRO_BITMAP *b1, ALLEGRO_BITMAP *b2, ALLEGRO_BITMAP *b1u, ALLEGRO_BITMAP *b2u, ALLEGRO_BITMAP *b1d, ALLEGRO_BITMAP *b2d, int x, int y, int qual_pacman, int sentido){

	if(qual_pacman == 1){
		if(sentido == DIREITA)
			al_draw_bitmap(b1, x, y, sentido);
		if(sentido == ESQUERDA)
			al_draw_bitmap(b1, x, y, sentido);
		if(sentido == CIMA)
			al_draw_bitmap(b1u, x, y, 0);
		if(sentido == BAIXO)
			al_draw_bitmap(b1d, x, y, 0);
	}
	if(qual_pacman == 2){
		if(sentido == DIREITA)
			al_draw_bitmap(b2, x, y, sentido);
		if(sentido == ESQUERDA)
			al_draw_bitmap(b2, x, y, sentido);
		if(sentido == CIMA)
			al_draw_bitmap(b2u, x, y, 0);
		if(sentido == BAIXO)
			al_draw_bitmap(b2d, x, y, 0);
	}

}
