/*
 * Esercizio 08: Puntatori a puntatori
 *
 * Scrivi un programma che dimostra l'uso di puntatori a puntatori.
 *
 * 1. Dichiara int x = 10, int *p = &x, int **pp = &p
 * 2. Modifica x attraverso pp
 * 3. Stampa tutti i valori e gli indirizzi
 *
 * Output atteso (indirizzi variano):
 * x = 10
 * *p = 10
 * **pp = 10
 *
 * Indirizzi:
 * &x = 0x...
 * p = 0x...
 * &p = 0x...
 * pp = 0x...
 *
 * Dopo **pp = 100:
 * x = 100
 *
 * Compilazione: gcc -Wall -o es08 es08_doppio_ptr.c
 */
