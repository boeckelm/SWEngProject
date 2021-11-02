#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX 11		//maximale länge der namesneingabe +end NULL
#define NUM_ENTRY 10	//anzahl der gespeicherten ergebnisse in bestenliste
#define datei_pfad "C:/Users/Lukas/Desktop/bestenliste.txt"	//Dateipfad an der sich die Textdatei befindet

struct highscore {
	char name[NAME_MAX];
	int score;
};

enum stearing {
	up,			//W
	down,		//S
	left,		//A
	right		//D
};


req_name(char* ptr) {

	char name[NAME_MAX];		//Puffer für fgets()

	fgets(name, NAME_MAX, stdin);	//name mit länge NAME_MAX einlesen, mit enter bestätigen

	for (int i = 0; i < NAME_MAX; i++) {	//name über Zeiger kopieren
		ptr[i] = name[i];
	}
}


req_dir(int* ptr) {

	char a = _getch();	//Puffer für _getch()

	switch (a) {		//switch.case für die eingaben w,a,s,d
	case 'w':	*ptr = up; break;		//0
	case 's':	*ptr = down; break;		//1
	case 'a':	*ptr = left; break;		//2
	case 'd':	*ptr = right;			//3
	}

}


req_any(){

_getch();	//beliebigen tastendruck abwarten

}


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


score_up(int punkte, char* ptr) {

	char string[NAME_MAX]="";	//Puffer für strcpy()
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
	for (int i = 0; i < NAME_MAX-1; i++) {	
		fputs(sc[i].name, fp);	//Name in Datei schreiben
		fprintf(fp,"%i", sc[i].score);	//Punktestand in Datei schreiben
		fprintf(fp, "\n");
	}
	fclose(fp);	//Datei schließen
		
}