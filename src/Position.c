
#include "../include/Position.h"

#include <assert.h>
#include <stdio.h>

int afficher_position (Position pos) {
    int i;

    for (i = 0; i < LARGEUR * HAUTEUR; i++) {
        if ((i % 8) == 0 && i != 0) {
            printf("\n");
        }

        if ((pos & (1L << i)) != 0) {
            printf("+");
        }
        else {
            printf(".");
        }
    }

    if ((i % 8) == 0 && i != 0) {
        printf("\n");
    }

    return 1;
}
