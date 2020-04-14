
#include "../include/Position.h"

#include <assert.h>
#include <stdio.h>

int afficher_position (Position pos) {
    int j, i;

    for (j = HAUTEUR - 1; j >= 0; j--){
        for (i = 0; i < LARGEUR; i++) {

            if ((pos & (1L << (i + (LARGEUR * j)))) != 0) {
                printf("+");
            }
            else {
                printf(".");
            }

        }
        printf("\n");
    }

    return 1;
}
