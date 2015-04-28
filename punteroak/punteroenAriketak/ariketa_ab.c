#include <stdio.h>
#include <string.h>

#define MAX 1024

int kateaJaso(char *katea_ptr);
void kateaPrintatu(char *katea_ptr, int tamaina);

int main(){
	//aldagaiak
	char katea[MAX];
	char *katea_ptr;
	int tamaina;

	//programa
	katea_ptr = katea;
	tamaina = kateaJaso(katea_ptr);
	printf("Kateak %i karaktere ditu\n", tamaina);

	//bukaera
	printf("Sakatu ENTER bukatzeko\n");
	getchar();
	fflush(stdin);
	return 0;
}

int kateaJaso(char *katea_ptr){
	//aldagaiak
	int i = 0;
	int kantitatea = 0;

	//programa
	printf("Idatzi zuk nahi duzun esaldia:\n");
	fflush(stdin);
	gets(katea_ptr);

	for (i = 0; i < MAX; i++){
		if (katea_ptr[i] == '\0'){
			kantitatea = i;
		}
	}

	return kantitatea;
}