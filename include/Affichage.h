#ifndef __AFFICHE__
#define __AFFICHE__

#include "Position.h"
#include "Cases.h"

#define LARGEUR_C 6
#define HAUTEUR_C 3

extern Position tab_cases_attaquees[64];

void init_affichage (void);

void affiche_dame (Position pos, Case c, int couleur, Position conflits, Case courante);

void affiche_grille (Position pos, Position conflits, Case courante);

#endif