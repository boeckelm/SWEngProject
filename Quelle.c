#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX 11		//maximale l�nge der namesneingabe +end NULL
#define NUM_ENTRY 10	//anzahl der gespeicherten ergebnisse in bestenliste
#define datei_pfad "C:/Users/Lukas/Desktop/bestenliste.txt"

struct highscore {
	char name[NAME_MAX];
	int score;
};


/*
(error code?) req_name(char* name);
//auf maximale l�nge pr�fen , 10 zeichen
//auf sonderzeichen pr�fen , nur abc...ABC...123 (klein/gro�/zahlen)
//abfrage ob name schon in Besten-liste vorhanden
	aufruf von #score_out 
	�bergebene Daten(Namen) mit eingabe vergleichen
	ggf. (name schon vorhanden) erneuter funktionsaufruf/fehlermeldung?
*/
req_name(char* ptr){

}


/*
(error code?) req_dir();	//direktion

*/ 
req_dir(){


}


/*
req_any(void)
beliebige tastatureingabe abwarten
*/
req_any(){
getch();	//keine erkl�rung notwendig
}


/*
(error code?) score_out(zeiger auf datenstructur);	//output 
(datei anlegen)
//�ffnet die Bestenliste datei(fehler�berpr�fung)

//kopiert den inhalt in datenstructur (datenstructur definieren!)

//schlie�st datei(fehler�berpr�fung)
*/
score_out(struct highscore* ptr) {

	char string[NAME_MAX] = "";	//puffer f�r funktion atoi()

	FILE* fp = fopen(datei_pfad, "r");
	if (fp == NULL) {
		printf("fehler!1");	//wie mit fehler umgehen?
		fclose(fp);
		exit;
	}

	for (int i = 0; i < NUM_ENTRY; i++) {
		fgets((ptr + i)->name, NAME_MAX, fp);
		fgets(string, 5, fp);
		(ptr + i)->score = atoi(string);
	}

	if (fclose(fp) != 0)
		printf("fehler!2");	//wie mit fehler umgehen?
	 
}


/*
(error code?) score_up(int score,char*name);	//update
//der funktion wird der spielername und endpunktestand �bergeben

//ruft  #score_output auf

//vergleicht die Tabellendaten und aktualisiert. sie ggf.

//speicher aktualisierte liste in der Datei (�ffnen->�berschreiben->schlie�en,�/S pr�fen!)
*/
score_up(int punkte, char* ptr) {

	char string[NAME_MAX]="";	//string f�r strcpy funktion
	struct highscore sc[NUM_ENTRY];
	score_out(sc);

	
	for (int i = 0; i <= NAME_MAX; i++) {	//erzeugen einen strings , zum kopieren
		string[i] = ptr[i];
	}

	for (int i = 0; i < NUM_ENTRY; i++) {	//vergleicht �bergeben punktestand mit liste
		if (punkte > (sc + i)->score) {
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

	fp = fopen(datei_pfad, "w");
	if (fp == NULL) {
		printf("fehler!3");
		return 0;
	}
	for (int i = 0; i < NAME_MAX-1; i++) {
		fputs(sc[i].name, fp);
		fprintf(fp,"%i", sc[i].score);
		fprintf(fp, "\n");
	}
	fclose(fp);
	
	
}



int main()
{

	char testname[NAME_MAX] = "testtest2 ";
	int testscore = 550;
	
	struct highscore sc[NUM_ENTRY];

	
 	score_up(testscore, testname);
	score_out(sc);

	
	

	//------------test ausgabe-----------
	for (int i = 0; i < NUM_ENTRY; i++) {		
		puts((sc + i)->name);
		printf("%i\n\n", (sc + i)->score);
	}
	//------------------------------------
		 
	return 1;
}

