- [Input Output](#io)
    - [Formattazione dei Dati in Uscita con `printf`](#printf)
        - [Funzioni con un Numero Variabile di Argomenti](#varargs)
    - [Formattazione dei Dati in Entrata con `scanf`](#scanf)
    - [Input Output Generalizzato](#generic-io)
    - [Lettura e Scrittura da File](#file-io)
    - [Gestione degli Errori](#exceptions)

# Input Output <a id="io"></a>

L'argomento che tratteremo adesso, riguarderà la gestione dei flussi di input ed output in C (anche detto flusso IO).
Fino a questo momento, infatti, abbiamo gestito solamente il flusso di output standard, mediante la funzione `printf`.

Un flusso di input e output è un generico canale di comunicazione, attraverso il quale passano i dati del nostro
programma. Come detto prima, il flusso standard è quello della console dalla quale è stato avviato il programma
compilato. Nulla, tuttavia, vieta che un flusso di dati sia qualcosa diverso dalla console. Un flusso alternativo
potrebbe essere un file, oppure una porta di rete del nostro dispositivo.

In questo capitolo, quindi, vedremo come manipolare generalmente un flusso di input output, e vedremo l'alternativa al
flusso standard, ossia: il flusso di dati su file.

## Formattazione dei Dati in Uscita con `printf` <a id="printf"></a>

La funzione `printf` permette di visualizzare i dati ricevuti in input direttamente sul flusso standard. Il primo
parametro della funzione `printf` è una stringa, contenente i dati che verranno reindirizzati sul flusso standard.
Alternativamente, è anche possibile specificare dei valori _jolly_ indicano come formattare correttamente i dati in
uscita. 

La formattazione della stringa in ingresso, avviene mediante l'uso del carattere `%`, seguito da un marcatore che indica
il tipo di dato che deve essere formattato. Una lista esaustiva dei caratteri di formattazione, è indicata dalla
seguente tabella:

| Carattere | Tipo dell'argomento | Valore Visualizzato |
| --------- | ------------------- | ------------------- |
| `%d`      | `int`               | Numero intero visualizzato con la notazione in decimale. |
| `%o`      | `unsigned int`      | Numero intero senza segno visualizzato in notazione ottale. |
| `%x`      | `unsigned int`      | Numero intero senza segno visualizzato in notazione esadecimale. |
| `%u`      | `unsigned int`      | Numero intero senza segno visualizzato con la notazione decimale. |
| `%c`      | `int`               | Singolo carattere. |
| `%s`      | `char*`             | Visualizza tutti i caratteri di una stringa stringa, fino carattere `\0`. |
| `%f`      | `double`            | Visualizza un numero con la virgola in formato `i.dddddd`. |
| `%e`      | `double`            | Visualizza un numero in virgola mobile, con l'esponente, in formato  `i.ddddddE±xx`. |
| `%p`      | `void*`             | Visualizza in formato esadecimale un indirizzo di memoria. | 

Se la funzione `printf` permette di visualizzare una stringa sullo standard output, la funzione `sprintf` permette di
reindirizzare la stringa ricevuta come input, su un diverso buffer il cui puntatore è specificato come primo parametro.
Potremmo pensare, quindi, alla funzione `sprintf` come una sorta di assegnazione, ma che non si limita ad assegnare il
valore del puntatore al primo carattere, bensì ad assegnare il valore completo della stringa ricevuta come input.

A conferma di quanto detto, consideriamo il seguente esempio:

```c
#include <stdio.h>
#include <stdlib.h>

int (const int argc, const char** argv)
{
    char* pointer_to_string = (char*)calloc(20, sizeof(char));
    sprintf(pointer_to_string, "Ciao Mondo dal Linguaggio %c!\n", 'C');
    printf("%s", pointer_to_string);
}
```

La cosa interessante di questo esempio, è l'assegnazione automatica del valore `\0` alla fine della stringa
`pointer_to_string`. Inoltre, analogamente a quanto accade per la funzione `printf`, mediante l'uso dei caratteri `%`,
possiamo controllare la formattazione delll'output, passando una lista dinamica di parametri alla funzione `sprintf`.  

### Funzioni con un Numero Variabile di Argomento <a id="varargs"></a>

E' arrivato il momento di parlare delle funzioni che ammettono un numero non ben definito di argomenti come input. Fino
a questo punto, infatti, abbiamo supposto che esista un qualcosa di sconosciuto, un meccanismo attraverso il quale sia
possibile specificare una serie di parametri alla funzione `printf`, senza che si sappia precisamente quanti e quali
argomenti questa funzione accetti.

Per implementare una funzione che accetti un numero variabile di argomenti, è necessario che vengano usate alcune
macro. Le macro in questione possiedono un'implementazione diversa a seconda dell'architettura in uso, tuttavia, una
serie di definizioni standard è presente all'interno della libreria `stdargs`.

Consideriamo il caso in cui vogliamo implementare una funzione che calcoli il numero minimo di elementi, tra quelle
registrati come parametri di una funzione. Una valida implementazione di questa funzione, potrebbe essere la seguente:

```c
#include <stdarg.h>
#include <limits.h>

int min (const int args_number, ...)
{
    va_list args;
    int minimum = INT_MAX;
    va_start(args, args_number);

    for (int index = 0; index < args_number; index = index + 1)
    {
        int current_min = va_arg(args, int);

        if (current_min < minimum)
        {
            minimum = current_min;
        }
    }

    va_end(args);

    return minimum;
}
```

Notiamo la presenza delle seguenti macro `va_list`, `va_start`, `va_arg` e `va_end`. Oltre che a queste macro, è
necessario tenere a mente che l'intestazione della funzione, richiede l'uso di `...`, per indicare che è previsto un
insime variabile di argomenti.

Le macro in questione, vengono usate al seguente scopo:

* `va_list` istanzia la lista variabile di argomenti.
* `va_start` inizializza la lista variabile di argomenti, con il numero effettivo che ci si aspetta.
* `va_arg` legge l'argomento corrente. Da notare che, la funzione richiede il tipo di argomento che è necessario leggere
  in questo momento. La funzione `printf` utilizza i marcatori inseriti all'interno della stringa da formattare, per
  determinare quale sia il tipo corrente di parametro.
* Infine, `va_end` rilascia le risorse precedentemente allocate.

## Formattazione dei Dati in Entrata con `scanf` <a id="scanf"></a>

Se la funzione `printf` visualizza una stringa, formattata seguendo delle precise istruzioni di composizione, sullo
standard output. La funzione `scanf` legge delle informazioni direttamente dallo standard input, basandosi sul formato
specifo secondo il quale queste informazioni verranno fornite. 

Questa, infatti, è la specifica della funzione `scanf` secondo la libreria standard:

```c
int scanf (const char restrict* format, ...);
```

La funzione, come si può vedere, riceve un numero variabile di argomenti. Diversamente dalla funzione `printf`, è
necessario che questo numero variabile di argomenti siano tutti quanti dei puntatori. Infatti, i puntatori verranno
usati per inserire all'interno delle variabili puntate, i valori estratti dalla stringa che ne specifica la
formattazione.

In maniera del tutto simile, la stringa che specifica la formattazione della stringa proveniente dallo standard input,
utilizza una serie di caratteri speciali, tutti dei quali preceduti dal carattere `%`, ed a cui possiamo rifarci
leggendo la tabella precedentemente descritta per la funzione `printf`.

Ad esempio, volendo leggere la data corrente in formato `dd/mm/yyyy`, e specificata dall'utente usando lo standard
input, possiamo utilizzare in questo modo la funzione `scanf`:

```c
#include <stdio.h>
#include <stdint.h>

int main (const int argc, const char** argv)
{
    uint32_t day, month, year;

    printf("Inserisci la data corrente in formato dd/mm/yyyy: ");
    scanf("%u/%u/%u", &day, &month, &year);
    printf("Il giorno corrente è: %u/%u/%u\n", day, month, year);
}
```

Così come accade per la funzione `printf`, la quale possiede l'alternativa `sprintf`. Anche per la funzione `scanf`
esiste la controparte `sscanf`, la quale, inserirà i dati estratti dallo standard input, ed accuratamente formattati,
all'interno di una stringa. Possiamo modificare l'esempio precedente, inserendo la stringa estratta da
quest'elaborazione, all'interno di un'altra stringa, e visualizzarne il contenuto:

```c
#include <stdio.h>
#include <stdint.h>

int main (const int argc, const char** argv)
{
    char* current_date = (char*)calloc(20, sizeof(char));
    uint32_t day, month, year;

    current_date = "26/12/2025";
    sscanf(current_date, "%u/%u/%u", &day, &month, &year);
    printf("Il giorno corrente è: %u/%u/%u\n", day, month, year);
}
```

## Input Output Generalizzato <a id="generic-io"></a>

Siamo adesso giunti alla trattazione dell'argomento file. Fino a questo punto, infatti, le operazioni di lettura e
scrittura hanno coinvolto solamente lo standard input e lo standard output. Non deve stupirci, quindi, che le medesime
operazioni sono comunque valide per un file.

Quando viene avviato un programma in C, di default, la libreria standard apre tre tipi diversi di flussi per l'input e
l'output , restituendone i relativi puntatori che possono essere usati in tutto il programma. Questi tre flussi sono:

* Lo __standard input__ utilizzabile mediante l'oggetto `stdin`;
* Lo __standard output__ utilizzabile mediante l'oggetto `stdout`;
* Infine, lo __standard error__, meno conosciuto rispetto agli altri, ma utilizzabile con l'oggetto `stderr`.

Nell'implementazione della libreria standard, si è deciso di dedicare un flusso separato alla gestione degli errori. Con
la conseguenza di aver implementato un flusso denominato `stderr`. La trattazione di questo flusso, verrà fatta nel
paragrafo successivo.

L'idea di trattare i flussi di I/O esattamente come se fossero dei file, deriva dall'approccio UNIX-like con il quale è
stata sviluppata la libreria standard del C. Non dovrà stupirci che le seguenti funzioni verranno usate in maniera
simile per scrivere su un file:

```c
#include <stdio.h>

int main (const int argc, const char** argv)
{
    uint8_t random_integer;

    fprintf(stdout, "Sto scrivendo sullo standard output, mediante la funzione 'fprintf': \n");
    fscanf(stdin, "%u", &random_integer);

    printf("Sto scrivendo sullo standard output, mediante la funzione 'printf': \n");
    scanf("%u", &random_integer);

    return 0;
}
```

La differenza tra le funzioni `fprintf` - `printf` e `fscanf` - `scanf`, consiste solamente nella capacità delle prime
di reindirizzare le operazioni di input-output verso uno specifico flusso di dati. Vedremo come per scrivere e/o leggere
su un file, sarà sufficiente usare le medesime funzioni ma specificando un puntatore diverso da `stdin` e `stdout`.

## Lettura e Scrittura da File <a id="file-io"></a>

Adesso che abbiamo capito che un flusso di I/O è trattabile esattamente come se fosse un flusso verso un file. Possiamo
procedere alla descrizione della procedura con la quale viene aperto un canale di comunicazione verso il file, e come è
possibile eseguire delle operazioni su questo.

Prima di mostrare le operazioni di lettura e scrittura da file, è necessario sapere che il processo è preceduto da delle
operazioni preliminari, da eseguire in sequenza per permette al sistema operativo di aprire e chiudere correttamente un
file.

La prima cosa di cui abbiamo bisogno è un puntatore alla struttura `FILE` definita all'interno della libreria
`stdio.h`. Questo puntatore viene usato dalle funzioni che vedremo di seguito, per leggere, scrivere e permettere alla
libreria standard di leggere i meta-dati che permettono di eseguire correttamente le operazioni elencate prima.

Una volta ottenuto questo puntatore, il passo successivo è richiedere al sistema operativo di aprire il file in
questione. L'operazione di apertura è eseguita dalla funzione `fopen` (File Open), la cui intestazione è descritta dalla
libreria standard come:

```c
FILE* fopen (const char* restrict path, const char* restrict mode);
```

Questa funzione richiede il percorso del file che si vuole aprire, e la modalità con la quale si vuole aprire il file in
questione. Le modalità elencate dalla libreria standard sono le seguenti:

* `r` (Read) apre il file in modalità sola lettura.
* `w` (Write) apre il file in modalità lettura-scrittura.
* `a` (Append) apre il file in modalità di scrittura, spostando il cursore alla fine del file.

Come possiamo notare, la funzione restituisce un puntatore ad una struttura `FILE`, la quale potrà essere usata per le
operazioni da eseguire sul file in questione. Tuttavia, potrebbero sorgere dei problemi all'apertura del file,
sopratutto quando un altro processo ha già aperto il file e sta eseguendo delle operazioni su questo. In caso di errore,
fortunatamente, viene restituito `NULL`. Dunque, è buona norma controllare che il puntatore sia valido, prima di
eseguire qualsiasi operazioni, onde evitare di incorrere in eccezioni non controllate. Nel caso in cui il file non
esista, fortunatamente, esso viene creato, avente dei permessi coerenti con quelli specificati durante l'operazione di
apertura.

Una volta che il file è stato aperto correttamente, si può procedere con le operazioni di lettura e scrittura. Queste
operazioni sono eseguite su un file mediante un puntatore specifico, il quale viene di volta in volta spostato al
carattere o alla riga successiva. Le operazioni più semplici sono:

* `int getc(FILE* fp)`, che legge il byte puntato, e facendo avanzare il puntatore di un byte, al carattere successivo.
* `int putc(int value, FILE* fp)` che scrive il carattere `value` sul puntatore corrente, restituendo il carattere
  scritto, ed avanzando il puntatore di un byte, puntato al carattere successivo.

Ad esempio, supponiamo di voler scrivere una stringa su un file specifico. Potremmo implementare questo programma in
questo modo:

```c
uint8_t write_file (const char* path, const char* string)
{
    FILE* file_pointer = fopen(path, "a");
    uint8_t written_chars = 0;

    if (file_pointer == NULL)
    {
        fprintf(stderr, "Cannot open file %s\n", path);
        return written_chars;
    }

    for (uint8_t index = 0; string[index] != '\0'; index++) 
    {
        int current_written_chars = putc(string[index], file_pointer);

        if (current_written_chars > 0) 
        {
            written_chars = written_chars + 1;
        }
    }

    return written_chars;
}
```

L'esempio è relativamente semplice, e come possiamo notare, segue lo schema che abbiamo definito. Per prima cosa bisogna
usare la funzione `fopen` per aprire il file, controllare che questo non sia `NULL` ed in questo caso, usare la modalità
`a` per indicare che vogliamo scrivere in modalità append. Successivamente, usiamo la funzione `putc` per scrivere un
carattere sul file corrente.

Tuttavia, manca una prima e fondamentale parte, ossia: il processo di chiusura del file. Nei sistemi UNIX è permesso
solamente ad un processo alla volta di accedere al contenuto di un file. Fortunatamente, qualora il processo che sta
eseguendo qualche operazione su un file, venisse terminato, automaticamente viene indicato al sistema operativo che il
file può essere letto o scritto da un altro processo. Per garantire che non ci siano situazioni di stallo, dovute a
processi ancora attivi, che non hanno rilasciato le risorse usate per il file, o che non hanno segnalato al sistema
operativo che il file è disponibile per altre operazioni, è necessario invocare la funzione `fclose`. 

Sulla base dell'intestazione della funzione `fclose`:

```c
int fclose(FILE* fp);
```

Questa funzione richiede il puntatore alla struttura `FILE`, e restituisce il valore `0` qualora l'operazione di
chiusura è andata a buon file, altrimenti, un valore diverso da `0` indica che si è verificato qualche problema nella
chiusura del file.

Possiamo, quindi, correggere l'esempio precedente inserendo l'operazione di chiusura e di verifica:

```
uint8_t safe_write_file (const char* path, const char* string)
{
    FILE* file_pointer = fopen(path, "a");
    uint8_t written_chars = 0;

    if (file_pointer == NULL)
    {
        fprintf(stderr, "Cannot open file %s\n", path);
        return 0;
    }

    for (uint8_t index = 0; string[index] != '\0'; index++) 
    {
        int current_written_chars = putc(string[index], file_pointer);

        if (current_written_chars > 0) 
        {
            written_chars = written_chars + 1;
        }
    }

    int close_flag = fclose(file_pointer);

    if (close_flag != 0) 
    {
        fprintf(stderr, "Cannot close file %s\n", path);
        return 0;
    }

    return written_chars;
}
```

## Gestione delle Eccezioni <a id="exceptions"></a>
