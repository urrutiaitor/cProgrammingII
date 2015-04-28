/* aplikazioFuntzioak.c */
/* Hemengo funtzioak zuzenean lotuta daude egiten ari garen aplikazioarekin.
   Menuak eta aukera desberdiank erabiltzeko funtzioak baita ere izen berria 
   emateko funtzioa (aukeraren arabera), bukatzeko erroreen erabilera.
*/
#include "aplikazio.h"  // fitxero honetan behar diren definizioak eta funtzioen
                        // prototipoak

/* fitxeroaren izen orokorra irakurtzeko erabiliko da. */
void fitxeroIzenaIrakurri (char izenaFitx[]) {
	
	printf("\n\nHemen ematen den fitxeroaren izena berdina izango da"
		                                          " aukera guztietan.\n");
	printf("Gero izen honeri geituko zaio aukerako zenbakia azpi marrarekin\n");

    printf ("\nFitxeroaren izena: ");
    gets (izenaFitx);
}

/* Aplikazioko aukera orokorrak */
int aukerenMenua () {
	int auk;

	do {
		printf("\n1)  testu moduan irakurri eta gorde   (fitxeroa txt - modo \"w\")\n");
		printf("2)  zenbaki moduan irakurri eta gorde (fitxeroa txt - modo \"w\")\n");
		printf("3)  testu moduan irakurri eta gorde   (fitxeroa txt - modo \"wb\")\n");
		printf("4)  testu moduan irakurri eta gorde   (fitxeroa txt - modo \"w\")\n");
		printf("0)  Programatik irten.\n");
		printf("\n\tZure aukera:  ");
		scanf("%i", &auk);
	} while (auk <0 && auk > 4);
	fflush(stdin);    // scanf-k uzten dun ENTER karakterea kentzeko

	return auk;
}


/* menuan dauden aukeren exekuzioa. Hobeto ikuzteko fitxeroak aukera desberdinekin
   fitxeroari aukerako zenbakia geituko zaio izenari.
*/
int aukerakExekutatu (char sarreraFitx[]) {  // programa nagusian irakurritako izena
	int auk, Err;
	char izenaFitx[STR64];   // sarrerakoa + aukera
	

	do {
		auk = aukerenMenua();
		switch (auk) {
			case 1:  // irakurri testu bezala eta gorde berdin (fprintf)
				izenaEgin(auk, sarreraFitx, izenaFitx);
				Err = irakurriGorde_1(izenaFitx);
				break;
			case 2:  // irakurri zenbaki bezala eta gorde zenbakia (fprintf)
				izenaEgin(auk, sarreraFitx, izenaFitx);
				Err = irakurriGorde_2(izenaFitx);
				break;
			case 3:  // irakurri testu bezala eta gorde bitarrean (fwrite)
				izenaEgin(auk, sarreraFitx, izenaFitx);
				Err = irakurriGorde_3(izenaFitx);
				break;
			case 4:  //random erabilita bete fitxeroa (fprintf)
				izenaEgin(auk, sarreraFitx, izenaFitx);
				Err = irakurriGorde_4(izenaFitx);
				break;
			case 0: ;
		}
		if (auk)
			erroreak (Err, izenaFitx);
	} while (auk != 0);

	return 0;   // ondo joan da
}

/* Honek aldatuko du fitxeroaren izena exekuzioko aukera izenari jarririk
   jarraian.
*/
void izenaEgin(int auk, char sarreraFitx[], char izenaFitx[]) {
	char exten [LUZAPEN];

	strcpy(exten, strstr(sarreraFitx, "."));  // kopiatu luzapena
	strcpy(izenaFitx, sarreraFitx);           // sarrerako fitxeroaren izena kopiatu
	*strstr(izenaFitx, ".") = '\0';           // . an bukatu string-a
			// egin izen berria, 3 zatirekin
	sprintf (izenaFitx, "%s_%i%s", izenaFitx, auk, exten);
}

/* Hau izangozen egon ahal diren erroreekin lan egiteko funtzioa. 
*/
int erroreak (int Err, char izenaFitx[]) {
	        // nola joan den begiratzeko
	switch (Err) {
		case -1:
			fprintf (stderr, "Ezin izan du ireki \"%s\" fitxeroa.\n", izenaFitx);
			break;
		case -2:
			fprintf(stderr, "Ez du ondo gorde zenbakiak\n");
			break;
		case 0:
			fprintf(stderr,"\n\tDena ondo bukatu da.\n\n");
	}

	return Err;
}