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

## Direttive per Dichiarare Costanti <a id="preprocessor-constants"></a>

## Direttive per Compilazione Condizionale <a id="preprocessor-conditional"></a>
