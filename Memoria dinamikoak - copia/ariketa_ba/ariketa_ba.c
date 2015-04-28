#include "ariketa_ba.h"

int menu(void){
	//aldagaiak
	char str[10];
	int i;

	//programa
	do {
		i = -1;
		printf("\n");
		printf("\t1 : Introducir un nuevo entero a la cabeza de la lista\n");
		printf("\t2 : Buscar un entero en la lista\n");
		printf("\t3 : Eliminar un entero de la lista\n");
		printf("\t4 : Visualizar todos los elementos de la lista\n");
		printf("\t0 : Finalizar programa\n");
		printf("\nOpcion -> ");
		gets(str);
		sscanf(str, "%d", &i);
	} while ((i < 0) || (i > 4));
	
	//bukaera
	return i;
}

ZENBAKIA* hasieranSartu(ZENBAKIA *ptr_hasiera){
	//aldagaiak
	ZENBAKIA* aux_ptr = 0;

	//programa
	aux_ptr = malloc(sizeof(struct zenbakia));
	aux_ptr->urrengo_ptr = ptr_hasiera;

	//return
	return aux_ptr;
}

ZENBAKIA* zenbakiaBilatu(ZENBAKIA *(ptr_hasiera), int zenbakia){
	//aldagaiak

	//programa
	while ((ptr_hasiera->zenbakia != zenbakia) && (ptr_hasiera->urrengo_ptr != NULL)){
		ptr_hasiera = ptr_hasiera->urrengo_ptr;
	}
	if (ptr_hasiera->urrengo_ptr != NULL){
		ptr_hasiera = NULL;
	}


	//return
	return ptr_hasiera;
}

void zenbakiaEzabatu(ZENBAKIA *(ptr_hasiera), int zenbakia){
	//aldagaiak

	//programa
	while ((ptr_hasiera->zenbakia != zenbakia)&&(ptr_hasiera->urrengo_ptr!=NULL)){
		ptr_hasiera = ptr_hasiera->urrengo_ptr;
	}
	if (ptr_hasiera->zenbakia == zenbakia){

	}


	//return
	return ptr_hasiera;
}

void zenbakiakBistaratu(ZENBAKIA *(ptr_hasiera)){
	//aldagaiak

	//programa
	while (ptr_hasiera->urrengo_ptr != NULL){
		printf("%i", ptr_hasiera->zenbakia);
		ptr_hasiera = ptr_hasiera->urrengo_ptr;
	}

	//bukaera
	return 0;
}