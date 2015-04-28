#include "ariketa1.h"

int main(){
	int auk = 0;

	do{
		printf("1 - Bezero berri bat sartu kirol DB\n");
		printf("2 - Sarrerako txartel irakurgailua\n");

		printf("0 - Irteteko\n");
		printf("Aukera> ");
		scanf("%i", &auk);

		switch (auk){
		case 1:
			biztanleaSartu();
			break;

		case 2:
			piszinaraSarrera();
			break;

		case 0:
			printf("Piszina itxita geratzen da\n");
			break;
		}
		
	} while (auk != 0);

	fflush(stdin);
	getchar();
}

void biztanleaSartu(){
	//aldagaiak
	FILE *fitxeroa;
	BIZTANLEA biztanleak;
	int posizioa = 0;


	//programa
	fitxeroa = fopen("kirolDB.dat", "a+");
	fread(&biztanleak, sizeof (BIZTANLEA), 1, fitxeroa);
	posizioa=ftell(fitxeroa);

	biztanleak = datuakJaso();
	
	
	fwrite(&biztanleak, sizeof (BIZTANLEA), 1, fitxeroa);
	fclose(fitxeroa); 

	//return
	return 0;
}

BIZTANLEA datuakJaso(){
	//aldagaiak
	BIZTANLEA biztanle;

	//programa
	printf("Izena: ");
	fflush(stdin);
	gets_s(biztanle.izena, IZENAMAX);

	printf("Abizena: ");
	fflush(stdin);
	gets_s(biztanle.abizena, IZENAMAX);

	printf("Helbidea, kalea: ");
	fflush(stdin);
	gets_s(biztanle.helbidea.kalea, 40);

	printf("Helbidea, zenbakia: ");
	fflush(stdin);
	scanf("%i", &biztanle.helbidea.zenbakia);

	printf("Helbidea, solairua: ");
	fflush(stdin);
	scanf("%i", &biztanle.helbidea.solairua);

	printf("Helbidea, letra: ");
	fflush(stdin);
	gets(biztanle.helbidea.letra);

	printf("Jaiotze urtea: ");
	fflush(stdin);
	scanf("%i", &biztanle.jaiotzeData.urtea);

	printf("Jaiotze hilea: ");
	fflush(stdin);
	scanf("%i", &biztanle.jaiotzeData.hilea);

	printf("Jaiotze eguna: ");
	fflush(stdin);
	scanf("%i", &biztanle.jaiotzeData.eguna);

	printf("Kontu korrontea: ");
	fflush(stdin);
	gets_s(biztanle.kontuKorrontea, KONTUKORRONTEAMAX);

	printf("Zure dni-a (letra gabe): ");
	scanf("%i", &biztanle.kodea);

	//return 
	return biztanle;
}

void piszinaraSarrera(){
	//aldagaiak
	int emaitza = 0;
	int kodea = 0;
	char izena[IZENAMAX];
	char abizena[IZENAMAX];
	char *izena_ptr = &izena[0];
	char *abizena_ptr = &abizena[0];

	//programa
	printf("Zein da zure bazkide kodea(DNI-a letra gabe): ");
	fflush(stdin);
	scanf("%i", &kodea);

	printf("Zein da zure izena: ");
	fflush(stdin);
	gets_s(izena, IZENAMAX);

	printf("Zein da zure abizena: ");
	fflush(stdin);
	gets_s(abizena, IZENAMAX);

	emaitza = datuakKonprobatu(kodea, izena_ptr, abizena_ptr);

	switch (emaitza){
	case TXARTO:
		printf("Zure kodea ez dago datu basean eta ezin zara sartu\n");
		break;
	case DENAONDO:
		printf("Zure kodea ondo dago, barrura sartu zaitezke\n");
		break;
	case IZENATXARTO:
		printf("Zure bazkide izenak ez du koinziditzen, arrerakoarekin hitz egin\n");
		break;
	case ABIZENATXARTO:
		printf("Zure bazkide abizenak ez du koinziditzen, arrerakoarekin hitz egin\n");
		break;
	case IZENAABIZENATXARTO:
		printf("Zure bazkide izen eta abizenak ez dute koinziditzen, arrerakoarekin hitz egin\n");
		break;
	}


	//return
	return 0;
}

int datuakKonprobatu(int kodea, char *izena, char *abizena){
	//aldagaiak
	int egral = TXARTO;
	FILE *fitxeroa;
	BIZTANLEA biztanleak;
	int kont = 0;

	//programa
	fitxeroa = fopen("kirolDB.dat", "rb");
	while (fread(&biztanleak, sizeof (BIZTANLEA), 1, fitxeroa)){
		if (biztanleak.kodea == kodea){
			if (strcmp(biztanleak.izena, izena) == 0){
				if (strcmp(biztanleak.abizena, abizena) == 0){
					egral = DENAONDO;
				}
				if (strcmp(biztanleak.abizena, abizena) != 0){
					egral = ABIZENATXARTO;
				}
			}
			if (strcmp(biztanleak.izena, izena) != 0){
				if (strcmp(biztanleak.abizena, abizena) == 0){
					egral = IZENATXARTO;
				}
				if (strcmp(biztanleak.abizena, abizena) != 0){
					egral = IZENAABIZENATXARTO;
				}
			}
		}

	}

	fclose(fitxeroa);


	//return
	return egral;
}

