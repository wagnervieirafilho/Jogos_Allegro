#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "principal.h"
#include "pacman.h"




int main(void){

	ALLEGRO_DISPLAY *janela = NULL;
	ALLEGRO_BITMAP *background = NULL;
	ALLEGRO_BITMAP *pMan1 = NULL;
	ALLEGRO_BITMAP *pMan1Up = NULL;
	ALLEGRO_BITMAP *pMan1Down = NULL;
	ALLEGRO_BITMAP *pMan2 = NULL;
	ALLEGRO_BITMAP *pMan2Up = NULL;
	ALLEGRO_BITMAP *pMan2Down = NULL;
	ALLEGRO_BITMAP *ghost1 = NULL;
	ALLEGRO_BITMAP *ghost2 = NULL;
	ALLEGRO_BITMAP *ghost3 = NULL;
	ALLEGRO_BITMAP *ghost4 = NULL;
	ALLEGRO_BITMAP *dizzyGhost = NULL;
	ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    ALLEGRO_EVENT evento;
    ALLEGRO_TIMEOUT timeout;

    PACMAN pacman;

    int SAIR = 0;
    int key_pressed = 0;
    int cont = 0;

	verifica_inicializacoes_libs();
	inicializa_bitmaps(&janela, &background, &pMan1, &pMan1Up, &pMan1Down, &pMan2, &pMan2Up, &pMan2Down, &ghost1, &ghost2, &ghost3, &ghost4, &dizzyGhost);
	inicializa_atributos_pacman(&pacman,3,260, 635);
	cria_fila_eventos(&fila_eventos, janela);

	al_init_timeout(&timeout, 0.00);

	while(!SAIR){
                int tem_eventos = al_wait_for_event_until(fila_eventos, &evento, &timeout);

                if (tem_eventos && evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                    break;
                }

                if(tem_eventos && evento.type == ALLEGRO_EVENT_KEY_DOWN){
                        key_pressed = 1;
                }

                if(tem_eventos && evento.type == ALLEGRO_EVENT_KEY_UP){
                        key_pressed = 0;
                }

                 switch(evento.keyboard.keycode){

                     case ALLEGRO_KEY_ESCAPE:
                 					SAIR = 1;
                 					break;
                 	 case ALLEGRO_KEY_LEFT:
                 	 				pacman.x -= pacman.velocidade;
                 	 				pacman.sentido = ESQUERDA;
                 	 				break;
                 	 case ALLEGRO_KEY_RIGHT:
                 	 				pacman.x += pacman.velocidade;
                 	 				pacman.sentido = DIREITA;
                 	 				break;
                 	 case ALLEGRO_KEY_UP:
                 	 				pacman.y -= pacman.velocidade;
                 	 				pacman.sentido = CIMA;
                 	 				break;
                 	 case ALLEGRO_KEY_DOWN:
                 	 				pacman.y += pacman.velocidade;
                 	 				pacman.sentido = BAIXO;
                 	 				break;

                }
                cont++;
                if(cont>=20 && cont<=40)
                		pacman.which_one = 2;
                if(cont == 40){
                		pacman.which_one = 1;
                		cont = 0;
                }
                set_janela_black();
                desenha_bg_bitmap(background);
                desenha_pacman(pMan1, pMan2, pMan1Up, pMan2Up, pMan1Down, pMan2Down ,pacman.x, pacman.y, pacman.which_one, pacman.sentido);
                al_flip_display();
	}

	al_destroy_bitmap(background);
    al_destroy_bitmap(pMan2);
    al_destroy_bitmap(pMan1);
    al_destroy_bitmap(ghost1);
    al_destroy_bitmap(ghost2);
    al_destroy_bitmap(ghost3);
    al_destroy_bitmap(ghost4);
    al_destroy_event_queue(fila_eventos);
    al_destroy_display(janela);

	return 0;
}
