#ifndef ARIKETAAG_H

#define ARIKETAAG_H

#include <stdio.h>
#include <Windows.h>

#define MAX 100
#define BAI 1
#define EZ 0
#define UBIKAZIOA_MAX 150

int main();
void ubikazioaLortu(char ubikazioa[UBIKAZIOA_MAX]);
int zenbakiakJaso(int zenbakiak[MAX]);
void zenbakiakFitxeroanGorde(int kantitatea, char ubikazioa[UBIKAZIOA_MAX],int zenbakiak[MAX]);
void hasieraTextua();


#endif