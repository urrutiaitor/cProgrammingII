#include "main.h"
#include "datuenModifikazioa.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void DATUENMODIFIKAZIOA_eskolakoDatuakSartu(ESKOLA eskolak[ESKOLAMAX]){
	//aldagaiak

	//programa
	DATUENMODIFIKAZIOA_eskolakoIzenaModifikatu(eskolak);

	DATUENMODIFIKAZIOA_eskolakoHelbideaModifikatu(eskolak);
	
	DATUENMODIFIKAZIOA_eskolakoTelefonoaModifikatu(eskolak);


	eskolak[0].eskolaKopurua = eskolak[0].eskolaKopurua + 1;
	system("cls");
}

void DATUENMODIFIKAZIOA_notakSartu(ESKOLA eskolak[ESKOLAMAX]){
	//aldagaiak
	int gela = 0, ikaslea = 0, ikasgaia = 0;
	int i = 0;
	

	//programa
	gela = BISTARATU_gelaAukeratu(eskolak);

	printf("Zein ikasgaitan nahi duzu sartu?\n");
	for (i = 0; i < IKASGAIMAX; i++){
		if (eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasgaiak[i].aukeratuta==1){
			printf("%i. %s\n", i + 1, eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasgaiak[i].izena);
		}
	}
	scanf("%i", &ikasgaia);
	fflush(stdin);
	ikasgaia = ikasgaia - 1;

	printf("Joan ikasleen notak sartzen:\n");
	for (i = 0; i < IKASLEAKMAX; i++){
		if (eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[i].ikasgaiak[ikasgaia].aukeratuta == 1){
			printf("%s %s:\n", eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[i].izena, eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[i].abizena);
			scanf("%f", &eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[i].ikasgaiak[ikasgaia].nota);
			fflush(stdin);
		}
	}
	system("cls");

}

void DATUENMODIFIKAZIOA_ikasleBatSartu(ESKOLA eskolak[ESKOLAMAX]){
	//aldagaiak
	int i = 0;
	int gela = 0;

	//programa
	gela = BISTARATU_gelaAukeratu(eskolak);
	if ((eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleKopurua >= IKASLEAKMAX) || (eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].aukeragarri==0)){
		printf("Maila hortan ezin da matrikulatu ikasle kopurua beteta dagoelako. Sentitzen dugu\n");
	}
	else{
		DATUENMODIFIKAZIOA_batenDatuakSartu(eskolak, gela);
		DATUENMODIFIKAZIOA_ikasgaiakSartu(eskolak, gela);
		eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleKopurua++;
	}
	system("cls");
}

void DATUENMODIFIKAZIOA_eskolakoDatuakModifikatu(ESKOLA eskolak[ESKOLAMAX]){
	//aldagaiak
	int aukera = 0;

	//programa
	printf("Zer aldatu nahi duzu?\n");
	printf("1. Eskolaren izena\n");
	printf("2. Eskolaren helbidea\n");
	printf("3. Eskolaren telefono zenbakia\n");
	printf("4. Atzera\n");
	scanf("%i", &aukera);
		
	switch (aukera){
	case1:
		DATUENMODIFIKAZIOA_eskolakoIzenaModifikatu(eskolak);
		break;
	case2:
		DATUENMODIFIKAZIOA_eskolakoHelbideaModifikatu(eskolak);
		break;
	case3:
		DATUENMODIFIKAZIOA_eskolakoTelefonoaModifikatu(eskolak);
		break;

	default:
		break;
	}
	system("cls");

}

void DATUENMODIFIKAZIOA_ikasleakGeletanBanatu(ESKOLA eskolak[ESKOLAMAX]){

} //hasiera batean funtzio hau ez da egongo erabilgarri

void DATUENMODIFIKAZIOA_gelaFisikoaAsignatu(ESKOLA eskolak[ESKOLAMAX]){
	//aldagaiak
	int i = 0;
	int kont = 1;
	

	//programa
	for (i = 0; i < GELAMAX; i++){
		if (eskolak[eskolak[0].aukeratutakoEskola].gelak[i].ikasleKopurua>0){
			eskolak[eskolak[0].aukeratutakoEskola].gelak[i].gelaId = (((eskolak[0].aukeratutakoEskola + 1) * 1000) + (kont));
			kont++;
		}
	}
	system("cls");

}

void DATUENMODIFIKAZIOA_irakasleakAsignatu(ESKOLA eskolak[ESKOLAMAX]){
	//aldagaiak
	int maila = 0, ikasgaia = 0;
	int i = 0;

	//programa
	maila = BISTARATU_gelaAukeratu(eskolak);

	printf("Zein ikasgaitan jarri nahi duzu irakaslea?\n");
	scanf("%i", &ikasgaia);
	fflush(stdin);
	printf("Zein izen du irakasleak?\n");
	gets_s(eskolak[eskolak[0].aukeratutakoEskola].gelak[maila].irakasleak[ikasgaia - 1].izena,IZENAMAX);
	fflush(stdin);
	printf("Zein abizen du irakasleak?\n");
	gets_s(eskolak[eskolak[0].aukeratutakoEskola].gelak[maila - 1].irakasleak[ikasgaia - 1].abizena, IZENAMAX);
	fflush(stdin); 
	printf("Zein urtetan jaio zen irakaslea?\n");
	scanf("%i", &eskolak[eskolak[0].aukeratutakoEskola].gelak[maila - 1].irakasleak[ikasgaia - 1].data.urtea);
	fflush(stdin);
	printf("Zein hiletan jaio zen irakaslea?\n");
	scanf("%i", &eskolak[eskolak[0].aukeratutakoEskola].gelak[maila - 1].irakasleak[ikasgaia - 1].data.hilea);
	fflush(stdin);
	printf("Zein egunetan jaio zen irakaslea?\n");
	scanf("%i", &eskolak[eskolak[0].aukeratutakoEskola].gelak[maila - 1].irakasleak[ikasgaia - 1].data.eguna);
	fflush(stdin);
	printf("Zein da irakaslearen NAN-a (letra gabe)?\n");
	scanf("%i", &eskolak[eskolak[0].aukeratutakoEskola].gelak[maila - 1].irakasleak[ikasgaia - 1].idal);
	fflush(stdin);

	system("cls");
}

void DATUENMODIFIKAZIOA_tutoreaAsignatu(ESKOLA eskolak[ESKOLAMAX]){
	//aldagaiak
	int maila = 0, ikasgaia = 0;

	//programa
	maila = BISTARATU_gelaAukeratu(eskolak);
	printf("Zein ikasgaitan jarri nahi duzu tutorea?\n");
	scanf("%i", &ikasgaia);
	fflush(stdin);
	printf("Zein izen du tutoreak?\n");
	gets_s(eskolak[eskolak[0].aukeratutakoEskola].gelak[maila].tutorea.izena, IZENAMAX);
	fflush(stdin);
	printf("Zein abizen du tutoreak?\n");
	gets_s(eskolak[eskolak[0].aukeratutakoEskola].gelak[maila].tutorea.abizena, IZENAMAX);
	fflush(stdin);
	printf("Zein urtetan jaio zen tutorea?\n");
	scanf("%i", &eskolak[eskolak[0].aukeratutakoEskola].gelak[maila].tutorea.data.urtea);
	fflush(stdin);
	printf("Zein hiletan jaio zen tutorea?\n");
	scanf("%i", &eskolak[eskolak[0].aukeratutakoEskola].gelak[maila].tutorea.data.hilea);
	fflush(stdin);
	printf("Zein egunetan jaio zen tutorea?\n");
	scanf("%i", &eskolak[eskolak[0].aukeratutakoEskola].gelak[maila].tutorea.data.eguna);
	fflush(stdin);
	printf("Zein da tutorearen NAN-a (letra gabe)?\n");
	scanf("%i", &eskolak[eskolak[0].aukeratutakoEskola].gelak[maila].tutorea.idal);
	fflush(stdin);

	system("cls");
}

void DATUENMODIFIKAZIOA_batenDatuakSartu(ESKOLA eskolak[ESKOLAMAX],int gela){
	//aldagaiak

	//programa
	printf("Zein da ikaslearen izena?\n");
	gets_s(eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleKopurua].izena, IZENAMAX);
	fflush(stdin);
	printf("Zein da ikaslearen abizena?\n");
	gets_s(eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleKopurua].abizena, IZENAMAX);
	fflush(stdin);
	printf("Zein da ikaslearen jaiotze urtea?\n");
	scanf("%i", &eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleKopurua].data.urtea);
	fflush(stdin);
	printf("Zein da ikaslearen jaiotze hilea?\n");
	scanf("%i", &eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleKopurua].data.hilea);
	fflush(stdin);
	printf("Zein da ikaslearen jaiotze eguna?\n");
	scanf("%i", &eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleKopurua].data.eguna);
	fflush(stdin);
	printf("Zein da ikaslearen NAN-a (letra gabe)?\n");
	scanf("%i", &eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleKopurua].idal);
	fflush(stdin);

	system("cls");
}

void DATUENMODIFIKAZIOA_ikaslearenIkasgaiakSartu(ESKOLA eskolak[ESKOLAMAX],int gela){
	//aldagaiak
	int i = 0;
	int segi = 0;
	int aukera = 0;

	//programa
	do{
		segi = 0;
		printf("Zein ikasgai nahi dituzu heman:\n");
		for (i = 0; i < IKASGAIMAX; i++){
			if (eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleKopurua].ikasgaiak[i].aukeratuta == 0){
				printf("%i. %s\n", i+1, eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasgaiak[i].izena);
			}
		}
		scanf("%i", &aukera);
		fflush(stdin);
		aukera = aukera - 1;
		eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleKopurua].ikasgaiak[aukera].aukeratuta = 1;

		for (i = 0; i < IKASGAIMAX; i++){
			if (eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleKopurua].ikasgaiak[i].aukeratuta == 0){
				segi = 1;
			}
		}
		if (segi == 1){
			printf("Beste ikasgairen bat heman nahi duzu? BAI(1)/EZ(0)\n");
			scanf("%i", &segi);
			fflush(stdin);
		}
		system("cls");
	}while (segi == 1);
}

void DATUENMODIFIKAZIOA_ikasgaiakSartu(ESKOLA eskolak[ESKOLAMAX], int gela){
	//aldagaiak
	int kont = 0;
	int i = 0, segi = 1;
	int aukera = 0;
	int jarraitu = 1;

	//programa


	do{
		printf("Sartu nahi duzun ikasgaiaren zenbakia\n");
		for (i = 0; i < IKASGAIMAX; i++){
			if (eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleKopurua].ikasgaiak[i].aukeratuta == 0){

				printf("%i. %s\n", i + 1, eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasgaiak[i].izena);
			}
		}
		scanf("%i", &aukera);
		aukera = aukera - 1;
		if (eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleKopurua].ikasgaiak[aukera].aukeratuta == 1){
			printf("Ikasgai hori aukeratuta daukazu\n");
		}
		if (eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleKopurua].ikasgaiak[aukera].aukeratuta == 0){
			eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleKopurua].ikasgaiak[aukera].aukeratuta = 1;
			eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleKopurua].ikasgaiKopurua++;
			printf("Ikasgai hortan matrikulatu zara\n");
		}
		for (i = 0; i < IKASGAIMAX; i++){
			if (eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleak[eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleKopurua].ikasgaiak[i].aukeratuta == 0){
				segi = 1;
			}
		}
			if (segi == 1){
				printf("Ikasgai gehiago aukeratu nahi dituzu? BAI(1)/EZ(0)\n");
				scanf("%i", &jarraitu);
				fflush(stdin);
				system("cls");
			
		}

	} while (jarraitu == 1);
		
}

void DATUENMODIFIKAZIOA_ikasgaiakSartuAdministrazioa(ESKOLA eskolak[ESKOLAMAX]){
	//aldagaiak
	int kont = 0;
	int maila = 0;
	int i = 0;
	int aukera = 0;
	int jarraitu = 1;

	//programa
	maila = BISTARATU_gelaAukeratu(eskolak);

	for (i = 0; i < IKASGAIMAX; i++){
		printf("%i. ikasgaiaren izena sartu:\n", i + 1);
		gets_s(eskolak[eskolak[0].aukeratutakoEskola].gelak[maila].ikasgaiak[i].izena, IZENAMAX);
		eskolak[eskolak[0].aukeratutakoEskola].gelak[maila].ikasgaiak[i].aukeratuta = 1;
	}
	eskolak[eskolak[0].aukeratutakoEskola].gelak[maila].aukeragarri = 1;
	system("cls");
	
}

void DATUENMODIFIKAZIOA_eskolakoIzenaModifikatu(ESKOLA eskolak[ESKOLAMAX]){
	fflush(stdin);
	printf("Sartu eskolaren izena\n");
	fflush(stdin);
	gets_s(eskolak[eskolak[0].eskolaKopurua].izena, IZENAMAX);
	fflush(stdin);
}

void DATUENMODIFIKAZIOA_eskolakoHelbideaModifikatu(ESKOLA eskolak[ESKOLAMAX]){
	printf("Sartu eskolaren kalea\n");
	gets_s(eskolak[eskolak[0].eskolaKopurua].helbidea.kalea, IZENAMAX);
	fflush(stdin);
	printf("Sartu eskolaren zenbakia\n");
	scanf("%i", &eskolak[eskolak[0].eskolaKopurua].helbidea.zenbakia);
	fflush(stdin);
	printf("Sartu eskolaren posta kodea\n");
	scanf("%i", &eskolak[eskolak[0].eskolaKopurua].helbidea.postaKodea);
	fflush(stdin);
}

void DATUENMODIFIKAZIOA_eskolakoTelefonoaModifikatu(ESKOLA eskolak[ESKOLAMAX]){
	printf("Sartu eskolaren telefono zenbakia\n");
	scanf("%i", &eskolak[eskolak[0].eskolaKopurua].telefonoa);
	fflush(stdin);
}

void DATUENMODIFIKAZIOA_eskolakoMailakJarri(ESKOLA eskolak[ESKOLAMAX]){
	//aldagaiak
	int i = 0;
	int maila = -1;

	//programa
	while ((i < GELAMAX)&&(maila==-1)){
		if (eskolak[eskolak[0].aukeratutakoEskola].gelak[i].aukeragarri == 0){
			maila = i;
		}
		i++;
	}
	printf("Zein da sartu nahi duzun mailaren izena:\n");
	gets_s(eskolak[eskolak[0].aukeratutakoEskola].gelak[maila].maila, IZENAMAX);
	eskolak[eskolak[0].aukeratutakoEskola].gelak[maila].aukeragarri = 1;
}