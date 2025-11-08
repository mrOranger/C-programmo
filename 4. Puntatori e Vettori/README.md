# Puntatori e Vettori

Siamo arrivati nella parte forse più complicata di questo linguaggio. Il fatto che il C sia un linguaggio a basso
livello, ci permette di accedere a funzionalità e concetti vicini al dispositivo sul quale un programma in C sta venendo
eseguito. Tra le varie funzionalità a "basso livello" è inclusa la diretta manipolazione della memoria.

Prima di iniziare a descrivere come sia possibile manipolare direttamente la memoria del nostro programma, è necessario
fare un excursus sulla gestione globale delle memoria nei più moderni calcolatori elettronici. Per prima cosa, è
necessario ricordare che la memoria è organizzata in __celle__, ciascuna delle quali possiede un __indirizzo__ che ne
identifica la precisa posizione e ne permette l'accesso immediato dal programma che ne fa uso. Gli indirizzi sono
tipicamente stringhe alfanumeriche di lunghezza pari alla dimensione delle parole nell'architettura corrente. Quindi,
dispositivi con architettura `x86` avranno indirizzi di memoria lunghi `32bit = 4byte`, mentre, dispositivi con
architettura a `x64` avranno indirizzi di memoria di lunghezza pari a `64bit = 8byte`.

Infine, dobbiamo precisare che in un linguaggio come il C, non si andrà direttamente a manipolare la memoria RAM del
dispositivo, ma quella che viene chiamata [__Memoria Virtuale__](https://it.wikipedia.org/wiki/Memoria_virtuale).
Un'effettiva astrazione della memoria primaria del dispositivo, gestita interamente dal sistema operativo, e che
permette sia di gestire una memoria primaria effettivamente più grande di quella disponibile, ma anche di prevenire
eventuali accessi illegali ad aree di memoria non manipolabili.

## Dichiarazione dei puntatori

Introduciamo, quindi, un nuovo tipo di dato chiamato __puntatore__. Un puntatore è letteralmente una variabile che punta
ad un indirizzo di memoria, e ci permette di accedere direttamente al contenuto di quell'indirizzo di memoria, a patto
che sia all'interno dello spazio allocato da parte del sistema operativo al processo del programma corrente. 

Con questo esempio, stiamo definendo un puntatore ad un numero intero, leggendone e modificandone il contenuto
attraverso il suo indirizzo di memoria.

```c 
int *number_ptr;
int number = 0;

number_ptr = &number;

*number_ptr = (*number_ptr) + 1;
```

* Per dichiarare un puntatore è necessario specificare anche il tipo di dato a cui esso punterà, inoltre, sarà
  necessario utilizzare il simbolo `*` per specificare che quello sarà un puntatore al tipo specificato. 
* L'operatore `&` permette di leggere l'indirizzo di memoria in cui è inserita una specifica variabile, quindi, con
  l'espressione `number_ptr = &number`, si sta inserendo all'interno del contenuto del puntatore, l'indirizzo di memoria
  della variabile `number`.
* Infine, lo stesso simbolo `*` utilizzato fuori dalla dichiarazione di una variabile, e non tra due tipi numerici,
  permette di __dereferenziare__ un puntatore, ossia: leggere il contenuto della cella di memoria il cui indirizzo è
  stato inserito all'interno di un puntatore.

La particolarità dell'esempio è che dopo l'espressione `*number_ptr = (*number_ptr) + 1` (il contenuto della cella di
memoria inserita all'interno della variabile `number_ptr` è uguale allo stesso contenuto incrementato di `1`). La
variabile `number` non avrà più valore `0` ma bensì `1`.

Quanto abbiamo appena visto, può essere facilmente sintetizzato attraverso la seguente rappresentazione di una memoria
centrale disponibile per un sistema con architettura a 64 bit.

<div style="display: flex; justify-content: center; align-items: center; width: 100%">
    <img 
        alt="Rappresentazione di un Puntatore"
        src="../assets/4. Puntatori e Vettori/rappresentazione-puntatore.png" 
        style="width: 100%; height: fit-content;" />
</div>

Il rettangolo principale che rappresenta la memoria centrale è diviso in piccole forme rappresentanti le diverse celle
di memoria. A ciascuna cella è assegnato un indirizzo di lunghezza pari a 64 bit, rappresentato in formato esadecimale,
all'interno della variabile chiamata `number_ptr` è inserito l'indirizzo di memoria della cella rappresentata dalla
variabile `number`. Infine, la freccia rossa indica l'operatore di dereferenziazione dal puntatore alla variabile
stessa.

## Aritmetica dei Puntatori

Essendo un puntatore una variabile contenente un indirizzo di memoria, è possibile eseguire delle operazioni tra
variabili di questo tipo. Consideriamo il seguente esempio:

```c
int number = 10;
int* number_ptr = &number;

printf("number_ptr = %p, number_ptr + 1 = %p\n", number_ptr, number_ptr + 1);
```

Supponendo che l'indirizzo di memoria del puntatore `number_ptr` sia `0x000000001` ci aspetteremo, ingenuamente, che
il valore di `number_ptr + 1` sia `0x000000002`, ma ci renderemo conto che, invece, questo sia `0x000000005`. Per
comprendere questo strano comportamento, è necessario analizzare un attimo come siano effettivamente rappresentate le
variabili in memoria. 

Considerando un dispositivo con architettura `x64`, avente, quindi, indirizzi di memoria a 64bit e con parole elaborate
dal processore di lunghezza pari a 8byte. Ciascuna cella di memoria può contenere esattamente 1byte di informazione,
dunque possiamo supporre che ciascuna cella di memoria può contenere una variabile di tipo `char`. Tuttavia,
considerando l'esempio di una variabile dichiarata come `int`, avente quindi dimensione di 4byte, saranno necessarie
quattro celle di memoria per memorizzare la variabile stessa, esattamente come vediamo dall'esempio in figura. 

<div style="display: flex; justify-content: center; align-items: center; width: 100%">
    <img 
        alt="Operazioni tra Puntatori"
        src="../assets/4. Puntatori e Vettori/operazioni-operatori.png" 
        style="width: 100%; height: fit-content;" />
</div>

Procedendo in questa direzione, e supponendo di avere un puntatore che referenza la variabile intera in questione,
l'espressione `integer_ptr + 1`, vuole accedere alla cella di memoria successiva a quella puntata da `integer_ptr`.
Tuttavia, basandoci sulla figura precedente, e supponendo che la cella di memoria in questione sia `0x000000001`, la
cella di memoria successiva `0x000000002`, è sempre parte della definizione del numero intero dichiarato
precedentemente, quale parte di questo intero memorizzi non lo sapremo mai. Tuttavia, accedere a questa cella di
memoria, e poter eseguire delle operazioni, potrebbe causare degli effetti indesiderati su tutto il programma. Dunque,
per impedire questo accesso, il compilatore in C, restituisce la cella di memoria successiva, appartenente ad un altro
informazione del nostro programma, ossia: `0x000000005`.

Possiamo quindi supporre che le operazioni aritmetiche su un puntatore sono __coerenti__, ossia: rispettano la semantica
dei puntatori stessi per impedire accessi non autorizzati e deleteri ad altre parti di informazioni del programma
stesso. Analogamente, possiamo supporre che le operazioni aritmetiche sui puntatori, come incremento e decremento,
aggiungono o sottraggono delle __unità__ dal valore rappresentato dall'indirizzo di memoria. Dunque, le operazioni di
incremento e decremento come `integer_ptr = integer_ptr + 1` sono da intendere nel seguente modo: `integer_ptr =
integer_ptr + (1 * sizeof(integer_ptr))`.

## Vettori e Puntatori 

La relazione tra i puntatori ed i vettori è così ravvicinata da richiedere che entrambi gli argomenti vengano trattati
insieme. Per dichiarare un vettore in C, è sufficiente usare la seguente sintassi:

```c
unsigned char a_char_vector[4];
unsigned short int a_integer_vector[] = { 1, 2, 3, 4 };
float a_float_vector[] = { 1, 2, 3, '\0' };
```

In tutti i casi, per dichiarare un vettore è necessario specificarne la dimensione, alternativamente, è possibile
dichiarare una variabile come vettore, senza inserire anche la dimensione fissa, purché la variabile stessa sia
inizializzata al momento della dichiarazione. Infatti, attraverso la diretta inizializzazione, il compilatore è in grado 
di inferire la dimensione del vettore stesso.

Analizziamo, adesso, come si configura un vettore in memoria:

<div style="display: flex; justify-content: center; align-items: center; width: 100%">
    <img 
        alt="Dichiarazione Vettore"
        src="../assets/4. Puntatori e Vettori/dichiarazione-vettore.png" 
        style="width: 100%; height: fit-content;" />
</div>

Nel momento in cui il compilatore legge la dichiarazione `char my_vector[4]` creerà in memoria 5 elementi consecutivi,
di cui: 4 di questi rappresenteranno gli elementi inizializzati o meno del nostro vettore; il quinto elemento viene
inserito automaticamente, e rappresenta il carattere di terminazione `\0`. Il carattere di terminazione è fondamentale
per riuscire a comprendere quando effettivamente un vettore sia terminato, e quindi, si debba evitare di leggere aree di
memoria diverse non più appartenenti al vettore stesso.

Non a caso, all'interno della foto, possiamo notare che la dichiarazione del vettore abbia una freccia che punti verso
il primo elemento. Infatti, una dichiarazione come quella che abbiamo appena visto, è un'espressione che restituisce un
puntatore al primo elemento del vettore appena creato. Questo ci permette di fare un ulteriore passo in avanti, e capire
che espressioni come le seguenti:

```c
my_char_vector[4];
my_integer_vector[3];
```

Possono essere equivalentemente espresse come: "_dato il puntatore al primo elemento del vettore, incrementa questo
puntatore di n unità, e restituiscimi il corrispondente risultato dato dall'incremento del primo". Perciò, queste
espressioni sono completamente equivalenti:

```c
my_char_vector[4];      // *(my_char_vector + 4)
my_integer_vector[3];   // *(my_integer_vector + 3)
```

Possiamo, tuttavia, fare un passo aggiuntivo. Tornando indietro ai cari tempi delle scuole elementari, possiamo
ricordarci che l'addizione gode della proprietà commutativa, quindi, `*(my_char_vector + 4)` è un'espressione
completamente equivalente a `*(4 + my_char_vector)`. Perciò, non dovrebbe, allora, farci scandalizzare questa
equivalenza:

```c
my_char_vector[4]; // *(my_char_vector + 4) => *(4 + my_char_vector) => 4[my_char_vector];
my_integer_vector[3];   // *(my_integer_vector + 3) => *(3 + my_integer_vector) => 3[my_integer_vector];
```

E'bene sapere che, il compilatore tradurrà sempre le espressioni come `my_integer_vector[4]` nel corrispondente
`*(my_integer_vector + 4)`. Tuttavia, questo non significa che esiste un'alternativa computazionalmente più efficiente
rispetto ad un'altra. Entrambe queste forme sono completamente valide, e possono essere usate senza problemi.

## Puntatori e Parametri

Adesso che abbiamo una conoscenza preliminare sui puntatori, analizziamo quale sia il loro impatto nella struttura anche
del più semplice programma. Quando abbiamo introdotto le funzioni, abbiamo anche accennato al meccanismo del passaggio
dei parametri. Nella comune teoria dei linguaggi di programmazione, esistono due modalità con le quali possono essere
passati i parametri ad una funzione: passare un parametro per valore; alternativamente, passare un parametro per
riferimento. 

Possiamo descrivere questi due diversi comportamenti, usando le seguenti definizioni:

> Nel _passaggio per valore_ di un parametro a ad una funzione f, il compilatore copia il parametro, creandone
 un'effettiva copia che possiamo chiamare _a. Qualsiasi operazione all'interno della funzione f che coinvolgerà
 apparentemente il parametro a, verrà concretamente eseguita sul parametro _a. Di conseguenza, il parametro in ingresso
 a, non subirà alcuna modifica diretta.

> Passando un parametro a ad una funzione f tramite _passaggio per riferimento_, il compilatore creerà un collegamento
 con il parametro a, in modo tale che: qualsiasi operazione che viene eseguita sul parametro a all'interno della
 funzione f si ripercuoterà direttamente sul parametro a stesso.

In C il passaggio dei parametri avviene esclusivamente per valore. Tuttavia, è possibile simulare il passaggio di un
parametro per riferimento mediante l'uso dei puntatori. Per chiarire e fissare bene quest'ultimo concetto, consideriamo
il seguente esempio:

```c
uint32_t a_variable = 10;

void passing_by_value (uint8_t parameter)
{
    printf("The input parameter in 'passing_by_value' is %u\n", parameter);
    parameter = parameter * 10;
    printf("The input parameter is 'passing_by_value' is %u\n", parameter);
}

void passing_by_reference (uint8_t* parameter)
{
    printf("The input parameter in 'passing_by_reference' is %u\n", *parameter);
    *parameter = (*parameter) * 10;
    printf("The input parameter is 'passing_by_reference' is %u\n", *parameter);
}

printf("'a_variable' = %u\n", a_variable);
passing_by_value(a_variable);
printf("'a_variable' = %u\n", a_variable);

printf("-----------------------------------------------------------------\n");

printf("'a_variable' = %u\n", a_variable);
passing_by_reference(&a_variable);
printf("'a_variable' = %u\n", a_variable);
```

Commentando l'esempio di sopra, sembra evidente che il passaggio della variabile alla funzione passing_by_reference
abbia creato quello che in gergo tecnico viene chiamato _side effect_, ossia, un effetto collaterale, che ha modificato
lo stato interno del programma rappresentato dalla funzione main, al di fuori della funzione stessa, ossia, nella
funzione passing_by_reference.

Quello che ci preme comprendere è che, il parametro uint8_t* parameter non è stato comunque passato per riferimento,
anche se sembra essere il contrario. Il compilatore C in questione, ha creato un'esatta copia del puntatore al
parametro. Tuttavia, sebbene sia stata creata una copia, del parametro puntatore, data la natura stessa del parametro, è
sempre possibile, attraverso una copia di questo, leggere il contenuto della variabile puntata.

Prima di concludere questa sezione, è necessario fare due considerazioni molto importanti: 

1. Per poter passare un parametro di tipo puntatore ad una funzione, è necessario che sia passato l'indirizzo di memoria
   della variabile puntata, e questo spiega il motivo dietro l'istruzione passing_by_reference(&a_variable);.

2. Funzioni che modificano i parametri stessi in input, ossia, che generato side effect, sono in generale da evitare.
   Questa è una raccomandazione che si legge spesso nei testi, e che si ascolta spesso dalle figure più esperte di noi.
   Il motivo dietro quest'affermazione? La complessità che aggiuge inevitabilmente un approccio basato su side effect.

## Puntatori e Stringhe

Diversamente da molti altri linguaggi di programmazione, in C non esiste un tipo per rappresentare le stringhe, e che
sia stato incluso nativamente nel linguaggio. Tuttavia, da un certo punto di vista, per compensare questa mancanza, è
necessario riflettere sulla natura stessa di una stringa di caratteri alfanumerici. Una stringa, è rappresentata in
memoria come un vettore di caratteri alfanumerici, aventi, tuttavia, un carattere di terminazione.

<div style="display: flex; justify-content: center; align-items: center; width: 100%">
    <img 
        alt="Stringhe in Memoria"
        src="../assets/4. Puntatori e Vettori/stringa.png" 
        style="width: 100%; height: fit-content;" />
</div>

Come possiamo vedere dall'immagine sopra, la dichiarazione che permette di creare un vettore di caratteri, restituisce un
puntatore al primo elemento del vettore. Dunque, le stesse operazioni dette ed implementate per i vettori, valgono
analogamente per le stringhe.

Quando parliamo di stringhe, tuttavia, dobbiamo fare una distinzione tra due diverse dichiarazioni:

```c
char[] my_str_1 = { 'A', 'B', 'C', '\0' };
char* my_str_2 = { 'D', 'E', 'F', '\0' };
```

La prima dichiarazione `char[] my_str_1` è un'espressione che definisce una stringa, dunque, non sarà possibile
assegnare alla variabile identificante la stringa, un'altra stringa magari di dimensione diversa. Inoltre, questo genere
di espressione, crea in memoria direttamente una sequenza di elementi di tipo `char`, di conseguenza, l'espressione
`sizeof(my_str_1)`, restituirà come valore 4, ossia la lunghezza del vettore stesso.

Diversamente dalla prima espressione, `char* my_str_2` dichiara solamente un puntatore. Che il puntatore si riferisca ad
una zona di memoria in cui consecutivamente sono memorizzati dei caratteri, oppure ad un singolo carattere, questo non
lo sapremo mai. Inoltre, essendo un semplice puntatore, non potremmo ottenere la dimensione dell'eventuale vettore a cui
punta, in quanto, `sizeof(my_str_2)`, restituirà sempre la dimensione assegnata ad un puntatore nell'architettura
corrente.

## Puntatori a Puntatori

Affermando che una stringa sia un vettore di caratteri, un puntatore ad una stringa è, in realtà, un puntatore ad un
puntatore. Un doppio puntatore, quindi, è in grado di definire un vettore multi-dimensionale. Tuttavia, la memoria
centrale di un computer, è in grado di memorizzare sequenzialmente solamente informazioni sotto forma di vettori
uni-dimensionali, ma questo non è un problema, in quanto con le dovute accortezze possiamo comunque memorizzare
informazioni con strutture multi-dimensionali, all'interno di altre strutture non aventi la stessa caratteristica. 

Sinteticamente, potremmo rappresentare questo ultimo concetto in maniera grafica, in questo modo:

<div style="display: flex; justify-content: center; align-items: center; width: 100%">
    <img 
        alt="Vettori Multi-dimensionali"
        src="../assets/4. Puntatori e Vettori/vettori-multidimensionali.png" 
        style="width: 100%; height: fit-content;" />
</div>

L'accesso ad uno degli elementi del nostro vettore, viene eseguito mediante un semplice calcolo: 
`base + (riga_corrente * numero_colonne + colonna_corrente) + sizeof(tipo_vettore)`. Nulla ci proibisce, tuttavia, di
poter accedere comunque ad elementi in memoria che sono al di fuori dello spazio di memorizzazione del nostro vettore
multi-dimensionale.
