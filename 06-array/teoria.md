# Modulo 06 - Array

## Introduzione

Un array e una collezione di elementi dello stesso tipo memorizzati in locazioni contigue.

```c
tipo nome[dimensione];
```

## Dichiarazione e inizializzazione

### Dichiarazione

```c
int numeri[5];      // Array di 5 interi (valori indefiniti)
double prezzi[10];  // Array di 10 double
char lettere[26];   // Array di 26 caratteri
```

### Inizializzazione

```c
int a[5] = {1, 2, 3, 4, 5};           // Inizializzazione completa
int b[5] = {1, 2};                     // b = {1, 2, 0, 0, 0}
int c[5] = {0};                        // Tutti zero
int d[] = {1, 2, 3, 4, 5};             // Dimensione dedotta (5)
```

### Accesso agli elementi

Gli indici partono da 0.

```c
int arr[5] = {10, 20, 30, 40, 50};

printf("%d\n", arr[0]);  // 10 (primo elemento)
printf("%d\n", arr[4]);  // 50 (ultimo elemento)

arr[2] = 100;            // Modifica il terzo elemento
printf("%d\n", arr[2]);  // 100
```

## Dimensione dell'array

```c
int arr[] = {1, 2, 3, 4, 5};
int dimensione = sizeof(arr) / sizeof(arr[0]);
printf("Elementi: %d\n", dimensione);  // 5
```

Nota: questo funziona solo se l'array e nello stesso scope. Non funziona con parametri di funzione.

## Iterare su un array

### Con for

```c
int arr[] = {10, 20, 30, 40, 50};
int n = sizeof(arr) / sizeof(arr[0]);

for (int i = 0; i < n; i++) {
    printf("arr[%d] = %d\n", i, arr[i]);
}
```

### Con while

```c
int i = 0;
while (i < n) {
    printf("%d ", arr[i]);
    i++;
}
```

## Array multidimensionali

### Matrici (2D)

```c
int matrice[3][4];  // 3 righe, 4 colonne

// Inizializzazione
int m[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};

// Accesso
printf("%d\n", m[0][0]);  // 1
printf("%d\n", m[1][2]);  // 6

// Modifica
m[0][1] = 100;
```

### Iterazione su matrice

```c
int mat[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        printf("%d ", mat[i][j]);
    }
    printf("\n");
}
```

Output:
```
1 2 3
4 5 6
7 8 9
```

### Array 3D e oltre

```c
int cubo[2][3][4];  // 2 x 3 x 4 elementi
cubo[0][1][2] = 42;
```

## Array e funzioni

### Passaggio di array

Gli array sono passati per riferimento (come puntatore al primo elemento).

```c
void stampa(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void azzera(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = 0;  // Modifica l'originale!
    }
}

int main(void) {
    int numeri[] = {1, 2, 3, 4, 5};
    int n = 5;

    stampa(numeri, n);  // 1 2 3 4 5
    azzera(numeri, n);
    stampa(numeri, n);  // 0 0 0 0 0

    return 0;
}
```

### Passaggio di matrici

Per le matrici, devi specificare le dimensioni eccetto la prima.

```c
void stampa_matrice(int mat[][3], int righe) {
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
```

## Operazioni comuni

### Somma elementi

```c
int somma(int arr[], int n) {
    int tot = 0;
    for (int i = 0; i < n; i++) {
        tot += arr[i];
    }
    return tot;
}
```

### Ricerca lineare

```c
int cerca(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;  // Indice trovato
        }
    }
    return -1;  // Non trovato
}
```

### Massimo e minimo

```c
int massimo(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int minimo(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}
```

### Inversione

```c
void inverti(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}
```

### Ordinamento (Bubble Sort)

```c
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
```

## Array e indirizzi

Il nome di un array e l'indirizzo del suo primo elemento.

```c
int arr[] = {10, 20, 30};

printf("%p\n", arr);      // Indirizzo di arr[0]
printf("%p\n", &arr[0]);  // Stesso indirizzo

// Gli elementi sono contigui in memoria
printf("%p\n", &arr[0]);  // es: 0x100
printf("%p\n", &arr[1]);  // es: 0x104 (+ sizeof(int))
printf("%p\n", &arr[2]);  // es: 0x108 (+ 2*sizeof(int))
```

## Errori comuni

1. **Accesso fuori dai limiti**
   ```c
   int arr[5];
   arr[5] = 10;  // Errore! Indici validi: 0-4
   arr[-1] = 5;  // Errore! Indice negativo
   ```

2. **Array non inizializzato**
   ```c
   int arr[5];
   printf("%d\n", arr[0]);  // Valore indefinito!
   ```

3. **sizeof con parametro funzione**
   ```c
   void func(int arr[]) {
       int n = sizeof(arr) / sizeof(arr[0]);  // Sbagliato!
       // arr e un puntatore, non un array
   }
   ```

4. **Assegnamento tra array**
   ```c
   int a[] = {1, 2, 3};
   int b[3];
   b = a;  // Errore! Non si possono assegnare array
   // Usa un ciclo o memcpy
   ```

5. **Confronto tra array**
   ```c
   int a[] = {1, 2, 3};
   int b[] = {1, 2, 3};
   if (a == b) { }  // Confronta indirizzi, non contenuto!
   // Usa un ciclo o memcmp
   ```
