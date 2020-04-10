
#include "../include/Cases.h"

#include <assert.h>

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