#include "main.h"
/*MAINEKO FUNTZIOAK BIRPASATU
USUARIOARENA EGIN
MENUKO FUNTZIOAK EGIN
*/


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
			if (!eskolaBilatu()){
				printf("Error\n");
			}
			break;
		case 2:
			if (!eskolaSortu()){
				printf("Error\n");
			}
			break;
		}
	}

	//bukaera
	return 0;
}

int eskolaSortu(){
	//aldagaiak
	FILE *fitxeroa;
	ESKOLA *burua_ptr;
	ESKOLA *aux_ptr;
	ESKOLA *aurrekoa_ptr;

	//programa
	if ((fitxeroa = fopen("eskolak.dat", "rb")) == NULL){
		printf("Eskolen datu basea ezin izan da ireki\n");
	}
	else{
		if (fread((burua_ptr = malloc(sizeof(ESKOLA))), sizeof (ESKOLA), 1, fitxeroa)!=NULL){
			(burua_ptr)->urrengo_ptr = NULL;
			aux_ptr = burua_ptr;
			while (fread((aux_ptr->urrengo_ptr = malloc(sizeof(ESKOLA))), sizeof (ESKOLA), 1, fitxeroa) != NULL){
				aurrekoa_ptr = aux_ptr;
				aux_ptr = aux_ptr->urrengo_ptr;
				free(aurrekoa_ptr);
			}
		}

		aux_ptr->urrengo_ptr = NULL;
		DATUENMODIFIKAZIOA_eskolakoDatuakSartu(aux_ptr);
		if (!fclose(fitxeroa)){
			printf("Errore bat egon da eskolen datu basea ixterakoan\n");
		}
		aux_ptr = burua_ptr;

		if ((fitxeroa = fopen("eskolak.dat", "wb")) == NULL){
			printf("Eskolen datu basea ezin izan da ireki, gero gorde ahal izateko\n");
		}
		else{
			while (fwrite((aux_ptr->urrengo_ptr = malloc(sizeof(ESKOLA))), sizeof (ESKOLA), 1, fitxeroa) != NULL){

				aux_ptr = aux_ptr->urrengo_ptr;
			}
			if (!fclose(fitxeroa)){
				printf("Errore bat egon da eskola berria gordetzerakoan\n");
			}
		}
		
	}

	//bukaera
	return 1;
}

int eskolaBilatu(){
	//aldagaiak
	FILE *fitxeroa;
	ESKOLA **eskola_ptr_ptr;
	ESKOLA *aurrekoa_ptr;
	ESKOLA *aux_ptr;
	ESKOLA *burua_ptr;
	int kont = 0, aukeratuta = 0;

	//programa
	if ((fitxeroa = fopen("eskolak.dat", "rb")) == NULL){
		printf("Eskolen datu basea ezin izan da ireki\n");
	}
	else{
		if (fread((burua_ptr = malloc(sizeof(ESKOLA))), sizeof (ESKOLA), 1, fitxeroa) != NULL){
			(burua_ptr)->urrengo_ptr = NULL;
			aux_ptr = burua_ptr;
			printf("Aukeratu eskola:\n");
			printf("%i. %s", (kont++) + 1, aux_ptr->izena);
			while (fread((aux_ptr->urrengo_ptr = malloc(sizeof(ESKOLA))), sizeof (ESKOLA), 1, fitxeroa) != NULL){
				aurrekoa_ptr = aux_ptr;
				printf("%i. %s", (kont++) + 1, aux_ptr->izena);
				aux_ptr = aux_ptr->urrengo_ptr;
				free(aurrekoa_ptr);
			}
		}
		scanf("%i", &aukeratuta);
		aukeratuta--;
		eskolaAukeratu(eskola_ptr_ptr, aukeratuta);
		aux_ptr->urrengo_ptr = NULL;
		if (!fclose(fitxeroa)){
			printf("Errore bat egon da eskolen datu basea irakurtzerakoan\n");
		}
		aux_ptr = burua_ptr;
	}
	//bukaera
	return 1;
}

int eskolaAukeratu(ESKOLA **eskola_ptr_ptr,int aukeratuta){
	//aldagaiak
	int kont = 0;
	int ondo = 0;
	ESKOLA *aux_ptr;
	ESKOLA *aukeratutakoEskola_ptr;
	//programa
	aux_ptr = *eskola_ptr_ptr;
	while ((aukeratuta != kont) && (aux_ptr!= NULL)){
		aux_ptr = aux_ptr->urrengo_ptr;
		kont++;
	}
	if (aukeratuta == kont){
		aukeratutakoEskola_ptr = aux_ptr;
	}
	aux_ptr = *eskola_ptr_ptr;
	while (aux_ptr != NULL){
		if (aux_ptr != aukeratutakoEskola_ptr){
			free(aux_ptr);
		}
		ondo = 1;
		*eskola_ptr_ptr = aukeratutakoEskola_ptr;
	}
	//bukaera
	return ondo;
}