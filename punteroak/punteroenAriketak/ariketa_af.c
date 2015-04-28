#include <stdio.h>
#include <string.h>

#define MAX 1024

void kateaJaso(char *katea_ptr);
int kateakKonprobatu(char *katea_ptr_1, char *katea_ptr_2);

int main(){
	//aldagaiak
	char katea_1[MAX];
	char katea_2[MAX];
	char *katea_ptr_1;
	char *katea_ptr_2;
	int tamaina;
	int i = 0;

	//programa
	katea_ptr_1 = &katea_1;
	katea_ptr_2 = &katea_2;
	kateaJaso(katea_ptr_1);
	kateaJaso(katea_ptr_2);

	i=kateakKonprobatu(katea_ptr_1, katea_ptr_2);

	if (i == 1){
		printf("Bigarrena lehenengoaren barruan dago\n");
	}
	if (i == 0){
		printf("Bigarrena ez dago lehenengoaren barruan\n");
	}

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

int kateakKonprobatu(char *katea_ptr_1, char *katea_ptr_2){
	//aldagaiak
	int i = 0, t = 0;
	int bukatu = 0;
	int bukatu_aux = 0;
	int emaitza = 0;

	//programa

	while ((*(katea_ptr_1 + i) != '\0') && (bukatu==0)){
		if (*(katea_ptr_1 + i) == *(katea_ptr_2)){
			emaitza = 0;
			bukatu_aux = 0;
			t++;
			while ((*(katea_ptr_2 + t) != '\0') && (bukatu_aux == 0)){
				if (*(katea_ptr_1 + i + t) == *(katea_ptr_2 + t)){
					emaitza = 1;
				}
				else{
					bukatu_aux = 1;
				}
				t++;
			}
		}
		i++;
	}
	


	//return
	return emaitza;

}