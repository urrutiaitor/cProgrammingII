#include "fitxeroetakoDatuak.h"
#include "main.h"

void usuarioenDatuakIrakurri(ESKOLA eskola, USUARIOA **ptr_ptr_usuarioa){
	//aldagaiak
	int i = 0;
	FILE* fitxeroa;
	char izena[IZENAMAX];
	char *ptr_izena;
	ptr_izena = &izena;
	USUARIOA aux;
	USUARIOA *ptr_aux;
	USUARIOA aux_usuario;
	USUARIOA *ptr_aux_usuarioa;

	//programa
	strcat(ptr_izena, &eskola.izena);
	strcat(ptr_izena, ".dat");

	if ((fitxeroa = fopen(izena, "rb")) == NULL){
		printf("Usuarioen datu basea ezin izan da ireki\n");
	}
	else{
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
	return 0;
}