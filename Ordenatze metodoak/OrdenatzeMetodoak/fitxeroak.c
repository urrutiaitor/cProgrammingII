#include "main.h"

#define MAX 100000
#define MIN -100000

void zenbakiakIrakurri30000(int zenbakiak[]){
	//aldagaiak
	FILE* fitxeroa;
	int i = 0;
	int zenbakia = 0;

	//programa
	if ((fitxeroa = fopen("zenbakiAleatorioak30000.dat", "rb")) != NULL){
		for (i = 0; i < 30000; i++){
			fscanf(fitxeroa, "%i", &zenbakiak[i]);
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
			fscanf(fitxeroa, "%i", &zenbakiak[i]);
		}
	}
	else{
		printf("\n");
		printf("'zenbakiAleatorioak50000.dat' fitxeroa ezin da zabaldu.\n");
	}

	//bukaera
	return 0;

}