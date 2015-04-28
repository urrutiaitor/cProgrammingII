#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

#define HELBIDEA "a.txt"

void zenbakiakIrakurri(char helbidea[]);

int main(){
	char helbidea[30] = HELBIDEA;

	zenbakiakIrakurri(helbidea);
	
	system("pause");
	return 0;
}

void zenbakiakIrakurri(char helbidea[]){
	FILE *file;
	int aukera;

	if((file = fopen(helbidea,"wb")) != NULL){
		printf("Zartu zenbaki bat, amaitzeko sartu 0 zenbakia\n");
		do{
			fflush(stdin);
			scanf("%i", &aukera);
			fprintf(file, "%i ", aukera);
		}while(aukera != 0);
	}
}