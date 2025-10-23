# Tipi, Operatori ed Espressioni

L'elemento "atomico" di un programma è costituito da una variable. Non mi dilungherò su cosa sia una variabile in
qualsiasi linguaggio di programmazione, la cosa che ci interessa sapere, tuttavia, è che i tipi assegnabili ad una
variabile in C, sono relativamente pochi. Tra loro, le variabili possono essere combinate attraverso degli operatori,
formando delle espressioni.

Siccome, come abbiamo detto precedentemente, il C è un linguaggio "a basso livello", tutti i tipi associabili ad una
variabile, hanno una relativa rappresentazione numerica. Di conseguenza, non essendoci una diretta rappresentazione 
delle stringhe, non sono ammissibili operatori nativi per la manipolazione di queste. Diversamente, infatti, da come accade
in un linguaggio come Java, in cui l'operatore `+` permette di concatenare due oggetti di tipo stringa.

Qualsiasi operazione che non coinvolga numeri interi o a virgola mobile, deve essere eseguita mediante la chiamata ad
apposite funzioni. Nel caso specifico delle stringhe, tutte le funzioni utili per la manipolazione delle stringhe, sono
inserite all'interno della libreria `<string.h>`.

## Tipi Primitivi 

Il linguaggio C supporta solamente quattro tipi primitivi: `char`, `int`, `float` e `double`. Ciascuno di questi tipi, 
rappresenta un valore numerico, il che può sembrare strano a chi possieda già una qualche familiarità con i linguaggi
di programmazione, e sia abituato a vedere una variabile di tipo `char` come un semplice carattere interposto tra due
apici. In realtà, in C come in qualsiasi elaboratore, un carattere non è che un numero intero associatovi ad un
carattere attraverso la tabella [ASCII](https://it.wikipedia.org/wiki/ASCII). 

La cosa che ancora di più potrebbe scandalizzare un altro programmatore, è che nel linguaggio C non è garantito che 
questi tipi abbiano una dimensione, in termini di bit, fissa. Sebbene quest'ultima affermazione possa comunque sollevare
dei dubbi a riguarda della sua veridicità, è bene ricordare che quando è stato realizzato il linguaggio C, negli anni
70, non esisteva una completa standardizzazione delle architettura come accade oggi, in cui, la stragrande maggioranza
di calcolatori elettronici funziona su un'architettura a 64 bit. Dunque, l'idea di assegnare questa flessibilità alle
dimensioni dei tipi numerici precedenti, trova la sua spiegazione nell'intento da parte dei suoi creatori, di essere un
linguaggio portabile, che possa essere eseguito su diversi sistemi di calcolo.

Un valore numerico, inoltre, può essere sia di tipo `signed` che di tipo `unsigned`. E'bene sapere, tuttavia, che di
base ciascun valore numerico viene creato con segno, (di conseguenza ciascuna dichiarazione del tipo associatovi ad una
variabile, possiede il prefisso `signed`). Tuttavia, qualora non si ritenga necessario che la variabile non ammetta 
valori numerici negativi, è comunque possibile rendere quest'ultima senza segno, aumentandone, di conseguenza,
il valore numerico limite superiore della stessa variabile.

Oltre che a poter possedere o no il relativo segno, i tipi `int` possono anche essere "estesi" di dimensione,
utilizzando anche i modificatori `short` e `long`. L'impatto di questi modificatori sulle variabili numeriche di tipo
int, sarà quello di "limitare" la dimensione numerica di un valore intero, ad almeno 16 bit per le variabili intere
dichiarate come `short int`, qualora, invece l'architettura preveda che un tipo numerico intero, venga rappresentato
con più di 16 bit. Ugualmente, ma in termini oppositi, il modificatore `long` permette di specificare che il tipo intero,
assuma il valore numerico più grande possibile per la sua rappresentazione nella macchina. Lo standard ANSI C, prevede
che siano usati almento 32 bit per le variabili intere dichiarate come `long int`. Con lo standard `C99` è stato
permesso di dichiarare una variabile come `long long int`, dunque, poter assegnare una rappresentazione a 64 bit di una
variabile intera. Esiste, tuttavia, un'eccezione il modificatore `long` può anche essere utilizzato in contemporanea con
una dichiarazione di un numero in virgola mobile a doppia precisione: `long double`. La diretta conseguenza è la
possibilità di estendere ulteriormente la precisione di una variabile di questo tipo, ad un massimo di 128 bit.

<table>
    <thead>
        <tr>
            <th style="width: 15%">tipo</th>
            <th style="width: 15%">byte / bit</th>
            <th style="width: 15%">min <br \> <code>signed</code></th>
            <th style="width: 15%">max <br \> <code>signed</code></th>
            <th style="width: 15%">min <br \> <code>unsigned</code></th>
            <th style="width: 15%">max <br \> <code>unsigned</code></th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td style="text-align: center;"><code>char</code></td>
            <td style="text-align: center; font-size: 0.8rem;"> 1 byte <br> 8 bit </td>
            <td style="text-align: right; font-size: 0.725rem;"> -128 </td>
            <td style="text-align: right; font-size: 0.725rem;"> 127 </td>
            <td style="text-align: right; font-size: 0.725rem;">0 </td>
            <td style="text-align: right; font-size: 0.725rem;">255 </td>
        </tr>
        <tr style="background-color: rgba(255, 210, 0, 0.2)">
            <td style="text-align: center;"><code>short int</code></td>
            <td style="text-align: center; font-size: 0.8rem;"> 2 byte <br> 16 bit </td>
            <td style="text-align: right; font-size: 0.725rem;"> -32.768 </td>
            <td style="text-align: right; font-size: 0.725rem;"> 32.767 </td>
            <td style="text-align: right; font-size: 0.725rem;"> 0 </td>
            <td style="text-align: right; font-size: 0.725rem;"> 65.535 </td>
        </tr>
        <tr style="background-color: rgba(255, 210, 0, 0.2)">
            <td style="text-align: center;"><code>int</code></td>
            <td style="text-align: center; font-size: 0.8rem;"> 4 byte <br> 32 bit </td>
            <td style="text-align: right; font-size: 0.725rem;"> -2.147.483.648 </td>
            <td style="text-align: right; font-size: 0.725rem;"> 2.147.483.647 </td>
            <td style="text-align: right; font-size: 0.725rem;"> 0 </td>
            <td style="text-align: right; font-size: 0.725rem;"> 4.294.967.295 </td>
        </tr>
        <tr style="background-color: rgba(255, 210, 0, 0.2)">
            <td style="text-align: center;"><code>long int</code></td>
            <td style="text-align: center; font-size: 0.8rem;"> 8 byte <br> 64 bit </td>
            <td style="text-align: right; font-size: 0.725rem;"> -9.223.372.036.854.775.808 </td>
            <td style="text-align: right; font-size: 0.725rem;"> 9.223.372.036.854.775.807 </td>
            <td style="text-align: right; font-size: 0.725rem;"> 0 </td>
            <td style="text-align: right; font-size: 0.725rem;"> 18.446.744.073.709.551.615 </td>
        </tr>
        <tr>
            <td style="text-align: center;"><code>long long int</code></td>
            <td style="text-align: center; font-size: 0.8rem;"> 8 byte <br> 64 bit</td>
            <td style="text-align: right; font-size: 0.725rem;"> -9.223.372.036.854.775.808 </td>
            <td style="text-align: right; font-size: 0.725rem;"> 9.223.372.036.854.775.807 </td>
            <td style="text-align: right; font-size: 0.725rem;"> 0 </td>
            <td style="text-align: right; font-size: 0.725rem;"> 18.446.744.073.709.551.615 </td>
        </tr>
        <tr>
            <td style="text-align: center;"><code>float</code></td>
            <td style="text-align: center; font-size: 0.8rem;"> 4 byte <br> 32 bit </td>
            <td style="text-align: right; font-size: 0.725rem;"> -3,4 × 10<sup>38</sup> </td>
            <td style="text-align: right; font-size: 0.725rem;"> 3,4 × 10<sup>38</sup> </td>
            <td style="text-align: right; font-size: 0.725rem;"></td>
            <td style="text-align: right; font-size: 0.725rem;"></td>
        </tr>
        <tr>
            <td style="text-align: center;"><code>double</code></td>
            <td style="text-align: center; font-size: 0.8rem;"> 8 byte <br> 64 bit </td>
            <td style="text-align: right; font-size: 0.725rem;"> -1,7 × 10<sup>308</sup> </td>
            <td style="text-align: right; font-size: 0.725rem;"> 1,07 × 10<sup>308</sup> </td>
            <td style="text-align: right; font-size: 0.725rem;"></td>
            <td style="text-align: right; font-size: 0.725rem;"></td>
        </tr>
        <tr style="background-color: rgba(255, 210, 0, 0.2)">
            <td style="text-align: center;"><code>long double</code></td>
            <td style="text-align: center; font-size: 0.8rem;"> 16 byte <br> 128 bit</td>
            <td style="text-align: right; font-size: 0.725rem;"> -1,1 × 10<sup>4932</sup></td>
            <td style="text-align: right; font-size: 0.725rem;"> 1,1 × 10<sup>4932</sup></td>
            <td style="text-align: right; font-size: 0.725rem;"></td>
            <td style="text-align: right; font-size: 0.725rem;"></td>
        </tr>
    </tbody>
</table>

Come, tuttavia, si può vedere dalla tabella, alcune righe sono evidenziate con un colore giallo, e richiedono un
un appronfondimento. Infatti, alcuni dei tipi primitivi indicati, come <u>`short int` , `int`, `long int` e `long double`, 
hanno una rappresentazione che dipende dalla specifica architettura del sistema.</u> Il fatto che non esista una garanzia 
sulla loro dimensione, è la diretta conseguenza della portabilità del linguaggio C. Infatti, essendo che questo sia 
stato ideato per essere eseguito per una vasta gamma di altre architetture che esistevano nel secolo scorso, 
non si poteva garantire che esistesse una dimensione fissa per ciascuno di questi tipi.

Ad oggi, possiamo però dire che, nelle architetture `x64` e `x86`, i valori precedenti, POTREBBERO assumere i seguenti
valori:

<table>
    <thead>
        <tr>
            <th style="width: 15%">tipo</th>
            <th style="width: 15%">byte / bit</th>
            <th style="width: 15%">min <br \> <code>signed</code></th>
            <th style="width: 15%">max <br \> <code>signed</code></th>
            <th style="width: 15%">min <br \> <code>unsigned</code></th>
            <th style="width: 15%">max <br \> <code>unsigned</code></th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td rowspan = 2 style="text-align: center;"><code>short int</code></td>
            <td style="text-align: center; font-size: 0.8rem;"> 2 byte <br> 16 bit </td>
            <td style="text-align: right; font-size: 0.725rem;"> -32.768 </td>
            <td style="text-align: right; font-size: 0.725rem;"> 32.767 </td>
            <td style="text-align: right; font-size: 0.725rem;"> 0 </td>
            <td style="text-align: right; font-size: 0.725rem;"> 65.535 </td>
        </tr>
        <tr>
            <td style="text-align: center; font-size: 0.8rem;"> 4 byte <br> 32 bit </td>
            <td style="text-align: right; font-size: 0.725rem;"> -2.147.483.648 </td>
            <td style="text-align: right; font-size: 0.725rem;"> 2.147.483.647 </td>
            <td style="text-align: right; font-size: 0.725rem;"> 0 </td>
            <td style="text-align: right; font-size: 0.725rem;"> 4.294.967.295 </td>
        </tr>
        <tr>
            <td rowspan = 2 style="text-align: center;"><code>int</code></td>
            <td style="text-align: center; font-size: 0.8rem;"> 2 byte <br> 16 bit </td>
            <td style="text-align: right; font-size: 0.725rem;"> -32.768 </td>
            <td style="text-align: right; font-size: 0.725rem;"> 32.767 </td>
            <td style="text-align: right; font-size: 0.725rem;"> 0 </td>
            <td style="text-align: right; font-size: 0.725rem;"> 65.535 </td>
        </tr>
        <tr>
            <td style="text-align: center; font-size: 0.8rem;"> 4 byte <br> 32 bit </td>
            <td style="text-align: right; font-size: 0.725rem;"> -2.147.483.648 </td>
            <td style="text-align: right; font-size: 0.725rem;"> 2.147.483.647 </td>
            <td style="text-align: right; font-size: 0.725rem;"> 0 </td>
            <td style="text-align: right; font-size: 0.725rem;"> 4.294.967.295 </td>
        </tr>
        <tr>
            <td rowspan = 2 style="text-align: center;"><code>long int</code></td>
            <td style="text-align: center; font-size: 0.8rem;"> 4 byte <br> 32 bit </td>
            <td style="text-align: right; font-size: 0.725rem;"> -2.147.483.648 </td>
            <td style="text-align: right; font-size: 0.725rem;"> 2.147.483.647 </td>
            <td style="text-align: right; font-size: 0.725rem;"> 0 </td>
            <td style="text-align: right; font-size: 0.725rem;"> 4.294.967.295 </td>
        </tr>
        <tr>
            <td style="text-align: center; font-size: 0.8rem;"> 8 byte <br> 64 bit </td>
            <td style="text-align: right; font-size: 0.725rem;"> -9.223.372.036.854.775.808 </td>
            <td style="text-align: right; font-size: 0.725rem;"> 9.223.372.036.854.775.807 </td>
            <td style="text-align: right; font-size: 0.725rem;"> 0 </td>
            <td style="text-align: right; font-size: 0.725rem;"> 18.446..744.073.709.551.615 </td>
        </tr>
        <tr>
            <td rowspan = 3 style="text-align: center;"><code>long double</code></td>
            <td style="text-align: center; font-size: 0.8rem;"> 8 byte <br> 64 bit </td>
            <td style="text-align: right; font-size: 0.725rem;"> ± 2,23 × 10<sup>-308</sup> </td>
            <td style="text-align: right; font-size: 0.725rem;"> ± 1,79× 10<sup>308</sup> </td>
            <td style="text-align: right; font-size: 0.725rem;"></td>
            <td style="text-align: right; font-size: 0.725rem;"></td>
        </tr>
        <tr>
            <td style="text-align: center; font-size: 0.8rem;"> 12 byte <br> 96 bit </td>
            <td style="text-align: right; font-size: 0.725rem;"> ± 1,18 × 10<sup>-4932</sup> </td>
            <td style="text-align: right; font-size: 0.725rem;"> ± 1,19× 10<sup>4932</sup> </td>
            <td style="text-align: right; font-size: 0.725rem;"></td>
            <td style="text-align: right; font-size: 0.725rem;"></td>
        </tr>
        <tr>
            <td style="text-align: center; font-size: 0.8rem;"> 16 byte <br> 128 bit </td>
            <td style="text-align: right; font-size: 0.725rem;"> ± 3,36 × 10<sup>-4932</sup> </td>
            <td style="text-align: right; font-size: 0.725rem;"> ± 1,19× 10<sup>4932</sup> </td>
            <td style="text-align: right; font-size: 0.725rem;"></td>
            <td style="text-align: right; font-size: 0.725rem;"></td>
        </tr>
    </tbody>
</table>

In linea generale, tuttavia, lo standard ANSI C garantisce che le varie rappresentazioni, soddisfino i seguenti
standard:

* `int` possiede normalmente la grandezza naturale sulla rappresentazione in macchina.
* `short` sia almeno di 16 bit, ma che non superi in grandezza quella di `int`.
* `long` sia di almeno 32 bit e che la dimensione di `int` non superi quella di `long`.

## Limiti Numerici

Tutte le grandezze precedentemente elencate, sono definite all'interno del file di intestazione `limits.h`. Conoscere le
grandezze dei dati primitivi all'interno del nostro programma, è fondamentale per programmare in un ambiente
multi-piattaforma, sopratutto quando, come nel linguaggio C, questo possa essere tranquillamente eseguito ed ottimizzato
per hardware aventi architetture diverse tra loro, come, ad esempio, dei micro-processori.

Per capire meglio come possono essere usate queste informazioni, rivediamo le precedenti tabelle, stavolta, definendo i
limiti superiori ed inferiori, sia per tipi con segno che senza segno, stavolta, tuttavia, non inserendo direttamente il
valore numerico, ma bensì il relativo valore descritto nella libreria `limits.h`. Inoltre, è bene sapere che per
conoscere l'esatta dimensione di un tipo, sull'architettura corrente, è possibile usare l'operatore `sizeof`:

<table style="width: 100%">
    <thead>
        <tr>
            <th style="width: 15%">tipo</th>
            <th style="width: 15%">byte / bit</th>
            <th style="width: 15%">min <br \> <code>signed</code></th>
            <th style="width: 15%">max <br \> <code>signed</code></th>
            <th style="width: 15%">min <br \> <code>unsigned</code></th>
            <th style="width: 15%">max <br \> <code>unsigned</code></th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td style="text-align: center;"><code>char</code></td>
            <td style="text-align: center; font-size: 0.8rem;"> <code>sizeof(char)</code> </td>
            <td style="text-align: center; font-size: 0.725rem;"> <code>SCHAR_MIN</code> </td>
            <td style="text-align: center; font-size: 0.725rem;"> <code>SCHAR_MAX</code> </td>
            <td style="text-align: right; font-size: 0.725rem;">0 </td>
            <td style="text-align: center; font-size: 0.725rem;"> <code>UCHAR_MAX</code> </td>
        </tr>
        <tr>
            <td style="text-align: center;"><code>short int</code></td>
            <td style="text-align: center; font-size: 0.8rem;"> <code>sizeof(short int)</code> </td>
            <td style="text-align: center; font-size: 0.725rem;"> <code>SHRT_MIN</code> </td>
            <td style="text-align: center; font-size: 0.725rem;"> <code>SHRT_MAX</code> </td>
            <td style="text-align: right; font-size: 0.725rem;"> 0 </td>
            <td style="text-align: center; font-size: 0.725rem;"> <code>USHRT_MAX</code> </td>
        </tr>
        <tr>
            <td style="text-align: center;"><code>int</code></td>
            <td style="text-align: center; font-size: 0.8rem;"> <code>sizeof(int)</code> </td>
            <td style="text-align: center; font-size: 0.725rem;"> <code>INT_MIN</code> </td>
            <td style="text-align: center; font-size: 0.725rem;"> <code>INT_MAX</code> </td>
            <td style="text-align: right; font-size: 0.725rem;"> 0 </td>
            <td style="text-align: center; font-size: 0.725rem;"> <code>UINT_MAX</code> </td>
        </tr>
        <tr>
            <td style="text-align: center;"><code>long int</code></td>
            <td style="text-align: center; font-size: 0.8rem;"> <code>sizeof(long int)</code> </td>
            <td style="text-align: center; font-size: 0.725rem;"> <code>LONG_MIN</code> </td>
            <td style="text-align: center; font-size: 0.725rem;"> <code>LONG_MAX</code> </td>
            <td style="text-align: right; font-size: 0.725rem;"> 0 </td>
            <td style="text-align: center; font-size: 0.725rem;"> <code>ULONG_MAX</code> </td>
        </tr>
        <tr>
            <td style="text-align: center;"><code>long long int</code></td>
            <td style="text-align: center; font-size: 0.8rem;"> <code>sizeof(long long int)</code> </td>
            <td style="text-align: center; font-size: 0.725rem;"> <code>LLONG_MIN</code> </td>
            <td style="text-align: center; font-size: 0.725rem;"> <code>LLONG_MAX</code> </td>
            <td style="text-align: right; font-size: 0.725rem;"> 0 </td>
            <td style="text-align: center; font-size: 0.725rem;"> <code>ULLONG_MAX</code> </td>
        </tr>
    </tbody>
</table>

Tuttavia, come possiamo notare, all'interno dell'intestazione `limit.h`, non sono presenti i valori relativi ai numeri
in virgola mobile. Diversamente, questi sono definiti all'interno di un'altra intestazione, ossia `float.h`:

<table style="width: 100%">
    <thead>
        <tr>
            <th style="width: 15%">tipo</th>
            <th style="width: 15%">byte / bit</th>
            <th style="width: 15%">min <br \> <code>signed</code></th>
            <th style="width: 15%">max <br \> <code>signed</code></th>
            <th style="width: 15%">min <br \> <code>unsigned</code></th>
            <th style="width: 15%">max <br \> <code>unsigned</code></th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td style="text-align: center;"><code>float</code></td>
            <td style="text-align: center; font-size: 0.8rem;"> <code>sizeof(float)</code> </td>
            <td style="text-align: center; font-size: 0.725rem;"><code>FLT_MIN</code></td>
            <td style="text-align: center; font-size: 0.725rem;"><code>FLT_MAX</code></td>
            <td style="text-align: right; font-size: 0.725rem;"></td>
            <td style="text-align: center; font-size: 0.725rem;"></td>
        </tr>
        <tr>
            <td style="text-align: center;"><code>double</code></td>
            <td style="text-align: center; font-size: 0.8rem;"> <code>sizeof(double)</code> </td>
            <td style="text-align: center; font-size: 0.725rem;"> <code>DBL_MIN</code> </td>
            <td style="text-align: center; font-size: 0.725rem;"> <code>DBL_MAX</code> </td>
            <td style="text-align: right; font-size: 0.725rem;"></td>
            <td style="text-align: center; font-size: 0.725rem;"></td>
        </tr>
    </tbody>
</table>

## Rappresentazioni con dimensione fissa

Per ovviare in parte al problema che è stato prima citato, relativo ad alcuni tipi numerici. Dallo standard `C99` è
stata introdotta la libreria `stdint.h`. Lo scopo di questa libreria è quello di esporre un insieme di tipi, la cui
rappresentazione numerica è garantita essere per qualsiasi architettura. 
<div style="width: 100%; display: inline-flex; flex-direction: column; justify-content: center; align-items: center;">
    <table style = "width: 90%;">
        <thead>
            <tr>
                <th style="width: 25%"><code>signed / unsigned</code></th>
                <th style="width: 25%">tipo</th>
                <th style="width: 25%">byte</th>
                <th style="width: 25%">bit</th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td style="text-align: center;"><code>signed</code></td>
                <td style="text-align: center; font-size: 0.8rem;"> <code>int8_t</code> </td>
                <td style="text-align: right; font-size: 0.725rem;">1</td>
                <td style="text-align: right; font-size: 0.725rem;">8</td>
            </tr>
            <tr>
                <td style="text-align: center;"><code>unsigned</code></td>
                <td style="text-align: center; font-size: 0.8rem;"> <code>uint8_t</code> </td>
                <td style="text-align: right; font-size: 0.725rem;">1</td>
                <td style="text-align: right; font-size: 0.725rem;">8</td>
            </tr>
            <tr>
                <td style="text-align: center;"><code>signed</code></td>
                <td style="text-align: center; font-size: 0.8rem;"> <code>int16_t</code> </td>
                <td style="text-align: right; font-size: 0.725rem;">2</td>
                <td style="text-align: right; font-size: 0.725rem;">16</td>
            </tr>
            <tr>
                <td style="text-align: center;"><code>unsigned</code></td>
                <td style="text-align: center; font-size: 0.8rem;"> <code>uint16_t</code> </td>
                <td style="text-align: right; font-size: 0.725rem;">2</td>
                <td style="text-align: right; font-size: 0.725rem;">16</td>
            </tr>
            <tr>
                <td style="text-align: center;"><code>signed</code></td>
                <td style="text-align: center; font-size: 0.8rem;"> <code>int32_t</code> </td>
                <td style="text-align: right; font-size: 0.725rem;">4</td>
                <td style="text-align: right; font-size: 0.725rem;">32</td>
            </tr>
            <tr>
                <td style="text-align: center;"><code>unsigned</code></td>
                <td style="text-align: center; font-size: 0.8rem;"> <code>uint32_t</code> </td>
                <td style="text-align: right; font-size: 0.725rem;">4</td>
                <td style="text-align: right; font-size: 0.725rem;">32</td>
            </tr>
            <tr>
                <td style="text-align: center;"><code>signed</code></td>
                <td style="text-align: center; font-size: 0.8rem;"> <code>int64_t</code> </td>
                <td style="text-align: right; font-size: 0.725rem;">8</td>
                <td style="text-align: right; font-size: 0.725rem;">64</td>
            </tr>
            <tr>
                <td style="text-align: center;"><code>unsigned</code></td>
                <td style="text-align: center; font-size: 0.8rem;"> <code>uint64_t</code> </td>
                <td style="text-align: right; font-size: 0.725rem;">8</td>
                <td style="text-align: right; font-size: 0.725rem;">64</td>
            </tr>
        </tbody>
    </table>
</div>

Prima di concludere, nella tabella è stato citato l'operatore `sizeof`. Questo particolare operatore nativo del C,
restituisce l'effettiva dimensione di una variabile o di un tipo, sotto forma di un valore numerico `unsigned long int`,
rappresentato dal tipo `size_t`. Questo operatore è molto utile per leggere l'effettiva rappresentazione di una variabile
nell'architettura corrente, inoltre, è comunemente restituito da molte funzione della libreria standard del C.

## Conversione dei Tipi

Un aspetto fondamentale dei tipi primitivi che abbiamo descritto precedentemente, riguarda la capacità del linguaggio di
convertire un tipo assegnato ad una variabile in un altro compatibile. Con il termine "compatibile" si intende dire, un
corrispondente tipo, appartenente alla stessa famiglia. Ovviamente, non sarà mai possibile convertire un tipo composto,
in un valore numerico. Tuttavia, come vedremo sarà possibile convertire tra loro i valori numerici, con alcune
accortezze.

Considerando che anche i caratteri `char` sono trattati nel linguaggio C come dei valori numerici. Da adesso,
considereremo solamente conversioni che coinvolgono valori numerici. Quando parliamo di conversione tra valori numerici,
occorre fare una differenza in:

* __Conversioni Implicite__ se sono applicate direttamente dal compilatore.
* __Conversioni Esplicite__ quando è il programmatore ad indicare esplicitamente il tipo di destinazione da cui
  convertire una variabile di partenza.

La conversione di variabili, tuttavia, può avere o no degli effetti collaterali. In tal caso si parla di perdita di
informazione, nel momento in cui un tipo più grande, viene forzato ad essere inserito all'interno di un tipo più
piccolo. L'esempio che segue mostra lo scenario descritto:

```c
float a_number = 1.123;
unsigned int another_number = (unsigned int)a_number;

printf("a_number = %f, has been converted in %ud, loosing some information ...", a_number, another_number);
```

L'istruzione `(unsigned int)a_number;` esegue una conversione esplicita della variabile `a_number` troncando la parte
frazionaria e forzandola ad essere inserita all'interno di una variabile `unsigned int`. Il compilatore, avvertirà con
un messaggio della perdita di informazione, nella conversione della variabile.
