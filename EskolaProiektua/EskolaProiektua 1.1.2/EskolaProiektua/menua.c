#include "main.h"
#include "menua.h"
#include <stdio.h>
#include <math.h>


int MENUA_erabiltzaileaAukeratu(ESKOLA eskolak[ESKOLAMAX]){
	int aukera = 0;

	aukera = MENUA_erabiltzaileaAukeratuBistaratu(eskolak);

	switch (aukera){

	case 1:
		MENUA_eskolaAukeratuAdministratzailea(eskolak);
		MENUA_aukerakAdministratzailea(eskolak);
		break;

	case 2:
		MENUA_aukerakIrakaslea(eskolak);
		break;

	case 3:
		MENUA_aukerakIkaslea(eskolak);
		break;

	default:
		break;

	}
	return aukera;
}

int MENUA_eskolaAukeratuAdministratzailea(ESKOLA eskolak[ESKOLAMAX]){
	int aukera = 0, aux = 0;

	printf("1.eskola aukeratu\n");
	printf("2.eskola berria sartu\n");
	scanf("%i", &aux);
	switch (aux){

	case 1:
		MENUA_eskolaAukeratuBistaratu(eskolak);
		break;

	case 2:
		DATUENMODIFIKAZIOA_eskolakoDatuakSartu(eskolak);
		break;

	}
}

int MENUA_eskolaAukeratuBesteak(ESKOLA eskolak[ESKOLAMAX]){

	MENUA_eskolaAukeratuBistaratu(eskolak);
}

void MENUA_aukerakAdministratzailea(ESKOLA eskolak[ESKOLAMAX]){
	int aukera = 0;

	aukera = MENUA_aukerakAdministratzaileaBistaratu(eskolak);

	switch (aukera){

	case 1:
		DATUENMODIFIKAZIOA_eskolakoDatuakSartu(eskolak);
		break;

	case 2:
		DATUENMODIFIKAZIOA_ikasleBatSartu(eskolak);
		break;

	case 3:
		DATUENMODIFIKAZIOA_ikasleakGeletanBanatu(eskolak);
		break;

	case 4:
		DATUENMODIFIKAZIOA_gelaFisikoaAsignatu(eskolak);
		break;

	case 5:
		DATUENMODIFIKAZIOA_tutoreaAsignatu(eskolak);
		break;

	case 6:
		//irten

	default:
		break;
	}

}

void MENUA_aukerakIrakaslea(ESKOLA enpresa[ESKOLAMAX]){



}

void MENUA_aukerakIkaslea(ESKOLA enpresa[ESKOLAMAX]){


}





int MENUA_erabiltzaileaAukeratuBistaratu(ESKOLA eskolak[ESKOLAMAX]){
	int aukera = 0;

	printf("aukeratu:\n");
	printf("1.Administratzailea\n");
	printf("2.Irakaslea\n");
	printf("3.Ikaslea\n");
	scanf("%i", &aukera);

	return aukera;
}

int MENUA_aukerakAdministratzaileaBistaratu(ESKOLA eskolak[ESKOLAMAX]){

}

int MENUA_aukerakIrakasleaBistaratu(ESKOLA eskolak[ESKOLAMAX]){

}

int MENUA_aukerakIkasleaBistaratu(ESKOLA eskolak[ESKOLAMAX]){

}

void MENUA_eskolaAukeratuBistaratu(ESKOLA eskolak[ESKOLAMAX]){

	int i = 0, aukera = 0;

	printf("eskola aukeratu\n");
	for (i = 0; i <= eskolak[0].eskolaKopurua; i++){
		printf("%i. %s \n", i + 1, eskolak[i].izena);
	}
	scanf("%i", &aukera);
	eskolak[0].aukeratutakoEskola = aukera;


}