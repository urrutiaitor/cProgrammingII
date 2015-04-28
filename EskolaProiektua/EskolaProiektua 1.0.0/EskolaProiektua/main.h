#ifndef MAIN
#define MAIN

#define GELAMAX 100
#define IKASLEAKMAX 30
#define IKASGAIMAX 10
#define ESKOLAMAX 2

typedef struct jaiotza{
	int eguna;
	int hilea;
	int urtea;
}JAIOTZA;

typedef struct ikasgaia{
	char izena[30];
	float nota;
	char id[15];
	int irakaslearenIdala[2];
}IKASGAIA;

typedef struct ikaslea{
	char izena[30];
	char abizena[30];
	int idal;
	JAIOTZA data;
	IKASGAIA ikasgaiak[IKASGAIMAX];
	int gela;
	float batezbestekoa;
}IKASLEA;

typedef struct irakaslea{
	char izena[30];
	char abizena[30];
	int idal;
	JAIOTZA data;
}IRAKASLEA;

typedef struct gela{
	char maila[70];
	int ikasleKopurua;
	IKASLEA ikasleak[IKASLEAKMAX];
	IRAKASLEA tutorea;
	char gelaId[15];
}GELA;

typedef struct helbidea{
	char kalea[70];
	int zenbakia;
	int postaKodea;
}HELBIDEA;

typedef struct eskola{
	char izena[50];
	HELBIDEA helbidea;
	int gelaKopurua;
	GELA gelak[GELAMAX];
	int telefonoa;
}ESKOLA;

typedef struct enpresa{
	ESKOLA eskolak[ESKOLAMAX];
	int eskolaKopurua;
}ENPRESA;




#endif