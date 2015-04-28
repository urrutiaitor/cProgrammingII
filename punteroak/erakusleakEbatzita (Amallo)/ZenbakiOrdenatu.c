/* zenbakiOrdenatu.c
 *
 * testu motako fitxstegi baten daude zenbaki osoak, zenbaki bat lerroko.
 * Fitxategi horren izena irakurri ondoren, zenbaki guztiak irakurriko dira eta
 * ordenatu txikiti handira. Ordenatuz gero gordeko dira izen berdineko 
 * fitxeroan.
 *
 * Egilea(k):
 *   + P.M. Amallobieta
 *   + 
 * Copyright (C) 2009 MGEP-MU
 *           Revisiones: febrero 2012
 */
//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-------------- Konstanteen deklarazioa ------------------*/
#define MAX 100

/*------------ funtzioen prototipoak -----------------*/
int kargatuBektorea (char *, int *);
int ordenatu (int *, int);
int fitxategiraPasatu (char *, int *, int);
void bistaratu (int *, int);

/*-------------- Programa nagusia ------------------*/
int main(void){
    /* ---------- Aldagaiak ------------*/
    char fitxIzena[MAX];
    int dim;                   // bektorearen dimentsioa
    int bektorea[MAX];
        
    /* --------- Programaren gorputza ------------*/
    printf("\n\nZenbaki fitxategiaren izena? \n");
    gets_s(fitxIzena, MAX-1);
    
    if ((dim = kargatuBektorea(fitxIzena, bektorea)) <= 0) 
        printf("\n\nFitxeroa hutsa edo ez dago fitxerorik.\n\n");
    else {
            if (ordenatu(bektorea, dim)) {
                printf("\n\n\tZenbakiak ordenatuta: \n");
                bistaratu (bektorea, dim);
            }
            printf("\n\n\nFitxeroan gordetzen. . .\n\n");
            if (!fitxategiraPasatu(fitxIzena, bektorea, dim)) {
                printf("\n\n\tEz dira gorde zenbakiak.\n\n");
            }
        }
        
    system("PAUSE");	
    return 0;
}

/*fitxerotik irakurri eta arraian gordeko ditu zenbakiak */
int kargatuBektorea (char fitxIzena[], int bektorea[])
{
   FILE* fd;
   int errno;
   int zbk, dim = 0; // dim lo utilizo como contador y dimension
   
   if ((errno = fopen_s(&fd, fitxIzena,"r")) != 0) {
        return 0; // ez dago, main-ean erabili
    }
    else{
            if ((fscanf_s(fd, "%i", &zbk)) == EOF) {
                fclose(fd);
                return -1; // fitxero hutsa, main-ean erabili
            }
            do {
                bektorea[dim]=zbk;
                dim++;
            } while((fscanf_s(fd, "%i", &zbk))!=EOF);      
    }
    
    fclose(fd);
    return dim;
}  

/* bektore ordenatzen du txikitik handira */
int ordenatu (int bektorea[], int dim)
{
    int i, j, zbk;
    
    for(i = 0;i < dim;i++){
        for(j = i+1; j < dim; j++){
            if(bektorea[i] > bektorea[j]){
                zbk = bektorea[i];
                bektorea[i] = bektorea[j];
                bektorea[j] = zbk;
            }
        }        
    }
    return 1; // ondo joan da
}

/* bektorean dauden zenbakiak fitxerora pasatu*/
int fitxategiraPasatu (char sarreraFitx[], int bektorea[], int dim)
{
    FILE* fd;
	char izenaFitx[MAX], exten[MAX];
    int i, errno;
    
    strcpy_s(exten, _countof(exten), strstr(sarreraFitx, "."));  // kopiatu luzapena
	strcpy_s(izenaFitx, _countof(izenaFitx), sarreraFitx);           // sarrerako fitxeroaren izena kopiatu
	*strstr(izenaFitx, ".") = '\0';           // . an bukatu string-a
								// egin izen berria, 3 zatirekin
	sprintf_s (izenaFitx, MAX, "%s%s%s", izenaFitx, "Ordenatuta", exten);
    //fd = fopen (izenaFitx, "wb");
	if((errno = fopen_s(&fd, izenaFitx,"w")) != 0) {
        return 0; // errorea, main-ean erabili
    }
    else{
        for(i=0; i < dim; i++)
            fprintf(fd, "%i\n", bektorea[i]);
    } 
    return 1;
}

/* bektoreko datuak bistaratu pantailara */
void bistaratu (int bektorea[], int dim)
{
    int i;
    
    for(i = 0;i < dim; i++){
        if(i==0)
            printf("\t");
        if(i!=0)
            printf(" , ");
        printf("%i", bektorea[i]);
    }
    
}
