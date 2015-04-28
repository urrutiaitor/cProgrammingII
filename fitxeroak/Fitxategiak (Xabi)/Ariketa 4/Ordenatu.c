#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int zenbakiakIrakurri(char helbidea[], int lista[]);
void zenbakiakOrdenatu(int lista[], int kont);
void zenbakiakIdatzi(int lista[], int kont, char helbidea[]);

int main(){
	char helbidea[30];
	int lista[100], kont;
	FILE * file;

	printf("Sartu fitxategiaren izena\n");
	fflush(stdin);
	gets(helbidea);

	kont = zenbakiakIrakurri(helbidea, lista);
	zenbakiakOrdenatu(lista, kont);
	zenbakiakIdatzi(lista, kont, helbidea);

	system("pause");
	return 0;
}

int zenbakiakIrakurri (char helbidea[], int lista[]){
	int kont = 0;
	FILE * file;

	if((file = fopen(helbidea, "rb")) != NULL){
		while(fgetc(file) != EOF){
			fscanf(file,"%i", &lista[kont]);
			kont++;
		}
	}
	return kont;
}

void zenbakiakOrdenatu(int lista[], int kont){
	int i, j, temp;
	
	for(i = 0; i < kont; i++){
		for(j = i+1; j < kont; j++){
			if(lista[j] < lista[i]){
				temp = lista[j];
				lista[j] = lista[i];
				lista[i] = temp;
			}
		}
	}
}

void zenbakiakIdatzi(int lista[], int kont, char helbidea[]){
	FILE *file;
	int i;

	if((file = fopen(helbidea, "a")) != NULL){
		fprintf(file, "\n");
		for( i = 0; i < kont; i++){
			fprintf(file, "%i ", lista[i]);
		}
	}
}