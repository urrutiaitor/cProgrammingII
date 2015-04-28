#include "kolaDinamikoa.h"

int lanaBixaldu(LANA **lana_ptr_ptr){
	//aldagaiak
	LANA *aux_ptr;
	LANA *barrixe_ptr;

	//programa
	aux_ptr = (*lana_ptr_ptr);

	if (aux_ptr == NULL){
		aux_ptr = malloc(sizeof (LANA));
		aux_ptr->aurrekoLana = NULL;
		aux_ptr->urrengoLana = NULL;
		if (lanekoDatuk(aux_ptr)){
			(*lana_ptr_ptr) = aux_ptr;
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
		if (lanekoDatuk(barrixe_ptr)){
			return 1;
		}
		else{
			return 0;
		}
	}
}

int kolakoLanakIkusi(LANA **lana_ptr_ptr){
	//aldagaiak
	int kont = 0;
	LANA *aux_ptr;

	//programa

	aux_ptr = (*lana_ptr_ptr);

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

	//programa

	if (*lana_ptr_ptr != NULL){
		if (hasierakuKendu(lana_ptr_ptr)){
			return 1;
		}
	}
	else{
		printf("On momentun ezta lanik impresorako kolan\n");
		fflush(stdin);
		getchar();
		return 1;
	}
}

int fisikokiAurrinJarri(LANA **lana_ptr_ptr){
	//aldagaiak
	int kodigu = 0;
	int *kodigu_ptr;

	//programa
	if (*lana_ptr_ptr != NULL){
		kodigu_ptr = &kodigu;
		printf("Kodigu: ");
		scanf("%i", kodigu_ptr);
		if (!kodigoduneAurrea(lana_ptr_ptr, kodigu_ptr)){
			printf("Zuk ipinitako lana kola hasieran da edo ezta existiuten\n");
			fflush(stdin);
			getchar();
		}
		system("cls");
	}
	else{
		printf("On momentun ezta lanik impresorako kolan\n");
		fflush(stdin);
		getchar();
	}
	

	//bukaera
	return 1;
}

int imprimiuFisikoki(LANA **lana_ptr_ptr){
	//aldagaia
	int kodigu = 0;
	int *kodigu_ptr;
	LANA *aux_ptr;

	//programa
	if (*lana_ptr_ptr != NULL){
		kodigu_ptr = &kodigu;
		aux_ptr = *lana_ptr_ptr;
		printf("Sartu kodigu: ");
		scanf("%i", kodigu_ptr);

		system("cls");

		if (aux_ptr->kodigu == kodigu){
			if (!imprimiutenSimulazioi(*lana_ptr_ptr)){
				printf("Errore bat egonda lana imprimiuten");
				fflush(stdin);
				getchar();
				return 0;
			}
			else{
				if (kodigoduneKendu(lana_ptr_ptr, kodigu_ptr)){
					return 1;
				}
				else{
					return 0;
				}
			}
		}
	}
	else{
		printf("On momentun ezta lanik impresorako kolan\n");
		fflush(stdin);
		getchar();
		return 1;
	}

	//bukaera
	return 1;
}