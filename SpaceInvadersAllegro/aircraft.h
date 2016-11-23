#ifndef AIRCRAFT_H
#define AIRCRAFT_H

//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#define DELTA_X_TELA (LARGURA_TELA/2)
#define DELTA_X (LARGURA_AVIAO/2)
#define DELTA_Y (ALTURA_AVIAO/2)

#define LARGURA_AVIAO 78
#define ALTURA_AVIAO  52

#define LARGURA_TELA 900
#define ALTURA_TELA 520

struct nave
{
	int x_aircraft;
	int y_aircraft;
	
};

typedef struct nave AIRCRAFT;

int desenha_aircraft_bitmap(ALLEGRO_BITMAP *b,int x,int y);

void inicializa_aircraft(AIRCRAFT *acft);



#endif // AIRCRAFT_H
