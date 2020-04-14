#ifndef __AFFICHE__
#define __AFFICHE__

#include "Position.h"
#include "Cases.h"

#define LARGEUR_C 6
#define HAUTEUR_C 3

extern Position tab_cases_attaquees[64];

/*PARAMETRES : void
 *RETOUR : aucun
 *EFFET DE BORD : modifie les parametres de stdscr
 *DESCRIPTION : Cette fonction initialise la fenetre ncurses.
 */
void init_affichage (void);

/*PARAMETRES : Position pos, Case c, int couleur, Position conflits, Case courante
 *RETOUR : aucun
 *EFFET DE BORD : affiche sur stdscr
 *DESCRIPTION : Cette fonction affiche une case de la position.
 *On affiche la case de la couleur couleur, sauf si il sagit de la case ou il y a le curseur.
 *On affiche une dame en vert si elle n'a pas de conflits, en rouge sinon.
 */
void affiche_dame (Position pos, Case c, int couleur, Position conflits, Case courante);

/*PARAMETRES : Position pos, Position conflits, Case courante
 *RETOUR : aucun
 *EFFET DE BORD : affiche sur stdscr
 *DESCRIPTION : Cette fonction affiche la position du jeu.
 */
void affiche_grille (Position pos, Position conflits, Case courante);

#endif