#include "zbk50mila.h"

void zbk50(){
	FILE* file = 0;
	int k = 0, ale = 0, *punk, *punale;
	punk = &k;
	punale = &ale;
	srand(time(NULL));
	file = fopen("zbk50mila.dat", "w+");
	for (*punk = 0; *punk != MAX_ZBK; *punk += 1){
		printf("DATUAK SORTZEN\n");
		printf("- Datuak idatzita (1/2)");
		printf("- Itxaron - Datuak idazten... (2/2) %i/%i", *punk + 1, MAX_ZBK);
		*punale = rand();
		fwrite(&punale, sizeof(int), 1, file);
		system("cls");
	}
	fclose(file);
}