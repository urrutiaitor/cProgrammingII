#ifndef KOLADINAMIKOA_H
#define KOLADINAMIKOA

#include <stdio.h>
#include <math.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 10000
#define MIN -10000
#define IZENA 100

typedef struct data{
	int urti;
	int illi;
	int egune;
	int ordu;
	int minutu;
	int segundu;

}DATA;

typedef struct lana{
	int kodigu;
	char ixena[IZENA];
	int tamañu;
	DATA data;
	struct lana *aurrekoLana;
	struct lana *urrengoLana;

}LANA;

int menuBistaratu(int *aukera_ptr);
int menu(LANA **lana_ptr_ptr);
void data(DATA *data);
int lanekoDatuk(LANA **lana_ptr_ptr);
int imprimiutenSimulazioi(LANA *lana_ptr);

int lanaBixaldu(LANA **lana_ptr_ptr);
int kolakoLanakIkusi(LANA **lana_ptr_ptr);
int imprimiu(LANA **lana_ptr_ptr);
int fisikokiAurrinJarri(LANA **lana_ptr_ptr);
int imprimiuFisikoki(LANA **lana_ptr_ptr);

int hasierakuKendu(LANA **lana_ptr_ptr);
int kodigoduneAurrea(LANA **lana_ptr_ptr, int *kodigu_ptr);
int kodigoduneKendu(LANA **lana_ptr_ptr, int *kodigu_ptr);

#endif