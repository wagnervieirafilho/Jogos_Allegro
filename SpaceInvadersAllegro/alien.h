#ifndef ALIEN_H
#define ALIEN_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "bunker.h"
#include "aircraft.h"

#define DELTA_X_TELA (LARGURA_TELA/2)
#define DELTA_X (LARGURA_AVIAO/2)
#define DELTA_Y (ALTURA_AVIAO/2)

#define LARGURA_AVIAO 52
#define ALTURA_AVIAO  78

#define LARGURA_TELA 900
#define ALTURA_TELA 520

#define QTDE_ALIEN 14

#define VEL_ALIEN 80


struct alien{

    int pontuacao;
    ALLEGRO_BITMAP *bitmap1;
    ALLEGRO_BITMAP *bitmap2;
    ALLEGRO_BITMAP *bitmap3;
    ALLEGRO_BITMAP *bitmap4;
    ALLEGRO_BITMAP *bitmap5;
	ALLEGRO_BITMAP *bitmap_tiro;
    int x_alien, y_alien, x_tiro_alien, y_tiro_alien, continua_tiro;
    int ativo;
};

typedef struct alien ALIEN;

void inicializa_alien0(ALIEN a[]);
void inicializa_alien1(ALIEN a[]);
void inicializa_alien2(ALIEN a[]);
void inicializa_alien3(ALIEN a[]);

void destroi_aliens(ALIEN a[]);

void desenha_aliens(ALIEN a[], int qual_alien, int move, int *est);
int verifica_aliens_mortos(ALIEN a[], ALIEN a1[], ALIEN a2[], ALIEN a3[]);
void verifica_colisao_tiro_alien(ALIEN a[], int i, BUNKER b[], AIRCRAFT *nave, int *lives);
void alien_atira(ALIEN a[], int escolhe_alien);
void desenha_tiro_alien(ALIEN a[], int escolhe_alien);
//int random_alien();
//void desenha_tiro_alien(ALIEN a[]);

#endif // ALIEN_H
