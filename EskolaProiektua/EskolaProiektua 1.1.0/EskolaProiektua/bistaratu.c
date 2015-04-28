#include "main.h"
#include "bistaratu.h"
#include <stdio.h>
#include <math.h>

int BISTARATU_eskolaAukeratu(ESKOLA eskolak[ESKOLAMAX]){

	int i = 0, aukera=0;
	
	printf("eskola aukeratu\n");
	for (i = 0; i <= eskolak[0].eskolaKopurua; i++){
		printf("%i. %s \n", i + 1, eskolak[i].izena);
	}
	scanf("%i", &aukera);

	return aukera-1;
}

int BISTARATU_gelaAukeratu(ESKOLA eskolak[ESKOLAMAX]){


}

void BISTARATU_notakBistaratuIkaslearentzat(ESKOLA eskolak[ESKOLAMAX]){
	
	int eskolaAutatua = 0;

	eskolaAutatua = BISTARATU_eskolaAukeratu(eskolak);
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