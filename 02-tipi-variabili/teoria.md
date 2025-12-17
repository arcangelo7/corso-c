# Modulo 02 - Tipi di Dati e Variabili

## Variabili

Una variabile e una locazione di memoria con un nome. In C bisogna dichiarare il tipo prima dell'uso.

```c
tipo nome_variabile;           // Dichiarazione
tipo nome_variabile = valore;  // Dichiarazione con inizializzazione
```

### Regole per i nomi

- Iniziano con lettera o underscore
- Contengono lettere, numeri, underscore
- Case-sensitive (`count` != `Count`)
- Non usare parole riservate (`int`, `if`, `while`, ecc.)

## Tipi Primitivi

### Tipi interi

| Tipo | Dimensione tipica | Range tipico |
|------|-------------------|--------------|
| `char` | 1 byte | -128 a 127 |
| `short` | 2 byte | -32768 a 32767 |
| `int` | 4 byte | -2^31 a 2^31-1 |
| `long` | 4-8 byte | dipende dalla piattaforma |
| `long long` | 8 byte | -2^63 a 2^63-1 |

### Tipi floating point

| Tipo | Dimensione | Precisione |
|------|------------|------------|
| `float` | 4 byte | ~7 cifre decimali |
| `double` | 8 byte | ~15 cifre decimali |
| `long double` | 8-16 byte | ~19+ cifre decimali |

### Tipo char

Il tipo `char` rappresenta un singolo carattere ASCII.

```c
char lettera = 'A';        // Carattere letterale
char newline = '\n';       // Sequenza di escape
char numero = 65;          // Codice ASCII (= 'A')
```

## Modificatori

### signed e unsigned

```c
signed int a;     // Puo essere negativo (default)
unsigned int b;   // Solo valori >= 0, range doppio positivo

unsigned char c;  // 0 a 255 invece di -128 a 127
```

### short e long

```c
short int s;      // Intero corto (almeno 16 bit)
long int l;       // Intero lungo (almeno 32 bit)
long long int ll; // Intero molto lungo (almeno 64 bit)

// "int" puo essere omesso
short s2;
long l2;
long long ll2;
```

## sizeof

L'operatore `sizeof` restituisce la dimensione in byte di un tipo o variabile.

```c
#include <stdio.h>

int main(void) {
    printf("char: %zu byte\n", sizeof(char));
    printf("int: %zu byte\n", sizeof(int));
    printf("long: %zu byte\n", sizeof(long));
    printf("float: %zu byte\n", sizeof(float));
    printf("double: %zu byte\n", sizeof(double));

    int x = 10;
    printf("variabile x: %zu byte\n", sizeof(x));

    return 0;
}
```

Nota: `%zu` e il formato per `size_t`, il tipo restituito da `sizeof`.

## Limiti dei Tipi

L'header `<limits.h>` definisce i limiti per i tipi interi:

```c
#include <stdio.h>
#include <limits.h>

int main(void) {
    printf("INT_MIN: %d\n", INT_MIN);
    printf("INT_MAX: %d\n", INT_MAX);
    printf("UINT_MAX: %u\n", UINT_MAX);
    printf("CHAR_MIN: %d\n", CHAR_MIN);
    printf("CHAR_MAX: %d\n", CHAR_MAX);
    return 0;
}
```

L'header `<float.h>` per i floating point:

```c
#include <float.h>

FLT_MIN    // Minimo float positivo normalizzato
FLT_MAX    // Massimo float
DBL_MIN    // Minimo double positivo normalizzato
DBL_MAX    // Massimo double
```

## Costanti

### Costanti letterali

```c
int dec = 42;        // Decimale
int oct = 052;       // Ottale (inizia con 0)
int hex = 0x2A;      // Esadecimale (inizia con 0x)

float f = 3.14f;     // Float (suffisso f)
double d = 3.14;     // Double (default)
long l = 100L;       // Long (suffisso L)
unsigned u = 100U;   // Unsigned (suffisso U)
```

### const

```c
const int MAX = 100;       // Variabile costante
const double PI = 3.14159; // Non puo essere modificata
```

### #define

```c
#define MAX 100            // Macro preprocessore
#define PI 3.14159         // Sostituzione testuale
```

Differenza: `const` crea una variabile con tipo, `#define` fa sostituzione testuale.

## Conversioni di Tipo

### Conversione implicita

Il C converte automaticamente in alcuni casi:

```c
int i = 10;
double d = i;       // int -> double (promozione)
int j = 3.7;        // double -> int (troncamento, j = 3)
```

### Conversione esplicita (cast)

```c
double d = 3.7;
int i = (int)d;              // Cast esplicito, i = 3

int a = 5, b = 2;
double risultato = (double)a / b;  // 2.5, non 2
```

## Input con scanf

```c
#include <stdio.h>

int main(void) {
    int eta;
    double altezza;
    char iniziale;

    printf("Inserisci eta: ");
    scanf("%d", &eta);            // Nota: & prima della variabile

    printf("Inserisci altezza: ");
    scanf("%lf", &altezza);       // %lf per double in scanf

    printf("Inserisci iniziale: ");
    scanf(" %c", &iniziale);      // Spazio prima di %c per saltare whitespace

    printf("Eta: %d, Altezza: %.2f, Iniziale: %c\n", eta, altezza, iniziale);
    return 0;
}
```

### Specificatori di formato

| Tipo | printf | scanf |
|------|--------|-------|
| int | %d | %d |
| unsigned | %u | %u |
| long | %ld | %ld |
| float | %f | %f |
| double | %f | %lf |
| char | %c | %c |
| stringa | %s | %s |

## Errori Comuni

1. **Variabile non inizializzata**
   ```c
   int x;
   printf("%d", x);  // Valore indefinito!
   ```

2. **Overflow**
   ```c
   unsigned char c = 255;
   c = c + 1;  // c diventa 0 (overflow)
   ```

3. **Divisione intera**
   ```c
   int a = 5 / 2;     // a = 2, non 2.5
   double b = 5 / 2;  // b = 2.0, divisione intera prima del cast
   double c = 5.0 / 2; // c = 2.5, corretto
   ```

4. **Dimenticare & in scanf**
   ```c
   int x;
   scanf("%d", x);   // Errore! Manca &
   scanf("%d", &x);  // Corretto
   ```
