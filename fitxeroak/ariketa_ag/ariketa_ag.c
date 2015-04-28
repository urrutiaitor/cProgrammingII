#include "ariketa_ag.h"

int main(){
	//aldagaiak
	FILE* fitxeroa = 0;
	int kantitatea = 0;
	char ubikazioa[UBIKAZIOA_MAX];
	int zenbakiak[MAX];

	//programa
	fflush(stdin);
	hasieraTextua();
	ubikazioaLortu(ubikazioa);
	kantitatea = zenbakiakJaso(zenbakiak);
	zenbakiakFitxeroanGorde(kantitatea, ubikazioa, zenbakiak[MAX]);

	//bukaera
	printf("Sakatu ENTER bukatzeko");
	fflush(stdin);
	getchar();
	return 0;
}

void ubikazioaLortu(char ubikazioa[UBIKAZIOA_MAX]){
	//aldagaiak

	//programa
	printf("Zein da zuk nahi duzun fitxeroaren ubikazioa?\n");
	gets_s(ubikazioa, UBIKAZIOA_MAX);
	fflush(stdin);

	//return
	return 0;
}

int zenbakiakJaso(int zenbakiak[MAX]){
	//aldagaiak
	int i = 0;
	char aux=' ';

	//programa
	printf("Joan nahi duzun zenbaki osoak sartzen\n");
	printf("Zenbakiak idazten amaitutakoan ENTER sakatu\n");

	while ((gets(zenbakiak[i]) != '\0') && (i < MAX)){

		i++;

	}
	
	return i - 1;
}

void zenbakiakFitxeroanGorde(int kantitatea, char ubikazioa[UBIKAZIOA_MAX], int zenbakiak[MAX]){
	//aldagaiak
	FILE* fitxeroa;
	int i = 0;

	//programa
	fitxeroa = fopen(ubikazioa, "w");

	for (i = 0; i < kantitatea; i++){
		fprintf(fitxeroa, "%i", zenbakiak[i]);
		fprintf(fitxeroa, "%c", "\n");
	}
}

void hasieraTextua(){
	printf("Programa honek teklatutik sartutako zenbaki osoen zekuentzia bat fitxero batean sartuko du:\n");
	printf("\n");
}
