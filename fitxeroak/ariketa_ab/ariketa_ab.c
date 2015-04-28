#include "ariketa_ab.h"

int main(){
	//aldagaiak
	FILE* fitxeroa = 0;
	int tamaina = 0;
	char ubikazioa[UBIKAZIOA_MAX];

	//programa
	fflush(stdin);
	hasieraTextua();
	ubikazioaLortu(ubikazioa);
	
	tamainaKalkulatu(fitxeroa, ubikazioa);

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

void tamainaKalkulatu(FILE* fitxeroa, char ubikazioa[UBIKAZIOA_MAX]){
	//aldagaiak
	int kantitatea = 0;
	int  c = 0;

	//programa
	fitxeroa = fopen(ubikazioa, "r+");
	while ((c = fgetc(fitxeroa)) != EOF){
		if (c == 'a'){
			kantitatea++;
		}	
	}
	
	tamainaPrintatu(kantitatea);

	//return
	return 0;
}

void tamainaPrintatu(int kantitatea){
	//aldagaiak

	//programa
	printf("Zuk aukeratutako fitxategiak %i 'a' ditu\n", kantitatea);
}

void hasieraTextua(){
	printf("Programa honek fitxeroaren barruan zenbat 'a' dauden kalkulatzen du:\n");
	printf("\n");
}