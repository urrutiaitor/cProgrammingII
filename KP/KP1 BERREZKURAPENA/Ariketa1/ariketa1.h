#ifndef ARIKETA1_H

#define ARIKETA1_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define BAI 1
#define EZ 0
#define IZENAMAX 30
#define KONTUKORRONTEAMAX 20

#define DENAONDO 1
#define TXARTO 0
#define IZENATXARTO 2
#define ABIZENATXARTO 3
#define IZENAABIZENATXARTO 4

typedef struct helbidea{
	char kalea[40];
	int zenbakia;
	int solairua;
	char letra[3];

}HELBIDEA;

typedef struct jaiotzeData{
	int urtea;
	int hilea;
	int eguna;

}JAIOTZEDATA;

typedef struct biztanlea{
	char izena[IZENAMAX];
	char abizena[IZENAMAX];
	HELBIDEA helbidea;
	JAIOTZEDATA jaiotzeData;
	int kodea;
	char kontuKorrontea[KONTUKORRONTEAMAX];

}BIZTANLEA;

void biztanleaSartu();
BIZTANLEA datuakJaso();
void piszinaraSarrera();
int datuakKonprobatu(int kodea, char *izena, char *abizena);

#endif




