#include <stdio.h>
#include <stdlib.h>

#define MAX 10
typedef enum { false, true }boolean;

typedef struct {
    int pos_X; //X-Position
    int pos_Y;//Y-Position
}snakepart;


snakepart Snake[MAX];
snakepart Goody;

int s_length;
int Score;


typedef enum {
    up,  //W oder  ↑
    down, //S oder ↓
    left, //A oder ←
    right //D →
}stearing;

stearing last_stearing;

void init();
void restart();
snakepart randomGoody();
void wait(int);
void eat(int,int);
boolean checkNextStep(int, int);
void move(int,int);
void game();//Snake_ErrorType game();

int main(void)//Spielfeldgröße: 7x7
{   
    init();
    return 0;
}



void init() {
    s_length = 1;
    Score = 0;
    Goody = randomGoody();
    
    for (int x = 0; x < s_length; x++) { //Vorherige Schlange aus dem Speicher löschen
        Snake[x].pos_X = NULL;
        Snake[x].pos_Y = NULL;
    }

    Snake[0].pos_X = 3; //Startposition
    Snake[0].pos_Y = 3;
}


void restart() {
    init();
}

void wait(int waiting_time_ms) {
    delay(waiting_time_ms);
}

snakepart randomGoody() {
    time_t t; //Zeitvariable für den Zufallsgenerator
    snakepart rGoody;//temporäre positions Variable 
    srand((unsigned)time(&t)); //Zufallsgenerator wird definiert

    rGoody.pos_X= rand() % 7; //Zufallswert zwischen 0-7 
    rGoody.pos_Y = rand() % 7;

    int y = 0;

    do {
        if (Snake[y].pos_X == rGoody.pos_X && Snake[y].pos_Y == rGoody.pos_Y) { //Abfrage ob Schlange sich auf der neuen Goodyposition befindet 
            rGoody.pos_X = rand() % 7; //Neue Position des Goodys außerhalb der Schlange
            rGoody.pos_Y = rand() % 7;
        }
        y++;
    } while (y < s_length);
    
    return rGoody;
}


void eat(snakepart next) {
    if (next.pos_X == Goody.pos_X && next.pos_Y == Goody.pos_Y) { //Wenn Schlange den Goody frisst wird sie um ein Element länger und der Score erhöht sich um 10 Pkt.
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
        
        valid_step = checkNextStep(next);
        if (!valid_step) {
            break;
        }
        eat(next);
        move(next);
        wait(500);
    } while (1);
    //Ausgabe des Scores und der Rangliste
}

boolean checkNextStep(snakepart next) {
    int o = 0;
    do {
        if (Snake[o].pos_X == next.pos_X && Snake[o].pos_Y == next.pos_Y) { //Abfrage ob Schlange sich im nächsten Zug berührt
            return false;//Game over
        }
        o++;
    } while (o < s_length);

    if (next.pos_X == -1 || next.pos_X == 8 || next.pos_Y == -1 || next.pos_Y == 8) { // Abfrage ob Schlange als nächstes den Spielrand berührt
        return false;//Game over
    }

    return true; //Nächster Schritt führt nicht zum Spielende
}

void move(snakepart next) { //Shiftet das Erste Element im Array um eine Stelle weiter nach hinten
   
    for (int i = s_length-1; i > 1; i--) {
        Snake[i].pos_X = Snake[i-1].pos_X;
        Snake[i].pos_Y = Snake[i-1].pos_Y;
    }

    Snake[0].pos_X = next.pos_X;
    Snake[0].pos_Y = next.pos_Y;

}
