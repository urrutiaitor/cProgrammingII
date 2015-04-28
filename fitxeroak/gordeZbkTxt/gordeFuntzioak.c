/* gordeFuntzioak.c */
/* hemen daude irakurri eta gorde egiten duten funtzioak.
 * lau funtzio desberdin egin dira, hiru irakurri ahala gorde egingo dute eta
 * bestea random erabilita betetzen du fitxeroa.
*/
#include "gordeFuntzioak.h"

/*  hemen gets() erabiliko da zenbaki bezala irakurtzeko eta gero gorde
    edo idatzi fitxeroan fprintf() bitartez string bezala */
int irakurriGorde_1 (char izenaFitx[]) {
	FILE *Fd;
	char str  [DIGKOP];  // hemen egongo da string bezala irakurritako zenbakia
	                     // zenbaki osoak 11 karakter nahikoa du

	Fd = fopen (izenaFitx, "w");
    if (!Fd)
		return -1;  // ezin izan du ireki

    printf ("\nZenbakiak irakurtzen goaz. "
            "\nIrakurketa bukatzeko eman RETURN, soilik.\n");

    printf ("\nAurrera: \n");
    while (gets (str) && str [0]) {
		if (fprintf(Fd, "%s\n", str) == EOF) {
			fclose(Fd);  // kanpora irten aurretik fitxeroa itxi
			return -2;
		}
	}
	fclose(Fd);   // ondo joan bada, hemen fitxeroa itxi

	return 0;    // ondo joan da 
}

/*  hemen sscanf() erabiliko da zenbaki bezala irakurtzeko eta gero gorde
    edo idatzi fitxeroan fprintf() bitartez zenbaki bezala */
int irakurriGorde_2 (char izenaFitx[]) {
	FILE *Fd;
	int zbk;        // hemen egongo da string bezala irakurritakoa, zenbaki
					// oso bat moduan
	char str [DIGKOP];   // zenbaki osoekin 11 karakter nahikoa da

	Fd = fopen (izenaFitx, "w");
    if (!Fd)
		return -1;  // ezin izan du ireki

    printf ("\nZenbaki irakurtzen goaz. "
            "\nIrakurketa bukatzeko eman RETURN, soilik.\n");

    printf ("\nAurrera: \n");
    while (gets (str) && str [0]) {
		sscanf(str, "%i", &zbk);		// hemen zenbakia da
		if (fprintf(Fd, "%i\n", zbk) == EOF) {
			fclose(Fd); // kanpora irten aurretik fitxeroa itxi
			return -2;  // ezin izan du idatzi
		}
	}
	fclose(Fd);   // ondo joan bada, hemen fitxeroa itxi

	return 0;    // ondo joan da 
}

/* hemen zenbakiak irakurriko dira testu bezala gets()arekin, gero idatziko dira fitxerora
   bitarrean (fwrite) erabilita.
*/
int irakurriGorde_3 (char izenaFitx[]) {
	FILE *Fd;
	char str [DIGKOP];
	char LF = 10;  // New Line Feed
	char CR = 13;  // Carriage Return
	int cod;

	Fd = fopen (izenaFitx, "wb");
    if (!Fd)
		return -1;  // ezin izan du ireki

    printf ("\nZenbaki irakurtzen goaz. "
            "\nIrakurketa bukatzeko eman RETURN, soilik.\n");

    printf ("\nAurrera: \n");
   
	while (gets (str) && str [0]) {
		     // konparaketa cod erabilita egin behar da 
		if ((cod = fwrite(str, sizeof(char), strlen(str),Fd)) == 0) {
			fclose(Fd);   // kanpora irten aurretik fitxeroa itxi
			return -2;
		}
				// bi honekin egiten da lerro saltoa
		fwrite(&CR,sizeof(char),1, Fd);  // lerroko hasierara
		fwrite(&LF,sizeof(char),1, Fd);  // lerro berria
		
	}
	fclose(Fd);   // ondo joan bada, hemen fitxeroa itxi

	return 0;     // ondo joan da 
}

/* random bitartez beteko egingo du zenbakiak eta gero fitxeroan gordeko ditu
   fprintf()arekin zenbaki bezala, baina testu motan.
*/
int irakurriGorde_4 (char izenaFitx[]) {
	FILE *Fd;
	int i, zbk;        // hemen egongo da random-ek lortutako zenbakia

	Fd = fopen (izenaFitx, "w");
    if (!Fd)
		return -1;  // ezin izan du ireki

    printf ("\n100 Zenbaki automatikoki gordeko dira.\n ");

    srand((unsigned)time(NULL));
	
    for (i = 0; i < 100; i++) {
		zbk = rand() % 10000;
		if (fprintf(Fd, "%i\n", zbk) == EOF) {
			fclose(Fd);   // kanpora irten aurretik fitxeroa itxi
			return -2;
		}
	}
	fclose(Fd);   // ondo joan bada, hemen fitxeroa itxi

	return 0;     // ondo joan da 
}