#include "main.h"
#include <stdio.h>
#include <math.h>



void datuEgituraHasieratu(ESKOLA enpresa[ESKOLAMAX]);
int erabiltzaileaAukeratu(ESKOLA enpresa[ESKOLAMAX]);
//void aukerak(int erabiltzailea);


int main(){
	//aldagaiak
	int erabiltzailea;

	ESKOLA eskolak[ESKOLAMAX];

	//programa
	datuEgituraHasieratu(eskolak);

	do{
		erabiltzailea = MENUA_erabiltzaileaAukeratu(eskolak);


	} while (erabiltzailea == 0);

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
				}
				eskolak[i].gelak[t].ikasleak[w].idal = 0;
				eskolak[i].gelak[t].ikasleak[w].data.eguna = 0;
				eskolak[i].gelak[t].ikasleak[w].data.hilea = 0;
				eskolak[i].gelak[t].ikasleak[w].data.urtea = 0;
				eskolak[i].gelak[t].ikasleak[w].gela = 0;
			}
			eskolak[i].gelak[t].ikasleKopurua = 0;
			eskolak[i].gelak[t].tutorea.data.eguna = 0;
			eskolak[i].gelak[t].tutorea.data.hilea = 0;
			eskolak[i].gelak[t].tutorea.data.urtea = 0;
			eskolak[i].gelak[t].tutorea.idal = 0;
		}
		eskolak[i].helbidea.postaKodea = 0;
		eskolak[i].helbidea.zenbakia = 0;
		eskolak[i].gelaKopurua = 0;
	}
}

