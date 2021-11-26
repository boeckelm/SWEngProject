/** @file visualisierung.h
 *
 * @brief Funktionen zur Visualisieren des Spieles "Snake".
 *
 * @version 1.0.0
 *
 * @par
 * COPYRIGHT NOTICE: (c) 2021 Michael Böckelen, Hochschule Landshut.  All rights reserved.
 */

#ifndef VISUALISIERUNG_H	
#define VISUALISIERUNG_H

#include "debug.h"
#include "windows.h"
#include "Spielsteuerung.h"
#include "Bestenliste.h"

//extern highscore *score_temp;

/*typedef struct {        //Temporär bis auf Tims Struct zugegriffen werden kann
    unsigned short x;
    unsigned short y;
} Snake_Vektor_t;
*/
typedef enum {  //Enum zum einfachen Setzen der Schlangen-Zeichen
    HEAD = 169,     // Kopf     -> '®'
    BODY = 254,     // Körper   -> '■'
    BLANK = 32,     // Leer     -> ' '
    GOODY = 184,    // Goody    -> '©'
    BARRIER = 219,  // Barriere -> '█'
}Snake_VS_chars;

#define OFFSET_X 5 //Offset damit Spielfeld nicht am Rand klebt
#define OFFSET_Y 3


//Funktion zum Initialisieren des Spielfeldes
Snake_DBG_t Snake_VS_init(unsigned short feldgroesse_x,  //Übergabe der Feldgröße in X-Richtung
    unsigned short feldgroesse_y); //Übergabe der Feldgröße in Y-Richtung

//Funktion zum Updaten des Spiels pro Zug
Snake_DBG_t Snake_VS_Update(snakepart snake[], //Pointer auf Vektoren-Array mit den Schlangenelementen, 1. Element (Index 0) immer Kopf
    unsigned short Anzahl,  //Länge der Schlange, bzw. Anzahl der Schlangenelemente
    snakepart goody,   //Koordinaten des Goodys
    unsigned short score);  //Momentaner Score

Snake_DBG_t Snake_VS_Update_brute(snakepart snake[], //Pointer auf Vektoren-Array mit den Schlangenelementen, 1. Element (Index 0) immer Kopf
    unsigned short Anzahl,  //Länge der Schlange, bzw. Anzahl der Schlangenelemente
    snakepart goody,   //Koordinaten des Goodys
    unsigned short score);  //Momentaner Score


Snake_DBG_t Snake_VS_Startscreen();    //Ausgabe eines Console-Art Startbildschirms

//Funktion um Spiel zu beenden
Snake_DBG_t Snake_VS_end(void);

//Funktion zum Darstellen der Bestenliste, TBA
//Snake_DBG_t Snake_VS_Rangliste(Snake_Rangliste_t[10], char* text); //Placeholder!


//Hilfsfunktion zum Zeichnen einzelner Zeichen mit Übergabe getrennter Koordinaten
Snake_DBG_t Snake_VS_draw(short x,  //x-Position 
    short y,  //y-Position
    Snake_VS_chars zeichen); //Zeichen aus obigem Enum

//Hilfsfunktion zum Zeichnen einzelner Zeichen mit Übergabe eines Vektors
Snake_DBG_t Snake_VS_draw_Vektor(snakepart vec, //Übergabe der Koordianten in Vektor-Form
    Snake_VS_chars zeichen); //Zeichen aus obigem Enum

//Hilfsfunktion zum Setzen des Cursors
void SetPosition(short x,   //x-Position 
    short y);  //y-Position 

//Hilfsfunktion zum Setzen des Cursors
void SetCurser_snake(COORD pos); //Übergabe des Windows-eigenen Koordinaten-Structs

//Windows-Magic zum Herausfinden der aktuellen Cursor-Position :)
COORD GetConsoleCursorPosition(HANDLE hConsoleOutput);












#endif