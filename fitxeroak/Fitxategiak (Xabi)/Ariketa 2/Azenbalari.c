#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int aZenbalari(char helbidea[]);

int main(){
	char helbidea[30];
	int total;
	FILE * file;

	printf("Sartu fitxategiaren izena\n");
	fflush(stdin);
	gets(helbidea);

	total = aZenbalari(helbidea);

	printf("%i a dauzka zure fitxeroa\n", total);
	
	system("pause");
	return 0;
}

int aZenbalari(char helbidea[]){
	int kont = 0;
	char kar;
	FILE * file;

	if((file = fopen(helbidea, "rb")) != NULL){
		do{
			kar = getc(file);
			if(kar == 'a' || kar == 'A'){
				kont++;
			}
		}while(kar != EOF);
	}
	return kont;
}