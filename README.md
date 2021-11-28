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
   ##### wird Programmiert und Entwickelt von `Tim Gebhard`

Im Modul der Spielsteuerung wird die Spielmechanik, also die Spiellogik und der Programmablauf gesteuert. Die nachfolgenden Punkte gehen darauf näher ein.		

* Programmablauf: 
Programmablauf: Nach Start des Spiels soll zu Beginn der Startbildschirm angezeigt werden. Der Benutzer soll dann aufgefordert werden eine Eingabe zu seinem gewünschten Spielernamen zu machen. Nach Bestätigen der Eingabe soll das Spiel gestartet werden. D. h. das Spielfeld soll erscheinen und die Schlange sollte anfangen sich mit einer bestimmten Geschwindigkeit zu bewegen. Das Spiel wird so lange gespielt bis die Schlange sich selbst oder eine der vier Ränder berührt. Nachdem das Spiel beendet wurde, soll der Benutzter eine Ausgabe zusehen bekommen, in der er nochmals sein erreichter Punktestand sehen kann. Die abgespeicherte Bestenliste wird angezeigt und der Benutzer wird gefragt, ob er nochmals spielen möchte. Wenn dieser nochmal spielen möchte, wird das Spiel neu gestartet.

[![Bild programmablauf7fk7y.png auf abload.de](https://abload.de/img/programmablauf7fk7y.png)](https://abload.de/image.php?img=programmablauf7fk7y.png)


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
  
* **Globale Variablen der Spielsteuerung:**

Jedes Element der Schlange besitzt eine Position auf dem Spielfeld, diese wird im  `Snake ` Array vom Typ  `snakepart ` gespeichert. Das erste Element des Arrays ist der Schlangenkopf, die anderen Gliedmaßen folgen im Array danach.
```c
snakepart snake[100];
```
Zur einfacheren Umsetzung wird am Anfang der Entwicklungsphase das Snake Array auf 100 Elemente beschränkt.

Die Schlangenteile vom Typ  `snakepart` bestehen aus der aktuellen X- und Y-Position und werden durch einen typedef als neuen Typen definiert.
```c
  	 typedef struct{
     		 int pos_X; //X-Position
      		int pos_Y;//Y-Position
    	 }snakepart;
```
Des Weiteren wird die Länge der Schlange in einer globalen Variable gespeichert. Die Variable wird benötigt, um die Anzahl der gültigen Elemente im 'Snake[]'Array um eins zu erweitern, d.h. wenn ein neues Element der Schlange hinzugefügt werden muss, wird das Array um ein Element weiter durchlaufen.
```c
     	int s_length = 1;  //Schlangenlänge
```      
Zu Beginn des Spiels wird die Variable auf eins initialisiert und kann durch Aufsammeln von Goodys im Laufe des Spiels erhöht werden. Beim Einsammeln eines Goodys wird die Länge der Schlange durch die nachfolgend beschriebene `eat()` Funktion erhöht.

Zudem benötigt das Spielfeld auch die Position eines Goodys, damit er von der Schlange gefressen werden. Das Goody ist wieder vom Type `snakepart` und enthält somit X- und Y-Koordinaten. Werden diese Koordinaten von dem Schlangenkopf erreicht, wird dieser von der Schlange gefressen. Folglich wird jetzt eine neue Goody Postion benötigt, die durch die Funktion `randomGoody()` generiert werden. 
```c 
    	snakepart Goody;  //Goody Position
```      
Für den Spieler ist es wichtig möglichst viele Goody mit der Schlange zu fressen. Durch das fressen `eat()` der Goodys wird der Score um 10 Punkte erhöht. 
```c
    	int Score = 0;
```      
Zu Beginn des Spiels wird der Score mit 0 initialisiert, da der Spieler noch keine Punkte erreicht haben kann.
Zu besseren Verständnis des Steuereingangs wird ein weiterer Typ für die Steuerung des Schlangenkopfs definiert. Dort wurde auch gleich der ASCII-Code der einzelnen Zeichen hinterlegt.
 ```c
    	typedef enum {
    	    up = 119,  //W 
    	    down = 115, //S 
    	    left = 97, //A 
    	    right = 100//D 
	}stearing;
```
Um die aktuelle Steuereingabe vom Benutzer erfassen zu können, wurde vom Typ `stearing` eine Variable des letzten Eingangs erzeugt. Diese wird von der Steuerung ständig abgefragt und nur durch das `Eingabemodul` verändert.
```c
	stearing last_stearing;
```
Für den Rückgabewert der `checkNextStep()`-Funktion wird ein Datentyp true oder false definiert. Diese gibt an, ob der nächste Zug zum Spielende oder zum Verfahren der Schlange führt.
```c
       	typedef enum{
        	false;
       		 true;
     	}bool;
```
---
*  **Funktionen der Spielsteuerung:**

***Initialisierung der wichtigesten Variablen*** <br/>

Die `init()`-Funktion initialisiert zu Beginn jedes Spiels die Variablen `Score=0`, alle Elementer des `Snake`-Arrays mit NULL und setzt Startposition in `Snake[0]`. Es wird das `Goody` mit einer zufälligen Position gefüllt, der Startbildschirm ausgegeben und die Eingabeaufforderung für den Spielernamen ausgeführt. Danach die Initialisierung der Dateiausgabe und des Spielfelds. Schlussendlich dann noch das Spielfeld aktualisiert.
Die `init()`-Funktion wird somit vor jedem Spielstart ausgeführt, um die grundlegende Spielumgebung zu schaffen.
```c
void init(); 
``` 

***Neustart*** <br/>
Setzt das Spielfeld und die Globale Variablen (snake, soody, last_stearing, score, s_length) zurück und startet Spiel erneut.
```c
void restart(); 
``` 

***Neuer Goody*** <br/>
Erzeugt eine zufällig generierte Position für die Goodys. Damit das Goody nicht in der Schlange generiert wird, wird beim Erzeugen überprüft, ob sich die neue Position schon in einem belegten Feld befindet, ist dies nicht der Fall wird die neue Goody-Position als Rückgabewert zurückgegeben.

```c
snakepart randomGoody();
``` 

***Spielgeschwindigkeit*** <br/>
Damit die Schlange nach einer bestimmten Zeit in Millisekunden auf die nächste Position bewegt wird, muss die `wait()-Funktion` aufgerufen werden. Beim Aufruf wird die Wartezeit in Millisekunden als Ganzzahl Übergabeparameter übergeben. Die Funktion bewirkt, dass die angegebene Zeit gewartet wird und erst nach Ablauf der Wartezeit das Programm fortgeführt wird.
Zu Beginn soll die Wartezeit 200ms betragen und mit jedem gefressenen Goody wird diese reduziert.
 ```c
 void wait(int Waiting_Time_ms);
 ``` 

***Wenn Goody aufgesammlt wird*** <br/>
Die `eat()`-Funktion überprüft, ob der Schlangenkopf sich auf das Goody bewegt, wenn ja, erhöht die Funktion die Schlangenlänge um eins und den Score um 10 Punkte. Danach wird eine neue zufällige Goody-Position erzeugt. Die Funktion benötigt die nächste Position vom Schlangenkopf als `snakepart` Datentyp.
```c
void eat(snakepart next);
```

***Überprüfung des nächsten Schritts*** <br/>
Ob die Schlange im nächsten Schritt ein Hindernis oder sich selbst berührt, wird durch die Funktion `checkNextStep()` überprüft. Dazu wird die nächste Position des Schlangenkopfs der Funktion übergeben. Die Funktion vergleicht diese Position anschließend mit dem `Snake[]`-Array und den Spielfeldbegrenzungen.
```c
 boolean checkNextStep(snakepart next); 
 
  //false : Hindernis wird berührt 
  //true : Hindernis wird nicht berührt	
```
Der Rückgabewert der Funktion liefert dann, ob ein Hindernis im nächsten Schritt berührt wird mit `false` oder ob kein Hindernis berührt wird mit `true`.

***Bewegung der Schlange*** <br/>
Damit die Schlange sich auf eine neue Position verschiebt, muss die Funktion `move()` aufgerufen werden. Die Funktion schiebt dabei die Positionen im `Snake[]`-Array um eine Position nach hinten. Das letzte Element bei `s_length-1` wird dabei nicht berücksichtigt, da dieses im nächsten Zug nicht mehr Teil der Schlange ist. Wird die Schlangenlänge `s_length` größer, so müssen immer mehr Elemente verschoben werden. Zuletzt, muss die neue X- und Y-Position des Schlangenkopfes in das 0. Element des `Snake[]`-Arrays geschrieben werden.
Aus diesem Grund benötigt die Funktion als Übergabeparameter wird die nächste Position des Schlangenkopfts als `snakepart` Datentyp.
```c
void move(snakepart next); 
``` 

***Spielablauf*** <br/>
Regelt den kompletten Spielverlauf, siehe Struktogramm.
```c
void game(); 
``` 

[![Bild struktogramm-zu-gamexcj9u.png auf abload.de](https://abload.de/img/struktogramm-zu-gamexcj9u.png)](https://abload.de/image.php?img=struktogramm-zu-gamexcj9u.png)

  
    
    


