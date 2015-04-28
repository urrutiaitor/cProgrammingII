#ifndef FITXEROETAKODATUAK_H	
#define FITXEROETAKODATUAK


IKASLEA ikasleaDatuakIrakurri(int ikaslea);
IRAKASLEA irakasleaDatuakIrakurri(int irakaslea);
ADMINISTRATZAILEA administratzaileaDatuakIrakurri(int administratzailea);

void ikasleakDatuakIrakurri(ESKOLA eskola, IKASLEA *ptr_ikaslea);
void irakasleakDatuakIrakurri(ESKOLA eskola, IRAKASLEA *ptr_irakaslea);
void administratzaileakDatuakIrakurri(ESKOLA eskola, ADMINISTRATZAILEA *ptr_administratzailea);


#endif