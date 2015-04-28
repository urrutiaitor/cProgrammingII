#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int biteZenbalari(char helbidea[]);
void berridatzi(int kont, char helbidea[], int zatiak);

int main(){
	char helbidea[30], kont;
	int zatiak;
	FILE * file;

	printf("Idatzi fitxategiaren izena\n");
	fflush(stdin);
	gets(helbidea);


	kont = biteZenbalari(helbidea);
	berridatzi( kont, helbidea, zatiak);

	system("pause");
	return 0;
}

int biteZenbalari(char helbidea[]){
	int kont = 0;
	FILE * file;

	if((file = fopen(helbidea, "r")) != NULL){
		while(getc(file) != EOF){
			kont++;
		}
	}
	return kont;
}

void berridatzi( int kont, char helbidea[], int zatiak){
	FILE *file1, *file2;
	char izena[30], c;
	int i, j = 0;
	
	if((file1 = fopen(helbidea, "r")) != NULL){
		for( i = 0; i < zatiak; i++){
			sprintf(izena, "%s.00%i",helbidea,i);
			if((file2 = fopen(izena, "a")) != NULL){
				for(j = 0; j < (kont/zatiak)+1; j++){
					c = fgetc(file1);
					if(c != EOF){
						fprintf(file2,"%c", c);
					}
				}
			}
		}
	}
}