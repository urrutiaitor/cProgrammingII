#include "main.h"
#include "menua.h"
#include <stdio.h>
#include <math.h>


int MENUA_erabiltzaileaAukeratu(ESKOLA eskolak[ESKOLAMAX]){
	int aukera = 0;

	do{

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
		system("cls");

	} while (aukera != 0);

	return aukera;
}

void MENUA_eskolaAukeratuAdministratzailea(ESKOLA eskolak[ESKOLAMAX]){
	int aukera = 0, aux = 0;

	do{

		printf("1.eskola aukeratu\n");
		printf("2.eskola berria sartu\n");
		fflush(stdin);
		scanf("%i", &aux);
		
		switch (aux){

		case 1:
			MENUA_eskolaAukeratuBistaratu(eskolak);
			MENUA_aukerakAdministratzailea(eskolak);
			break;

		case 2:
			DATUENMODIFIKAZIOA_eskolakoDatuakSartu(eskolak);
			break;
		
		}
		system("cls");

	} while (aux != 0);
}

void MENUA_aukerakAdministratzailea(ESKOLA eskolak[ESKOLAMAX]){
	int aukera = 0;

	do{
		
			aukera = MENUA_aukerakAdministratzaileaBistaratu(eskolak);
		
		switch (aukera){

		case 1: DATUENMODIFIKAZIOA_ikasleBatSartu(eskolak);
			break;

		case 2: DATUENMODIFIKAZIOA_eskolakoDatuakModifikatu(eskolak);
			break;

		case 3: DATUENMODIFIKAZIOA_gelaFisikoaAsignatu(eskolak);
			break;

		case 4: DATUENMODIFIKAZIOA_irakasleakAsignatu(eskolak);
			break;

		case 5: DATUENMODIFIKAZIOA_tutoreaAsignatu(eskolak);
			break;

		case 6: DATUENMODIFIKAZIOA_ikasgaiakSartuAdministrazioa(eskolak);
			break;

		case 7: DATUENMODIFIKAZIOA_eskolakoMailakJarri(eskolak);
			break;
		default:MENUA_aukerakAdministratzailea(eskolak);
			break;
		}
		system("cls");

	} while (aukera != 0);

}

void MENUA_aukerakIrakaslea(ESKOLA eskolak[ESKOLAMAX]){
	int aukera = 0;
	
	do{

		aukera = MENUA_aukerakIrakasleaBistaratu(eskolak);

		switch (aukera){
		case 1: DATUENMODIFIKAZIOA_notakSartu(eskolak);
			break;

		case 2: BISTARATU_notakBistaratuIrakaslearentzat(eskolak);
			break;

		case 3: BISTARATU_ikaslearenBatezbestekoa(eskolak);
			break;

		case 4: BISTARATU_taldekoIkasgaikoBatezbestekoa(eskolak);
			break;

		case 5: BISTARATU_taldekoBatezbestekoa(eskolak);
			break;

		case 6: BISTARATU_taldekoBatezbestekoHoberena(eskolak);
			break;

		case 7: BISTARATU_taldekoIkasleakBatezbestekoarenArabera(eskolak);
			break;

		default:
			break;
		}
		system("cls");

	} while (aukera != 0);

}

void MENUA_aukerakIkaslea(ESKOLA eskolak[ESKOLAMAX]){
	int aukera = 0;

	do{

		aukera = MENUA_aukerakIkasleaBistaratu(eskolak);

		switch (aukera){

		case 1: BISTARATU_notakBistaratuIkaslearentzat(eskolak);
			break;

		case 2: BISTARATU_ikaslearenBatezbestekoa(eskolak);
			break;
		}
		system("cls");

	} while (aukera != 0);

}





int MENUA_erabiltzaileaAukeratuBistaratu(ESKOLA eskolak[ESKOLAMAX]){
	int aukera = 0;

	printf("Aukeratu:\n");
	printf("1. Administratzailea\n");
	printf("2. Irakaslea\n");
	printf("3. Ikaslea\n");
	printf("0. Irten\n");
	scanf("%i", &aukera);
	fflush(stdin);
	system("cls");

	return aukera;
}

int MENUA_aukerakAdministratzaileaBistaratu(ESKOLA eskolak[ESKOLAMAX]){
	int aukera = 0;

	printf("1. Ikasle berri bat sartu\n");
	printf("2. Eskolako datuak modifikatu\n");
	printf("3. Gela fisikoa asignatu\n");
	printf("4. Irakasleak asignatu\n");
	printf("5. Tutorea asignatu\n");
	printf("6. Ikasgai posibleak sartu\n");
	printf("7. Maila berri bat sartu\n");
	printf("0. Irten\n");
	scanf("%i", &aukera);
	fflush(stdin);
	system("cls");

	return aukera;
}

int MENUA_aukerakIrakasleaBistaratu(ESKOLA eskolak[ESKOLAMAX]){
	int aukera = 0;

	printf("1. Notak sartu\n");
	printf("2. Notak ikusi\n");
	printf("3. Ikaslearen batezbestekoa ikusi\n");
	printf("4. Ikasgaiko batezbestekoa taldeka ikusi\n");
	printf("5. Taldeko batezbestekoa ikusi\n");
	printf("6. Taldeko batezbesteko hoberena ikusi\n");
	printf("7. Taldeko ikasleak batezbestekoaren arabera ikusi\n");
	printf("0. Irten\n");
	scanf("%i", &aukera);
	system("cls");

	return aukera;
}

int MENUA_aukerakIkasleaBistaratu(ESKOLA eskolak[ESKOLAMAX]){
	int aukera = 0;

	printf("1. Notak ikusi\n");
	printf("2. Batezbestekoa ikusi\n");
	scanf("%i", &aukera);
	system("cls");

	return aukera;
}

void MENUA_eskolaAukeratuBistaratu(ESKOLA eskolak[ESKOLAMAX]){

	int i = 0, aukera = 0;

	printf("Eskola aukeratu:\n");
	for (i = 0; i < eskolak[0].eskolaKopurua; i++){
		printf("%i. %s \n", i + 1, eskolak[i].izena);
		
	}
	scanf("%i", &aukera);
	aukera = aukera - 1;
	eskolak[0].aukeratutakoEskola = aukera;
	system("cls");

}