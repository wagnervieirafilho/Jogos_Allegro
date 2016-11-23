#include "principal.h"

#define LARGURA_TELA 900
#define ALTURA_TELA 520

void set_janela_black(){
    al_clear_to_color(al_map_rgb(0, 0, 0));
}

void desenha_bg_bitmap(ALLEGRO_BITMAP *b, ALLEGRO_FONT *f, ALLEGRO_FONT *f2, ALLEGRO_FONT *f3, int p, int lives){
    char p2[10];
    sprintf(p2, "%d", p);
    al_draw_bitmap(b, 0, 0, 0);
    al_draw_text(f, al_map_rgb(255, 255, 255), 10, 5, ALLEGRO_ALIGN_LEFT, "s c o r e :");
    al_draw_text(f3, al_map_rgb(255, 255, 255), 150, 5, ALLEGRO_ALIGN_LEFT, p2);

    sprintf(p2, "%d", lives);
    al_draw_text(f2, al_map_rgb(255, 255, 255), 650, 5, ALLEGRO_ALIGN_LEFT, "l i v e s :");
    al_draw_text(f2, al_map_rgb(255, 255, 255), 750, 5, ALLEGRO_ALIGN_LEFT, "x");
    al_draw_text(f2, al_map_rgb(255, 255, 255), 765, 5, ALLEGRO_ALIGN_LEFT, p2);
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

void desenha_tela_abertura(ALLEGRO_BITMAP *b, ALLEGRO_FONT *f, int x){

        if(x == 1){
                al_draw_bitmap(b, 0, 0, 0);
                al_draw_text(f, al_map_rgb(255, 255, 255), 10, 5, ALLEGRO_ALIGN_LEFT, "s c o r e :");
                al_draw_text(f, al_map_rgb(255, 255, 255), 650, 5, ALLEGRO_ALIGN_LEFT, "l i v e s :");
                al_draw_text(f, al_map_rgb(255, 255, 255), 330, 400, ALLEGRO_ALIGN_LEFT, "press  'space'  to start");

        }
}


void inicializa_bitmaps(ALLEGRO_DISPLAY **jnl, ALLEGRO_BITMAP **bckgd, ALLEGRO_BITMAP **bckgd2, ALLEGRO_BITMAP **bss, ALLEGRO_BITMAP **acft, ALLEGRO_BITMAP **bull,  ALLEGRO_FONT **f, ALLEGRO_FONT **f2, ALLEGRO_FONT **f3,
     ALLEGRO_FONT **f4){

    *jnl = al_create_display(LARGURA_TELA, ALTURA_TELA);

    al_set_window_title(*jnl, "Space Invaders v1.0");

    *bckgd = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/bg.jpg");

    *bckgd2 = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/spaceInvadersAbertura.jpg");

    *bss = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/boss.png");

    *acft = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/fighterJet.png");

    *bull = al_load_bitmap("/home/wagner/Documentos/UFRJ/Comp 1 e 2/SpaceInvadersAllegro/images/bullet.png");

    *f = al_load_font("/usr/share/fonts/truetype/starjedi/Starjedi.ttf", 16, 0);

    *f2 = al_load_font("/usr/share/fonts/truetype/starjedi/Starjedi.ttf", 16, 0);

    *f3 = al_load_font("/usr/share/fonts/truetype/starjedi/Starjedi.ttf", 16, 0);

    *f4 = al_load_font("/usr/share/fonts/truetype/starjedi/Starjedi.ttf", 48, 0);



}
