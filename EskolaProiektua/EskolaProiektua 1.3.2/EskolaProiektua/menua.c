#include "main.h"
#include "menua.h"

ESKOLA MENUA_eskolaAukeratu(){
	//aldagaiak
	FILE* fitxeroa;
	int i = 0;
	ESKOLA eskolak[ESKOLAMAX];
	int aukera = 0;

	//programa
	if ((fitxeroa = fopen("eskolak.dat", "rb")) == NULL){
		printf("Eskolako datu basea ezin izan da ireki\n");
	}
	else{
		for (i = 0; i < ESKOLAMAX; i++){
			fread(&eskolak[i], sizeof (ESKOLA), 1, fitxeroa);
		}

		printf("Zein eskola nahi duzu aukeratu:\n");
		for (i = 0; i < ESKOLAMAX; i++){
			printf("%i. %s", i + 1, eskolak[i].izena);
		}
		scanf("%i", &aukera);
		aukera = aukera - 1;

	}

	//return 
	return eskolak[aukera];
	
}



int MENUA_erabiltzaileaAukeratu(ESKOLA eskola){
	//aldagaiak
	int aukera = 0;
	int erabiltzailea = 0;

	//programa
	do{

		erabiltzailea = MENUA_erabiltzaileaAukeratuBistaratu(eskola);
		aukera = erabiltzailea / 10000000;

		switch (aukera){

		case 1:
			MENUA_eskolaAukeratuAdministratzailea(eskola, erabiltzailea);
			break;

		case 2:
			MENUA_aukerakIrakaslea(eskola, erabiltzailea);
			break;

		case 3:
			MENUA_aukerakIkaslea(eskola, erabiltzailea);
			break;

		default:
			break;
		}
		system("cls");

	} while (aukera != 0);

	return aukera;
}



void MENUA_aukerakAdministratzailea(ESKOLA eskola, int erabiltzailea){
	int aukera = 0;

	do{
		
		aukera = MENUA_aukerakAdministratzaileaBistaratu(eskola, erabiltzailea);
		switch (aukera){

		case 1: DATUENMODIFIKAZIOA_ikasleBatSartu(eskola, erabiltzailea);
			break;

		case 2: DATUENMODIFIKAZIOA_eskolakoDatuakModifikatu(eskola, erabiltzailea);
			break;

		case 3: DATUENMODIFIKAZIOA_gelaFisikoaAsignatu(eskola, erabiltzailea);
			break;

		case 4: DATUENMODIFIKAZIOA_irakasleakAsignatu(eskola, erabiltzailea);
			break;

		case 5: DATUENMODIFIKAZIOA_tutoreaAsignatu(eskola, erabiltzailea);
			break;

		case 6: DATUENMODIFIKAZIOA_ikasgaiakSartuAdministrazioa(eskola, erabiltzailea);
			break;

		case 7: DATUENMODIFIKAZIOA_eskolakoMailakJarri(eskola, erabiltzailea);
			break;
		}
		system("cls");

	} while (aukera != 0);

}

void MENUA_aukerakIrakaslea(ESKOLA eskola, int erabiltzailea){
	int aukera = 0;
	
	do{

		aukera = MENUA_aukerakIrakasleaBistaratu(eskola, erabiltzailea);

		switch (aukera){
		case 1: DATUENMODIFIKAZIOA_notakSartu(eskola, erabiltzailea);
			break;

		case 2: BISTARATU_notakBistaratuIrakaslearentzat(eskola, erabiltzailea);
			break;

		case 3: BISTARATU_ikaslearenBatezbestekoa(eskola, erabiltzailea);
			break;

		case 4: BISTARATU_taldekoIkasgaikoBatezbestekoa(eskola, erabiltzailea);
			break;

		case 5: BISTARATU_taldekoBatezbestekoa(eskola, erabiltzailea);
			break;

		case 6: BISTARATU_taldekoBatezbestekoHoberena(eskola, erabiltzailea);
			break;

		case 7: BISTARATU_taldekoIkasleakBatezbestekoarenArabera(eskola, erabiltzailea);
			break;

		default:
			break;
		}
		system("cls");

	} while (aukera != 0);

}

void MENUA_aukerakIkaslea(ESKOLA eskola, int erabiltzailea){
	int aukera = 0;

	do{

		aukera = MENUA_aukerakIkasleaBistaratu(eskola, erabiltzailea);

		switch (aukera){

		case 1: BISTARATU_notakBistaratuIkaslearentzat(eskola, erabiltzailea);
			break;

		case 2: BISTARATU_ikaslearenBatezbestekoa(eskola, erabiltzailea);
			break;
		}
		system("cls");

	} while (aukera != 0);

}





int MENUA_erabiltzaileaAukeratuBistaratu(ESKOLA eskola){
	//aldagaiak
	int erabiltzailea = 0;
	int pasahitza = 0;
	int aukera;
	FILE *fitxeroa;
	int i = 0;
	int egokia = 0;

	//programa
	printf("Erabiltzailea: ");
	scanf("%i", &erabiltzailea);
	printf("Pasahitza: ");
	scanf("%i", &pasahitza);
	system("cls");
	
	aukera = erabiltzailea / 10000000;


	switch (aukera){

	case 1: //ikasleak
		IKASLEA ikasleak[eskola.ikasleak];
		eskola.ikasleak = 1;

		if ((fitxeroa = fopen("ikasleak.dat", "rb")) == NULL){
			/* control del error de apertura */
			printf("Ezin izan da ikasleen datu basea ireki\n");
		}
		else{
			for (i = 0; i < eskola.ikasleak; i++){
				fread(&ikasleak[i], sizeof (IKASLEA), 1, fitxeroa);
			}
			for (i = 0; i < eskola.ikasleak; i++){
				if ((ikasleak[i].erabiltzailea == erabiltzailea) && (ikasleak[i].pasahitza == pasahitza)){
					printf("Erabiltzailea eta pasahitza zuzenak dira\n");
					egokia = 1;
				}
			}
			if (egokia == 0){
				printf("Erabiltzailea edo pasahitza desegokia da\n");
				erabiltzailea = 0;
				pasahitza = 0;
			}

		}

		break;

	case 2: //irakasleak
		IRAKASLEA irakasleak[eskola.irakasleak];

		if ((fitxeroa = fopen("irakasleak.dat", "rb")) == NULL){
			/* control del error de apertura */
			printf("Ezin izan da irakaslearen datu basea ireki\n");
		}
		else{
			for (i = 0; i < eskola.ikasleak; i++){
				fread(&irakasleak[i], sizeof (IRAKASLEA), 1, fitxeroa);
			}
			for (i = 0; i < eskola.ikasleak; i++){
				if ((irakasleak[i].erabiltzailea == erabiltzailea) && (irakasleak[i].pasahitza == pasahitza)){
					printf("Erabiltzailea eta pasahitza zuzenak dira\n");
					egokia = 1;
				}
			}
			if (egokia == 0){
				printf("Erabiltzailea edo pasahitza desegokia da\n");
				erabiltzailea = 0;
				pasahitza = 0;
			}

		}


		break;

	case 3: //administratzaileak
		
		ADMINISTRATZAILEA administratzaileak[eskola.administratzaileak];

		if ((fitxeroa = fopen("administratzaileak.dat", "rb")) == NULL){
			/* control del error de apertura */
			printf("Ezin izan da administratzaileen datu basea ireki\n");
		}
		else{
			for (i = 0; i < eskola.administratzaileak; i++){
				fread(&administratzaileak[i], sizeof (ADMINISTRATZAILEA), 1, fitxeroa);
			}
			for (i = 0; i < eskola.ikasleak; i++){
				if ((administratzaileak[i].erabiltzailea == erabiltzailea) && (administratzaileak[i].pasahitza == pasahitza)){
					printf("Erabiltzailea eta pasahitza zuzenak dira\n");
					egokia = 1;
				}
			}
			if (egokia == 0){
				printf("Erabiltzailea edo pasahitza desegokia da\n");
				erabiltzailea = 0;
				pasahitza = 0;
			}

			break;

		}

		return erabiltzailea;
	}
}

int MENUA_aukerakAdministratzaileaBistaratu(){
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

int MENUA_aukerakIrakasleaBistaratu(){
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

int MENUA_aukerakIkasleaBistaratu(){
	int aukera = 0;

	printf("1. Notak ikusi\n");
	printf("2. Batezbestekoa ikusi\n");
	scanf("%i", &aukera);
	system("cls");

	return aukera;
}