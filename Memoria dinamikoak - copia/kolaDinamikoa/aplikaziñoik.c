#include "kolaDinamikoa.h"

int lanaBixaldu(LANA **lana_ptr_ptr){
	//aldagaiak
	LANA *aux_ptr=*lana_ptr_ptr;
	LANA *barrixe_ptr = *lana_ptr_ptr;

	//programa
	if (*lana_ptr_ptr == NULL){
		*lana_ptr_ptr = malloc(sizeof (LANA));
		(*lana_ptr_ptr)->aurrekoLana = NULL;
		(*lana_ptr_ptr)->urrengoLana = NULL;
		if (lanekoDatuk(lana_ptr_ptr)){
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		while (aux_ptr->urrengoLana!=NULL){
			aux_ptr = aux_ptr->urrengoLana;
		}
		aux_ptr->urrengoLana = malloc(sizeof (LANA));
		barrixe_ptr = aux_ptr->urrengoLana;
		barrixe_ptr->aurrekoLana = aux_ptr;
		barrixe_ptr->urrengoLana = NULL;
		if (lanekoDatuk(&barrixe_ptr)){
			return 1;
		}
		else{
			return 0;
		}
	}
}

int kolakoLanakIkusi(LANA **lana_ptr_ptr){
	//aldagaiak
	LANA *aux_ptr = *lana_ptr_ptr;
	int kont = 0;

	//programa
	if (aux_ptr != NULL){
		printf("Momentuz kolan dazen lanak honek di:\n");
	}
	else{
		printf("Momentuz kolan ezta ixe\n");
	}
	while (aux_ptr != NULL){
		kont++;
		printf("%i. %s\n", kont, aux_ptr->ixena);
		aux_ptr = aux_ptr->urrengoLana;
	}
	fflush(stdin);
	getchar();
	system("cls");

	//bukaera
	return 1;
}

int imprimiu(LANA **lana_ptr_ptr){
	//aldagaiak
	LANA *aux_ptr=*lana_ptr_ptr;

	//programa
	
	if (*lana_ptr_ptr != NULL){

		if (!imprimiutenSimulazioi(*lana_ptr_ptr)){
			printf("Errore bat egonda lana imprimiuten");
			return 0;
		}
		else{
			if (hasierakuKendu(lana_ptr_ptr)){
				return 1;
			}
		}
	}
	else{
		printf("On momentun ezta lanik impresorako kolan\n");
		fflush(stdin);
		getchar();
		return 1;
	}
}

int imprimiuFisikoki(LANA **lana_ptr_ptr){

}