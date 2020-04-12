
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

    pos = (1L << t1);

    if (!est_case_occupee(pos, t1)) {
        fprintf(stderr, "ERREUR : est_case_occupee test 1\n");
        return 0;
    }

    pos = 0;

    if (est_case_occupee(pos, t2)) {
        fprintf(stderr, "ERREUR : est_case_occupee test 2\n");
        return 0;
    }

    pos = (1L << t2);

    if (!est_case_occupee(pos, t2)) {
        fprintf(stderr, "ERREUR : est_case_occupee test 2\n");
        return 0;
    }

    pos = 0;

    if (est_case_occupee(pos, t3)) {
        fprintf(stderr, "ERREUR : est_case_occupee test 3\n");
        return 0;
    }

    pos = (1L << t3);

    if (!est_case_occupee(pos, t3)) {
        fprintf(stderr, "ERREUR : est_case_occupee test 3\n");
        return 0;
    }

    return 1;
}

int test_placer_dame_position (void) {
    Case t1, t2, t3;
    Position pos;

    t1 = A1;

    t2 = H8;

    t3 = B2;

    pos = 0;

    if (placer_dame_position(&pos, t1)) {
        if ((pos & (1L << t1)) == 0L){
            fprintf(stderr, "ERREUR : placer_dame_position test 1\n");
            return 0;
        }
    }
    else {
        return 0;
    }

    pos = 0;

    if (placer_dame_position(&pos, t2)) {
        if ((pos & (1L << t2)) == 0){
            fprintf(stderr, "ERREUR : placer_dame_position test 2\n");
            return 0;
        }   
    }
    else {
        return 0;
    }

    pos = 0;

    if (placer_dame_position(&pos, t3)) {
        if ((pos & (1L << t3)) == 0){
            fprintf(stderr, "ERREUR : placer_dame_position test 3\n");
            return 0;
        } 
    }
    else {
        return 0;
    }

    pos = 0;

    if (placer_dame_position(&pos, t1) && placer_dame_position(&pos, t2)) {
        if ((pos & (1L << t1)) == 0 || (pos & (1L << t2)) == 0){
            fprintf(stderr, "ERREUR : placer_dame_position test 4\n");
            return 0;
        }
    }
    else {
        return 0;
    }

    pos = 0;

    if (placer_dame_position(&pos, t2) && placer_dame_position(&pos, t3)) {
        if ((pos & (1L << t2)) == 0 || (pos & (1L << t3)) == 0){
            fprintf(stderr, "ERREUR : placer_dame_position test 5\n");
            return 0;
        }   
    }
    else {
        return 0;
    }

    pos = 0;

    if (placer_dame_position(&pos, t3) && placer_dame_position(&pos, t1)) {
        if ((pos & (1L << t3)) == 0 || (pos & (1L << t1)) == 0){
            fprintf(stderr, "ERREUR : placer_dame_position test 6\n");
            return 0;
        } 
    }
    else {
        return 0;
    }

    pos = 0;

    if (placer_dame_position(&pos, t1) && !placer_dame_position(&pos, t1)) {
        if ((pos & (1L << t1)) == 0){
            fprintf(stderr, "ERREUR : placer_dame_position test 7\n");
            return 0;
        }
    }
    else {
        return 0;
    }

    pos = 0;

    if (placer_dame_position(&pos, t2) && !placer_dame_position(&pos, t2)) {
        if ((pos & (1L << t2)) == 0){
            fprintf(stderr, "ERREUR : placer_dame_position test 8\n");
            return 0;
        }   
    }
    else {
        return 0;
    }

    pos = 0;

    if (placer_dame_position(&pos, t3) && !placer_dame_position(&pos, t3)) {
        if ((pos & (1L << t3)) == 0){
            fprintf(stderr, "ERREUR : placer_dame_position test 9\n");
            return 0;
        } 
    }
    else {
        return 0;
    }


    return 1;
}

int test_est_sans_attaque_mutuelle(void) {
    Case t1, t2, t3;
    Position pos;

    t1 = A1;

    t2 = H8;

    t3 = B1;

    pos = 0;

    if (!est_sans_attaque_mutuelle(pos)) {
        fprintf(stderr, "ERREUR : placer_dame_position test 1\n");
        return 0;
    }

    if (placer_dame_position(&pos, t1)) {
        if (!est_sans_attaque_mutuelle(pos)) {
            fprintf(stderr, "ERREUR : placer_dame_position test 2\n");
            return 0;
        } 
    }
    else {
        return 0;
    }

    pos = 0;

    if (placer_dame_position(&pos, t2)) {
        if (!est_sans_attaque_mutuelle(pos)) {
            fprintf(stderr, "ERREUR : placer_dame_position test 3\n");
            return 0;
        } 
    }
    else {
        return 0;
    }

    pos = 0;

    if (placer_dame_position(&pos, t3)) {
        if (!est_sans_attaque_mutuelle(pos)) {
            fprintf(stderr, "ERREUR : placer_dame_position test 4\n");
            return 0;
        } 
    }
    else {
        return 0;
    }

    pos = 0;

    if (placer_dame_position(&pos, t1) && placer_dame_position(&pos, t2)) {
        if (est_sans_attaque_mutuelle(pos)) {
            fprintf(stderr, "ERREUR : placer_dame_position test 5\n");
            return 0;
        } 
    }
    else {
        return 0;
    }

    pos = 0;

    if (placer_dame_position(&pos, t1) && placer_dame_position(&pos, t3)) {
        if (est_sans_attaque_mutuelle(pos)) {
            fprintf(stderr, "ERREUR : placer_dame_position test 6\n");
            return 0;
        } 
    }
    else {
        return 0;
    }

    pos = 0;

    if (placer_dame_position(&pos, t2) && placer_dame_position(&pos, t3)) {
        if (!est_sans_attaque_mutuelle(pos)) {
            fprintf(stderr, "ERREUR : placer_dame_position test 7\n");
            return 0;
        } 
    }
    else {
        return 0;
    }

    pos = 0;

    if (placer_dame_position(&pos, t2) && placer_dame_position(&pos, t2) && placer_dame_position(&pos, t3)) {
        if (est_sans_attaque_mutuelle(pos)) {
            fprintf(stderr, "ERREUR : placer_dame_position test 8\n");
            return 0;
        } 
    }
    else {
        return 0;
    }

    return 1;
}

int test (void) {
    
    if (test_est_case_occupee() && test_placer_dame_position() && test_est_sans_attaque_mutuelle()) {
        return 1;
    }

    return 0;
}