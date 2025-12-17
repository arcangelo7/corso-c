/*
 * Esercizio 02: Lista ordinata
 *
 * Implementa una lista che mantiene i numeri ordinati.
 * Funzione: inserisci_ordinato(Nodo **testa, int valore)
 *
 * Test: inserisci 30, 10, 50, 20, 40
 *
 * Output atteso:
 * Lista ordinata: 10 -> 20 -> 30 -> 40 -> 50 -> NULL
 *
 * Compilazione: gcc -Wall -o es02 es02_lista_ord.c
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *next;
} Nodo;

// TODO: implementa inserisci_ordinato
// Il nodo va inserito nella posizione corretta per mantenere l'ordine

int main(void) {
    Nodo *lista = NULL;

    // TODO: inserisci 30, 10, 50, 20, 40
    // TODO: stampa lista
    // TODO: libera memoria

    return 0;
}
