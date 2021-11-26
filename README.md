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
  * Tastaturabfrage ob J gedrückt wurde
  


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

 <br/>
 
  In diesem Modul werden die Drei Funktionen definiert, welche die Eingabe über die Tastatur ermöglichen.
   Diese sind die Namenseingabe , die Richtungsabfrage und die Bestätigung durch die Taste J.
  
  <br/>
  
   Folgende Global Definierten Variablen werden in diesem Modul genutzt:
   * `spielername[MAX_NAME]`
   * `int last_stearing`

   Sowie die Folgenden definierten Konstanten:
  *	`NAME_MAX`
  *	`NUM_ENTRY` 

<br/><br/>
 
 ### Funktionen der Eingabe:
 
 <br/>

```snake_eing_name()```

Diese Funktion dient zur Eingabe des Spielernamens über die Tastatur.

 + Zuerst wird ein String der Länge `NAME_MAX` über `stdin` eingelesen. Zu viel eingegeben Tasten werden ignoriert. Falls zu wenig Tasten eingelesen wurden, wird der String mit `-` aufgefüllt.
Anschließend wird der String in die Globale variabel `spielername[MAX_NAME]` kopiert.
 
 <br/><br/>
  
```snake_eing_dir()```

Diese Funktion dient zur Eingabe der Bewegungsrichtung über die Tasten ```w``` ```a``` ```s``` ```d``` .

 + Über die Funktion `_kbhit` wird der Tastaturpuffer abgefragt. Wenn dieser `ungleich 0` ist, wird der Wert über `_getch` einer `char Variablen` zugewiesen. Diese Variable wird anschließend über eine `Switch-Case` Anweisung ausgewertet und je nach eingelesener Taste der Globale Wert `last_stearing verändert`. Hierfür wird das in `"Spielsteuerung.h"` definierte `enum stearing` verwendet.
 
 <br/><br/>
  
 ```bool snake_eing_any()```


Diese Funktion dient zur Bestätigung durch die Tasten J.

 + Über `_getch` wird eine `char Variable` eingelesen. Wenn diese dem Wert `J` bzw. `j` entspricht, wird `true` als Rückgabewert ausgegeben. Alle anderen Eingaben führen zu einem Rückgabewert `false`. Diese Rückgabewerte sind vom Typ `bool` und wurden in `"Spielsteuerung.h"` definierte definiert. 

<br/>

- - - -

<br/>

### 🏆Rangliste 

``` Lukas Sellmaier ``` 


 In diesem Modul werden die Drei Funktionen definiert mit welcher die Bestenliste initialisiert, ausgegeben und aktualisiert werden kann.
 
 
<br/>

  Folgende Global Definierten Variablen werden in diesem Modul genutzt:
  * `spielername[MAX_NAME]`
  * `struct highscore score_temp[NUM_ENTRY]`

  Sowie die Folgenden definierten Konstanten:
  * NAME_MAX
  * NUM_ENTRY

<br/>

  Das `struct highscore` ist ebenfalls hier Definiert:
```
    struct highscore {
           char name[NAME_MAX];
           int score;
           }; 
```
In diesem Struktur werden alle Namen sowie die dazugehörigen Punktestände gleichzeitig in einem `struct Array` gepeichert werde.

<br/><br/>

 ### Funktionen der Bestenliste:
 
 <br/>
 
 ```snake_best_init()```
 
 Diese Funktion dient zum Erstellen sowie der initialisierung der Text Datei. Und wird im Programm nur einmal ausgeführt.
 
 + Zuerst wird überprüft ob bereits eine Datei mit diesen Namen existiert. In diesen Fall wird die Funktion beendet. Andernfalls wird eine Datei erzeugt und ein Datenstrom im `Write-Modus` geöffnet. Anschließend werden `NUM_ENTRY` (Anzahl) Werte in die Text Datei geschrieben. Nach der Initialisierung enthält die Datei `NUM_ENTRY` (Anzahl) identische Einträge mit jeweils Null Punkten. Als letztes wird der Datenstrom geschlossen.
 
 <br/><br/>
  
 ```snake_best_out()```
 
  Mit dieser Funktion wird die Globale variable `struct highscore score_temp[NUM_ENTRY]` mit den aktuellen Werten aus der Bestenliste-Datei befüllt.
 
  + Zu beginn wird ein Datenstrom zur `Bestenlisten-Datei` im `Read-Modus` geöffnet. Nun werden in einer Schleife die Werte der Namen aus der Datei in die Globale variable `struct highscore score_temp[NUM_ENTRY]` kopiert, sowie die dazugehörigen Punktestände. Die Punktestände werden vor der Speicherung als `string` in einen hilfs-string gespeichert und anschließend mit der Funktion `atoi()` in einen `int` Wert gewandelt.
  
  <br/><br/>
 
 ```snake_best_up(int)```
 
  Diese Funktion aktualisiert die Globale `struct highscore score_temp[NUM_ENTRY]`, sowie die `Text-Datei`, mit dem Übergebenen Punktestand und dem Global definierten `spielername[MAX_NAME]`.
 
 + Als erstes wird die zu vergleichende Liste über die Funktion `snake_best_out()` geholt. Nun wird der Punktestand mit allen Punkteständen des Arrays verglichen und gegebenenfalls zusammen mit dem Spielernamen in das Array einsortiert. Wenn bereits ein Eintrag mit dem Gleichen Punktestand vorhanden ist, wird der neu unterhalb dessen eingefügt. Es können immer nur maximal `NUM_ENTRY` (Anzahl) Einträge im Array gespeichert werden.
 + Anschließend wird die die Angegeben `Datei` im `Write-Modus` geöffnet und das Aktualisierte Array formatiert in diese geschrieben. Es können wieder nur maximal `NUM_ENTRY` (Anzahl) Einträge in der Bestenliste gespeichert werden. Als letztes wird der Datenstrom wieder geschlossen.
 
