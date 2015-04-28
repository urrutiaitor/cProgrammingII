#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

void alfabetoa(char helbidea[]);

int main(){
	char helbidea[30];
	FILE * file;

	printf("Sartu fitxategiaren izena\n");
	fflush(stdin);
	gets(helbidea);

	alfabetoa(helbidea);
	
	system("pause");
	return 0;
}

void alfabetoa(char helbidea[]){
	char kar;
	FILE * file;

	if((file = fopen(helbidea, "w")) != NULL){
		fprintf(file, "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ \nabcdefghijklmnñopqrstuvwxyz");
	}
}