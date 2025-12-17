# Corso di programmazione C

Corso completo di programmazione C, dalla sintassi base alle strutture dati avanzate.

## Prerequisiti

- Conoscenza base di programmazione (variabili, cicli, funzioni)
- Un compilatore C installato (gcc consigliato)
- Editor di testo o IDE

## Struttura del corso

| Modulo | Argomento | Descrizione |
|--------|-----------|-------------|
| 01 | Introduzione | Setup, compilazione, primo programma |
| 02 | Tipi e variabili | Tipi primitivi, modificatori, sizeof |
| 03 | Operatori | Aritmetici, logici, bitwise |
| 04 | Controllo flusso | if, switch, cicli |
| 05 | Funzioni | Parametri, scope, ricorsione |
| 06 | Array | Mono e multidimensionali |
| 07 | Stringhe | Manipolazione e string.h |
| 08 | Puntatori | Memoria, aritmetica puntatori |
| 09 | Struct e union | Tipi composti, typedef |
| 10 | Allocazione dinamica | malloc, free, gestione memoria |
| 11 | File I/O | Lettura/scrittura file |
| 12 | Preprocessore | Macro, compilazione condizionale |
| 13 | Strutture dati | Liste, stack, queue |

## Come usare il corso

Ogni modulo contiene:
- `teoria.md` - Spiegazioni con esempi di codice
- `esercizi/` - File .c con tracce da completare

### Compilazione

```bash
gcc -Wall -o programma nomefile.c
./programma
```

Flag consigliati:
- `-Wall` - Abilita tutti i warning
- `-Wextra` - Warning aggiuntivi
- `-std=c99` o `-std=c11` - Standard C specifico
- `-g` - Informazioni di debug