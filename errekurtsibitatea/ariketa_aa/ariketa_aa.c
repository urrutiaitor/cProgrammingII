#include <stdio.h>
#include <stdlib.h>

int faktoriala(int zenbakia);

int main(){
	//aldagaiak
	int zenbakia = 0;

	//programa
	printf("Zein zenbakiren faktoriala egin nahi duzu?\n");
	scanf("%i", &zenbakia);

	zenbakia = faktoriala(zenbakia);

	printf("Faktoriala %i da\n", zenbakia);

	//bukaera
	printf("Sakatu ENTER programa bukatzeko");
	fflush(stdin);
	getchar();
	return 0;
}

int faktoriala(int zenbakia){
	//aldagaiak
	int ret = 1;

	//programa
	if (zenbakia != 1){
		ret = faktoriala(zenbakia - 1);
	}

	ret = ret*zenbakia;

	//return
	return ret;
}