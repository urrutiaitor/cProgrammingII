#ifndef ARIKETA1_H

#define ARIKETA1_H

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define BIZTANLERIA_MAX 100
#define BAI 1
#define EZ 0
#define UBIKAZIOA_MAX 150

typedef struct helbidea{
	char kalea[40];
	int zenbakia;
	int solairua;
	char letra;

}HELBIDEA;

typedef struct jaiotzeData{
	int urtea;
	int hilea;
	int eguna;
	int jubilatua;

}JAIOTZEDATA;

typedef struct biztanlea{
	char izena[30];
	char lehenAbizena[30];
	char bigarrenAbizena[30];
	HELBIDEA helbidea;
	JAIOTZEDATA jaiotzeData;
	int etxebizitza;
	int errenta;
	char dni[9];
	long telefonoa;

}BIZTANLEA;

void biztanleakHasieratu();
void menua();
void biztanleaSortu();
void jubilatuetaraPasatu();
void etxebizitzenBatezbestekoa();
void fitxeroetatikDatuakJaso();
void fitxeroetanDatuakSartu();


BIZTANLEA biztanleak[BIZTANLERIA_MAX];
BIZTANLEA jubilatuak[BIZTANLERIA_MAX];

#endif




