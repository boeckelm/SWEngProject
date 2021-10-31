## Software Engineering Projekt
Git Repository zur einfacheren kooperativen Bearbeitung der Software Engineering Aufgabe aus dem Informatik III Modul des Elektro- Informationstechnik Studiengangs der Hochschule Landshut.

Gruppenmitglieder: 
* Michael Böckelen - s-mboeck@haw-landshut.de <img align="right" width="150" height="150" src="https://www.haw-landshut.de/fileadmin/Resources/Public/Images/landshut_logo.jpg">
* Tim Gebhard - s-tgebha@haw-landshut.de
* Lukas Sellmaier - s-lsell1@haw-landshut.de  

<br><br />

# Unser Spiel: Snake 🐍

Als Projektziel wurde die Entwicklung des Computerspielklassikers Snake ausgewählt. Das Spiel überzeugt besonders durch seine einfache und intuitive Spielweise, bei gleichzeitig hohen möglichen Komplexitätsgraden in Teilmodulen sowie der nativen Spieloptik auf der Konsole.  

## ⚙️ Anforderungsdefinition

Zu Programmieren ist das  Spiel "Snake" mit den allgemein bekannten Regeln und Spielmechanismen. Bei Snake steuert der Spieler mit der Tastatur den Kopf einer Schlange, um möglichst viele Goodys einzusammeln. Durch Aufsammeln der Goodys wächst die Schlange um eine Längeneinheit und der Spieler erhält Punkte. Ziel des Spielers ist es eine möglichst hohe Punktzahl zu erreichen, ohne dass der Schlangenkopf ein Körperteil oder die Begrenzung des Spielfelds berührt. 

Das komplette Spiel soll in C geschrieben und in der Windows Konsole ausführbar sein, sowie mittels Tastatureingabe zu steuern sein. Weitere elementare Anforderungen werden im Folgenden aufgeführt: 

* Kollisionserkennung des Schlangenkopfes mit einem Element der Schlange oder mit den Spielfeldrändern
* Ungepufferte Tastatureingabe zur sofortigen Ausführung 
* Highscore-Counter, der je aufgenommenem Goody um eins erhöht wird
* Highscore-Liste, die samt einzugebenden Namen in einem File gespeichert wird
* Farbige Konsolenelemente für die Schlange, möglichst unterschiedliche Grüntöne für Kopf und Körper
* Variabler Takt für unterschiedliche Spielgeschwindigkeiten
* Zufälliges Erscheinen der Goodys
* Nach Aufnahme eines Goodys wird Schlange am Kopf erweitert
* Erweiterte Debugmöglichkeiten in Form eines separat abzuspeichernden Log-Files, der alle Spielzüge und mögliche Runtime-Fehler dokumentiert
* Darkmode



## 💡 Architekturspezifikation
  Das Projekt wird in drei größere Modulblöcke, die jeweils verschiedene Funktionsblöcke abbilden, unterteilt. 
  
  ### ⌨️Eingabe 
 ``` Lukas Sellmaier ```
 
 
  In diesem Modul befinden sich die Funktionen welche die Eingabe über die Tastaur ermöglichen.
  * Namen eingeben und überprüfen der Anforderungen
  * Die Steuerung der Schlange über die Tasten ```W``` ```A``` ```S``` ```D```
  * Auf beliebiege Tastertureingabe warten
  


  ### 🏆Rangliste 
  ``` Lukas Sellmaier ```
   
   In diesem Modul wird die Rangliste angelegt sowie ihre Funktionen und das Struct zur übergabe der Daten definiert.
   * Es wird einen TextDatei angelegt, in welcher Zehn  Namen und ihre Punktestände gespeichert werden
   * Zu Beginn enthält sie Zehn Platzhalter mit jeweils Null punkten
   * Über eine Funktion kann man einen neuen Punktestand mit der Liste vergleichen und gegebenenfalls in diese aufnehmen
   * Des weiteren wird hier ein Struct definiert mit dem die Daten anderen Funktionen zur verfügung gestellt werden können

  
## ⌨️ Designspezifikation
 * Alle Funktionen sollten als `return` value den eigenen Fehler-Datentyp `Snake_ErrorType` verwenden, um Logging zu ermöglichen.
   
       
### ⌨️Eingabe 
 ``` Lukas Sellmaier ``` 
 
 
  In diesem Modul werden die Drei Funktionene definiert welche die Eingabe über die Tastatur zu ermöglichen  
   
   <br/>


```req_name(char* ptr)```

- - - -

```req_dir()```
Diese Funktion dient zur Eingabe der Bewegungsrichtung über die Tasten ```W``` ```A``` ```S``` ```D``` .

- - - -

```req_any()```

<br/>

### 🏆Rangliste 

``` Lukas Sellmaier ``` 


 In diesem Modul wird eine ***Textdatei*** angelegt sowie Zwei ***Funktionen*** und das ***Struct*** zur übergabe der Daten definiert.
 Beide Funktionen greifen auf ***Konstanten*** zu, welche die Parameter der Funktionene festlegen.


- - - -

#### Konstanten zum festlegen der Parameter:

<br/>

 + ``` NAME_MAX ```  _Maximale Länge der Namenseingabe **(inclusive /0)**_


 + ``` NUM_ENTRY ```  _Anzahl der maximal in der Liste gespeicherten Elemente_


 + ``` datei_pfad ``` _Adresse an der sich die Textdatei befindet_  
      > Beispiel: ```#define datei_pfad "C:/Users/Lukas/Desktop/bestenliste.txt"```
 
<br/>

- - - -

#### Beispiel für die Textdatei:

<br/>

[liste_beispiel.txt](https://github.com/boeckelm/SWEngProject/files/7449667/liste_beispiel.txt)

Bei verwendung der Beispieldatei ist ``` NAME_MAX 11```  und ``` NUM_ENTRY 10```  festzulegen.

<br/>

- - - -

#### Struktur zur übergabe der Daten:

<br/>

```
    struct highscore {
           char name[NAME_MAX];
           int score;
           }; 
```

 Mit dieser Struktur können alle Namen sowie die dazugehörigen Punktestände gleichzeitig in einem struct array gepeichert werde.
 
> Beispiel: ```struct highescore testliste[NUM_ENTRY]```

<br/>
 
 - - - -
 
 #### Funktionen der Bestenliste:
 
 <br/>
  
+ ```score_out (struct highscore* ptr)```
  Diese Funktion füllt ein Array des Datentypen struct highscore mit den Werten aus der Textdatei.
 
  + Beim Aufrufen wird der Funktion ein Zeiger auf ein  ```struct highescore``` Array übergeben
  + Als erstes wird die Textdatei  mit der Adresse ``` datei_pfad ``` im readonly Modus geöffnet
  + Anschließend werden in einer Schleife die einzelnen Namen und Punktestände aus der Textdatei gelsen und in das Array geschrieben
  + Als letztes wird die Datei wieder geschlossen
  
  <br/>
  <br/>
  
+ ```score_up (int punkte, char* ptr)```
  Diese Funktion Aktualisiert die Textdatei falls der übergeben Punktestand höher als das Letzte Element der Liste ist.
 
  + Beim Aufruf wird der Funktion der Punktestand als ```INT``` sowie der Spielername als ```char``` Zeiger übergeben
  + Als erstes wird ein ```struct highscore``` deklariert und mit der Funktion ```score_out``` initialiert
  + Anschließend werden die Daten aus dem Array mit dem übergebenen Punktestand verglichen und gegebenenfalls Aktualisiert
  + Wenn die Liste Aktualisiert wurde, wird die ***Textdatei*** im Schreibmodus geöffnet und die Namen sowie die Punktestände aus dem ***Struct Arrays*** in die Datei geschrieben
  + Als letztes wird die ***Textdatei*** geschlossen 
 
