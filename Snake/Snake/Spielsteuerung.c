#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#include "visualisierung.h"
#include "Spielsteuerung.h"
#include "debug.h"
#include "eingabe.h"
#include "Bestenliste.h"

#define MAX 100 //Beschränkung der Maximalen Körperteile der Schlange
//typedef enum { false, true }bool; //Wahr/Falsch Datentyp

/*
typedef struct {
     unsigned short pos_X; //X-Position
     unsigned short pos_Y;//Y-Position 
}snakepart;
*/


//snakepart* snake;
snakepart Snake[MAX]; //Schlangenkörperpositionen
snakepart Goody; //Goodyposition 

short s_length;//aktuelle Schlangen länge
int Score;//Aktueller Punktestand

/*
typedef enum {
    up,  //W oder  ↑
    down, //S oder ↓
    left, //A oder ←
    right //D →
}stearing;
*/


/*
//-------Funktionstest Funktionen--------------
void testprintf();
void testrand();
//-------Funktionstest Funktionen--------------
*/



int main(void){//Spielfeldgröße: 16x10

    init();
    game();
   
    snake_best_up(Score);
    //Endbildschirm
    if (snake_eing_any()) {
        do {    
                
                restart();
                game();
                snake_best_up(Score);
                //Endbildschirm
        } while (snake_eing_any());
    }
    Snake_VS_end();
    Snake_DGB_Save();
    Snake_DBG_Freigeben();
     
    

    return 0;
}

void init() {
    //!!CHECKED!! 
    time_t t; 
    srand((unsigned)time(&t));  //Initialisieren des Zufallsgenerators

    s_length = 1;//Anfangslänge der Schlange =1
    Score = 0;//initialisieren des Scores mit dem Anfangswert 0

    Goody = randomGoody();
    
    for (int x = 1; x < s_length; x++) { //Vorherige Werte der Schlange aus dem Speicher löschen
        Snake[x].pos_X = (int)NULL;
        Snake[x].pos_Y = (int)NULL;
    }

    Snake[0].pos_X = 3; //Startposition
    Snake[0].pos_Y = 3;

    Snake_VS_Startscreen();
     
    snake_eing_name();

    snake_best_init();
    snake_best_up(Score);
    Snake_VS_init(16, 10);
    Snake_VS_Update(Snake, s_length, Goody, Score);

 
    last_stearing = right;
}

void restart() {
    //!!CHECKED!! 
    
    s_length = 1;//Anfangslänge der Schlange =1
    Score = 0;//initialisieren des Scores mit dem Anfangswert 0

    Goody = randomGoody();

    for (int x = 1; x < s_length; x++) { //Vorherige Werte der Schlange aus dem Speicher löschen
        Snake[x].pos_X = (int)NULL;
        Snake[x].pos_Y = (int)NULL;
    }

    Snake[0].pos_X = 3; //Startposition
    Snake[0].pos_Y = 3;

    Snake_VS_end();
    Snake_VS_init(16, 10);
    Snake_VS_Update(Snake, s_length, Goody, Score);


    last_stearing = right;
}

void wait(int waiting_time_ms) { //Programm wartet die angegebene Zeit
    //!!CHECKED!!
    long pause;
    clock_t now, then;

    pause = waiting_time_ms * (CLOCKS_PER_SEC / 1000); //Länge der Pause in ms  
    now = then = clock(); //Aktueller TIK wird gespeichert
    while ((now - then) < pause) { //Ständig überprüft ob die gegebene Wartezeit vergangen ist
        now = clock();  //Ständig aktueller TIK abgespeichert
    }

/* int x = 0; Debug Code
    while (x <= 5) {
        printf("Wert: %i", x);
        wait(500);
        x++;
    }
*/
       
}

snakepart randomGoody() {
    //!!CHECKED!!
    snakepart rGoody;//temporäre positions Variable 
    
    rGoody.pos_X= rand() %16; //Zufallswert zwischen 0-7 
    rGoody.pos_Y = rand() % 10;

    for (int y = 0; y < s_length; y++) {//Überprüft ob Schlange auf der neuen Position ist
        if (Snake[y].pos_X == rGoody.pos_X && Snake[y].pos_Y == rGoody.pos_Y) { //Abfrage ob Schlange sich auf der neuen Goodyposition befindet 
            rGoody.pos_X = rand() % 16; //Neue Position des Goodys außerhalb der Schlange
            rGoody.pos_Y = rand() % 10;
            y = 0;
        }
    }
   // printf("X:%i , Y:%i \n", rGoody.pos_X, rGoody.pos_Y);
    Snake_DBG_Success("Goody wurde erfolgreich gefressen");
    return rGoody;

/*void testrand() { //Debug Zufallsgenerator
    for (int x = 0; x < 20; x++) {
        snakepart test = randomGoody();
        printf("X:%i , Y:%i \n", test.pos_X, test.pos_Y);
        wait(100);
    }
}
*/

}

void eat(snakepart *next) {
    //!!CHECKED!!
    if ((*next).pos_X == Goody.pos_X && (*next).pos_Y == Goody.pos_Y) { //Wenn Schlange den Goody frisst wird sie um ein Element länger und der Score erhöht sich um 10 Pkt.
        s_length++;
        Score += 10;
        Goody = randomGoody();
    }
}

void game() {

    snakepart next = Snake[0];
    boolean valid_step;

    do {

        snake_eing_dir(); //Aktuelle Taste wir abgefragt

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
            Snake_DBG_Error("Falsche Eingabe");
            break;
        }

        //printf("TEST");

        valid_step = checkNextStep(&next);//Überprüft ob nächster Schritt zum Abbruch des Spiels führt
        // printf("Valid? %d",valid_step);
        if (!valid_step) {
            //printf("Spiel verloren!!");
            return;
        }
        eat(&next); //Schaut ob Schlange im nächsten Schritt den Goody berührt
        move(&next);//Bewegt die Schlange ein Feld weiter
        Snake_VS_Update(Snake, s_length, Goody, Score);

        wait(200 - (s_length * 2)); //mit zunehmender länge wird die Spielgeschwindigkeit schneller

       //Wartet 500ms
    } while (1);//solange das Spiel nicht beendet wird, wird gespielt
 

}

bool checkNextStep(snakepart *next) {
    //!!CHECKED!!
    int o = 0;
    do {
        if ((Snake[o].pos_X == (*next).pos_X) && (Snake[o].pos_Y == (*next).pos_Y)) { //Abfrage ob Schlange sich im nächsten Zug berührt
            return false;//Game over
        }
        o++;
    } while (o < s_length);
    //printf("X: %i", (*next).pos_X);
    if ((*next).pos_X == -1 || (*next).pos_X == 16 || (*next).pos_Y == -1 || (*next).pos_Y == 10) { // Abfrage ob Schlange als nächstes den Spielrand berührt
        return false;//Game over
    }
    // printf("Test");
    return true; //Nächster Schritt führt nicht zum Spielende
}

void move(snakepart *next) { //Shiftet das Erste Element im Array um eine Stelle weiter nach hinten
   //!!CHECKED!!
    for (int i = s_length-1; i > 0; i--) {
       
        Snake[i].pos_X = Snake[i-1].pos_X; //Schreib vorheriges Element in das jetzige
        Snake[i].pos_Y = Snake[i-1].pos_Y; //ohne Pointer
       
    }

    Snake[0].pos_X = (*next).pos_X; //Schlangenkopf bekommt neue pos
    Snake[0].pos_Y = (*next).pos_Y;
   
    /* Debug 
    for (int i = 0; i < s_length; i++) { 
        printf("X:%i , Y:%i ,  ", Snake[i].pos_X, Snake[i].pos_Y);  
    }*/

}

/*----Debug-------------------------------------------------------------------



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