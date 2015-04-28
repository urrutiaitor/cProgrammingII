#include <stdio.h>
#include <string.h>

#define MAX 1024

int kateaJaso(char *katea_ptr);
int kapikua(char *katea_ptr, int tamaina);
void kateaPrintatu(char *katea_ptr, int tamaina);

int main(){
	//aldagaiak
	char katea[MAX];
	char *katea_ptr;
	int tamaina;

	//programa
	katea_ptr = katea;
	tamaina = kateaJaso(katea_ptr);
	if (kapikua(katea_ptr,tamaina) == 1){
		printf("Zuk idatzitako esaldia kapikua da\n");
	}
	else{
		printf("Zuk idatzitako esaldia ez da kapikua\n");
	}
	kateaPrintatu(katea_ptr, tamaina);

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

void kateaPrintatu(char *katea_ptr, int tamaina){
	//aldagaiak
	int i = 0;

	//programa
	printf("Esaldia aurretik atzera:\n");
	for (i = 0; (i < tamaina)&&(*katea_ptr!='\0'); i++){
		printf("%c", katea_ptr[i]);
	}
	printf("\n");

	printf("Esaldia atzetik aurrera:\n");
	for (i = tamaina-1; (i >= 0) && (*katea_ptr != '\0'); i--){
		printf("%c", katea_ptr[i]);
	}
	printf("\n\n");
}

int kapikua(char *katea_ptr, int tamaina){
	//aldagaiak
	int i = 0, t = tamaina - 1;
	int kapikua = 1;

	//programa
	while ((i <= t)&&(kapikua==1)){
		while (katea_ptr[i] == ' '){
			i++;
		}
		while (katea_ptr[t] == ' '){
			t--;
		}
		if (katea_ptr[i] != katea_ptr[t]){
			kapikua = 0;
		}
		i++;
		t--;

	}

	return kapikua;
}