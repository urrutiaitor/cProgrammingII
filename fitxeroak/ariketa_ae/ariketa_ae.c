#include "ariketa_ae.h"

int main(){
	//aldagaiak
	int tamaina = 0;
	char ubikazioa[UBIKAZIOA_MAX];

	//programa
	fflush(stdin);
	hasieraTextua();
	ubikazioaLortu(ubikazioa);
	tamaina=tamainaMaximoaLortu(tamaina);
	zatienBanaketaEgin(tamaina, ubikazioa);

	//bukaera
	printf("Sakatu ENTER bukatzeko");
	fflush(stdin);
	getchar();
	return 0;
}

void ubikazioaLortu(char ubikazioa[UBIKAZIOA_MAX]){
	//aldagaiak

	//programa
	printf("Zein da banatu nahi duzun fitxeroaren ubikazioa?\n");
	gets_s(ubikazioa, UBIKAZIOA_MAX);
	fflush(stdin);

	//return
	return 0;
}

int tamainaMaximoaLortu(int tamaina){
	//aldagaiak

	//programa
	printf("Zein izango da fitxategian tamaina maximoa (tamaina Byte-etan emango da):\n");
	scanf("%i", &tamaina);

	//return
	return tamaina;

}
void zatienBanaketaEgin(int tamaina, char ubikazioa[UBIKAZIOA_MAX]){
	//aldagaiak
	FILE* sarreraFitxeroa;
	FILE* irteeraFitxeroak[FITXERO_MAX];
	char aux = ' ';
	int i = 0;
	int t = 0;

	//programa
	sarreraFitxeroa = fopen(ubikazioa, "r");
	irteeraFitxeroak[t] = fopen("izena.txt", "w");
	while (!feof(sarreraFitxeroa)){
		fscanf(sarreraFitxeroa, "%c", &aux);
		if (i == tamaina){
			fclose(irteeraFitxeroak[t]);
			t++;
			i = 0;
			irteeraFitxeroak[t]=fopen("izena.txt" ,"w");
		}
		fputc(aux, irteeraFitxeroak[t]);
		i++;
	}
	fclose(irteeraFitxeroak[t]);

}

void hasieraTextua(){
	printf("Programa honek fitxategi handi bat fitxategi txikiagoetan banatzen du:\n");
	printf("\n");
}
