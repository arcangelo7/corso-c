/*
 * Esercizio 04: Queue con lista concatenata
 *
 * Implementa una coda con lista concatenata:
 * - enqueue (inserisci in coda)
 * - dequeue (rimuovi dalla testa)
 * - is_empty
 *
 * Test: enqueue 1, 2, 3, poi dequeue due elementi, poi enqueue 4.
 *
 * Output atteso:
 * Enqueue: 1, 2, 3
 * Dequeue: 1
 * Dequeue: 2
 * Enqueue: 4
 * Coda: 3 -> 4 -> NULL
 *
 * Compilazione: gcc -Wall -o es04 es04_queue.c
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *next;
} Nodo;

typedef struct {
    Nodo *front;
    Nodo *rear;
} Queue;

// TODO: implementa init_queue
// TODO: implementa is_empty
// TODO: implementa enqueue
// TODO: implementa dequeue
// TODO: implementa stampa_queue
// TODO: implementa libera_queue

int main(void) {
    Queue q;

    // TODO: inizializza
    // TODO: enqueue 1, 2, 3
    // TODO: dequeue due volte e stampa
    // TODO: enqueue 4
    // TODO: stampa coda
    // TODO: libera memoria

    return 0;
}
