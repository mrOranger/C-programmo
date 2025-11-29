# Gestione Dinamica della Memoria

- [Semplice Allocazione della Memoria `malloc`](#malloc)
- [Rilascio della Memoria `free`](#free)
- [Allocazione con Inizializzazione `calloc`](#calloc)
- [Riuso della Memoria con `realloc`](#realloc)
- [Problemi di Sicurezza](#security)

In un normale elaboratore, la memoria centrale viene divisa in due macro-sezioni: lo _stack_ e lo _heap_. Lo stack è una
porzione della memoria centrale allocata direttamente dal sistema operativa, ogni volta che un thread viene avviato, e
che possiede una dimensione fissa. Lo heap è una porzione più disordinata, con delle prestazione relativamente inferiori
in termini di lettura/scrittura delle informazioni, ma con una dimensione molto più grande rispetto allo stack.

Fino a questo momento, ogni volta che abbiamo definito una variabile, questa veniva inserita automaticamente all'interno
dello stack. Nel momento che la nostra applicazione cresce, e richiede più spazio per memorizzare le informazioni,
diventa necessario ricorrere all'uso dello heap.

Lo scenario precedente, tuttavia, non è l'unica motivazione all'uso dello heap rispetto allo stack. Un altro motivo, è
quello di gestire strutture dati dinamiche, ossia: che non possiedono una lunghezza conosciuta a propri. Ad esempio,
considerando una stringa di dimensione variabile, non siamo in grado di conoscerne da subito la lunghezza effettiva, in
quanto questa potrebbe variare durante l'esecuzione del programma.

Con queste premesse, in questo capitolo analizzeremo come gestire dinamicamente la memoria di un'applicazione, mediante
l'uso dello heap. Diversamente da molti altri linguaggi di programmazione come Java, il C non possiede un Garbage
Collector. Di conseguenza, dovremmo prestare attenzione a rilasciare la memoria precedentemente utilizzata, e non più
utile, per evitare che il nostro programma incorra in un [_Memory Leak_](https://it.wikipedia.org/wiki/Memory_leak).

La gestione dinamica della memoria, prevede l'uso di alcune funzioni definiti nella librarie `stdlib.h`, ossia:
`malloc`, `calloc`, `realloc`, e `free`. Ciascuna delle sezioni di questo capitolo, si concentreranno sull'analisi delle
seguenti funzioni, e dei relativi pro e contro.

Diversamente dalle sezioni precedenti, in questo capitolo lavoreremo con un esempio pratico, ossia: creeremo una
libreria che gestisca le stringhe lavorando dinamicamente con la memoria che viene allocata per queste.

## Semplice Allocazione della Memoria `malloc` <a id="malloc"></a>

Cominciamo con la funzione più semplice per allocare memoria dinamicamente, ossia: `malloc`. Come indicato dalla
descrizione ufficiale del C, la funzione richiede in input la dimensione in byte della memoria che è necessario
allocare. Come risultato, viene restituito un puntatore al primo elemento della porzione di memoria appena allocata.

Consideriamo il seguente esempio: vogliamo allocare dinamicamente un vettore di 100 elementi di tipo uint32_t:

```c
#include <stdlib.h>
#include <stdint.h>

int main (const int argc, const char** argv)
{
    uint32_t* vector = (uint32_t*)malloc(100 * sizeof(uint32_t));
    return 0;
}
```

Come possiamo notare, dall'istruzione `uint32_t* vector = (int*)malloc(100 * sizeof(uint32_t));`, viene allocata una
zona di memoria di dimensioni pari a `100 * sizeof(uint32_t)` byte, considerando che la dimensione di un tipo `uint32_t`
è pari a 4 byte. Quindi, nello heap verranno segnati come _"in uso"_ 400 celle di memoria, per l'applicazione corrente.

Essendo che la funzione malloc restituisce un puntatore `void*` al primo elemento della nostra area di memoria, possiamo
accedervi semplicemente usando la notazione per gli array già vista precedentemente. Sebbene, tuttavia, il tipo
restituito sia `void*`, è comunque bene eseguire il cast quando non sia chiaro quale sia il tipo specifico che deve
essere restituito dalla funzione.

La funzione malloc è la più semplice e la più veloce per richiedere nuova memoria al sistema operativo. Sebbene abbia
questi vantaggi, la sua semplicità è allo stesso tempo uno svantaggio, in quanto non _"pulisce"_ la memoria appena
richiesta. Di conseguenza, la funzione potrebbe restituire un puntatore ad una zona di memoria precedentemente allocata,
ed al cui interno sono presenti dei valori usanti in passato dall'applicazione stessa.

## Rilascio della Memoria `free` <a id="free"></a>

Una volta che è stata allocata una porzione di memoria, questa rimane _"riservata"_ al thread che ne ha richiesto,
fintantoché l'applicazione di cui fa parte il thread è in esecuzione; alternativamente, finché non è il programmatore
stesso a liberare la memoria esplicitamente, mediante l'uso della funzione free.

Analizzando la descrizione della funzione `free(void\*), questa richiede di ricevere il puntatore all'indirizzo di
memoria appena allocato, e dal quale, eventualmente, parte una sezione di memoria assegnata dinamicamente. Come è in
grado, tuttavia, il sistema, a sapere che il dopo il puntatore è dichiarato uno spazio da rimuovere pari alla dimensione
specificata precedentemente con l'uso di malloc?

Quando allochiamo spazio in memoria, come possiamo vedere dalla figura sovrastante, prima della posizione in cui è
contenuto il puntatore, è presente una zona di memoria privata, al cui interno sono inseriti i **meta-dati del
puntatore**. All'interno di questi meta-dati, sono inserite informazioni come:

- _Flag di Stato_, che indica se lo spazio può essere riusato, oppure è occupato.
- _Dimensioni_ del blocco allocato.

Tra tutte le funzioni, free è sicuramente la più importante. Nel momento in cui è stato allocato dello spazio in
memoria, e non viene indicato dal programmatore che questo è libero dopo che non sia più utile per il programma. Lo
spazio allocato, rimarrà segnato come _"occupato"_, per tutta l'attività del programma stesso. In uno scenario di
esecuzione in test o in locale, questo potrebbe non risultare un problema. In uno scenario di produzione, tuttavia, dove
l'applicazione è in esecuzione sempre, dimenticarsi di segnalare che lo spazio può essere ri-usato dall'applicazione
stessa, implicherebbe un maggiore consumo di memoria da parte dell'applicazione, di conseguenza, il programma potrebbe
esaurire lo spazio disponibile in memoria centrale, e causare un crash. Questo problema è la descrizione del **Memory
Leak**.

## Allocazione con Inizializzazione `calloc` <a id="calloc"></a>

Come abbiamo scritto precedentemente, la funzione malloc alloca uno spazio libero, senza _"pulirlo"_ prima che venga
riusato dal programma. La funzione `calloc` esegue quest'operazione di pulizia automaticamente, a scapito, tuttavia, di
una minore efficienza nell'allocazione della memoria.

Riprendendo l'esempio precedente, possiamo usare al posto di malloc la funzione calloc in questo modo:

```c
#include <stdlib.h>
#include <stdint.h>

int main (const int argc, const char** argv)
{
    uint32_t* vector = (uint32_t*)calloc(100, sizeof(uint32_t));

    return 0;
}
```

Effettivamente, l'istruzione `uint32_t* vector = (int*)calloc(100, sizeof(uint32_t));`, è molto simile, se non per la
differenza del numero di parametri usati, rispetto alla stessa istruzione che usa la funzione `malloc`. Vista la
capacità di sanificare lo spazio di memoria, prima di restituirlo al programmatore, è consigliato l'uso di `calloc`
rispetto a `malloc`.

## Riuso della Memoria `realloc` <a id="realloc"></a>

Diversamente dalle due funzioni precedenti `malloc` e `calloc`, che creano una nuova zona di memoria disponibile per il
nostro programma, non è detto che `realloc` ne crei una nuova. Analizzando il seguente esempio, ci sarà più chiara la
differenza con le rimanenti istruzioni:

```c
#include <stdlib.h>
#include <stdint.h>

int main (const int argc, const char** argv)
{
    uint32_t* old_vector = (uint32_t*)calloc(100, sizeof(uint32_t));
    uint32_t* new_vector = (uint32_t*)realloc(old_vector, 100 * sizeof(uint32_t));

    return 0;
}
```

Come possiamo vedere, realloc richiede un parametro aggiuntivo, rispetto alla dimensione in byte della memoria da
allocare; questo parametro aggiuntivo è: il puntatore all'inizio della zona di memoria che deve essere allocata
nuovamente.

Nel momento in cui richiediamo di allocare nuovamente la zona di memoria che era stata precedentemente richiesta, e la
nuova dimensione della zona di memoria è sufficientemente larga da non occupare un'altra zona di memoria attualmente
allocata ed adiacente a quella vecchia. Allora, il sistema operativo provvederà ad aumentarne le dimensioni, restituendo
come risultato lo stesso puntatore, senza, tuttavia, ripulire la vecchia zona di memoria.

Tuttavia, se la nuova dimensione da allocare è tale da invadere lo spazio di un'altra zona di memoria attualmente
occupata. Allora, analizzando lo Heap, si troverà una zona di memoria sufficientemente grande da poter
essere usata dal programma. Di conseguenza, il puntatore cambierà, riferendosi alla nuova zona di memoria. Sebbene
`realloc` ha il vantaggio di poter "riciclare" la memoria, aumentando o diminuendo le dimensioni di una zona
precedentemente occupata. Ciò nonostante, non è in grado come `calloc` di ripulire lo spazio precedentemente allocato,
quindi, qualcuno potrebbe avere accesso a dati _"sporchi"_, nel momento in cui la vecchia zona sia nuovamente assegnata
dal compilatore.

## Problemi di Sicurezza <a id="security"></a>

Affrontiamo, adesso, i problemi di sicurezza con i quali ci si deve interfacciare nella gestione dinamica della memoria
in C. Come abbiamo detto nella sezione in cui abbiamo parlato della funzione `free`, nel momento in cui si alloca uno
spazio di memoria nello Heap, vengono inseriti dei meta-dati, che descrivono al compilatore cosa deve aspettarsi
nell'area di memoria che segue.

Consideriamo il seguente esempio:

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main (const int argc, const char** argv)
{
    size_t vector_size      = 100;
    size_t vector_type_size = sizeof(uint8_t);
    uint8_t* vector         = (uint8_t*)calloc(vector_size, vector_type_size);

    printf("\t[BEFORE free()] -> vector = %p\n", vector);

    free(vector);

    printf("\t[AFTER free()] --> vector = %p\n", vector);

    return 0;
}
```

Dopo la chiamata alla funzione free, il puntatore memorizzato all'interno della variabile vector, rimane sempre valido,
e punta sempre alla stessa area di memoria. Cosa accade, allora se invochiamo nuovamente la funzione free sullo stesso
puntatore, che si riferisce ad un'area di memoria già segnalata come allocabile? Sicuramente, verrà sollevato un'errore,
e probabilmente l'errore sarà simile a questo:

> malloc: \* error for object 0x600003fac000: pointer being freed was not allocate

Andando nel dettaglio, quello che accade è questo:

1. Il gestore della memoria della libreria standard, _glibc_, controlla i meta-dati che sono inseriti all'interno
   dell'area di memoria puntata dal puntatore vector.
2. Dall'analisi dei meta-dati, sembra che l'area di memoria sia già stata liberata, precedentemente.
3. Per prevenire eventuali corruzioni alla memoria, il gestore della memoria preferisce terminare il programma con un
   codice di errore.

Questo è un comportamento comune, atto a prevenire accessi illegali a porzioni di memoria non attualmente sotto il
controllo del gestore stesso della memoria. Ad ogni modo, abbiamo detto che la stessa area precedentemente usata,
potrebbe contenere ancora dei residui dal precedente utilizzo, qualora non pulita correttamente dopo il vecchio
utilizzatore, o prima della consegna al nuovo utilizzatore.
