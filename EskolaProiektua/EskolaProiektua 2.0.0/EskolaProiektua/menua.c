#include "datuEgiturak.h"
#include "menua.h"



int MENUA_menukoAukerak(ESKOLA *ptr_eskola, USUARIOA **ptr_ptr_usuarioa, int *ptr_usuarioa, int *ptr_pasahitza){
	//aldagaiak
	USUARIOA *ptr_aux;
	int egoera = 0;
	int aukera = 0;

	//programa

	ptr_aux = *ptr_ptr_usuarioa;
	

	while (ptr_aux != NULL){
		if (ptr_aux->erabiltzailea == *ptr_usuarioa){
			if (ptr_aux->pasahitza == *ptr_pasahitza){
				printf("Kargatzen...");
				Sleep(1400);
				egoera = 1;
				break;
			}
			else{
				egoera = 0;
				break;
			}
		}
		else{
			ptr_aux = ptr_aux->urrengo_ptr;
		}
	}
	if (egoera == 1){
		switch (ptr_aux->mota){
		case 1:
			MENUA_aukerakAdministratzailea(ptr_eskola, ptr_ptr_usuarioa, ptr_usuarioa);
			break;
		case 2:
			MENUA_aukerakIrakaslea(ptr_eskola, ptr_ptr_usuarioa, ptr_usuarioa);
			break;
		case 3:
			MENUA_aukerakIkaslea(ptr_eskola, ptr_aux, ptr_usuarioa);
			break;
		}
	}
	if (egoera == 0){
		printf("Zure erabiltzaile kontua edo pasahitza ez da zuzena\n");
		printf("1. Saiatu berriz\n");
		printf("0. Irten\n");
		scanf("%i", &aukera);
	}
	system("cls");
	return aukera;
}



void MENUA_aukerakAdministratzailea(ESKOLA *ptr_eskola, USUARIOA **ptr_ptr_usuarioa, int *ptr_usuarioa){
	int aukera = 0;

	do{

		aukera = MENUA_aukerakAdministratzaileaBistaratu();
		switch (aukera){

		case 1: DATUENMODIFIKAZIOA_eskolakoDatuakModifikatu(ptr_eskola);
			break;

		case 2: DATUENMODIFIKAZIOA_ikasgaiakSartuAdministrazioa(ptr_eskola);
			break;

		case 3: DATUENMODIFIKAZIOA_usuarioBatSartu(ptr_eskola, ptr_ptr_usuarioa);
			break;

		case 4: DATUENMODIFIKAZIOA_usuarioarenDatuakSartu(ptr_usuarioa);
			break;

		case 5: DATUENMODIFIKAZIOA_irakasleakAsignatu(ptr_eskola);
			break;

		case 6:DATUENMODIFIKAZIOA_ikaslearenIkasgaiakSartu(ptr_usuarioa);
			break;

		}
		system("cls");

	} while (aukera != 0);

}

void MENUA_aukerakIrakaslea(ESKOLA *ptr_eskola, USUARIOA **ptr_ptr_usuarioa, int *ptr_usuarioa){
	int aukera = 0;
	
	do{

		aukera = MENUA_aukerakIrakasleaBistaratu();

		switch (aukera){
		case 1: DATUENMODIFIKAZIOA_notakSartu(ptr_ptr_usuarioa, ptr_usuarioa);
			break;

		case 2: BISTARATU_ikaslearenBatezbestekoa(ptr_usuarioa);
			break;

		case 3: BISTARATU_taldekoIkasgaikoBatezbestekoa(ptr_eskola, ptr_ptr_usuarioa);
			break;

		case 4:BISTARATU_taldekoBatezbestekoa(ptr_eskola, ptr_ptr_usuarioa);
			break;

		default:
			break;
		}
		system("cls");

	} while (aukera != 0);

}

void MENUA_aukerakIkaslea(ESKOLA *ptr_eskola, USUARIOA *ptr_ikaslea, int *ptr_usuarioa){
	int aukera = 0;

	do{

		aukera = MENUA_aukerakIkasleaBistaratu();

		switch (aukera){

		case 1: BISTARATU_notakBistaratuIkaslearentzat(ptr_eskola, ptr_usuarioa);
			break;

		case 2: BISTARATU_ikaslearenBatezbestekoa(ptr_usuarioa);
			break;

		case 3:BISTARATU_taldekoIkasgaikoBatezbestekoa(ptr_eskola, ptr_usuarioa);
			break;

		case 4:BISTARATU_taldekoBatezbestekoa(ptr_eskola, ptr_usuarioa);
			break;

		}
		system("cls");

	} while (aukera != 0);

}



int MENUA_aukerakAdministratzaileaBistaratu(){
	int aukera = 0;

	printf("1. Usuario berri bat sartu\n");
	printf("2. Eskolako datuak modifikatu\n");
	printf("3. Ikasgai posibleak sartu\n");
	printf("4. Irakasleak asignatu\n");
	printf("5. Gela fisikoa asignatu\n");
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