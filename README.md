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
* Erweiterte Debugmöglichkeiten in Form eines separat abzuspeichernden Log-Files, der mögliche Runtime-Fehler dokumentiert
* Darkmode



## 💡 Architekturspezifikation
  Das Projekt wird in mehrere größere Modulblöcke, die jeweils verschiedene Funktionsblöcke abbilden, unterteilt:  
  
  ### ⌨️Eingabe 
  
   `Lukas Sellmaier`
  
  ### 🎮 Spielmechanik 
  
  Tim Gebhard
  
  ### 🖥️ Visualisierung  
` Michael Böckelen`    
Diese Modul ist für sämtliche Ausgaben auf dem Terminal verantwortlich und stellt entsprechende Schnittstellen zur Verfügung. Als Rückgabewert wird der jeweils der `Snake_DBG_t`-Struct, beschrieben in `Debugging und Logging`, verwendet.

* **Hauptaufgabe: Visualisierung des Spiels**  
Zu Anfang des Spiels soll das Spielfeld mit Hilfe der zu übergebenden `Snake_VS_init_t` Struktur im Terminal initalisiert werden. Die Struktur beinhaltet die Größe und eine mögliche Darkmode-Einstellung. Die Funktion cleared das Terminal und gibt die Ränder des Spielfeldes aus.
* Während des Spiels müssen die Positionen der Elemente laufend angepasst werden. Dafür gibt es eine Update-Funktion, der die Koordinaten des **Schlangenkopfes, des Schlangenendes und die der Knickstellen**, sowie die des Goodys, übergeben werden. Zur besseren Vorstellung ein Bild:  

* <img align="center" width="541" height="210" src="https://abload.de/img/snake_2plk7l.png"> 
* Für die einzelnen Koordinaten soll der Struct `Snake_Vektor_t`, der je eine ganzzahlige x und y Variabe besitzt, verwendet werden. Zur Übergabe an die Update-Funktion soll dann der `Snake_VS_Update_t` Struct verwendet werden, genaueres in den Designspezifikationen.

* Zur reinen Textausgabe in gewohnter Format-String-Form soll eine Funktion erstellt werden, die eine Ausgabe auch während des Spiels ohne Grafikfehler oder ähnlichem ermöglicht.
* Ausgabe eines Spielende-Screens samt Rangliste, hierbei orientiert sich die Übergabe am Ranglisten-Modul.

  
### 🏆 Rangliste 
  `Lukas Sellmaier`
  
### 🐞 Debugging und Logging 
  ` Michael Böckelen`  
Dieses Modul stellt Schnittstellen zur besseren Fehlerdokumentation zur Verfügung.  
* Um einen **einheitlichen und auswertbaren Rückgabewert** zur Verfügung zu stellen, wird die Datenstrukur `Snake_DBG_t` erstellt. Diese beinhaltet einen ganzzahligen Statuscode, ein Severity-Level (Schweregrad) sowie einen String zur Fehlerbeschreibung.   
Als Statuscodes sollen die Enums `SNAKE_SUCCESS` und `SNAKE_FAIL` verwendet werden, als Severity-Levels jene des Severity Enums von `SNAKE_DEBUG` bis `SNAKE_FATAL`.   
Diese Struktur sollte wo immer möglich als Rückgabewert einer Funktion verwendet werden. Beispiele und Details sind in der Designspezifikation zu finden.

* Zur allgemeinen Abspeicherung von Debug-Daten wird eine Funktion erstellt, der man eine Zeichenkette sowie einen Severity-Grad übergeben kann.

* Sollte der Statuscode `SNAKE_FAIL` als Rückgabewert übergeben werden, oder ein separater Debug-Eintrag mittels vorheriger Funktion gewünscht sein, werden diese Daten zusammen mit einem Zeitstempel in eine Datei geschrieben. 
  
## ⌨️ Designspezifikation
 * 
   ### Eingabe
       
  
   ### Spielmechanik
        randomGoody();
        void restart();
  
   ### Visualisierung
   

    
    


