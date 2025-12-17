/*
 * Esercizio 02: Macro con parametri
 *
 * Definisci le seguenti macro:
 * - MAX(a, b) - restituisce il massimo
 * - MIN(a, b) - restituisce il minimo
 * - ABS(x) - valore assoluto
 * - QUADRATO(x) - quadrato di x
 * - CUBO(x) - cubo di x
 *
 * Ricorda di usare le parentesi correttamente!
 *
 * Test:
 * MAX(5, 3) = 5
 * MIN(5, 3) = 3
 * ABS(-7) = 7
 * QUADRATO(4) = 16
 * CUBO(3) = 27
 * QUADRATO(2+1) = 9 (verifica parentesi!)
 *
 * Compilazione: gcc -Wall -o es02 es02_macro.c
 */

#include <stdio.h>

// TODO: definisci le macro

int main(void) {
    // TODO: testa le macro

    printf("MAX(5, 3) = %d\n", MAX(5, 3));
    printf("MIN(5, 3) = %d\n", MIN(5, 3));
    printf("ABS(-7) = %d\n", ABS(-7));
    printf("QUADRATO(4) = %d\n", QUADRATO(4));
    printf("CUBO(3) = %d\n", CUBO(3));
    printf("QUADRATO(2+1) = %d\n", QUADRATO(2+1));

    return 0;
}
