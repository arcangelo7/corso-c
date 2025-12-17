# Modulo 10 - Allocazione Dinamica della Memoria

## Introduzione

L'allocazione dinamica permette di allocare memoria durante l'esecuzione del programma, invece che a tempo di compilazione.

Le funzioni sono in `<stdlib.h>`.

## Stack vs Heap

### Stack
- Memoria per variabili locali e parametri funzione
- Allocazione/deallocazione automatica
- Dimensione limitata
- Accesso veloce

### Heap
- Memoria per allocazione dinamica
- Gestione manuale (malloc/free)
- Dimensione maggiore
- Persiste finche non liberata

## malloc

Alloca un blocco di memoria non inizializzata.

```c
void *malloc(size_t size);
```

```c
int *p = malloc(sizeof(int));        // Un intero
int *arr = malloc(10 * sizeof(int)); // Array di 10 interi

if (p == NULL) {
    // Gestisci errore: memoria non disponibile
}
```

### Esempio

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Quanti elementi? ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Errore allocazione\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = i * 10;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}
```

## calloc

Alloca memoria inizializzata a zero.

```c
void *calloc(size_t num, size_t size);
```

```c
int *arr = calloc(10, sizeof(int));  // 10 interi, tutti a 0
```

Differenze da malloc:
- Prende due parametri (numero elementi, dimensione elemento)
- Inizializza a zero
- Leggermente piu lento

## realloc

Ridimensiona un blocco di memoria esistente.

```c
void *realloc(void *ptr, size_t new_size);
```

```c
int *arr = malloc(5 * sizeof(int));
// ... usa arr ...

// Espandi a 10 elementi
int *temp = realloc(arr, 10 * sizeof(int));
if (temp == NULL) {
    // Errore, arr e ancora valido
    free(arr);
    return 1;
}
arr = temp;
```

Comportamenti:
- Se `ptr` e NULL, equivale a malloc
- Se `new_size` e 0, equivale a free (comportamento deprecato)
- Puo spostare i dati in una nuova locazione
- I dati esistenti sono preservati

## free

Libera memoria allocata dinamicamente.

```c
void free(void *ptr);
```

```c
int *p = malloc(sizeof(int));
// ... usa p ...
free(p);
p = NULL;  // Buona pratica
```

Regole:
- Chiamare free solo su memoria allocata con malloc/calloc/realloc
- Non chiamare free due volte sullo stesso puntatore
- free(NULL) e sicuro (non fa nulla)

## Memory Leak

Un memory leak si verifica quando memoria allocata non viene mai liberata.

```c
void funzione(void) {
    int *p = malloc(100 * sizeof(int));
    // ... usa p ...
    // Dimentica free(p) -> memory leak!
}
```

### Prevenzione

```c
// Liberare sempre prima di uscire
int *p = malloc(100);
if (condizione_errore) {
    free(p);  // Non dimenticare!
    return -1;
}
// ... usa p ...
free(p);
```

## Dangling Pointer

Un puntatore che punta a memoria gia liberata.

```c
int *p = malloc(sizeof(int));
free(p);
*p = 10;  // ERRORE! p e un dangling pointer
```

### Prevenzione

```c
free(p);
p = NULL;  // Rende il puntatore sicuro

if (p != NULL) {
    // Ora puoi verificare se e valido
}
```

## Double Free

Liberare la stessa memoria due volte causa undefined behavior.

```c
int *p = malloc(sizeof(int));
free(p);
free(p);  // ERRORE! Double free
```

## Array Dinamici

### Array 1D

```c
int *arr = malloc(n * sizeof(int));
// Usa come array normale
arr[0] = 10;
arr[n-1] = 20;
free(arr);
```

### Array 2D (array di puntatori)

```c
int **mat = malloc(righe * sizeof(int *));
for (int i = 0; i < righe; i++) {
    mat[i] = malloc(colonne * sizeof(int));
}

// Uso
mat[0][0] = 1;
mat[righe-1][colonne-1] = 99;

// Liberazione (ordine inverso!)
for (int i = 0; i < righe; i++) {
    free(mat[i]);
}
free(mat);
```

### Array 2D contiguo

```c
int *mat = malloc(righe * colonne * sizeof(int));

// Accesso: mat[i * colonne + j]
mat[0 * colonne + 0] = 1;   // mat[0][0]
mat[2 * colonne + 3] = 99;  // mat[2][3]

free(mat);
```

## Struct Dinamiche

```c
typedef struct {
    char nome[50];
    int eta;
} Persona;

Persona *p = malloc(sizeof(Persona));
if (p == NULL) {
    return 1;
}

strcpy(p->nome, "Mario");
p->eta = 30;

printf("%s ha %d anni\n", p->nome, p->eta);

free(p);
```

### Array di struct

```c
Persona *team = malloc(n * sizeof(Persona));

for (int i = 0; i < n; i++) {
    sprintf(team[i].nome, "Persona%d", i);
    team[i].eta = 20 + i;
}

free(team);
```

## Struct con Membri Dinamici

```c
typedef struct {
    char *nome;  // Puntatore, non array
    int eta;
} Persona;

Persona *crea_persona(const char *nome, int eta) {
    Persona *p = malloc(sizeof(Persona));
    if (p == NULL) return NULL;

    p->nome = malloc(strlen(nome) + 1);
    if (p->nome == NULL) {
        free(p);
        return NULL;
    }

    strcpy(p->nome, nome);
    p->eta = eta;
    return p;
}

void distruggi_persona(Persona *p) {
    if (p != NULL) {
        free(p->nome);  // Prima i membri
        free(p);        // Poi la struct
    }
}
```

## Pattern: Array Dinamico Ridimensionabile

```c
typedef struct {
    int *dati;
    int dimensione;
    int capacita;
} ArrayDinamico;

void init(ArrayDinamico *a) {
    a->capacita = 4;
    a->dimensione = 0;
    a->dati = malloc(a->capacita * sizeof(int));
}

void aggiungi(ArrayDinamico *a, int valore) {
    if (a->dimensione == a->capacita) {
        a->capacita *= 2;
        a->dati = realloc(a->dati, a->capacita * sizeof(int));
    }
    a->dati[a->dimensione++] = valore;
}

void distruggi(ArrayDinamico *a) {
    free(a->dati);
    a->dati = NULL;
    a->dimensione = a->capacita = 0;
}
```

## Errori Comuni

1. **Non controllare il ritorno di malloc**
   ```c
   int *p = malloc(1000000000);
   *p = 10;  // Crash se malloc fallisce
   ```

2. **sizeof errato**
   ```c
   int *arr = malloc(10);  // Solo 10 byte, non 10 int!
   int *arr = malloc(10 * sizeof(int));  // Corretto
   ```

3. **Perdere il puntatore originale**
   ```c
   int *p = malloc(100);
   p = p + 1;  // Hai perso l'inizio!
   free(p);    // Errore!
   ```

4. **Usare memoria dopo free**
   ```c
   free(p);
   printf("%d", *p);  // Undefined behavior
   ```

5. **Non liberare in caso di errore**
   ```c
   int *a = malloc(100);
   int *b = malloc(100);  // Se fallisce, a non viene liberato
   ```

## Strumenti di Debug

### Valgrind (Linux)

```bash
valgrind --leak-check=full ./programma
```

Rileva:
- Memory leak
- Accessi invalidi
- Double free
- Uso di memoria non inizializzata
