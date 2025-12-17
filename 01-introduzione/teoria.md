# Modulo 01 - Introduzione al C

## Storia e caratteristiche

Il C e stato creato da Dennis Ritchie nei Bell Labs tra il 1969 e il 1973. E un linguaggio:

- **Compilato**: il codice sorgente viene tradotto in codice macchina
- **Imperativo**: descrive sequenze di istruzioni
- **Di basso livello**: accesso diretto alla memoria
- **Portabile**: lo stesso codice compila su diverse piattaforme

### Imperativo vs dichiarativo

Un linguaggio **imperativo** descrive *come* eseguire un compito, passo dopo passo. Il programmatore specifica la sequenza esatta di operazioni.

Un linguaggio **dichiarativo** descrive *cosa* si vuole ottenere, senza specificare i passaggi. Il sistema decide come raggiungere il risultato.

**Esempio: somma dei numeri da 1 a 10**

In C (imperativo) dobbiamo specificare ogni passo:
```c
int somma = 0;
for (int i = 1; i <= 10; i++) {
    somma = somma + i;
}
// somma = 55
```

In SQL (dichiarativo) diciamo solo cosa vogliamo:
```sql
SELECT SUM(n) FROM numeri WHERE n BETWEEN 1 AND 10;
```

Il C e imperativo perche richiede di specificare:
- L'inizializzazione delle variabili
- Il ciclo con condizione e incremento
- L'operazione di accumulo ad ogni iterazione

Il compilatore esegue esattamente le istruzioni scritte, nell'ordine specificato.

## Setup ambiente

### Installazione GCC

**Linux (Debian/Ubuntu)**:
```bash
sudo apt install build-essential
```

**Linux (Arch)**:
```bash
sudo pacman -S gcc
```

**macOS**:
```bash
xcode-select --install
```

**Windows**: Installare MinGW o usare WSL.

### Verifica installazione

```bash
gcc --version
```

## Struttura di un programma C

```c
#include <stdio.h>    // Direttiva preprocessore: include libreria standard I/O

int main(void) {      // Funzione principale, punto di ingresso
    // Corpo del programma
    return 0;         // Valore di ritorno (0 = successo)
}
```

### Elementi principali

| Elemento | Descrizione |
|----------|-------------|
| `#include` | Inclusione di header file |
| `int main(void)` | Funzione principale |
| `{ }` | Delimitatori di blocco |
| `return 0` | Valore di ritorno al sistema operativo |
| `;` | Terminatore di istruzione |

## Hello World

```c
#include <stdio.h>

int main(void) {
    printf("Hello, World!\n");
    return 0;
}
```

### printf

La funzione `printf` stampa testo formattato su stdout.

```c
printf("Testo semplice\n");           // Stringa letterale
printf("Numero: %d\n", 42);           // Intero
printf("Decimale: %f\n", 3.14);       // Float/double
printf("Carattere: %c\n", 'A');       // Carattere
```

Sequenze di escape comuni:
- `\n` - newline
- `\t` - tab
- `\\` - backslash
- `\"` - virgolette

## Compilazione ed esecuzione

### Processo di compilazione

```
Sorgente (.c) -> Preprocessore -> Compilatore -> Assembler -> Linker -> Eseguibile
```

### Comandi base

```bash
# Compilazione semplice
gcc programma.c -o programma

# Compilazione con warning
gcc -Wall -Wextra programma.c -o programma

# Esecuzione
./programma
```

### Flag utili

| Flag | Descrizione |
|------|-------------|
| `-o nome` | Specifica nome output |
| `-Wall` | Abilita warning comuni |
| `-Wextra` | Warning aggiuntivi |
| `-Werror` | Tratta warning come errori |
| `-g` | Informazioni di debug |
| `-std=c99` | Usa standard C99 |
| `-std=c11` | Usa standard C11 |

## Commenti

```c
// Commento su singola riga (C99+)

/*
   Commento
   su piu righe
*/
```

## Errori comuni

1. **Dimenticare il punto e virgola**
   ```c
   printf("Hello")   // Errore: manca ;
   printf("Hello");  // Corretto
   ```

2. **Dimenticare #include**
   ```c
   int main(void) {
       printf("Test");  // Errore: printf non dichiarato
       return 0;
   }
   ```

3. **main senza return**
   ```c
   int main(void) {
       printf("Test");
       // Warning: manca return
   }
   ```
