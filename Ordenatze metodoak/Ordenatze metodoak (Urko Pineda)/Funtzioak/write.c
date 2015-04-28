#include "write.h"

void write(int auxzbk30[], int auxzbk50[]){
	FILE* file;
	int k = 0, i = 0, *punk, *puni;
	punk = &k;
	puni = &i;
	file = fopen("zbk30milaord.dat", "w+");
	for (*punk = 0; *punk != MAX_30; *punk += 1){
		printf("DATUEN GORDEKETA\n");
		fwrite(auxzbk30[*punk], sizeof(int), 1, file);
		printf("- Itxaron - Datuak ordenaturik gordetzen (1/2) ... %i/%i", *punk + 1, MAX_30);
		system("cls");
	}
	fclose(file);
	file = fopen("zbk50milaord.dat", "w+");
	for (*punk = 0; *punk != MAX_50; *punk += 1){
		printf("DATUEN GORDEKETA\n");
		printf("- Datuak gordeta (1/2)\n");
		fwrite(auxzbk50[*punk], sizeof(int), 1, file);
		printf("Itxaron - Datuak ordenaturik gordetzen (2/2) ... %i/%i", *punk + 1, MAX_50);
		system("cls");
	}
	fclose(file);
}