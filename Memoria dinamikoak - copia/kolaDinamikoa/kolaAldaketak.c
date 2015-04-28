#include "kolaDinamikoa.h"

int hasierakuKendu(LANA **lana_ptr_ptr){
	//aldagaiak
	LANA *aux_ptr = *lana_ptr_ptr;

	//programa
	*lana_ptr_ptr = &aux_ptr->urrengoLana;
	free(aux_ptr);

	//bukaera
	return 1;
}

int ixenazKendu(LANA **lana_ptr_ptr, char *ixena){
	//aldagaiak

	//programa
	
	//return
	return 1;
}