
#ifndef __POS__
#define __POS__

#define LARGEUR 8
#define HAUTEUR 8

typedef unsigned long long Position; 

extern Position tab_cases_attaquees[64];

int afficher_position (Position pos);

#endif