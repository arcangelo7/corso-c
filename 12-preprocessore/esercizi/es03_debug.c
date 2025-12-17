/*
 * Esercizio 03: Compilazione condizionale per debug
 *
 * Crea un programma con macro di debug:
 * - Se DEBUG e definito, stampa messaggi di debug
 * - Se VERBOSE e definito, stampa messaggi extra
 *
 * Macro da implementare:
 * - DEBUG_LOG(msg) - stampa [DEBUG] msg se DEBUG definito
 * - VERBOSE_LOG(msg) - stampa [VERBOSE] msg se VERBOSE definito
 * - ASSERT(cond) - se DEBUG, verifica condizione
 *
 * Compila con:
 * gcc -DDEBUG es03_debug.c -o es03_debug
 * gcc -DDEBUG -DVERBOSE es03_debug.c -o es03_verbose
 * gcc es03_debug.c -o es03_release
 *
 * Compilazione: gcc -Wall -DDEBUG -o es03 es03_debug.c
 */

#include <stdio.h>
#include <stdlib.h>

// TODO: definisci DEBUG_LOG
// TODO: definisci VERBOSE_LOG
// TODO: definisci ASSERT

int somma(int a, int b) {
    DEBUG_LOG("Entrato in somma");
    VERBOSE_LOG("Calcolo somma di due numeri");
    ASSERT(a >= 0);
    ASSERT(b >= 0);
    return a + b;
}

int main(void) {
    DEBUG_LOG("Programma avviato");

    int risultato = somma(5, 3);
    printf("Risultato: %d\n", risultato);

    DEBUG_LOG("Programma terminato");
    return 0;
}
