#ifndef ARIKETAAB_H
#define ARIKETAAB

#include <stdio.h>

typedef struct zenbakia{
	int zenbakia;
	struct zenbakia *urrengo_ptr;
}ZENBAKIA, *PZENBAKIA;

ZENBAKIA* hasieranSartu(ZENBAKIA *ptr_hasiera);
ZENBAKIA* zenbakiaBilatu(ZENBAKIA *ptr_hasiera, int zenbakia);
ZENBAKIA* zenbakiaEzabatu(ZENBAKIA *ptr_hasiera, int zenbakia);
void zenbakiakBistaratu(ZENBAKIA *ptr_hasiera);

#endif