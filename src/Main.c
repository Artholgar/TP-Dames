
#include "../include/Test.h"
#include "../include/Position.h"
#include "../include/Cases.h"
#include "../include/Reso.h"
#include "../include/Affichage.h"
#include "../include/Event.h"

#include <stdio.h>

Position tab_cases_attaquees[64];

int main (void) {
    Position pos;

    pos = 0;

    test();


    placer_dame_position(&pos, A1);

    placer_dame_position(&pos, B1);

    placer_dame_position(&pos, H8);

    

    pos = 0;

    calculer_cases_attaquees(&pos, F3);

    afficher_position(pos);
    return 0;
}