#include "ariketa_cb.h"

int main(){
	//aldagaiak
	int aukera = 0;
	tMatriz matrizHasiera;
	tMatriz * matrizeHasiera_ptr = &matrizHasiera;
	int m = 0, n = 0;
	int fil = 0, col = 0;
	char nomFich[IZENA];
	FILE *fitxeroa;

	//programa

	printf("Fitxeroaren helbidea(sortuta badago sartu horren izena, bestela beste izen bat aukeratu): ");
	fflush(stdin);
	gets_s(nomFich, IZENA);

	do{
		printf("1. Fitxeroa sortu\n");
		printf("2. Matrizea bete\n");
		printf("TXARTO -> ");
		printf("3. Matrizea txikitu\n");
		printf("TXARTO -> ");
		printf("4. Matrizea bistaratu pantailan\n");
		printf("5. Matrizea borratu\n");
		printf("0. Irten\n");
		scanf("%i", &aukera);

		switch (aukera){

		case 1:
			fitxeroaSortu(nomFich);
			break;

		case 2:
			matrizeHasiera_ptr = cargarMatriz(nomFich);
			break;

		case 3:
			matrizeHasiera_ptr = reducirMatriz(matrizeHasiera_ptr, fil, col);
			break;

		case 4:
			imprimirMatriz(matrizeHasiera_ptr);
			break;
		
		case 5:
			liberarMemoria(matrizeHasiera_ptr);
			break;
		}

		system("cls");

	} while (aukera != 0);

	//bukaera
	fflush(stdin);
	return 0;
}

void fitxeroaSortu(char *nomFich){
	//aldagaiak
	FILE *fitxeroa;
	double zenbakia = 0;
	int m = 0, n = 0;
	int i = 0;

	//programa
	printf("Lerro kopurua: ");
	scanf("%i", &m);
	printf("Zutabe kopurua: ");
	scanf("%i", &n);

	fitxeroa = fopen(nomFich, "wb");

	fwrite(&m, sizeof (int), 1, fitxeroa);
	fwrite(&n, sizeof (int), 1, fitxeroa);

	for (i = 0; i < (m*n); i++){
		zenbakia = rand() % (MAX - MIN + 1) + MIN;
		fwrite(&zenbakia, sizeof (double), 1, fitxeroa);
	}
	fclose(fitxeroa);

	printf("Zure matrizea %s fitxeroan gorde da\n");

	fflush(stdin);
	getchar();

	//return
	return 0;
}

tMatriz * initMatriz(int m, int n){
	//aldagaiak
	tMatriz **matriz; /*Puntero de puntero*/
	int i = 0, j = 0;
	FILE *fitxeroa;

	//programa
	
	fitxeroa = fopen("matrizea.dat", "rb");
	fseek(fitxeroa, 2 * sizeof(int), SEEK_SET);

	matriz = malloc(sizeof (int*)*m);

	for (i = 0; i < m; i++){
		matriz[i] = malloc(sizeof (int)*n); /*reserva de memoria matriz*/
	}

	for (i = 0; i < m; i++){
		for (j = 0; j < n; j++){
			fread(&matriz[i][j], sizeof (int), 1, fitxeroa);
		}
	}

	for (i = 0; i< m; i++){ /*Imprimimos los valores */
		for (j = 0; j < n; j++){
			printf("Elemento (%d,%d) = %d\n", i, j, matriz[i][j]);
		}
	}

	//bukaera
	return matriz;
}

tMatriz * cargarMatriz(char *nomFich){
	//aldagaiak
	int i = 0, j = 0;
	int m = 0, n = 0;
	FILE *fitxeroa;
	tMatriz * matrizHasiera_ptr;

	//programa
	matrizHasiera_ptr = initMatriz(m, n);

	fitxeroa = fopen(nomFich, "rb");
	fread(&matrizHasiera_ptr->f, sizeof (int), 1, fitxeroa);
	fread(&matrizHasiera_ptr->c, sizeof (int), 1, fitxeroa);

	

	for (i = 0; i < m; i++){
		for (j = 0; j < n; j++){
			fread(&matrizHasiera_ptr->m[i][j], sizeof (int), 1, fitxeroa);
		}
	}

	//bukaera
	return matrizHasiera_ptr;
}

tMatriz * reducirMatriz(tMatriz *mat, int fil, int col){
	//aldagaiak

	//programa

	//bukaera

}

void imprimirMatriz(tMatriz *mat){
	//aldagaiak
	int i = 0, j = 0;
	//programa
	for (i = 0; i< mat->f; i++){
		for (j = 0; j < mat->c; j++){
			printf("Elemento (%d,%d) = %d\n", i, j, (mat->m)[i][j]);
		}
	}

	//bukaera

}

void liberarMemoria(tMatriz *mat){
	//aldagaiak
	int i = 0;
	//programa
	for (i = 0; i< mat->f; i++){
		free(&mat[i]);
	}

	//bukaera
	return 0;
}