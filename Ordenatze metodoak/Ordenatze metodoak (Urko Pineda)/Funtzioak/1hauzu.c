#include "1hauzu.h"

void main(int zbk30[], int zbk50[]){
	int auk = 0, *punauk;
	punauk = &auk;
	printf("\n");
	printf("	30.000 edo 50.000 zenbaki ordenatu nahi dituzu? (30.000 = 1; 50.000 = 0) --> ");
	scanf_s("%i", punauk);
	switch (*punauk){
		case 0:kalkulua50(zbk50);
			break;
		case 1:kalkulua30(zbk30);
			break;
	}
	printf("\n");
	printf("	Zenbakiak ordenaturik gorde nahi dituzu? (BAI = 1; EZ = 0) --> ");
	scanf_s("%i", punauk);
	if (*punauk == 1){
		write(zbk30, zbk50);
		printf("Datuak 'zbk30milaord.dat' eta 'zbk30milaord.dat' fitxeroetan gorde dira.\n");
	}
	printf("\n");
	printf("Sakatu ENTER tekla jarraitzeko...");
	fflush(stdin);
	getchar();
}

void kalkulua30(int zbk30[]){
	int i = 0, k = 1, h = 0;
	int temp = 0;
	for (h = 0; h != MAX_30 - 1; h++){
		k = 1;
		for (i = 0; i != MAX_30 - 1; i++){
			if (zbk30[i] > zbk30[k]){
				temp = zbk30[i];
				zbk30[i] = zbk30[k];
				zbk30[k] = temp;
			}
			k++;
		}
	}
}
void kalkulua50(int zbk50[]){
	int i = 0, k = 1, h = 0;
	int temp = 0;
	for (h = 0; h != MAX_50 - 1; h++){
		k = 1;
		for (i = 0; i != MAX_50 - 1; i++){
			if (zbk50[i] > zbk50[k]){
				temp = zbk50[i];
				zbk50[i] = zbk50[k];
				zbk50[k] = temp;
			}
			k++;
		}
	}
}