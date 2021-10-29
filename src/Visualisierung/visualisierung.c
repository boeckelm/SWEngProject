/** @file visualisierung.c
 *
 * @brief Funktionen zur Visualisieren des Spieles "Snake".
 *
 * @version 1.0.0
 * 
 * @par
 * COPYRIGHT NOTICE: (c) 2021 Michael Böckelen, Hochschule Landshut.  All rights reserved.
 */

#define _CRT_SECURE_NO_WARNINGS

#include "visualisierung.h"
#include "debug.h"

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#include <Windows.h> //Manches funktioniert nur bei großem bzw kleinem w, warum auch immer
#endif


static unsigned short feld_y, first_update = 1; //Globale Variablen zum Setzen der Feldgröße, sowie zu Speichern, ob die Update-Funktion bereits aufgerufen wurde

Snake_DBG_t Snake_VS_init(unsigned short feldgroesse_x, unsigned short feldgroesse_y) {

    system("cls");

    //Setzen der globalen Variablen
    feld_y = feldgroesse_y; //Feldhöhe, damit die Cursor-Funktion den Offset zwischen unserem Nullpunkt (unten links) dem der Windows-Konsole (oben links) bestimmen kann. 
       
   
    //Zeichnen des Spielfeldrandes
    for (unsigned short i = 0; i <= feldgroesse_x + 1; i++)//Werte 0 und breite+1 für die Ecken
    {
        Snake_VS_draw(i, 0, BARRIER); //oberer Rand
        Snake_VS_draw(i, feldgroesse_y + 1, BARRIER);//unterer Rand
    }
    for (unsigned short i = 1; i <= feldgroesse_y; i++)
    {
        Snake_VS_draw(0, i, BARRIER); //linker Rand
        Snake_VS_draw(feldgroesse_x + 1, i, BARRIER);//rechter Rand
    }

    SetPosition(5,1); //Cursor wieder über das Spielfeld setzen für die Score-Anzeige
    printf("Score: ");

    SetPosition(0, OFFSET_Y + feld_y + 5);  //Cursor unterhalb des Spielfeldes setzen, damit bei einer Textausgabe das Spielfeld nicht zerstört wird


    return Snake_DBG_Success("Visualisation initiated"); 
}

Snake_DBG_t Snake_VS_Update(Snake_Vektor_t snake[], unsigned short Anzahl, Snake_Vektor_t goody, unsigned short score_count) {

    static unsigned short highest_element_count; //Variable zum Zwischenspeichern der Länge des letzten Updates
    static Snake_Vektor_t last_goody, end; //Damit nicht immer das ganze Spielfeld neu dargestellt werden muss werden die Positionen des Schlangen-Endes und des Goodys zwischengespeichert
    static COORD cursor; //Rücksprungposition für den Cursor, damit der Cursor nach dem Update wieder an die gleiche Position gestellt wird

    cursor = GetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE)); //Hole aktuelle Cursor-Position (Konsolen-Cursor)

    if (first_update && Anzahl) {   //erstes Update, alle Schlangenteile müssen dargestellt werden

        highest_element_count = Anzahl; //Mindestlänge, wichtig um zu wissen ob Schlange verlängert wurde
        Snake_VS_draw_Vektor(snake[0], HEAD); //Erstes Element ist immer der Kopf
        Snake_VS_draw_Vektor(goody, GOODY); //Goody wird dargestellt

        for (unsigned short i = 1; i < Anzahl; i++) {   //Schleife zum Darstellen der verbleibenden Schlangenteile
            Snake_VS_draw_Vektor(snake[i], BODY);
        }

        last_goody.x = goody.x; //Zwischenspeichern der Goody-Position
        last_goody.y = goody.y;

        end.x = snake[Anzahl - 1].x; //Zwischenspeichern des Schlangenendes
        end.y = snake[Anzahl - 1].y;

        first_update = 0; 

    }

    else { //Schlange existiert bereits auf Bildschirm, nur geänderte Elemente werden dargestellt

        Snake_VS_draw_Vektor(snake[0], HEAD); //Kopf verändert immer Position

        if (Anzahl > 1) Snake_VS_draw_Vektor(snake[1], BODY); //Aus alter Kopfstelle wird Schlangenkörper, falls nur der Kopf exisitert nicht

        if (Anzahl == highest_element_count) {  //Schlange wurde nicht länger

            Snake_VS_draw_Vektor(end, BLANK); //Altes Schlangenende wird wieder frei

            end.x = snake[Anzahl - 1].x; //Schlangenende nun an neuer Position -> Speichern
            end.y = snake[Anzahl - 1].y;
        }
        else {
            highest_element_count = Anzahl; //Schlange wurde länger, Ende bleibt also bestehen, da neues Teil am Kopf eingefügt wird
        }
    }
    
    SetPosition(7 + OFFSET_X, 1); //Cursor an Ausgabeposition für Score
    printf("%d", score_count); //Ausgabe Score

    SetCurser_snake(cursor); //Rücksprung an ursprüngliche Cursor-Position

    return Snake_DBG_Success(0);
}

Snake_DBG_t Snake_VS_end(void) {
    first_update = 1;   //Spiel auf Anfang setzen

    system("cls");  //Fenster clearen
    SetPosition(0, 0); //Cursor oben links

    return Snake_DBG_Success("Visualisation ended!");
}

Snake_DBG_t Snake_VS_draw(short x, short y, Snake_VS_chars zeichen){

    SetPosition(x + OFFSET_X, y + OFFSET_Y); //Setzt Cursor an richtige Stelle, Offset damit das Spielfeld nicht am Rand klebt
    putchar(zeichen); //jeweiliges Zeichen aus Enum setzen

    return Snake_DBG_Success(0);
       
}

Snake_DBG_t Snake_VS_draw_Vektor(Snake_Vektor_t vec, Snake_VS_chars zeichen) {

     unsigned short x = vec.x + OFFSET_X + 1; //Offset damit Spiel nicht am Rand klebt, + 1 wegen Rand
     unsigned short y = OFFSET_Y + feld_y  - vec.y; //Invertierung der y-Koordinate, weil anderer Nullpunkt zwischen unserem System (unten links) und Windows(oben links)

     SetPosition(x, y); //Cursor an übergebene Position
     putchar(zeichen);  //jeweiliges Zeichen aus Enum setzen

     return Snake_DBG_Success(0);

 }

void SetPosition(short x, short y){ //Hilfsfunktion zum Setzen des Cursors mittels getrennter Koordinaten

    COORD pos = { x , y }; 
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void SetCurser_snake(COORD pos){    //Hilfsfunktion zum Setzen des Cursors mittels mittels windowseigenem COORD-Struct

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    
}

COORD GetConsoleCursorPosition(HANDLE hConsoleOutput){  //Hilfsfunktion zum Finden des aktuellen Cursors, siehe https://docs.microsoft.com/en-us/windows/console/console-screen-buffer-info-str

    CONSOLE_SCREEN_BUFFER_INFO console;
    if (GetConsoleScreenBufferInfo(hConsoleOutput, &console))
    {
        return console.dwCursorPosition;
    }
    else
    {
        //Fail
        COORD fallback = { 0, 0 };
        return fallback;
    }
}