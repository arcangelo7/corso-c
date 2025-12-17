# Modulo 12 - Preprocessore

## Introduzione

Il preprocessore C elabora il codice sorgente prima della compilazione. Le direttive iniziano con `#`.

```
Sorgente -> Preprocessore -> Compilatore -> Linker -> Eseguibile
```

## #include

Include il contenuto di un altro file.

### Header standard

```c
#include <stdio.h>    // Cerca in directory di sistema
#include <stdlib.h>
#include <string.h>
```

### Header personalizzati

```c
#include "mioheader.h"  // Cerca prima nella directory corrente
```

### Cosa contengono gli header

- Prototipi di funzioni
- Definizioni di tipi (typedef, struct)
- Macro e costanti
- Dichiarazioni extern

## #define

### Costanti simboliche

```c
#define PI 3.14159
#define MAX_SIZE 100
#define NOME "Programma"

double area = PI * r * r;
int arr[MAX_SIZE];
```

### Macro senza parametri

```c
#define NEWLINE printf("\n")
#define DEBUG_ON

NEWLINE;  // Espande a: printf("\n");
```

### Macro con parametri

```c
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define QUADRATO(x) ((x) * (x))

int m = MAX(5, 3);        // Espande a: ((5) > (3) ? (5) : (3))
int q = QUADRATO(4);      // Espande a: ((4) * (4))
```

### Importanza delle parentesi

```c
// Sbagliato
#define QUADRATO_BAD(x) x * x
int r = QUADRATO_BAD(2 + 3);  // Espande a: 2 + 3 * 2 + 3 = 11

// Corretto
#define QUADRATO(x) ((x) * (x))
int r = QUADRATO(2 + 3);      // Espande a: ((2 + 3) * (2 + 3)) = 25
```

### Macro multiriga

```c
#define SWAP(a, b) do { \
    int temp = (a);     \
    (a) = (b);          \
    (b) = temp;         \
} while(0)

SWAP(x, y);
```

## #undef

Rimuove una definizione di macro.

```c
#define DEBUG 1
// ... codice con debug ...
#undef DEBUG
// ... codice senza debug ...
```

## Compilazione condizionale

### #ifdef / #ifndef

```c
#ifdef DEBUG
    printf("Debug: x = %d\n", x);
#endif

#ifndef MAX_SIZE
    #define MAX_SIZE 100
#endif
```

### #if / #elif / #else / #endif

```c
#define VERSION 2

#if VERSION == 1
    // Codice per versione 1
#elif VERSION == 2
    // Codice per versione 2
#else
    // Codice per altre versioni
#endif
```

### defined()

```c
#if defined(DEBUG) && defined(VERBOSE)
    printf("Debug verbose attivo\n");
#endif

#if !defined(NDEBUG)
    // Codice di debug
#endif
```

## Header guards

Prevengono l'inclusione multipla di un header.

```c
// file: mioheader.h
#ifndef MIOHEADER_H
#define MIOHEADER_H

// Contenuto dell'header
typedef struct {
    int x, y;
} Punto;

void funzione(void);

#endif // MIOHEADER_H
```

Alternativa moderna (non standard ma supportata):
```c
#pragma once

// Contenuto dell'header
```

## Macro predefinite

```c
__FILE__    // Nome file sorgente
__LINE__    // Numero riga corrente
__DATE__    // Data compilazione "Mmm dd yyyy"
__TIME__    // Ora compilazione "hh:mm:ss"
__func__    // Nome funzione corrente (C99)
```

### Esempio: debug

```c
#define DEBUG_LOG(msg) \
    printf("[%s:%d] %s\n", __FILE__, __LINE__, msg)

DEBUG_LOG("Entrato in funzione");
// Output: [main.c:42] Entrato in funzione
```

## Operatori # e ##

### # (Stringification)

Converte un argomento macro in stringa.

```c
#define TO_STRING(x) #x
#define PRINT_VAR(x) printf(#x " = %d\n", x)

printf("%s\n", TO_STRING(hello));  // Stampa: hello
int n = 42;
PRINT_VAR(n);  // Stampa: n = 42
```

### ## (Concatenazione)

Unisce due token.

```c
#define CONCAT(a, b) a##b
#define MAKE_VAR(n) var##n

int CONCAT(my, Var) = 10;   // int myVar = 10;
int MAKE_VAR(1) = 100;      // int var1 = 100;
```

## Organizzazione progetto multi-file

### Struttura tipica

```
progetto/
├── main.c
├── funzioni.c
├── funzioni.h
├── utils.c
└── utils.h
```

### Header file (funzioni.h)

```c
#ifndef FUNZIONI_H
#define FUNZIONI_H

// Prototipi
int somma(int a, int b);
int prodotto(int a, int b);

// Tipi
typedef struct {
    int x, y;
} Punto;

// Costanti
#define PI 3.14159

#endif
```

### Implementation file (funzioni.c)

```c
#include "funzioni.h"

int somma(int a, int b) {
    return a + b;
}

int prodotto(int a, int b) {
    return a * b;
}
```

### Main file (main.c)

```c
#include <stdio.h>
#include "funzioni.h"

int main(void) {
    printf("%d\n", somma(3, 4));
    return 0;
}
```

### Compilazione

```bash
# Compila separatamente
gcc -c main.c -o main.o
gcc -c funzioni.c -o funzioni.o

# Linka insieme
gcc main.o funzioni.o -o programma

# Oppure tutto insieme
gcc main.c funzioni.c -o programma
```

## #error e #warning

```c
#ifndef VERSION
    #error "VERSION non definita!"
#endif

#if VERSION < 2
    #warning "Versione obsoleta"
#endif
```

## #pragma

Direttive specifiche del compilatore.

```c
#pragma once           // Include guard (non standard)
#pragma pack(1)        // Rimuovi padding struct
#pragma warning(disable: 4996)  // Disabilita warning (MSVC)
```

## Esempio: configurazione build

```c
// config.h
#ifndef CONFIG_H
#define CONFIG_H

// Configurazione piattaforma
#ifdef _WIN32
    #define PLATFORM "Windows"
    #define PATH_SEP '\\'
#else
    #define PLATFORM "Unix"
    #define PATH_SEP '/'
#endif

// Configurazione debug
#ifdef DEBUG
    #define LOG(msg) printf("[DEBUG] %s\n", msg)
#else
    #define LOG(msg)  // Espande a nulla
#endif

// Configurazione versione
#define VERSION_MAJOR 1
#define VERSION_MINOR 0
#define VERSION_STR "1.0"

#endif
```

## Errori comuni

1. **Dimenticare parentesi nelle macro**
   ```c
   #define DOPPIO(x) x * 2
   int r = DOPPIO(1 + 2);  // 1 + 2 * 2 = 5, non 6!
   ```

2. **Effetti collaterali nelle macro**
   ```c
   #define MAX(a, b) ((a) > (b) ? (a) : (b))
   int m = MAX(i++, j);  // i++ valutato piu volte!
   ```

3. **Dimenticare header guard**
   ```c
   // Senza guard, errori di ridefinizione se incluso piu volte
   ```

4. **Include circolari**
   ```c
   // a.h include b.h, b.h include a.h -> errore
   ```

5. **Macro vs funzioni inline**
   ```c
   // Preferisci funzioni inline per type safety
   static inline int max(int a, int b) {
       return a > b ? a : b;
   }
   ```
