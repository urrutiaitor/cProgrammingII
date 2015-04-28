/* testuZenbakiak.c  */
/*
 * zenbaki osoak irakurri eta gorde fitxeroan testu bezala, testu fitxeroa da.
 * zenbakiak irakurriko dira soilik, ENTER,  sartu arte.
 *
 * Autores:
 *   + P.M. Amallobieta
 *   +
 *
 * Copyright (C) 2010 MGEP-MU
 *     Revisiones Global: 2012
 *
 * Programa naguzian erabiliko diren funtzioak
 *	 void fitxeroIzenaIrakurri (char izenaFitx[]); // fitxeroaren izen irakurri
 *               eta bueltatu programara
 *
 *   int aukerakExekutatu (char izenaFitx[]);   // zenbakiak irakurtzen dira string
 *               bezala eta gorde ere horrela
 *
 */

#include "aplikazio.h"    // hemen daude behar diren definizioak eta funtzioen
						  // prototipoa

/* ---------------- Programa Nagusia ------------------ */
int main (void) {
	/* -----------------  Aldagaien Deklarazioa  --------------- */
	int Err = 0;           // ondo joan da
	char   izenaFitx [STR64];
                          

    /* ----------------- Programaren Gorputza ------------------ */
	printf ("Programa honen helburua izango da, zenbakiak gordetzea,"
		                           "\n testu motako fitxategi baten.\n");
		
	fitxeroIzenaIrakurri (izenaFitx);
	
	Err = aukerakExekutatu(izenaFitx);

	/* --------------- Programan Bukaera ------------------ */	
    printf ("Sakatu <Intro>"); getchar ();
    
	return Err;
}

