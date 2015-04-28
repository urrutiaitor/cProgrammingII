/* a_kopurua.c
 *
 * Fitxategiaren izena galdetu ondoren, fitxategi horretan agertzen 
 * den ‘a’ kopurua zein den esango digu.
 *
 * Egilea(k):
 *   + P.M. Amallobieta
 *   + 
 * Copyright (C) 2009 MGEP-MU
 *           Revisiones: febrero 2010, enero 2012
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/************ Konstanteen deklarazioa **************/
#define MAX 30

/************ Programa nagusia *********************/
int main(){
    /* ---------- Aldagaiak ------------*/
    FILE* fd;     // fitxeroaren deskriptorea
    int kont=0;
    char fitxIzena[MAX];
    char letra;    
    
    /* --------- Programaren gorputza ------------*/
    printf("\nEman fitxategiaren izena:  ");
    gets(fitxIzena);        
    
    if((fd = fopen(fitxIzena, "r"))== NULL)
        printf("\n\n\nFitxategia ez dago");
    else{
        while((letra = fgetc(fd))!= EOF){
            if(letra == 'a'){
                kont++;
            }
        }
        fclose(fd);        
        printf("\n\n\n\t%d 'a' daude \"%s\" fitxategian \n\n", kont, fitxIzena);                
    }
        
    system("PAUSE");	
    return 0;
}
