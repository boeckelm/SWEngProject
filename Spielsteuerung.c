#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10 //Beschränkung der Maximalen Körperteile der Schlange
typedef enum { false, true }boolean; //Wahr/Falsch Datentyp

typedef struct {
    int pos_X; //X-Position
    int pos_Y;//Y-Position 
}snakepart;


snakepart Snake[MAX]; //Schlangenkörperpositionen
snakepart Goody; //Goodyposition 

int s_length;//aktuelle Schlangen länge
int Score;//Aktueller Punktestand


typedef enum {
    up,  //W oder  ↑
    down, //S oder ↓
    left, //A oder ←
    right //D →
}stearing;

stearing last_stearing;//letzte Tastatureingang

void init();
void restart();
snakepart randomGoody();
void wait(int);
void eat(snakepart*);
boolean checkNextStep(snakepart*);
void move(snakepart*);
void game();//Snake_ErrorType game();

//-------Funktionstest Funktionen--------------
void testprintf();
void testrand();
//-------Funktionstest Funktionen--------------


int main(void)//Spielfeldgröße: 7x7
{   
    init();
    //testrand();

    /*     Test von move für die Schlange 
    testprintf();
    snakepart next;
    next.pos_X = 3;
    next.pos_Y = 2;
    s_length = 2;
    move(&next);
    //game();
    printf("\n");
    testprintf();

    next.pos_X = 2;
    next.pos_Y = 2;
    s_length = 2;
    move(&next);
    //game();
    printf("\n");
    testprintf();

    next.pos_X = 1;
    next.pos_Y = 2;
    s_length = 2;
    move(&next);
    //game();
    printf("\n");
    testprintf();
    
    next.pos_X = 1;
    next.pos_Y = 3;
    s_length = 2;
    move(&next);
    //game();
    printf("\n");
    testprintf();
    */


    return 0;
}

void init() {
    s_length = 1;//Anfangslänge der Schlange =1
    Score = 0;//initialisieren des Scores mit dem Anfangswert 0
    Goody = randomGoody();
    
    for (int x = 0; x < s_length; x++) { //Vorherige Werte der Schlange aus dem Speicher löschen
        Snake[x].pos_X = (int)NULL;
        Snake[x].pos_Y = (int)NULL;
    }

    Snake[0].pos_X = 3; //Startposition
    Snake[0].pos_Y = 3;
}


void restart() {
    init(); //Alle Variablen zurücksetzen
}

void wait(int waiting_time_ms) {
   // delay(waiting_time_ms);
}

snakepart randomGoody() {
 
    snakepart rGoody;//temporäre positions Variable 
   
    rGoody.pos_X= rand() % 7; //Zufallswert zwischen 0-7 
    rGoody.pos_Y = rand() % 7;

    int y = 0;

    do {//Überprüft ob Schlange auf der neuen Position ist
        if (Snake[y].pos_X == rGoody.pos_X && Snake[y].pos_Y == rGoody.pos_Y) { //Abfrage ob Schlange sich auf der neuen Goodyposition befindet 
            rGoody.pos_X = rand() % 7; //Neue Position des Goodys außerhalb der Schlange
            rGoody.pos_Y = rand() % 7;
        }
        y++;
    } while (y < s_length);
    
    return rGoody;
}


void eat(snakepart *next) {
    if ((*next).pos_X == Goody.pos_X && (*next).pos_Y == Goody.pos_Y) { //Wenn Schlange den Goody frisst wird sie um ein Element länger und der Score erhöht sich um 10 Pkt.
        s_length++;
        Score += 10;
        Goody = randomGoody();
    }
}


void game() {

     snakepart next=Snake[0];
     boolean valid_step;

    do {
        //Aktuelle Taste wir abgefragt
        switch (last_stearing)
        {
        case up:
            next.pos_Y++;
            break;
        case down:
            next.pos_Y--;
            break;
        
        case left:
            next.pos_X--;
            break;
        
        case right:
            next.pos_X++;
            break;
        default:
            //Error Message Invalid Input
            break;
        }
        
        valid_step = checkNextStep(&next);//Überprüft ob nächster Schritt zum Abbruch des Spiels führt
        if (!valid_step) {
            break;
        }
        eat(&next); //Schaut ob Schlange im nächsten Schritt den Goody berührt
        move(&next);//Bewegt die Schlange ein Feld weiter
        wait(500);//Wartet 500ms
    } while (1);//solange das Spiel nicht beendet wird, wird gespielt
    //Ausgabe des Scores und der Rangliste
}

boolean checkNextStep(snakepart *next) {
    int o = 0;
    do {
        if (Snake[o].pos_X == (*next).pos_X && Snake[o].pos_Y == (*next).pos_Y) { //Abfrage ob Schlange sich im nächsten Zug berührt
            return false;//Game over
        }
        o++;
    } while (o < s_length);

    if ((*next).pos_X == -1 || (*next).pos_X == 8 || (*next).pos_Y == -1 || (*next).pos_Y == 8) { // Abfrage ob Schlange als nächstes den Spielrand berührt
        return false;//Game over
    }

    return true; //Nächster Schritt führt nicht zum Spielende
}

void move(snakepart *next) { //Shiftet das Erste Element im Array um eine Stelle weiter nach hinten
   
    for (int i = s_length-1; i > 0; i--) {
        Snake[i].pos_X = Snake[i-1].pos_X; //Schreib vorheriges Element in das jetzige
        Snake[i].pos_Y = Snake[i-1].pos_Y;
    }

    Snake[0].pos_X = (*next).pos_X; //Schlangenkopf bekommt neue pos
    Snake[0].pos_Y = (*next).pos_Y;

/* Debug 
    for (int i = 0; i < s_length; i++) { 
        printf("X:%i , Y:%i ,  ", Snake[i].pos_X, Snake[i].pos_Y);  
    }*/
}

/*
void testrand() { //Debug Zufallsgenerator
    for (int x = 0; x < 1000; x++) {
        snakepart test = randomGoody();
        printf("X:%i , Y:%i \n", test.pos_X, test.pos_Y);
    }
   
}


void testprintf() {//Debugausgabe 

    for (int x = 0; x < 7; x++) {
        for (int y = 0; y < 7; y++) {
            for (int z = 0; z < 10; z++) {
                if (Snake[z].pos_X != NULL && Snake[z].pos_Y != NULL) {
                    if (Snake[z].pos_X == x && Snake[z].pos_Y == y) {
                        printf("X");
                        y++;
                    }
                }
                  
            }
            printf("O");
        }
        printf("\n");
    }
}

*/