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
  Lukas Sellmaier  
  In diesem Modul befinden sich die Funktionen welche die eingabe über die tastaur ermöglichen.
  * Namen eingeben und überprüfen der Anforderungen
  * Die steuerung der Schlange über die Tasten W A S D
  * Auf beliebiege Tastertureingabe warten
  
  ### 🎮Spielmechanik 
   ##### wird Programmiert und Entwickelt von Tim Gebhard
   
Das Modul der Spielsteuerung steuert den Programmablauf sowie die Spielmechanik.

* Programmablauf: 
Nach Start des Spiels soll zu Beginn die Bestenliste angezeigt werden. Der Benutzer soll dann aufgefordert werden eine Eingabe zu seinem gewünschten Spielername zu                    machen. Nach Bestätigen der Eingabe soll das Spiel gestartet werden. D. h. das Spielfeld soll erscheinen und die Schlange sollte anfangen sich mit einer bestimmten                    Geschwindigkeit zu bewegen. Berührt die Schlange sich selbst oder eine der vier Rändern, wird das Spiel beendet. Der Benutzter soll anschließend eine Ausgabe zusehen                  bekommen, in     der er nochmals sein erreichten Punktestand sehen kann. Danach wird die abgespeicherte Bestenliste angezeigt und der Benutzer wird gefragt, ob er nochmals         spielen möchte.

* Spielmechanik:
Während dem Spiel verarbeitet die Spielsteuerung die Eingabe des Benutzers, sodass die Schlangen auf dem Spielfeld in die gewünschte Richtung gesteuert werden kann. Dabei sollen  die einzelnen Elemente (Körperteile) der Schlange den vorherigen Elementen folgen, wie in einer Kette. Der Schlangenkopf gibt hierbei die Richtung der kompletten Schlangen vor.    Während des Spiels wird auch überprüft, ob der Schlangenkopf ein Teil der Schlange oder die Spielbegrenzung berührt.
Fährt die Schlange über einen durch die Spielmechanik zufällig auf dem Spielfeld generierten Goody, so wird diese am Kopf um ein weiteres Element (Körperteil) erweitert und der     Punktestand des Spielers wird erhöht.

  
  ### 🖥️Visualisierung 
   Michael Böckelen 
  
  ### 🏆Rangliste 
   Lukas Sellmaier  
   In diesem Modul wird die Rangliste angelegt sowie ihre Funktionen und das Struct zur übergabe der Daten definiert.
    * Es wird einen TextDatei angelegt, in welcher Zehn  Namen und ihre Punktestände gespeichert werden
    * Zu Beginn enthält sie Zehn Platzhalter mit jeweils Null punkten
    * Über eine Funktion kann man einen neuen Punktestand mit der Liste vergleichen und gegebenenfalls in diese aufnehmen
    * Des weiteren wird hier ein Struct definiert mit dem die Daten anderen Funktionen zur verfügung gestellt werden können
    
  ### 🪲Debugging und Logging 
   Michael Böckelen 
  
## ⌨️ Designspezifikation
 * Alle Funktionen sollten als `return` value den eigenen Fehler-Datentyp `Snake_ErrorType` verwenden, um Logging zu ermöglichen.
   ### Eingabe
       
  
   ### Spielmechanik
        randomGoody();
        void restart();
  
   ### Visualisierung
   
   ### Der Super Strukt (Designed bei Michael)
    
    


