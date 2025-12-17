# Modulo 11 - File I/O

## Introduzione

Il C fornisce funzioni per leggere e scrivere file attraverso stream. Le funzioni sono in `<stdio.h>`.

## FILE pointer

```c
FILE *fp;  // Puntatore a stream
```

## fopen - Apertura file

```c
FILE *fopen(const char *filename, const char *mode);
```

### Modalita di apertura

| Modalita | Descrizione |
|----------|-------------|
| `"r"` | Lettura (file deve esistere) |
| `"w"` | Scrittura (crea o sovrascrive) |
| `"a"` | Append (crea o aggiunge in fondo) |
| `"r+"` | Lettura e scrittura (file deve esistere) |
| `"w+"` | Lettura e scrittura (crea o sovrascrive) |
| `"a+"` | Lettura e append |
| `"rb"` | Lettura binaria |
| `"wb"` | Scrittura binaria |

### Esempio

```c
FILE *fp = fopen("dati.txt", "r");
if (fp == NULL) {
    perror("Errore apertura file");
    return 1;
}
// ... usa il file ...
fclose(fp);
```

## fclose - Chiusura file

```c
int fclose(FILE *fp);
```

Chiude lo stream e libera le risorse. Restituisce 0 se successo, EOF se errore.

```c
if (fclose(fp) != 0) {
    perror("Errore chiusura file");
}
```

## Lettura file di testo

### fgetc - Legge un carattere

```c
int fgetc(FILE *fp);  // Restituisce char o EOF
```

```c
int c;
while ((c = fgetc(fp)) != EOF) {
    putchar(c);
}
```

### fgets - Legge una riga

```c
char *fgets(char *str, int n, FILE *fp);
```

Legge fino a n-1 caratteri o newline. Restituisce NULL a fine file.

```c
char linea[100];
while (fgets(linea, sizeof(linea), fp) != NULL) {
    printf("%s", linea);  // linea include '\n'
}
```

### fscanf - Lettura formattata

```c
int fscanf(FILE *fp, const char *format, ...);
```

```c
int a, b;
fscanf(fp, "%d %d", &a, &b);

// Legge finche ci sono dati
while (fscanf(fp, "%d", &n) == 1) {
    printf("Letto: %d\n", n);
}
```

## Scrittura file di testo

### fputc - Scrive un carattere

```c
int fputc(int c, FILE *fp);
```

```c
fputc('A', fp);
fputc('\n', fp);
```

### fputs - Scrive una stringa

```c
int fputs(const char *str, FILE *fp);
```

```c
fputs("Hello World\n", fp);
```

### fprintf - Scrittura formattata

```c
int fprintf(FILE *fp, const char *format, ...);
```

```c
fprintf(fp, "Nome: %s, Eta: %d\n", nome, eta);
```

## File binari

### fread - Lettura binaria

```c
size_t fread(void *ptr, size_t size, size_t count, FILE *fp);
```

```c
int numeri[10];
size_t letti = fread(numeri, sizeof(int), 10, fp);
printf("Letti %zu interi\n", letti);
```

### fwrite - Scrittura binaria

```c
size_t fwrite(const void *ptr, size_t size, size_t count, FILE *fp);
```

```c
int numeri[] = {1, 2, 3, 4, 5};
fwrite(numeri, sizeof(int), 5, fp);
```

### Esempio: salva/carica struct

```c
typedef struct {
    char nome[50];
    int eta;
    double stipendio;
} Persona;

// Salvataggio
void salva_persona(FILE *fp, const Persona *p) {
    fwrite(p, sizeof(Persona), 1, fp);
}

// Caricamento
int carica_persona(FILE *fp, Persona *p) {
    return fread(p, sizeof(Persona), 1, fp) == 1;
}
```

## Posizionamento nel file

### fseek - Sposta la posizione

```c
int fseek(FILE *fp, long offset, int origin);
```

Origin:
- `SEEK_SET` - Inizio file
- `SEEK_CUR` - Posizione corrente
- `SEEK_END` - Fine file

```c
fseek(fp, 0, SEEK_SET);    // Vai all'inizio
fseek(fp, 0, SEEK_END);    // Vai alla fine
fseek(fp, 100, SEEK_SET);  // Vai al byte 100
fseek(fp, -10, SEEK_CUR);  // Indietro di 10 byte
```

### ftell - Posizione corrente

```c
long ftell(FILE *fp);
```

```c
long pos = ftell(fp);
printf("Posizione: %ld\n", pos);
```

### rewind - Torna all'inizio

```c
void rewind(FILE *fp);  // Equivale a fseek(fp, 0, SEEK_SET)
```

### Esempio: dimensione file

```c
long dimensione_file(FILE *fp) {
    long pos_corrente = ftell(fp);  // Salva posizione
    fseek(fp, 0, SEEK_END);         // Vai alla fine
    long dimensione = ftell(fp);     // Leggi posizione
    fseek(fp, pos_corrente, SEEK_SET); // Ripristina
    return dimensione;
}
```

## Controllo errori

### feof - Fine file

```c
int feof(FILE *fp);  // Restituisce non-zero se EOF
```

### ferror - Errore

```c
int ferror(FILE *fp);  // Restituisce non-zero se errore
```

### clearerr - Resetta flag

```c
void clearerr(FILE *fp);
```

### perror - Stampa errore

```c
perror("Messaggio");  // Stampa: Messaggio: descrizione errore
```

## Stream standard

```c
stdin   // Input standard (tastiera)
stdout  // Output standard (schermo)
stderr  // Output errori
```

```c
fprintf(stderr, "Errore: %s\n", messaggio);
```

## Esempio completo: copia file

```c
#include <stdio.h>

int copia_file(const char *src, const char *dst) {
    FILE *fin = fopen(src, "rb");
    if (fin == NULL) {
        perror("Errore apertura sorgente");
        return -1;
    }

    FILE *fout = fopen(dst, "wb");
    if (fout == NULL) {
        perror("Errore apertura destinazione");
        fclose(fin);
        return -1;
    }

    char buffer[4096];
    size_t letti;

    while ((letti = fread(buffer, 1, sizeof(buffer), fin)) > 0) {
        if (fwrite(buffer, 1, letti, fout) != letti) {
            perror("Errore scrittura");
            fclose(fin);
            fclose(fout);
            return -1;
        }
    }

    fclose(fin);
    fclose(fout);
    return 0;
}
```

## Esempio: Conta righe e parole

```c
#include <stdio.h>
#include <ctype.h>

void conta_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Errore");
        return;
    }

    int righe = 0, parole = 0, caratteri = 0;
    int in_parola = 0;
    int c;

    while ((c = fgetc(fp)) != EOF) {
        caratteri++;
        if (c == '\n') righe++;
        if (isspace(c)) {
            in_parola = 0;
        } else if (!in_parola) {
            in_parola = 1;
            parole++;
        }
    }

    printf("Righe: %d\n", righe);
    printf("Parole: %d\n", parole);
    printf("Caratteri: %d\n", caratteri);

    fclose(fp);
}
```

## Errori comuni

1. **Non controllare fopen**
   ```c
   FILE *fp = fopen("file.txt", "r");
   fscanf(fp, ...);  // Crash se fp e NULL!
   ```

2. **Dimenticare fclose**
   ```c
   FILE *fp = fopen("file.txt", "w");
   fprintf(fp, "dati");
   // Dimentica fclose -> dati potrebbero non essere scritti
   ```

3. **Modalita sbagliata**
   ```c
   FILE *fp = fopen("file.txt", "r");
   fprintf(fp, "dati");  // Errore: file aperto in lettura!
   ```

4. **Buffer overflow con fscanf**
   ```c
   char nome[10];
   fscanf(fp, "%s", nome);  // Pericoloso!
   fscanf(fp, "%9s", nome); // Sicuro: limita a 9 char
   ```

5. **Usare feof nel modo sbagliato**
   ```c
   // Sbagliato
   while (!feof(fp)) {
       fscanf(fp, "%d", &n);
       printf("%d\n", n);  // Stampa l'ultimo valore due volte
   }

   // Corretto
   while (fscanf(fp, "%d", &n) == 1) {
       printf("%d\n", n);
   }
   ```
