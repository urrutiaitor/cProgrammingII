#include <stdio.h>

void visuDec2binary(int n);
void visuDec2binary8(int n);

int main(){
	//aldagaiak
	int zenbakia = 0;

	//programa
	printf("Sartu zenbaki bat 256 baino txikiagoa: ");
	scanf("%i", &zenbakia);

	visuDec2binary(zenbakia);
	printf("\n");

	visuDec2binary8(zenbakia);
	printf("\n");


	//bukaera
	printf("Sakatu ENTER programa bukatzeko");
	fflush(stdin);
	getchar();
	return 0;
}

void visuDec2binary(int n){
	//aldagaiak
	
	//programa
	if ((n / 2) > 0){
		printf("1");
		visuDec2binary(n % 2);
	}
	if (((n / 2) <= 0) && (n>0)){
		printf("0");
		visuDec2binary(n);
	}
	
	//bukaera
	return 0;
}

void visuDec2binary8(int n){

}