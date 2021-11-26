//Erstellt von Lukas Sellmaier
#ifndef Bestenliste_h
#define Bestenliste_h

#include "Global.h"


typedef struct {
	char name[NAME_MAX];
	int score;
	
}highscore;
highscore score_temp[NUM_ENTRY];		//globale Variable für die Bestenliste


int snake_best_out(struct highscore* ptr);

int snake_best_up(int punkte);

int snake_best_init();

#endif