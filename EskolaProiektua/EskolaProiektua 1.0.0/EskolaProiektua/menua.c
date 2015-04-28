#include "main.h"
#include "menua.h"
//#include "datuenModifikazioa.h"
#include <stdio.h>
#include <math.h>


int MENUA_erabiltzaileaAukeratu(ENPRESA enpresa[1]){
	int aukera = 0;

	switch (aukera){

	case 1:
		MENUA_eskolaAukeratuAdministratzailea(enpresa);
		MENUA_aukerakAdministratzailea(enpresa);
		break;

	case 2: 
		MENUA_aukerakIrakaslea(enpresa);
		break;

	case 3:
		MENUA_aukerakIkaslea(enpresa);
		break;

	default:
		break;
	}
	return aukera;
}

int MENUA_eskolaAukeratuAdministratzailea(ENPRESA enpresa[1]){
	int aukera = 0;

	switch (aukera){

	case 1: 
		BISTARATU_eskolaAukeratu(enpresa[0]);
		break;

	case 2:
		DATUENMODIFIKAZIOA_eskolakoDatuakSartu(enpresa[0]);
		break;

	}
}

int MENUA_eskolaAukeratuBesteak(ENPRESA enpresa[1]){

	BISTARATU_eskolaAukeratu(enpresa[0]);
}

void MENUA_aukerakAdministratzailea(ENPRESA enpresa[1]){
	int aukera = 0;

	switch (aukera){

	case 1:
		DATUENMODIFIKAZIOA_eskolakoDatuakSartu(enpresa[0]);
		break;

	case 2:
		DATUENMODIFIKAZIOA_ikasleBatSartu(enpresa[0]);
		break;

	case 3:
		DATUENMODIFIKAZIOA_ikasleakGeletanBanatu(enpresa[0]);
		break;

	case 4:
		DATUENMODIFIKAZIOA_gelaFisikoaAsignatu(enpresa[0]);
		break;

	case 5:
		DATUENMODIFIKAZIOA_tutoreaAsignatu(enpresa[0]);
		break;

	case 6:
		//irten

	default:
		break;
	}

}

void MENUA_aukerakIrakaslea(ENPRESA enpresa[1]){

	

}

void MENUA_aukerakIkaslea(ENPRESA enpresa[1]){


}