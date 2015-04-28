#include "main.h"
#include "menua.h"
//#include "datuenModifikazioa.h"
#include <stdio.h>
#include <math.h>


int MENUA_erabiltzaileaAukeratu(ESKOLA eskolak[ESKOLAMAX]){
	int aukera = 0;

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
	int aukera = 0;

	switch (aukera){

	case 1: 
		BISTARATU_eskolaAukeratu(eskolak);
		break;

	case 2:
		DATUENMODIFIKAZIOA_eskolakoDatuakSartu(eskolak);
		break;

	}
}

int MENUA_eskolaAukeratuBesteak(ESKOLA eskolak[ESKOLAMAX]){

	BISTARATU_eskolaAukeratu(eskolak);
}

void MENUA_aukerakAdministratzailea(ESKOLA eskolak[ESKOLAMAX]){
	int aukera = 0;

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