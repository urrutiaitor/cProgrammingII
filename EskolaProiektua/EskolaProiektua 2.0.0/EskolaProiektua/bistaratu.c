#include "datuEgiturak.h"
#include "bistaratu.h"

//
void BISTARATU_notakBistaratuIkaslearentzat(USUARIOA *ptr_usuarioa){
	//aldagaiak
	int i = 0;

	//programa
	for (i = 0; i < IKASGAIMAX; i++){
		if (ptr_usuarioa->ikasgaiak[i].id != NULL){
			printf("%s: %.2f\n", ptr_usuarioa->ikasgaiak[i].izena, ptr_usuarioa->ikasgaiak[i].nota);
		}
	}
	getchar();
	fflush(stdin);
	system("cls");

}
//
void BISTARATU_ikaslearenBatezbestekoa(USUARIOA *ptr_usuarioa){
	//aldagaiak
	int i = 0;
	float totala = 0;
	float kantitatea = 0;
	float media = 0;

	//programa
	for (i = 0; i < IKASGAIMAX; i++){
		if (ptr_usuarioa->ikasgaiak[i].id != NULL){
			kantitatea++;
			totala = totala + ptr_usuarioa->ikasgaiak[i].nota;
		}
	}
	media = totala / kantitatea;

	printf("%i ikasgaien arteko batezbestekoa: %.2f", kantitatea, media);

	getchar();
	fflush(stdin);
	system("cls");
}
//
void BISTARATU_taldekoIkasgaikoBatezbestekoa(ESKOLA *ptr_eskola, USUARIOA **ptr_ptr_usuarioa){
	//aldagaiak
	float batura = 0;
	int kopurua = 0;
	float batezbestekoa = 0;
	USUARIOA *ptr_aux;
	int ikasgaia = 0;
	int i = 0;

	//programa
	ptr_aux = *ptr_ptr_usuarioa;

	printf("Zein da batezbesteko ikusi nahi duzun ikasgaia:\n");
	for (i = 0; i < IKASGAIMAX; i++){
		if (ptr_eskola->ikasgaiak[i].id != NULL){
			printf("%i. %s\n", i + 1, ptr_eskola->ikasgaiak[i].izena);
		}
	}
	scanf(&ikasgaia);
	ikasgaia--;

	while (ptr_aux != NULL){
		if (ptr_aux->ikasgaiak[ikasgaia].id != NULL){
			kopurua++;
			batura = batura + ptr_aux->ikasgaiak[ikasgaia].nota;
		}
		ptr_aux = ptr_aux->urrengo_ptr;
	}

	batezbestekoa = batura / kopurua;
	printf("%i ikasleren batezbesteko ikasgaian: %.2f\n \n", kopurua, batezbestekoa);
	getchar();
	fflush(stdin);
	system("cls");
}
//
void BISTARATU_taldekoBatezbestekoa(ESKOLA *ptr_eskola, USUARIOA **ptr_ptr_usuarioa){
	//aldagaiak
	float batura = 0;
	int kopurua = 0;
	float batezbestekoa = 0;
	USUARIOA *ptr_aux;
	int i = 0;

	//programa
	ptr_aux = *ptr_ptr_usuarioa;

	while (ptr_aux != NULL){
		for (i = 0; i < IKASGAIMAX; i++){
			if (ptr_aux->ikasgaiak[i].id != NULL){
				kopurua++;
				batura = batura + ptr_aux->ikasgaiak[i].nota;
			}
		}
		ptr_aux = ptr_aux->urrengo_ptr;
	}

	batezbestekoa = batura / kopurua;
	printf("%i ikasleren batezbesteko ikasgai guztietan: %.2f\n \n", kopurua, batezbestekoa);
	getchar();
	fflush(stdin);
	system("cls");

}