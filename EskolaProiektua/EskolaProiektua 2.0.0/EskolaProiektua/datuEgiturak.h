#ifndef DATUEGITURAK_H
#define DATUEGITURAK_H

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

#define IKASGAIMAX 100
#define IZENAMAX 10

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
	int irakaslea;
	float nota;
	int id;
}IKASGAIA;

typedef struct usuarioa{
	char izena[IZENAMAX];
	char abizena[IZENAMAX];
	int erabiltzailea;
	int pasahitza;
	int mota;
	JAIOTZA data;
	IKASGAIA ikasgaiak[IKASGAIMAX];
	struct usuarioa *urrengo_ptr;
}USUARIOA;

typedef struct eskola{
	char izena[30];
	HELBIDEA helbidea;
	int telefonoa;
	IKASGAIA ikasgaiak[IKASGAIMAX];
}ESKOLA;

#endif