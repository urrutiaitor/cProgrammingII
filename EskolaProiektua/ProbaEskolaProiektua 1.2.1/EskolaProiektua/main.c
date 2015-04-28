#include "main.h"
#include <stdio.h>
#include <math.h>
#include<string.h>
#include <stdlib.h>



void datuEgituraHasieratu(ESKOLA enpresa[ESKOLAMAX]);
int erabiltzaileaAukeratu(ESKOLA enpresa[ESKOLAMAX]);
//void aukerak(int erabiltzailea);


int main(){
	//aldagaiak
	int erabiltzailea;

	ESKOLA eskolak[ESKOLAMAX];

	//programa
	datuEgituraHasieratu(eskolak);
	printf("Eskolako datuak sartzen hasteko sakatu ENTER\n");
	getchar();
	fflush(stdin);
	DATUENMODIFIKAZIOA_eskolakoDatuakSartu(eskolak);

	do{
		erabiltzailea = MENUA_erabiltzaileaAukeratu(eskolak);

		system("cls");
	} while (erabiltzailea == 0);

}

void datuEgituraHasieratu(ESKOLA eskolak[ESKOLAMAX]){
	//aldagaiak
	int i = 0, t = 0, w = 0, x = 0, y = 0;

	//programa
	for (i = 0; i < ESKOLAMAX; i++){
		eskolak[i].aukeratutakoEskola = 0;
		eskolak[i].eskolaKopurua = 0;
		eskolak[i].telefonoa = 0;
		eskolak[i].gelaKopurua = 0;
		strcpy(eskolak[i].izena, "izena");
		strcpy(eskolak[i].helbidea.kalea, "kalea");
		eskolak[i].helbidea.postaKodea = 0;
		eskolak[i].helbidea.zenbakia = 0;

		for (t = 0; t < IKASLEAKMAX; t++){
			strcpy(eskolak[i].ikasleak[t].izena, "izena");
			strcpy(eskolak[i].ikasleak[t].abizena, "abizena");
			eskolak[i].ikasleak[t].idal = 0;
			eskolak[i].ikasleak[t].data.eguna = 0;
			eskolak[i].ikasleak[t].data.hilea = 0;
			eskolak[i].ikasleak[t].data.urtea = 0;
			for (w = 0; w < IKASGAIMAX; w++){
				strcpy(eskolak[i].ikasleak[t].ikasgaiak[w].izena, "izena");
				eskolak[i].ikasleak[t].ikasgaiak[w].nota = 0;
				eskolak[i].ikasleak[t].ikasgaiak[w].id = 0;
				eskolak[i].ikasleak[t].ikasgaiak[w].aukeratuta = 0;
			}
			eskolak[i].ikasleak[t].gela = 0;
			eskolak[i].ikasleak[t].batezbestekoa = 0;
			eskolak[i].ikasleak[t].ikasgaiKopurua = 0;
		}
		for (t = 0; t < IRAKASLEAKMAX; t++){
			strcpy(eskolak[i].irakasleak[t].izena, "izena");
			strcpy(eskolak[i].irakasleak[t].abizena, "abizena");
			eskolak[i].irakasleak[t].idal = 0;
			eskolak[i].irakasleak[t].data.eguna = 0;
			eskolak[i].irakasleak[t].data.hilea = 0;
			eskolak[i].irakasleak[t].data.urtea = 0;
			eskolak[i].irakasleak[t].orduak = 0;
		}
		for (t = 0; t < GELAMAX; t++){
			strcpy(eskolak[i].gelak[t].maila, "kalea");
			eskolak[i].gelak[t].ikasleKopurua = 0;
			eskolak[i].gelak[t].irakasleaId = 0;
			eskolak[i].gelak[t].gelaId = 0;
			eskolak[i].gelak[t].aukeragarri = 0;

			for (w = 0; w < IKASGAIMAX; w++){
				eskolak[i].gelak[t].ikasgaiak[w].nota = 0;
				eskolak[i].gelak[t].ikasgaiak[w].id = 0;
				eskolak[i].gelak[t].ikasgaiak[w].aukeratuta = 0;
				strcpy(eskolak[i].gelak[t].ikasgaiak[w].izena, "ikasgaia");
			}
		}
		
	}
}

