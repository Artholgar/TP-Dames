
#include "../include/Cases.h"

#include <assert.h>

int est_case_occupee (Position pos, Case c) {

    assert(c >= 0);
    assert(c <= 63);

    if ((pos & (1 << c)) != 0) {
        return 1;
    }

    return 0;
}