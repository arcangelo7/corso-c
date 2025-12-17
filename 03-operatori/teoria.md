# Modulo 03 - Operatori

## Operatori aritmetici

| Operatore | Descrizione | Esempio |
|-----------|-------------|---------|
| `+` | Addizione | `5 + 3` = 8 |
| `-` | Sottrazione | `5 - 3` = 2 |
| `*` | Moltiplicazione | `5 * 3` = 15 |
| `/` | Divisione | `5 / 3` = 1 (intera) |
| `%` | Modulo (resto) | `5 % 3` = 2 |

### Divisione intera vs floating point

```c
int a = 7 / 2;        // a = 3 (divisione intera)
double b = 7 / 2;     // b = 3.0 (divisione intera, poi cast)
double c = 7.0 / 2;   // c = 3.5 (divisione floating point)
double d = (double)7 / 2;  // d = 3.5 (cast esplicito)
```

### Operatore modulo

Il modulo restituisce il resto della divisione intera.

```c
int resto = 17 % 5;   // resto = 2 (17 = 5*3 + 2)
int pari = 10 % 2;    // pari = 0 (10 e divisibile per 2)
int dispari = 7 % 2;  // dispari = 1
```

## Operatori di assegnamento

| Operatore | Equivalente | Esempio |
|-----------|-------------|---------|
| `=` | assegnazione | `x = 5` |
| `+=` | `x = x + y` | `x += 3` |
| `-=` | `x = x - y` | `x -= 3` |
| `*=` | `x = x * y` | `x *= 3` |
| `/=` | `x = x / y` | `x /= 3` |
| `%=` | `x = x % y` | `x %= 3` |

```c
int x = 10;
x += 5;   // x = 15
x -= 3;   // x = 12
x *= 2;   // x = 24
x /= 4;   // x = 6
x %= 4;   // x = 2
```

## Operatori di incremento/decremento

| Operatore | Descrizione |
|-----------|-------------|
| `++x` | Pre-incremento: incrementa, poi usa |
| `x++` | Post-incremento: usa, poi incrementa |
| `--x` | Pre-decremento |
| `x--` | Post-decremento |

```c
int a = 5;
int b = ++a;  // a = 6, b = 6 (incrementa prima)
int c = a++;  // c = 6, a = 7 (usa prima, poi incrementa)

printf("%d\n", a);  // 7
printf("%d\n", b);  // 6
printf("%d\n", c);  // 6
```

## Operatori relazionali

Restituiscono 1 (vero) o 0 (falso).

| Operatore | Descrizione | Esempio |
|-----------|-------------|---------|
| `==` | Uguale | `5 == 5` -> 1 |
| `!=` | Diverso | `5 != 3` -> 1 |
| `<` | Minore | `3 < 5` -> 1 |
| `>` | Maggiore | `5 > 3` -> 1 |
| `<=` | Minore o uguale | `5 <= 5` -> 1 |
| `>=` | Maggiore o uguale | `3 >= 5` -> 0 |

```c
int x = 5, y = 3;
printf("%d\n", x == y);  // 0
printf("%d\n", x > y);   // 1
printf("%d\n", x != y);  // 1
```

## Operatori logici

| Operatore | Descrizione | Esempio |
|-----------|-------------|---------|
| `&&` | AND logico | `1 && 0` -> 0 |
| `\|\|` | OR logico | `1 \|\| 0` -> 1 |
| `!` | NOT logico | `!1` -> 0 |

### Tabella di verita

| A | B | A && B | A \|\| B | !A |
|---|---|--------|----------|-----|
| 0 | 0 | 0 | 0 | 1 |
| 0 | 1 | 0 | 1 | 1 |
| 1 | 0 | 0 | 1 | 0 |
| 1 | 1 | 1 | 1 | 0 |

### Short-circuit evaluation

Gli operatori logici usano valutazione a corto circuito:

```c
// Se a e falso, b non viene valutato
if (a && b) { }

// Se a e vero, b non viene valutato
if (a || b) { }
```

## Operatori bitwise

Operano sui singoli bit.

| Operatore | Descrizione | Esempio |
|-----------|-------------|---------|
| `&` | AND bit a bit | `5 & 3` = 1 |
| `\|` | OR bit a bit | `5 \| 3` = 7 |
| `^` | XOR bit a bit | `5 ^ 3` = 6 |
| `~` | NOT bit a bit | `~5` = -6 |
| `<<` | Shift a sinistra | `5 << 1` = 10 |
| `>>` | Shift a destra | `5 >> 1` = 2 |

### Esempi bit a bit

```
5 in binario: 0101
3 in binario: 0011

5 & 3 = 0001 = 1   (AND: bit a 1 se entrambi 1)
5 | 3 = 0111 = 7   (OR: bit a 1 se almeno uno 1)
5 ^ 3 = 0110 = 6   (XOR: bit a 1 se diversi)
```

### Shift

```c
int x = 5;          // 0101 in binario
int left = x << 1;  // 1010 = 10 (moltiplica per 2)
int right = x >> 1; // 0010 = 2 (divide per 2)
```

### Usi comuni degli operatori bitwise

```c
// Verifica se un numero e pari
if ((n & 1) == 0) { /* pari */ }

// Imposta un bit
flags |= (1 << 3);  // Imposta il bit 3

// Cancella un bit
flags &= ~(1 << 3); // Cancella il bit 3

// Toggle di un bit
flags ^= (1 << 3);  // Inverte il bit 3

// Verifica un bit
if (flags & (1 << 3)) { /* bit 3 impostato */ }
```

## Operatore condizionale (ternario)

```c
condizione ? valore_se_vero : valore_se_falso
```

```c
int a = 5, b = 3;
int max = (a > b) ? a : b;  // max = 5

// Equivalente a:
int max2;
if (a > b)
    max2 = a;
else
    max2 = b;
```

## Operatore virgola

L'operatore virgola valuta le espressioni da sinistra a destra e restituisce l'ultima.

```c
int a = (1, 2, 3);  // a = 3
int b, c;
b = (c = 5, c + 2); // c = 5, b = 7
```

## Precedenza degli operatori

Dalla precedenza piu alta alla piu bassa:

| Livello | Operatori |
|---------|-----------|
| 1 | `()` `[]` `->` `.` `++` `--` (postfissi) |
| 2 | `++` `--` (prefissi) `!` `~` `+` `-` (unari) `*` `&` `sizeof` |
| 3 | `*` `/` `%` |
| 4 | `+` `-` |
| 5 | `<<` `>>` |
| 6 | `<` `<=` `>` `>=` |
| 7 | `==` `!=` |
| 8 | `&` |
| 9 | `^` |
| 10 | `\|` |
| 11 | `&&` |
| 12 | `\|\|` |
| 13 | `?:` |
| 14 | `=` `+=` `-=` ecc. |
| 15 | `,` |

### Consiglio

Quando la precedenza non e chiara, usa le parentesi:

```c
// Poco chiaro
int x = a + b * c >> d & e;

// Chiaro
int x = ((a + (b * c)) >> d) & e;
```

## Errori comuni

1. **Confondere = e ==**
   ```c
   if (x = 5)   // Assegnazione! Sempre vero se 5 != 0
   if (x == 5)  // Confronto, corretto
   ```

2. **Divisione intera inaspettata**
   ```c
   double media = (a + b) / 2;     // Divisione intera se a,b sono int
   double media = (a + b) / 2.0;   // Corretto
   ```

3. **Overflow negli shift**
   ```c
   int x = 1 << 31;  // Undefined behavior per signed int
   unsigned x = 1u << 31;  // OK per unsigned
   ```
