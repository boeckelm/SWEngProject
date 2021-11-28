//Erstellt von Lukas Sellmaier
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "eingabe.h"
#include "Global.h"
//#include "Spielsteuerung.h"

// Namenseingabe über Zeiger auf den zu beschreibenden Namen

#define _CRT_SECURE_NO_WARNINGS

void snake_eing_name() 
{

	int len = 0;
	char string[NAME_MAX+1] = "";
	char string_help[NAME_MAX] = "---------";	//evtl noch anzahl mit name_max initialisieren
	fgets(string, NAME_MAX+1, stdin);
	len = strlen(string)-1;

	if (len > NAME_MAX - 1)
		len = NAME_MAX - 1;

	strncpy_s(spielername,NAME_MAX, string, len);
	strncat_s(spielername, NAME_MAX, string_help, (NAME_MAX - 1) - len);

}
 


// Abfrage der Bewegungsrichtung

void snake_eing_dir() 
{

		if (_kbhit())//hier wird abgefragt, ob der Nutzer eine Taste gedrückt hat
		{
			char a = _getch();	//eigentliche Tastaturabfrage

			switch (a) {		//switch.case für die eingaben w,a,s,d
			case 'w':	last_stearing = up; break;		//0
			case 's':	last_stearing = down; break;		//1
			case 'a':	last_stearing = left; break;		//2
			case 'd':	last_stearing = right; break;   	//3
			}
		}


}



// Auf beliebige Tasteneingabe warten
bool snake_eing_any() 
{
	printf_s("Möchten Sie nochmal Spielen? [J/N]");

	char i = "a";

	while (i!= 'J' || 'j' || 'N' || 'n') {
		i = _getch();

		if (i == 'J' || i == 'j')
			return true;
		if (i == 'N' || i == 'n')
			return false;
	}
}
