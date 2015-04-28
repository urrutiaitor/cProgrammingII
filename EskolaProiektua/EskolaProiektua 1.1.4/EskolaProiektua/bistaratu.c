#include "main.h"
#include "bistaratu.h"
#include <stdio.h>
#include <math.h>
#include<string.h>
#include <stdlib.h>



int BISTARATU_gelaAukeratu(ESKOLA eskolak[ESKOLAMAX]){
	int gela = 0, ikaslea = 0, ikasgaia = 0;
	int i = 0;
	int eskola = 0;

	printf("Zein gela nahi duzu aukeratu?\n");
	for (i = 0; i < GELAMAX; i++){
		if (eskolak[eskolak[0].aukeratutakoEskola].gelak[i].ikasleKopurua>0){
			printf("%i. %s\n", i + 1, eskolak[eskola].gelak[i].maila);
		}
	}
	scanf("%i", &gela);
	fflush(stdin);
	gela = gela - 1;

	return gela;

}

void BISTARATU_notakBistaratuIkaslearentzat(ESKOLA eskolak[ESKOLAMAX]){
	
	int eskolaAutatua = 0;

	MENUA_eskolaAukeratuBistaratu(eskolak);
	printf("gela aukeratu\n");

}

void BISTARATU_notakBistaratuIrakaslearentzat(ESKOLA eskolak[ESKOLAMAX]){

}

void BISTARATU_ikaslearenBatezbestekoa(ESKOLA eskolak[ESKOLAMAX]){

}

void BISTARATU_taldekoIkasgaikoBatezbestekoa(ESKOLA eskolak[ESKOLAMAX]){

}

void BISTARATU_taldekoBatezbestekoa(ESKOLA eskolak[ESKOLAMAX]){

}

void BISTARATU_taldekoBatezbestekoHoberena(ESKOLA eskolak[ESKOLAMAX]){

}

void BISTARATU_taldekoIkasleakBatezbestekoarenArabera(ESKOLA eskolak[ESKOLAMAX]){

}