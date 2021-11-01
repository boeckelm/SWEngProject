#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX 11		//maximale länge der namesneingabe +end NULL
#define NUM_ENTRY 10	//anzahl der gespeicherten ergebnisse in bestenliste
#define datei_pfad "C:/Users/Lukas/Desktop/bestenliste.txt"

struct highscore {
	char name[NAME_MAX];
	int score;
};


/*
(error code?) req_name(char* name);
//auf maximale länge prüfen , 10 zeichen
//auf sonderzeichen prüfen , nur abc...ABC...123 (klein/groß/zahlen)
//abfrage ob name schon in Besten-liste vorhanden
	aufruf von #score_out 
	übergebene Daten(Namen) mit eingabe vergleichen
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
getch();	//keine erklärung notwendig
}


/*
(error code?) score_out(zeiger auf datenstructur);	//output 
(datei anlegen)
//öffnet die Bestenliste datei(fehlerüberprüfung)

//kopiert den inhalt in datenstructur (datenstructur definieren!)

//schließst datei(fehlerüberprüfung)
*/
score_out(struct highscore* ptr) {

	char string[NAME_MAX] = "";	//puffer für funktion atoi()

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
//der funktion wird der spielername und endpunktestand übergeben

//ruft  #score_output auf

//vergleicht die Tabellendaten und aktualisiert. sie ggf.

//speicher aktualisierte liste in der Datei (öffnen->überschreiben->schließen,Ö/S prüfen!)
*/
score_up(int punkte, char* ptr) {

	char string[NAME_MAX]="";	//string für strcpy funktion
	struct highscore sc[NUM_ENTRY];
	score_out(sc);

	
	for (int i = 0; i <= NAME_MAX; i++) {	//erzeugen einen strings , zum kopieren
		string[i] = ptr[i];
	}

	for (int i = 0; i < NUM_ENTRY; i++) {	//vergleicht übergeben punktestand mit liste
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
	//------------test ausgabe-----------
	
	char testname[NAME_MAX] = "testtest2 ";
	int testscore = 550;
	
	struct highscore sc[NUM_ENTRY];

	
 	score_up(testscore, testname);
	score_out(sc);

	
	for (int i = 0; i < NUM_ENTRY; i++) {		
		puts((sc + i)->name);
		printf("%i\n\n", (sc + i)->score);
	}
	//------------------------------------
		 
	return 1;
}

