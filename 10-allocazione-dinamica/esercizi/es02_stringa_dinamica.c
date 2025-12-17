/*
 * Esercizio 02: Stringa dinamica
 *
 * Scrivi una funzione che duplica una stringa allocando nuova memoria.
 *
 * Prototipo: char *mia_strdup(const char *s);
 *
 * La funzione deve:
 * 1. Calcolare la lunghezza della stringa
 * 2. Allocare memoria sufficiente (lunghezza + 1 per '\0')
 * 3. Copiare la stringa
 * 4. Restituire il puntatore (o NULL se malloc fallisce)
 *
 * Test:
 * originale = "Hello World"
 * copia = mia_strdup(originale)
 *
 * Output atteso:
 * Originale: Hello World
 * Copia: Hello World
 *
 * Compilazione: gcc -Wall -o es02 es02_stringa_dinamica.c
 */
