- [Tipi, Operatori ed Espressioni](#types-operators-expressions)
- [Tipi Primitivi](#primitive-data-types)
- [Limiti Numerici](#numerical-limits)
- [Rappresentazione Numerica Fissa](#fixed-length-representation)
- [Conversione dei Tipi](#casting)
- [Modificatori di Accesso](#access-keywords)
    - [Variabili Costanti](#constant-variables)
    - [Variabili Statiche](#static-variables)
    - [Argomenti Costanti](#const-arguments)
    - [Funzioni Statiche](#static-functions)

# Tipi, Operatori ed Espressione <a id="types-operators-expressions"></a>

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

## Tipi Primitivi <a id="primitive-data-types"></a>

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

## Limiti Numerici <a id="numerical-limits"></a>

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

## Rappresentazioni con Dimensione Fissa <a id="fixed-length-rappresentation"></a>

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

## Conversione dei Tipi <a id="casting"></a>

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

## Modificatori di accesso <a id="access-keywords"></a>

Insieme alla definizione di un variabile, è possibile applicare un modificatore, che ne modifica il normale
comportamento all'interno di un programma. I modificatori di accesso più comuni sono: `const` e `static`.

### Variabili Costanti <a id="constant-variables"></a>
Fino a questo punto, nella dichiarazione di una qualsiasi variabile, che sia essa anche un argomento di una funzione,
non abbiamo specificato alcun vincolo, se non il tipo di valore assegnabile a questo. Qualora decisdessimo di rendere
una qualsiasi variabile immutabile, sarà sufficiente anteporre alla dichiarazione della variabile il prefisso `const`.

Prendiamo ad esempio questo piccolo programma, che inizializza ed una una serie di variabili da mostrare in console:

```c
#include <stdio.h>

int main (const int argc, const char** argv)
{
    const int my_constant_variabile = 10;
    int my_variable = 50;

    printf("Before Assignment, 'my_constant_variable' = %d and 'my_variable' = %d\n", my_constant_variable, my_ariable);

    my_constant_variable = my_variable;
    my_variable = my_constant_variable;

    printf("After Assignment, 'my_constant_variable' = %d and 'my_variable' = %d\n", my_constant_variable, my_ariable);

    return 0;
}
```

La compilazione di questo programma è impossibile, in quanto non è ammissibile modificare il valore inizializzato ad una
variabile definita come costante. Sebbene in questo caso abbiamo usato il modificatore `const` per una singola
variabile, nel caso in cui il primo si applichi ad un vettore, o ad un puntatore che si riferisce ad una sequenza di
elementi. Non sarà possibile modificare la sequenza o ciascun elemento appartenente a quest'ultima,

### Argomenti Costanti <a id="const-arguments"></a>

Il modificatore `const` può anche essere applicato ai parametri di una funzione. Analizzando l'esempio precedente,
possiamo notare la dicitura:

```c
int main (const int argc, const char** argv)
```

ignorando cosa siano a parametri alla funzione main, possiamo notare che, invece, questi siano preceduti entrambi dalla
parola chiave `const`. All'interno di questa funzione, i parametri non potranno essere modificati.


### Variabili Statiche <a id="static-variables"></a>

Oltre che al modificatore `const`, alla dichiarazione di una variabile può essere applicata anche la parola chiave
`static`. Potremmo definire una variabile __statica__, come una variabile il cui ciclo di vita è indipendente dalla
visibilità del contesto in cui inserita. 

Analizziamo che cosa accade se usassimo questo modificatore ad una variabile locale di una funzione:


```c
float sum_with_scaling_factor (const int first, const int second)
{
    static float scaling_factor = 2.0;
    const int result = (first + second) * scaling_factor;
    scaling_factor = scaling_factor + 2.0;
    return result;
}

int main (const int argc, const char** argv)
{
    float result = sum_with_scaling_factor(1, 2);
    result = sum_with_scaling_factor(1, 2);

    printf("'sum_with_scaling_factor' = %f\n", result);
    return 0;
}
```

Comprensibilmente, potremmo aspettarci di vedere a video il valore `6`, quando in realtà verrà visto il valore `12`.
Questo comportamento apparentemente "anomalo" è spiegato dalla presenza del modificatore `static` associato alla variabile
`result`.

L'uso del modificatore `static` rende di fatto la variabile permamente in memoria, dissociandola dallo scope che vi
associa la funzione. Pertanto, nell'istruzione `result = sum_with_scaling_factor(1, 2)`, sebbene incontriamo nuovamente
la dichiarazione `static float scaling_factor = 2.0`, il programma è autonomamente in grado di capire che esiste già una
variabile chiamata `scaling_factor` in memoria, è riprendere il valore precedentemete associatovi a questa, come se
ignorasse quest'inizializzazione.

In termini generali, possiamo dire che qualsiasi variabile a cui è associato il modificatore `static`, che sia globale o
locale, viene dissociata dal proprio scope. Pertanto, la variabile statica avrà un ciclo di vita indipendente da dove si
trova. 

L'uso di questo modificatore è particolarmente utile quando vogliamo dichiarare costanti che non cambieranno nel tempo,
il che ci permetterà di rispariare risorso nella dichiarazione multipla della stessa costante in diverse aree di
visibilità del programma.

### Funzioni Statiche <a id="static-functions"></a>

L'uso del modificatore `static` può essere impiegato anche nella dichiarazione di una funzione. Per spiegare meglio
quali siano le conseguenze dell'uso di questo modificatore nella dichiarazione di una funzione, consideriamo di aver
creato un file denonimato `operations.c` al cui interno sono dichiarate le seguente funzioni:

```c
static int sum (const int first, const int second)
{
    return first + second;
}

int difference (const int first, const int second)
{
    return sum(first, -second);
}
```

Immaginiamo di voler usare queste funzioni in questo modo:

```c
#include <stdio.h>

#include "operations.c"

int main (const int argc, const char** argv)
{
    int sum_result = sum(1, 2);
    int difference_result = difference(1, 2);

    printf("'sum_result' = %d, 'difference_result = %d'\n", sum_result, difference_result);

    return 0;
}
```

Non sarà mai possibile compilare questo programma, perché non siamo in grado di usare la funzione `sum` all'interno del
file `main.c`, in cui ne è definito l'uso.

E' bene sapere che la dichiarazione di una funzione, normalmente, definisce la visibilità della funzione stessa come
globale e disponibile all'interno di tutto il programma. Il modificatore `static` applicato in questa maniera ad una 
funzione, limita la visibilità della funzione stessa all'interno del file in cui questa è definita.

Di conseguenza, l'uso di `static` per una funzione permette di definire il meccanismo di [__Information
Hiding__](https://en.wikipedia.org/wiki/Information_hiding). Dichiarando una funzione in questo modo, siamo in grado di
limitare la visibilità della stessa all'interno del file in cui è definita, come se usassimo il modificatore di
visibilità `private` per un'attributo di una classe.
