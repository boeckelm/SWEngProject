#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#include "bestenliste.h"

//-----------------------------------------------------------//

score_out(struct highscore* ptr) {

	char string[NAME_MAX] = "";	//puffer für funktion atoi()

	FILE* fp = fopen(datei_pfad, "r");	//Datei in read öfnen
	if (fp == NULL) {
		printf("fehler!1");
		fclose(fp);
		exit;
	}

	for (int i = 0; i < NUM_ENTRY; i++) {
		fgets((ptr + i)->name, NAME_MAX, fp);	//Name in liste kopieren
		fgets(string, 5, fp);		//Punkte in Liste kopieren
		(ptr + i)->score = atoi(string);	//5 =Maximal einlesbarer punktestand , über define?
	}

	if (fclose(fp) != 0)	//Datei schließen
		printf("fehler!2");

}

//-----------------------------------------------------------//

score_up(int punkte, char* ptr) {

	char string[NAME_MAX] = "";	//Puffer für strcpy()
	struct highscore sc[NUM_ENTRY];
	score_out(sc);	//struct highscore sc mit werten füllen


	for (int i = 0; i <= NAME_MAX; i++) {	//erzeugen einen strings , zum kopieren
		string[i] = ptr[i];
	}

	for (int i = 0; i < NUM_ENTRY; i++) {
		if (punkte > (sc + i)->score) {		//vergleicht übergeben punktestand mit liste
			for (int j = NUM_ENTRY - 1; j >= i + 1; j--) {
				strcpy(sc[j].name, sc[j - 1].name);
				sc[j].score = sc[j - 1].score;
			}
			strcpy(sc[i].name, string);
			sc[i].score = punkte;
			break;
		}
	}

	FILE* fp;

	fp = fopen(datei_pfad, "w");	//Datei öffnen
	if (fp == NULL) {
		printf("fehler!3");
		return 0;
	}
	for (int i = 0; i < NAME_MAX - 1; i++) {
		fputs(sc[i].name, fp);	//Name in Datei schreiben
		fprintf(fp, "%i", sc[i].score);	//Punktestand in Datei schreiben
		fprintf(fp, "\n");
	}
	fclose(fp);	//Datei schließen

}

//-----------------------------------------------------------//