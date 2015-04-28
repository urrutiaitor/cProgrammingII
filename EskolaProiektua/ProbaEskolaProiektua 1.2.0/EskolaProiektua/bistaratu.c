#include "main.h"
#include "bistaratu.h"
#include <stdio.h>
#include <math.h>

void ordenatu(ESKOLA eskolak[ESKOLAMAX],int gela);

int BISTARATU_gelaAukeratu(ESKOLA eskolak[ESKOLAMAX]){
	int gela = 0, ikaslea = 0, ikasgaia = 0;
	int i = 0;
	int eskola = 0;

	printf("Zein gela nahi duzu aukeratu?\n");
	for (i = 0; i < GELAMAX; i++){
		if (eskolak[eskolak[0].aukeratutakoEskola].gelak[i].aukeragarri==1){
			printf("%i. %s\n", i + 1, eskolak[eskola].gelak[i].maila);
		}
	}
	scanf("%i", &gela);
	fflush(stdin);
	gela = gela - 1;
	system("cls");
	return gela;

}

void BISTARATU_notakBistaratuIkaslearentzat(ESKOLA eskolak[ESKOLAMAX]){
	int gela = 0, i=0, ikasgaia=0;

	gela = BISTARATU_gelaAukeratu;
	printf("Zein ikasgaia nahi duzu aukeratu?\n");
	for (i = 0; i < IKASGAIMAX; i++){
		if (eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasgaiak[i].nota == 1){
			printf("%i. %s\n", i + 1, eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasgaiak[i].izena);
		}
	}
	scanf("%i", &ikasgaia);
	fflush(stdin);
	ikasgaia = ikasgaia - 1;
	
	for (i = 0; i < eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleKopurua;i++){

		printf("%i: %f\n", eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[i].idal, eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[i].ikasgaiak[ikasgaia].nota);
	}
	system("cls");

}

void BISTARATU_notakBistaratuIrakaslearentzat(ESKOLA eskolak[ESKOLAMAX]){
	int gela = 0, i = 0, ikasgaia = 0;

	gela = BISTARATU_gelaAukeratu;
	printf("Zein ikasgaia nahi duzu aukeratu?\n");
	for (i = 0; i < IKASGAIMAX; i++){
		if (eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasgaiak[i].nota == 1){
			printf("%i. %s\n", i + 1, eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasgaiak[i].izena);
		}
	}
	scanf("%i", &ikasgaia);
	fflush(stdin);
	ikasgaia = ikasgaia - 1;

	printf("Notak:\n");
	for (i = 0; i < eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleKopurua; i++){

		printf("%s %s: %f\n", eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[i].abizena, eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[i].izena, eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[i].ikasgaiak[ikasgaia].nota);
	}
	system("cls");
}

void BISTARATU_ikaslearenBatezbestekoa(ESKOLA eskolak[ESKOLAMAX]){
	int gela = 0, i = 0, ikasgaia = 0, aukera = 0;
	float batura = 0;

	gela = BISTARATU_gelaAukeratu;
	printf("Idala aukeratu:\n");
	for (i = 0; i < eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleKopurua; i++){

		printf("%i. %i\n", i+1,eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[i].idal);
	}
	scanf("%i", &aukera);
	aukera = aukera - 1;
	for (i = 0; i < IKASGAIMAX; i++){
		batura = batura + eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[aukera].ikasgaiak[i].nota;
	}
	eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[aukera].batezbestekoa = batura / eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[aukera].ikasgaiKopurua;
	printf("Zure batazbestekoa: %.2f\n", eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[aukera].batezbestekoa);

	system("cls");
}

void BISTARATU_taldekoIkasgaikoBatezbestekoa(ESKOLA eskolak[ESKOLAMAX]){
	int gela = 0, i=0, ikasgaia=0, kopurua=0;
	float batazbestekoa = 0, batura = 0;

	gela = BISTARATU_gelaAukeratu;
	printf("Zein ikasgaitan nahi duzu sartu?\n");
	for (i = 0; i < IKASGAIMAX; i++){
		if (eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasgaiak[i].nota == 1){
			printf("%i. %s\n", i + 1, eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasgaiak[i].izena);
		}
	}
	scanf("%i", &ikasgaia);
	fflush(stdin);
	ikasgaia = ikasgaia - 1;

	for (i = 0; i < eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleKopurua; i++){
		if (eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[i].ikasgaiak[ikasgaia].aukeratuta == 1){
		batura = batura + eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[i].ikasgaiak[ikasgaia].nota;
		kopurua = kopurua + 1;
		}
	}
	batazbestekoa = batura / kopurua;
	printf("Asignaturaren batazbestekoa: %.2f\n", batazbestekoa);
	system("cls");
}

void BISTARATU_taldekoBatezbestekoa(ESKOLA eskolak[ESKOLAMAX]){
	float batura = 0, batazbestekoa=0;
	int gela = 0,i=0, j=0;

	for (j = 0; j < eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleKopurua; j++){
		for (i = 0; i < IKASGAIMAX; i++){
			batura = batura + eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[j].ikasgaiak[i].nota;
		}
		eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[j].batezbestekoa = batura / eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[j].ikasgaiKopurua;
		batura = 0;
		batazbestekoa = batazbestekoa + eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[j].batezbestekoa;
	}
	batazbestekoa = batazbestekoa / j;
	printf("Taldeko batazbestekoa:%.2f\n", batazbestekoa);
	system("cls");

}

void BISTARATU_taldekoBatezbestekoHoberena(ESKOLA eskolak[ESKOLAMAX]){
	int gela = 0;

	gela = BISTARATU_gelaAukeratu(eskolak);
	ordenatu(eskolak,gela);
	printf("Taldeko batezbesteko hoberana: %s %s %.2f-ko batezbestekoarekin\n", eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[0].abizena, eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[0].izena, eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[0].batezbestekoa);
	system("cls");
}

void BISTARATU_taldekoIkasleakBatezbestekoarenArabera(ESKOLA eskolak[ESKOLAMAX]){
	int gela = 0,i=0;

	gela = BISTARATU_gelaAukeratu(eskolak);
	ordenatu(eskolak, gela);
	printf("Taldeko ikasleak batezbestekoaren arabera ordenatuta:\n");
	for (i = 0; i < eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleKopurua; i++){
		printf("%s %s %f-ko batezbestekoarekin\n", eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[i].abizena, eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[i].izena, eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[i].batezbestekoa);

	}
	system("cls");
}

void ordenatu(ESKOLA eskolak[ESKOLAMAX],int gela){
	ESKOLA aux;
	int i = 0, j=0;
	float lehena = 0;

	
	lehena = eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[0].batezbestekoa;
	for (i = 1; i < eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleKopurua; i++){
		for (j = 0; j < eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleKopurua; j++){

			if (lehena < eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[i].batezbestekoa){
				aux.gelak[gela].ikasleak[0] = eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[i];
				eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[i] = eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[j];
				eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[j] = aux.gelak[gela].ikasleak[0];
				lehena = eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[j].batezbestekoa;
			}
		}
	}
	system("cls");
}