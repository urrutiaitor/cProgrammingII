/* Ion_idatzi.c  */
/*
 * Se trata ver la interpretacion de la informacion, como se guarda y 
 * leen los bit, numeros o textos.
 * Para ello trabajaremos con un fichero que tendra un numero o palabra segun
 * como lo miremos.
 *
 * Autores:
 *   + pmamallobieta
 *
 * Copyright (C) 2006 MGEP-MU
 *           Revision:   2006, 2011, 2012, 2013
 *
 */

/*************** Declaracion de Funciones *******************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/************ Konstanteen deklarazioa **************/


int main (void)
{
    char   izenaFitx [80];
    FILE *fd;
    int    zbkIdatzi;

    printf("Fitxeroaren luzapenerako ipini     \".dat\"\n");
    printf ("Zenbaki osoa gordetzeko, Fitxeroaren izan eta luzapena:  "); 
    gets (izenaFitx);
  
    printf("Zenbakia:  ");
    scanf("%i", &zbkIdatzi);
    fflush(stdin);
    
    fd = fopen(izenaFitx, "wb");
    fwrite(&zbkIdatzi, sizeof(int), 1, fd);
    
    fclose(fd);
    printf ("\nGenerados los ficheros: \"%s\" y ", izenaFitx);
    sprintf(izenaFitx, "%s%s", izenaFitx, ".txt"); // izena.dat.txt hartuko du
    fd = fopen(izenaFitx, "wb");
    fprintf(fd, "%i", zbkIdatzi); // esto lo guarda como texto, es decir digitos
    
    fclose(fd);
    printf (" \"%s\"\n", izenaFitx);
 

    printf ("Pulsar <Intro>"); getchar ();
    return 0;
}
