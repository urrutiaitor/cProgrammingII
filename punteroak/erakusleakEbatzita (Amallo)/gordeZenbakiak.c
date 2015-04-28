/* gordeZenbakiak.c  */
/*
 * zenbaki errealak irakurri eta gorde fitxeroan (fitxero bitarra).
 * zenbakiak irakurriko dira ENTER soilik sartu arte.
 *
 * Autores:
 *   + 
 *
 * Copyright (C) 2003 MGEP-MU
 *     Revisiones: 2006, 2009, 2011
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/************ Konstanteen deklarazioa **************/
#define DIM 100       // bektorean tamaina
#define ZENBDIM 20    // zenbakiaren digitu kopurua

/* ------------------- funtzioen prototipoak ------------------ */
static void irakurriZenbakiak (double [], int *);
static int  gordeFitxeroan    (char *izenaFitx, double  [], int );


/* ---------------- Programa Nagusia ------------------ */
int main (void)
{
  char   izenaFitx [DIM];
  double zerrenda  [DIM];
  int    dim;
  int    Err;

  printf ("Programa honek zenbaki errealak fitxeroan gordeko du.\n");

  printf ("Fitxeroaren izena: ");
  gets (izenaFitx);

  irakurriZenbakiak (zerrenda, &dim);

  Err = gordeFitxeroan (izenaFitx, zerrenda, dim);

  switch (Err) {
    case -1:
      fprintf (stderr, "Ezin izan du ireki \"%s\" fitxeroa.\n", izenaFitx);
      break;
    case -2:
         fprintf(stderr, "Ez du ondo gorde zenbakiak\n");
         break;
    case 0:
         fprintf(stderr,"\n\tDena ondo bukatu da.\n\n");
  }

  printf ("Sakatu <Intro>"); getchar ();
  return 0;
}

static void irakurriZenbakiak (double zerrenda [], int *dim)
{
  char str [ZENBDIM];  // zenbakiaren karaktere zerrenda
  int  kont;           // zenbaki kopurua bektorean

  printf ("Zenbaki errealak irakurtzera goaz. "
          "\nIrakurketa bukatzeko eman RETURN soilik.\n");

  printf ("Aurrera: \n");
  for (kont = 0; kont < DIM; kont++) {  
	  gets (str);
     if (!str [0])
          break;
	  sscanf (str, "%lf", &zerrenda [kont]);
  }

  *dim = kont;
}

static int gordeFitxeroan (char *izenaFitx, double zerrenda [], int dim)
{
  FILE *Fd;
  int   Err = 0;  // ez dago errorerik

  Fd = fopen (izenaFitx, "wb");
  if (!Fd)
    return -1;  // ezin izan du ireki
    
  if (fwrite (zerrenda, sizeof (double), dim, Fd) != dim)
    Err = -2;  // ez du gorde zenbakiak
 

  fclose (Fd);

  return Err;
}

