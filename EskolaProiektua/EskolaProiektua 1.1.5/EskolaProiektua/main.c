#include "main.h"
#include <stdio.h>
#include <math.h>
#include<string.h>
#include <stdlib.h>



void datuEgituraHasieratu(ESKOLA eskolak[ESKOLAMAX]);
int erabiltzaileaAukeratu(ESKOLA eskolak[ESKOLAMAX]);
int fitxeroanIrakurri(ESKOLA eskolak[ESKOLAMAX]);
int fitxeroanIdatzi(ESKOLA eskolak[ESKOLAMAX]);
//void aukerak(int erabiltzailea);


int main(){
	//aldagaiak
	int erabiltzailea = 0;
	int emaitza = 0;

	ESKOLA eskolak[ESKOLAMAX];

	//programa
	emaitza = fitxeroanIrakurri(eskolak);
	if (emaitza == 0){
		datuEgituraHasieratu(eskolak);
		printf("Eskolako datuak sartzen hasteko sakatu ENTER\n");
		getchar();
		fflush(stdin);
		DATUENMODIFIKAZIOA_eskolakoDatuakSartu(eskolak);
	}
	

	do{
		erabiltzailea = MENUA_erabiltzaileaAukeratu(eskolak);

		system("cls");
	} while (erabiltzailea == 0);

	emaitza = fitxeroanIdatzi(eskolak);

}

void datuEgituraHasieratu(ESKOLA eskolak[ESKOLAMAX]){
	//aldagaiak
	int i = 0, t = 0, w = 0, x = 0, y = 0;

	//programa
	for (i = 0; i < ESKOLAMAX; i++){
		for (t = 0; t < GELAMAX; t++){
			for (w = 0; w < IKASLEAKMAX; w++){
				for (x = 0; x < IKASGAIMAX; x++){
					eskolak[i].gelak[t].ikasleak[w].ikasgaiak[x].nota = -1;
					eskolak[i].gelak[t].ikasleak[w].ikasgaiak[x].aukeratuta = 0;
				}
				eskolak[i].gelak[t].ikasleak[w].idal = 0;
				eskolak[i].gelak[t].ikasleak[w].data.eguna = 0;
				eskolak[i].gelak[t].ikasleak[w].data.hilea = 0;
				eskolak[i].gelak[t].ikasleak[w].data.urtea = 0;
				eskolak[i].gelak[t].ikasleak[w].gela = 0;
				eskolak[i].gelak[t].ikasleak[w].batezbestekoa = 0;
				eskolak[i].gelak[t].ikasleak[w].ikasgaiKopurua = 0;
			}
			for (w = 0; w < IKASGAIMAX; w++){
				eskolak[i].gelak[t].irakasleak[w].data.eguna = 0;
				eskolak[i].gelak[t].irakasleak[w].data.hilea = 0;
				eskolak[i].gelak[t].irakasleak[w].data.urtea = 0;
				eskolak[i].gelak[t].irakasleak[w].idal = 0;
				eskolak[i].gelak[t].irakasleak[w].orduak = 0;
			}
			eskolak[i].gelak[t].ikasleKopurua = 0;
			eskolak[i].gelak[t].tutorea.data.eguna = 0;
			eskolak[i].gelak[t].tutorea.data.hilea = 0;
			eskolak[i].gelak[t].tutorea.data.urtea = 0;
			eskolak[i].gelak[t].tutorea.idal = 0;
			eskolak[i].gelak[t].tutorea.orduak = 0;
			eskolak[i].gelak[t].gelaId = 0;
			eskolak[i].gelak[t].aukeragarri = 0;
			strcpy(eskolak[i].gelak[t].maila, "0");
			for (x = 0; x < IKASGAIMAX; x++){
				eskolak[i].gelak[t].ikasgaiak[x].nota = -1;
				eskolak[i].gelak[t].ikasgaiak[x].aukeratuta = 0;
				strcpy(eskolak[i].gelak[t].ikasgaiak[x].izena, "ikasgaia");
			}
		}
		eskolak[i].helbidea.postaKodea = 0;
		eskolak[i].helbidea.zenbakia = 0;
		eskolak[i].gelaKopurua = 0;
		eskolak[i].telefonoa = 0;
		eskolak[i].eskolaKopurua = 0;
		eskolak[i].aukeratutakoEskola = 0;
	}
}

int fitxeroanIrakurri(ESKOLA eskolak[ESKOLAMAX]){
	//aldagaiak
	int karaktereKopurua = 0;
	FILE* fitxeroa;
	int egokia = 0;


	//programa
	if ((fitxeroa = fopen("datos.txt", "rb")) == NULL){
		printf("Ezin izan da datuak irekitzeko fitxeroa aurkitu");
		egokia = 0;
	}
	else{
		karaktereKopurua = fread(&eskolak[ESKOLAMAX], ESKOLAMAX * sizeof(eskolak), 1, fitxeroa);
		if (sizeof(eskolak) == karaktereKopurua){
			egokia = 1;
		}
	}
	//return 
	return egokia;
}

int fitxeroanIdatzi(ESKOLA eskolak[ESKOLAMAX]){
	//aldagaiak
	int karaktereKopurua = 0;
	FILE* fitxeroa;
	int egokia = 0;


	//programa
	if ((fitxeroa = fopen("datos.txt", "wb")) == NULL){
		printf("Ezin izan da datuak gordetzeko fitxeroa aurkitu");
		egokia = 0;
	}
	else{
		karaktereKopurua = karaktereKopurua = fwrite(&eskolak[ESKOLAMAX], ESKOLAMAX * sizeof(eskolak), 1, fitxeroa);
		if (sizeof(eskolak) == karaktereKopurua){
			egokia = 1;
		}
	}

	//return 
	return egokia;
}

