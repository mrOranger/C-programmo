<div style="min-width: 100px; max-width: 200px; display: inline-flex; justify-content:center; align-items:center;">
    <img src = "assets/logo-c.png" alt = "Logo Linguaggio C" style = "max-width: 200px; padding: 1em 2em;" />
</div>

# Introduzione     

Il linguaggio C è uno dei più conosciuti nel panorama dell'informatica, la sua fama è dovuta principalmente a due
fattori: il suo impiego nello sviluppo dei sistemi operativi UNIX, e la sua semplicità. La sua popolarità e la sua
semplicità hanno influenzato gran parte dei linguaggi di programmazione moderni, come: Java, JavaScript ed C++. Non a
caso, quando si impara un nuovo linguaggio, spesso ci si imbatte nella frase "__sintassi C-like__", ad indicare, proprio
la somiglianza del linguaggio con il C.

Il fatto che il C sia stato impiegato nello sviluppo del core di [UNIX](https://it.wikipedia.org/wiki/Unix), è anche il
motivo per il quale ho deciso di creare questa repository. Per chi non lo sapesse, UNIX è il sistema operativo alla base
di gran parte dei sistemi operativi moderni come Linux e MacOS. 

Un altro motivo, fondamentale per il quale, secondo me, è importante conoscere un linguaggio come questo, è dato dalla
sua "vicinanza alla macchina". Con quest'ultimo termine, indendo dire che l'astrazione fornita dal linguaggio, è tale 
concedere al programmatore l'onere di gestire concetti come: l'allocazione ed il rilascio della memoria; 
la gestione dei flussi di dati indipendentemente dalla sorgente; e l'uso accurato di variabili dipendenti dal sistema 
di calcolo su cui il programma verrà eseguito.

Tutti i concetti precedentemente elencati, non si trovano in buona parte dei linguaggi ad "alto livello", come
JavaScript o Java. Tuttavia, sebbene la potenza dei calcolatori moderni sia sufficiente a sollevare il programmatore
dall'incarico di gestire in maniera prudente la memoria (a causa dell'insermento del [Garbage Collector](https://it.wikipedia.org/wiki/Garbage_collection)); per la realizzazione di un programma funzionale ed ottimizzato, è comunque necessario comprendere questi
concetti, e quale modo migliore di utilizzare un linguaggio di programmazione che obbliga il programmatore a fare questo. 

Lo scopo di questa repository è quella di approfondire il linguaggio C, ed impiegarlo per uno studio degli Algoritmi e
delle Strutture Dati. La repository non è rivolta ad un pubblico neofita, in quanto, per comodità verranno saltati
concetti relativamente scontati ad un programmatore, riguardandi la [Programmazione Imperativa](https://it.wikipedia.org/wiki/Programmazione_imperativa).

## Storia del Linguaggio.

Il C nasce nei Bell Laboratories tra il 1969 e il 1973 e creato da [Dennis Ritchie](https://it.wikipedia.org/wiki/Dennis_Ritchie) 
come evoluzione del linguaggio B sviluppato da [Ken Thompson](https://it.wikipedia.org/wiki/Ken_Thompson) nel 1970 per 
il primo sistema operativo UNIX sul DEC PDP-7. Molte idee basilari del linguaggio, sono ereditate anche dal linguaggio 
BCPL. 

Nel corso della sua storia, il linguaggio C ha subito molte modifiche e revisione. La cosa fondamentale da sapere è che
nel 1989 il linguaggio è stato finalmente standardizzato dall'[ANSI](https://it.wikipedia.org/wiki/American_National_Standards_Institute), 
di fatto, realizzando la versione del linguaggio adottata dalla stragrande maggioranza dei calcolatori e nota come
__ANSI-C__.

* `1978`. Nel 1978, Brian Kernighan e Dennis Ritchie pubblicarono "The C Programming Language", libro che definì lo 
standard de facto del linguaggio, noto come K&R C. Questa pubblicazione contribuì enormemente alla diffusione del C oltre
i confini dei Bell Labs.

* `1989`. L'American National Standards Institute (ANSI) standardizzò il linguaggio nel 1989, creando lo standard ANSI
C (o C89). Questo garantì maggiore portabilità del codice tra diverse piattaforme e compilatori.

* `1999`. Lo standard C99 introdusse numerose migliorie: commenti in stile //, tipi di dato come long long, array a 
lunghezza variabile, e la libreria <stdbool.h> per i booleani.

* `2011-2018`. C11 aggiunse supporto per il multithreading, analisi statica migliorata e gestione degli Unicode. C17
fu principalmente una revisione tecnica che corresse difetti del C11.

* `2023`. L'ultimo standard, C23, introduce ulteriori miglioramenti come attributi standardizzati, nuovi tipi e 
funzionalità moderne mantenendo la filosofia originale del linguaggio.

## Crezione di un eseguibile

Prima di partire con l'effettiva spiegazione del linguaggio, analizziamo come sia possibile, a partire da un semplice
programma che stampa in console la stringa `Hello World from C`, generare un programma da poter eseguire sul calcolatore
corrente:

```C
#include <stdio.h>

int main (int argc, const char** argv) 
{
    printf("Hello World from C\n");
    return 0;
}
```

Considerando che sto usando il compilatore [GCC](https://it.wikipedia.org/wiki/GNU_Compiler_Collection), le fase che
compongono la creazione di un programma eseguibile, partendo dal codice sorgente sopra, sono le seguenti:

1. __Preprocessing__. In questo parte, vegono espanse le macro, sostituite le importazioni delle librerie come
   `stdio.h`, e rimossi i commenti all'interno del programma.

2. __Compilazione__. Successivamente, il programma viene convertito nel relativo codice [Assembly](https://it.wikipedia.org/wiki/Linguaggio_assembly). E'possibile analizzare il codice che viene generato dal compilatore, usando il comando `gcc -S`, il cui risultato sarà quello di un file `.s`, a seconda dell'ottimizzazione che viene fornita al comando.

3. __Assemblaggio__. Il codice Assembly viene generato in un codice macchina binario, chiamato __codice oggetto__
   specifico per la macchina corrente, ma non ancora eseguibile.

4. __Linking__. Infine, per essere reso effettivamente eseguibile il codice oggetto viene associato con le relative
   librerie di sistema che permettano l'effettiva esecuzione del codice oggetto. 

Se state compilando il programma da un sistema operativo basato su UNIX, attraverso il comando `gcc hello_world.c`,
(supponendo che il file contenente il codice sorgente di sopra si chiami `hello_world`), otterrete come risultato il
file `a.out`, ossia l'effettivo eseguibile ottenuto dal risultato del processo precedente.

$$    
 f(x) = x
$$
