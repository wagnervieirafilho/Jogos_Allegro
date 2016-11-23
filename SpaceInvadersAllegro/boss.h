#ifndef BOSS_H
#define BOSS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#define DIREITA 1
#define ESQUERDA -1

#define LARGURA_TELA 900
#define ALTURA_TELA 520

struct chefao{
	int x_boss;
	int y_boss;
    int estado_boss;
    int boss_ativo;
};
typedef struct chefao BOSS;	

int desenha_boss_bitmap(ALLEGRO_DISPLAY *display, ALLEGRO_BITMAP *b, BOSS *bs);
void inicializa_boss(BOSS *b);

#endif // BOSS_H
