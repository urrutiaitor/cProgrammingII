#include "main.h"

int hautaketaZuzena(int zerrenda[], int kopurua){
	//aldagaiak
	int i = 0, t = 0;
	int aux = 0;
	int t_iniziala = 0, t_finala = 0, t_totala = 0;

	//programa
	t_iniziala = clock();

	for (i = 0; i < kopurua; i++){
		for (t = i + 1; t < kopurua; t++){
			if (zerrenda[i]>zerrenda[t]){
				aux = zerrenda[i];
				zerrenda[i] = zerrenda[t];
				zerrenda[t] = aux;
			}
		}
	}
	
	t_finala = clock();
	t_totala = (t_finala - t_iniziala);

	if (kopurua == 30000){
		BISTARATU_30000zenbakiBistaratu(zerrenda);
	}
	if (kopurua == 50000){
		BISTARATU_50000zenbakiBistaratu(zerrenda);
	}

	//bukaera
	return t_totala;
	
}

int hautaketaZuzena_hobetua(int zerrenda[], int kopurua){
	//aldagaiak
	int i = 0, t = 0;
	int aux = 0;
	int t_iniziala = 0, t_finala = 0, t_totala = 0;
	int txikiena = 0;

	//programa
	t_iniziala = clock();

	for (i = 0; i < kopurua; i++){
		txikiena = i;
		for (t = i + 1; t < kopurua; t++){
			if (zerrenda[txikiena]>zerrenda[t]){
				txikiena = t;
			}
		}
		aux = zerrenda[i];
		zerrenda[i] = zerrenda[txikiena];
		zerrenda[txikiena] = aux;
	}

	t_finala = clock();
	t_totala = (t_finala - t_iniziala);

	if (kopurua == 30000){
		BISTARATU_30000zenbakiBistaratu(zerrenda);
	}
	if (kopurua == 50000){
		BISTARATU_50000zenbakiBistaratu(zerrenda);
	}

	//bukaera
	return t_totala;

}

int burbuila(int zerrenda[], int kopurua){
	//aldagaiak
	int i = 0;
	int zuzena = 0;
	int aux = 0;
	int t_iniziala = 0, t_finala = 0, t_totala = 0;

	//programa
	t_iniziala = clock();

	while (zuzena == 0){
		zuzena = 1;
		for (i = 0; i < kopurua - 1; i++){
			if (zerrenda[i]>zerrenda[i + 1]){
				aux = zerrenda[i];
				zerrenda[i] = zerrenda[i + 1];
				zerrenda[i + 1] = aux;
				zuzena = 0;
			}
		}
	}
	t_finala = clock();
	t_totala = (t_finala - t_iniziala);

	if (kopurua == 30000){
		BISTARATU_30000zenbakiBistaratu(zerrenda);
	}
	if (kopurua == 50000){
		BISTARATU_50000zenbakiBistaratu(zerrenda);
	}

	//bukaera
	return t_totala;
}

int burbuila_hobetua(int zerrenda[], int kopurua){
	//aldagaiak
	int i = 0;
	int zuzena = 0;
	int aux = 0;
	int t_iniziala = 0, t_finala = 0, t_totala = 0;
	int hasiera = 0;

	//programa
	t_iniziala = clock();

	while (zuzena == 0){
		zuzena = 1;
		for (i = 0; i < kopurua - 1; i++){
			if (zerrenda[i]>zerrenda[i + 1]){
				aux = zerrenda[i];
				zerrenda[i] = zerrenda[i + 1];
				zerrenda[i + 1] = aux;
				zuzena = 0;
			}
			if ((zuzena == 1)&&(i>0)){
				hasiera = i - 1;
			}
		}
	}
	t_finala = clock();
	t_totala = (t_finala - t_iniziala);

	if (kopurua == 30000){
		BISTARATU_30000zenbakiBistaratu(zerrenda);
	}
	if (kopurua == 50000){
		BISTARATU_50000zenbakiBistaratu(zerrenda);
	}

	//bukaera
	return t_totala;
}

int txertaketaZuzena(int zerrenda[], int kopurua){
	//aldagaiak
	int i = 0, t = 0;
	int aux = 0;
	int t_iniziala = 0, t_finala = 0, t_totala = 0;

	//programa
	t_iniziala = clock();

	for (i = 1; i < kopurua; i++){
		for (t = i - 1; t >= 0; t--){
			if (zerrenda[t]>zerrenda[t + 1]){
				aux = zerrenda[t];
				zerrenda[t] = zerrenda[t + 1];
				zerrenda[t + 1] = aux;
			}
		}
	}

	t_finala = clock();
	t_totala = (t_finala - t_iniziala);

	if (kopurua == 30000){
		BISTARATU_30000zenbakiBistaratu(zerrenda);
	}
	if (kopurua == 50000){
		BISTARATU_50000zenbakiBistaratu(zerrenda);
	}

	//bukaera
	return t_totala;
}

int txertaketaZuzena_hobetua(int zerrenda[], int kopurua){
	//aldagaiak
	int i = 0, t = 0;
	int aux = 0;
	int t_iniziala = 0, t_finala = 0, t_totala = 0;

	//programa
	t_iniziala = clock();

	for (i = 1; i < kopurua; i++){
		for (t = i - 1; t >= 0; t--){
			if (zerrenda[t]>zerrenda[t + 1]){
				aux = zerrenda[t];
				zerrenda[t] = zerrenda[t + 1];
				zerrenda[t + 1] = aux;
			}
		}
	}

	t_finala = clock();
	t_totala = (t_finala - t_iniziala);

	if (kopurua == 30000){
		BISTARATU_30000zenbakiBistaratu(zerrenda);
	}
	if (kopurua == 50000){
		BISTARATU_50000zenbakiBistaratu(zerrenda);
	}

	//bukaera
	return t_totala;
}

int shellSort(int zerrenda[], int kopurua){
	//aldagaiak
	int i = 0, j = 0;
	int increment = 0, temp = 0;
	int t_iniziala = 0, t_finala = 0, t_totala = 0;

	//programa
	t_iniziala = clock();

	for (increment = kopurua / 2; increment > 0; increment /= 2){
		for (i = increment; i<kopurua; i++){
			temp = zerrenda[i];
			for (j = i; j >= increment; j -= increment){
				if (temp < zerrenda[j - increment]){
					zerrenda[j] = zerrenda[j - increment];
				}
				else{
					break;
				}
			}
			zerrenda[j] = temp;
		}
	}

	t_finala = clock();
	t_totala = (t_finala - t_iniziala);

	if (kopurua == 30000){
		BISTARATU_30000zenbakiBistaratu(zerrenda);
	}
	if (kopurua == 50000){
		BISTARATU_50000zenbakiBistaratu(zerrenda);
	}

	//bukaera
	return t_totala;

}

int quickSort(int zerrenda[], int kopurua){
	//aldagaiak
	int t_iniziala = 0, t_finala = 0, t_totala = 0;

	//programa
	t_iniziala = clock();

	quicksort_funtzioRekurtsiboa(zerrenda, 0, kopurua);

	t_finala = clock();
	t_totala = (t_finala - t_iniziala);

	if (kopurua == 30000){
		BISTARATU_30000zenbakiBistaratu(zerrenda);
	}
	if (kopurua == 50000){
		BISTARATU_50000zenbakiBistaratu(zerrenda);
	}

	//bukaera
	return t_totala;
}

void quicksort_funtzioRekurtsiboa(int zerrenda[], int start, int end){
	//aldagaiak
	int pivot;

	//programa

	if (start < end) {
		pivot = divide(zerrenda, start, end);

		// Ordeno la lista de los menores
		quicksort_funtzioRekurtsiboa(zerrenda, start, pivot - 1);

		// Ordeno la lista de los mayores
		quicksort_funtzioRekurtsiboa(zerrenda, pivot + 1, end);
	}
}

int divide(int *array, int start, int end){
	//aldagaiak
	int left;
	int right;
	int pivot;
	int temp;

	//programa
	pivot = array[start];
	left = start;
	right = end;

	while (left < right) {
		while (array[right] > pivot) {
			right--;
		}

		while ((left < right) && (array[left] <= pivot)) {
			left++;
		}

		if (left < right) {
			temp = array[left];
			array[left] = array[right];
			array[right] = temp;
		}
	}

	temp = array[right];
	array[right] = array[start];
	array[start] = temp;

	//bukaera
	return right;
}