#include "ariketa_ac.h"

int main(){
	//aldagaiak
	FILE* fitxeroa = 0;
	int tamaina = 0;
	char ubikazioa[UBIKAZIOA_MAX];

	//programa
	fflush(stdin);
	hasieraTextua();
	ubikazioaLortu(ubikazioa);
	
	textuaPrintatu(fitxeroa, ubikazioa);

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

void textuaPrintatu(FILE* fitxeroa, char ubikazioa[UBIKAZIOA_MAX]){
	//aldagaiak
	int i = 0;
	int egokia = 0;

	//programa
	fitxeroa = fopen(ubikazioa, "w");
	for (i = 'a'; i < 'a'+ABECEDARIO_KANTITATEA; i++){
		egokia = fputc(i, fitxeroa);
	}
	egokia = fputc('\n', fitxeroa);
	for (i = 'A'; i < 'A' + ABECEDARIO_KANTITATEA; i++){
		egokia = fputc(i, fitxeroa);
	}

	fitxeroa = fclose(ubikazioa);

	//return
	return 0;
}

void hasieraTextua(){
	printf("Programa honek fitxeroaren barruan alfabetoa bi aldiz jarriko dut (lehena letra xehez eta bigarrena larriz):\n");
	printf("\n");
}