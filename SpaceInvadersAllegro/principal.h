#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

void set_janela_black();
void desenha_bg_bitmap(ALLEGRO_BITMAP *b, ALLEGRO_FONT *f, ALLEGRO_FONT *f2, ALLEGRO_FONT *f3, int p, int lives);
void desenha_tela_abertura(ALLEGRO_BITMAP *b, ALLEGRO_FONT *f, int x);
void verifica_inicializacoes_libs();
void cria_fila_eventos(ALLEGRO_EVENT_QUEUE **fl_ev, ALLEGRO_DISPLAY *display);
void inicializa_bitmaps(ALLEGRO_DISPLAY **jnl, ALLEGRO_BITMAP **bckgd, ALLEGRO_BITMAP **bckgd2, ALLEGRO_BITMAP **bss, ALLEGRO_BITMAP **acft, ALLEGRO_BITMAP **bull,  ALLEGRO_FONT **f, ALLEGRO_FONT **f2, ALLEGRO_FONT **f3,
     ALLEGRO_FONT **f4);

#endif // PRINCIPAL_H
