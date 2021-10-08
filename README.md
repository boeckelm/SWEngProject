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
  Das Projekt wird in mehrere größere Modulblöcke, die jeweils verschiedene Funktionsblöcke abbilden, unterteilt:  
  
  ### ⌨️Eingabe 
  
   `Lukas Sellmaier`
  
  
  ### 🎮 Spielmechanik 
  
  Tim Gebhard
  
  ### 🖥️ Visualisierung  
` Michael Böckelen`    
Diese Modul ist für sämtliche Ausgaben auf dem Terminal verantwortlich und stellt entsprechende Schnittstellen von reiner Textausgabe bin hin zur Spielvisulisierung zur        Verfügung. Als Rückgabewert wird der jeweils der Error-Struct, beschrieben in `Debugging und Logging`, verwendet. Folgende Schnittstellen sollen erzielt werden:
* Reine Textausgabe in gewohnter Form, damit es bei einer Ausgabe während des Spiels nicht zu Grafikfehlern oder ähnlichem kommt.

  
### 🏆 Rangliste 
  `Lukas Sellmaier`
  
### 🐞 Debugging und Logging 
  ` Michael Böckelen`  
Diese Modul stellt Schnittstellen zur besseren Fehlerdokumentation zur Verfügung.  
* Um einen **einheitlichen und auswertbaren Rückgabewert** zur Verfügung zu stellen, wird die Datenstrukur `Snake_DBG_t` erstellt. Diese beinhaltet einen ganzzahligen Statuscode sowie einen String zur Fehlerbeschreibung.   
Als Statuscodes sollen die Enums `SNAKE_SUCCESS` und `SNAKE_FAIL` verwendet werden.  
Sollte der Statuscode SNAKE_FAIL samt Fehlerbeschreibung übermittelt werden, wird die Struktur zusammen mit einem Zeitstempel in eine Text-Datei geschrieben.   
Diese Struktur sollte wo immer möglich als Rückgabewert einer Funktion verwendet werden. Beispiele sind in der Designspezifikation zu finden.

  
## ⌨️ Designspezifikation
 * Alle Funktionen sollten als `return` value den eigenen Fehler-Datentyp `Snake_ErrorType` verwenden, um Logging zu ermöglichen.
   ### Eingabe
       
  
   ### Spielmechanik
        randomGoody();
        void restart();
  
   ### Visualisierung
   

    
    


