#ifndef SPIELSTEUERUNG_H
#define SPIELSTEUERUNG_H



typedef struct {
     short pos_X; //X-Position
     short pos_Y;//Y-Position 
}snakepart;

typedef enum {
    up = 119,  //W oder  ↑
    down = 115, //S oder ↓
    left = 97, //A oder ←
    right = 100//D →
}stearing;

typedef enum { false, true }bool; //Wahr/Falsch Datentyp

stearing last_stearing;//letzte Tastatureingang

void init();
void restart();
snakepart randomGoody();
void wait(int);
void eat(snakepart*);
bool checkNextStep(snakepart*);
void move(snakepart*);
void game();//Snake_ErrorType game();


#endif