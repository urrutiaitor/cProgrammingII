#include <stdio.h>
#include <string.h>

#define MAX 100

void kateaJaso(int *katea_ptr);
void ordenatu(int *katea_ptr, int tamaina);
void kateaPrintatu(int *katea_ptr, int tamaina);

int main(){
	//aldagaiak
	int katea[MAX];
	int *katea_ptr;
	int tamaina = 0;

	//programa
	katea_ptr = katea;
	kateaJaso(katea_ptr);
	ordenatu(katea_ptr, tamaina);
	kateaPrintatu(katea_ptr, tamaina);

	//bukaera
	printf("Sakatu ENTER bukatzeko\n");
	getchar();
	fflush(stdin);
	return 0;
}

void kateaJaso(int *katea_ptr){
	//aldagaiak
	int i = 0;
	int kantitatea = 0;

	//programa
	printf("Joan idazten nahi duzun zenbakiak:\n");

	for (i = 0; i < MAX; i++){
		printf("Sartu %i. zenbakia:", i+1);
		scanf("%i", katea_ptr+i);
		fflush(stdin);
	}

	return 0;
}

void kateaPrintatu(int *katea_ptr, int tamaina){
	//aldagaiak
	int i = 0;

	//programa
	printf("Zenbakien katea ordenatuta:\n");
	for (i = 0; i < MAX; i++){
		printf("%i\n", katea_ptr[i]);
	}
	printf("\n");
}

void ordenatu(int *katea_ptr){
	//aldagaiak
	int i = 0, t = 0;
	int aux = 0;

	//programa
	for (i = 0; i < MAX; i++){
		for (t = 0; t < MAX; t++){
			if (katea_ptr[t]>katea_ptr[i]){
				aux = katea_ptr[i];
				katea_ptr[i] = katea_ptr[t];
				katea_ptr[t] = aux;
			}
		}
	}

	return 0;
}