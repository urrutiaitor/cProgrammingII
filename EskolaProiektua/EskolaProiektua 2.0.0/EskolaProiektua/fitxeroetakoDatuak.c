#include "datuEgiturak.h"
#include "fitxeroetakoDatuak.h"

int datuBaseaIrakurri(ESKOLA *ptr_eskola, USUARIOA **ptr_ptr_usuarioa){
	//aldagaiak
	FILE* fitxeroa;

	USUARIOA aux;
	USUARIOA *ptr_aux;
	USUARIOA aux_usuario;
	USUARIOA *ptr_aux_usuarioa;

	//programa
	if ((fitxeroa = fopen("datuak.dat", "rb")) == NULL){
		printf("Datu basea ezin izan da ireki\n");
	}
	else{
		fread(ptr_eskola, sizeof(ESKOLA), 1, fitxeroa);
		ptr_aux_usuarioa = malloc(sizeof(USUARIOA));
		fread(ptr_aux, sizeof(USUARIOA), 1, fitxeroa);
		*ptr_ptr_usuarioa = ptr_aux_usuarioa;
		*ptr_aux_usuarioa = *ptr_aux;
		ptr_aux_usuarioa->urrengo_ptr = NULL;
		while (fread(ptr_aux, sizeof(USUARIOA), 1, fitxeroa) != NULL){
			ptr_aux_usuarioa->urrengo_ptr = malloc(sizeof(USUARIOA));
			ptr_aux_usuarioa = ptr_aux_usuarioa->urrengo_ptr;
			*ptr_aux_usuarioa = *ptr_aux;
			ptr_aux_usuarioa->urrengo_ptr = NULL;
		}
	}

	//return
	return 1;
}

int datuBaseaIdatzi(ESKOLA *ptr_eskola, USUARIOA **ptr_ptr_usuarioa){
	//aldagaiak
	FILE* fitxeroa;
	USUARIOA *ptr_aux;
	USUARIOA *ptr_aux2;

	//programa

	ptr_aux = *ptr_ptr_usuarioa;

	if ((fitxeroa = fopen("datuak.dat", "wb")) == NULL){
		printf("Datu basean ezin izan da gorde\n");
	}
	else{
		fwrite(ptr_eskola, sizeof(ESKOLA), 1, fitxeroa);
		
		while (ptr_aux != NULL){
			fread(ptr_aux, sizeof(USUARIOA), 1, fitxeroa);
			ptr_aux = ptr_aux->urrengo_ptr;
		}

		ptr_aux = *ptr_ptr_usuarioa;

		while (ptr_aux != NULL){
			ptr_aux2 = ptr_aux->urrengo_ptr;
			free(ptr_aux);
			ptr_aux = ptr_aux2;
		}
	}

	//return
	return 1;
}