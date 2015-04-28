#include "bistaratu.h"
//#include "main.h"
#include <stdio.h>
#include <math.h>

int BISTARATU_eskolaAukeratu(ENPRESA enpresa[1]){

	int i = 0, aukera=0;
	
	printf("eskola aukeratu\n");
	for (i = 0; i <= enpresa[0].eskolaKopurua; i++){
		printf("%i. %s \n", i+1,enpresa[0].eskolak[i].izena);
	}
	scanf("%i", &aukera);

	return aukera-1;
}

int BISTARATU_gelaAukeratu(ENPRESA enpresa[1]){


}

void BISTARATU_notakBistaratuIkaslearentzat(ENPRESA enpresa[1]){
	
	int eskolaAutatua = 0;

	eskolaAutatua = BISTARATU_eskolaAukeratu(enpresa[0]);
	printf("gela aukeratu\n");

}

void BISTARATU_notakBistaratuIrakaslearentzat(ENPRESA enpresa[1]){

}

void BISTARATU_ikaslearenBatezbestekoa(ENPRESA enpresa[1]){

}

void BISTARATU_taldekoIkasgaikoBatezbestekoa(ENPRESA enpresa[1]){

}

void BISTARATU_taldekoBatezbestekoa(ENPRESA enpresa[1]){

}

void BISTARATU_taldekoBatezbestekoHoberena(ENPRESA enpresa[1]){

}

void BISTARATU_taldekoIkasleakBatezbestekoarenArabera(ENPRESA enpresa[1]){

}