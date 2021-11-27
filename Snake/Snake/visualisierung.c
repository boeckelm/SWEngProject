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

#include "Spielsteuerung.h"
#include "bestenliste.h"
#include "global.h"

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
    
    for (unsigned short i = 0; i < NUM_ENTRY; i++) {

        SetPosition(OFFSET_X + feldgroesse_x + 5, OFFSET_Y + i);    //Ausgabe der Bestenliste rechts neben dem Spielfeld
        printf("%d.\t%s \t %d", i + 1, score_temp[i].name, score_temp[i].score);
    }   
           

    SetPosition(5, 1); //Cursor wieder über das Spielfeld setzen für die Score-Anzeige
    printf("Score: ");

    SetPosition(0, OFFSET_Y + feld_y + 5);  //Cursor unterhalb des Spielfeldes setzen, damit bei einer Textausgabe das Spielfeld nicht zerstört wird


    return Snake_DBG_Success("Visualisation initiated");
}

Snake_DBG_t Snake_VS_Update(snakepart snake[], unsigned short Anzahl, snakepart goody, unsigned short score_count) { //Update-Funktion, bei der mittels Algorithmus nur die veränderten Elemente neu dargestellt werden

    static unsigned short highest_element_count; //Variable zum Zwischenspeichern der Länge des letzten Updates
    static snakepart last_goody, end; //Damit nicht immer das ganze Spielfeld neu dargestellt werden muss werden die Positionen des Schlangen-Endes und des Goodys zwischengespeichert
    static COORD cursor; //Rücksprungposition für den Cursor, damit der Cursor nach dem Update wieder an die gleiche Position gestellt wird

    cursor = GetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE)); //Hole aktuelle Cursor-Position (Konsolen-Cursor)

    if (first_update && Anzahl) {   //erstes Update, alle Schlangenteile müssen dargestellt werden

        highest_element_count = Anzahl; //Mindestlänge, wichtig um zu wissen ob Schlange verlängert wurde
        Snake_VS_draw_Vektor(snake[0], HEAD); //Erstes Element ist immer der Kopf
        Snake_VS_draw_Vektor(goody, GOODY); //Goody wird dargestellt

        for (unsigned short i = 1; i < Anzahl; i++) {   //Schleife zum Darstellen der verbleibenden Schlangenteile
            Snake_VS_draw_Vektor(snake[i], BODY);
        }

        last_goody.pos_X = goody.pos_X; //Zwischenspeichern der Goody-Position
        last_goody.pos_Y = goody.pos_Y;

        end.pos_X = snake[Anzahl - 1].pos_X; //Zwischenspeichern des Schlangenendes
        end.pos_Y = snake[Anzahl - 1].pos_Y;
           
        first_update = 0;

    }

    else { //Schlange existiert bereits auf Bildschirm, nur geänderte Elemente werden dargestellt

        Snake_VS_draw_Vektor(snake[0], HEAD); //Kopf verändert immer Position

        if (Anzahl > 1) Snake_VS_draw_Vektor(snake[1], BODY); //Aus alter Kopfstelle wird Schlangenkörper, falls nur der Kopf exisitert nicht

        if (Anzahl == highest_element_count) {  //Schlange wurde nicht länger

            Snake_VS_draw_Vektor(end, BLANK); //Altes Schlangenende wird wieder frei

            end.pos_X = snake[Anzahl - 1].pos_X; //Schlangenende nun an neuer Position -> Speichern
            end.pos_Y = snake[Anzahl - 1].pos_Y;
        }
        else {
            highest_element_count = Anzahl; //Schlange wurde länger, Ende bleibt also bestehen, da neues Teil am Kopf eingefügt wird
        }

       if(last_goody.pos_X != goody.pos_X || last_goody.pos_Y != goody.pos_X){ //Falls  Goody-Position verändert neu darstellen
            
            last_goody.pos_X = goody.pos_X; //Zwischenspeichern der Goody-Position
            last_goody.pos_Y = goody.pos_Y;
            Snake_VS_draw_Vektor(goody, GOODY); //Goody wird neu dargestellt

       }

    }

    SetPosition(7 + OFFSET_X, 1); //Cursor an Ausgabeposition für Score
    printf("%d", score_count); //Ausgabe Score

    SetCurser_snake(cursor); //Rücksprung an ursprüngliche Cursor-Position

    return Snake_DBG_Success(0);
}

Snake_DBG_t Snake_VS_Update_brute(snakepart snake[], unsigned short Anzahl, snakepart goody, unsigned short score_count) {  //Update-Funktion, bei dem pro Zug alle Elemente neu gezeichnet werden

    static unsigned short highest_element_count; //Variable zum Zwischenspeichern der Länge des letzten Updates
    static snakepart last_goody, end; //Damit nicht immer das ganze Spielfeld neu dargestellt werden muss werden die Positionen des Schlangen-Endes und des Goodys zwischengespeichert
    static COORD cursor; //Rücksprungposition für den Cursor, damit der Cursor nach dem Update wieder an die gleiche Position gestellt wird
    cursor = GetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE)); //Hole aktuelle Cursor-Position (Konsolen-Cursor)

    Snake_VS_end();

    Snake_VS_init(16,10);

    Snake_VS_draw_Vektor(snake[0], HEAD); //Erstes Element ist immer der Kopf
    Snake_VS_draw_Vektor(goody, GOODY); //Goody wird dargestellt
    
   for (unsigned short i = 1; i < Anzahl; i++) {   //Schleife zum Darstellen der verbleibenden Schlangenteile
            Snake_VS_draw_Vektor(snake[i], BODY);
        }

    SetPosition(7 + OFFSET_X, 1); //Cursor an Ausgabeposition für Score
    printf("%d", score_count); //Ausgabe Score

    return Snake_DBG_Success(0);
}

Snake_DBG_t Snake_VS_Startscreen(){
    
    printf("\n  ________   _____  ___         __       __   ___    _______  ");
    printf("\n /\"       ) (\\\" \\ \\|\"  \\       /\"\"\\     |/\"| /  \")  /\"     \"| ");
    printf("\n(:   \\___/  |.\\\\   \\    |     /    \\    (: |/   /  (: ______) ");
    printf("\n \\___  \\    |: \\.   \\   |    /' /\\  \\   |    __/    \\/    |   ");
    printf("\n  __/  \\\\   |.  \\   \\.  |   //  __'  \\  (// _  \\    // ___)_  ");
    printf("\n /\" \\   :)  |    \\    \\ |  /   /  \\\\  \\ |: | \\  \\  (:      \"| ");
    printf("\n(_______/    \\___|\\____\\) (___/    \\___)(__|  \\__)  \\_______) ");

    printf("\n\n Geben Sie ihren Namen ein:");
   
   return Snake_DBG_Success(0);
}


Snake_DBG_t Snake_VS_end(void) {
    first_update = 1;   //Spiel auf Anfang setzen

    system("cls");  //Fenster clearen
    SetPosition(0, 0); //Cursor oben links

    return Snake_DBG_Success("Visualisation ended!");
}

Snake_DBG_t Snake_VS_draw(short x, short y, Snake_VS_chars zeichen) {

    SetPosition(x + OFFSET_X, y + OFFSET_Y); //Setzt Cursor an richtige Stelle, Offset damit das Spielfeld nicht am Rand klebt
    putchar(zeichen); //jeweiliges Zeichen aus Enum setzen

    return Snake_DBG_Success(0);

}

Snake_DBG_t Snake_VS_draw_Vektor(snakepart vec, Snake_VS_chars zeichen) {

    unsigned short x = vec.pos_X + OFFSET_X + 1; //Offset damit Spiel nicht am Rand klebt, + 1 wegen Rand
    unsigned short y = OFFSET_Y + feld_y - vec.pos_Y; //Invertierung der y-Koordinate, weil anderer Nullpunkt zwischen unserem System (unten links) und Windows(oben links)

    SetPosition(x, y); //Cursor an übergebene Position
    putchar(zeichen);  //jeweiliges Zeichen aus Enum setzen

    return Snake_DBG_Success(0);

}

void SetPosition(short x, short y) { //Hilfsfunktion zum Setzen des Cursors mittels getrennter Koordinaten

    COORD pos = { x , y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void SetCurser_snake(COORD pos) {    //Hilfsfunktion zum Setzen des Cursors mittels mittels windowseigenem COORD-Struct

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}

COORD GetConsoleCursorPosition(HANDLE hConsoleOutput) {  //Hilfsfunktion zum Finden des aktuellen Cursors, siehe https://docs.microsoft.com/en-us/windows/console/console-screen-buffer-info-str

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
