/** @file debug.h
 *
 * @brief Erweiterte Debug-Funktionen für das Spiel "Snake".
 *
 * @version 1.0.0
 *
 * @par
 * COPYRIGHT NOTICE: (c) 2021 Michael Böckelen, Hochschule Landshut.  All rights reserved.
 */
 /*
 Allgemeines Vorgehen beim Benutzen der Debug-Funktionen:
	Eine mit diesem Datentyp versehene Funktion gibt immer einen Pointer auf einen Debug-Listen-Eintrag zurück, dieser kann, muss aber nicht
	von der aufrufenden Funktion ausgewertet werden.
	Vorgehen wenn direktes Feedback gewünscht:
	Beispiel:
		Snake_DBG_t feedback = foo(); //Abspeichern des Rückgabewertes in lokaler Variable
			if(feedback->status == SNAKE_SUCCESS){...} //Auswertung des Status-Codes, dazu bitte unteres Enum zu Rate ziehen
 */


#ifndef DEBUG_H	//alternativ pragma once
#define DEBUG_H

#include "time.h"

typedef enum { SNAKE_SUCCESS, SNAKE_FAIL, SNAKE_DEBUG } Snake_status; //Enum für Statuscode

struct Snake_DBG_struct {	//Struct eines Debug-Eintrages in einer Verketteten Liste
	time_t timestamp;		//Zeitstempel
	Snake_status status;	//Status-Code, zum einfachen Abfragen ob eine Funktion erfolgreich durchgeführt wurde oder nicht
	char* error;			//Pointer auf dynamisches char-Array, um Fehler, bzw. Debug-Meldungen zu speichern

	struct Snake_DBG_struct* next; //für verkettete List
};

typedef struct Snake_DBG_struct* Snake_DBG_t; //typedef damit struct pointer nicht mitgeschleppt werden muss

//Erstmaliges Setzen des Ankers, in dieser Listenstruktur ist dies der Eintrag "DEFAULT SUCCESS", sodass bei erfolgreicher Ausführung einer Funktion nicht unbedingt ein neues Listenelement erstellt werden muss
Snake_DBG_t setAnker(void);

//Hilfsfunktion zum Erstellen eines neuen Listenelementes
Snake_DBG_t Snake_DBG_new_entry(char* text, Snake_status status);

//Einfach zu benutzende Funktion, die im Fehlerfall während des returns aufgerufen werden kann -> z.B. return Snake_DBG_Error("Fehler bei Erstellen des Pointers");
Snake_DBG_t Snake_DBG_Error(char* text); //Übergabe einer Fehlerbeschreibung, falls keine weitere Beschreibung erfolgt bitte 0 übergeben. Es wird jedoch immer ein neues Listenelement erstellt.

//Einfach zu benutzende Funktion, die bei Erfolg während des returns aufgerufen werden kann -> z.B. return Snake_DBG_Success(0);
Snake_DBG_t Snake_DBG_Success(char* text); //Wenn der Nutzer auch bei erfolgreicher Durchführung einen Eintrag wünscht, kann er einen String übergeben, falls nicht einfach eine 0 übergeben

//Funktion zum Abspeichern eines Debugeintragen
Snake_DBG_t Snake_DBG_General(char* text, //Übergabe der Notiz
	Snake_status status); //Status zum schnellen einordnen, bitte aus obigem Enum entnehmen

//Funktion zum Abspeichern der Listeneinträge in eine Datei, sollte einmalig vor Beenden des Programms aufgerufen werden
void Snake_DGB_Save(void);

//Funktion zum Ausgeben der Listeneinträge auf der Konsole
void Snake_DBG_Ausgabe_Konsole(void);

//Freigeben der Listenelemente im Heap
void Snake_DBG_Freigeben(void);


#endif
