
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
	
	init_pair(1, COLOR_WHITE, COLOR_BLUE);
	init_pair(2, COLOR_WHITE, COLOR_CYAN);
    init_pair(3, COLOR_WHITE, COLOR_GREEN);
	init_pair(4, COLOR_WHITE, COLOR_RED);
	init_pair(5, COLOR_WHITE, COLOR_WHITE);
}

void affiche_dame (Position pos, Case c, int couleur, Position conflits, Case courante) {
	int x, y;
	int n, m;
	int ordonnee, abscisse;

	n = 0;

	ordonnee = HAUTEUR_C * (((c / LARGEUR) * - 1) + 7);
	abscisse = LARGEUR_C * (c % LARGEUR);
	
	attron(COLOR_PAIR(couleur));

	if (c == courante) {
		attron(COLOR_PAIR(5));
	}
	
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
				if (c == courante) {
					attron(COLOR_PAIR(5));
				}
            }
            mvprintw(y, x, " ");
		}
	}

	refresh();
	
	attroff(COLOR_PAIR(couleur) | COLOR_PAIR(3) | COLOR_PAIR(4) | COLOR_PAIR(5));
}

void affiche_grille (Position pos, Position conflits, Case courante) {
	int i, j;
	
	for(j = 0; j < HAUTEUR; j++)
		for(i = 0; i < LARGEUR; i++)
			affiche_dame(pos, i + (j * LARGEUR), (j + i) % 2, conflits, courante);
}
