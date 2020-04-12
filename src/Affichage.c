
#include "../include/Affichage.h"

#include <assert.h>
#include <ncurses.h>

void init_affichage (void) {
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	mousemask(ALL_MOUSE_EVENTS | REPORT_MOUSE_POSITION, NULL);
	
	start_color();
	
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_WHITE, COLOR_WHITE);
    init_pair(3, COLOR_WHITE, COLOR_GREEN);
	init_pair(4, COLOR_WHITE, COLOR_RED);
}

void affiche_dame (Position pos, Case c, int couleur, Position conflits) {
	int x, y;
	int n, m;
	int ordonnee, abscisse;

	n = 0;

	ordonnee = HAUTEUR_C * (c / HAUTEUR);
	abscisse = LARGEUR_C * (c % LARGEUR);
	
	attron(COLOR_PAIR(couleur));
	
	
	for(y = ordonnee; y < ordonnee + HAUTEUR_C; y++){
		for(x = abscisse; x < abscisse + LARGEUR_C; x++){
            if (y == ordonnee + 1 && (x == abscisse + 2 || x == abscisse + 3)) {
                if(est_case_occupee(pos, c) && !est_case_occupee(conflits, c))
                    attron(COLOR_PAIR(3));
                
                else if(est_case_occupee(pos, c) && est_case_occupee(conflits, c))
                    attron(COLOR_PAIR(4));
            }
            else {
                attron(COLOR_PAIR(couleur + 1));
            }
            mvprintw(y, x, " ");
		}
	}
	refresh();
	
	attroff(COLOR_PAIR(couleur) | COLOR_PAIR(3) | COLOR_PAIR(4));
}

void affiche_grille (Position pos, Position conflits) {
	int i, j;
	
	for(j = 0; j < HAUTEUR ; j++)
		for( i = 0; i < LARGEUR; i++)
			affiche_dame(pos, i + (j * LARGEUR), (j + i) % 2, conflits);
}
