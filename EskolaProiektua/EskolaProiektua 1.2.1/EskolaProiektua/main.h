#ifndef MAIN_H
#define MAIN

#define GELAMAX 30
#define IKASLEAKMAX 30
#define IKASGAIMAX 10
#define ESKOLAMAX 2
#define IZENAMAX 10

typedef struct helbidea{
	char kalea[40];
	int zenbakia;
	int postaKodea;
}HELBIDEA;

typedef struct jaiotza{
	int eguna;
	int hilea;
	int urtea;
}JAIOTZA;

typedef struct ikasgaia{
	char izena[IZENAMAX];
	float nota;
	char id[15];
	int aukeratuta;
}IKASGAIA;

typedef struct ikaslea{
	char izena[IZENAMAX];
	char abizena[IZENAMAX];
	int idal;
	JAIOTZA data;
	IKASGAIA ikasgaiak[IKASGAIMAX];
	int gela;
	float batezbestekoa;
	int ikasgaiKopurua;
}IKASLEA;

typedef struct irakaslea{
	char izena[IZENAMAX];
	char abizena[IZENAMAX];
	int idal;
	JAIOTZA data;
	int orduak;
}IRAKASLEA;

typedef struct gela{
	char maila[50];
	int ikasleKopurua;
	IKASLEA ikasleak[IKASLEAKMAX];
	IRAKASLEA tutorea;
	IKASGAIA ikasgaiak[IKASGAIMAX];
	IRAKASLEA irakasleak[IKASGAIMAX];
	int gelaId;
	int aukeragarri;
}GELA;

typedef struct eskola{
	char izena[30];
	HELBIDEA helbidea;
	int gelaKopurua;
	GELA gelak[GELAMAX];
	int telefonoa;
	int eskolaKopurua;
	int aukeratutakoEskola;
}ESKOLA;


#endif

/*aukeratuta=eskolak[0].aukeratutakoEskola;
eskolak[aukeratu].*/