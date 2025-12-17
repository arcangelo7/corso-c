/*
 * Esercizio 06: Puntatori a funzioni
 *
 * Scrivi un programma che:
 * 1. Definisce funzioni per le 4 operazioni (+, -, *, /)
 * 2. Usa un puntatore a funzione per scegliere l'operazione
 * 3. Chiede all'utente l'operazione e i numeri
 *
 * Prototipi:
 * double somma(double a, double b);
 * double sottrai(double a, double b);
 * double moltiplica(double a, double b);
 * double dividi(double a, double b);
 *
 * Input esempio:
 * +
 * 10
 * 3
 *
 * Output atteso: 10 + 3 = 13.00
 *
 * Compilazione: gcc -Wall -o es06 es06_funzione_ptr.c
 */

#include <stdio.h>

// TODO: implementa le 4 funzioni

int main(void) {
    double (*operazione)(double, double);

    // TODO: leggi operazione (+, -, *, /)
    // TODO: assegna la funzione corretta al puntatore
    // TODO: leggi i due numeri
    // TODO: esegui l'operazione tramite il puntatore

    return 0;
}
