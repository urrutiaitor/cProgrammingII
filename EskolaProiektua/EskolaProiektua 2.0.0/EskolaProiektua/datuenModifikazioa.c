#include "datuEgiturak.h"
#include "datuenModifikazioa.h"

//
int DATUENMODIFIKAZIOA_eskolakoDatuakModifikatu(ESKOLA *ptr_eskola){
	//aldagaiak
	int aukera = 0;

	//programa

	do{
		printf("Zer datu nahi duzu sartu?\n");
		printf("1. Eskolaren izena\n");
		printf("2. Eskolaren helbidea\n");
		printf("3. Eskolaren telefono zenbakia\n");
		printf("4. Atzera\n");
		scanf("%i", &aukera);

		switch (aukera){
		case1:
			DATUENMODIFIKAZIOA_eskolakoIzenaModifikatu(ptr_eskola);
			break;
		case2:
			DATUENMODIFIKAZIOA_eskolakoHelbideaModifikatu(ptr_eskola);
			break;
		case3:
			DATUENMODIFIKAZIOA_eskolakoTelefonoaModifikatu(ptr_eskola);
			break;

		default:
			break;
		}
		system("cls");
	} while (aukera != 0);

}
//
int DATUENMODIFIKAZIOA_eskolakoIzenaModifikatu(ESKOLA *ptr_eskola){
	fflush(stdin);
	printf("Sartu eskolaren izena\n");
	fflush(stdin);
	gets_s(ptr_eskola->izena, IZENAMAX);
	fflush(stdin);
}
//
int DATUENMODIFIKAZIOA_eskolakoHelbideaModifikatu(ESKOLA *ptr_eskola){
	printf("Sartu eskolaren kalea\n");
	gets_s(ptr_eskola->helbidea.kalea, IZENAMAX);
	fflush(stdin);
	printf("Sartu eskolaren zenbakia\n");
	scanf("%i", &ptr_eskola->helbidea.zenbakia);
	fflush(stdin);
	printf("Sartu eskolaren posta kodea\n");
	scanf("%i", &ptr_eskola->helbidea.postaKodea);
	fflush(stdin);
}
//
int DATUENMODIFIKAZIOA_eskolakoTelefonoaModifikatu(ESKOLA *ptr_eskola){
	printf("Sartu eskolaren telefono zenbakia\n");
	scanf("%i", &ptr_eskola->telefonoa);
	fflush(stdin);
}
//
int DATUENMODIFIKAZIOA_ikasgaiakSartuAdministrazioa(ESKOLA *ptr_eskola){
	//aldagaiak
	int kont = 0;
	int maila = 0;
	int i = 0;
	int aukera = 0;
	int jarraitu = 1;

	//programa
	printf("Momentuz sortuta dauden ikasgaiak hauek dira:\n");

	for (i = 0; i < IKASGAIMAX; i++){
		if (ptr_eskola->ikasgaiak[i].id!=0){
			printf("%i. %s\n", ptr_eskola->ikasgaiak[i].id, ptr_eskola->ikasgaiak[i]);
		}
		else{
			break;
		}
	}
	printf("Ikasgai berriaren izena sartu: ");
	gets_s(ptr_eskola->ikasgaiak[i].izena, IZENAMAX);
	ptr_eskola->ikasgaiak[i].id = i + 1;

	system("cls");

}
//
int DATUENMODIFIKAZIOA_usuarioBatSartu(ESKOLA *ptr_eskola, USUARIOA **ptr_ptr_usuarioa){
	//aldagaiak
	int i = 0;
	int gela = 0;
	USUARIOA *ptr_aux;

	//programa
	ptr_aux = *ptr_ptr_usuarioa;
	if (ptr_aux == NULL){
		ptr_aux = malloc(sizeof(USUARIOA));
		ptr_aux->urrengo_ptr = NULL;
	}
	else{
		while (ptr_aux->urrengo_ptr != NULL){
			ptr_aux = ptr_aux->urrengo_ptr;
		}
		ptr_aux->urrengo_ptr = malloc(sizeof(USUARIOA));
		ptr_aux = ptr_aux->urrengo_ptr;
		ptr_aux->urrengo_ptr = NULL;
	}
	
	

	DATUENMODIFIKAZIOA_usuarioarenDatuakSartu(ptr_aux);
	DATUENMODIFIKAZIOA_ikaslearenIkasgaiakSartu(ptr_eskola, ptr_aux);

	system("cls");
}
//
int DATUENMODIFIKAZIOA_usuarioarenDatuakSartu(USUARIOA *ptr_usuarioa){
	//aldagaiak

	//programa
	fflush(stdin);
	printf("Zein da ikaslearen izena?\n");
	gets_s(ptr_usuarioa->izena, IZENAMAX);
	fflush(stdin);
	printf("Zein da ikaslearen abizena?\n");
	gets_s(ptr_usuarioa->abizena, IZENAMAX);
	fflush(stdin);
	printf("Zein da ikaslearen jaiotze urtea?\n");
	scanf("%i", &(ptr_usuarioa->data.urtea));
	fflush(stdin);
	printf("Zein da ikaslearen jaiotze hilea?\n");
	scanf("%i", &(ptr_usuarioa->data.hilea));
	fflush(stdin);
	printf("Zein da ikaslearen jaiotze eguna?\n");
	scanf("%i", &(ptr_usuarioa->data.eguna));
	fflush(stdin);
	printf("Zein da ikaslearen NAN-a (letra gabe)?\n");
	scanf("%i", &(ptr_usuarioa->erabiltzailea));
	fflush(stdin);
	printf("Zein da ikaslearen pasahitza (4 zenbaki)?\n");
	scanf("%i", &(ptr_usuarioa->pasahitza));
	fflush(stdin);

	system("cls");
}
//
int DATUENMODIFIKAZIOA_irakasleakAsignatu(ESKOLA *ptr_eskola, USUARIOA **ptr_ptr_usuarioa){
	//aldagaiak
	int i = 1;
	int t = 0;
	int irakasgaia = 0;
	USUARIOA *ptr_aux;

	//programa
	printf("Irakasten diren irakasgaiak (aukeratu bat):\n");
	for (t = 0; t < IKASGAIMAX; t++){
		if (ptr_eskola->ikasgaiak[i].id != NULL){
			printf("%i. %s", t + 1, ptr_eskola->ikasgaiak[i].izena);
		}
		else{
			break;
		}
	}
	fflush(stdin);
	scanf("%i", &irakasgaia);
	fflush(stdin);
	irakasgaia--;

	ptr_aux = *ptr_ptr_usuarioa;
	printf("Aukeratu irakasle bat irakasgai hortarako: (parentesi arteko zenbakia jarri)\n");
	while (ptr_aux != NULL){
		if (ptr_aux->mota == 2){
			printf("%i. %s %s (%i)", i, ptr_aux->izena, ptr_aux->abizena, ptr_aux->erabiltzailea);
		}
		ptr_aux = ptr_aux->urrengo_ptr;
	}
	scanf("%i", &(ptr_eskola->ikasgaiak[irakasgaia].irakaslea));
	fflush(stdin);

	system("cls");
}
//
int DATUENMODIFIKAZIOA_ikaslearenIkasgaiakSartu(ESKOLA *ptr_eskola, USUARIOA *ptr_usuarioa){
	//aldagaiak
	int i = 0;
	int segi = 0;
	int aukera = 0;

	//programa
	printf("Jarri 1(BAI)/0(EZ) heman nahi duzun ikasgaien ondoan:\n");

	for (i = 0; i < IKASGAIMAX; i++){
		if (ptr_eskola->ikasgaiak[i].id != NULL){
			printf("%i. %s: ", i + 1, ptr_eskola->ikasgaiak[i].izena);
			scanf("%i", &(ptr_usuarioa->ikasgaiak[i].id));
			fflush(stdin);
		}
		else{
			break;
		}
	}
	system("cls");
	return 1;
}
//
int DATUENMODIFIKAZIOA_notakSartu(ESKOLA *ptr_eskola, USUARIOA **ptr_ptr_usuarioa, USUARIOA *ptr_usuarioa){
	//aldagaiak
	int i = 0;
	int ikasgaia = 0;
	USUARIOA *ptr_aux;

	//programa
	printf("Zein ikasgaitan nahi duzu sartu?\n");
	for (i = 0; i < IKASGAIMAX; i++){
		if (ptr_eskola->ikasgaiak[i].irakaslea == ptr_usuarioa->erabiltzailea){
			printf("%i. %s: ", i + 1, ptr_eskola->ikasgaiak[i].izena);
		}
	}
	scanf("%i", &ikasgaia);
	fflush(stdin);
	ikasgaia--;

	printf("Joan ikasleen notak sartzen:\n");
	while (ptr_aux != NULL){
		if (ptr_aux->mota == 3){
			printf("%s %s: ", ptr_aux->izena, ptr_aux->abizena);
			scanf("%f", ptr_aux->ikasgaiak[ikasgaia].nota);
		}
		ptr_aux = ptr_aux->urrengo_ptr;
	}

	system("cls");
	return 1;
}