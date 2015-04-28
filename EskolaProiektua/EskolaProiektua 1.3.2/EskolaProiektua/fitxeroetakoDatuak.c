#include "fitxeroetakoDatuak.h"
#include "main.h"


IKASLEA ikasleaDatuakIrakurri(int ikaslea){
	//aldagaiak
	FILE* fitxeroa;
	int i = 0;
	IKASLEA ikasleak;

	//programa
	if ((fitxeroa = fopen("ikasleak.dat", "rb")) == NULL){
		printf("Ikasleen datu basea ezin izan da ireki\n");
	}
	else{
		for (i = 0; i < ikaslea; i++){
			fread(&ikasleak, sizeof (IKASLEA), 1, fitxeroa);
		}

	}

	//return 
	return ikasleak;
}

IRAKASLEA irakasleaDatuakIrakurri(int irakaslea){
	//aldagaiak
	FILE* fitxeroa;
	int i = 0;
	IRAKASLEA irakasleak;

	//programa
	if ((fitxeroa = fopen("irakasleak.dat", "rb")) == NULL){
		printf("Irakasleen datu basea ezin izan da ireki\n");
	}
	else{
		for (i = 0; i < irakaslea; i++){
			fread(&irakasleak, sizeof (IKASLEA), 1, fitxeroa);
		}

	}

	//return 
	return irakasleak;
}

ADMINISTRATZAILEA administratzaileaDatuakIrakurri(int administratzailea){
	//aldagaiak
	FILE* fitxeroa;
	int i = 0;
	ADMINISTRATZAILEA administratzaileak;

	//programa
	if ((fitxeroa = fopen("administratzaileak.dat", "rb")) == NULL){
		printf("Administratzaileen datu basea ezin izan da ireki\n");
	}
	else{
		for (i = 0; i < administratzailea; i++){
			fread(&administratzaileak, sizeof (IKASLEA), 1, fitxeroa);
		}

	}

	//return 
	return administratzaileak;
}



void ikasleakDatuakIrakurri(ESKOLA eskola, IKASLEA *ptr_ikaslea){
	//aldagaiak
	int i = 0;
	FILE* fitxeroa;

	//programa
	if ((fitxeroa = fopen("ikasleak.dat", "rb")) == NULL){
		printf("Ikasleen datu basea ezin izan da ireki\n");
	}
	else{
		for (i = 0; i < eskola.ikasleak; i++){
			fread(&ptr_ikaslea[i], sizeof (IKASLEA), 1, fitxeroa);
		}
	}

	//return
	return 0;
}

void irakasleakDatuakIrakurri(ESKOLA eskola, IRAKASLEA *ptr_irakaslea){
	//aldagaiak
	int i = 0;
	FILE* fitxeroa;

	//programa
	if ((fitxeroa = fopen("irakasleak.dat", "rb")) == NULL){
		printf("Irakasleen datu basea ezin izan da ireki\n");
	}
	else{
		for (i = 0; i < eskola.irakasleak; i++){
			fread(&ptr_irakaslea[i], sizeof (IRAKASLEA), 1, fitxeroa);
		}
	}

	//return
	return 0;
}

void administratzaileakDatuakIrakurri(ESKOLA eskola, ADMINISTRATZAILEA *ptr_administratzailea){
	//aldagaiak
	int i = 0;
	FILE* fitxeroa;

	//programa
	if ((fitxeroa = fopen("administratzaileak.dat", "rb")) == NULL){
		printf("Administratzaileen datu basea ezin izan da ireki\n");
	}
	else{
		for (i = 0; i < eskola.ikasleak; i++){
			fread(&ptr_administratzailea[i], sizeof (ADMINISTRATZAILEA), 1, fitxeroa);
		}
	}

	//return
	return 0;
}