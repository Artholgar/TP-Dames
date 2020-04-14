#ifndef __EVENT__
#define __EVENT__

#include "Position.h"
#include "Cases.h"
#include "Affichage.h"
#include <ncurses.h>

extern Position tab_cases_attaquees[64];

/*PARAMETRES : Position *pos, Case *cas, int ev, Case tab_cases[8], int *compteur_dames
 *RETOUR : aucun
 *EFFET DE BORD : affiche sur stdscr, modifie pos, cas, tab_cases et compeur_dames
 *DESCRIPTION : Cette fonctiongere les evenements.
 *On déplace cas si l'utilisateur appuie sur les fleches.
 *On ajoute une dame si il appuie sur espace.
 */
void gestion_ev(Position *pos, Case *cas, int ev, Case tab_cases[8], int *compteur_dames);


#endif