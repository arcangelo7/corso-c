/*
 * Esercizio 05: File binario con struct
 *
 * Crea un programma per gestire un archivio di studenti.
 * Struct Studente: nome[50], matricola, media
 *
 * Menu:
 * 1. Aggiungi studente (append al file)
 * 2. Mostra tutti gli studenti
 * 3. Cerca per matricola
 * 0. Esci
 *
 * Usa file binario "studenti.dat".
 *
 * Compilazione: gcc -Wall -o es05 es05_binario.c
 */

#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int matricola;
    double media;
} Studente;

// TODO: funzione per aggiungere studente
// void aggiungi_studente(const char *filename);

// TODO: funzione per mostrare tutti
// void mostra_tutti(const char *filename);

// TODO: funzione per cercare per matricola
// void cerca_matricola(const char *filename, int matricola);

int main(void) {
    const char *filename = "studenti.dat";
    int scelta;

    // TODO: implementa il menu

    return 0;
}
