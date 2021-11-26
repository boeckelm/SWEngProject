//Erstellt von Lukas Sellmaier-
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#pragma warning(disable: 4996)

#include "Bestenliste.h"
#include "Global.h"
#include "Spielsteuerung.h"

#define _CRT_SECURE_NO_WARNINGS

// Übergibt die Aktuelle Bestenliste über Zeiger

int snake_best_out() {


	FILE* fp;
	char score[5] = "";
	char name[NAME_MAX] = "";

	fopen_s(&fp, "SnakeBestenliste.txt", "r+");

	if (fp == NULL)
		return 1;		//return 1 = Fehler beim Öffnen der Datei

	for (int i = 0; i < NUM_ENTRY; i++)
	{
		fgets(score_temp[i].name, NAME_MAX, fp);		//Name in liste kopieren
		fgets(score, 5, fp);						//Punkte in Liste kopieren
		score_temp[i].score = atoi(score);
	}
	

	if (!(fclose(fp)))
		return 2;		//return 2 = Fehler beim Schließenn der Datei
	

	return 0;

}



// Aktualisiert die Bestenliste mit übergebenem Punktestand und Namen

int snake_best_up(int punkte) {


	//---------------Variabeln Deklarieren---------------//

		
		snake_best_out(score_temp);		//struct highscore sc mit Werten füllen

		
	//---------------Liste Aktualisieren---------------// 

	
		for (int i = 0; i < NUM_ENTRY; i++) {
			if (punkte > score_temp[i].score) {		
				for (int j = NUM_ENTRY - 1; j > i; j--) {
					strcpy(score_temp[j].name, score_temp[j -1].name);
					score_temp[j].score = score_temp[j - 1].score;
				}
				strcpy(score_temp[i].name, spielername);
				score_temp[i].score = punkte;
				break;
			}
		}
	

	//---------------Aktualisierte Liste Speichern---------------// 


	FILE* fp;

	fopen_s(&fp, "SnakeBestenliste.txt" , "w");	
	if (fp == NULL) 
		return 1;		//return 1 = Fehler beim Öffnen der Datei
	

	for (int i = 0; i < NUM_ENTRY ; i++) {
		fputs(score_temp[i].name, fp);	//Name in Datei schreiben
		fprintf(fp, "%i", score_temp[i].score);	//Punktestand in Datei schreiben
		fprintf(fp, "\n");
	}


	if (!(fclose(fp)))
		return 2;		//return 2 = Fehler beim Schließen der Datei
	

	return 0;
}



// Initialisiert die Bestenliste, erst und füllt Datei falls nich vorhanden

int snake_best_init() {

	FILE* fp;
	
	
	if (!(fopen_s(&fp, "SnakeBestenliste.txt", "r"))) {
		if (!(fclose(fp)))
			return 2;		//return 2 = Fehler beim Schließen der Datei
		return 0;
	}
	
	 
	fopen_s(&fp, "SnakeBestenliste.txt", "w");

	if (fp == NULL) 
		return 1;		//return 1 = Fehler beim Öffnen der Datei
		

	for (int i = NUM_ENTRY; i > 0; i--) 
	{
		if (fp == NULL)
			return 0;
		int n = NAME_MAX-1;
		while (n--)
			fprintf(fp, "-");
		fprintf(fp, "0000");
	}


	if (!(fclose(fp)))
		return 2;		//return 2 = Fehler beim Schließen der Datei

	return 0;
}