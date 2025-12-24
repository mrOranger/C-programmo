- [Strutture](#struct)
  - [Rappresentazione di una Struttura](#struct-representation)
  - [Alias e `typedef`](#typedef)
  - [Unione e Membri Diversi](#union)
  - [Enumerativi](#enums)

# Strutture <a id="struct">

In C è possibile aggregare tra loro delle informazioni mediante un costrutto denominato `struct`. Elementi che
utilizzano questo costrutto nativo, sono chiamati **Strutture** o **Record**. Il vantaggio di usare questo nuovo
concetto, rispetto a definire separatamente delle variabili, consiste proprio dell'usare un unico punto di accesso, ad
un insieme di informazioni che tra loro formano un unico concetto. In questo capitolo, analizzeremo come sia possibile
definire una struttura, come questa viene trattata dal compilatore, e le operazioni ammissibili su questo tipo di
entità.

## Rappresentazione di una Struttura <a id="struct-representation"></a>

Supponiamo di voler rappresentare una persona all'interno del nostro programma. Idealmente, possiamo pensare ad una
persona come ad un oggetto composto dai seguenti elementi: nome; cognome e età. Possiamo, quindi, rappresentare una
persona in un programma C, usando la seguente sintassi:

```c
struct person {
    uint8_t age;
    char* first_name;
    char* last_name;
};
```

L'espressione è composta dai seguenti elementi: il **nome** o **alias** della struttura, nel nostro caso specifico
questo è `person`; ed i **membri**, ossia le singole variabili che compongono la nostra struttura.

Con quest'espressione stiamo _dichiarando_ una struttura. Preferisco porre enfasi sulla parola "dichiarare", perché, con
l'istruzione che abbiamo appena visto, non accade nulla in memoria. Fintantoché non viene creata una variabile il cui
tipo è proprio quello della nostra struttura stessa, non accadrà nulla. La dichiarazione, tuttavia, è utile al
compilatore per comprendere che, nel caso in cui venga creata una variabile con questo tipo, esso sarà in grado di
comprendere come e quanto spazio usare per gestire la variabile stessa.

A livello del compilatore, infatti, una struttura è semplicemente rappresentata come un unico blocco continuo, al cui
interno sono inseriti tutti i membri della struttura stessa. In termini grafici, possiamo dire, approssimativamente, che
la struttura `person` sia definita in questo modo:

<div style="display: flex; justify-content: center; align-items: center; width: 100%">
    <img 
        alt="Rappresentazione di una Struttura"
        src="../assets/5. Strutture/rappresentazione-struttura.png" 
        style="width: 100%; height: fit-content;" />
</div>

In realtà la figura che ho appena mostrato è errata! Per avere conferma di quest'ultima affermazione, analizziamo in
seguente codice, in [`main.c`](./main.c):

```c
printf ("sizeof(struct person) = %lu byte\n", sizeof(struct person));
printf ("sizeof(uint8_t) = %lu byte, sizeof(char*) = %lu byte\n", sizeof(uint8_t), sizeof(char*));
```

Analizzando l'output di questo codice, possiamo notare che
`sizeof(struct person) = 24 byte, sizeof(uint8_t) = 1 byte, sizeof(char*) = 8 byte`. Sperando che la matematica ci
assista, `(8 * 2) + 1) byte != 24 byte`. Come mai, allora la dimensione della struttura non coincide con la somma dei
suoi campi, come intuitivamente uno si aspetterebbe che fosse così?

La risposta a quest'ultima domanda richiede un'analisi delle modalità con il quale il processore legge le informazioni
che compongono la struttura. Immaginiamo di lavorare con un processore avente architettura a 64bit, con parole, quindi,
di 8byte ciascuna. Per ciascun ciclo del clock, quindi, vengono letti 8 byte di informazione alla volta.

<div style="display: flex; justify-content: center; align-items: center; width: 100%">
    <img 
        alt="Padding di una Struttura"
        src="../assets/5. Strutture/padding.png" 
        style="width: 100%; height: fit-content;" />
</div>

Sulla base delle informazioni precedenti, ed analizzando l'immagine a sinistra nella figura sovrastante. Se il
compilatore rappresentasse in memoria una struttura esattamente come viene scritta nel codice, il processore dovrà
eseguire le seguenti operazioni ogni volta che dovrà essere manipolata una struttura:

- `1` accesso alla parola `word_1` per leggere le informazioni del membro `age`.
- `1` accesso alla parola `word_1`, `1` accesso alla parola `word_2` per leggere le informazioni del membro
  `first_name`;
- `1` accesso alla parola `word_2` ed `1` accesso alla parola `word_3` per leggere le informazioni del membro
  `last_name`.

Diversamente, se riuscissimo a rappresentare una struttura come nell'immagine a destra, assegnando ad uno spazio extra
ad un membro della struttura, anche chiamato **padding**. Sarebbero necessarie le seguenti operazioni:

- `1` accesso alla parola `word_1` per leggere le informazioni del membro `age`;
- `1` accesso alla parola `word_2` per leggere le informazioni del membro `first_name`;
- `1` accesso alla parola `word_3` per leggere le informazioni del membro `last_name`;

Quindi, sacrificando 7 byte di memoria, siamo in grado di ridurre il numero di operazioni di lettura/scrittura del
processore. Concludendo, quando si crea una struttura, è necessario porre attenzione all'ordine in cui sono stati
inseriti i membri, l'ordine corretto potrebbe evitare che si utilizzi padding per allineare correttamente una struttura
alla dimensione delle parole. Una buona regola da seguire è sempre quella di registrare per prima i membri che
possiedono lunghezza maggiore, ed infine, verificare se la dimensione di una variabile possa essere modificata per
permette un migliore allineamento.

## Alias e `typedef` <a id="typedef"></a>

Una volta che è stata creata una struttura, se volessimo dichiarare una variabile il cui tipo sia proprio della
struttura stessa, dovremmo dichiararne il tipo usando la parola `struct`, seguita dal nome della struttura in questione.
Consideriamo, quindi, questo esempio:

```c
struct person {
    char* first_name;
    char* last_name;
    uint8_t age;
};

struct person init_person (char* first_name, char* last_name, uint8_t age)
{
    struct person new_person;

    new_person.first_name = first_name;
    new_person.last_name = last_name;
    new_person.age = age;

    return new_person;
}

void print_person (struct person a_person)
{
    printf("First Name: %s\n", a_person.first_name);
    printf("Last Name:  %s\n", a_person.last_name);
    printf("Age:        %u\n", a_person.age);
}

int main (const int argc, const char** argv)
{
    struct person a_person = init_person("Mario", "Rossi", (uint8_t)29);
    print_person(a_person);
    return 0;
}
```

Sicuramente, questo codice sembra molto prolisso nella definizione delle variabili di tipo `struct person`. Esiste una
valida alternativa, rappresentata dall'operatore `typedef`. Mediante questo operatore, possiamo definire degli alias per
uno specifico tipo. In realtà, ridefinire un tipo mediante `typedef`, non esegue nessun' operazione reale nel nostro
programma, analogamente non verrà richiesta altra memoria. Sarà compito del compilatore, successivamente, "espandere" le
definizioni di `typedef` sostituendole con il relativo tipo che hanno ridefinito.

## Unione di Membri Diversi <a id="union"></a>

Un unione in C rappresenta la letterale e pratica fusione di diversi tipi di variabile all'interno di un'unica area di
memoria. L'operazione di unione si realizza in maniera simile alle strutture, mediante l'uso della parola chiave
`union`. Ad esempio, l'età di una oggetto `Person` potrebbe essere rappresentata sia come un valore numerico senza segno
a 8bit, sia come un vettore di caratteri. Possiamo esprimere questa dualità attraverso l'uso del costrutto `union`:

```c
union age {
    uint8_t age_number;
    char*   age_string;
};

typedef union age Age;
```

Il nuovo tipo `Age` potrà essere in maniera mutuamente esclusiva un numero a 8 bit, oppure una stringa. Tuttavia, come
verrà rappresentata questa variabile in memoria? In presenza di un'unione, il compilatore utilizzerà un'unica area di
memoria, la cui dimensione in celle dipende dalla grandezza dell'elemento di maggiore dimensione nell'unione (nel nostro
caso `char*`). Per comprendere al meglio cosa faccia il compilatore in questo specifico caso, consideriamo il seguente
esempio:

```c
union elem {
    uint8_t number;
    unsigned char characters[4];
};
```

Abbiamo dichiarato un'unione composta da un intero senza segno ad 8 bit, ed un vettore di caratteri di dimensione 4.
Considerando che l'intero ad 8 bit occuperà esattamente una cella di memoria da 1 byte, e che il vettore di caratteri
richiederà 4 byte per essere rappresentato in memoria; la dimensione complessiva dell'unione sarà di 4 byte (la
grandezza dell'elemento più grande dell'unione). Considerando la seguente inizializzazione:

```c
union elem elements;
elements.number = 10;
printf("elements.number = %u\n", elements.number);
printf(
    "elements.characters = [ %d, %d, %d, %d ]\n",
    elements.characters[0],
    elements.characters[1],
    elements.characters[2],
    elements.characters[3]
);
```

Considerando che sia `number` che `characters` occupano la stessa area di memoria, l'assegnamento `number = 10`,
inserirà il valore `10` all'interno dei primi 8 bit utilizzati per rappresentare anche la variable `characters`.
Tuttavia, questo risultato cambierà in base anche al fatto se l'architettura dell'elaboratore sia basata su
[**little endian** o **big endian**](https://it.wikipedia.org/wiki/Ordine_dei_byte).

Prima di concludere questa sezione, è necessario fare un'ultima considerazione. Supponiamo di aver modificato l'esempio
precedente, in cui l'età di una persona può essere rappresentata come una stringa o un numero intero. Come possiamo
conoscere il tipo che è stato usato dalla struttura, in presenza di un'unione di più elementi di questa? La soluzione,
consiste nell'utilizzare un nuovo membro che faccia da discriminante, e ci indichi quando è stato utilizzato un tipo
nell'unione rispetto ad un altro:

```c
enum age_type {
    NUMERIC,
    STRING,
};

typedef enum age_type AgeType;

union age {
    uint8_t age_number;
    char*   age_string;
};

typedef union age Age;

struct person {
    char*   first_name;
    char*   last_name;
    AgeType age_type;
    Age     age;
};

typedef struct person Person;
```

## Enumerativi <a id="enums"></a>

Nel caso in cui volessimo definire una struttura semplice, i cui valori all'interno devono rappresentare un insieme
finito di elementi, possiamo ricorrere all'uso degli enumerativi. In questo esempio, definiamo un enumerativo che
rappresenta due valori, `TRUE` o `FALSE`:

```c
enum Boolean {
    TRUE,
    FALSE
}
```

Quello che accade è che verranno creati due alias utilizzabili in tutto il codice mediante le parole chiavi `TRUE` o
`FALSE` e che saranno rappresentati dai valori numerici 0 o 1. Potremmo dire che un enumerativo è quindi un modo per
associare a dei numeri interi positivi crescenti delle parole chiavi, in realtà non è cosi:

```c
enum Boolean {
    TRUE = 't',
    FALSE = 'f'
}
```

In C è ammissibile associare un qualsiasi numero intero ad un espressione che rappresenta un enumerativo. Infatti, come
possiamo vedere nell'esempio precedente, abbiamo associato alle parole `TRUE` e `FALSE` i numeri interi tramite i quali
sono rappresentati i caratteri `t` e `f`.
