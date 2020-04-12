
#include "../include/Test.h"
#include "../include/Position.h"
#include "../include/Cases.h"
#include "../include/Affichage.h"
#include "../include/Event.h"

#include <stdio.h>
#include <ncurses.h>



Position tab_cases_attaquees[64];

int main (void) {
    Position pos;
    //int i;

    init_tab_cases_attaquees();

    pos = 0;

    test();


    placer_dame_position(&pos, A1);

    placer_dame_position(&pos, G3);

    placer_dame_position(&pos, C5);

    placer_dame_position(&pos, D7);

    placer_dame_position(&pos, H8);



    init_affichage();

    affiche_grille(pos, est_sans_attaque_mutuelle(pos));

    /*for (i = 0; i < 64; i++) {
        afficher_position(tab_cases_attaquees[i]);
        printf("\n\n");
    }*/

    getchar();

    endwin();


    return 0;
}