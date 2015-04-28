#include "ariketa_ad.h"

int main(){
	//aldagaiak
	int zenbakiak[MAX];
	char ubikazioa[UBIKAZIOA_MAX];
	int kantitatea = 0;

	//programa
	fflush(stdin);
	hasieraTextua();
	ubikazioaLortu(ubikazioa);
	kantitatea = zenbakiakJaso(ubikazioa, zenbakiak);
	zenbakiakOrdenatu(zenbakiak, kantitatea);
	zenbakiakIdatzi(ubikazioa, zenbakiak, kantitatea);
	

	//bukaera
	printf("Sakatu ENTER bukatzeko");
	fflush(stdin);
	getchar();
	return 0;
}

void ubikazioaLortu(char ubikazioa[UBIKAZIOA_MAX]){
	//aldagaiak

	//programa
	printf("Zein da zuk nahi duzun fitxeroaren ubikazioa/izena?\n");
	gets_s(ubikazioa, UBIKAZIOA_MAX);
	fflush(stdin);

	//return
	return 0;
}

void zenbakiakOrdenatu(int zenbakiak[MAX], int kantitatea){
	//aldagaiak
	int segi = 0;
	int i = 0, t = 0;
	int aux = 0;

	//programa
	
	for (i = 0; i < kantitatea; i++){
		for (t = 0; t < kantitatea; t++){
			if (zenbakiak[t]>zenbakiak[i]){
				aux = zenbakiak[i];
				zenbakiak[i] = zenbakiak[t];
				zenbakiak[t] = aux;
			}
		}
	}
}

int zenbakiakJaso(char ubikazioa[UBIKAZIOA_MAX], int zenbakiak[MAX]){
	//aldagaiak
	int i = 0;
	int egokia = 0;
	int aux = 0;
	FILE* fitxeroa;
	int kantitatea = 0;

	//programa
	fitxeroa = fopen(ubikazioa, "r");
	while ((!feof(fitxeroa))&&(i<MAX)){
		fscanf(fitxeroa, "%i", &zenbakiak[i]);
		i++;
	}
	kantitatea = i - 1;
	fclose(fitxeroa);
	

	printf("\nHauek dira zenbakiak ordenatu aurretik:\n");
	for (i = 0; i < kantitatea; i++){
		printf("%i\n", zenbakiak[i]);
	}

	//return
	return kantitatea;
}

void zenbakiakIdatzi(char ubikazioa[UBIKAZIOA_MAX], int zenbakiak[MAX],int kantitatea){
	//aldagaiak
	int i = 0;
	int egokia = 0;
	FILE* fitxeroa;

	//programa
	printf("\nHauek dira zenbakiak ordenatuta:\n");
	fitxeroa = fopen(ubikazioa, "w");
	for (i = 0; i < kantitatea; i++){
		fprintf(fitxeroa, "%i\n",zenbakiak[i]);
		printf("%i\n", zenbakiak[i]);
	}
	fclose(fitxeroa);

	printf("Zenbaki berriak fitxeroan gordeta gelditu dira\n");
	//return
	return 0;
}

void hasieraTextua(){
	printf("Programa honek fitxeroaren barruan dauden zenbakiak ordenatuko ditu (txikitik handira):\n");
	printf("\n");
}