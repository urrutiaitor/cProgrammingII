#include "instructions.h"

//aldagaiak
FILE* fitxeroa;
char helbidea[UBIKAZIOA_MAX] = ' ';
char karakterea;
char arraya;
int kantitatea;
int hasiera;
int zenbakia;

//programa
fitxeroa = fopen(helbidea, "r"); //sólo lectura. El fichero debe existir.
fitxeroa = fopen(helbidea, "w"); //se abre para escritura, se crea un fichero nuevo o se sobreescribe si ya existe.
fitxeroa = fopen(helbidea, "a"); //añadir, se abre para escritura, el cursor se situa al final del fichero. Si el fichero no existe, se crea.
fitxeroa = fopen(helbidea, "r+"); //lectura y escritura. El fichero debe existir.
fitxeroa = fopen(helbidea, "w+"); //lectura y escritura, se crea un fichero nuevo o se sobreescribe si ya existe.
fitxeroa = fopen(helbidea, "a+"); //añadir, lectura y escritura, el cursor se situa al final del fichero. Si el fichero no existe, se crea.
fitxeroa = fopen(helbidea, "t"); //tipo texto, si no se especifica "t" ni "b", se asume por defecto que es "t"
fitxeroa = fopen(helbidea, "b"); //tipo binario.

int fclose(fitxeroa); // 0 bueltatzen du ondo badago

int fgetc(fitxeroa); // irakurritako karakterea bueltatzen du edo EOF

int fputc(karakterea, fitxeroa); //Esta función escribe un carácter a un fichero.  El valor de retorno es el carácter escrito, si la operación fue completada con éxito, en caso contrario será EOF. Los parámetros de entrada son el carácter a escribir, convertido a int y un puntero a una estructura FILE del fichero en el que se hará la escritura.

int feof(fitxeroa); //fitxero amaiera bada EOF hau da 0

void rewind(fitxeroa); //fitxeroaren hasieran jartzen du kurtsorea

char fgets(arraya, n, fitxeroa); //fitxerotik irakurri  //n=fitxerotik irakurriko dituen string kopurua  //char arraya=non gordeko den

int puts(arraya, fitxeroa); //arrayan irakurri  //fitxeroan jarri  //errorea badago EOF

int fread(*puntero, sizeof (BIZTANLEA), 1, fitxeroa);

int fwrite(*puntero, sizeof (BIZTANLEA), 1, fitxeroa);

int fprintf(fitxeroa, "%i", zenbakia); //programatik hartu eta fitxeroan idatzi

int fscanf(fitxeroa, "%i", zenbakia); //fitxerotik irakurri eta programara pasatu

int fflush(fitxeroa);

int fseek(fitxeroa, kantitatea, origen); //kurtsorea nahi duzun lekuan jarri
//SEEK_SET el desplazamiento se cuenta desde el principio del fichero. El primer byte del fichero tiene un desplazamiento cero.
//SEEK_CUR el desplazamiento se cuenta desde la posición actual del cursor.
//SEEK_END el desplazamiento se cuenta desde el final del fichero.

long int ftell(fitxeroa); //kurtsorea zenbatgarren posizioan dagoen jakiteko




void zenbakiakOrdenatu(int zenbakiak[MAX], int kantitatea){
	//aldagaiak
	int segi = 0;
	int i = 0, t = 0;
	int aux = 0;

	//programa

	for (i = 0; i < kantitatea; i++){
		for (t = 0; t < kantitatea; t++){
			if (zenbakiak[t]>zenbakiak[i]){
				aux = zenbakiak[i];
				zenbakiak[i] = zenbakiak[t];
				zenbakiak[t] = aux;
			}
		}
	}
}






void biztanleakHasieratu(BIZTANLEA biztanleak[BIZTANLERIA_MAX], BIZTANLEA jubilatuak[BIZTANLERIA_MAX], int biztanleKopurua);
void menua(BIZTANLEA biztanleak[BIZTANLERIA_MAX], BIZTANLEA jubilatuak[BIZTANLERIA_MAX]);
void biztanleaSortu(BIZTANLEA biztanleak[BIZTANLERIA_MAX], BIZTANLEA jubilatuak[BIZTANLERIA_MAX]);
void jubilatuetaraPasatu(BIZTANLEA biztanleak[BIZTANLERIA_MAX], BIZTANLEA jubilatuak[BIZTANLERIA_MAX]);
void etxebizitzenBatezbestekoa(BIZTANLEA biztanleak[BIZTANLERIA_MAX], BIZTANLEA jubilatuak[BIZTANLERIA_MAX]);
void fitxeroetatikDatuakJaso(BIZTANLEA biztanleak[BIZTANLERIA_MAX], BIZTANLEA jubilatuak[BIZTANLERIA_MAX], int jubilatuKantitatea);
void fitxeroetanDatuakSartu(BIZTANLEA biztanleak[BIZTANLERIA_MAX], BIZTANLEA jubilatuak[BIZTANLERIA_MAX], int jubilatuKantitatea);

int main(){
	//aldagaiak
	BIZTANLEA biztanleak[BIZTANLERIA_MAX];
	BIZTANLEA jubilatuak[BIZTANLERIA_MAX];
	int jubilatuKantitatea;
	int biztanleKopurua;

	//programa
	biztanleakHasieratu(biztanleak, jubilatuak, biztanleKopurua);

	//bukaera
}

void biztanleakHasieratu(BIZTANLEA biztanleak[BIZTANLERIA_MAX], BIZTANLEA jubilatuak[BIZTANLERIA_MAX], int biztanleKopurua){
	//aldagaiak
	int i = 0;


	//programa
	strcpy(biztanleak[0].izena, "Koldo");
	strcpy(biztanleak[0].lehenAbizena, "Aranbarri");
	strcpy(biztanleak[0].bigarrenAbizena, "Herrero");
	strcpy(biztanleak[0].helbidea.kalea, "Gipuzkoa Etorbidea");
	biztanleak[0].helbidea.zenbakia = 23;
	biztanleak[0].helbidea.solairua = 2;
	strcpy(biztanleak[0].helbidea.letra, "A");
	biztanleak[0].jaiotzeData.urtea = 1945;
	biztanleak[0].jaiotzeData.hilea = 09;
	biztanleak[0].jaiotzeData.eguna = 14;
	biztanleak[0].errenta = 0;
	biztanleak[0].etxebizitza = 1;

	biztanleak[0].biztanlea = 1;

	strcpy(biztanleak[1].izena, "Mikel");
	strcpy(biztanleak[1].lehenAbizena, "Gamboa");
	strcpy(biztanleak[1].bigarrenAbizena, "Perez");
	strcpy(biztanleak[1].helbidea.kalea, "Urarte Kalea");
	biztanleak[1].helbidea.zenbakia = 18;
	biztanleak[1].helbidea.solairua = 1;
	strcpy(biztanleak[1].helbidea.letra, "A");
	biztanleak[1].jaiotzeData.urtea = 1949;
	biztanleak[1].jaiotzeData.hilea = 03;
	biztanleak[1].jaiotzeData.eguna = 04;
	biztanleak[1].errenta = 1;
	biztanleak[1].etxebizitza = 0;
	biztanleak[1].biztanlea = 1;

	strcpy(biztanleak[2].izena, "Ainhoa");
	strcpy(biztanleak[2].lehenAbizena, "Solabre");
	strcpy(biztanleak[2].bigarrenAbizena, "Ajuria");
	biztanleak[2].biztanlea = 1;

	strcpy(biztanleak[3].izena, "Andoni");
	strcpy(biztanleak[3].lehenAbizena, "Ugalde");
	strcpy(biztanleak[3].bigarrenAbizena, "Irigoien");
	strcpy(biztanleak[3].helbidea.kalea, "Mintegi Kalea");
	biztanleak[3].helbidea.zenbakia = 5;
	biztanleak[3].helbidea.solairua = 3;
	strcpy(biztanleak[3].helbidea.letra, "B");
	biztanleak[3].jaiotzeData.urtea = 1931;
	biztanleak[3].jaiotzeData.hilea = 11;
	biztanleak[3].jaiotzeData.eguna = 23;
	biztanleak[3].errenta = 1;
	biztanleak[3].etxebizitza = 0;
	biztanleak[3].biztanlea = 1;

	strcpy(biztanleak[4].izena, "Amaia");
	strcpy(biztanleak[4].lehenAbizena, "Errasti");
	strcpy(biztanleak[4].bigarrenAbizena, "Azkoitia");
	strcpy(biztanleak[4].helbidea.kalea, "Errekabarren Kalea");
	biztanleak[4].helbidea.zenbakia = 15;
	biztanleak[4].helbidea.solairua = 3;
	strcpy(biztanleak[4].helbidea.letra, "B");
	biztanleak[4].jaiotzeData.urtea = 1947;
	biztanleak[4].jaiotzeData.hilea = 12;
	biztanleak[4].jaiotzeData.eguna = 05;
	biztanleak[4].errenta = 0;
	biztanleak[4].etxebizitza = 1;
	biztanleak[4].biztanlea = 1;

	strcpy(biztanleak[5].izena, "Mari Carmen");
	strcpy(biztanleak[5].lehenAbizena, "Zubizarreta");
	strcpy(biztanleak[5].bigarrenAbizena, "Montero");
	strcpy(biztanleak[5].helbidea.kalea, "Loramendi Kalea");
	biztanleak[5].helbidea.zenbakia = 8;
	biztanleak[5].helbidea.solairua = 4;
	strcpy(biztanleak[5].helbidea.letra, "C");
	biztanleak[5].jaiotzeData.urtea = 1942;
	biztanleak[5].jaiotzeData.hilea = 06;
	biztanleak[5].jaiotzeData.eguna = 25;
	biztanleak[5].errenta = 0;
	biztanleak[5].etxebizitza = 1;

	biztanleak[5].biztanlea = 1;

	strcpy(biztanleak[6].izena, "Maddi");
	strcpy(biztanleak[6].lehenAbizena, "Lasuen");
	strcpy(biztanleak[6].bigarrenAbizena, "Azcona");
	biztanleak[6].biztanlea = 1;

	strcpy(biztanleak[7].izena, "Ander");
	strcpy(biztanleak[7].lehenAbizena, "Lazcano");
	strcpy(biztanleak[7].bigarrenAbizena, "Lopez");
	biztanleak[7].biztanlea = 1;

	strcpy(biztanleak[8].izena, "Iker");
	strcpy(biztanleak[8].lehenAbizena, "Sukia");
	strcpy(biztanleak[8].bigarrenAbizena, "Aldanondo");
	biztanleak[8].biztanlea = 1;

	strcpy(biztanleak[9].izena, "Ane");
	strcpy(biztanleak[9].lehenAbizena, "Iriarte");
	strcpy(biztanleak[9].bigarrenAbizena, "Lasuen");
	biztanleak[9].biztanlea = 1;

	strcpy(biztanleak[10].izena, "Maider");
	strcpy(biztanleak[10].lehenAbizena, "Herrero");
	strcpy(biztanleak[10].bigarrenAbizena, "Arana");
	biztanleak[10].biztanlea = 1;

	strcpy(biztanleak[11].izena, "Mikel");
	strcpy(biztanleak[11].lehenAbizena, "Garcia");
	strcpy(biztanleak[11].bigarrenAbizena, "Moreno");
	biztanleak[11].biztanlea = 1;

	strcpy(biztanleak[12].izena, "Jagoba");
	strcpy(biztanleak[12].lehenAbizena, "Aldazabal");
	strcpy(biztanleak[12].bigarrenAbizena, "Bengoa");
	biztanleak[12].biztanlea = 1;

	strcpy(biztanleak[13].izena, "Maite");
	strcpy(biztanleak[13].lehenAbizena, "Gandiaga");
	strcpy(biztanleak[13].bigarrenAbizena, "Biain");
	biztanleak[13].biztanlea = 1;

	for (i = 14; i < biztanleKopurua; i++){
		strcpy(biztanleak[i].izena, "izena");
		strcpy(biztanleak[i].lehenAbizena, "lehenAbizena");
		strcpy(biztanleak[i].bigarrenAbizena, "bigarrenAbizena");
		biztanleak[i].biztanlea = 1;
	}


}

void menua(BIZTANLEA biztanleak[BIZTANLERIA_MAX], BIZTANLEA jubilatuak[BIZTANLERIA_MAX]){
	//aldagaiak
	int aukera = 0;

	//programa
	printf("Zer nahi duzu egin:\n");
	printf("1. Biztanle berri baten fitxa egin\n");
	printf("2. Biztanle bat jubilatu bezala jarri\n");
	printf("3. Biztanle guztien artea, etxebizitza propioa dutenen ehunekoa ikusi");
	printf("4. Irten");

	switch (aukera){
	case 1:
		biztanleaSortu(biztanleak, jubilatuak);
		break;
	case 2:
		jubilatuetaraPasatu(biztanleak, jubilatuak);
		break;
	case 3:
		etxebizitzenBatezbestekoa(biztanleak, jubilatuak);
		break;
	}
}

void biztanleaSortu(BIZTANLEA biztanleak[BIZTANLERIA_MAX], BIZTANLEA jubilatuak[BIZTANLERIA_MAX]){
	//aldagaiak
	int i = 0;
	int segi = 0;
	int biztanlea = 0;
	int aux = 0;

	//programa
	while ((segi == 1) && (i < BIZTANLERIA_MAX)){
		if (biztanleak[i].biztanlea == 1){
			segi = 0;
			biztanlea = i;
		}
		i++;
	}

	printf("Zein da biztanlearen izena?\n");
	gets(biztanleak[biztanlea].izena);
	printf("Zein da biztanlearen lehen abizena?\n");
	gets(biztanleak[biztanlea].lehenAbizena);
	printf("Zein da biztanlearen bigarren abizena?\n");
	gets(biztanleak[biztanlea].bigarrenAbizena);
	printf("Nola bizi da biztanlea: Alokatuta(0)/Etxebizitza propioa(1)\n");
	scanf("%i", &aux);
	if (aux == 0){
		biztanleak[biztanlea].errenta = 1;
		biztanleak[biztanlea].etxebizitza = 0;
	}
	if (aux == 1){
		biztanleak[biztanlea].etxebizitza = 1;
		biztanleak[biztanlea].errenta = 0;
	}
	printf("Zein da biztanlearen jaiotze urtea?\n");
	scanf("%i", &biztanleak[biztanlea].jaiotzeData.urtea);
	printf("Zein da biztanlearen jaiotze hilea?\n");
	scanf("%i", &biztanleak[biztanlea].jaiotzeData.hilea);
	printf("Zein da biztanlearen jaiotze eguna?\n");
	scanf("%i", &biztanleak[biztanlea].jaiotzeData.eguna);
	printf("Biztanlea jubilatuta dago? BAI(1)/EZ(0)\n");
	scanf("%i", &aux);
	if (aux == 1){
		biztanleak[biztanlea].jaiotzeData.jubilatua = 1;
	}
	printf("Zein da biztanlearen DNI-a\n");
	gets(biztanleak[biztanlea].dni);
	printf("Zein da biztanlearen telefono zenbakia?\n");
	scanf("%i", biztanleak[biztanlea].telefonoa);

	//return
}

void jubilatuetaraPasatu(BIZTANLEA biztanleak[BIZTANLERIA_MAX], BIZTANLEA jubilatuak[BIZTANLERIA_MAX]){
	//aldagaiak
	int i = 0, t = 0;

	//programa
	for (i = 0; i < BIZTANLERIA_MAX; i++){
		if ((biztanleak[i].biztanlea == 1) && (biztanleak[i].jaiotzeData.jubilatua == 1)){
			jubilatuak[t] = biztanleak[i];
			t++;
		}
	}

	return t;
}

void etxebizitzenBatezbestekoa(BIZTANLEA biztanleak[BIZTANLERIA_MAX], BIZTANLEA jubilatuak[BIZTANLERIA_MAX]){
	//aldagaiak
	int i = 0, t = 0;
	int kont = 0;
	float batezbestekoa = 0;

	//programa
	for (i = 0; i < BIZTANLERIA_MAX; i++){
		if (biztanleak[i].biztanlea == 1){
			if (biztanleak[i].etxebizitza == 1){
				kont++;
			}
			t++;
		}
	}
	batezbestekoa = kont / t;
	printf("batezbestekoa %f-koa da", batezbestekoa);

}

void fitxeroetatikDatuakJaso(BIZTANLEA biztanleak[BIZTANLERIA_MAX], BIZTANLEA jubilatuak[BIZTANLERIA_MAX], int jubilatuKantitatea){
	//aldagaiak
	FILE* fitxeroa;
	int konprobazioa = 0;

	//programa
	fitxeroa = fopen("zentsua.txt", "rb");

	konprobazioa = fread(biztanleak, BIZTANLERIA_MAX, 0, fitxeroa);

	if (konprobazioa != 0){
		printf("Fitxerotik ondo irakurri da\n");
	}
	else{
		printf("Ezin izan da fitxerotik ondo irakurri\n");
	}
}

void fitxeroetanDatuakSartu(BIZTANLEA biztanleak[BIZTANLERIA_MAX], BIZTANLEA jubilatuak[BIZTANLERIA_MAX], int jubilatuKantitatea){
	//aldagaiak
	FILE* fitxeroa;
	int konprobazioa = 0;

	//programa
	fitxeroa = fopen("zentsua.txt", "wb");

	konprobazioa = fwrite(biztanleak, BIZTANLERIA_MAX, 0, fitxeroa);

	if (konprobazioa != 0){
		printf("Fitxeroan ondo gorde da\n");
	}
	else{
		printf("Ezin izan da fitxeroan ondo gorde\n");
	}
}