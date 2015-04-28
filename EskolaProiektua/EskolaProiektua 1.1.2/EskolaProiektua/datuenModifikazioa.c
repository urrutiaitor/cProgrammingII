#include "main.h"
#include "datuenModifikazioa.h"
//#include "menua.h"
#include <stdio.h>
#include <math.h>

void DATUENMODIFIKAZIOA_eskolakoDatuakSartu(ESKOLA eskolak[ESKOLAMAX]){
	//aldagaiak
	int eskola = 0; //sarrera parametro gisa sartu behar da

	//programa
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

	DATUENMODIFIKAZIOA_ikasgaiakSartu(eskola);


	eskolak[0].eskolaKopurua = eskolak[0].eskolaKopurua + 1;
}

void DATUENMODIFIKAZIOA_notakSartu(ESKOLA eskolak[ESKOLAMAX]){
	//aldagaiak
	int gela = 0, ikaslea = 0, ikasgaia = 0;
	int i = 0;
	int eskola = 0; //se supone hau sarrera bat gisa jaso behar dela

	//programa
	printf("Zein gelatan nahi duzu sartu?\n");
	for (i = 0; i < GELAMAX; i++){
		if (eskolak[eskola].gelak[i].ikasleKopurua>0){
			printf("%i. %s\n", i+1, eskolak[eskola].gelak[i].maila);
		}
	}
	scanf("%i", &gela);
	fflush(stdin);
	gela = gela - 1;

	printf("Zein ikasgaitan nahi duzu sartu?\n");
	for (i = 0; i < IKASGAIMAX; i++){
		if (eskolak[eskola].gelak[gela].ikasgaiak[i].nota==1){
			printf("%i. %s\n", i+1, eskolak[eskola].gelak[gela].ikasgaiak[i].izena);
		}
	}
	scanf("%i", &ikasgaia);
	fflush(stdin);
	ikasgaia = ikasgaia - 1;

	printf("Joan ikasleen notak sartzen:\n");
	for (i = 0; i < IKASLEAKMAX; i++){
		if (eskolak[eskola].gelak[gela].ikasleak[i].ikasgaiak[ikasgaia].aukeratuta == 1){
			printf("%s %s:\n", eskolak[eskola].gelak[gela].ikasleak[i].izena, eskolak[eskola].gelak[gela].ikasleak[i].abizena);
			scanf("%f", &eskolak[eskola].gelak[gela].ikasleak[i].ikasgaiak[ikasgaia].nota);
			fflush(stdin);
		}
	}

}

void DATUENMODIFIKAZIOA_ikasleBatSartu(ESKOLA eskolak[ESKOLAMAX]){
	//aldagaiak
	int eskola = 0; //sarrera bezala jaso beharko zen
	int i = 0;
	int gela = 0;

	//programa
	printf("Zein mailatan nahi du matrikulatu ikasleak:\n");
	for (i = 0; i < GELAMAX; i++){
		if (eskolak[eskola].gelak[i].aukeragarri == 1){
			printf("%i. %s\n", i + 1, eskolak[eskola].gelak[i].maila);
		}
	}
	scanf("%i", &gela);
	gela = gela - 1;
	if (eskolak[eskola].gelak[gela].ikasleKopurua == IKASLEAKMAX){
		printf("Maila hortan ezin da matrikulatu ikasle kopurua beteta dagoelako. Sentitzen dugu\n");
	}
	else{
		DATUENMODIFIKAZIOA_batenDatuakSartu(eskolak,eskola,gela);
		DATUENMODIFIKAZIOA_ikaslearenIkasgaiakSartu(eskolak,eskola,gela);
		eskolak[eskola].gelak[gela].ikasleKopurua++;
	}
}

void DATUENMODIFIKAZIOA_eskolakoDatuakModifikatu(ESKOLA eskolak[ESKOLAMAX]){
	printf("Zer aldatu nahi duzu?\n");
	

}

void DATUENMODIFIKAZIOA_ikasleakGeletanBanatu(ESKOLA eskolak[ESKOLAMAX]){

} //hasiera batean funtzio hau ez da egongo erabilgarri

void DATUENMODIFIKAZIOA_gelaFisikoaAsignatu(ESKOLA eskolak[ESKOLAMAX]){
	//aldagaiak
	int i = 0;
	int kont = 1;
	int eskola = 0; //sarrera parametro gisa hartu behar da

	//programa
	for (i = 0; i < GELAMAX; i++){
		if (eskolak[eskola].gelak[i].ikasleKopurua>0){
			eskolak[eskola].gelak[i].gelaId = (((eskola + 1) * 1000) + (kont));
			kont++;
		}
	}
}

void DATUENMODIFIKAZIOA_irakasleakAsignatu(ESKOLA eskolak[ESKOLAMAX]){
	//aldagaiak

	//programa
}

void DATUENMODIFIKAZIOA_tutoreaAsignatu(ESKOLA eskolak[ESKOLAMAX]){

}

void DATUENMODIFIKAZIOA_batenDatuakSartu(ESKOLA eskolak[ESKOLAMAX],int eskola,int gela){
	//aldagaiak

	//programa
	printf("Zein da ikaslearen izena?\n");
	gets(eskolak[eskola].gelak[gela].ikasleak[eskolak[eskola].gelak[gela].ikasleKopurua].izena);
	fflush(stdin);
	printf("Zein da ikaslearen abizena?\n");
	gets(eskolak[eskola].gelak[gela].ikasleak[eskolak[eskola].gelak[gela].ikasleKopurua].abizena);
	fflush(stdin);
	printf("Zein da ikaslearen jaiotze urtea?\n");
	scanf("%i", &eskolak[eskola].gelak[gela].ikasleak[eskolak[eskola].gelak[gela].ikasleKopurua].data.urtea);
	fflush(stdin);
	printf("Zein da ikaslearen jaiotze hilea?\n");
	scanf("%i", &eskolak[eskola].gelak[gela].ikasleak[eskolak[eskola].gelak[gela].ikasleKopurua].data.hilea);
	fflush(stdin);
	printf("Zein da ikaslearen jaiotze eguna?\n");
	scanf("%i", &eskolak[eskola].gelak[gela].ikasleak[eskolak[eskola].gelak[gela].ikasleKopurua].data.eguna);
	fflush(stdin);
}

void DATUENMODIFIKAZIOA_ikaslearenIkasgaiakSartu(ESKOLA eskolak[ESKOLAMAX],int eskola,int gela){
	//aldagaiak
	int i = 0;
	int segi = 0;
	int aukera = 0;

	//programa
	while (segi == 1){
		segi = 0;
		printf("Zein ikasgai nahi dituzu heman:\n");
		for (i = 0; i < IKASGAIMAX; i++){
			if (eskolak[eskola].gelak[gela].ikasleak[eskolak[eskola].gelak[gela].ikasleKopurua].ikasgaiak[i].aukeratuta == 0){
				printf("%i. %s", i, eskolak[eskola].gelak[gela].ikasgaiak[i].izena);
			}
		}
		scanf("%i", &aukera);
		fflush(stdin);
		aukera = aukera - 1;
		eskolak[eskola].gelak[gela].ikasleak[eskolak[eskola].gelak[gela].ikasleKopurua].ikasgaiak[aukera].aukeratuta = 1;

		for (i = 0; i < IKASGAIMAX; i++){
			if (eskolak[eskola].gelak[gela].ikasleak[eskolak[eskola].gelak[gela].ikasleKopurua].ikasgaiak[i].aukeratuta == 0){
				segi = 1;
			}
		}
		if (segi == 1){
			printf("Beste ikasgairen bat heman nahi duzu? BAI(1)/EZ(0)\n");
			scanf("%i", &segi);
			fflush(stdin);
		}
	}
}

void DATUENMODIFIKAZIOA_ikasgaiakSartu(ESKOLA eskolak[ESKOLAMAX]){
	//aldagaiak
	int kont = 0;
	int maila = 0;
	int i = 0;
	int eskola = 0; //sarrera parametro bezela sartu behar da
	
	//programa
	printf("Zein mailatako ikasgaiak nahi dituzu sartu?\n");
	scanf("%i", &maila);
	fflush(stdin);

	while (kont < 10){
		printf("Sartu nahi duzun ikasgaiaren izena:\n");
		gets(eskolak[eskola].gelak[maila].ikasgaiak[kont].izena);
		eskolak[eskola].gelak[maila].ikasgaiak[kont].aukeratuta = 1;
		for (i = 0; i < IKASLEAKMAX; i++){
			strcpy(eskolak[eskola].gelak[maila].ikasleak[i].ikasgaiak[kont].izena, eskolak[eskola].gelak[maila].ikasgaiak[kont].izena);
		}
		kont++;
	}
	
}