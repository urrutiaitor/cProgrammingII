#include "main.h"
#include "menua.h"

int main(){
	//aldagaiak
	ESKOLA **eskola_ptr_ptr;
	ESKOLA **aukeratutakoEskola_ptr_ptr;
	ESKOLA *eskola_ptr;
	int aukera = 1;

	//programa
	eskola_ptr_ptr = &eskola_ptr;

	system("color B");
	
	while (aukera != 0){
		printf("1. Eskola bat sortu\n");
		printf("2. Eskolak datu basetik kargatu\n");
		printf("3. Eskola bat aukeratu\n");
		printf("0. Irten\n");
		switch (aukera){
		case 1:
			if (!eskolaSortu(eskola_ptr_ptr)){
				printf("Fault\n");
			}
			break;
		case 2:
			if (!eskolaBilatu(eskola_ptr_ptr)){
				printf("Fault\n");
			}
			break;
		case 3:
			if (!eskolaAukeratu(eskola_ptr_ptr, aukeratutakoEskola_ptr_ptr)){
				printf("Fault\n");
			}
			break;
		}
	}

	//bukaera
	return 0;
}

int eskolaSortu(ESKOLA **eskola_ptr_ptr){
	//aldagaiak
	ESKOLA eskola;
	ESKOLA *eskola_ptr;
	FILE *fitxeroa;

	//programa
	eskola_ptr = &eskola;
	DATUENMODIFIKAZIOA_eskolakoDatuakSartu(eskola_ptr);

	if ((fitxeroa = fopen("eskolak.dat", "ab")) == NULL){
		printf("Eskolen datu basea ezin izan da ireki\n");
	}

	else{
		fwrite(eskola_ptr, sizeof (ESKOLA), 1, fitxeroa);
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

int eskolaAukeratu(ESKOLA **eskola_ptr_ptr, ESKOLA **aukeratutakoEskola_ptr_ptr){
	//aldagaiak
	ESKOLA *aux_ptr;
	int kont = 0;
	int aukera = 0;
	int i = 0;

	//programa
	if (*eskola_ptr_ptr == NULL){
		printf("Ez dago eskolarik\n");
	}
	else{
		aux_ptr = *eskola_ptr_ptr;
		*aukeratutakoEskola_ptr_ptr = *eskola_ptr_ptr;

		printf("Aukeratzeko dauden eskolak hauek dira:\n");
		while (aux_ptr->urrengo_ptr != NULL){
			printf("%i. %s\n", kont + 1, aux_ptr->izena);
			kont++;
		}
		scanf("%i", &aukera);
		for (i = 0; i < kont; i++){
			(*aukeratutakoEskola_ptr_ptr) = (*aukeratutakoEskola_ptr_ptr)->urrengo_ptr;
		}
	}

	//bukaera
	return 1;
}

void menu(ESKOLA **eskola_ptr_ptr){

}