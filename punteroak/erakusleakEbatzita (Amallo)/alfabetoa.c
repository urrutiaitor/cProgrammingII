/* alfabetoa.c
 *
 * Fitxategiaren izena galdetu ondoren, fitxategi horretan alfabetoa 
 * idatziko du bai minuskulaz eta maiuskulaz, bakoitza lerro batean.
 *
 * Egilea(k):
 *   + P.M. Amallobieta
 *   + 
 * Copyright (C) 2009 MGEP-MU
 *           Revisiones: enero 2011, febrero 2012
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-------------- Konstanteen deklarazioa ------------------*/
#define MAX 30

/*-------------- Programa nagusia ------------------*/
int main(){
    /* ---------- Aldagaiak ------------*/
    FILE * fd;          // fitxeroaren deskriptorea
    char fitxIzena[MAX];
    char i;             // edo int i; berdina
    
    /* --------- Programaren gorputza ------------*/
    printf("\n\nFitxategiaren izena non alfabetoa idatzi behar den:  \n\n");
    gets(fitxIzena);
     
    if((fd=fopen(fitxIzena,"w"))==NULL)
         printf("\n\n\tFitxategiarekin arazo bat dago.\n\t\n\t");
    
    else{    
        for(i = 'a'; i <= 'z'; i++){ // minuskulak idatzi
            fprintf(fd, "%c ", i);
        }            
    
        fprintf(fd, "\n");     // lerro saltoa
        
        for(i = 65; i <= 90; i++){   // maiuskulak idatzi
            fprintf(fd, "%c ", i);           
        }
        fclose(fd); 
    }    
    
    system("PAUSE");	
    return 0;
}
