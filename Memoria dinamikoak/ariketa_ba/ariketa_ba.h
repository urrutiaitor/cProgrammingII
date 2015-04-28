#ifndef ARIKETABA_H
#define ARIKETABA

#include <stdio.h>

typedef struct zenbakia{
	int zenbakia;
	struct zenbakia *urrengo_ptr;
}ZENBAKIA, *PZENBAKIA;

ZENBAKIA* hasieranSartu(ZENBAKIA *ptr_hasiera);
ZENBAKIA* zenbakiaBilatu(ZENBAKIA *ptr_hasiera, int zenbakia);
void zenbakiaEzabatu(ZENBAKIA *ptr_hasiera, int zenbakia);
void zenbakiakBistaratu(ZENBAKIA *ptr_hasiera);

#endif