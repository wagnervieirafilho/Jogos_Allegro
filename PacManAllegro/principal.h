#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#define LARGURA_TELA 569
#define ALTURA_TELA 680

#define DIREITA 0
#define ESQUERDA 1
#define CIMA 2
#define BAIXO -2

void set_janela_black();
void desenha_bg_bitmap(ALLEGRO_BITMAP *b);//, ALLEGRO_FONT *f, ALLEGRO_FONT *f2, ALLEGRO_FONT *f3, int p, int lives);
//void desenha_tela_abertura(ALLEGRO_BITMAP *b, ALLEGRO_FONT *f, int x);
void verifica_inicializacoes_libs();
void cria_fila_eventos(ALLEGRO_EVENT_QUEUE **fl_ev, ALLEGRO_DISPLAY *display);
void inicializa_bitmaps(ALLEGRO_DISPLAY **jnl, ALLEGRO_BITMAP **bckgd, ALLEGRO_BITMAP **pm1, ALLEGRO_BITMAP **pm11, ALLEGRO_BITMAP **pm111, ALLEGRO_BITMAP **pm2, ALLEGRO_BITMAP **pm22, ALLEGRO_BITMAP **pm222, ALLEGRO_BITMAP **g1, ALLEGRO_BITMAP **g2,
    ALLEGRO_BITMAP **g3, ALLEGRO_BITMAP **g4, ALLEGRO_BITMAP **g5);

#endif // PRINCIPAL_H
