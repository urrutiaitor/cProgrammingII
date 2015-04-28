/* Ion_irakurri.c */
/* Ikusi nahi da balioak bitarrean edo karakter moduan.
 * horretarako erabiliko da 4 karaktereko hitz bat ikusi ahal izateko
 * baita zenbaki oso bat izango balitz bezala.
 * Erabiliko da:
 *          funtzio bat, bi fitxero, erkuzteko bi eratan irakurritakoak.
 *
 * Autores:
 *   + pmamallobieta
 *
 * Copyright (C) 2012 MGEP-MU
 *            Revision:   2011, 2012, 2013
 *           
 *
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int irakurFitx(char izenaFitx[]);

int main (void)
{
    char   izenaFitx [80];
    int    zbkIrakurri = 0; 

    printf ("Irakurri nahi den Fitxeroaren izena:  "); 
    gets (izenaFitx);
  
    if (irakurFitx(izenaFitx)) {
       sprintf(izenaFitx, "%s%s", izenaFitx, ".txt");
       if (irakurFitx(izenaFitx))
          printf("\n\nJustifikatu ateratzen diren balioak . . . . \n");
    }

    printf ("Sakatu <Intro>"); getchar ();
    return 0;
}

int irakurFitx(char izenaFitx[]) {
    FILE *fd;
    int   zbkIrakurri;
	int basura[2] = {1431519554,16722}; // zenbaki honek testu modoan BASURA
     
    printf("\n\t\"%s\" irakurtzera goaz.\n", izenaFitx);
    if ((fd = fopen(izenaFitx, "rb")) == NULL) { // kasu honeta berdina da "r" edo "rb"
        printf("No existe fichero\n");           // bakarrik gauza bat delako, bestela ez
        return 0;
    }

     /* irakurketa hau egiteko testua digitoak izan behar dute. "%d" honek esaten
        du digituak zenbakira bihurtzeko, baina beste karakter batzuk badira (BASURA)*/
    fscanf(fd,"%d", &zbkIrakurri);
    if (strstr(izenaFitx, ".dat."))
		printf("Irakurritako balioa (fscanf) = %i\n", zbkIrakurri);
		
	else
		printf("Irakurritako balioa (fscanf) = %i  %s\n", zbkIrakurri, &basura);
    
    
    rewind(fd);  //hasieratu fitxero irakurketa eta orain irakurri fread erbilita
    fread(&zbkIrakurri,sizeof(int),1, fd);
    if (strstr(izenaFitx, ".dat.txt"))
		printf("Irakurritako balioa (fread) = %i  %s\n", zbkIrakurri, &basura);    
	else
		printf("Irakurritako balioa (fread) = %i\n", zbkIrakurri); 
    
    fclose(fd);
    return 1;
}
    
