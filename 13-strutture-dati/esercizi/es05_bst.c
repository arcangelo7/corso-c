/*
 * Esercizio 05: Albero binario di ricerca (BST)
 *
 * Implementa un BST con:
 * - inserisci
 * - cerca
 * - visita inorder (stampa ordinata)
 * - visita preorder
 * - visita postorder
 *
 * Test: inserisci 50, 30, 70, 20, 40, 60, 80
 *
 * Output atteso:
 * Inorder:   20 30 40 50 60 70 80
 * Preorder:  50 30 20 40 70 60 80
 * Postorder: 20 40 30 60 80 70 50
 *
 * Cerca 40: Trovato
 * Cerca 55: Non trovato
 *
 * Compilazione: gcc -Wall -o es05 es05_bst.c
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *sinistro;
    struct Nodo *destro;
} Nodo;

// TODO: implementa crea_nodo
// TODO: implementa inserisci
// TODO: implementa cerca
// TODO: implementa inorder (sinistro, radice, destro)
// TODO: implementa preorder (radice, sinistro, destro)
// TODO: implementa postorder (sinistro, destro, radice)
// TODO: implementa libera_albero

int main(void) {
    Nodo *radice = NULL;

    // TODO: inserisci 50, 30, 70, 20, 40, 60, 80
    // TODO: stampa le tre visite
    // TODO: cerca 40 e 55
    // TODO: libera memoria

    return 0;
}
