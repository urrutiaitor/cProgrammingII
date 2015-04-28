/* aplikazio.h  */
/* aplikazioko funtzioak beharduten konstanteak eta funtzioen deklarazioak */
#ifndef APLIKAZIO__H
	#define APLIKAZIO__H

	#ifdef _MSC_VER
		#ifndef _CRT_SECURE_NO_DEPRECATE
			#define _CRT_SECURE_NO_DEPRECATE
		#endif
	#endif
	#include <stdio.h>
	#include <string.h>

	#include "gordeFuntzioak.h"  // fitxeroekin lan egiteko, aukerakExekutatu() erabiliko du

	/************ Konstanteen deklarazioa **************/
	#define STR64  64       // fitxero izenaren tamaina
	#define LUZAPEN 6      // fitxero luzapenaren tamaina

	/* ------------------- funtzioen prototipoak ------------------ */
	void fitxeroIzenaIrakurri (char izenaFitx[]);
	void izenaEgin(int auk, char sarreraFitx[], char izenaFitx[]);
	int erroreak (int Err, char izenaFitx[]);
	int aukerakExekutatu (char sarreraFitx[]);
	int aukerenMenua ();
#endif