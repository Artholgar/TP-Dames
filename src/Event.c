
#include "../include/Event.h"

#include <assert.h>

void gestion_ev(Position *pos, Case *cas, int ev, Case tab_cases[8], int *compteur_dames){
	switch (ev) {
		case KEY_UP:
			if(*cas < HAUTEUR * (LARGEUR - 1) )
				*cas += HAUTEUR;
			break;
			
		case KEY_DOWN:
			if(*cas >= LARGEUR)
				*cas -= HAUTEUR;
			break;
			
		case KEY_LEFT:
			if(*cas % 8 != 0 )
				*cas -= 1;
			break;
			
		case KEY_RIGHT:
			if((*cas + 1) % 8 != 0)
				*cas +=  1;
			break;
		case ' ':
			if ((*compteur_dames) <= 7 && placer_dame_position(pos, *cas)) {
				tab_cases[*compteur_dames] = (*cas);
				*compteur_dames += 1;
			}
			break;
		case 'r':
			if ((*compteur_dames > 0)) {
				*compteur_dames -= 1;
				(*pos) = (*pos) & ~(1L << tab_cases[*compteur_dames]);
				
			}
			break;
	}
}