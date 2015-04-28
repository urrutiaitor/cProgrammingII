#ifndef MAIN_H
#define MAIN

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


#define IKASGAIMAX 10
#define IZENAMAX 10

int eskolaSortu(ESKOLA **eskola_ptr_ptr);
int eskolaBilatu(ESKOLA **eskola_ptr_ptr);
int eskolaAukeratu(ESKOLA **eskola_ptr_ptr, ESKOLA **aukeratutakoEskola_ptr_ptr);
void menu(ESKOLA **eskola_ptr_ptr);

typedef struct helbidea{
	char kalea[40];
	int zenbakia;
	int postaKodea;
}HELBIDEA;

typedef struct jaiotza{
	int eguna;
	int hilea;
	int urtea;
}JAIOTZA;

typedef struct ikasgaia{
	char izena[IZENAMAX];
	float nota;
	int id;
	int aukeratuta;
}IKASGAIA;

typedef struct usuarioa{
	char izena[IZENAMAX];
	char abizena[IZENAMAX];
	int erabiltzailea;
	int pasahitza;
	JAIOTZA data;
	IKASGAIA ikasgaiak[IKASGAIMAX];
	USUARIOA *urrengo_ptr;
}USUARIOA;

typedef struct eskola{
	char izena[30];
	HELBIDEA helbidea;
	int telefonoa;
	int ikasleak;
	int irakasleak;
	int administratzaileak;
	ESKOLA *urrengo_ptr;
}ESKOLA;


#endif