#ifndef __CASES__
#define __CASES__

#include "Position.h"

extern Position tab_cases_attaquees[64];

typedef enum cas {
    A1,
    B1,
    C1,
    D1,
    E1,
    F1,
    G1,
    H1,
    A2,
    B2,
    C2,
    D2,
    E2,
    F2,
    G2,
    H2,
    A3,
    B3,
    C3,
    D3,
    E3,
    F3,
    G3,
    H3,
    A4,
    B4,
    C4,
    D4,
    E4,
    F4,
    G4,
    H4,
    A5,
    B5,
    C5,
    D5,
    E5,
    F5,
    G5,
    H5,
    A6,
    B6,
    C6,
    D6,
    E6,
    F6,
    G6,
    H6,
    A7,
    B7,
    C7,
    D7,
    E7,
    F7,
    G7,
    H7,
    A8,
    B8,
    C8,
    D8,
    E8,
    F8,
    G8,
    H8,
} Case;

/*PARAMETRES : Position pos, Case c
 *RETOUR : int
 *EFFET DE BORD : aucun
 *DESCRIPTION : Cette fonction détermine si une case de la 
 *position est occupée, on renvoie 1 si c'est le cas et 0 sinon.
 */
int est_case_occupee (Position pos, Case c);

/*PARAMETRES : Position * pos, Case c
 *RETOUR : int
 *EFFET DE BORD : modifie pos
 *DESCRIPTION : Cette fonction ajoute une dame à la position, 
 *on renvera 1 si la dame a pu être placée, 0 sinon.
 */
int placer_dame_position (Position * pos, Case c);

/*PARAMETRES : Position * pos, Case c
 *RETOUR : code d'erreur
 *EFFET DE BORD : modifie pos
 *DESCRIPTION : Cette fonction permet de stoquer dans la 
 *position toutes les cases attaqués par la dame placé en c.
 */
int calculer_cases_attaquees (Position * pos, Case c);

/*PARAMETRES : void
 *RETOUR : code d'erreur
 *EFFET DE BORD : aucun
 *DESCRIPTION : Cette fonction initialise le tableau tab_cases_attaques 
 *avec pr chaque element du tabeau la position contenant les cases 
 *attaqués par la case de l'indice du tableau.
 */
int init_tab_cases_attaquees (void);

/*PARAMETRES : Position pos
 *RETOUR : Position
 *EFFET DE BORD : aucun
 *DESCRIPTION : Cette fonction détermine si il y a des dames 
 *qui s'attaquent dans la position, si il n'y a aucune attaque 
 *on renvoie 0, sinon on renvoie la position contentnat 
 *les dames qui posent probleme.
 */
Position est_sans_attaque_mutuelle (Position pos);

#endif