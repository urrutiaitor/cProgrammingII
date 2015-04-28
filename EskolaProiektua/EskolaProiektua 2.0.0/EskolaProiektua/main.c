#include "datuEgiturak.h"
#include "main.h"


int main(){
	//aldagaiak
	int erabiltzailea = 0;
	int emaitza = 0;
	int aukera = 1;

	ESKOLA eskola;
	ESKOLA *ptr_eskola;

	USUARIOA *ptr_usuarioa;
	USUARIOA **ptr_ptr_usuarioa;

	int usuarioa;
	int pasahitza;

	//programa
	system("color B");

	ptr_eskola = &eskola;
	ptr_usuarioa = NULL;
	ptr_ptr_usuarioa = &ptr_usuarioa;

	if (!hasieraketa(ptr_eskola,ptr_ptr_usuarioa)){
		printf("E\n");
	}

	ptr_eskola = &eskola;
	ptr_ptr_usuarioa = &ptr_usuarioa;

	while (aukera != 0){
		if (datuBaseaIrakurri(ptr_eskola, ptr_ptr_usuarioa)){
			printf("Usuarioa: ");
			scanf("%i", &usuarioa);
			fflush(stdin);
			printf("Pasahitza: ");
			scanf("%i", &pasahitza);
			fflush(stdin);
		}
		if ((usuarioa == 0) && (pasahitza == 0)){
			printf("Kargatzen...");
			Sleep(1400);
			system("cls");
			DATUENMODIFIKAZIOA_usuarioBatSartu(ptr_eskola, ptr_ptr_usuarioa);
		}
		if ((usuarioa != 0) || (pasahitza != 0)){
			printf("Kargatzen...");
			Sleep(1400);
			system("cls");
			aukera = MENUA_menukoAukerak(ptr_eskola, ptr_ptr_usuarioa, &usuarioa, &pasahitza);
		}
		
	}

	//bukaera
	return 0;
}

int hasieraketa(ESKOLA *ptr_eskola, USUARIOA **ptr_ptr_usuarioa){
	int i = 0;
	USUARIOA *ptr_aux;

	ptr_aux = *ptr_ptr_usuarioa;
	while (ptr_aux != NULL){
		for (i = 0; i < 100; i++){
			ptr_aux->ikasgaiak[i].id = NULL;
		}
	}

	for (i = 0; i < 100; i++){
		ptr_eskola->ikasgaiak[i].id = NULL;
	}

	return 1;
}