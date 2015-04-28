#include "main.h"
#include "datuenModifikazioa.h"

void DATUENMODIFIKAZIOA_eskolakoDatuakSartu(ESKOLA *eskola_ptr){
	//aldagaiak

	//programa
	DATUENMODIFIKAZIOA_eskolakoIzenaModifikatu(eskola_ptr);

	DATUENMODIFIKAZIOA_eskolakoHelbideaModifikatu(eskola_ptr);
	
	DATUENMODIFIKAZIOA_eskolakoTelefonoaModifikatu(eskola_ptr);

	system("cls");
}

void DATUENMODIFIKAZIOA_notakSartu(USUARIOA **usuarioa_ptr_ptr, ESKOLA **eskola_ptr_ptr){
	//aldagaiak
	IRAKASLEA irakaslea;
	IKASLEA ikasleak[eskola.ikasleak];
	int i = 0;
	int ikasgaia = 0;

	//programa
	irakaslea = irakasleaDatuakIrakurri(usuarioa_ptr_ptr, eskola_ptr_ptr);
	ikasleakDatuakIrakurri(usuarioa_ptr_ptr, eskola_ptr_ptr);

	printf("Zein ikasgaitan nahi duzu sartu?\n");
	for (i = 0; i < IKASGAIMAX; i++){
		if (irakaslea.ikasgaiak[i].aukeratuta==1){
			printf("%i. %s\n", i + 1, irakaslea.ikasgaiak[i].izena);
		}
	}
	scanf("%i", &ikasgaia);
	fflush(stdin);
	ikasgaia = ikasgaia - 1;

	printf("Joan ikasleen notak sartzen:\n");
	for (i = 0; i < IKASLEAKMAX; i++){
		if (ikasleak[i].ikasgaiak[ikasgaia].aukeratuta == 1){
			printf("%s %s:\n", ikasleak[i].izena, ikasleak[i].abizena);
			scanf("%f", &ikasleak[i].ikasgaiak[ikasgaia].nota);
			fflush(stdin);
		}
	}
	system("cls");

}
//
void DATUENMODIFIKAZIOA_ikasleBatSartu(USUARIOA **usuarioa_ptr_ptr, ESKOLA **eskola_ptr_ptr){
	//aldagaiak
	int i = 0;
	int gela = 0;

	//programa
	gela = BISTARATU_gelaAukeratu(usuarioa_ptr_ptr,eskola_ptr_ptr);
	if ((eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleKopurua >= IKASLEAKMAX) || (eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].aukeragarri==0)){
		printf("Maila hortan ezin da matrikulatu ikasle kopurua beteta dagoelako. Sentitzen dugu\n");
	}
	else{
		DATUENMODIFIKAZIOA_batenDatuakSartu(usuarioa_ptr_ptr,eskola_ptr_ptr);
		DATUENMODIFIKAZIOA_ikasgaiakSartu(usuarioa_ptr_ptr, eskola_ptr_ptr);
		eskolak[eskolak[0].aukeratutakoEskola].gelak[gela].ikasleKopurua++;
	}
	system("cls");
}

void DATUENMODIFIKAZIOA_eskolakoDatuakModifikatu(USUARIOA **usuarioa_ptr_ptr, ESKOLA **eskola_ptr_ptr){
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
		DATUENMODIFIKAZIOA_eskolakoIzenaModifikatu(eskola_ptr);
		break;
	case2:
		DATUENMODIFIKAZIOA_eskolakoHelbideaModifikatu(eskola_ptr);
		break;
	case3:
		DATUENMODIFIKAZIOA_eskolakoTelefonoaModifikatu(eskola_ptr);
		break;

	default:
		break;
	}
	system("cls");

}

void DATUENMODIFIKAZIOA_ikasleakGeletanBanatu(USUARIOA **usuarioa_ptr_ptr, ESKOLA **eskola_ptr_ptr){

} //hasiera batean funtzio hau ez da egongo erabilgarri

void DATUENMODIFIKAZIOA_gelaFisikoaAsignatu(USUARIOA **usuarioa_ptr_ptr, ESKOLA **eskola_ptr_ptr){
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

void DATUENMODIFIKAZIOA_irakasleakAsignatu(USUARIOA **usuarioa_ptr_ptr, ESKOLA **eskola_ptr_ptr){
	//aldagaiak
	int maila = 0, ikasgaia = 0;
	int i = 0;

	//programa
	maila = BISTARATU_gelaAukeratu(usuarioa_ptr_ptr, ESKOLA **eskola_ptr_ptr);

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

void DATUENMODIFIKAZIOA_tutoreaAsignatu(USUARIOA **usuarioa_ptr_ptr, ESKOLA **eskola_ptr_ptr){
	//aldagaiak
	int maila = 0, ikasgaia = 0;

	//programa
	maila = BISTARATU_gelaAukeratu(usuarioa_ptr_ptr, eskola_ptr_ptr);
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

void DATUENMODIFIKAZIOA_batenDatuakSartu(USUARIOA **usuarioa_ptr_ptr, ESKOLA **eskola_ptr_ptr){
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

void DATUENMODIFIKAZIOA_ikaslearenIkasgaiakSartu(USUARIOA **usuarioa_ptr_ptr, ESKOLA **eskola_ptr_ptr){
	//aldagaiak
	int i = 0;
	int segi = 0;
	int aukera = 0;

	//programa
	do{
		segi = 0;
		printf("Zein ikasgai nahi dituzu eman:\n");
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
			printf("Beste ikasgairen bat eman nahi duzu? BAI(1)/EZ(0)\n");
			scanf("%i", &segi);
			fflush(stdin);
		}
		system("cls");
	}while (segi == 1);
}

void DATUENMODIFIKAZIOA_ikasgaiakSartu(USUARIOA **usuarioa_ptr_ptr, ESKOLA **eskola_ptr_ptr){
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

void DATUENMODIFIKAZIOA_ikasgaiakSartuAdministrazioa(USUARIOA **usuarioa_ptr_ptr, ESKOLA **eskola_ptr_ptr){
	//aldagaiak
	int kont = 0;
	int maila = 0;
	int i = 0;
	int aukera = 0;
	int jarraitu = 1;

	//programa
	maila = BISTARATU_gelaAukeratu(usuarioa_ptr_ptr, eskola_ptr_ptr);

	for (i = 0; i < IKASGAIMAX; i++){
		printf("%i. ikasgaiaren izena sartu:\n", i + 1);
		gets_s(eskolak[eskolak[0].aukeratutakoEskola].gelak[maila].ikasgaiak[i].izena, IZENAMAX);
		eskolak[eskolak[0].aukeratutakoEskola].gelak[maila].ikasgaiak[i].aukeratuta = 1;
	}
	eskolak[eskolak[0].aukeratutakoEskola].gelak[maila].aukeragarri = 1;
	system("cls");
	
}

void DATUENMODIFIKAZIOA_eskolakoIzenaModifikatu(ESKOLA *eskola_ptr){
	fflush(stdin);
	printf("Sartu eskolaren izena\n");
	fflush(stdin);
	gets_s(eskola_ptr->izena, IZENAMAX);
	fflush(stdin);
}

void DATUENMODIFIKAZIOA_eskolakoHelbideaModifikatu(ESKOLA *eskola_ptr){
	printf("Sartu eskolaren kalea\n");
	gets_s(eskola_ptr->helbidea.kalea, IZENAMAX);
	fflush(stdin);
	printf("Sartu eskolaren zenbakia\n");
	scanf("%i", &eskola_ptr->helbidea.zenbakia);
	fflush(stdin);
	printf("Sartu eskolaren posta kodea\n");
	scanf("%i", &eskola_ptr->helbidea.postaKodea);
	fflush(stdin);
}

void DATUENMODIFIKAZIOA_eskolakoTelefonoaModifikatu(ESKOLA *eskola_ptr){
	printf("Sartu eskolaren telefono zenbakia\n");
	scanf("%i", &eskola_ptr->telefonoa);
	fflush(stdin);
}

void DATUENMODIFIKAZIOA_eskolakoMailakJarri(USUARIOA **usuarioa_ptr_ptr, ESKOLA **eskola_ptr_ptr){
	//aldagaiak
	int i = 0;
	int maila = -1;

	//programa
	while ((i < GELAMAX)&&(maila==-1)){
		if ((*eskola_ptr_ptr)->gelak[i].aukeragarri == 0){
			maila = i;
		}
		i++;
	}
	printf("Zein da sartu nahi duzun mailaren izena:\n");
	gets_s(eskola[eskolak[0].aukeratutakoEskola].gelak[maila].maila, IZENAMAX);
	eskolak[eskola[0].aukeratutakoEskola].gelak[maila].aukeragarri = 1;
}