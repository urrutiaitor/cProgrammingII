#include <stdio.h>
#include <string.h>

#define MAX 4

void kateaJaso(float *katea_ptr);
int ordenatu(float *f, int dim);
void kateaPrintatu(float *katea_ptr, int tamaina);

int main(){
	//aldagaiak
	float katea[MAX];
	float *katea_ptr;
	int tamaina = MAX;
	int ondo = 0;

	//programa
	katea_ptr = katea;
	kateaJaso(katea_ptr);
	ondo=ordenatu(katea_ptr, tamaina);
	if (ondo == 1){
		kateaPrintatu(katea_ptr, tamaina);
	}
	else{
		printf("Ezin izan da katea ondo ordenatu\n");
	}

	//bukaera
	printf("Sakatu ENTER bukatzeko\n");
	getchar();
	fflush(stdin);
	return 0;
}

void kateaJaso(float *katea_ptr){
	//aldagaiak
	int i = 0;
	int kantitatea = 0;

	//programa
	printf("Joan idazten nahi duzun zenbakiak:\n");

	for (i = 0; i < MAX; i++){
		printf("Sartu %i. zenbakia:", i+1);
		scanf("%f", katea_ptr+i);
		fflush(stdin);
	}

	return 0;
}

void kateaPrintatu(float *katea_ptr, int tamaina){
	//aldagaiak
	int i = 0;

	//programa
	printf("Zenbakien katea ordenatuta:\n");
	for (i = 0; i < MAX; i++){
		printf("%f\n", katea_ptr[i]);
	}
	printf("\n");
}

int ordenatu(float *f, int dim){
	//aldagaiak
	int i = 0, t = 0;
	int aux = 0;

	//programa
	for (i = 0; i < dim; i++){
		for (t = 0; t < dim; t++){
			if (f[t]>f[i]){
				aux = f[i];
				f[i] = f[t];
				f[t] = aux;
			}
		}
	}

	return 1;
}