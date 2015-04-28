#include <stdio.h>
#include <string.h>

#define MAX 1024

void kateaJaso(char *katea_ptr);
void kateakBatu(char *katea_ptr_1, char *katea_ptr_2, char *katea_batuta);

int main(){
	//aldagaiak
	char katea_1[MAX];
	char katea_2[MAX];
	char katea_batuta[2 * MAX];
	char *katea_ptr_1;
	char *katea_ptr_2;
	char *katea_ptr_batuta;
	int tamaina;
	int i = 0;

	//programa
	katea_ptr_1 = &katea_1;
	katea_ptr_2 = &katea_2;
	katea_ptr_batuta = &katea_batuta;
	kateaJaso(katea_ptr_1);
	kateaJaso(katea_ptr_2);

	kateakBatu(katea_ptr_1, katea_ptr_2,katea_ptr_batuta);

	printf("%s\n", katea_ptr_batuta);

	//bukaera
	printf("Sakatu ENTER bukatzeko\n");
	getchar();
	fflush(stdin);
	return 0;
}

void kateaJaso(char *katea_ptr){
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

	return 0;
}

void kateakBatu(char *katea_ptr_1, char *katea_ptr_2, char *katea_batuta){
	//aldagaiak
	int i=0, t = 0;
	int bukatu = 0;
	int bukatu_aux = 0;

	//programa

	while ((t < MAX) && (*(katea_ptr_1 + t) != '\0')){
		katea_batuta[i] = katea_ptr_1[t];
		i++;
		t++;
	}
	t = 0;
	while ((t < MAX) && (*(katea_ptr_2 + t) != '\0')){
		katea_batuta[i] = katea_ptr_2[t];
		i++;
		t++;
	}
	katea_batuta[i] = '\0';


	//return
	return 0;

}