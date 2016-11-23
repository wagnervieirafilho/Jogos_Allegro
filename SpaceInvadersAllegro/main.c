#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "aircraft.h"
#include "boss.h"
#include "bunker.h"
#include "tiro.h"
#include "alien.h"
#include "principal.h"


#define LARGURA_TELA 900
#define ALTURA_TELA 520



int main(void)
{

    ALLEGRO_DISPLAY *janela = NULL;
    ALLEGRO_BITMAP *background = NULL;
    ALLEGRO_BITMAP *background2 = NULL;
    ALLEGRO_BITMAP *aircraft = NULL;
    ALLEGRO_BITMAP *bullet = NULL;
    ALLEGRO_BITMAP *boss = NULL;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    ALLEGRO_EVENT evento;
    ALLEGRO_TIMEOUT timeout;
    ALLEGRO_FONT *fonte = NULL;
    ALLEGRO_FONT *fonte2 = NULL;
    ALLEGRO_FONT *fonte_pontos = NULL;
    ALLEGRO_FONT *fonte_game_over = NULL;

    ALIEN alien0[QTDE_ALIEN];
    ALIEN alien1[QTDE_ALIEN];
    ALIEN alien2[QTDE_ALIEN];
    ALIEN alien3[QTDE_ALIEN];

    BUNKER bunker[QTD_BUNKER];

    BOSS bss;

    AIRCRAFT acraft;

    int SAIR = 0;
    int VIDAS = 3;
    int i;
    int x_tiro = -1000;
    int y_tiro;
    int tem_tiro = 0;
    int continua_tiro = 0;
    int escolhe_alien;
    int alien_atira_ou_nao = 0;
    int estado_alien0 = DIREITA;
    int estado_alien1 = DIREITA;
    int estado_alien2 = DIREITA;
    int estado_alien3 = DIREITA;
    int qual_alien = 1;
    int mortos = 0;
    int tem_colisao = 0;
    int key_pressed = 0;
    int cont = 0;
    int move_alien = 0;
    int cont2 = 0;
    int pontuacao = 0;
    int desenha_tela_inicio = 1;

    char p2[5];

    verifica_inicializacoes_libs();

    inicializa_aircraft(&acraft);
    inicializa_boss(&bss);                                                   								                   
    inicializa_bitmaps(&janela, &background, &background2, &boss, &aircraft, &bullet, &fonte, &fonte2, &fonte_pontos, &fonte_game_over);         
    cria_fila_eventos(&fila_eventos, janela);                                     								                   
    inicializa_alien1(&alien1);
    inicializa_alien2(&alien2);
    inicializa_alien3(&alien3);
    inicializa_alien0(&alien0);
    inicializa_bunker(&bunker);

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

                        case ALLEGRO_KEY_LEFT:
                                                if(key_pressed == 1){
                                                    if(bss.estado_boss == ESQUERDA){
                                                        acraft.x_aircraft = acraft.x_aircraft - 4;
                                                        bss.x_boss+=4;
                                                        bss.estado_boss = desenha_boss_bitmap(janela,boss,&bss);
                                                    }
                                                    if(bss.estado_boss == DIREITA){
                                                        acraft.x_aircraft = acraft.x_aircraft - 4;
                                                        bss.x_boss-=4;
                                                        bss.estado_boss = desenha_boss_bitmap(janela,boss,&bss);
                                                    }
                                                }
                                                break;

                        case ALLEGRO_KEY_RIGHT:
                                                if(key_pressed == 1){
                                                    if(bss.estado_boss == ESQUERDA){
                                                        acraft.x_aircraft = acraft.x_aircraft + 4;
                                                        bss.x_boss+=4;
                                                        bss.estado_boss = desenha_boss_bitmap(janela,boss,&bss);
                                                    }
                                                    if(bss.estado_boss == DIREITA){
                                                        acraft.x_aircraft = acraft.x_aircraft + 4;
                                                        bss.x_boss-=4;
                                                        bss.estado_boss = desenha_boss_bitmap(janela,boss,&bss);
                                                    }
                                                }
                                                break;


                        case ALLEGRO_KEY_SPACE:
                                                    if(key_pressed == 1){
                                                        key_pressed = 0;
                                                        continua_tiro = 1;
                                                        if(tem_tiro == 0){
                                                            if(desenha_tela_inicio == 0){
                                                                x_tiro = acraft.x_aircraft;
                                                                y_tiro = 448;
                                                                tem_tiro = 1;
                                                            }
                                                        }
                                                        if(desenha_tela_inicio == 1)
                                                            desenha_tela_inicio = 0;
                                                    }
                                                    break;
                        case ALLEGRO_KEY_ESCAPE:
                                                SAIR = 1;

                        case ALLEGRO_KEY_X:
                        					if(key_pressed == 1){
                                                srand( (unsigned)time(NULL) );
                                                acraft.x_aircraft = rand()%LARGURA_TELA;
                                            }
                                                break;

                }

                set_janela_black();
                desenha_tela_abertura(background2, fonte2, desenha_tela_inicio);
                if(desenha_tela_inicio == 0){
                    desenha_bg_bitmap(background, fonte, fonte2, fonte_pontos, pontuacao, VIDAS);
                    acraft.x_aircraft = desenha_aircraft_bitmap(aircraft,acraft.x_aircraft,acraft.y_aircraft);
                    desenha_tiro(bullet,x_tiro+DELTA_X+12,&y_tiro, continua_tiro);
    				bss.estado_boss = desenha_boss_bitmap(janela,boss,&bss);
                    desenha_bunker(&bunker);
                    cont++;
                    cont2++;
                    if(cont >= VEL_ALIEN/2  &&  cont <= VEL_ALIEN){
                    	qual_alien = 2;
                    }
                    if(cont == VEL_ALIEN){
                    	qual_alien = 1;
                    	cont = 0;
                    }
                    if(cont2 >= VEL_ALIEN/2  &&  cont2 <=VEL_ALIEN){
                    	move_alien = 1;
                    	cont2 = 0;
                    }
                    desenha_aliens(&alien0, qual_alien, move_alien, &estado_alien0);
                    desenha_aliens(&alien1, qual_alien, move_alien, &estado_alien1);
                    desenha_aliens(&alien2, qual_alien, move_alien, &estado_alien2);
                    desenha_aliens(&alien3, qual_alien, move_alien, &estado_alien3);


                    srand( (unsigned)time(NULL) );
                    escolhe_alien = rand()%QTDE_ALIEN;
                    srand( (unsigned)time(NULL) );
                    alien_atira_ou_nao = rand()%2;
                    if(alien_atira_ou_nao == 1  || alien_atira_ou_nao == 0){
                        alien_atira(&alien0, escolhe_alien);
                    }
                    for(i=0;i<QTDE_ALIEN;i++){
                        if(alien0[i].ativo == 1){
                            desenha_tiro_alien(&alien0, i);
                            verifica_colisao_tiro_alien(&alien0, i, &bunker, &acraft,  &VIDAS);
                        }
                        if(alien1[i].ativo == 1){
                            desenha_tiro_alien(&alien1, i);
                            verifica_colisao_tiro_alien(&alien1, i, &bunker, &acraft,  &VIDAS);
                        }
                        if(alien2[i].ativo == 1){
                            desenha_tiro_alien(&alien2, i);
                            verifica_colisao_tiro_alien(&alien2, i, &bunker, &acraft, &VIDAS);
                        }
                        if(alien3[i].ativo == 1){
                            desenha_tiro_alien(&alien3, i);
                            verifica_colisao_tiro_alien(&alien3, i, &bunker, &acraft, &VIDAS);
                        }
                   }




                    tem_colisao = verifica_colisao(x_tiro, y_tiro, &alien0, &bunker, &pontuacao, &acraft, &VIDAS);
                    if(y_tiro == -12 || tem_colisao == 1){
                        tem_tiro = 0;
                        continua_tiro = 0;
                        y_tiro = -200;
                    }
                    tem_colisao = verifica_colisao(x_tiro, y_tiro, &alien1, &bunker, &pontuacao, &acraft, &VIDAS);
                    if(y_tiro == -12 || tem_colisao == 1){
                        tem_tiro = 0;
                        continua_tiro = 0;
                        y_tiro = -200;
                    }
                     tem_colisao = verifica_colisao(x_tiro, y_tiro, &alien2, &bunker,&pontuacao, &acraft, &VIDAS);
                    if(y_tiro == -12 || tem_colisao == 1){
                        tem_tiro = 0;
                        continua_tiro = 0;
                        y_tiro = -200;
                    }
                     tem_colisao = verifica_colisao(x_tiro, y_tiro, &alien3, &bunker, &pontuacao, &acraft, &VIDAS);
                    if(y_tiro == -12 || tem_colisao == 1){
                        tem_tiro = 0;
                        continua_tiro = 0;
                        y_tiro = -200;
                    }
                    tem_colisao = verifica_colisao_boss(x_tiro, y_tiro, &bss, &pontuacao);
                    if(y_tiro == -12 || tem_colisao == 1){
                        tem_tiro = 0;
                        continua_tiro = 0;
                        y_tiro = -200;
                    }
                    move_alien = 0;
                    mortos = verifica_aliens_mortos(&alien0, &alien1, &alien2, &alien3);
                    if(mortos == 1){
                        VIDAS = 0;
                    }

                   //desenha_tela_abertura(background2, fonte2, desenha_tela_inicio);

                    if(VIDAS == 0 && mortos == 0){
                        SAIR = 1;
                        sprintf(p2, "%d", pontuacao);
                        set_janela_black();
                        desenha_bg_bitmap(background, fonte, fonte2, fonte_pontos, pontuacao,VIDAS);
                        al_draw_text(fonte_game_over, al_map_rgb(255, 255, 255), 280, 200, ALLEGRO_ALIGN_LEFT, "game over");
                        al_draw_text(fonte, al_map_rgb(255, 255, 255), 285, 260, ALLEGRO_ALIGN_LEFT, "s c o r e :");
                        al_draw_text(fonte, al_map_rgb(255, 255, 255), 410, 260, ALLEGRO_ALIGN_LEFT, p2);
                        al_flip_display();
                        al_rest(3.0);

                    }
                    if(VIDAS == 0 && mortos == 1){
                        SAIR = 1;
                        sprintf(p2, "%d", pontuacao);
                        set_janela_black();
                        desenha_bg_bitmap(background, fonte, fonte2, fonte_pontos, pontuacao, VIDAS);
                        al_draw_text(fonte_game_over, al_map_rgb(255, 255, 255), 280, 200, ALLEGRO_ALIGN_LEFT, "you win!");
                        al_draw_text(fonte, al_map_rgb(255, 255, 255), 285, 260, ALLEGRO_ALIGN_LEFT, "s c o r e :");
                        al_draw_text(fonte, al_map_rgb(255, 255, 255), 410, 260, ALLEGRO_ALIGN_LEFT, p2);
                        al_flip_display();
                        al_rest(3.0);

                    }
                }
                al_flip_display();

    }

    al_destroy_bitmap(background);
    al_destroy_bitmap(aircraft);
    al_destroy_bitmap(boss);
    al_destroy_bitmap(bunker);
    al_destroy_bitmap(bullet);
    destroi_aliens(&alien1);
    destroi_aliens(&alien2);
    destroi_aliens(&alien3);
    destroi_aliens(&alien0);
    al_destroy_event_queue(fila_eventos);
    al_destroy_display(janela);
    return 0;
}
