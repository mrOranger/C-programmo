- [Preprocessore del C](#preprocessor)
    - [Direttive per Includere File](#preprocesor-file-inclusion)
    - [Direttive per Dichiarare Costanti](#preprocessor-constants)
    - [Direttive per Compilazione Condizionale](#preprocessor-conditional)

# Preprocessore del C <a id="preprocessor"></a>

Il C fornisce una serie aggiunta di funzionalità, grazie all'uso di un preprocessore, che di fatto inserisce un passo
aggiuntivo al processo di compilazione, prima della creazione del file sorgente. In passato abbiamo già usato delle
dichiarazioni che in realtà erano delle direttive usate direttamente dal preprocessore, come:

```c
#include <stdio.h>
#define MAX_LEGTH 100
```

In generale, le direttive più importanti sono due, ed usate per questi scopi:

* Includere il contenuto di un file all'interno di un altro. La direttiva `#include <stdio.h>` non fa altro che copiare
  il contenuto del file `stdio.h` della libreria standard C, all'interno del file in cui è definita la direttiva stessa;

* Definire espressioni anche complesse, come ad esempio: `#define MAX_LENGTH 100` che definisce una costante
  `MAX_LENGTH` che sarà inclusa e visibile all'interno del file in cui è usata la direttiva;

## Direttive per Includere File <a id="preprocessor-file-inclusion"></a>

L'inclusione di un file sorgente all'interno di un altro, può essere eseguito mediante la direttiva `#include`. Negli
esempi precedenti, abbiamo, tuttavia, visto l'uso in due diverse modalità di questa direttiva:

* L'uso mediante parentesi angolari, come `#include <stdio.g>`;
* L'uso mediante le doppie virgolette, come `#include "libs/string/string.h";

La differenza tra queste due sintassi risiede nella posizione del file sorgente all'interno del nostro programma.
Tipicamente, solamente i file della libreria standard sono importabili mediante parentesi angolari. Alternativamente, le
"normali" istruzioni `#include` permettono di importare un qualsiasi file al di fuori della libreria standard. 

Nel caricamento di un file sorgente normale, il percorso del file viene calcolato partendo dalla directory
corrente. Quindi, la specifica del percorso di un qualsiasi file sorgente, deve avvenire mediante la normale navigazione
all'interno del file-system del sistema operativo corrente.

## Direttive per Dichiarare Costanti <a id="preprocessor-constants"></a>

L'uso più comune del preprocessore è quello di definire delle costanti da usare nel codice sorgente. Per definire una
costante, è sufficiente usare la seguente sintassi:

```c
#define MAX_LENGTH 100
```

Da notare che è buona norma specificare i nomi delle costanti in maiuscolo. All'interno del nostro programma, adesso,
possiamo usare la costante `MAX\_LENGTH` come in questo esempio:

```c
#include <stdio.h>
#include <stdint.h>

void print_cycle () 
{
    for (uint8_t index = 0; index < MAX_LENGTH; index = index + 1)
    {
        printf("index = %d\n", index);
    }
} ```
Quello che accadrà durante il processo di compilazione è la pura sostituzione di ciascuna occorrenza di `MAX\_LENGTH`,
con il corrispondente valore associato, ossia `100`. Se l'istruzione `#define`, definisce un sinonimo per un'espressione
all'interno del nostro programma, la direttiva `#undef` annulla l'effeto una una precedente definizione.

La sostituzione di una definizione all'interno del nostro programma richiede qualche accortezza nell'uso delle stringhe.
Consideriamo lo stesso esempio precedente, con qualche modifica per il caso:

```c
void print_cycle () 
{
    for (uint8_t index = 0; index < MAX_LENGTH; index = index + 1)
    {
        printf("index = %d / MAX_LENGTH\n", index);
    }
}
```

In questo specifico esempio il valore `MAX\_LENGTH` non verrà sostituito. Una caratteristica dei valori creati tramite
la direttiva `#define` è che possono essere sostituiti valori che non siano letterali inseriti tra `"`. Per ovviare a
questo problema, è necessario usare l'operatore `#`, il quale indica quale sia correttamente il valore da sostituire.
Modificando l'esempio precedente affinché sia corretto, otteniamo il seguente codice:

```c
void print_cycle () 
{
    for (uint8_t index = 0; index < MAX_LENGTH; index = index + 1)
    {
        printf("index = %d / #MAX_LENGTH\n", index);
    }
}
```

Quello che accadrà, sarà una sostituzione al valore `#MAX\_LENGTH` di un'intera stringa, rappresentata come `"100"`
solamente successivamente, la stringa risultante verrà interpolata con il resto, ottenendo il seguente codice:

```c
void print_cycle () 
{
    for (uint8_t index = 0; index < MAX_LENGTH; index = index + 1)
    {
        printf("index = %d /" "100" "\n", index);
    }
}
```

Fino a questo punto, ci siamo limitati ad usare la direttiva `#define` per definire semplici valori. E'possibile,
tuttavia, poter definire espressioni complesse addirittura con parametri. Le espressioni subiranno la stessa fine dei
valori semplici che abbiamo visto, il preprocessore non farà altro che limitarsi a sostituire le espressioni in cui
trova le occorreze, con i relativi valori associati. 

Ad esempio, supponiamo di definire a livello di preprocessore, una funzione che sostituisca un valore con un altro:

```c
#define swap(first, second, temp) { temp = first; first = second; second = temp; }

void swap_variables(int first, int second)
{
    swap(first, second);
}
```

Durante la fase di pre-compilazione, il preprocessore non farà altro che sostituire il blocco di codice definito
attraverso l'identificativo `swap(first, second, temp)` ovunque vi sia quest'occorreza. Dobbiamo tenere a mente,
tuttavia, che la valutazione dei parametri all'interno della dichiarazione di `swap`, avviente ogni qual volta che ci
venga usato un parametro. Questo è da tenere a mente nel momento in cui si devono sostituire dichiarazioni "compatte"
come `i++`, onde evitare effetti collaterali sgradevoli.

## Direttive per Compilazione Condizionale <a id="preprocessor-conditional"></a>

Oltre che le direttive `#define` e `#undef`, esistono una serie di direttive per implementare rami condizionali. In
questo modo, possiamo indicare al preprocessore di considerare un pezzo di codice rispetto ad un altro. Un'utile
applicazione potrebbe essere quella di definire implementazioni su specifiche architetture, ad esempio a 32bit, rispetto
ad altre.

Un pratico esempio su come utilizzare questa funzionalità è stato ampiamente visto nella sezione in cui sono stati
trattati i file headers: 

```c
#ifndef TEST_H
#define TEST_H

/* Qui andrà del codice .. */

#endif
```

In questo caso, mediante l'istruzione `#ifndef` verifichiamo se l'oggetto `TEST\_H` è presente o no all'interno del file
corrente. Nel caso in cui non lo sia, si potrà procedere alla definizione del primo mediante l'istruzione `#define
TEST\_H`, e chiudere il ramo corrente con l'istruzione `#endif`.

Questo esempio mostra come il preprocessore possa essere usato per scopi di ottimizzazione. Infatti, il codice viene
considerato solamente nel caso in cui non sia stato ancora caricato in memoria, ossia, nel caso in cui nessuno ha ancora
importato il contenuto di questo file. Nel momento in cui il file è stato usato almeno una volta, non sarà più
necessario caricarne il contenuto nuovamente, in quando sarà già presente in memoria.
