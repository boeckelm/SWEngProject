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
* ~~Farbige Konsolenelemente für die Schlange, möglichst unterschiedliche Grüntöne für Kopf und Körper~~
* Variabler Takt für unterschiedliche Spielgeschwindigkeiten
* Zufälliges Erscheinen der Goodys
* Nach Aufnahme eines Goodys wird Schlange am Kopf erweitert
* Erweiterte Debugmöglichkeiten in Form eines separat abzuspeichernden Log-Files, der alle Spielzüge und mögliche Runtime-Fehler dokumentiert



## 💡 Architekturspezifikation
  Das Projekt wird in drei größere Modulblöcke, die jeweils verschiedene Funktionsblöcke abbilden, unterteilt. 
  ### ⌨️Eingabe 
   ``` Lukas Sellmaier ```
 
 
  In diesem Modul befinden sich die Funktionen welche die Eingabe über die Tastaur ermöglichen.
  * Namen eingeben und überprüfen der Anforderungen
  * Die Steuerung der Schlange über die Tasten ```W``` ```A``` ```S``` ```D```
  * Auf beliebiege Tastertureingabe warten
  

  
  ### 🎮Spielmechanik 
   ##### wird programmiert und entwickelt von `Tim Gebhard`

Im Modul der Spielsteuerung wird die Spielmechanik, also die Spiellogik und der Programmablauf gesteuert. Die nachfolgenden Punkte gehen darauf näher ein.		

* Programmablauf: 
Programmablauf: Nach Start des Spiels soll zu Beginn der Startbildschirm angezeigt werden. Der Benutzer soll dann aufgefordert werden eine Eingabe zu seinem gewünschten Spielernamen zu machen. Nach Bestätigen der Eingabe soll das Spiel gestartet werden. D. h. das Spielfeld soll erscheinen und die Schlange sollte anfangen sich mit einer bestimmten Geschwindigkeit zu bewegen. Das Spiel wird so lange gespielt bis die Schlange sich selbst oder eine der vier Ränder berührt. Nachdem das Spiel beendet wurde, soll der Benutzter eine Ausgabe zusehen bekommen, in der er nochmals sein erreichter Punktestand sehen kann. Die abgespeicherte Bestenliste wird angezeigt und der Benutzer wird gefragt, ob er nochmals spielen möchte. Wenn dieser nochmal spielen möchte, wird das Spiel neu gestartet.

[![Bild programmablauf7fk7y.png auf abload.de](https://abload.de/img/programmablauf7fk7y.png)](https://abload.de/image.php?img=programmablauf7fk7y.png)


* Spielmechanik:
Während dem Spiel verarbeitet die Spielsteuerung die Eingabe des Benutzers, sodass die Schlangen auf dem Spielfeld in die gewünschte Richtung gesteuert werden kann. Dabei sollen  die einzelnen Elemente (Körperteile) der Schlange den vorherigen Elementen folgen, wie in einer Kette. Der Schlangenkopf gibt hierbei die Richtung der kompletten Schlangen vor. Während des Spiels wird auch überprüft, ob der Schlangenkopf ein Teil der Schlange oder die Spielbegrenzung berührt.
Fährt die Schlange über einen durch die Spielmechanik zufällig auf dem Spielfeld generierten Goody, so wird diese am Kopf um ein weiteres Element (Körperteil) erweitert und der Punktestand des Spielers wird erhöht.

  
 ### 🖥️ Visualisierung  
 ``` Michael Böckelen ```   
Dieses Modul ist für sämtliche Ausgaben auf dem Terminal verantwortlich und stellt entsprechende Schnittstellen zur Verfügung.

* **Hauptaufgabe: Visualisierung des Spiels**  
Bei der Visualisierung des Spiels soll rein auf ASCII-Zeichen zurückgegriffen werden. 
Zu Anfang des Spiels soll das Spielfeld im Terminal initalisiert werden. Dabei wird die Anzeige zuerst gecleared und die Ränder des Spielfeldes ausgegeben. Anschließend soll bei einem Positionsupdate die Schlange am Spielfeld gezeichnet werden und jeweils nur die veränderten Bestandteile neu gezeichnet werden.

* Möglichkeit zur einfachen Textausgabe während des Spiels, zum Beispiel für Debug-Daten. Am besten ohne eigene Funktion
* Formatierte Ausgabe des Ranglisten-Screens 
  
### 🏆Rangliste 
  ``` Lukas Sellmaier ```
   
   In diesem Modul wird die Rangliste angelegt sowie ihre Funktionen und das Struct zur Übergabe der Daten definiert.
   * Es wird einen Textdatei angelegt, in welcher zehn  Namen und ihre Punktestände gespeichert werden
   * Zu Beginn enthält sie zehn Platzhalter mit jeweils Null Punkten
   * Über eine Funktion kann man einen neuen Punktestand mit der Liste vergleichen und gegebenenfalls in diese aufnehmen
   * Des Weiteren wird hier ein Struct definiert mit dem die Daten anderen Funktionen zur Verfügung gestellt werden können

    
### 🐞 Debugging und Logging 
  ` Michael Böckelen`  
Dieses Modul stellt Schnittstellen zur besseren Fehlerdokumentation zur Verfügung.  
* Zuverfügungstellen eines einheitlichen und auswertbaren Funktionsendes

* Anzeige und Abspeicherung von Debug-Daten
  
## ⌨️ Designspezifikation

### ⌨️Eingabe 
 ``` Lukas Sellmaier ``` 

 <br/>
 
  In diesem Modul werden die drei Funktionen definiert, welche die Eingabe über die Tastatur ermöglichen.
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
Anschließend wird der String in die globale Variable `spielername[MAX_NAME]` kopiert.
 
 <br/><br/>
  
```snake_eing_dir()```

Diese Funktion dient zur Eingabe der Bewegungsrichtung über die Tasten ```w``` ```a``` ```s``` ```d``` .

 + Über die Funktion `_kbhit` wird der Tastaturpuffer abgefragt. Wenn dieser `ungleich 0` ist, wird der Wert über `_getch` einer `char Variablen` zugewiesen. Diese Variable wird anschließend über eine `Switch-Case` Anweisung ausgewertet und je nach eingelesener Taste der globale Wert `last_stearing verändert`. Hierfür wird das in `"Spielsteuerung.h"` definierte `enum stearing` verwendet.
 
 <br/><br/>
  
 ```bool snake_eing_any()```


Diese Funktion dient zur Bestätigung durch die Taste J.

 + Über `_getch` wird eine `char Variable` eingelesen. Wenn diese dem Wert `J` bzw. `j` entspricht, wird `true` als Rückgabewert ausgegeben. Alle anderen Eingaben führen zu einem Rückgabewert `false`. Diese Rückgabewerte sind vom Typ `bool` und wurden in `"Spielsteuerung.h"` definiert. 

<br/>

- - - -

<br/>
  
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

<br/><br/>
 
   ### 🖥️ Visualisierung  
` Michael Böckelen`    
Diese Modul ist für sämtliche Ausgaben auf dem Terminal verantwortlich und stellt entsprechende Schnittstellen zur Verfügung. Als Rückgabewert wird der jeweils der `Snake_DBG_t`-Struct, beschrieben in `Debugging und Logging`, verwendet.

**Startbildschirm**  
```c
Snake_DBG_t Snake_VS_Startscreen(void);
```
Diese Funktion gibt eine Pixelart vom Schriftzug "Snake" aus und fordert den Nutzer zur Eingabe seines Namen auf.
<br><br/> 

**Initialsierung des Spielbildschrims**  
```c
Snake_DBG_t Snake_VS_init(unsigned short feldgroesse_x, unsigned short feldgroesse_y);
```
* Zu Anfang des Spiels soll das Spielfeld mit den übergebenen Feldgröße-Parametern initialisiert werden und alle anderen bestehenden Ausgaben gelöscht werden. 
Die Darstellung erfolgt mittels fest definierter ASCII-Zeichen. Desweiteren wird dann der formatierte High-Score-Counter, sowie die Bestenliste (global, deswegen ohne Parameterübergabe) neben dem Spielfeld angezeigt.
<br><br/>

**Update des Spielfeld-Inhalts**  
```c
Snake_DBG_t Snake_VS_Update (Snake_Vektor_t snake [ ], unsigned short Anzahl, Snake_vektor_t goody, unsigned short score);
``` 
* Während des Spiels müssen die Positionen der Elemente laufend angepasst werden. Dafür gibt es eine Update-Funktion, der mittels Array alle Positionsdaten der Schlange sowie die Goody-Koordinate übergeben werden. Außerdem wird die Anzahl der Schlangenstücke sowie der aktuelle Highscore übergeben. Der Koordinatenursprung befindet sich dabei immer unten links. Zur besseren Vorstellung ein Bild:  

* <img align="center" width="541" height="210" src="https://abload.de/img/68747470733a2f2f61626udj3v.png"> 
* Für die einzelnen Koordinaten soll der Struct `snakepart` oder der im Hauptteil definierten Struct, der je eine ganzzahlige x und y Variabe besitzt, verwendet werden.

```c
typedef struct{
     		int pos_X; //X-Position
      		int pos_Y;//Y-Position
    	 }snakepart;
```
Intern wird der Cursor mittels der in `"Windows.h"` definierten `SetConsoleCursorPosition()`-Funktion an jene Koordinate gesetzt und ein entsprechendes Zeichen gesetzt.
Anschließend wird dieser wieder unter das Spielfeld gesetzt, damit Ausgaben das Spielfeld nicht zerstören. Um diese Vorgänge zu vereinfachen gibt es bestimmte Hilfsfunktionen, die den Cursor mittels Vektor setzen.  
Um nicht jedes mal den kompletten Screen neu darstellen zu müssen wurde ein Algorithmus implementiert, der die veränderten Elemente herausrechnet und nur diese darstellt.

<Details>
https://github.com/boeckelm/SWEngProject/blob/main/Snake/Snake/Visualisierung_Algorithmus.svg
</Details>


	
<br><br/>

**Beenden des Spiels** 
```c
Snake_DBG_t Snake_VS_end(void);
``` 
* Zum Beenden der Spielausgabe soll diese Funktion ohne Parameter aufgerufen werden. Dabei wird das Terminal gecleared und der Cursor wieder oben links gesetzt. Außerdem wird der Algorithmus zum Festellen der Schlangenänderung wieder zurückgesetzt.
<br><br/>

**Ausgabe eines Textes** 

* Zur reinen Textausgabe kann wie gewohnt die printf()-Funktion o.Ä. beutzt werden. Intern wird der Text-Cursor immer unter das Spielfeld gesetzt, sodass keine Komplikationen auftreten sollten.
<br><br/>  

### 🏆Rangliste 

``` Lukas Sellmaier ``` 


 In diesem Modul werden die drei Funktionen definiert mit welcher die Bestenliste initialisiert, ausgegeben und aktualisiert werden kann.
 
 
<br/>

  Folgende Global Definierten Variablen werden in diesem Modul genutzt:
  * `spielername[MAX_NAME]`
  * `struct highscore score_temp[NUM_ENTRY]`

  Sowie die Folgenden definierten Konstanten:
  * NAME_MAX
  * NUM_ENTRY

<br/>

  Das `struct highscore` ist ebenfalls hier definiert:
```
    struct highscore {
           char name[NAME_MAX];
           int score;
           }; 
```
In diesem Struktur werden alle Namen sowie die dazugehörigen Punktestände gleichzeitig in einem `struct Array` gepeichert.

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
 
 <br/><br/>
 
### 🐞 Debugging und Logging 
  ` Michael Böckelen`  
Dieses Modul stellt Schnittstellen zur besseren Fehlerdokumentation zur Verfügung. 
**Einheitlicher und auswertbarer Rückgabewert**
* Um einen **einheitlichen und auswertbaren Rückgabewert** zur Verfügung zu stellen, wird die Datenstrukur `Snake_DBG_t` erstellt. Diese beinhaltet einen ganzzahligen Statuscode, einen optionalen String zur Fehlerbeschreibung und einen Zeitstempel. 
* **Zur Vereinfachung des Debug-Verfahrens muss bei der Implementation nur zwischen zwei Funktionen unterschieden werden, die während `return` aufgerufen werden.**

```c
Snake_DBG_t Snake_DBG_Success("Alles gut"); //Bei Erfolg
``` 
```c
Snake_DBG_t Snake_DBG_Error("Fehlerbeschreibung"); //Bei einem Fehler
```

* Falls die aufrufende Funktion direktes Feedback wünscht, besteht die Möglichkeit den Rückgabewert manuell auszuwerten. Falls nur die Benutzung gewünscht ist, kann der Punkt "Details" übersprungen werden.
<Details>
<br><br/>  
  
  * Der Rückgabewert einer solchen Funktion ist immer ein Pointer auf ein Listenelement, in das die Fehlermeldung der Status, und der Zeitstempel geschrieben wird.
  
 * Die Debug-Datenstruktur wurde dabei als rückwärts-verkettete Liste ausgeführt, bei der der Anker global definiert ist und sich nicht ändert.
  Dieser Anker repräsentiert den Default-Success-Case, der bei einem Erfolg und keiner Meldung zurückgegeben wird. In allen anderen Fällen wird ein neuer Listeneintrag erstellt   und direkt hinter den Anker gesetzt, damit Fehlermeldungen der Zeit nach geordnet abgelegt werden.
  
  
  
  * <img align="center" width="567" height="370" src="https://abload.de/img/designrrkk0.png"> 
  


```c
struct Snake_DBG_struct{	//Struct eines Debug-Eintrages in einer Verketteten Liste
	time_t timestamp;		//Zeitstempel
	Snake_status status;	//Status-Code
	char* error;			//Fehlermeldung

	struct Snake_DBG_struct* next; //für verkettete List
};
``` 
Zur schnellen Auswertung muss nur der Status-Code kontrolliert werden.
Als Statuscode werden die Enums `SNAKE_SUCCESS` oder `SNAKE_FAIL` verwendet werden.  
 
```c
typedef enum {SNAKE_SUCCESS, SNAKE_FAIL} Snake_status;
``` 
</Details> 

Zur weiteren Erläuterung werden die zwei möglichen Fälle aufgezeigt:

```c
Snake_DBG_t foo (int a, int b){

// Funktion

if(success){
  return Snake_DBG_Success();
 
else{
  return Snake_DGB_Error("Failed to ...");

``` 

<br><br/>
**Ausgabe und Abspeichern von allgemeinen Debugdaten**
```c
Snake_DBG_t Snake_DGB_General(char* meldung, Snake_status status);
``` 
* Falls es außerhalb des Funktionendes gewünscht sein sollte Debugmeldungen auszugeben oder zu speichern, soll diese Funktion samt Debug-Beschreibung und Status als Parameter aufgerufen werden.

**Schreiben der Debugdaten in eine Datei**
```c
Snake_DBG_t Snake_DGB_SAVE(void);
``` 
* Diese Funktion sollte vor einmalig vor Programmende aufgerufen werden, um alle Debugdaten samt Zeitstempel in eine Datei zu schreiben.

**Löschen der Liste**
```c
void Snake_DBG_Freigeben(void);

``` 
* Diese Funktion muss zum Ende des Programms aufgerufen werden, um den Speicher wieder freizugeben.    
    

  
