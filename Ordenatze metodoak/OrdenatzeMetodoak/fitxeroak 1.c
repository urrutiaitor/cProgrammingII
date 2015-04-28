#include "main.h"

#define MAX 100000
#define MIN -100000

void zenbakiakIrakurri30000(int zenbakiak[]){
	//aldagaiak
	FILE* fitxeroa;
	int i = 0;

	//programa
	if ((fitxeroa = fopen("zenbakiAleatorioak30000.dat", "rb")) != NULL){
		for (i = 0; i < 30000; i++){
			fread(&zenbakiak[i], sizeof (int), 1, fitxeroa);
		}
	}
	else{
		printf("\n");
		printf("'zenbakiAleatorioak30000.dat' fitxeroa ezin da zabaldu.\n");
	}

	//bukaera
	return 0;

}

void zenbakiakIrakurri50000(int zenbakiak[]){
	//aldagaiak
	FILE* fitxeroa;
	int i = 0;

	//programa
	if ((fitxeroa = fopen("zenbakiAleatorioak50000.dat", "rb")) != NULL){
		for (i = 0; i < 50000; i++){
			fread(&zenbakiak[i], sizeof (int), 1, fitxeroa);
		}
	}
	else{
		printf("\n");
		printf("'zenbakiAleatorioak50000.dat' fitxeroa ezin da zabaldu.\n");
	}

	//bukaera
	return 0;

}

void FITXEROAK_fitxeroaSortu30000(){
	//aldagaiak
	FILE* fitxeroa;
	int i = 0;
	int zenbakia = 0;

	//programa
	if ((fitxeroa = fopen("zenbakiAleatorioak30000.dat", "wb")) != NULL){
		for (i = 0; i < 30000; i++){
			zenbakia = rand() % (MAX - MIN + 1) + MIN;
			fwrite(&zenbakia, sizeof (int), 1, fitxeroa);
			if (i % 100 == 0){
				printf("%i/30000", i);
				system("cls");
			}
		}
	}
	else{
		printf("\n");
		printf("Fitxeroa ezin da sortu.\n");
	}

	//return
	return 0;
}

void FITXEROAK_fitxeroaSortu50000(){
	//aldagaiak
	FILE* fitxeroa;
	int i = 0;
	int zenbakia = 0;

	//programa
	if ((fitxeroa = fopen("zenbakiAleatorioak.dat", "wb")) != NULL){
		for (i = 0; i < 5000000000000; i++){
			zenbakia = rand() % (MAX - MIN + 1) + MIN;
			fwrite(&zenbakia, sizeof (int), 1, fitxeroa);
			if (i % 100000000000 == 0){
				printf("%i", i);
				system("cls");
			}
		}
	}
	else{
		printf("\n");
		printf("Fitxeroa ezin da sortu.\n");
	}

	//return
	return 0;
}