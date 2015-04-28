#include "main.h"
#include "menua.h"

int main(){
	//aldagaiak
	int erabiltzailea = 0;
	int emaitza = 0;
	int aukera = 1;

	//programa
	system("color B");
	while (aukera != 0){
		printf("1. Eskola baten sartu\n");
		printf("2. Eskola bat sortu\n");
		printf("0. Irten\n");
		switch (aukera){
		case 1:

			break;
		case 2:

			break;
		}
	}

	//bukaera
	return 0;
}

int eskolaSortu(ESKOLA **eskola_ptr_ptr){
	//aldagaiak
	ESKOLA eskola;
	FILE *fitxeroa;

	//programa
	if ((fitxeroa = fopen("eskolak.dat", "rb")) == NULL){
		printf("Eskolen datu basea ezin izan da ireki\n");
	}
	else{
		while (!fread((eskola_ptr = malloc(sizeof(ESKOLA))), sizeof (ESKOLA), 1, fitxeroa)){
			
		}
	}

	//bukaera
	return 1;
}

int eskolaBilatu(ESKOLA **eskola_ptr_ptr){
	//aldagaiak
	FILE *fitxeroa;
	ESKOLA *eskola_ptr = NULL;
	ESKOLA *aux_ptr = NULL;

	//programa
	if ((fitxeroa = fopen("eskolak.dat", "rb")) == NULL){
		printf("Eskolen datu basea ezin izan da ireki\n");
	}
	else{
		while (!fread((eskola_ptr = malloc(sizeof(ESKOLA))), sizeof (ESKOLA), 1, fitxeroa)){
			if (aux_ptr != NULL){
				aux_ptr->urrengo_ptr = eskola_ptr;
			}
			else{
				*eskola_ptr_ptr = eskola_ptr;
			}
			aux_ptr = eskola_ptr;
			aux_ptr->urrengo_ptr = NULL;
		}
	}

	//bukaera
	return 1;
}