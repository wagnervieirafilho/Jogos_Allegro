#include "aircraft.h"

int desenha_aircraft_bitmap(ALLEGRO_BITMAP *b,int x,int y){
    if((x>=0)&&(x<=LARGURA_TELA-LARGURA_AVIAO)){
        al_draw_bitmap(b, x, y, 0);
        return x;
    }
    else{
        if(x<0){
            al_draw_bitmap(b, 0, y, 0);
            x = 0;
            return x;
        }
        else{
            if(x>LARGURA_TELA-LARGURA_AVIAO){
                al_draw_bitmap(b, LARGURA_TELA-LARGURA_AVIAO, y, 0);
                x = LARGURA_TELA-LARGURA_AVIAO;
                return x;
            }
        }

    }

}


void inicializa_aircraft(AIRCRAFT *acft){
    acft -> x_aircraft = DELTA_X_TELA;
    acft -> y_aircraft = 440;
}