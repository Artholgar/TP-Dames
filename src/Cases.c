
#include "../include/Cases.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int est_case_occupee (Position pos, Case c) {

    assert(c >= 0);
    assert(c <= 63);

    if ((pos & (1L << c)) != 0) {
        return 1;
    }

    return 0;
}

int placer_dame_position (Position * pos, Case c) {

    assert(c >= 0);
    assert(c <= 63);

    if (est_case_occupee((*pos), c)) {
        return 0;
    }

    (*pos) += (1L << c);

    return 1;
}

int calculer_cases_attaquees (Position *pos, Case c) {
    int j, i;

    assert(c >= 0);
    assert(c <= 63);

    for (j = 0; j < HAUTEUR; j++) {
        for (i = 0; i < LARGEUR; i++) {
            if ((i + (j * LARGEUR)) == c){
                continue;
            }
            else if (j == (c / LARGEUR)) {
                if (!placer_dame_position(pos, (i + (j * LARGEUR)))) {
                    return 0;
                }
            }
            else if (i == (c % LARGEUR)) {
                if (!placer_dame_position(pos, (i + (j * LARGEUR)))) {
                    return 0;
                }
            }
            else if ((i + j) == (c % LARGEUR) + (c / LARGEUR)) {
                if (!placer_dame_position(pos, (i + (j * LARGEUR)))) {
                    return 0;
                }
            }
            else if (i - j == (c % LARGEUR) - (c / LARGEUR)) {
                if (!placer_dame_position(pos, (i + (j * LARGEUR)))) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int init_tab_cases_attaquees (void) {
    int i;

    for (i = 0; i < LARGEUR * HAUTEUR; i++) {
        if (!calculer_cases_attaquees(&(tab_cases_attaquees[i]), i)) {
            return 0;
        }
    }

    return 1;
}

Position est_sans_attaque_mutuelle (Position pos) {
    int j, i;
    Position res;

    res = 0L;

    for (j = 0; j < HAUTEUR; j++) {
        for (i = 0; i < LARGEUR; i++) {
            if (est_case_occupee(pos, (i + (j * LARGEUR)))) {
                res = (pos & tab_cases_attaquees[(i + (j * 8))]) | res;
            }
        }
    }

    return res;
}