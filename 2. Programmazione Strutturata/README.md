- [Programmazione Strutturata](#programmazione-strutturata)
- [Istruzione e Blocchi](#istruzioni-blocchi)
- [Salti con `goto`](#goto)
- [Rami condizionali e `if-else`](#if-else)
- [Multi Condizioni con `switch`](#multi-condizioni)
- [Costrutti Iterativi](#costrutti-iterativi)
    - [Fintantochè, fai qualcosa `while`](#while)
    - [Fai qualcosa, fintantochè `do-while`](#do-while)
    - [Per tutte le volte `for`](#for)
    - [Interruzione dell'iteazione corrente `break` e `continue`](#break-continue)

# Programmazione Strutturata <a name="programmazione-strutturata"></a>

Ad oggi la presenza di costrutti per la modifica del flusso di controllo, come `if-then-else`, `while`, `do-while`, e
tutti i loro derivati, è un concetto scontato per molti linguaggi di programmazione. Agli inizi degli anni 60, tuttavia,
questo non lo era affatto. Infatti, tutti queste strutture di controllo non erano ancora state teorizzate e/o
implementate, l'unico modo con il quale era possibile ricorrere, per modificare il normale flusso di controllo del
programma, era il costrutto `goto`. 

L'uso indiscriminato di salti all'interno di un programma, tuttavia, non sempre conduceva a situazioni gradevoli,
sopratutto per chi doveva occuparsi di leggere il codice e capire cosa stava accadendo. Fu così che nel 1968, in una
lettera alla redazione di CACM (Communications of the Association for Computing Machinery) intitolata _Go To Statement
Considered Harmful_, il professore [Edsger Dijkstra](https://en.wikipedia.org/wiki/Edsger_W._Dijkstra) dimostrò come
l'uso indiscriminato dei costrutti `goto` fosse dannoso per i programmatori stessi. Successivamente, fu possibile
individuare dei pattern ricorrenti all'interno dell'uso del `goto` che descrivevano delle specifiche strutture di
controllo, che vennero descritte come `if/then/else` ed infine `do/while`. Dalla lettera di Dijkstra, nacque, quindi,
la __Programmazione Strutturata__.

# Istruzioni e Blocchi <a name="istruzioni-blocchi"></a>

Prima di partire con la definizione di tutti i costrutti che modificano il flusso del controllo di un programma,
definiamo alcuni concetti teorici. Abbaimo visto che la combinazione di operatori e dichiarazioni formano delle
espressioni. Delle espressioni che terminano con il carattere `;` sono dette __istruzioni__. Tra loro, le istruzioni
posso essere raggruppate formando dei __blocchi__.

Più o meno, possiamo dire che un blocco non è altro che un'istruzione di grandi dimensioni. Per creare un blocco di
codice, è sufficiente raggruppare delle istruzioni all'interno di `{}`, come nell'esempio seguente:

```c
int main (int argc, const char** argv)
{
    {
        unsigned short int random_variable = 1;
        printf("This is my first block, having variable %u", random_variable);
    }

    return 0;
}
```

Introducendo i blocchi, dobbiamo fare una precisazione sulle variabili. A ciascuna variabile viene assegnato quello che
in teoria è chiamato __scope__, ossia: la visibilità di una variabile all'interno di un blocco. Le variabili definite
all'interno di un blocco, sono chiamate __variabili locali__, mentre, quelle definite fuori da qualsiasi blocco, sono
chiamate __variabili globali__. E' bene sapere che le variabili globali saranno visibili in tutte le parti del codice,
mentre, quelle locali solamente all'interno del blocco corrente.

# Salti con `goto` <a name="goto"></a>

`goto` è probabilmente il primo costrutto nativo che permette di modificare il normale flusso di controllo sequenziale
del codice. In linea generale, il suo funzionamento è relativamente semplice: associo ad un blocco o ad un'istruzione
un'__etichetta__; e quando voglio saltare dal punto A al punto B definito dall'etichetta precedente, è sufficiente usare
l'istruzione `goto <etichetta>`. Vediamo in pratica questo costrutto a lavoro:

```c
int main (int argc, const char** argv)
{
    printf("Process started ...");
    goto success;

    success: {
         printf("Process completed!");
         return 0;
    }

    error: {
       printf("Process failed!");
       return -1;
    }

   return 0;
}
```

il funzionamento è relativamente semplice: a due blocchi di codici diversi, sono associate le etichette `success` e
`error`; dopo aver avviato il processo, l'istruzione `goto success` salta direttamente al blocco associato all'etichetta
`success`, eseguendone il contenuto e terminando l'esecuzione del programma con l'istruzione `return 0`.

Un'applicazione interessante di questo costrutto, potrebbe essere proprio la gestione degli errori e delle eccezioni,
che vedremo più avanti. Tuttavia, la comprensione di codice contenente il costrutto `goto`, risulta molto ostia a chi
deve leggerlo e comprenderlo. Di conseguenza, sebbene sia comunque un costrutto disponibile per la maggior parte dei
linguaggi, il suo utilizzo è sconsigliato. L'alternativa è utilizzare il resto dei costrutti che vedremo, con
l'accortezza di rendere il codice più leggibile.

# Rami condizionali e `if-else` <a name="if-else"></a>

Procediamo, adesso, con la descrizione del costrutto più fondamentale, che permette di eseguire condizionatamente
blocchi e/o istruzioni, sulla base di un'espressione numerica, ossia: il costrutto `if-else`. In termini generali,
questo si presenta sotto questa forma:

```c
if (<espressione>) 
    <istruzione> / <blocco>
else 
    <istruzione> / <blocco>
```

Analizziamo questa descizione, introducendo l'espressione sulla quale si valuta quale dei due rami della computazione
scegliere. Ricordiamo che un'espressione è un'istruzione senza l'uso del simbolo `;`. La cosa fondamentale è che
l'espressione in questione, deve essere un valore numerico. Se il valore numerico restituito dalla valutazione
dell'espressione è uguale a `0`, allora si asserirà che l'espressione sia falsa, e si procederà con la valutazione
dell'istruzione o del blocco associato alla parola `else`; altrimenti, per qualsiasi numero diverso da `0`, che sia
positivo o negativo, si procederà con la valutazione del ramo subito sotto la parola `if`.

```c
int main (int argc, const char** argv) 
{
    unsigned short int first_variable = 0;
    unsigned short int second_variable = 1;

    if (first_variable * second_variable == 0) {
        printf("I'm inside the block below the 'if' keyword\n");
    } else {
        printf("I'm below the block described by the 'else' keyword\n");
    }

    return 0;
}
```

In questo caso, essendo che l'espressione `first_variable * second_variable` restituisce come risultato `0`, e che il
confronto tra `0` e `0`, mediante l'operatore `==`, restituisce come risultato `1`; allora, verrà eseguito il blocco di
codice immediatamente sotto l'espressione stessa.

La cosa che non dovrebbe stupirci, è che il costrutto stesso `if-else` è un'istruzione. Di conseguenza, sarebbe logico
poter inserire all'interno di un ramo stesso dell'istruzione, un altro ramo condizionale `if-else`, esattamente come
accade in questo modo:

```c
int main (int argc, const char** argv) 
{
    unsigned short int first_variable = 0;
    unsigned short int second_variable = 1;

    if (first_variable * second_variable == 0) {
        printf("I'm inside the block below the 'if' keyword\n");
    } else {
        if (first_variable == 0) {
            printf("I'm inside the block below the 'if' keyword, below the first 'else' keyword\n");
        } else {
            printf("I'm inside the block below the 'else' keyword, below the first 'else' keyword\n");
        }
    }

    return 0;
}
```

In termini semplici, possiamo descrivere in questo modo la struttura appena vista: 

> Se il risultato di `first_variable * second_variable` è un valore uguale a `0`, allora procedi con l'esecuzione del
> blocco immediatamente sotto; altrimento, se il valore di `first_variable` è uguale a `0`, allora procedi con
> l'esecuzione del blocco immediatamente sotto; altrimenti, esegui l'ultimo blocco di sotto la parola chiave iniziale `else`.

Adesso, c'è una considerazione importante da fare riguardo il costrutto `if-else`. Come possiamo evincere, analizzando
la sintassi di questo, a ciascuna parola `if` o `else`, deve corrispondere necessariamente un'istruzione, oppure, un
blocco, qualora ci siano diverse istruzioni da dover eseguire. Considerando questo esempio, dunque:

```c
unsigned char first_char = 1;
unsigned char second_char = 2;

if (first_char + second_char == 3)
    printf("first_char + second_char == 3\n");
    if (first_char == 2)
        printf("first_char == 2\n");
else 
    printf("first_char + second_char != 3\n");
```

Analizzando l'indentazione, ad una prima vista ci sembrerebbe che venisse visualizzato solamente il messaggio
`first_char + second_char == 3`. In realtà, verrà visualizzato il messaggio `first_char + second_char != 3`. La ragione
dietro questo comportamento apparentemente anomalo, è proprio nell'associazione dell'istruzione caratterizzata dalla
parola `else` all'istruzione associato alla parola chiave `if` immediatamente più vicina. 

Di conseguenza, possiamo dire che: sebbene sia possibile associare una sola istruzione a ciascuna parola chiave `if` o
`else`, è sembre bene che questa istruzione sia inclusa in un blocco, prevenendo qualsiasi comportamento anomalo, dato
da errate indentazioni e/o allineamenti. 

Se avessimo scritto il codice precedente, tenendo conto delle considerazioni appena fatte, questo risulterebbe essere in
realtà più comprensibile, senza far nascere eventuali comportamenti anomali:

```c
if (first_char + second_char == 3) {
    printf("first_char + second_char == 3\n");
    if (first_char == 2) {
        printf("first_char == 2\n");
    }
} else {
    printf("first_char + second_char != 3\n");
}
```

# Multi Condizioni con `switch` <a name="multi-condizioni"></a> 

Esiste, tuttavia, un'abbreviazione che ci permette di evitare di scrivere diverse condizioni anche annidati, basate sul
costrutto `if-else`. L'abbreviazione in questione è definita dalla parola chiave `switch`, e viene descritta in questa
maniera:

```c
switch (<espressione_0>) 
    case <espressione_1>:
        <istruzione_1> / <blocco_1>
    case <espressione_2>:
        <istruzione_2> / <blocco_2>
    default:
        <istruzione_0> / <blocco_0>
```

Questo costrutto è completamente analogo alla corrispondente istruzione `if-else` seguente:

```c
if (<espressione_0> == <espressione_1>) 
    <istruzione_1> / <blocco_1>
else if (<espressione_0> == <espressione_2>) 
    <istruzione_2> / <blocco_2>
else 
    <istruzione_0> / <blocco_0>
```

# Costrutti iterativi <a name="costrutti-iterativi"></a>

I costrutti iterativi permettono di eseguire ripetizioni di blocchi di codice o di singole istruzioni, sulla base di una
variabile chiamata contatore, ed una condizione da valutare a ciascuna iterazione. I costrutti iterativi comuni a quasi
tutti i linguaggi di programmazione sono: `while`, `do-while` e `for`. Altri costrutti sono in realtà dei derivati di
combinazioni di questi. 

Partiamo però riflettendo come sia possibile eseguire un'iterazione, senza l'uso di uno di questi costrutti, ma
solamente con l'istruzione di salto `goto`. Infatti, come venne dimostrato dal [Teorema di Bohm-Jacopini](https://it.wikipedia.org/wiki/Teorema_di_B%C3%B6hm-Jacopini), usando un'adeguata combinazione di salti e condizioni, è possibile creare un costrutto iterativo. 
Considerando il seguente esempio, infatti:

```c
unsigned short int counter = 0;

condition: {
    if (counter < 10) { 
        goto body;
    } else {
        goto rest;
    }
}

body: {
    printf("i'm doing something using counter = %u\n", counter);
    counter++;
    goto condition;
}

rest: {
    printf("i'm out of the iteration\n");
}
```

Questo esempio grezzo di un costrutto iterativo, è una dimostrazione in breve di come siano necessarie alcune parti
fondamentali, affinché si possa realizzate un'iterazione nel nostro programma. In breve, sono necessari i seguenti
elementi:

1. Una variabile __contatore__ che permetta di riconoscere a quale iterazione corrente ci si trovi.
2. Una __condizione__ che verifichi se sia necessario continuare con l'iterazione.
3. Un blocco o una singola istruzione, che rappresenta un __corpo__ da eseguire per ciascuna iterazione.
4. Un __incremento__ che permetta di passare all'iterazione successiva.

Nel nostro caso, l'espressione `counter < 10` è la condizione; la variabile `counter` è il contatore; l'incremento è
rappresentato dall'istruzione `counter++`; infine, il corpo del nostro costrutto è rappresentato dal blocco identificato
dall'etichetta `body`. 

Tuttavia, è facile capire il motivo per cui è stata teorizzata la Programmazione Strutturata. Non è per nulla semplice
comprendere che ci si trovi all'interno di un ciclo, usando solamente un costrutto `goto`.

## Fintantochè, allora fai qualcosa `while` <a name="while"></a>

Il primo costrutto iterativo che vediamo, ed anche quello più semplice, è identificato solamente dalla parola chiave
`while`. Considerando i componenti che abbiamo elencato precedentemente, in congiunzione con questa parola chiave,
devono esserci gli stessi elementi. Ad esempio, consideriamo un esempio in cui, si vuole visualizzare in maniera
incrementale i numeri da uno a dieci. Possiamo realizzare questo piccolo programma in questo modo:

```c
unsigned short int counter = 0;

while (counter < 10) {
    printf("counter = %u\n", counter);
    counter++;
}
```

## Fai qualcosa, fintantochè `do-while` <a name="do-while"></a>

Dall'esempio precedente, possiamo invece considerare una variante in cui il corpo viene eseguito almeno una volta.
Questa variante, prevede l'introduzione di un'altra parola chiave, ossia: `do`. Riscriviamo lo stesso esempio di prima
con questa nuova variabile:

```c
unsigned short int counter = 0;

do {
    printf("counter = %u\n", counter);
    counter++;
} while (counter < 10);
```

## Per tutte le volte `for` <a name="for"></a>

Infine, l'ultimo costrutto iterativo è una versione sintatticamente più compatta rispetto a quelle precedenti. Lo scopo
di questo costrutto è quello di raggruppare all'interno di un unico punto: l'inizializzazione del contatore; la
condizione di ciclo; ed infine l'incremento del contatore stesso. Usando la parola chiave `for` possiamo realizzare
questo nuovo questo costrutto iterativo:

```c
for (unsigned short int counter = 0; counter < 10; counter++) {
    printf("counter = %u\n", counter);
}
```

A proposito di quest'ultimo costrutto c'è da fare una considerazione. Prima della versione `C99` non era concesso
inizializzare la variabile contatore direttamente all'interno del ciclo for. La sintassi precedente, dunque, sarebbe
stata illegate, e sarebbe risultato necessario, invece, apportare le seguenti modifiche:

```c
unsigned short int counter = 0;

for (counter = 0; counter < 10; counter++) {
    printf("counter = %u\n", counter);
}
```

## Interruzione dell'iterazione corrente con `break` e `continue` <a name="break-continue"></a>

Prima di concludere questo capitolo, vediamo due parole chiave che sono spesso utilizzati nei costrutti iterativi,
rispettivamente `break` e `continue`. Spesso, infatti, durante un'iterazione, può essere necessario interrompere
l'iterazione oppure passare a quella successiva, in quanto si è verificata una specifica condizione.

Pensiamo, ad esempio, ad un algoritmo di ricerca, quando abbiamo trovato l'elemento che ci interessa, non è più
necessario continuare a cercare, quindi, possiamo interrompere il ciclo di ricerca che siamo eseguendo. Oppure,
potremmo direttamente saltare all'iterazione successiva, nel momento in cui stiamo visualizzando solamente gli elementi
pari di un contatore.

Considerando i due esempi precedenti, implementiamo queste iterazioni, utilizzando le parole chiave `break` e
`continue`:

```c
for (unsigned short int counter = 0; counter < 10; counter++) {
    if (counter == 3) {
        printf ("I found the element %u!\n", counter);
        break;
    }
}

for (unsigned short int counter = 0; counter < 10; counter++) {
    if (counter % 2 == 0) {
        printf("The element %u is even!\n", counter);
    } else {
        continue;
    }
}
```

Un'ultima considerazione a riguardo, è stato possibile riutilizzare una variabile con lo stesso nome `counter`,
solamente perché questa è stata inizializzata ed utilizzata all'interno di due cicli diversi. Quando, infatti, si
inizializza una variabile all'interno di un ciclo `for`, una volta terminato il ciclo quella variabile verrà
automaticamente distrutta, di conseguenza, sarà possibile ricreare una nuova variabile con lo stesso nome, in quanto non
ci saranno conflitti tra i nomi.
