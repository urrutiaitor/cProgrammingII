/* unirFicheros.c
 *
 * Programa que realiza la operación opuesta al del programa anterior: lee
 * cuántos ficheros son los que van a componer el fichero original, el nombre
 * de éste y lo reconstruye.
 *
 * Autores:
 *   + 
 *
 * Copyright (C) 2003 MGEP-MU
 *       Revisiones: 2005, 2006, 2009, 2011, 2012  
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define STR80 80

static int Juntar (char *FitxIzena, char *);

int main (void)
{
    char   nomFich [STR80], mezu[STR80];
    int    Err;
    
    printf ("Fitxero bakarra egitea zatiekin.\n");
    printf ("Fitxeroaren izena emango da: izena eta mota, bigarren luzapen gabe.\n");
    printf ("Fitxeroaren izena: ");
    gets (nomFich);
    
    Err = Juntar (nomFich, mezu);
     
    switch (Err) {
        case -1:
              fprintf (stderr, "Ezin da ireki \"%s\" fitxeroa. \n", nomFich);
              break;
        case -2:
              fprintf (stderr, "Ezin da idatzi \"%s\" fitxeroan.\n", nomFich);
              break;
        case 0: printf("%s\n", mezu);
    }

    printf ("Sakatu <Intro>"); getchar ();
    return 0;
}

  /* Fitxeroaren izena eman eta denak juntatu.
   * Iturri fitxeroa ezin badu ireki bueltatuko du -1
   * Ezin badu idatzi fitxerora bueltatuko du -2 */
static int Juntar (char *nomFich, char *mezu) {
    size_t  Cont;
    int     Exten;
    FILE   *FdOut,
           *FdIn;
    char    ExtenNom [80];
    int     Car;
     
    FdOut = fopen (nomFich, "wb");
    if (!FdOut)
         return -1;
    
    for (Cont = Exten = 0; ; Exten++) {
        sprintf (ExtenNom, "%s.%03d", nomFich, Exten);
        FdIn = fopen (ExtenNom, "rb");
        
        if (!FdIn) {
            fclose (FdOut);
            sprintf(mezu,"\nBatutako zatiak: %ld\nTamaina guztira = %ld Byte\n", Exten, Cont);
            //printf ("Zatiak: %ld Tamaina: %ld\n", Exten, Cont);
            break;
        }
        
        for (; (Car = fgetc (FdIn)) != EOF; Cont++)
            if ((fputc (Car, FdOut)) == EOF) 
                return -2;     
        
        fclose (FdIn);
    }
    fclose (FdOut);

    return 0;
}

