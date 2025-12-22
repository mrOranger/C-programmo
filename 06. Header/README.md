# File di Intestazione

Fino a questo momento, ci siamo limitati a creare programmi definiti in un unico file sorgete, ossia `main.c`. Nel
momento in cui la nostra applicazioni comincia a crescere di dimensione, si potrebbe arrivare ad un punto in cui non sia
più pratico inserire tutto il codice all'interno di un unico file sorgente. In questo modo, avendo il file assunto
dimensioni mastodontiche, useremo gran parte del nostro tempo nello scorrere il file sorgente, alla ricerca di uno
specifico punto.

L'idea è quella, quindi, di separare il file sorgente in diversi file sorgenti. Quindi, tramite l'uso della direttiva
`#include`, potremmo riferirci al contenuto di questi file, utilizzandone le funzionalità definite al loro interno. La
direttiva `#include`, infatti, indica al compilatore di leggere il contenuto del file identificato dallo specifico nome,
quindi, di sostituirne il contenuto all'interno del file stesso in cui è definita la direttiva. 

Partiamo considerando il seguente esempio: supponiamo di voler creare un'applicazione che permetta di registrare delle
anagrafiche di alcuni pazienti. Ciascun paziente è identificato da un codice fiscale, un nome, un cognome ed una
specifica età. Sulla base di queste informazioni, potremmo implementare i requisiti all'interno del file
[`patient.c`](./libs/patient.c).

Questo modello di implementazione, fino a questo momento, non ha difetti, abbiamo evitato di definire delle operazioni
specifiche di un'entità all'interno di un file che ne conterrebbe di diverse. Tuttavia, un difetto c'è, ed è
rappresentato dalla mancanza di astrazione di queste funzionalità rispetto al resto dell'applicazione.

## Headers

Separare l'implementazione di una funzione dalla relativa dichiarazione, ha diversi vantaggi:

1. __Compilazione separata delle dipendenze__. Riprendendo l'esempio precedente, all'invocazione del comando `gcc
   main.c`, il  compilatore creerà due file oggetto diversi, ciascuno per ogni file sorgente, successivamente il linker
   provvederà a collegare tra loro questi file all'interno di un unico eseguibile. Collegando direttamente tra loro due
   file sorgenti, sarà necessario ricompilare l'interno progetto. In un progetto di dimensioni relativamente grandi,
   sarebbe richiesto uno sforzo notevole per ricompilare l'intero progetto. Separando le dipendenze, facendo in modo che
   siano collegate tra loro mediante delle interfacce, qualora un'implementazione cambi, non sarà necessario ricompilare
   anche tutti i file sorgenti che dipendono dal primo, in quanto l'interfaccia garantisce che non sia cambiato nulla
   nella definizione stessa di una funzione.

2. __Riusabilità delle interfacce__. Separando le interfacce dalle implementazioni, ha come diretta conseguenza
   l'aumento della capacità del codice di essere riciclato. In questo modo, un file sorgente che si riferisce ad
   un'interfaccia, non si deve curare delle modifiche all'implementazione dell'interfaccia definita all'interno di un
   fil diverso. L'unica cosa che bisogna garantire, è che le definizioni dell'interfaccia non cambino.

3. __Evitare definizioni multiple__. In C, ma anche in altri linguaggi di programmazione, è possibile indicare al
   compilatore, di non definire nuovamente una dichiarazione, qualora questa sia stata già definita in passato.

Sulla base di queste considerazioni, dobbiamo modificare il nostro file sorgente [`main.c`](./main.c). L'idea è quella
di creare una struttura simile a quella definita dalla seguente figura:

<div style="display: flex; justify-content: center; align-items: center; width: 100%">
    <img 
        alt="Struttura Programma"
        src="../assets/6. Header/struttura-programma.png" 
        style="width: 100%; height: fit-content;" />
</div>

L'implementazione del file [`patient.c`](./libs/patient/patient.c) non è cambiata, ciò che bisogna cambiare, tuttavia, è
l'implementazione del file [`main.c`](./main.c), in modo tale che punti al file di intestazione
[`patient.h`](`./libs/patient/patient.h`):

```c
#include <stdio.h>

#include "libs/patient/patient.h"

int main (const int argc, const char** argv)
{
    Patient patient = init_patient("ABCDCD10H72A991K", "Mario", "Rossi", 38);
    print_patient(patient);

    return 0;
}
```

Infine, è necessario inserire le definizioni delle nostre funzioni e delle strutture dati all'interno del file
[`patient.h`](./libs/patient/patient.h):

```c
#ifndef PATIENT_H
#define PATIENT_H

#include <stdint.h>

struct patient {
    char*   tax_code;
    char*   first_name;
    char*   last_name;
    uint8_t age;
};

typedef struct patient Patient;

Patient init_patient (char* tax_code, char* first_name, char* last_name, uint8_t age);

void set_tax_code(Patient patient, char* tax_code);
void set_first_name(Patient patient, char* first_name);
void set_last_name(Patient patient, char* last_name);
void set_age(Patient patient, uint8_t age);

char* get_tax_code (Patient patient);
char* get_first_name (Patient patient);
char* get_last_name (Patient patient);
uint8_t get_age (Patient patient);

void print_patient (Patient patient);

#endif
```

Notiamo, tuttavia, l'uso delle istruzioni al preprocessore: `#ifndef`, `#define` e `#endif`. Usate nella combinazione
indicata, permettono che il compilatore eviti di elaborare nuovamente queste dichiarazioni qualora siano state già
elaborate precedentemente in un'altra parte del nostro programma.
