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
}
```

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

## Direttive per Compilazione Condizionale <a id="preprocessor-conditional"></a>
