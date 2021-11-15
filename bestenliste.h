#ifndef BESTENLISTE_H
#define BESTENLISTE_H


struct highscore {
	char name[NAME_MAX];
	int score;
};

#define NAME_MAX 11		//maximale länge der namesneingabe +end NULL
#define NUM_ENTRY 10	//anzahl der gespeicherten ergebnisse in bestenliste
#define datei_pfad "C:/Users/Lukas/Desktop/bestenliste.txt"	//Dateipfad an der sich die Textdatei befindet

void score_out(struct highscore* ptr);

void score_up(int punkte, char* ptr);

#endif