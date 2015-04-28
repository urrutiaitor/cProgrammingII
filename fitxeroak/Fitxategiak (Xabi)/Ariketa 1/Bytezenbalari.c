#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int biteZenbalari(char helbidea[]);

int main(){
	char helbidea[30];
	int total;
	FILE * file;

	printf("Sartu fitxategiaren izena\n");
	fflush(stdin);
	gets(helbidea);

	total = biteZenbalari(helbidea);

	printf("%i bite dauzka zure fitxeroa\n", total);
	
	system("pause");
	return 0;
}

int biteZenbalari(char helbidea[]){
	int kont = 0;
	FILE * file;

	if((file = fopen(helbidea, "rb")) != NULL){
		while(getc(file) != EOF){
			kont++;
		}
	}
	return kont;
}