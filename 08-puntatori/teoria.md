# Modulo 08 - Puntatori

## Introduzione

Un puntatore e una variabile che contiene l'indirizzo di memoria di un'altra variabile.

```c
int x = 10;
int *p = &x;  // p contiene l'indirizzo di x
```

## Dichiarazione

```c
tipo *nome_puntatore;

int *pi;       // Puntatore a int
double *pd;    // Puntatore a double
char *pc;      // Puntatore a char
```

## Operatori & e *

### & (address-of)

Restituisce l'indirizzo di una variabile.

```c
int x = 10;
int *p = &x;  // p = indirizzo di x

printf("Valore di x: %d\n", x);       // 10
printf("Indirizzo di x: %p\n", &x);   // es: 0x7ffd1234
printf("Valore di p: %p\n", p);       // stesso indirizzo
```

### * (dereference)

Accede al valore all'indirizzo contenuto nel puntatore.

```c
int x = 10;
int *p = &x;

printf("Valore puntato da p: %d\n", *p);  // 10

*p = 20;  // Modifica il valore di x attraverso p
printf("Nuovo valore di x: %d\n", x);  // 20
```

## Inizializzazione

### Puntatore valido

```c
int x = 10;
int *p = &x;  // Punta a x
```

### Puntatore NULL

```c
int *p = NULL;  // Non punta a nulla

if (p != NULL) {
    // Usa p solo se non e NULL
}
```

### Puntatore non inizializzato

```c
int *p;  // Valore indefinito - PERICOLOSO!
*p = 10; // Undefined behavior
```

## Puntatori e Funzioni

### Passaggio per riferimento

I puntatori permettono alle funzioni di modificare le variabili del chiamante.

```c
void incrementa(int *p) {
    (*p)++;  // Incrementa il valore puntato
}

int main(void) {
    int x = 10;
    incrementa(&x);
    printf("%d\n", x);  // 11
    return 0;
}
```

### Swap

```c
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int x = 5, y = 10;
    swap(&x, &y);
    printf("x=%d, y=%d\n", x, y);  // x=10, y=5
    return 0;
}
```

### Ritornare piu valori

```c
void divmod(int a, int b, int *quoziente, int *resto) {
    *quoziente = a / b;
    *resto = a % b;
}

int main(void) {
    int q, r;
    divmod(17, 5, &q, &r);
    printf("17/5 = %d resto %d\n", q, r);  // 3 resto 2
    return 0;
}
```

## Aritmetica dei Puntatori

I puntatori supportano operazioni aritmetiche che considerano la dimensione del tipo.

### Incremento/Decremento

```c
int arr[] = {10, 20, 30, 40, 50};
int *p = arr;  // Punta al primo elemento

printf("%d\n", *p);    // 10
p++;                   // Avanza di sizeof(int) byte
printf("%d\n", *p);    // 20
p += 2;                // Avanza di 2*sizeof(int)
printf("%d\n", *p);    // 40
```

### Sottrazione tra puntatori

```c
int arr[] = {10, 20, 30, 40, 50};
int *p1 = &arr[1];
int *p2 = &arr[4];

printf("%ld\n", p2 - p1);  // 3 (elementi tra p1 e p2)
```

### Confronto

```c
int arr[5];
int *p1 = &arr[2];
int *p2 = &arr[4];

if (p1 < p2) {
    printf("p1 precede p2\n");
}
```

## Puntatori e Array

Il nome di un array e un puntatore costante al primo elemento.

```c
int arr[] = {10, 20, 30, 40, 50};
int *p = arr;  // Equivalente a: int *p = &arr[0];

// Questi sono equivalenti:
arr[2]     // 30
*(arr + 2) // 30
p[2]       // 30
*(p + 2)   // 30
```

### Differenze

```c
int arr[5];
int *p = arr;

sizeof(arr)  // 20 (5 * sizeof(int))
sizeof(p)    // 8 (dimensione puntatore su 64-bit)

arr++;  // Errore! arr e costante
p++;    // OK
```

## Puntatori a Puntatori

```c
int x = 10;
int *p = &x;
int **pp = &p;  // Puntatore a puntatore

printf("%d\n", x);    // 10
printf("%d\n", *p);   // 10
printf("%d\n", **pp); // 10

**pp = 20;
printf("%d\n", x);    // 20
```

### Uso comune: array di stringhe

```c
char *args[] = {"prog", "-v", "file.txt"};
// args[0] = "prog", args[1] = "-v", args[2] = "file.txt"
```

## Puntatori a Funzioni

Un puntatore puo contenere l'indirizzo di una funzione.

### Dichiarazione

```c
int (*funzione_ptr)(int, int);  // Puntatore a funzione che prende 2 int e ritorna int
```

### Esempio

```c
int somma(int a, int b) {
    return a + b;
}

int prodotto(int a, int b) {
    return a * b;
}

int main(void) {
    int (*op)(int, int);  // Puntatore a funzione

    op = somma;
    printf("%d\n", op(3, 4));  // 7

    op = prodotto;
    printf("%d\n", op(3, 4));  // 12

    return 0;
}
```

### Callback

```c
void applica(int arr[], int n, int (*f)(int)) {
    for (int i = 0; i < n; i++) {
        arr[i] = f(arr[i]);
    }
}

int raddoppia(int x) {
    return x * 2;
}

int main(void) {
    int numeri[] = {1, 2, 3, 4, 5};
    applica(numeri, 5, raddoppia);
    // numeri = {2, 4, 6, 8, 10}
    return 0;
}
```

## const e Puntatori

### Puntatore a dato costante

```c
const int *p;  // Non puoi modificare *p
int x = 10;
p = &x;
*p = 20;  // Errore!
p = &y;   // OK
```

### Puntatore costante

```c
int * const p = &x;  // Non puoi modificare p
*p = 20;  // OK
p = &y;   // Errore!
```

### Entrambi costanti

```c
const int * const p = &x;
*p = 20;  // Errore!
p = &y;   // Errore!
```

## Puntatore void

Un puntatore generico che puo puntare a qualsiasi tipo.

```c
void *p;
int x = 10;
double d = 3.14;

p = &x;
printf("%d\n", *(int *)p);  // Cast necessario

p = &d;
printf("%f\n", *(double *)p);
```

Uso comune: funzioni generiche come `malloc`, `memcpy`.

## Errori Comuni

1. **Dereferenziare puntatore NULL**
   ```c
   int *p = NULL;
   *p = 10;  // Crash!
   ```

2. **Puntatore non inizializzato**
   ```c
   int *p;
   *p = 10;  // Undefined behavior
   ```

3. **Ritornare indirizzo di variabile locale**
   ```c
   int *funzione(void) {
       int x = 10;
       return &x;  // ERRORE! x non esiste piu dopo il return
   }
   ```

4. **Confondere * in dichiarazione e uso**
   ```c
   int *p = &x;  // * indica "puntatore a"
   *p = 10;      // * indica "dereferenzia"
   ```

5. **Aritmetica errata**
   ```c
   int *p = arr;
   p = p + sizeof(int);  // Sbagliato! Usa p + 1
   ```

## Riepilogo Sintassi

| Espressione | Significato |
|-------------|-------------|
| `int *p` | p e un puntatore a int |
| `&x` | Indirizzo di x |
| `*p` | Valore puntato da p |
| `p++` | Avanza p al prossimo elemento |
| `*p++` | Legge *p, poi incrementa p |
| `(*p)++` | Incrementa il valore puntato |
| `p[i]` | Equivale a *(p + i) |
