#include "datuenModifikazioa.h"
#include "main.h"
//#include "menua.h"
#include <stdio.h>
#include <math.h>

void DATUENMODIFIKAZIOA_eskolakoDatuakSartu(ENPRESA enpresa[1]){

	printf("sartu eskolaren izena\n");
	gets(enpresa[0].eskolak[enpresa[0].eskolaKopurua].izena);
	fflush(stdin);
	printf("sartu eskolaren kalea\n");
	gets(enpresa[0].eskolak[enpresa[0].eskolaKopurua].helbidea.kalea);
	fflush(stdin);
	printf("sartu eskolaren zenbakia\n");
	scanf("%i", enpresa[0].eskolak[enpresa[0].eskolaKopurua].helbidea.zenbakia);
	fflush(stdin);
	printf("sartu eskolaren posta kodea\n");
	scanf("%i", enpresa[0].eskolak[enpresa[0].eskolaKopurua].helbidea.postaKodea);
	fflush(stdin);
	printf("sartu eskolaren telefono zenbakia\n");
	scanf("%i", enpresa[0].eskolak[enpresa[0].eskolaKopurua].telefonoa);
	fflush(stdin);


	enpresa[0].eskolaKopurua = enpresa[0].eskolaKopurua + 1;
}

void DATUENMODIFIKAZIOA_notakSartu(ENPRESA enpresa[1]){

}

void DATUENMODIFIKAZIOA_ikasleBatSartu(ENPRESA enpresa[1]){

}

void DATUENMODIFIKAZIOA_eskolakoDatuakModifikatu(ENPRESA enpresa[1]){
	printf("Zer aldatu nahi duzu?\n");
	

}

void DATUENMODIFIKAZIOA_ikasleakGeletanBanatu(ENPRESA enpresa[1]){

}

void DATUENMODIFIKAZIOA_gelaFisikoaAsignatu(ENPRESA enpresa[1]){

}

void DATUENMODIFIKAZIOA_irakasleakAsignatu(ENPRESA enpresa[1]){

}

void DATUENMODIFIKAZIOA_tutoreaAsignatu(ENPRESA enpresa[1]){

}