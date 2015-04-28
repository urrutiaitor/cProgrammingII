#include "ariketa_ab.h"

int main(){
	//aldagaiak
	int aukera = 0;
	int zenb = 0;
	PZENBAKIA *burua = 0;
	PZENBAKIA *bilatutaku = 0;

	//programa
	do {

		printf("1. Zenbaki barri bat sartu zerrenda hasieran\n");
		printf("2. Zenbaki bat bilatu zerrendan\n");
		printf("3. Zenbaki oso bat borra zerrendan\n");
		printf("4. Zerrendako zenbaki guztik bistaratu\n");
		printf("0. Urten\n");
		scanf("%i", &aukera);

		switch (aukera){
		case 1:
			burua = hasieranSartu(burua);
			break;
		case 2:
			if (burua != 0){
				zenb = zenbakia();
				bilatutaku = zenbakiaBilatu(burua, zenb);
				printf("Bilatutako zenbakixe %i helbidin da\n", bilatutaku);
			}
			break;
		case 3:
			if (burua != 0){
				zenb = zenbakia();
				burua = zenbakiaEzabatu(burua, zenb);
			}
			break;
		case 4:
			if (burua != 0){
				zenbakiakBistaratu(burua);
			}
			break;
		}


	} while (aukera!=0);

	//bukaera
	return 0;
}

ZENBAKIA* hasieranSartu(ZENBAKIA *ptr_hasiera){
	//aldagaiak
	ZENBAKIA* aux_ptr = 0;

	//programa

	aux_ptr = malloc(sizeof(struct zenbakia));
	aux_ptr->urrengo_ptr = ptr_hasiera;
	aux_ptr->zenbakia = zenbakia();


	//return
	return aux_ptr;
}

ZENBAKIA* zenbakiaBilatu(ZENBAKIA *ptr_hasiera, int zenbakia){
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

ZENBAKIA* zenbakiaEzabatu(ZENBAKIA *ptr_hasiera, int zenbakia){
	//aldagaiak
	ZENBAKIA* aux_ptr = ptr_hasiera;
	ZENBAKIA* aurrekoa_ptr = ptr_hasiera;
	int segi = 1;

	//programa

	while (aux_ptr->urrengo_ptr != NULL){
		if (ptr_hasiera->zenbakia == zenbakia){
			free(ptr_hasiera);
			ptr_hasiera = ptr_hasiera->urrengo_ptr;
		}
		else{
			if (aux_ptr->urrengo_ptr->zenbakia == zenbakia){
				free(aux_ptr->urrengo_ptr);
				aux_ptr->urrengo_ptr = aux_ptr->urrengo_ptr->urrengo_ptr;
			}
			else{
				aux_ptr = aux_ptr->urrengo_ptr;
			}
		}
	}

	//return
	return ptr_hasiera;
}

void zenbakiakBistaratu(ZENBAKIA *ptr_hasiera){
	//aldagaiak
	int segi = 1;

	//programa
	while (segi == 1){
		printf("%i\n", ptr_hasiera->zenbakia);
		if (ptr_hasiera->urrengo_ptr == NULL){
			segi = 0;
		}
		if (ptr_hasiera->urrengo_ptr != NULL){
			ptr_hasiera = ptr_hasiera->urrengo_ptr;
		}
	}
	

	//bukaera
	return 0;
}

int zenbakia(){
	//aldagaiak
	int zenbakia = 0;

	//programa
	printf("Zenbakixe: ");
	scanf("%i", &zenbakia);

	//return
	return zenbakia;
}