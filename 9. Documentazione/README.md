- [Commenti e Documentazione](#comments-documentation)
- [Doxygen](#doxygen)

# Documentazione e Doxygen

In questo capitolo affronteremo il tema della documentazione del proprio codice. Quando il proprio programma comincia a
diventare particolaremente complesso, a prescindere dalla presenza o meno di altri sviluppatori nel proprio team, è
buona norma documentare appropriatamente il codice che si produce. 

Oltre che a produrre una buona documentazione interna al codice stesso, è necessario produrre sotto forma di documento
esterno, una documentazione fruibile anche ai non addetti ai lavori. In questo ambito si inquadra [__Doxygen__](www.doxygen.nl),
una libreria utilizzata per produrre documentazione sotto forma di pagina HTML, analizzando la documentazione sotto
forma di commenti inseriti nel codice stesso.

Perchè ritengo che sia così importante la documentazione? Nel tempo ho visto codice sia legacy che non, mal documentato
oppure non documentato per nulla. La mancanza di questa documentazione, si è tradotta nel tempo in mancanza di
comunicazione, ed eventuale allungamento dei tempi per la trasmissione della conoscenza del dominio applicativo. In
termini pratici, questo allungamento dei tempi ha come diretta conseguenza una maggiore spesa da parte del datore di
lavoro, in quanto lo sviluppatore dovrà impiegare più tempo prima di essere effettivamente operativo. 

Inoltre, senza addentrarci troppo in aspetti economici. Prendendo come esempio la libreria che abbiamo sviluppato.
E'bene sapere che alcune funzioni restituiscono una nuova istanza del tipo `String`, anzichè modificare direttamente la
il parametro iniziale. Se da un lato è un'ottima cosa, in quanto si evita di creare sgradevoli effetti collaterali,
dall'altro potrebbero esserci istanze della struttura, che rimangono attive in memoria senza che il programmatore ne sia
effettivamente a conoscenza, il che si traduce in un maggiore consumo di risorse.

## Commenti e Documentazione <a id="comments-documentation"></a>

Nei capitolo precedenti, non abbiamo accennato a cosa siano i commenti nel codice e come possono essere usati. In C come
in molti altri linguaggi di programmazione, è possibile inserire del testo sotto forma di commento, il cui unico scopo è
quello di documentare il codice. I commenti, infatti, sono blocchi di testo che vengono completamente ignorati da parte
del compilatore, e che vengono addiritutta rimossi per rendere l'eseguibile più leggero possibile.

In C è possibile definire tre tipi di commenti, ciascuno dei quali ha un proprio scopo:

* I __commenti a singola riga__ sono caratterizzati dalla combinazione di caratterri iniziali `//`. Commenti di questo
  tipo, sono usati solamente per documentare piccoli pezzi di codice;
* I __commenti a riga multipla__ sono blocchi di testo racchiusi tra i caratteri `/* */`. Diversamente dal caso
  precedente, il testo racchiuso in questi blocchi vengono usati per documentare più accuratamente del codice. Non è un
  caso che questi commenti vengano usati per descrivere più comunemente le funzioni;
* Infine, i __commenti a riga multipla per documentazione__ sono simili ai commenti a riga multipla, con l'unica
  differenza che il blocco iniziale è identificato dalla combinazione di carattere `/**`. Commenti di questo tipo sono
  più articolati e vengono usati per i tool di documentazione come Doxygen. Commenti di questo tipo, sono accompagnati
  da speciali tag che descrivono le parti specifiche del codice.

In questa sezione, analizzeremo come usare correttamente i commenti per la documentazione. Come abbiamo detto, questi
possono essere accompagnati da dei tag identificati dal carattere `@`, i quali descrivono le singole parti del codice. I
tag più comuni che useremo sono:

* `@param <identificativo-parametro> <descrizione>` per descrivere il parametro di una funzione.
* `@return <descrizione>` per descrivere il valore di ritorno associato ad una funzione.
* `@see <riferimento>` che indica il riferimento ad un'altra parte del codice.

## Doxygen <a id="doxygen"></a>

Doxygen è un potente analizzatore di codice in grado di estrarre automaticamente della documentazione, leggendo i
commenti associati alle entità del nostro programma. Per installare Doxygen è possibile rifarsi alla [documentazione
ufficiale](https://www.doxygen.nl/manual/install.html) in cui sono descritti i passaggi per ciascuna piattaforma.

Una volta che Doxygen è stato installato correttamente, per prima cosa è necessario generare un __Doxyfile__. Un
Doxyfile è un file di configurazione, il quale indica a Doxygen le operazioni che quest'ultimo dovrà completare al fine
di creare una corretta documentazione. All'interno di questa cartella è riportato il file di configurazione con il quale
è stato possibile generare la relativa documentazione.

Dopo che è stato creato correttamente il file di configurazione, sarà sufficiente usare il comando:

```sh
doxygen Doxyfile
```

per creare la documentazione che verrà inserita all'interno della cartella `/docs`. All'interno di questa cartella,
saranno inseriti una serie di file HTML e JavaScript, dai quali sarà possibile leggere la documentazione dal browser.
