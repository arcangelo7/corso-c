/*
 * Esercizio 04: Matrice dinamica
 *
 * Scrivi funzioni per:
 * - Allocare una matrice RxC dinamicamente
 * - Riempirla con valori
 * - Stamparla
 * - Liberare la memoria
 *
 * Prototipi:
 * int **crea_matrice(int righe, int colonne);
 * void riempi_matrice(int **mat, int righe, int colonne);
 * void stampa_matrice(int **mat, int righe, int colonne);
 * void libera_matrice(int **mat, int righe);
 *
 * Input esempio:
 * 3 4
 *
 * Output atteso (esempio con valori riga*10+colonna):
 *   0   1   2   3
 *  10  11  12  13
 *  20  21  22  23
 *
 * Compilazione: gcc -Wall -o es04 es04_matrice.c
 */

#include <stdio.h>
#include <stdlib.h>

// TODO: implementa le funzioni

int main(void) {
    int righe, colonne;

    printf("Righe e colonne: ");
    scanf("%d %d", &righe, &colonne);

    // TODO: crea matrice
    // TODO: riempi (mat[i][j] = i*10 + j)
    // TODO: stampa
    // TODO: libera

    return 0;
}
