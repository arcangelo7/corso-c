# Modulo 05 - Funzioni

## Introduzione

Una funzione e un blocco di codice riutilizzabile che esegue un compito specifico.

```c
tipo_ritorno nome_funzione(parametri) {
    // corpo della funzione
    return valore;
}
```

## Dichiarazione e definizione

### Definizione completa

```c
int somma(int a, int b) {
    return a + b;
}
```

### Dichiarazione (prototipo)

Il prototipo dichiara la funzione senza definirla. Necessario se la funzione e usata prima della sua definizione.

```c
// Prototipo
int somma(int a, int b);

int main(void) {
    int risultato = somma(3, 5);  // Usa la funzione
    return 0;
}

// Definizione
int somma(int a, int b) {
    return a + b;
}
```

I nomi dei parametri nel prototipo sono opzionali:
```c
int somma(int, int);  // Valido
```

## Parametri e argomenti

- **Parametri**: variabili nella dichiarazione della funzione
- **Argomenti**: valori passati alla chiamata

```c
int moltiplica(int x, int y) {  // x, y sono parametri
    return x * y;
}

int main(void) {
    int a = 5, b = 3;
    int r = moltiplica(a, b);  // a, b sono argomenti
    return 0;
}
```

### Passaggio per valore

In C, i parametri sono passati per valore: la funzione riceve una copia.

```c
void incrementa(int x) {
    x = x + 1;  // Modifica la copia
}

int main(void) {
    int n = 5;
    incrementa(n);
    printf("%d\n", n);  // Stampa 5, non 6!
    return 0;
}
```

## Valore di ritorno

### return

L'istruzione `return` termina la funzione e restituisce un valore.

```c
int valore_assoluto(int x) {
    if (x < 0) {
        return -x;
    }
    return x;
}
```

### Funzioni void

Le funzioni `void` non restituiscono nulla.

```c
void saluta(void) {
    printf("Ciao!\n");
    // return; e opzionale
}
```

## Scope delle variabili

### Variabili locali

Visibili solo dentro il blocco in cui sono dichiarate.

```c
void funzione(void) {
    int x = 10;  // Locale a funzione
    {
        int y = 20;  // Locale al blocco
        printf("%d %d\n", x, y);  // OK
    }
    // printf("%d\n", y);  // Errore: y non visibile
}
```

### Variabili globali

Dichiarate fuori da tutte le funzioni, visibili ovunque.

```c
int globale = 100;  // Variabile globale

void stampa(void) {
    printf("%d\n", globale);  // Accesso a globale
}

int main(void) {
    stampa();  // Stampa 100
    globale = 200;
    stampa();  // Stampa 200
    return 0;
}
```

Le variabili locali "nascondono" quelle globali con lo stesso nome:

```c
int x = 10;  // Globale

void funzione(void) {
    int x = 20;  // Locale, nasconde la globale
    printf("%d\n", x);  // Stampa 20
}
```

## static e extern

### static (variabili locali)

Una variabile `static` locale mantiene il valore tra le chiamate.

```c
void contatore(void) {
    static int count = 0;  // Inizializzata una volta sola
    count++;
    printf("Chiamata %d\n", count);
}

int main(void) {
    contatore();  // Chiamata 1
    contatore();  // Chiamata 2
    contatore();  // Chiamata 3
    return 0;
}
```

### static (funzioni)

Una funzione `static` e visibile solo nel file in cui e definita.

```c
static void funzione_privata(void) {
    // Visibile solo in questo file
}
```

### extern

Dichiara che una variabile o funzione e definita altrove.

```c
// file1.c
int variabile_condivisa = 100;

// file2.c
extern int variabile_condivisa;  // Usa variabile da file1.c
```

## Ricorsione

Una funzione che chiama se stessa.

### Fattoriale

```c
long fattoriale(int n) {
    if (n <= 1) {
        return 1;  // Caso base
    }
    return n * fattoriale(n - 1);  // Caso ricorsivo
}
```

Esecuzione di `fattoriale(4)`:
```
fattoriale(4)
= 4 * fattoriale(3)
= 4 * 3 * fattoriale(2)
= 4 * 3 * 2 * fattoriale(1)
= 4 * 3 * 2 * 1
= 24
```

### Fibonacci

```c
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

### Considerazioni sulla ricorsione

- Ogni funzione ricorsiva deve avere un **caso base**
- La ricorsione usa lo stack: troppi livelli causano stack overflow
- Spesso e meno efficiente dell'iterazione

## Funzioni con array

Gli array vengono sempre passati per riferimento (come puntatori).

```c
void stampa_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void raddoppia(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;  // Modifica l'array originale!
    }
}

int main(void) {
    int numeri[] = {1, 2, 3, 4, 5};
    int n = sizeof(numeri) / sizeof(numeri[0]);

    stampa_array(numeri, n);  // 1 2 3 4 5
    raddoppia(numeri, n);
    stampa_array(numeri, n);  // 2 4 6 8 10

    return 0;
}
```

## Funzioni nella libreria standard

### stdio.h

```c
printf(format, ...);  // Stampa formattata
scanf(format, ...);   // Input formattato
getchar();            // Legge un carattere
putchar(c);           // Stampa un carattere
```

### stdlib.h

```c
abs(n);       // Valore assoluto (int)
atoi(str);    // Stringa a intero
atof(str);    // Stringa a double
rand();       // Numero casuale
srand(seed);  // Inizializza generatore
```

### math.h

```c
sqrt(x);      // Radice quadrata
pow(x, y);    // x^y
sin(x);       // Seno
cos(x);       // Coseno
fabs(x);      // Valore assoluto (double)
ceil(x);      // Arrotonda verso l'alto
floor(x);     // Arrotonda verso il basso
```

Nota: compilare con `-lm` per math.h su Linux:
```bash
gcc programma.c -lm -o programma
```

## Errori comuni

1. **Dimenticare il prototipo**
   ```c
   int main(void) {
       int x = somma(1, 2);  // Warning: funzione non dichiarata
       return 0;
   }

   int somma(int a, int b) { return a + b; }
   ```

2. **Tipo di ritorno errato**
   ```c
   int divisione(int a, int b) {
       return a / b;  // Divisione intera!
   }
   // Se serve un double, usa double come tipo ritorno
   ```

3. **Aspettarsi modifica per valore**
   ```c
   void swap(int a, int b) {  // Non funziona!
       int temp = a;
       a = b;
       b = temp;
   }
   // Serve passaggio per puntatore (modulo 08)
   ```

4. **Ricorsione senza caso base**
   ```c
   int infinito(int n) {
       return infinito(n - 1);  // Mai termina -> stack overflow
   }
   ```
