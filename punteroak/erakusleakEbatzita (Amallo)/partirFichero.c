/* partirFichero.c
 *
 * Se trata de trocear un fichero. Se leerá el nombre del fichero a partir 
 * y el tamaño que queremos que tenga cada trozo.
 * Los ficheros que salgan de este troceo cogerán el nombre del fichero origen
 * mas una extensión de, por ejemplo:
 *    + nombre.txt.000
 *    + nombre.txt.001
 *    + ...
 *
 * Autores:
 *   Pedro M. Amallobieta 
 *
 * Copyright (C) 2003 MGEP-MU
 *       Revisiones: 2005, 2006, 2009, 2011, 2012
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

static int Partir (char *NomFich, size_t Dimension);

int main (void) {
    char   buffer [80];  // erabiliko da karakter segida bat gordetzeko
    size_t dim = 0;
    int    Err;         // erroreak erabiltzeko

    printf ("Fitxategi baten zatiketa egingo da.\n");

    printf ("Zein izan bahar du zati bakoitzaren tamaina(KByte): ");
    gets (buffer);
    sscanf (buffer, "%ld", &dim);
    if (dim < 10)
        fprintf (stderr, "Zatiaren tamaina ezin da izan 10KByte baino txikiagoa: \"%ld\"\n", dim);
    else {
        dim *= 1000; 
        printf ("Fitxeroaren izena: ");
        gets (buffer);
    
        Err = Partir (buffer, dim);
    
        switch (Err) {
            case -1:
                fprintf (stderr, "Ezin da \"%s\" fitxeroa ireki:\n", buffer);
                break;
            case -2:
                fprintf (stderr, "Ezin da idatzi \"%s.xxx\" fitxeroan.\n", buffer);
                break;
        }
    }

    printf ("Eman <Intro>"); getchar ();
    return 0;
}

  /* Ematen zaion fitxeroa zatitu.
   * Ezin badu ireki fitxeroa bueltatuko du -1
   * Ezin badu idatxi fitxeroan, errorea ematen du, bueltatuko du -2 */
static int Partir (char *NomFich, size_t dim)
{
    size_t  Cont;
    int     Exten;
    FILE   *FdIn,
           *FdOut;
    char    ExtenNom [80];
    int     Car;

    FdIn = fopen (NomFich, "rb");
    if (!FdIn)    // NULL bueltatzen badu, errorea, ezin du ireki
        return -1;
    
    for (Car = Exten = 0; Car != EOF; Exten++) {
        sprintf (ExtenNom, "%s.%03d", NomFich, Exten);
        FdOut = fopen (ExtenNom, "wb");
    
        if (!FdOut) {        // NULL bada irteerako fitxeroa, ezin du idatzi
            fclose (FdIn);   // ordu itxi egin behar da sarrerakoa
       
        return -2;
    }

    for (Cont = 0; Cont < dim; Cont++) {
        if ((Car = fgetc (FdIn)) != EOF) {
            if ((fputc (Car, FdOut)) == EOF) 
                 return -2;  // errorea eman du idazten
            }
        else
            break;  // zatia 10 baino txikiagoa eta bukatu eginda fitxeroa
    }
    fclose (FdOut);
  }
  fclose (FdIn);

  return 0;   // ondo joan da
}

