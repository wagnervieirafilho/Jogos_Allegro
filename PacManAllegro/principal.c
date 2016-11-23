#include "principal.h"

void set_janela_black(){
    al_clear_to_color(al_map_rgb(0, 0, 0));
}

void desenha_bg_bitmap(ALLEGRO_BITMAP *b){
    //char p2[10];
    //sprintf(p2, "%d", p);
    al_draw_bitmap(b, 0, 30, 0);
    //al_draw_text(f, al_map_rgb(255, 255, 255), 10, 5, ALLEGRO_ALIGN_LEFT, "s c o r e :");
    //al_draw_text(f3, al_map_rgb(255, 255, 255), 150, 5, ALLEGRO_ALIGN_LEFT, p2);

    //sprintf(p2, "%d", lives);
    //al_draw_text(f2, al_map_rgb(255, 255, 255), 650, 5, ALLEGRO_ALIGN_LEFT, "l i v e s :");
    //al_draw_text(f2, al_map_rgb(255, 255, 255), 750, 5, ALLEGRO_ALIGN_LEFT, "x");
    //al_draw_text(f2, al_map_rgb(255, 255, 255), 765, 5, ALLEGRO_ALIGN_LEFT, p2);
}


void verifica_inicializacoes_libs(){
    if (!al_init()){
        fprintf(stderr, "Falha ao inicializar a Allegro.\n");
    }

    if (!al_init_image_addon()){
        fprintf(stderr, "Falha ao inicializar add-on allegro_image.\n");
    }
    if (!al_install_keyboard()){
        fprintf(stderr, "Falha ao inicializar o teclado.\n");
    }

    al_init_font_addon();

    if (!al_init_ttf_addon()){
        fprintf(stderr, "Falha ao inicializar add-on allegro_ttf.\n");
    }
}



void cria_fila_eventos(ALLEGRO_EVENT_QUEUE **fl_ev, ALLEGRO_DISPLAY *display){
        *fl_ev = al_create_event_queue();

        al_register_event_source(*fl_ev, al_get_keyboard_event_source());

        al_register_event_source(*fl_ev, al_get_display_event_source(display));
}
/*
void desenha_tela_abertura(ALLEGRO_BITMAP *b, ALLEGRO_FONT *f, int x){

        if(x == 1){
                al_draw_bitmap(b, 0, 0, 0);
                al_draw_text(f, al_map_rgb(255, 255, 255), 10, 5, ALLEGRO_ALIGN_LEFT, "s c o r e :");
                al_draw_text(f, al_map_rgb(255, 255, 255), 650, 5, ALLEGRO_ALIGN_LEFT, "l i v e s :");
                al_draw_text(f, al_map_rgb(255, 255, 255), 330, 400, ALLEGRO_ALIGN_LEFT, "press  'space'  to start");

        }
}*/


void inicializa_bitmaps(ALLEGRO_DISPLAY **jnl, ALLEGRO_BITMAP **bckgd, ALLEGRO_BITMAP **pm1, ALLEGRO_BITMAP **pm11, ALLEGRO_BITMAP **pm111, ALLEGRO_BITMAP **pm2, ALLEGRO_BITMAP **pm22, ALLEGRO_BITMAP **pm222, ALLEGRO_BITMAP **g1, ALLEGRO_BITMAP **g2,
    ALLEGRO_BITMAP **g3, ALLEGRO_BITMAP **g4, ALLEGRO_BITMAP **g5){

    *jnl = al_create_display(LARGURA_TELA, ALTURA_TELA);

    al_set_window_title(*jnl, "Pac Man v1.0");

    *bckgd = al_load_bitmap("/home/wagner/Documentos/PacManAllegro/images/maze.png");

    *pm1 = al_load_bitmap("/home/wagner/Documentos/PacManAllegro/images/pacman.png");

    *pm11 = al_load_bitmap("/home/wagner/Documentos/PacManAllegro/images/pacmanUp.png");

    *pm111 = al_load_bitmap("/home/wagner/Documentos/PacManAllegro/images/pacmanDown.png");

    *pm2 = al_load_bitmap("/home/wagner/Documentos/PacManAllegro/images/pacman2.png");

    *pm22 = al_load_bitmap("/home/wagner/Documentos/PacManAllegro/images/pacman2Up.png");

    *pm222 = al_load_bitmap("/home/wagner/Documentos/PacManAllegro/images/pacman2Down.png");

    *g1 = al_load_bitmap("/home/wagner/Documentos/PacManAllegro/images/blueGhost.png");

    *g2 = al_load_bitmap("/home/wagner/Documentos/PacManAllegro/images/redGhost.png");

    *g3 = al_load_bitmap("/home/wagner/Documentos/PacManAllegro/images/pinkGhost.png");

    *g4 = al_load_bitmap("/home/wagner/Documentos/PacManAllegro/images/yellowGhost.png");

    *g5 = al_load_bitmap("/home/wagner/Documentos/PacManAllegro/images/dizzyGhost.png");



}
