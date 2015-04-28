/* gordeFuntzioak.h  */
/* testu motako fitxeroan nola gorde zenbakiak, egin dira 4 funtzio 
 * desberdin, hemen daude behar diren deklarazioak funtzioak erbiltzeko aplikazio baten. */
#ifndef GORDEFUNTZIOAK__H
	#define GORDEFUNTZIOAK__H
	
	#ifndef _CRT_SECURE_NO_WARNINGS
		#define _CRT_SECURE_NO_WARNINGS
	#endif

	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <time.h>

	/************ Konstanteen deklarazioa **************/
	#define DIM 100       // bektorean tamaina
	#define DIGKOP 23     // zenbakiaren digitu kopurua, double mota kontutan harturik

	/* ------------------- funtzioen prototipoak ------------------ */
	int irakurriGorde_1 (char izenaFitx[]);
	int irakurriGorde_2 (char []);
	int irakurriGorde_3 (char []);
	int irakurriGorde_4 (char []);
#endif