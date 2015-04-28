#include "main.h"

void MENU_menua(){
	//aldagaiak
	int denborak[8][2];
	int i = 0, t = 0;
	int aukera = 0;

	//programa
	for (i = 0; i < 8; i++){
		for (t = 0; t < 2; t++){
			denborak[i][t] = 0;
		}
	}

	do{
		printf("Zer nahi duzu egin?\n");
		printf("1. Fitxeroetako zenbakiak metodo desberdinekin ordenatu\n");
		printf("2. Zenbakien ordenaketan irauten diren denborak ikusi\n");
		printf("0. Irten\n");
		scanf("%i", &aukera);
		switch (aukera){
		case 1:
			MENU_menuaFuntzioak(denborak);
			break;
		case 2:
			MENU_menuaDenborak(denborak);
			break;
		}

	} while (aukera!=0);

	//bukaera

}

void MENU_menuaFuntzioak(int denborak[5][2]){
	//aldagaiak
	int aukera = 0;
	int mota = 0;
	char helbidea[300];
	int zenbakiak[50000];

	//programa
	printf("Zer nahi duzu egin?\n");
	printf("1. Hautaketa zuzena(selección directa)\n");
	printf("2. Hautaketa zuzena hobetua(selección directa mejorada)\n");
	printf("3. Burbuila(burbuja – bubleSort)\n");
	printf("4. Burbuila hobetua(burbuja mejorada – bubleSort implemented)\n");
	printf("5. Txertaketa zuzena(inserción directa)\n");
	printf("6. Txertaketa zuzena hobetua(inserción directa mejorada)\n");
	printf("7. ShellSort\n");
	printf("8. QuickSort\n");
	scanf("%i", &aukera);

	printf("Zein tamainatako fitxeroak nahi dituzu ordenatu?\n");
	printf("1. 30 000\n");
	printf("2. 50 000\n");
	scanf("%i", &mota);

	if (mota == 1){

		zenbakiakIrakurri30000(zenbakiak);

		switch (aukera){
		case 1:
			denborak[0][0] = hautaketaZuzena(zenbakiak, 30000);
			break;

		case 2:
			denborak[1][0] = hautaketaZuzena_hobetua(zenbakiak, 30000);
			break;

		case 3:
			denborak[2][0] = burbuila(zenbakiak, 30000);
			break;

		case 4:
			denborak[3][0] = burbuila_hobetua(zenbakiak, 30000);
			break;

		case 5:
			denborak[4][0] = txertaketaZuzena(zenbakiak, 30000);
			break;

		case 6:
			denborak[5][0] = txertaketaZuzena_hobetua(zenbakiak, 30000);
			break;

		case 7:
			denborak[6][0] = shellSort(zenbakiak, 30000);
			break;

		case 8:
			denborak[7][0] = quickSort(zenbakiak, 30000);
			break;

		}
	}

	if (mota == 2){

		zenbakiakIrakurri50000(zenbakiak);

		switch (aukera){
		case 1:
			denborak[0][1] = hautaketaZuzena(zenbakiak, 30000);
			break;

		case 2:
			denborak[1][1] = hautaketaZuzena_hobetua(zenbakiak, 30000);
			break;

		case 3:
			denborak[2][1] = burbuila(zenbakiak, 30000);
			break;

		case 4:
			denborak[3][1] = burbuila_hobetua(zenbakiak, 30000);
			break;

		case 5:
			denborak[4][1] = txertaketaZuzena(zenbakiak, 30000);
			break;

		case 6:
			denborak[5][1] = txertaketaZuzena_hobetua(zenbakiak, 30000);
			break;

		case 7:
			denborak[6][1] = shellSort(zenbakiak, 30000);
			break;

		case 8:
			denborak[7][1] = quickSort(zenbakiak, 30000);
			break;

		}
	}
}

void MENU_menuaDenborak(int denborak[5][2]){
	//aldagaiak
	int i = 0, t = 0;

	//programa
	printf("1. Hautaketa zuzena(selección directa)\n");
	if (denborak[0][0] == 0){
		printf("\t 30 000 zenbakiko fitxeroa: Datu hau ez dago eskuragarri\n");
	}
	else{
		printf("\t 30 000 zenbakiko fitxeroa: %i miliSeg\n", denborak[0][0]);
	}
	if (denborak[0][1] == 0){
		printf("\t 50 000 zenbakiko fitxeroa: Datu hau ez dago eskuragarri\n");
	}
	else{
		printf("\t 50 000 zenbakiko fitxeroa: %i miliSeg\n", denborak[0][1]);
	}

	printf("2. Hautaketa zuzena hobetua(selección directa mejorada)\n");
	if (denborak[1][0] == 0){
		printf("\t 30 000 zenbakiko fitxeroa: Datu hau ez dago eskuragarri\n");
	}
	else{
		printf("\t 30 000 zenbakiko fitxeroa: %i miliSeg\n", denborak[1][0]);
	}
	if (denborak[1][1] == 0){
		printf("\t 50 000 zenbakiko fitxeroa: Datu hau ez dago eskuragarri\n");
	}
	else{
		printf("\t 50 000 zenbakiko fitxeroa: %i miliSeg\n", denborak[1][1]);
	}

	printf("3. Burbuila(burbuja – bubleSort)\n");
	if (denborak[2][0] == 0){
		printf("\t 30 000 zenbakiko fitxeroa: Datu hau ez dago eskuragarri\n");
	}
	else{
		printf("\t 30 000 zenbakiko fitxeroa: %i miliSeg\n", denborak[2][0]);
	}
	if (denborak[2][1] == 0){
		printf("\t 50 000 zenbakiko fitxeroa: Datu hau ez dago eskuragarri\n");
	}
	else{
		printf("\t 50 000 zenbakiko fitxeroa: %i miliSeg\n", denborak[2][1]);
	}

	printf("4. Burbuila hobetua(burbuja mejorada – bubleSort implemented)\n");
	if (denborak[3][0] == 0){
		printf("\t 30 000 zenbakiko fitxeroa: Datu hau ez dago eskuragarri\n");
	}
	else{
		printf("\t 30 000 zenbakiko fitxeroa: %i miliSeg\n", denborak[3][0]);
	}
	if (denborak[3][1] == 0){
		printf("\t 50 000 zenbakiko fitxeroa: Datu hau ez dago eskuragarri\n");
	}
	else{
		printf("\t 50 000 zenbakiko fitxeroa: %i miliSeg\n", denborak[3][1]);
	}

	printf("5. Txertaketa zuzena(inserción directa)\n");
	if (denborak[4][0] == 0){
		printf("\t 30 000 zenbakiko fitxeroa: Datu hau ez dago eskuragarri\n");
	}
	else{
		printf("\t 30 000 zenbakiko fitxeroa: %i miliSeg\n", denborak[4][0]);
	}
	if (denborak[4][1] == 0){
		printf("\t 50 000 zenbakiko fitxeroa: Datu hau ez dago eskuragarri\n");
	}
	else{
		printf("\t 50 000 zenbakiko fitxeroa: %i miliSeg\n", denborak[4][1]);
	}

	printf("6. Txertaketa zuzena hobetua(inserción directa mejorada)\n");
	if (denborak[5][0] == 0){
		printf("\t 30 000 zenbakiko fitxeroa: Datu hau ez dago eskuragarri\n");
	}
	else{
		printf("\t 30 000 zenbakiko fitxeroa: %i miliSeg\n", denborak[5][0]);
	}
	if (denborak[5][1] == 0){
		printf("\t 50 000 zenbakiko fitxeroa: Datu hau ez dago eskuragarri\n");
	}
	else{
		printf("\t 50 000 zenbakiko fitxeroa: %i miliSeg\n", denborak[5][1]);
	}

	printf("7. ShellSort\n");
	if (denborak[6][0] == 0){
		printf("\t 30 000 zenbakiko fitxeroa: Datu hau ez dago eskuragarri\n");
	}
	else{
		printf("\t 30 000 zenbakiko fitxeroa: %i miliSeg\n", denborak[6][0]);
	}
	if (denborak[6][1] == 0){
		printf("\t 50 000 zenbakiko fitxeroa: Datu hau ez dago eskuragarri\n");
	}
	else{
		printf("\t 50 000 zenbakiko fitxeroa: %i miliSeg\n", denborak[6][1]);
	}

	printf("8. QuickSort\n");
	if (denborak[7][0] == 0){
		printf("\t 30 000 zenbakiko fitxeroa: Datu hau ez dago eskuragarri\n");
	}
	else{
		printf("\t 30 000 zenbakiko fitxeroa: %i miliSeg\n", denborak[7][0]);
	}
	if (denborak[7][1] == 0){
		printf("\t 50 000 zenbakiko fitxeroa: Datu hau ez dago eskuragarri\n");
	}
	else{
		printf("\t 50 000 zenbakiko fitxeroa: %i miliSeg\n", denborak[7][1]);
	}

	//bukaera

}

