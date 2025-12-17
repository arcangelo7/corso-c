# Modulo 09 - Struct e Union

## Struct

Una struct raggruppa variabili di tipi diversi sotto un unico nome.

### Definizione

```c
struct Persona {
    char nome[50];
    int eta;
    double altezza;
};
```

### Dichiarazione variabili

```c
struct Persona p1;                    // Variabile singola
struct Persona team[10];              // Array di struct
struct Persona *ptr;                  // Puntatore a struct
```

### Inizializzazione

```c
// Inizializzazione completa
struct Persona p1 = {"Mario", 30, 1.75};

// Inizializzazione parziale (resto a zero)
struct Persona p2 = {"Luigi"};  // eta=0, altezza=0.0

// Designated initializers (C99)
struct Persona p3 = {.nome = "Anna", .eta = 25};

// Inizializzazione dopo dichiarazione
struct Persona p4;
strcpy(p4.nome, "Paolo");
p4.eta = 28;
p4.altezza = 1.80;
```

## Accesso ai Membri

### Operatore punto (.)

```c
struct Persona p = {"Mario", 30, 1.75};

printf("Nome: %s\n", p.nome);
printf("Eta: %d\n", p.eta);

p.eta = 31;  // Modifica
```

### Operatore freccia (->)

Usato con puntatori a struct.

```c
struct Persona p = {"Mario", 30, 1.75};
struct Persona *ptr = &p;

printf("Nome: %s\n", ptr->nome);   // Equivale a (*ptr).nome
printf("Eta: %d\n", ptr->eta);

ptr->eta = 31;  // Modifica
```

## typedef

Crea alias per tipi, evita di ripetere `struct`.

```c
typedef struct {
    char nome[50];
    int eta;
    double altezza;
} Persona;

// Ora puoi usare:
Persona p1;                // Invece di: struct Persona p1;
Persona team[10];
Persona *ptr;
```

### typedef con nome struct

```c
typedef struct Persona {
    char nome[50];
    int eta;
} Persona;

// Utile per strutture autoreferenziali (liste)
typedef struct Nodo {
    int valore;
    struct Nodo *next;  // Deve usare struct Nodo
} Nodo;
```

## Struct Annidate

```c
typedef struct {
    int giorno;
    int mese;
    int anno;
} Data;

typedef struct {
    char nome[50];
    Data nascita;       // Struct annidata
} Persona;

Persona p = {"Mario", {15, 6, 1990}};

printf("Anno nascita: %d\n", p.nascita.anno);
```

## Struct e Funzioni

### Passaggio per valore

La struct viene copiata (costoso per struct grandi).

```c
void stampa(Persona p) {
    printf("Nome: %s, Eta: %d\n", p.nome, p.eta);
}

Persona crea(const char *nome, int eta) {
    Persona p;
    strcpy(p.nome, nome);
    p.eta = eta;
    return p;
}
```

### Passaggio per riferimento (consigliato)

```c
void stampa(const Persona *p) {
    printf("Nome: %s, Eta: %d\n", p->nome, p->eta);
}

void incrementa_eta(Persona *p) {
    p->eta++;
}
```

## Array di Struct

```c
typedef struct {
    char nome[50];
    int voto;
} Studente;

Studente classe[30];

// Inizializzazione
Studente classe2[] = {
    {"Mario", 28},
    {"Luigi", 30},
    {"Anna", 27}
};

// Accesso
for (int i = 0; i < 3; i++) {
    printf("%s: %d\n", classe2[i].nome, classe2[i].voto);
}
```

## sizeof e Padding

Il compilatore puo aggiungere padding per allineamento.

```c
struct Esempio {
    char c;    // 1 byte
    int i;     // 4 byte
    char d;    // 1 byte
};

printf("%zu\n", sizeof(struct Esempio));  // Probabilmente 12, non 6
```

Memoria (su sistema 32-bit con allineamento a 4):
```
| c | pad | pad | pad | i | i | i | i | d | pad | pad | pad |
  1    2     3     4    5   6   7   8   9   10    11    12
```

## Union

Una union e come una struct, ma tutti i membri condividono la stessa memoria.

```c
union Numero {
    int i;
    float f;
    char c;
};

union Numero n;
n.i = 65;
printf("%d\n", n.i);  // 65
printf("%c\n", n.c);  // 'A' (stesso byte interpretato come char)
```

### Dimensione

La dimensione di una union e quella del membro piu grande.

```c
union U {
    char c;    // 1 byte
    int i;     // 4 byte
    double d;  // 8 byte
};

printf("%zu\n", sizeof(union U));  // 8
```

### Uso comune: variant type

```c
typedef enum { INT, FLOAT, STRING } TipoValore;

typedef struct {
    TipoValore tipo;
    union {
        int i;
        float f;
        char s[20];
    } valore;
} Variante;

Variante v;
v.tipo = INT;
v.valore.i = 42;
```

## Enum

Definisce costanti intere con nomi simbolici.

```c
enum Giorno {LUN, MAR, MER, GIO, VEN, SAB, DOM};
// LUN=0, MAR=1, MER=2, ...

enum Giorno oggi = MER;

if (oggi == SAB || oggi == DOM) {
    printf("Weekend!\n");
}
```

### Valori personalizzati

```c
enum Mese {
    GEN = 1, FEB, MAR, APR, MAG, GIU,
    LUG, AGO, SET, OTT, NOV, DIC
};
// GEN=1, FEB=2, MAR=3, ...

enum Errore {
    OK = 0,
    ERR_FILE = -1,
    ERR_MEMORIA = -2,
    ERR_RETE = -100
};
```

### typedef con enum

```c
typedef enum {
    ROSSO, VERDE, BLU
} Colore;

Colore c = VERDE;
```

## Bit Fields

Permettono di specificare il numero di bit per un membro.

```c
struct Flags {
    unsigned int attivo : 1;     // 1 bit
    unsigned int priorita : 3;   // 3 bit (0-7)
    unsigned int stato : 4;      // 4 bit (0-15)
};

struct Flags f;
f.attivo = 1;
f.priorita = 5;
f.stato = 10;
```

Utili per risparmiare memoria o mappare registri hardware.

## Errori Comuni

1. **Assegnare stringhe con =**
   ```c
   Persona p;
   p.nome = "Mario";  // Errore! nome e un array
   strcpy(p.nome, "Mario");  // Corretto
   ```

2. **Confrontare struct con ==**
   ```c
   if (p1 == p2)  // Errore!
   // Confronta membro per membro o usa memcmp
   ```

3. **Dimenticare typedef**
   ```c
   struct Persona p;  // Serve struct senza typedef
   Persona p;         // OK con typedef
   ```

4. **Usare . invece di -> con puntatori**
   ```c
   Persona *ptr = &p;
   ptr.nome;   // Errore!
   ptr->nome;  // Corretto
   ```

5. **Restituire puntatore a struct locale**
   ```c
   Persona *crea(void) {
       Persona p = {"Mario", 30};
       return &p;  // ERRORE! p non esiste piu
   }
   ```
