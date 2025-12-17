/*
 * Esercizio 02: Swap con puntatori
 *
 * Scrivi una funzione che scambia i valori di due variabili
 * usando i puntatori.
 *
 * Prototipo: void swap(int *a, int *b);
 *
 * Input esempio:
 * 5
 * 10
 *
 * Output atteso:
 * Prima: x=5, y=10
 * Dopo:  x=10, y=5
 *
 * Compilazione: gcc -Wall -o es02 es02_swap.c
 */

#include <stdio.h>

// TODO: implementa swap

int main(void) {
    int x, y;

    printf("Inserisci x: ");
    scanf("%d", &x);
    printf("Inserisci y: ");
    scanf("%d", &y);

    // TODO: stampa prima dello swap
    // TODO: chiama swap
    // TODO: stampa dopo lo swap

    return 0;
}
