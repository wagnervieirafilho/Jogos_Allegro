#ifndef TIRO_H
#define TIRO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "alien.h"
#include "bunker.h"
#include "boss.h"
#include "aircraft.h"

void desenha_tiro(ALLEGRO_BITMAP *b, int x, int *y, int continua);
int verifica_colisao(int x_tiro, int y_tiro, ALIEN a[], BUNKER b[], int *pont, AIRCRAFT *nave, int *lives);
int verifica_colisao_boss(int x_tiro, int y_tiro, BOSS *b, int *pont);
void desenha_explosao(ALIEN al[], int x, int y, int t);

#endif // TIRO_H
