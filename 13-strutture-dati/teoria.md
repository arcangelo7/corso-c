# Modulo 13 - Strutture Dati

## Introduzione

Le strutture dati permettono di organizzare i dati in modo efficiente. In C si implementano usando puntatori e allocazione dinamica.

## Lista Concatenata (Linked List)

Una lista concatenata e una sequenza di nodi, dove ogni nodo contiene un dato e un puntatore al nodo successivo.

### Struttura

```c
typedef struct Nodo {
    int dato;
    struct Nodo *next;
} Nodo;
```

### Operazioni base

```c
// Crea nuovo nodo
Nodo *crea_nodo(int valore) {
    Nodo *nuovo = malloc(sizeof(Nodo));
    if (nuovo != NULL) {
        nuovo->dato = valore;
        nuovo->next = NULL;
    }
    return nuovo;
}

// Inserimento in testa
void inserisci_testa(Nodo **testa, int valore) {
    Nodo *nuovo = crea_nodo(valore);
    if (nuovo != NULL) {
        nuovo->next = *testa;
        *testa = nuovo;
    }
}

// Inserimento in coda
void inserisci_coda(Nodo **testa, int valore) {
    Nodo *nuovo = crea_nodo(valore);
    if (nuovo == NULL) return;

    if (*testa == NULL) {
        *testa = nuovo;
        return;
    }

    Nodo *corrente = *testa;
    while (corrente->next != NULL) {
        corrente = corrente->next;
    }
    corrente->next = nuovo;
}

// Stampa lista
void stampa_lista(Nodo *testa) {
    Nodo *corrente = testa;
    while (corrente != NULL) {
        printf("%d -> ", corrente->dato);
        corrente = corrente->next;
    }
    printf("NULL\n");
}

// Ricerca
Nodo *cerca(Nodo *testa, int valore) {
    Nodo *corrente = testa;
    while (corrente != NULL) {
        if (corrente->dato == valore) {
            return corrente;
        }
        corrente = corrente->next;
    }
    return NULL;
}

// Eliminazione nodo
void elimina(Nodo **testa, int valore) {
    if (*testa == NULL) return;

    // Se e la testa
    if ((*testa)->dato == valore) {
        Nodo *temp = *testa;
        *testa = (*testa)->next;
        free(temp);
        return;
    }

    // Cerca nel resto
    Nodo *corrente = *testa;
    while (corrente->next != NULL && corrente->next->dato != valore) {
        corrente = corrente->next;
    }

    if (corrente->next != NULL) {
        Nodo *temp = corrente->next;
        corrente->next = corrente->next->next;
        free(temp);
    }
}

// Libera tutta la lista
void libera_lista(Nodo *testa) {
    while (testa != NULL) {
        Nodo *temp = testa;
        testa = testa->next;
        free(temp);
    }
}
```

### Esempio uso

```c
int main(void) {
    Nodo *lista = NULL;

    inserisci_coda(&lista, 10);
    inserisci_coda(&lista, 20);
    inserisci_testa(&lista, 5);

    stampa_lista(lista);  // 5 -> 10 -> 20 -> NULL

    elimina(&lista, 10);
    stampa_lista(lista);  // 5 -> 20 -> NULL

    libera_lista(lista);
    return 0;
}
```

## Lista Doppiamente Concatenata

Ogni nodo ha puntatori al nodo precedente e successivo.

```c
typedef struct NodoD {
    int dato;
    struct NodoD *prev;
    struct NodoD *next;
} NodoD;

NodoD *crea_nodo_d(int valore) {
    NodoD *nuovo = malloc(sizeof(NodoD));
    if (nuovo != NULL) {
        nuovo->dato = valore;
        nuovo->prev = NULL;
        nuovo->next = NULL;
    }
    return nuovo;
}

void inserisci_coda_d(NodoD **testa, NodoD **coda, int valore) {
    NodoD *nuovo = crea_nodo_d(valore);
    if (nuovo == NULL) return;

    if (*testa == NULL) {
        *testa = *coda = nuovo;
    } else {
        nuovo->prev = *coda;
        (*coda)->next = nuovo;
        *coda = nuovo;
    }
}
```

## Stack (Pila)

Struttura LIFO (Last In, First Out). L'ultimo elemento inserito e il primo a uscire.

```c
typedef struct {
    int *dati;
    int top;
    int capacita;
} Stack;

// Inizializza
Stack *crea_stack(int capacita) {
    Stack *s = malloc(sizeof(Stack));
    if (s != NULL) {
        s->dati = malloc(capacita * sizeof(int));
        s->top = -1;
        s->capacita = capacita;
    }
    return s;
}

// E vuoto?
int stack_vuoto(Stack *s) {
    return s->top == -1;
}

// E pieno?
int stack_pieno(Stack *s) {
    return s->top == s->capacita - 1;
}

// Push: inserisci in cima
int push(Stack *s, int valore) {
    if (stack_pieno(s)) {
        return 0;  // Fallito
    }
    s->dati[++s->top] = valore;
    return 1;
}

// Pop: rimuovi dalla cima
int pop(Stack *s, int *valore) {
    if (stack_vuoto(s)) {
        return 0;  // Fallito
    }
    *valore = s->dati[s->top--];
    return 1;
}

// Peek: guarda la cima senza rimuovere
int peek(Stack *s, int *valore) {
    if (stack_vuoto(s)) {
        return 0;
    }
    *valore = s->dati[s->top];
    return 1;
}

// Libera
void libera_stack(Stack *s) {
    if (s != NULL) {
        free(s->dati);
        free(s);
    }
}
```

### Stack con lista concatenata

```c
typedef struct NodoStack {
    int dato;
    struct NodoStack *next;
} NodoStack;

void push_lista(NodoStack **top, int valore) {
    NodoStack *nuovo = malloc(sizeof(NodoStack));
    if (nuovo != NULL) {
        nuovo->dato = valore;
        nuovo->next = *top;
        *top = nuovo;
    }
}

int pop_lista(NodoStack **top) {
    if (*top == NULL) return -1;  // Stack vuoto

    int valore = (*top)->dato;
    NodoStack *temp = *top;
    *top = (*top)->next;
    free(temp);
    return valore;
}
```

## Queue (Coda)

Struttura FIFO (First In, First Out). Il primo elemento inserito e il primo a uscire.

```c
typedef struct {
    int *dati;
    int front;
    int rear;
    int dimensione;
    int capacita;
} Queue;

Queue *crea_queue(int capacita) {
    Queue *q = malloc(sizeof(Queue));
    if (q != NULL) {
        q->dati = malloc(capacita * sizeof(int));
        q->front = 0;
        q->rear = -1;
        q->dimensione = 0;
        q->capacita = capacita;
    }
    return q;
}

int queue_vuota(Queue *q) {
    return q->dimensione == 0;
}

int queue_piena(Queue *q) {
    return q->dimensione == q->capacita;
}

// Enqueue: inserisci in fondo
int enqueue(Queue *q, int valore) {
    if (queue_piena(q)) return 0;

    q->rear = (q->rear + 1) % q->capacita;  // Coda circolare
    q->dati[q->rear] = valore;
    q->dimensione++;
    return 1;
}

// Dequeue: rimuovi dalla testa
int dequeue(Queue *q, int *valore) {
    if (queue_vuota(q)) return 0;

    *valore = q->dati[q->front];
    q->front = (q->front + 1) % q->capacita;
    q->dimensione--;
    return 1;
}

void libera_queue(Queue *q) {
    if (q != NULL) {
        free(q->dati);
        free(q);
    }
}
```

### Queue con lista concatenata

```c
typedef struct NodoQ {
    int dato;
    struct NodoQ *next;
} NodoQ;

typedef struct {
    NodoQ *front;
    NodoQ *rear;
} QueueLista;

void enqueue_lista(QueueLista *q, int valore) {
    NodoQ *nuovo = malloc(sizeof(NodoQ));
    if (nuovo == NULL) return;

    nuovo->dato = valore;
    nuovo->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = nuovo;
    } else {
        q->rear->next = nuovo;
        q->rear = nuovo;
    }
}

int dequeue_lista(QueueLista *q) {
    if (q->front == NULL) return -1;

    int valore = q->front->dato;
    NodoQ *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return valore;
}
```

## Albero Binario (Cenni)

Un albero binario e una struttura gerarchica dove ogni nodo ha al massimo due figli.

```c
typedef struct NodoAlbero {
    int dato;
    struct NodoAlbero *sinistro;
    struct NodoAlbero *destro;
} NodoAlbero;

NodoAlbero *crea_nodo_albero(int valore) {
    NodoAlbero *nuovo = malloc(sizeof(NodoAlbero));
    if (nuovo != NULL) {
        nuovo->dato = valore;
        nuovo->sinistro = NULL;
        nuovo->destro = NULL;
    }
    return nuovo;
}

// Inserimento in albero binario di ricerca (BST)
NodoAlbero *inserisci_bst(NodoAlbero *radice, int valore) {
    if (radice == NULL) {
        return crea_nodo_albero(valore);
    }

    if (valore < radice->dato) {
        radice->sinistro = inserisci_bst(radice->sinistro, valore);
    } else {
        radice->destro = inserisci_bst(radice->destro, valore);
    }

    return radice;
}

// Visita in ordine (stampa ordinata per BST)
void visita_inorder(NodoAlbero *radice) {
    if (radice != NULL) {
        visita_inorder(radice->sinistro);
        printf("%d ", radice->dato);
        visita_inorder(radice->destro);
    }
}

// Ricerca in BST
NodoAlbero *cerca_bst(NodoAlbero *radice, int valore) {
    if (radice == NULL || radice->dato == valore) {
        return radice;
    }

    if (valore < radice->dato) {
        return cerca_bst(radice->sinistro, valore);
    }
    return cerca_bst(radice->destro, valore);
}
```

## Confronto Strutture

| Struttura | Inserimento | Ricerca | Rimozione | Uso tipico |
|-----------|-------------|---------|-----------|------------|
| Array | O(n) | O(n) / O(1) | O(n) | Accesso per indice |
| Lista | O(1) testa | O(n) | O(n) | Inserimenti frequenti |
| Stack | O(1) | - | O(1) | Undo, parsing |
| Queue | O(1) | - | O(1) | Scheduling, BFS |
| BST | O(log n) avg | O(log n) avg | O(log n) avg | Dati ordinati |

## Errori Comuni

1. **Memory leak nelle strutture**
   ```c
   // Dimenticare di liberare i nodi
   lista = NULL;  // Memory leak!

   // Corretto: liberare ogni nodo
   libera_lista(lista);
   ```

2. **Accesso a puntatore NULL**
   ```c
   corrente->next->dato  // Se next e NULL: crash
   ```

3. **Perdere riferimento alla testa**
   ```c
   Nodo *lista = ...;
   lista = lista->next;  // Hai perso il primo nodo!
   ```

4. **Non aggiornare puntatore doppio**
   ```c
   void inserisci(Nodo *testa, int v) {  // Sbagliato
       // La modifica a testa non e visibile fuori
   }

   void inserisci(Nodo **testa, int v) {  // Corretto
       *testa = nuovo;
   }
   ```
