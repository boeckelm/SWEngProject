/** @file debug.c
 *
 * @brief Erweiterte Debug-Funktionen für das Spiel "Snake".
 *
 * @version 1.0.0
 * 
 * @par
 * COPYRIGHT NOTICE: (c) 2021 Michael Böckelen, Hochschule Landshut.  All rights reserved.
 */

#define _CRT_SECURE_NO_WARNINGS

#include "debug.h"

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "String.h"


static Snake_DBG_t ANKER = 0; //Globaler Pointer auf erstes Listenelement, wird nur einmalig gesetzt

Snake_DBG_t setAnker(void) {	//Setzen des globalen Ankers, stellt immer "DEFAULT SUCCESS" zur Vefügung

	char text[] = "DEFAULT SUCCESS";

	if (ANKER) return ANKER; //Nur einen neuen Anker erstellen wenn es noch keinen gibt

	Snake_DBG_t local = (Snake_DBG_t) malloc(sizeof(struct Snake_DBG_struct)); //Erstellen des Ankers
		if (!local) return 0; //Wenn nicht erfolgreich direkt abbrechen

	local->error = (char*)malloc(strlen(text)+1); //Allozierung für den Beschreibungstext

	if (local->error) {	//nur Beschreibung kopieren wenn Allozierung erfolgreich
		strcpy(local->error, text);
	}

	local->status = SNAKE_SUCCESS; //Fester Status
	local->timestamp = time(NULL); //Zeitstempel aus time.h libe
	local->next = NULL;	//Nächstes Listenelement zunächst leer
	

	return local; //Anker zurückgeben

}

Snake_DBG_t Snake_DBG_new_entry(char* text, Snake_status status) {

	if (!ANKER) {	//falls erstmaliger Aufruf Erstellung des Ankers
		ANKER = setAnker();

		if (!ANKER) {
			printf("\n[DEBUG] Keine Initialisierung des Ankers moeglich!"); //Wenn Fehler kann nicht auf Debug-Funktionen zugegriffen werden, deswegen Konsolenausgabe 
			return 0;
		}
	}

	if (!text && !status) return ANKER; //Falls keine Rückmeldung kam und SNAKE_SUCCESS übermittelt wurde, wird der Standard-Success-Struct übermittelt und nichts gespeichert
	
	else {
		
		Snake_DBG_t local = (Snake_DBG_t)malloc(sizeof(struct Snake_DBG_struct)); //Neuen Listeneintrag erstellen
		if (!local){
			printf("\n[DEBUG] Keine Listenerweitung moeglich!"); //Wenn Fehler kann nicht auf Debug-Funktionen zugegriffen werden, deswegen Konsolenausgabe 
			return 0;
		}

		if (text) {
			local->error = (char*)malloc(strlen(text) + 1); //Allozierung für den Beschreibungstext
			if (local->error) {	//nur Beschreibung kopieren wenn Allozierung erfolgreich
				strcpy(local->error, text); 
			}
			else {
				printf("\n[DEBUG] Keine Allozierung des dynamischen char-pointers moeglich!");  //Wenn Fehler kann nicht auf Debug-Funktionen zugegriffen werden, deswegen Konsolenausgabe 
			}
		}

		else {
			local->error = 0; //Im Fehlerfall Nullsetzen des char-pointers damit ein definierter Fehler besteht
		}

		local->status = status; //Snake-Status setzen
		local->timestamp = time(NULL); //aktullen Zeitstempel setzen

		local->next = ANKER->next;	//verkettete List: ANKER bleibt immer an erster Stelle, folgende Elemente werden rückwärts verkettet
		ANKER->next = local;	

		return local; //Rückgabe eines Pointers auf neues Listenelement

	}
}

Snake_DBG_t Snake_DBG_Error(char* text) {

	return Snake_DBG_new_entry(text, SNAKE_FAIL); //Aufruf der allgemeinen Hilfsfunktion 

}

Snake_DBG_t Snake_DBG_Success(char* text) {

	return Snake_DBG_new_entry(text, SNAKE_SUCCESS); //Aufruf der allgemeinen Hilfsfunktion 

}

Snake_DBG_t Snake_DBG_General(char* text, Snake_status status) {

	printf("\n[DEBUG] %s", text); //Ausgabe auf dem Bildschirm

	return Snake_DBG_new_entry(text, status); //Aufruf der allgemeinen Hilfsfunktion 
}

void Snake_DGB_Save(void) { //Funktion zum Speichern der verketteten Liste in eine Datei

	char name[50], buff[20], stat [15]; //lokale Variablen für Bezeichnungen
	Snake_DBG_t local = ANKER;	//Lokaler Traversenanker
	unsigned short i = 0; //interner Zähler der Einträge
	FILE* fp; 

	strftime(name, 50, "%Y-%m-%d--%H-%M-%S_SNAKE_LOG.txt", localtime(&(local->timestamp))); //Dateiname wird aus aktueller Uhrzeit gebildet

	fp = fopen(name, "w");	//Öffnen des Dateistreams
		if (!fp) return;
	
	while (local) {	//Schleife, die die verkettete Liste entlang geht

		strftime(buff, 20, "%Y-%m-%d %H:%M:%S", localtime(&(local->timestamp))); //String aus Timestamp machen

		switch (local->status) {
			case SNAKE_SUCCESS: strcpy(stat, "SNAKE_SUCCESS"); break; //String aus Status
			case SNAKE_FAIL: strcpy(stat, "SNAKE_FAIL"); break;
			case SNAKE_DEBUG: strcpy(stat, "SNAKE_DEBUG"); break;
		}

		fprintf(fp, "\n\n---- %d. last Entry ----\n", i++); //Schreiben der Debugdaten
		fprintf(fp, "Time: %s", buff);
		fprintf(fp, "\nSnake-Status: %s", stat);
		fprintf(fp, "\nSnake-Error: %s", local->error);

		local = local->next; //Nächster Listeneintrag
	}

	Snake_DBG_Freigeben(); //Freigabe des Heaps
	fclose(fp); //Schließen des Filestreams

}

void Snake_DBG_Ausgabe_Konsole(void) {

	Snake_DBG_t local = ANKER;
	int i = 0;
	char buff[20], stat[15];
	

	while (local) { //Schleife, die die verkettete Liste entlang geht

		switch (local->status) {
			case SNAKE_SUCCESS: strcpy(stat, "SNAKE_SUCCESS"); break; //String aus Status
			case SNAKE_FAIL: strcpy(stat, "SNAKE_FAIL"); break;
			case SNAKE_DEBUG: strcpy(stat, "SNAKE_DEBUG"); break;
		}

		strftime(buff, 20, "%Y-%m-%d %H:%M:%S", localtime(&(local->timestamp))); //String aus Timestamp machen
		printf("\n\n---- %d. last Entry ----\n", i++); //Ausgabe der Debugdaten
		printf("Time: %s", buff);
		printf("\nSnake-Status: %s", stat);
		printf("\nSnake-Error: %s", local->error);

		local = local->next; //Nächster Listeneintrag
	}

}

void Snake_DBG_Freigeben(void) { //Freigeben der Listenelemente im Heap

	Snake_DBG_t local = ANKER, temp;
	
	while (local) {

		temp = local->next; //Zwischenspeichern des nächsten Listeneintrages, weil dieer nach freigeben des aktuellen nicht mehr aufrufbar ist

		if (local->error) free((void*)local->error);
		if (local) free((void*)local);

		local = temp;

	}

	ANKER = 0; //Zurücksetzen des Ankers

}