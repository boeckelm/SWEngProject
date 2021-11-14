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




## 💡 Architekturspezifikation
  Das Projekt wird in mehrere größere Modulblöcke, die jeweils verschiedene Funktionsblöcke abbilden, unterteilt:  
  
  ### ⌨️Eingabe 
  
   `Lukas Sellmaier`
  
  ### 🎮 Spielmechanik 
  
  Tim Gebhard
  
  ### 🖥️ Visualisierung  
` Michael Böckelen`    
Dieses Modul ist für sämtliche Ausgaben auf dem Terminal verantwortlich und stellt entsprechende Schnittstellen zur Verfügung.

* **Hauptaufgabe: Visualisierung des Spiels**  
Bei der Visualisierung des Spiels soll rein auf ASCII-Zeichen zurückgegriffen werden. 
Zu Anfang des Spiels soll das Spielfeld im Terminal initalisiert werden. Dabei wird die Anzeige zuerst gecleared und die Ränder des Spielfeldes ausgegeben. Anschließend soll bei einem Positionsupdate die Schlange am Spielfeld gezeichnet werden und jeweils nur die veränderten Bestandteile neu gezeichnet werden.

* Möglichkeit zur einfachen Textausgabe während des Spiels, zum Beispiel für Debug-Daten. Am besten wird hier einfach der Text-Cursor an die alte Stelle zurückgesetzt 
* Formatierte Ausgabe des Ranglisten-Screens mit Option eines Beschreibungstextes

  
### 🏆 Rangliste 
  `Lukas Sellmaier`
  
### 🐞 Debugging und Logging 
  ` Michael Böckelen`  
Dieses Modul stellt Schnittstellen zur besseren Fehlerdokumentation zur Verfügung.  
* Zuverfügungstellen eines einheitlichen und auswertbaren Funktionsendes

* Anzeige und Abspeicherung von Debug-Daten

## ⌨️ Designspezifikation
 * 
   ### Eingabe
       
  
   ### Spielmechanik
        randomGoody();
        void restart();
  
   ### 🖥️ Visualisierung  
` Michael Böckelen`    
Diese Modul ist für sämtliche Ausgaben auf dem Terminal verantwortlich und stellt entsprechende Schnittstellen zur Verfügung. Als Rückgabewert wird der jeweils der `Snake_DBG_t`-Struct, beschrieben in `Debugging und Logging`, verwendet.

**Initialsierung des Spielbildschrims**  
```c
Snake_DBG_t Snake_VS_init(unsigned short feldgroesse_x, unsigned short feldgroesse_y);
```
* Zu Anfang des Spiels soll das Spielfeld mit den übergebenen Feldgröße-Parametern initialisiert werden und alle anderen bestehenden Ausgaben gelöscht werden. 
Die Darstellung erfolgt mittels fest definierter ASCII-Zeichen. Desweiteren wird der formatierte High-Score-Counter dann angezeigt.
<br><br/>

**Update des Spielfeld-Inhalts**  
```c
Snake_DBG_t Snake_VS_Update (Snake_Vektor_t snake [ ], unsigned short Anzahl, Snake_vektor_t goody, unsigned short score);
``` 
* Während des Spiels müssen die Positionen der Elemente laufend angepasst werden. Dafür gibt es eine Update-Funktion, der mittels Array alle Positionsdaten der Schlange sowie die Goody-Koordinate übergeben werden. Außerdem wird die Anzahl der Schlangenstücke sowie der aktuelle Highscore übergeben. Der Koordinatenursprung befindet sich dabei immer unten links. Zur besseren Vorstellung ein Bild:  

* <img align="center" width="541" height="210" src="https://abload.de/img/68747470733a2f2f61626udj3v.png"> 
* Für die einzelnen Koordinaten soll der Struct `Snake_Vektor_t` oder der im Hauptteil definierten Struct, der je eine ganzzahlige x und y Variabe besitzt, verwendet werden.

```c
typedef struct {
    unsigned short x;
    unsigned short y;
} Snake_Vektor_t;
```
Intern wird der Cursor mittels der in `"Windows.h"` definierten `SetConsoleCursorPosition()`-Funktion an jene Koordinate gesetzt und ein entsprechendes Zeichen gesetzt.
Anschließend wird dieser wieder unter das Spielfeld gesetzt, damit Ausgaben das Spielfeld nicht zerstören.
<br><br/>

**Beenden des Spiels** 
```c
Snake_DBG_t Snake_VS_end(void);
``` 
* Zum Beenden der Spielausgabe soll diese Funktion ohne Parameter aufgerufen werden. Dabei wird das Terminal gecleared und der Cursor wieder oben links gesetzt.
<br><br/>

**Ausgabe eines Textes** 

* Zur reinen Textausgabe kann wie gewohnt die printf()-Funktion o.Ä. beutzt werden. Intern wird der Text-Cursor immer unter das Spielfeld gesetzt, sodass keine Komplikationen auftreten können.
<br><br/>  

**Darstellung der Rangliste** 
```c
Snake_DBG_t Snake_VS_Rangliste(Snake_Rangliste_t [10], char* text); //Placeholder!
``` 
* Zur formatierten Ausgabe der Rangliste soll diese Funktion aufgerufen werden. Als Parameter sollen ein Array des im Ranglisten-Modul definierten Datentyps `PLACEHOLDER` sowie ein Beschreibungstext übergeben werden. Mit dem Beschreibungstext kann zum Beispiel zur Eingabe des Namens aufgefordert werden.
<br><br/>  

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
* Falls es außerhalb des Funktionendes gewünscht sein Debugmeldungen auszugeben oder zu speichern, soll diese Funktion samt Debug-Beschreibung und Statusals Parameter aufgerufen werden.

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
    


