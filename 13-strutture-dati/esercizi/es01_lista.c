/*
 * Esercizio 01: Lista concatenata base
 *
 * Implementa una lista concatenata con le seguenti operazioni:
 * - inserisci_testa
 * - inserisci_coda
 * - stampa_lista
 * - libera_lista
 *
 * Test: inserisci 5, 10, 15 in coda, poi 1 in testa.
 *
 * Output atteso:
 * Lista: 1 -> 5 -> 10 -> 15 -> NULL
 * Lunghezza: 4
 *
 * Compilazione: gcc -Wall -o es01 es01_lista.c
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *next;
} Nodo;

// TODO: implementa crea_nodo
// TODO: implementa inserisci_testa
// TODO: implementa inserisci_coda
// TODO: implementa stampa_lista
// TODO: implementa lunghezza_lista
// TODO: implementa libera_lista

int main(void) {
    Nodo *lista = NULL;

    // TODO: inserisci 5, 10, 15 in coda
    // TODO: inserisci 1 in testa
    // TODO: stampa lista e lunghezza
    // TODO: libera memoria

    return 0;
}
