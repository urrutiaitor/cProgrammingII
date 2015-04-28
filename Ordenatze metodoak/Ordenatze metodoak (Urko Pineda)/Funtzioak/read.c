#include "read.h"

void read(int zbk30[], int zbk50[]){
	FILE* file;
	int k = 0, i = 0, auk = EZ, *punk, *puni, *punauk;
	punk = &k;
	puni = &i;
	punauk = &auk;
	do{
		if (((file = fopen("zbk30mila.dat", "rb")) != 0) && ((file = fopen("zbk50mila.dat", "rb")) != 0)){
			*punauk = EZ;
			file = fopen("zbk30mila.dat", "rb");
			for (*punk = 0; *punk != MAX_30; *punk += 1){
				printf("DATUEN IRAKURKETA\n");
				fread(zbk30[*punk], sizeof(int), 1, file);
				printf("- Itxaron - Datuak irakurtzen (1/2) ... %i/%i", *punk + 1, MAX_30);
				system("cls");
			}
			fclose(file);
			file = fopen("zbk50mila.dat", "rb");
			for (*punk = 0; *punk != MAX_50; *punk += 1){
				printf("DATUEN IRAKURKETA\n");
				printf("- Datuak irakurrita (1/2)\n");
				fread(zbk50[*punk], sizeof(int), 1, file);
				printf("- Itxaron - Datuak irakurtzen (2/2) ... %i/%i", *punk + 1, MAX_50);
				system("cls");
			}
			fclose(file);
		}
		else{
			printf("Ezin dira zenbakien fitxeroak irakurri - Sortu nahi duzu programarekin? (BAI: 1, EZ: 0)\n");
			scanf_s("%i", punauk);
			if (*punauk == 1){
				system("\Fitxeroak.exe");
			}
		}
	} while (*punauk == BAI);
}