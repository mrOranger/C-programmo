- [Testing e CUnit](#testing-cunit)
- [Test di Unità](#unit-testing)
- [CUnit](#cunit)
    - [Test Registry](#cunit-test-registry)
    - [Test Suite](#cunit-test-suite)
    - [Test Case](#cunit-test-case)

# Testing e CUnit <a id="testing-cunit"></a>

Nel capitolo precedente abbiamo creato una semplice libreria che gestisce il tipo `String`. Ora che abbiamo completato
quest'attività, dovremmo procedere con il testing del nostro codice. Se siete dei programmatore alle prime armi, molto
probabilmente scrivereste nel `main.c` varie combinazioni della funzione, sperando che sia tutto okay.

In ambito enterprise, per validare il lavoro appena fatto è necessario usare un framework di testing. Nel mondo dello
sviluppo software, esistono una miriade di tipi di test: che siano i semplici
[**test di unità**](https://it.wikipedia.org/wiki/Unit_testing); oppure i
[**test di regressione**](https://it.wikipedia.org/wiki/Collaudo_del_software#Il_collaudo_di_regressione). Ad ogni modo,
in base al livello di test che vogliamo applicare, sarà necessario usare una libreria o un framework associato.

In questo capitolo, analizzeremo cosa siano i test di unità, e di come questi possano essere implementati mediante la
libreria [**CUnit**](https://cunit.sourceforge.net/doc/index.html).

## Test di Unità <a id="unit-testing"></a>

Tra tutte le classi di testing, i test di unità controllano piccole unità di codice sorgente, senza verificare
l'integrazione di tutto il sistema complessivo. Possiamo dire, quindi, che questi sono la classe più semplice e più
veloce da implementare.

Nel nostro specifico esempio, i test di unità sono sufficiente ad assicurarci il corretto funzionamento del nostro
programma. Considerando il fatto che questo non sia un programma particolarmente complesso, che non interagisce a sua
volta con altre entità software.

Consideriamo il seguente esempio, che descrive brevemente un test di unità per una semplice funzione di somma:

```c
int sum (int first, int second)
{
    return first + second;
}

void test_sum_of_zero()
{
    int first = 0;
    int second = 0;

    int result = sum(first, second);

    if (result == 0)
    {
        printf("Passed!\n");
        return;
    }

    printf("Not Passed!\n");
}
```

In questo semplice esempio, abbiamo implementato noi una funzione che stampa in console il risultato del test. In un
caso più complesso, tuttavia, sarà necessario ricorrere a funzionalità più articolate, che permettano anche una più
rapita prototipizzazione delle funzioni di testing.

## CUnit

CUnit è una libreria di testing implementata per il linguaggio C. La libreria è nota per essere leggera, semplice e
robusta. Come molte librerie di testing, anche CUnit permette di organizzare i test della nostra applicazione, usando
uno schema gerarchico simile a quello descritto dalla seguente figura:

<div style="width: 100%; display: flex: flex-direction: row: justify-content:center: align-items:center">
    <img 
        alt="CUnit Organization" 
        src="../assets/8. CUnit/CUnit-organization.png" 
        style="width: 100%" />
</div>

### Test Registry <a id="cunit-test-registry1"></a>

Il **Test Registry** è il macro-componente al cui interno sono incapsulati tutti i test della nostra applicazione.
Questo componente è, quindi, il registro al cui interno sono inseriti tutti i test e da cui viene generato il report
complessivo sull'esecuzione di quest'ultimi.

Per generare un sistema di testing della nostra applicazione, il primo passo è quello di creare, appunto, un test
registry al cui interno inserire tutti i test. La creazione del Test Registry, può essere riassunta nei seguenti
passaggi:

1. Inizializzazione del registro.
2. Associazione dei test al registro appena creato.
3. Esecuzione del registro.
4. Chiusura del registro e visualizzazione del report.

Questi passaggi possono essere tradotti nel seguente codice:

```c
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

int main (const int argc, const char** argv)
{
    CU_ErrorCode registry_code = CU_initialize_registry();
    
    if (registry_code == CUE_NOMEMORY) 
    {
        printf("Si è verificato un errore nell'inizializzazione del registro!\n");
        return EXIT_FAILURE;
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return EXIT_SUCCESS;
}
```

1. L'inizializzazione del Test Registry, avviene mediante l'uso della funzione `CU_initialize_registry()`. Secondo
   quanto è scritto nella documentazione, questa funzione restituisce un codice tra: `CUE_SUCCESS`, per indicare che il
   Test Registry è stato inizializzato correttamente; `CU_NOMEMORY` per indicare che si è verificato un errore durante
   l'allocazione della memoria necessaria per eseguire i test.

2. Nell'esempio corrente, non ci sono test da associare. Tuttavia, ciò non impedirà a CUnit di eseguire comunque il Test
   Registry. Possiamo, invece, specificare il livello di informazioni da visualizzare nel report finale, mediante la
   funzione `CU_basic_set_mode(CU_BRM_VERBOSE)`, la quale indica di generare un report verbose. 

3. `CU_basic_run_tests()` esegue il registro corrente con gli eventuali test associati.

4. Infine, per concludere la nostra sessione di test, dobbiamo rilasciare le risorse allocate per il registro. In questo
   caso, è necessario usare la funzione `CU_cleanup_registry()`.

### Test Suite <a id="cunit-test-suite"></a>

Adesso che abbiamo definito il contenitore principale, è necessario definirne il contenuto. Un singolo test deve essere
associato ad una **Test Suite**, ossia: un raggruppamento logico di test tale da poter essere registrato all'interno di
un Test Registry, e che permette di eseguire in serie i test definiti all'interno del primo. Un Test Suite, quindi, non
è altro che una collezione di test.

Per creare una Test Suite, ricorriamo alla funzione `CU_add_suite`, la quale richiede tre parametri:

1. Un identificativo sotto forma di stringa, che descrive brevemente il contenuto della Test Suite.
2. Una funzione da eseguire prima dell'esecuzione degli eventuali test registrati nella Test Suite.
3. Una funzione da eseguire dopo l'esecuzione di tutti i test registrati nella Test Suite.

L'uso della funzione `CU_add_suite`, può essere descritta nel seguente codice:

```c
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdlib.h>

int setup()
{
    printf("Questa è la funzione di 'setup'\n");
    return 0;
}

int tearDown()
{
    printf("Questa è la funzione di 'tearDown'\n");
    return 0;
}

int main (const int argc, const char** argv)
{
    CU_pSuite suite = CU_add_suite("My First Suite", setup, tearDown);

    if (suite == NULL)
    {
        printf("Errore nell'inizializzazione della Test Suite!\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
```

Come possiamo vedere, le due funzioni `setup` e `tearDown`, vengono eseguite prima e dopo l'inizializzazione dei test.
Inoltre, queste funzioni possono indicare a CUnit di essere fallite o no, restituendo un codice di errore diverso dal
valore `0`. Qualora una di queste funzioni fallisca, CUnit ferma immediatamente il registro, indicando che si è
verificato un errore all'interno dell'inizializzazione o rilascio delle risorse di una specifica Test Suite.

### Test Case <a id="cunit-test-case"></a>

Una volta che abbiamo definito il Test Registry, ed il Test Suite, l'ultimo elemento che manca, è il test effettivo da
implementare. Il testing da eseguire, viene codificato in un apposito scenario, definito nel corpo di una funzione, al
cui interno, deve essere presente, un'**asserzione**. CUnit possiede un insieme non indifferente di asserzioni da usare
all'interno di uno scenario di testing, e la lista completa può essere consultata [qui](https://cunit.sourceforge.net/doc/writing_tests.html)). 

Iniziamo definendo gli scenari di test che vogliamo implementare, e che verificano il corretto funzionamento della
funzione `sum`. Nel nostro caso, vogliamo verificare cosa accada nel caso in cui si sommino due numeri positivi, o due
numeri negativi. Gli scenari di test sono codificati all'interno delle seguenti funzioni:


```c
int sum (int first, int second)
{
    return first + second;
}

void test_sum_of_two_positive_numbers()
{
    CU_ASSERT_EQUAL(sum(1, 2), 3);
}

void test_sum_of_two_negative_numbers()
{
    CU_ASSERT_EQUAL(sum(-1, -2), -3);
}
```

I due scenari `test_sum_of_two_positivie_numbers` e `test_sum_of_two_negative_numbers`, contengono al loro interno le
relative asserzioni, che verranno verificate da CUnit, nel momento in cui verrà eseguita la Test Suite, che conterrà
questi due scenari.

La parte mancante, affinché possiamo considerare valido il nostro test, consiste nell'associazione degli scenari
all'interno di una relative Test Suite, registrata nel Test Register precedente:

```c
int main (const int argc, const char** argv)
{
    CU_ErrorCode registry_code = CU_initialize_registry();
    
    if (registry_code == CUE_NOMEMORY) 
    {
        printf("Si è verificato un errore nell'inizializzazione del registro!\n");
        return EXIT_FAILURE;
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);

    CU_pSuite suite = CU_add_suite("My First Suite", setup, tearDown);

    if (suite == NULL)
    {
        printf("Errore nell'inizializzazione della Test Suite!\n");
        return EXIT_FAILURE;
    }

    CU_add_test(suite, "test sum of two positive numbers", test_sum_of_two_positive_numbers);
    CU_add_test(suite, "test sum of two negative numbers", test_sum_of_two_negative_numbers);

    CU_basic_run_tests();

    CU_cleanup_registry();

    return EXIT_SUCCESS;
}
```

Come possiamo osservare, mediante la funzione `CU_add_test`, possiamo registrare all'interno di una specifica Test
Suite, i nostri scenari di test che conterranno le relative asserzioni. Eseguendo questo programma, otterremo un report
completo di cosa è accaduto con l'indicazione di fallimento o successo degli scenari che abbiamo definito.
