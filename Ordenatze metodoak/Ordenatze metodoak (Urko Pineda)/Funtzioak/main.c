#include "main.h"

int main(){
	int zbk30[MAX_30], zbk50[MAX_50], auxzbk30[MAX_30], auxzbk50[MAX_50];
	int auk = 0, *punauk;
	punauk = &auk;
	punauk = hasiera(punauk);
	if ((*punauk == 0) || (*punauk == 1)){
		if (*punauk == 0){
			system("\Fitxeroak.exe");
		}
		read(zbk30, zbk50);
		do{
			punauk = menua(punauk);
			switch (*punauk){
				case 1:
					break;
					/*
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
					*/
				case 0: *punauk = 0;
					break;
			}
		} while (*punauk != 0);
	}
	else{
		printf("\n");
		printf("CRITICAL ERROR\n");
		printf("\n");
		printf("Sakatu ENTER tekla amaitzeko...");
		fflush(stdin);
		getchar();
	}
}