#ifndef PACMAN_H
#define PACMAN_H

#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "principal.h"

struct pm{
	int x;
	int y;
	int VIDAS;
	int which_one;
	int sentido;
	int velocidade;
};

typedef struct pm PACMAN;

void desenha_pacman(ALLEGRO_BITMAP *b1, ALLEGRO_BITMAP *b2, ALLEGRO_BITMAP *b1u, ALLEGRO_BITMAP *b2u, ALLEGRO_BITMAP *b1d, ALLEGRO_BITMAP *b2d, int x, int y, int qual_pacman, int sentido);
void inicializa_atributos_pacman(PACMAN *p, int vidas, int x, int y);

#endif // PACMAN_H
