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
  
  ### 🪲Debugging und Logging 
   Michael Böckelen 
  
## ⌨️ Designspezifikation
 * Alle Funktionen sollten als `return` value den eigenen Fehler-Datentyp `Snake_ErrorType` verwenden, um Logging zu ermöglichen.
   ### Eingabe
       
  
   ### Spielmechanik
  
* **Globale Variablen:**

Jedes Element der Schlange besitzt eine Position auf dem Spielfeld, diese wird im  `Snake ` Array vom Typ  `snakepart ` gespeichert. Das erste Element des Arrays ist der Schlangenkopf, die anderen Gliedmaßen folgen im Array danach.
```c
snakepart snake[10];
```
Zur einfacheren Umsetzung wird am Anfang der Entwicklungsphase das Snake Array auf 10 Elemente beschränkt. Im Verlauf der Entwicklung wird hierbei jedoch   die `malloc()` Funktion hinzugefügt.

Die Schlangenteile vom Typ  `snakepart` bestehen aus der aktuellen X- und Y-Position und werden durch einen typedef als neuen Typen definiert.
```c
  	 typedef struct{
     		 int pos_X; //X-Position
      		int pos_Y;//Y-Position
    	 }snakepart;
```
Des Weiteren wird die Länge der Schlange in einer Globalen Variable gespeichert.
```c
     	int s_length = 1;  //Schlangenlänge
```      
Diese ist zu Beginn des Spiels 1 und kann durch aufsammeln von Goodys im Laufe des Spiels erhöht werden. Beim einsammel eines Goodys wird die länge der Schlange durch die nachfolgend beschriebene `eat()` Funktion erhöht.

 Auch der Goody wird auf dem Spielfeld dem Spielfeld angezeigt. Damit er angezeigt und von der Schlange gefressen werden kann wird seine Position benötigt. Diese wird in der Globalen Variable
```c 
    	snakepart Goody;  //Goody Position
```      
Goody vom Typ snakepart gespeichert und wird von der randomGoody() Funktion initialisiert und während der Laufzeit verändert.
```c
    	int Score = 0;
```      
Die Ganzzahl Variable Score gibt den aktuellen Punktestand wieder. Zu beginn des Spiels wird dieser auf 0 gesetzt. Wird ein Goody eingesammelt wird durch die eat() Funktion der Score um 10 Pkt. erhöht. 
 Zu besseren Verständnis des Steuereingangs wir ein weitere Typ für die Steuerung des Schlangenkopfs definiert.
 ```c
    	typedef enum{
        	up,  //W oder  ↑
        	down, //S oder ↓
        	left, //A oder ←
       		right //D →
     	}stearing;
```
Die Variable laststearing von dem neuen Typ stearing gibt an, welche Taste zu Letzt gedrückt wurde. Diese wird durch das Eingabemodul verändert.
```c
	stearing last_stearing;
```
Für den Rückgabewert der checkNextStep-Funktion wird ein Datentyp true oder false definiert. Diese gibt an, ob der nächste Zug zum Spielende oder zum verfahren der Schlange führt.
```c
       	typedef enum{
        	false;
       		 true;
     	}boolean;
```
<br><br/>
*  **Funktionen:**

***Initialisierung der wichtigesten Variablen*** <br/>

Initialisiert zu beginn jedes Spiels die Variablen `score = 0`, `snake` alle Elemente außer Snake[0] mit NULL, `s_length = 1`, `soody` mit random Position und startet Startfrequenz des Spiels.
```c
void init(); 
``` 

***Neustart*** <br/>
Setzt das Spielfeld und die Globale Variablen (snake, soody, last_stearing, score, s_length) zurück und startet Spiel erneut.
```c
void restart(); 
``` 

***Neuer Goody*** <br/>
Erzeugt eine zufällig generierte Position für die Goodys. Überprüft beim erzeugen der Position ob das Feld schon belegt ist, wenn nicht wird die Goody-Position zurückgegeben.
```c
snakepart randomGoody();
``` 

***Spielgeschwindigkeit*** <br/>
Die Delay-Funktion ist Taktgeber des Spiels, wird sie aufgerufen wird die angegebene Zeit gewartet. Die Wartezeit wird als Übergabeparameter in Millisekunden und als Ganzzahl angegeben. Zu Beginn soll die Wartezeit 500ms betragen.
 ```c
 void wait(int Waiting_Time_ms);
 ``` 

***Wenn Goody aufgesammlt wird*** <br/>
Überprüft ob Schlangenkopf sich auf Goody bewegt, wenn ja erhöht die Funktion die Schlangenlänge um 1, den Score um 10 Pkt. und eine neue zufällige Goody-Position wird erzeugt. Benötigt die nächste Position vom Schlangenkopf als Snakepart Datentyp. 
```c
void eat(snakepart *next);
```

***Überprüfung des nächsten Schritts*** <br/>
Überprüft ob die nächste Position möglich ist, also ob kein Hinderniss berührt wird. Als Übergabeparameter wird die nächste Position des Schlangenkopfts als Snakepart Datentyp benötigt.
```c
 boolean checkNextStep(snakepart *next); 
 
  //false : Hindernis wird berührt 
  //true : Hindernis wird nicht berührt
	
```

***Bewegung der Schlange*** <br/>
Schiebt die Schlange auf die neue Position. Dazu wird die Position des Schlangenkopfs im Array um 1 Element weiter nach hinten geschoben. Die neue X- und Y-Position wird ind das 0.Element des Arrays, also den Schlangenkopf geschrieben. Als Übergabeparameter wird die nächste Position des Schlangenkopfts als Snakepart Datentyp benötigt.
```c
void move(snakepart *next); 
``` 

***Spielablauf*** <br/>
Regelt den kompletten Spielverlauf, siehe Struktogramm.
```c
Snake_ErrorType game(); 
``` 

<img align="center" width="800" height="600" src="https://abload.de/img/struktogramm-spiel-snz0jum.png"> 

   ### Visualisierung
   
  
    
    


