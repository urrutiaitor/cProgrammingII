#ifndef ARIKETAAC_H

#define ARIKETAAC_H

#include <stdio.h>
#include <Windows.h>

#define BAI 1
#define EZ 0
#define UBIKAZIOA_MAX 150
#define ABECEDARIO_KANTITATEA 26

int main();
void ubikazioaLortu(char ubikazioa[UBIKAZIOA_MAX]);
void textuaPrintatu(FILE* fitxeroa, char ubikazioa[UBIKAZIOA_MAX]);
void hasieraTextua();


#endif