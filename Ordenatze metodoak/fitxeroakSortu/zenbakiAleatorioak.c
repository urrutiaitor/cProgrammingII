#include <stdio.h>
#include <math.h>
#include <Windows.h>
#include <stdlib.h>

 
#define MAX 10000
#define MIN -10000

void zenbakiAleatorioak30000();
void zenbakiAleatorioak50000();

int main(){
	//aldagaiak
	int aukera = 0;

	//programa
	printf("Zer nahi duzu egin?\n");
	printf("1. 30 000 zenbaki aleatorioko fitxeroa sortu\n");
	printf("2. 50 000 zenbaki aleatorioko fitxeroa sortu\n");
	scanf("%i", &aukera);

	switch (aukera){
	case 1:
		zenbakiAleatorioak30000();
		break;
	case 2:
		zenbakiAleatorioak50000();
		break;
	}

	//bukaera
	printf("Sakatu ENTER programa bukatzeko\n");
	fflush(stdin);
	getchar();
	return 0;
}

void zenbakiAleatorioak30000(){
	//aldagaiak
	FILE* fitxeroa;
	int i = 0;
	int zenbakia = 0;

	//programa
	if ((fitxeroa = fopen("zenbakiAleatorioak30000.dat","wb")) != NULL){
		for (i = 0; i < 30000; i++){
			zenbakia = rand() % (MAX - MIN + 1) + MIN;
			fprintf(fitxeroa, "%i\t", zenbakia);
			
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

void zenbakiAleatorioak50000(){
	//aldagaiak
	FILE* fitxeroa;
	int i = 0;
	int zenbakia = 0;

	//programa
	if ((fitxeroa = fopen("zenbakiAleatorioak50000.dat", "wb")) != NULL){
		for (i = 0; i < 50000; i++){
			zenbakia = rand() % (MAX - MIN + 1) + MIN;
			fprintf(fitxeroa, "%i\t", zenbakia);
			if (i % 100 == 0){
				printf("%i/50000", i);
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