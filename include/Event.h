#ifndef __EVENT__
#define __EVENT__

#include "Position.h"
#include "Cases.h"
#include "Affichage.h"
#include <ncurses.h>

extern Position tab_cases_attaquees[64];

void gestion_ev(Position *pos, Case *cas, int ev, Case tab_cases[8], int *compteur_dames);


#endif