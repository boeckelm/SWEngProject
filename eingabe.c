#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#include "eingabe.h"

//-----------------------------------------------------------//

req_name(char* ptr) {

	char name[NAME_MAX];		//Puffer für fgets()

	fgets(name, NAME_MAX, stdin);	//Name mit länge NAME_MAX einlesen, mit enter bestätigen

	for (int i = 0; i < NAME_MAX; i++) {	//Name über Zeiger kopieren
		ptr[i] = name[i];
	}
}

//-----------------------------------------------------------//

req_dir(int* ptr, float t) {

	time_t t0 = time(NULL);//Startzeit
	do
	{
		if (_kbhit())//hier wird abgefragt, ob der Nutzer eine Taste gedrückt hat
		{
			char a = _getch();	//eigentliche Tastaturabfrage

			switch (a) {		//switch.case für die eingaben w,a,s,d
			case 'w':	*ptr = up; break;		//0
			case 's':	*ptr = down; break;		//1
			case 'a':	*ptr = left; break;		//2
			case 'd':	*ptr = right; break;   	//3
			}

		}
		Sleep(10);  //10ms Pause um den Prozessor nicht zu überlasten
	} while ((time(NULL) - t0) < t);//Abbruch, wenn Zeit überschritten

}

//-----------------------------------------------------------//

req_any(){

_getch();	//beliebigen tastendruck abwarten

}

//-----------------------------------------------------------//
