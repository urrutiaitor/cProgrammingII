/* gordetakoakOrdenatu.c  */
/* Zenbaki erreal zekuentzia bat irakurri fitxategi batetik eta ordenatuz 
 * gero bistaratu.
 * Baldintza jarriko da 100 zenbaki baino gutxiago izatea.
 *  Autores:
 *   + 
 *   + 
 * Copyright (C) 2003 MGEP-MU
 *      Revision:   2006, 2010, 2011
 */

/***************** funtzioen deklarazioak *********************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ------------------- funtzioen prototipoak ------------------ */
static int  irakurFitxZenb (const char *izenaFitx, double []);
static void ordenatuZenb (double [], int );
static void aldaketa     (double *X, double *Y);
static void bistaratuZenb   (double [], int );

/************ Konstanteen deklarazioa **************/
#define DIM 100

/*--------------------- Programa Nagusia --------------------*/
int main (void)
{
  char   izenFitx [80];
  double zerrenda [DIM];
  int    dim;
  int    Err = 0;  // ondo joan da

  printf ("Programak zenbakiak irakurriko ditu fitxategian, gero ordenatu eta bistaratu.\n");

  printf ("\n\tFitxeroan izena:  ");
  gets (izenFitx);

  Err = dim = irakurFitxZenb (izenFitx, zerrenda);
       
  if (Err == -1) {  /* Caso de que no haya abierto el fichero */
       fprintf (stderr, "\n\tEzin da ireki \"%s\" fitxeroa.\n", izenFitx);
       getchar();
       return 1;     // devuelve al S.O. como error
  }

  ordenatuZenb (zerrenda, dim);
  bistaratuZenb   (zerrenda, dim);

  printf ("Sakatu <Intro>"); getchar ();
  return 0;
}

static int irakurFitxZenb (const char *izenFitx, double zerrenda [])
{
  FILE *Fd;
  int   kont;
  
  Fd = fopen (izenFitx, "rb");
  if (!Fd)
    return -1;

                 // egia den bitartean egingo du
  for (kont = 0; fread (&zerrenda [kont], sizeof (double), 1, Fd); kont++);

  return kont;
}

static void ordenatuZenb (double zerrenda [], int dim)
{
  int i, j, indMin;

  for (i = 0; i < dim - 1; i++) {
    indMin = i;
    for (j = i + 1; j < dim; j++)
      if (zerrenda [j] < zerrenda [indMin])
        indMin = j;
    aldaketa (&zerrenda [i], &zerrenda [indMin]);
  }
}

static void aldaketa (double *X, double *Y)
{
  double aux;

  aux = *X;
  *X = *Y;
  *Y = aux;
}

static void bistaratuZenb (double zerrenda [], int dim)
{
  int kont;

  printf ("\nZenbakien zerrenda Ordenatuta:\n");
  for (kont = 0; kont < dim; kont++)
    printf ("%2d: %8.3lf\n", kont, zerrenda [kont]);
}

