/*
 * Esercizio 03: Array espandibile con realloc
 *
 * Scrivi un programma che legge numeri dall'utente finche
 * non inserisce -1. L'array deve espandersi dinamicamente
 * usando realloc.
 *
 * Strategia: inizia con capacita 2, raddoppia quando pieno.
 *
 * Input esempio:
 * 5
 * 10
 * 15
 * 20
 * 25
 * -1
 *
 * Output atteso:
 * Numeri inseriti: 5 10 15 20 25
 * Totale: 5 numeri
 *
 * Compilazione: gcc -Wall -o es03 es03_realloc.c
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int capacita = 2;
    int dimensione = 0;
    int *arr = malloc(capacita * sizeof(int));

    if (arr == NULL) {
        printf("Errore allocazione\n");
        return 1;
    }

    // TODO: leggi numeri finche != -1
    // TODO: quando dimensione == capacita, usa realloc per raddoppiare
    // TODO: stampa i numeri inseriti
    // TODO: libera memoria

    return 0;
}
