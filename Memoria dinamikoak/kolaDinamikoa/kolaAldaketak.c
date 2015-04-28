#include "kolaDinamikoa.h"

int hasierakuKendu(LANA **lana_ptr_ptr){
	//aldagaiak
	LANA *aux_ptr;
	LANA *ptr;

	//programa
	aux_ptr = *lana_ptr_ptr;

	while ((aux_ptr != NULL)&&(aux_ptr->kodigu != 1)){
		aux_ptr = aux_ptr->urrengoLana;
	}

	if (aux_ptr != NULL){
		if (aux_ptr->kodigu == 1){
			if (!imprimiutenSimulazioi(aux_ptr)){
				printf("Papera falta da impresoran\n");
				fflush(stdin);
				getchar();
				return 0;
			}
			if (aux_ptr->aurrekoLana == NULL){
				*lana_ptr_ptr = NULL;
			}
			if (aux_ptr->aurrekoLana != NULL){
				aux_ptr->aurrekoLana->urrengoLana = aux_ptr->urrengoLana;
			}
			if (aux_ptr->urrengoLana == NULL){
				if (aux_ptr->aurrekoLana != NULL){
					aux_ptr->aurrekoLana->urrengoLana = aux_ptr->urrengoLana;
				}
			}
			if (aux_ptr->urrengoLana != NULL){
				aux_ptr->urrengoLana->aurrekoLana = aux_ptr->aurrekoLana;
			}


			ptr = aux_ptr;
			aux_ptr = aux_ptr->urrengoLana;
			free(ptr);
		}
	}
	else{
		printf("Ezta 1 kodigoko lanik kolan\n");
		fflush(stdin);
		getchar();
	}

	system("cls");

	//bukaera
	return 1;
}

int kodigoduneAurrea(LANA **lana_ptr_ptr, int *kodigu_ptr){
	//aldagaiak
	LANA *aux_ptr;
	LANA *imprimiuteku_ptr;
	LANA *bigarrena_ptr;

	//programa
	aux_ptr = *lana_ptr_ptr;

	bigarrena_ptr = aux_ptr->urrengoLana;

	while (aux_ptr != NULL){
		if (aux_ptr->kodigu == *kodigu_ptr){
			imprimiuteku_ptr = aux_ptr;
			break;
		}
		aux_ptr = aux_ptr->urrengoLana;
	}

	aux_ptr = *lana_ptr_ptr;

	if ((imprimiuteku_ptr == aux_ptr) || (imprimiuteku_ptr == bigarrena_ptr)){
		return 0;
	}
	else{
		imprimiuteku_ptr->aurrekoLana->urrengoLana = imprimiuteku_ptr->urrengoLana;
		if (imprimiuteku_ptr->urrengoLana != NULL){
			imprimiuteku_ptr->urrengoLana->aurrekoLana = imprimiuteku_ptr->aurrekoLana;
		}

		aux_ptr->urrengoLana = imprimiuteku_ptr;
		imprimiuteku_ptr->aurrekoLana = aux_ptr;

		imprimiuteku_ptr->urrengoLana = bigarrena_ptr;
		bigarrena_ptr->aurrekoLana = imprimiuteku_ptr;

		return 1;
	}
}

int kodigoduneKendu(LANA **lana_ptr_ptr, int *kodigu_ptr){
	//aldagaiak
	LANA *aux_ptr;

	//programa
	aux_ptr = *lana_ptr_ptr;

	if (aux_ptr->kodigu == *kodigu_ptr){
		(*lana_ptr_ptr) = (*lana_ptr_ptr)->urrengoLana;
		free(aux_ptr);
		return 1;
	}
	else{
		return 0;
	}
}