/** @file visualisierung_debug_example.c
 *
 * @brief Beispiel zur Visualisieren des Spieles "Snake".
 *
 * @version 1.0.1
 *
 * @par
 * COPYRIGHT NOTICE: (c) 2021 Michael Böckelen, Hochschule Landshut.  All rights reserved.
 */

#include <stdio.h>
#include "debug.h"
#include "visualisierung.h"

int main()
{
    Snake_DBG_Success("Alles toll!");
    Snake_DBG_Error("Alles fehlerhaft!");

    Snake_VS_init(24, 16);

    Snake_Vektor_t snake[5];
    Snake_Vektor_t goody = { 23, 15 };
    unsigned short score = 10;
    
    
    for (unsigned short j = 15; j > 0; j--) {
        for (unsigned short i = 0; i < 5; i++) {

            snake[i].x = j+i;
            snake[i].y = 15;
        }

        Snake_VS_Update(snake, 5, goody, j+10);
        Sleep(500);
    }

    //Snake_VS_end();

    Snake_DBG_General("Hier kann ihre Werbung stehen!", SNAKE_DEBUG);

    Snake_DBG_Ausgabe_Konsole();

    Snake_DGB_Save();

    Snake_DBG_Freigeben();
    
    return 0;

}

