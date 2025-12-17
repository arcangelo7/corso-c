# Modulo 07 - Stringhe

## Introduzione

In C, una stringa e un array di caratteri terminato dal carattere nullo `\0`.

```c
char str[] = "Hello";  // {'H', 'e', 'l', 'l', 'o', '\0'}
```

## Dichiarazione e inizializzazione

### Come array di caratteri

```c
char s1[6] = "Hello";           // 5 caratteri + '\0'
char s2[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
char s3[] = "Hello";            // Dimensione automatica (6)
char s4[10] = "Hello";          // Spazio extra riempito con '\0'
```

### Come puntatore (stringa letterale)

```c
const char *s = "Hello";  // Punta a memoria read-only
```

Nota: le stringhe letterali non devono essere modificate.

## Terminatore nullo

Il carattere `\0` (valore ASCII 0) marca la fine della stringa.

```c
char s[] = "ABC";
// In memoria: 'A' 'B' 'C' '\0'
// s[0]='A', s[1]='B', s[2]='C', s[3]='\0'
```

Senza terminatore, le funzioni non sanno dove finisce la stringa:

```c
char bad[3] = {'A', 'B', 'C'};  // Manca '\0'!
printf("%s\n", bad);  // Comportamento indefinito
```

## Lunghezza di una stringa

```c
#include <string.h>

char s[] = "Hello";
int len = strlen(s);  // 5 (non conta '\0')
```

### Implementazione manuale

```c
int my_strlen(const char *s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}
```

## Input di stringhe

### scanf

```c
char nome[50];
scanf("%s", nome);  // Legge fino al primo spazio
// Non serve & perche nome e gia un indirizzo
```

Problema: scanf si ferma agli spazi e non controlla i limiti.

### fgets (consigliato)

```c
char linea[100];
fgets(linea, sizeof(linea), stdin);  // Legge l'intera riga
```

Nota: fgets include il carattere newline `\n` se presente.

```c
// Rimuovere newline
char linea[100];
fgets(linea, sizeof(linea), stdin);
linea[strcspn(linea, "\n")] = '\0';  // Rimuove \n
```

### getchar

```c
char c = getchar();  // Legge un singolo carattere
```

## Output di stringhe

```c
char s[] = "Hello";

printf("%s\n", s);       // Hello
printf("%.3s\n", s);     // Hel (primi 3 caratteri)
printf("%10s\n", s);     //      Hello (padding a destra)
printf("%-10s\n", s);    // Hello      (padding a sinistra)

puts(s);                 // Hello + newline automatico
```

## Funzioni di string.h

### strlen - Lunghezza

```c
size_t strlen(const char *s);

char s[] = "Hello";
printf("%zu\n", strlen(s));  // 5
```

### strcpy - Copia

```c
char *strcpy(char *dest, const char *src);

char dest[20];
strcpy(dest, "Hello");  // dest = "Hello"
```

### strncpy - Copia sicura

```c
char *strncpy(char *dest, const char *src, size_t n);

char dest[5];
strncpy(dest, "Hello World", 4);
dest[4] = '\0';  // Assicura terminazione
// dest = "Hell"
```

### strcat - Concatenazione

```c
char *strcat(char *dest, const char *src);

char s[20] = "Hello";
strcat(s, " World");  // s = "Hello World"
```

### strncat - Concatenazione sicura

```c
char *strncat(char *dest, const char *src, size_t n);

char s[15] = "Hello";
strncat(s, " World!", 6);  // s = "Hello World"
```

### strcmp - Confronto

```c
int strcmp(const char *s1, const char *s2);
// Ritorna:
// < 0 se s1 < s2
// 0 se s1 == s2
// > 0 se s1 > s2

if (strcmp(s1, s2) == 0) {
    printf("Uguali\n");
}
```

### strncmp - Confronto parziale

```c
int strncmp(const char *s1, const char *s2, size_t n);

strncmp("Hello", "Help", 3);  // 0 (primi 3 uguali)
```

### strchr - Cerca carattere

```c
char *strchr(const char *s, int c);

char s[] = "Hello World";
char *p = strchr(s, 'W');
if (p != NULL) {
    printf("Trovato: %s\n", p);  // "World"
}
```

### strstr - Cerca sottostringa

```c
char *strstr(const char *haystack, const char *needle);

char s[] = "Hello World";
char *p = strstr(s, "Wor");
if (p != NULL) {
    printf("Trovato: %s\n", p);  // "World"
}
```

## Funzioni di ctype.h

Operano su singoli caratteri.

```c
#include <ctype.h>

isalpha(c)   // Lettera (a-z, A-Z)
isdigit(c)   // Cifra (0-9)
isalnum(c)   // Lettera o cifra
isspace(c)   // Spazio, tab, newline
isupper(c)   // Maiuscola
islower(c)   // Minuscola

toupper(c)   // Converte in maiuscola
tolower(c)   // Converte in minuscola
```

### Esempio: converti in maiuscolo

```c
void to_upper(char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        s[i] = toupper(s[i]);
    }
}
```

## Conversione stringa-numero

### Da stringa a numero (stdlib.h)

```c
#include <stdlib.h>

int i = atoi("123");       // i = 123
long l = atol("123456");   // l = 123456
double d = atof("3.14");   // d = 3.14
```

### Da numero a stringa (sprintf)

```c
char buffer[50];
int n = 42;
sprintf(buffer, "%d", n);  // buffer = "42"

double pi = 3.14159;
sprintf(buffer, "%.2f", pi);  // buffer = "3.14"
```

## Array di stringhe

```c
// Array di puntatori a stringhe
char *giorni[] = {"Lun", "Mar", "Mer", "Gio", "Ven", "Sab", "Dom"};

for (int i = 0; i < 7; i++) {
    printf("%s\n", giorni[i]);
}

// Array 2D di caratteri
char nomi[3][20] = {"Alice", "Bob", "Charlie"};

for (int i = 0; i < 3; i++) {
    printf("%s\n", nomi[i]);
}
```

## Pattern comuni

### Contare caratteri

```c
int conta_vocali(const char *s) {
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        char c = tolower(s[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    return count;
}
```

### Invertire stringa

```c
void inverti(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        char temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
}
```

### Verificare palindromo

```c
int is_palindrome(const char *s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - 1 - i]) {
            return 0;
        }
    }
    return 1;
}
```

## Errori comuni

1. **Buffer overflow**
   ```c
   char s[5];
   strcpy(s, "Hello World");  // Overflow! Serve spazio per 12 caratteri
   ```

2. **Dimenticare il terminatore**
   ```c
   char s[5];
   strncpy(s, "Hello", 5);  // '\0' non incluso!
   s[4] = '\0';  // Necessario
   ```

3. **Modificare stringhe letterali**
   ```c
   char *s = "Hello";
   s[0] = 'h';  // Undefined behavior!
   ```

4. **Usare == per confrontare**
   ```c
   if (s1 == s2)  // Confronta indirizzi, non contenuto!
   if (strcmp(s1, s2) == 0)  // Corretto
   ```

5. **Non controllare il valore di ritorno**
   ```c
   char *p = strstr(s, "test");
   printf("%s\n", p);  // Crash se p e NULL!

   // Corretto:
   if (p != NULL) {
       printf("%s\n", p);
   }
   ```
