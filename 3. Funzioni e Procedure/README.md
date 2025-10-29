# Le Funzioni e le Procedure

Fino a questo momento, abbiamo definito tutte le operazioni all'interno di un unico programma, ossia: la funzione
`main`. In una realtà operativa, tuttavia, sarebbe impensabile definire un intero software solo ed esclusivamente
all'interno di questa funzione. Se così fosse, oltre che difficilmente navigabile, sarebbe anche pieno di codice
ripetuto, e di conseguenza poco ottimizzato. Il nostro scopo, quindi, deve essere quello di separare blocchi di codice
che eseguono delle specifiche operazioni, favorendone quella che viene chiamata _modularità_. 

I blocchi di codice che verranno così creati prenderanno il nome, a seconda della loro natura, di __funzioni__ oppure
__procedure__. Una funzione è un blocco di codice che produce un output. Diversamente, una procedura è un blocco di
codice che non produce nessun output, ma esegue solamente una determinata computazione.

Che sia una funzione o una procedura, entrambe queste entità devono essere identificate all'interno del nostro
programma, e ciò avviene assegnandole un nome. Essendo quindi il nome un identificativo univoco, non possono esistere
funzioni o procedure con nomi duplicati. Inoltre, possiamo dichiarare che una funzione o una procedura possiede delle
variabili provenienti dall'esterno di loro stesse. Queste variabili "esterne", prendono il nome di __parametri__, i
quali devono possedere un loro tipo, e non esiste un numero massimo di parametri che una funzione o una procedura
possieda.

Vediamo, adesso, due esempi: il primo è una funzione che data due numeri interi, restituisce la somma di questi; il
secondo, è una semplice procedura che stampa il nome ed il cognome di una persona:

```c
int sum (int first_number, int second_number)
{
    return first_number + second_number;
}

void print_name (char* first_name, char* last_name)
{
    printf("%s %s\n", first_name, last_name);
}
```

Da questi esempi, possiamo ricavare lo schema generale che definisce una funzione o una procedura:

```c
<valore-restituito> <nome-funzione> ( <elenco-parametri> )
    <corpo-funzione>
```

* `<valore-restituito>` è il tipo di dato che verrà prodotto in output da una funzione. Per le procedure, questo
  coincide con il tipo `void`, ossia: nessun dato restituito; di conseguenza, non sarà possibile associare,
  eventualmente, il risultato di una procedura ad una variabile;

* `<nome-funzione>` è l'identificato univoco della funzione o della procedura. E'importante che questi identificativi
  non vengano ripetuti all'interno del programma.

* `<elenco-parametri>` rappresenta l'elenco delle variabili che possono essere fornite come input alla funzione o alla
  procedura; è buona norma, nella dichiarazione del prototipo di una di queste, specificare oltre che al tipo, il
  relativo nome, per documentare meglio i parametri e la loro utilità.
j
* Infine, `<corpo-funzione>` è il blocco di codice associato alla funzione, e che ne rappresenta i passaggi
  computazionali di questa.

## Ricorsione e Iterazione

Supponiamo di voler creare una funzione che calcoli il fattoriale di un numero intero positivo. Una prima versione di
questa implementazione potrebbe essere la seguente:

```c
unsigned long int iterative_factorial (unsigned short int number)
{
    unsigned long int starting_number = 1;

    for (unsigned short int index = 1; index <= number; index++)
    {
        starting_number = starting_number * index;
    }

    return starting_number;
}
```

Tuttavia, se prestiamo attenzione alla definizione matematica di funzione fattoriale, questa si presenta nella seguente
forma: 

$$
f(x) = \begin{cases} 1 & \text{se } x = 0 \\ f(x-1) \cdot x & \text{se } x > 0 \end{cases}
$$

La quale rappresentazione, sembra molto più compatta e semplice da interpretare rispetto alla sua contro parte
iterativa. Esiste, quindi, un modo per rappresentare una funzione usando se stessa? La risposta è si, e prende il nome
di `ricorsione`:

```c
unsigned long int recursive_factorial (unsigned short int number)
{
    if (number == 0)
    {
        return 1;
    }

    return number * recursive_factorial(number - 1);
}
```

Come possiamo notare, la funzione richiama se stessa, in questo modo, si verrà a creare una catena di chiamate, la quale
terminerà con il valore 1, nel momento in cui il parametro `number` registrerà valore pari a `0`. Quello che accade in
memoria, consisterà nell'inserimento in sequenza di una serie di chiamate alla funzione `recursive_factorial`. Al
termine di queste chiamate, in cima allo stack, sarà presente la funzione avente come parametro `number = 0`, la quale
restituirà il valore `1`. Una volta che quest'ultima funzione verrà eseguita, il sistema operativo comincerà a
rimuovere, una dopo l'altra, le funzioni inserite nello stack, fintantoché il controllo non verrà restituito alla prima
versione, ossia quella che abbiamo invocato, avente come parametro il valore `number = 10`.

<u>Abbiamo quindi due versioni con cui realizzare una stessa funzione, come scegliamo una versione rispetto ad un'altra?</u> La risposta può essere data dall'analisi delle affermazioni precedenti, e che possiamo riassumere come:

* La versione ricorsiva è più semplice e coincisa rispetto alla versione ricorsiva.
* La versione iterativa richiede meno sforzo computazionale rispetto alla contro parte ricorsiva, data la mancanza dei
  ripetuti inserimenti della funzione all'interno dello stack.

La scelta di una versione rispetto ad un'altra, è completamente a carico del programmatore, il quale ne deve valutare
correttamente i pregi ed i difetti. In futuro, vedremo come spesso, invece, la funzione ricorsiva permette di definire
meglio degli algoritmi rispetto alla stessa versione iterativa.
