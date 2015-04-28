#include "ariketa_ca.h"

int main(){
	//aldagaiak
	int aukera = 0;
	ZENBAKIA *zenbakiHasiera_ptr;
	int zutabeak = 0, lerroak = 0;
	TAMAINA tamaina;
	TAMAINA *tamaina_ptr=&tamaina;

	//programa
	do{
		printf("1. Matrizea sortu fitxeroan\n");
		printf("2. Matrizea irakurri fitxerotik\n");
		printf("3. Matrizea bistaratu pantailan\n");
		printf("0. Irten\n");
		scanf("%i", &aukera);

		switch (aukera){

		case 1:
			matrizeaSortu();
			break;

		case 2:
			zenbakiHasiera_ptr = matrizeaIreki(tamaina_ptr);
			break;

		case 3:
			matrizeaBistaratu(tamaina_ptr, zenbakiHasiera_ptr);
			break;

		case 4:

			break;
		}
		system("cls");

	} while (aukera != 0);

	//bukaera
	fflush(stdin);
	return 0;
}

void matrizeaSortu(){
	//aldagaiak
	FILE *fitxeroa;
	TAMAINA tamaina;
	double zenbakia = 0;
	int lerroak = 0, zutabeak = 0, kopurua = 0;
	int i = 0;

	//programa
	printf("Lerro kopurua: ");
	scanf("%i", &tamaina.lerroak);
	printf("Zutabe kopurua: ");
	scanf("%i", &tamaina.zutabeak);

	printf("Zure matrizea matrizea.dat fitxeroan gorde da\n");

	fitxeroa = fopen("matrizea.dat", "wb");

	fwrite(&tamaina, sizeof (TAMAINA), 1, fitxeroa);

	for (i = 0; i < (tamaina.lerroak*tamaina.zutabeak); i++){
		zenbakia = rand() % (MAX - MIN + 1) + MIN;
		fwrite(&zenbakia, sizeof (double), 1, fitxeroa);
	}
	fclose(fitxeroa);

	fflush(stdin);
	getchar();

	//return
	return 0;
}

ZENBAKIA* matrizeaIreki(TAMAINA* tamaina_ptr){
	//aldagaiak
	FILE *fitxeroa;
	char helbidea[IZENA];
	double zenbakia = 0;
	int lerroak = 0, zutabeak = 0, kopurua = 0;
	int i = 0;
	TAMAINA tamaina;
	ZENBAKIA zenbakiHasiera;
	PZENBAKIA aux_ptr = &zenbakiHasiera;
	PZENBAKIA zenbakiHasiera_ptr = &zenbakiHasiera;

	//programa	

	printf("Zein da matrizearen izena: \n");
	fflush(stdin);
	gets_s(helbidea, IZENA);

	fitxeroa = fopen(helbidea, "rb");

	fread(tamaina_ptr, sizeof (TAMAINA), 1, fitxeroa);

	for (i = 1; i < ((tamaina_ptr->lerroak)*(tamaina_ptr->zutabeak)); i++){
		aux_ptr->urrengo_ptr = (PZENBAKIA)malloc(sizeof(ZENBAKIA));
		fread(&aux_ptr->zenbakia, sizeof (double), 1, fitxeroa);
		aux_ptr = aux_ptr->urrengo_ptr;
		
	}
	fread(&aux_ptr->zenbakia, sizeof (double), 1, fitxeroa);
	aux_ptr->urrengo_ptr = NULL;
	fclose(fitxeroa);

	system("cls");

	//return
	return zenbakiHasiera_ptr;
}

void matrizeaTransformatu(){

}

void matrizeaPrintatu(){

}

void matrizeaBistaratu(TAMAINA* tamaina_ptr, PZENBAKIA zenbakiHasiera_ptr){
	//aldagaiak
	PZENBAKIA aux_ptr = zenbakiHasiera_ptr;
	int i = 0, t = 0;

	//programa
	for (i = 0; i <tamaina_ptr->zutabeak; i++){
		for (t = 0; t < tamaina_ptr->lerroak; t++){
			printf("%f", aux_ptr->zenbakia);
			aux_ptr = aux_ptr->urrengo_ptr;
		}
	}

	//bukaera
	return 0;
}