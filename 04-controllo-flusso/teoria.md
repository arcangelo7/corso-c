# Modulo 04 - Controllo del Flusso

## Istruzione if

```c
if (condizione) {
    // eseguito se condizione e vera (diversa da 0)
}
```

### if-else

```c
if (condizione) {
    // eseguito se vera
} else {
    // eseguito se falsa
}
```

### if-else if-else

```c
if (condizione1) {
    // eseguito se condizione1 vera
} else if (condizione2) {
    // eseguito se condizione2 vera
} else if (condizione3) {
    // eseguito se condizione3 vera
} else {
    // eseguito se nessuna condizione vera
}
```

### Esempio

```c
int voto = 75;

if (voto >= 90) {
    printf("Ottimo\n");
} else if (voto >= 70) {
    printf("Buono\n");
} else if (voto >= 60) {
    printf("Sufficiente\n");
} else {
    printf("Insufficiente\n");
}
```

### if senza parentesi graffe

Se il corpo e una sola istruzione, le parentesi sono opzionali (ma sconsigliate):

```c
if (x > 0)
    printf("Positivo\n");  // Una sola istruzione

if (x > 0) {
    printf("Positivo\n");  // Consigliato: sempre con graffe
}
```

## Istruzione switch

Alternativa a catene di if-else per valori discreti.

```c
switch (espressione) {
    case valore1:
        // codice
        break;
    case valore2:
        // codice
        break;
    default:
        // eseguito se nessun case corrisponde
        break;
}
```

### Esempio

```c
int giorno = 3;

switch (giorno) {
    case 1:
        printf("Lunedi\n");
        break;
    case 2:
        printf("Martedi\n");
        break;
    case 3:
        printf("Mercoledi\n");
        break;
    case 4:
        printf("Giovedi\n");
        break;
    case 5:
        printf("Venerdi\n");
        break;
    case 6:
    case 7:
        printf("Weekend\n");
        break;
    default:
        printf("Giorno non valido\n");
        break;
}
```

### Fall-through

Senza `break`, l'esecuzione continua al case successivo:

```c
int mese = 2;
int giorni;

switch (mese) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        giorni = 31;
        break;
    case 4: case 6: case 9: case 11:
        giorni = 30;
        break;
    case 2:
        giorni = 28;
        break;
}
```

## Ciclo while

Esegue il corpo finche la condizione e vera.

```c
while (condizione) {
    // corpo del ciclo
}
```

### Esempio

```c
int i = 0;
while (i < 5) {
    printf("%d\n", i);
    i++;
}
// Stampa: 0 1 2 3 4
```

### Ciclo infinito

```c
while (1) {
    // ciclo infinito
    // usa break per uscire
}
```

## Ciclo do-while

Esegue il corpo almeno una volta, poi verifica la condizione.

```c
do {
    // corpo del ciclo
} while (condizione);
```

### Esempio

```c
int n;
do {
    printf("Inserisci un numero positivo: ");
    scanf("%d", &n);
} while (n <= 0);  // Ripete finche n non e positivo
```

### Differenza tra while e do-while

```c
int x = 0;

// while: non esegue nulla se condizione falsa
while (x > 0) {
    printf("while\n");  // Non viene eseguito
}

// do-while: esegue almeno una volta
do {
    printf("do-while\n");  // Viene eseguito una volta
} while (x > 0);
```

## Ciclo for

```c
for (inizializzazione; condizione; aggiornamento) {
    // corpo del ciclo
}
```

### Esempio

```c
for (int i = 0; i < 5; i++) {
    printf("%d\n", i);
}
// Stampa: 0 1 2 3 4
```

### Equivalenza for-while

```c
// Questo for:
for (int i = 0; i < 5; i++) {
    printf("%d\n", i);
}

// E equivalente a:
int i = 0;
while (i < 5) {
    printf("%d\n", i);
    i++;
}
```

### Varianti del for

```c
// Contare al contrario
for (int i = 10; i > 0; i--) {
    printf("%d\n", i);
}

// Incremento diverso da 1
for (int i = 0; i < 100; i += 10) {
    printf("%d\n", i);
}

// Parti opzionali (ciclo infinito)
for (;;) {
    // ciclo infinito
}

// Variabili multiple
for (int i = 0, j = 10; i < j; i++, j--) {
    printf("i=%d, j=%d\n", i, j);
}
```

## Cicli Annidati

```c
for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
        printf("(%d,%d) ", i, j);
    }
    printf("\n");
}
```

Output:
```
(1,1) (1,2) (1,3)
(2,1) (2,2) (2,3)
(3,1) (3,2) (3,3)
```

## break e continue

### break

Esce immediatamente dal ciclo o switch.

```c
for (int i = 0; i < 10; i++) {
    if (i == 5) {
        break;  // Esce dal ciclo quando i e 5
    }
    printf("%d ", i);
}
// Stampa: 0 1 2 3 4
```

### continue

Salta il resto dell'iterazione corrente e passa alla successiva.

```c
for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
        continue;  // Salta i numeri pari
    }
    printf("%d ", i);
}
// Stampa: 1 3 5 7 9
```

## goto

L'istruzione `goto` salta a un'etichetta. Generalmente sconsigliato.

```c
for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
        if (i * j > 50) {
            goto fine;  // Esce da entrambi i cicli
        }
    }
}
fine:
printf("Uscito dai cicli\n");
```

Uso legittimo: uscire da cicli annidati o gestione errori in C.

## Pattern Comuni

### Input validation

```c
int n;
do {
    printf("Inserisci un numero tra 1 e 10: ");
    scanf("%d", &n);
} while (n < 1 || n > 10);
```

### Menu interattivo

```c
int scelta;
do {
    printf("\n1. Opzione 1\n");
    printf("2. Opzione 2\n");
    printf("0. Esci\n");
    printf("Scelta: ");
    scanf("%d", &scelta);

    switch (scelta) {
        case 1:
            printf("Hai scelto 1\n");
            break;
        case 2:
            printf("Hai scelto 2\n");
            break;
        case 0:
            printf("Arrivederci\n");
            break;
        default:
            printf("Scelta non valida\n");
    }
} while (scelta != 0);
```

### Ricerca con flag

```c
int numeri[] = {3, 7, 2, 9, 5};
int target = 9;
int trovato = 0;

for (int i = 0; i < 5; i++) {
    if (numeri[i] == target) {
        trovato = 1;
        break;
    }
}

if (trovato) {
    printf("Trovato!\n");
}
```

## Errori Comuni

1. **Punto e virgola dopo if/for/while**
   ```c
   if (x > 0);        // Errore: if vuoto!
       printf("Positivo");

   for (int i = 0; i < 5; i++);  // Errore: ciclo vuoto!
       printf("%d", i);
   ```

2. **Dimenticare break in switch**
   ```c
   switch (x) {
       case 1:
           printf("Uno\n");
           // Manca break! Continua al case 2
       case 2:
           printf("Due\n");
           break;
   }
   ```

3. **Ciclo infinito accidentale**
   ```c
   int i = 0;
   while (i < 5) {
       printf("%d\n", i);
       // Dimenticato i++!
   }
   ```

4. **Off-by-one**
   ```c
   for (int i = 0; i <= 5; i++)  // 6 iterazioni, non 5!
   for (int i = 0; i < 5; i++)   // 5 iterazioni (0,1,2,3,4)
   ```
