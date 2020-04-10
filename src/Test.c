
#include "../include/Test.h"

#include <stdio.h>

int test_est_case_occupee (void) {
    Case t1, t2, t3;
    Position pos;

    t1 = A1;

    t2 = H8;

    t3 = B2;

    pos = 0;

    if (est_case_occupee(pos, t1)) {
        fprintf(stderr, "ERREUR : est_case_occupee test 1\n");
        return 0;
    }

    pos = 1;

    if (!est_case_occupee(pos, t1)) {
        fprintf(stderr, "ERREUR : est_case_occupee test 1\n");
        return 0;
    }

    pos = 0;

    if (est_case_occupee(pos, t2)) {
        fprintf(stderr, "ERREUR : est_case_occupee test 2\n");
        return 0;
    }

    pos = (1L << 63);

    if (!est_case_occupee(pos, t2)) {
        fprintf(stderr, "ERREUR : est_case_occupee test 2\n");
        return 0;
    }

    pos = 0;

    if (est_case_occupee(pos, t3)) {
        fprintf(stderr, "ERREUR : est_case_occupee test 3\n");
        return 0;
    }

    pos = (1L << 9);

    if (!est_case_occupee(pos, t3)) {
        fprintf(stderr, "ERREUR : est_case_occupee test 3\n");
        return 0;
    }

    return 1;
}

int test (void) {
    
    if (test_est_case_occupee()) {
        return 1;
    }

    return 0;
}