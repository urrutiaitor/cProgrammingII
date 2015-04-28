#include "main.h"
#include "datuenModifikazioa.h"
//#include "menua.h"
#include <stdio.h>
#include <math.h>

void DATUENMODIFIKAZIOA_eskolakoDatuakSartu(ESKOLA eskolak[ESKOLAMAX]){

	printf("sartu eskolaren izena\n");
	gets(eskolak[eskolak[0].eskolaKopurua].izena);
	fflush(stdin);
	printf("sartu eskolaren kalea\n");
	gets(eskolak[eskolak[0].eskolaKopurua].helbidea.kalea);
	fflush(stdin);
	printf("sartu eskolaren zenbakia\n");
	scanf("%i", eskolak[eskolak[0].eskolaKopurua].helbidea.zenbakia);
	fflush(stdin);
	printf("sartu eskolaren posta kodea\n");
	scanf("%i", eskolak[eskolak[0].eskolaKopurua].helbidea.postaKodea);
	fflush(stdin);
	printf("sartu eskolaren telefono zenbakia\n");
	scanf("%i", eskolak[eskolak[0].eskolaKopurua].telefonoa);
	fflush(stdin);


	eskolak[0].eskolaKopurua = eskolak[0].eskolaKopurua + 1;
}

void DATUENMODIFIKAZIOA_notakSartu(ESKOLA eskolak[ESKOLAMAX]){

}

void DATUENMODIFIKAZIOA_ikasleBatSartu(ESKOLA eskolak[ESKOLAMAX]){

}

void DATUENMODIFIKAZIOA_eskolakoDatuakModifikatu(ESKOLA eskolak[ESKOLAMAX]){
	printf("Zer aldatu nahi duzu?\n");
	

}

void DATUENMODIFIKAZIOA_ikasleakGeletanBanatu(ESKOLA eskolak[ESKOLAMAX]){

}

void DATUENMODIFIKAZIOA_gelaFisikoaAsignatu(ESKOLA eskolak[ESKOLAMAX]){

}

void DATUENMODIFIKAZIOA_irakasleakAsignatu(ESKOLA eskolak[ESKOLAMAX]){

}

void DATUENMODIFIKAZIOA_tutoreaAsignatu(ESKOLA eskolak[ESKOLAMAX]){

}