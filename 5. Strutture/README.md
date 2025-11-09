# Strutture

In C è possibile aggregare tra loro delle informazioni mediante un costrutto denominato `struct`. Elementi che
utilizzano questo costrutto nativo, sono chiamati __Strutture__ o __Record__. Il vantaggio di usare questo nuovo
concetto, rispetto a definire separatamente delle variabili, consiste proprio dell'usare un unico punto di accesso, ad
un insieme di informazioni che tra loro formano un unico concetto. In questo capitolo, analizzeremo come sia possibile
definire una struttura, come questa viene trattata dal compilatore, e le operazioni ammissibili su questo tipo di
entità.

## Rappresentazione di una Struttura

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
L'espressione è composta dai seguenti elementi: il __nome__ o __alias__ della struttura, nel nostro caso specifico
questo è `person`; ed i __membri__, ossia le singole variabili che compongono la nostra struttura.

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

Analizzando l'output di questo codice, possiamo notare che `sizeof(struct person) = 24 byte, sizeof(uint8_t) = 1 byte,
sizeof(char*) = 8 byte`. Sperando che la matematica ci assista, `(8 * 2) + 1) byte != 24 byte`. Come mai, allora la
dimensione della struttura non coincide con la somma dei suoi campi, come intuitivamente uno si aspetterebbe che fosse
così?

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

* `1` accesso alla parola `word_1` per leggere le informazioni del membro `age`.
* `1` accesso alla parola `word_1`, `1` accesso alla parola `word_2` per leggere le informazioni del membro
  `first_name`;
* `1` accesso alla parola `word_2` ed `1` accesso alla parola `word_3` per leggere le informazioni del membro `last_name`.

Diversamente, se riuscissimo a rappresentare una struttura come nell'immagine a destra, assegnando ad uno spazio extra
ad un membro della struttura, anche chiamato __padding__. Sarebbero necessarie le seguenti operazioni:

* `1` accesso alla parola `word_1` per leggere le informazioni del membro `age`;
* `1` accesso alla parola `word_2` per leggere le informazioni del membro `first_name`;
* `1` accesso alla parola `word_3` per leggere le informazioni del membro `last_name`;

Quindi, sacrificando 7 byte di memoria, siamo in grado di ridurre il numero di operazioni di lettura/scrittura del
processore. Concludendo, quando si crea una struttura, è necessario porre attenzione all'ordine in cui sono stati
inseriti i membri, l'ordine corretto potrebbe evitare che si utilizzi padding per allineare correttamente una struttura
alla dimensione delle parole. Una buona regola da seguire è sempre quella di registrare per prima i membri che
possiedono lunghezza maggiore, ed infine, verificare se la dimensione di una variabile possa essere modificata per
permette un migliore allineamento.

## Alias e `typedef`

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
