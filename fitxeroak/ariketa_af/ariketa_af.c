#include "ariketa_af.h"

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
	printf("Zein da zuk nahi duzun fitxeroaren ubikazioa?\n");
	gets_s(ubikazioa, UBIKAZIOA_MAX);
	fflush(stdin);

	//return
	return 0;
}

void tamainaKalkulatu(FILE* fitxeroa, char ubikazioa[UBIKAZIOA_MAX]){
	//aldagaiak
	int tamaina = 0;
	

	//programa
	if ((fitxeroa = fopen(ubikazioa, "rb")) != NULL){
		fitxeroa = fopen(ubikazioa, "rb");
		if (fseek(fitxeroa, 0, SEEK_END)){
			printf("Error al colocarse al final del archivo.\n");
		}
		else{
			tamaina = ftell(fitxeroa);
			fclose(fitxeroa);
		}
	}
	else{
		printf("\n");
		printf("'%s' fitxeroa ezin da zabaldu.\n", ubikazioa);
	}

	tamainaPrintatu(tamaina);

	//return
	return 0;
}

void tamainaPrintatu(int tamaina){
	//aldagaiak

	//programa
	printf("Zuk aukeratutako fitxategiak %i byte ditu\n", tamaina);
}

void hasieraTextua(){
	printf("Programa honek fitxeroen tamaina kalkulatzen du:\n");
	printf("\n");
}
