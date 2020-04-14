
#ifndef __POS__
#define __POS__

#define LARGEUR 8
#define HAUTEUR 8

typedef unsigned long long Position; 

extern Position tab_cases_attaquees[64];

/*PARAMETRES : Position pos
 *RETOUR : code d'erreur
 *EFFET DE BORD : affichage sur stdout
 *DESCRIPTION : Cette fonction permet d'afficher une position sur 
 *la sortie standard avec un '+' si il y a une dame et '.' sinon.
 */
int afficher_position (Position pos);

#endif