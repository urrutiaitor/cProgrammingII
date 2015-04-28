#ifndef ARIKETAAH_H

#define ARIKETAAH_H

#include <stdio.h>
#include <Windows.h>

#define MAX_IZENA 30
#define BAI 1
#define EZ 0
#define UBIKAZIOA_MAX 150

int main();
void ubikazioaLortu(char ubikazioa[UBIKAZIOA_MAX]);
void tamainaKalkulatu(FILE* fitxeroa, char ubikazioa[UBIKAZIOA_MAX]);
void tamainaPrintatu(int tamaina);
void hasieraTextua();


#endif