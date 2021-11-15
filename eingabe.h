#ifndef EINGABE_H
#define EINGABE_H

enum stearing {
	up,			//W
	down,		//S
	left,		//A
	right		//D
};

void req_name(char* ptr);

void req_dir(int* ptr, float t);

void req_any();

#endif