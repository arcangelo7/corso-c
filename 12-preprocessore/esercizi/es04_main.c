/*
 * Esercizio 04: Main che usa il modulo geometria
 *
 * Compila insieme a es04_geometria.c:
 * gcc -Wall -o es04 es04_main.c es04_geometria.c -lm
 *
 * Output atteso:
 * Distanza tra (0,0) e (3,4): 5.00
 * Area cerchio (r=2): 12.57
 * Perimetro cerchio (r=2): 12.57
 */

#include <stdio.h>
#include "es04_header.h"

int main(void) {
    Punto p1 = {0.0, 0.0};
    Punto p2 = {3.0, 4.0};

    printf("Distanza tra (0,0) e (3,4): %.2f\n", distanza(p1, p2));

    Cerchio c = {{0.0, 0.0}, 2.0};
    printf("Area cerchio (r=2): %.2f\n", area_cerchio(c));
    printf("Perimetro cerchio (r=2): %.2f\n", perimetro_cerchio(c));

    return 0;
}
