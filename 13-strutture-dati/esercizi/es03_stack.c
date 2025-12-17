/*
 * Esercizio 03: Stack con array
 *
 * Implementa uno stack con le operazioni:
 * - push
 * - pop
 * - peek
 * - is_empty
 * - is_full
 *
 * Test: push 10, 20, 30, poi pop due elementi.
 *
 * Output atteso:
 * Push: 10, 20, 30
 * Peek: 30
 * Pop: 30
 * Pop: 20
 * Peek: 10
 *
 * Compilazione: gcc -Wall -o es03 es03_stack.c
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int dati[MAX_SIZE];
    int top;
} Stack;

// TODO: implementa init_stack
// TODO: implementa is_empty
// TODO: implementa is_full
// TODO: implementa push
// TODO: implementa pop
// TODO: implementa peek

int main(void) {
    Stack s;

    // TODO: inizializza stack
    // TODO: push 10, 20, 30
    // TODO: peek e stampa
    // TODO: pop e stampa due volte
    // TODO: peek e stampa

    return 0;
}
