#include "kolaDinamikoa.h"

int main(){
	//aldagaiak
	LANA *lana_ptr = 0;
	LANA **lana_ptr_ptr = &lana_ptr;

	//programa
	system("color E");

	if (!menu(lana_ptr_ptr)){
		printf("Failed\n");
	}

	//bukaera
	return 0;
}

int menuBistaratu(int *aukera_ptr){
	//programa
	printf("1. Lan bat bixaldu inpresora\n");
	printf("2. Kolako lanak zeintzuk dizen ikusi\n");
	printf("3. Imprimiu\n");
	printf("4. Lan bat imprimiu fisikoki\n");
	printf("0. Urten\n");
	printf("Aukera: ");
	scanf("%i", aukera_ptr);

	system("cls");

	//return
	return 1;
}

int menu(LANA **lana_ptr_ptr){
	//aldagaiak
	int aukera = 0;
	int *aukera_ptr = &aukera;
	int i = 0;

	//programa
	do{
		system("cls");
		if (menuBistaratu(aukera_ptr)){
			switch (aukera){
			case 1:
				if (!lanaBixaldu(lana_ptr_ptr)){
					printf("Zure aukeri ezin ixanda ondo ein\n");
				}
				break;
			case 2:
				if (!kolakoLanakIkusi(lana_ptr_ptr)){
					printf("Zure aukeri ezin ixanda ondo ein\n");
				}
				break;
			case 3:
				if (!imprimiu(lana_ptr_ptr)){
					printf("Zure aukeri ezin ixanda ondo ein\n");
				}
				break;
			case 4:
				if (!imprimiuFisikoki(lana_ptr_ptr)){
					printf("Zure aukeri ezin ixanda ondo ein\n");
				}
				break;
			case 0:
				for (i = 0; i < 3; i++){
					system("cls");
					printf("Amataten");
					Sleep(400);
					system("cls");
					printf("Amataten.");
					Sleep(400);
					system("cls");
					printf("Amataten..");
					Sleep(400);
					system("cls");
					printf("Amataten...");
					Sleep(400);
				}
				break;
			}
		}
		else{
			printf("Menun aukeratzeko ordun arazon bat egonda\n");
			return 0;
		}
	} while (aukera != 0);

	//bukaera
	return 1;
}

void data(DATA *data){
	//aldagaiak
	struct tm *ordu;
	time_t segunduk;

	//programa

	segunduk = time(NULL); /* obtiene los segundos desde 1-1-1970 */
	ordu = localtime(&segunduk); /* convierte los 'segundos' en la hora local */

	data->urti = ordu->tm_year + 1900;
	data->illi = ordu->tm_mon + 1;
	data->egune = ordu->tm_mday;
	data->ordu = ordu->tm_hour;
	data->minutu=ordu->tm_min;
	data->segundu = ordu->tm_sec;

	//bukaera
	return 0;
}

int lanekoDatuk(LANA **lana_ptr_ptr){
	//aldagaiak

	//programa
	printf("Zure usuaxo moti (1(ordenadoretik)/2(fisikoki)): ");
	scanf("%i", &(*lana_ptr_ptr)->usuaxu);

	printf("Lanan ixena: ");
	fflush(stdin);
	gets_s((*lana_ptr_ptr)->ixena, IZENA);

	printf("Ze tamañoko lana da (orrialde kantidadi): ");
	scanf("%i", &(*lana_ptr_ptr)->tamañu);

	data(&((*lana_ptr_ptr)->data));

	system("cls");

	//bukaera
	return 1;
}

int imprimiutenSimulazioi(LANA *lana_ptr){
	//aldagaiak
	int i = 0, j = 0;
	int k = 0, m = 0;

	//programa
	for (i = 0; i < lana_ptr->tamañu; i++){
		printf("[");
		for (j = 0; j < lana_ptr->tamañu; j++){
			if (j <= i){
				printf(".");
			}
			else{
				printf(" ");
			}
		}
		printf("]");
		Sleep(1000);
		system("cls");
	}
	

	//return
	return 1;
}