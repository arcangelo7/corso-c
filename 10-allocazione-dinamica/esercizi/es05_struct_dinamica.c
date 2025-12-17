/*
 * Esercizio 05: Array di struct dinamico
 *
 * Gestisci un elenco dinamico di prodotti con:
 * - nome (stringa dinamica)
 * - prezzo
 *
 * Funzioni:
 * - Aggiungere un prodotto
 * - Stampare tutti i prodotti
 * - Liberare tutta la memoria
 *
 * Input esempio:
 * 3
 * Mela 1.50
 * Pane 2.00
 * Latte 1.80
 *
 * Output atteso:
 * Prodotti:
 * 1. Mela: 1.50 euro
 * 2. Pane: 2.00 euro
 * 3. Latte: 1.80 euro
 * Totale: 5.30 euro
 *
 * Compilazione: gcc -Wall -o es05 es05_struct_dinamica.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nome;    // Allocato dinamicamente
    double prezzo;
} Prodotto;

// TODO: funzione per creare un prodotto
// Prodotto *crea_prodotto(const char *nome, double prezzo);

// TODO: funzione per liberare un prodotto
// void libera_prodotto(Prodotto *p);

int main(void) {
    int n;
    printf("Quanti prodotti? ");
    scanf("%d", &n);

    // TODO: alloca array di Prodotto
    // TODO: leggi e crea ogni prodotto
    // TODO: stampa tutti i prodotti e il totale
    // TODO: libera tutta la memoria

    return 0;
}
