#ifndef MAIN_H
#define MAIN

#define GELAMAX 30
#define IKASLEAKMAX 300
#define IRAKASLEAKMAX 30
#define IKASGAIMAX 10
#define ESKOLAMAX 2

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
	char izena[10];
	float nota;
	int id;
	int aukeratuta;
}IKASGAIA;

typedef struct ikaslea{
	char izena[10];
	char abizena[10];
	int idal;
	int pasahitza;
	JAIOTZA data;
	IKASGAIA ikasgaiak[IKASGAIMAX];
	int gela;
	float batezbestekoa;
	int ikasgaiKopurua;
}IKASLEA;

typedef struct irakaslea{
	char izena[15];
	char abizena[15];
	int idal;
	JAIOTZA data;
	int orduak;
}IRAKASLEA;

typedef struct gela{
	char maila[50];
	int ikasleKopurua;
	int irakasleaId;
	int gelaId;
	IKASGAIA ikasgaiak[IKASGAIMAX];
	int aukeragarri;
}GELA;

typedef struct eskola{
	char izena[30];
	HELBIDEA helbidea;
	int gelaKopurua;
	GELA gelak[GELAMAX];
	IKASLEA ikasleak[IKASLEAKMAX];
	IRAKASLEA irakasleak[IRAKASLEAKMAX];
	int telefonoa;
	int eskolaKopurua;
	int aukeratutakoEskola;
}ESKOLA;


#endif