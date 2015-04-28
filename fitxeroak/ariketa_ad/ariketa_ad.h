#ifndef ARIKETAAD_H

#define ARIKETAAD_H

#include <stdio.h>
#include <Windows.h>

#define BAI 1
#define EZ 0
#define UBIKAZIOA_MAX 150
#define MAX 100

int main();
void ubikazioaLortu(char ubikazioa[UBIKAZIOA_MAX]);
void hasieraTextua();
void zenbakiakOrdenatu(int zenbakiak[MAX],int kantitatea);
int zenbakiakJaso(char ubikazioa[UBIKAZIOA_MAX], int zenbakiak[MAX]);
void zenbakiakIdatzi(char ubikazioa[UBIKAZIOA_MAX], int zenbakiak[MAX],int kantitatea);

int zenbakiak[MAX];
char ubikazioa[UBIKAZIOA_MAX];


#endif