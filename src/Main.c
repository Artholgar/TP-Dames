
#include "../include/Test.h"
#include "../include/Position.h"
#include "../include/Cases.h"
#include "../include/Affichage.h"
#include "../include/Event.h"

#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>



Position tab_cases_attaquees[64];

int main (void) {
    Position pos;
	Case cas;
	int compteur_dames, touche;
	Case tab_cases[8];
	//int i;

    init_tab_cases_attaquees();

    pos = 0;
	cas = A1;
	compteur_dames = 0;
	
	
    test();	
	
	init_affichage();

	affiche_grille(pos, est_sans_attaque_mutuelle(pos), cas);

	while (compteur_dames != 8 || est_sans_attaque_mutuelle(pos) != 0L) {

		touche = getch();

		gestion_ev(&pos, &cas, touche, tab_cases, &compteur_dames);

		affiche_grille(pos, est_sans_attaque_mutuelle(pos), cas);
		
	}
	sleep(1);
	clear();
	mvprintw((HAUTEUR * HAUTEUR_C) / 2, (LARGEUR * LARGEUR_C) / 2, "Vous avez gagné !");
	refresh();
    getchar();

    endwin();


    return 0;
}