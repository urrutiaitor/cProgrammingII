#ifndef ARIKETA_CB_H
#define ARIKETA_CB

#include <stdio.h>
#include <math.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000
#define MIN -10000
#define IZENA 100

typedef struct Matriz{
	int f;
	int c;
	double **m;
}tMatriz;

void fitxeroaSortu(char *nomFich);
tMatriz * initMatriz(int m, int n);
tMatriz * cargarMatriz(char *nomFich);
tMatriz * reducirMatriz(tMatriz *mat, int fil, int col);
void imprimirMatriz(tMatriz *mat);
void liberarMemoria(tMatriz *mat);


#endif