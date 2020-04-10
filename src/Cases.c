
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

    if (((*pos) & (1L << c)) != 0) {
        return 0;
    }

    (*pos) += (1L << c);

    return 1;
}

int calculer_cases_attaquees (Position *pos, Case c) {
    int j, i;

    assert(c >= 0);
    assert(c <= 63);

    for (j = 0; j < 8; j++) {
        for (i = 0; i < 8; i++) {
            if ((i + (j * 8)) == c){
                ;
            }
            else if (j == (c / 8)) {
                placer_dame_position(pos, (i + (j * 8)));
            }
            else if (i == (c % 8)) {
                placer_dame_position(pos, (i + (j * 8)));
            }
            else if ((i + j) == (c % 8) + (c / 8)) {
                placer_dame_position(pos, (i + (j * 8)));
            }
            else if (i - j == (c % 8) - (c / 8)) {
                placer_dame_position(pos, (i + (j * 8)));
            }
        }
    }
    return 1;


}