#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

void zenbakiakIrakurri(char helbidea[], int aukera[]);

int main(){
	char helbidea[30];
	int aukera[100], i = 0;

	printf("Idatzi fitxategiaren izena\n");
	fflush(stdin);
	gets(helbidea);

	zenbakiakIrakurri(helbidea, aukera);

	do{
		printf("%i\n", aukera[i]);
		i++;
	}while(aukera[i - 1] != 0);
	
	system("pause");
	return 0;
}

void zenbakiakIrakurri(char helbidea[], int aukera[]){
	FILE *file;
	int i = 0;

	if((file = fopen(helbidea,"r")) != NULL){
		do{
			fscanf(file,"%i", &aukera[i]);
			i++;
		}while(aukera[i-1] != 0);
	}
}