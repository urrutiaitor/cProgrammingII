#ifndef ARIKETA_CA_H
#define ARIKETA_CA

#include <stdio.h>
#include <math.h>
#include <Windows.h>
#include <stdlib.h>

#define MAX 10000
#define MIN -10000
#define IZENA 100

typedef struct zenbakia{
	double zenbakia;
	struct zenbakia *urrengo_ptr;
}ZENBAKIA, *PZENBAKIA;

typedef struct tamaina{
	int lerroak;
	int zutabeak;
}TAMAINA;

void matrizeaSortu();
ZENBAKIA* matrizeaIreki(TAMAINA* tamaina_ptr);
void matrizeaTransformatu();
void matrizeaPrintatu();
void matrizeaBistaratu(TAMAINA* tamaina_ptr, PZENBAKIA zenbakiHasiera_ptr);

#endif