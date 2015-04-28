#ifndef MAIN_H
#define MAIN

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#include "bistaratu.h"
#include "datuenModifikazioa.h"
#include "fitxeroetakoDatuak.h"
#include "menua.h"


#define IKASGAIMAX 10
#define IZENAMAX 10

int eskolaSortu();
int eskolaBilatu();
int eskolaAukeratu(ESKOLA **eskola_ptr_ptr, int aukeratuta);

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
	int eskola;
	char izena[30];
	HELBIDEA helbidea;
	int telefonoa;
	int ikasleak;
	int irakasleak;
	int administratzaileak;
	ESKOLA *urrengo_ptr;
}ESKOLA;


#endif