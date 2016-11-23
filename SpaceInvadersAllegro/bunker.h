#ifndef BUNKER_H
#define BUNKER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#define DELTA_X_TELA (LARGURA_TELA/2)
#define DELTA_X (LARGURA_AVIAO/2)
#define DELTA_Y (ALTURA_AVIAO/2)

#define LARGURA_AVIAO 52
#define ALTURA_AVIAO  78

#define QTD_BUNKER 5

#define LARGURA_TELA 900
#define ALTURA_TELA 520

struct bk{
	ALLEGRO_BITMAP *bitmap_bunker1;
	ALLEGRO_BITMAP *bitmap_bunker2;
	ALLEGRO_BITMAP *bitmap_bunker3;
	ALLEGRO_BITMAP *bitmap_bunker4;
	ALLEGRO_BITMAP *bitmap_bunker5;
	ALLEGRO_BITMAP *bitmap_bunker6;

	int x_bunker, y_bunker, estado, ativo;
};
typedef struct bk BUNKER;
void inicializa_bunker(BUNKER b[]);
void desenha_bunker(BUNKER b[]);

#endif // BUNKER_H
