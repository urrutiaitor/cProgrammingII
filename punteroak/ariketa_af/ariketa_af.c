#include <stdio.h>
#include <string.h>

#define MAX 1024

void kateaJaso(char *katea_ptr);
char  * nire_strstr(const char *s1, const char *s2);

int main(){
	//aldagaiak
	char katea_1[MAX];
	char katea_2[MAX];
	char *katea_ptr_1;
	char *katea_ptr_2;
	int tamaina;
	int i = 0;
	char *hasiera;

	//programa
	katea_ptr_1 = &katea_1;
	katea_ptr_2 = &katea_2;
	kateaJaso(katea_ptr_1);
	kateaJaso(katea_ptr_2);

	hasiera=nire_strstr(katea_ptr_1, katea_ptr_2);

	if (hasiera != NULL){
		printf("Bigarrena lehenengoaren barruan dago\n");
	}
	if (hasiera == NULL){
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

char  * nire_strstr(const char *s1, const char *s2){
	//aldagaiak
	int i = 0, t = 0;
	int bukatu = 0;
	int bukatu_aux = 0;
	int emaitza = 0;
	char *ret = NULL;

	//programa

	while ((*(s1 + i) != '\0') && (bukatu==0)){
		if (*(s1 + i) == *(s2)){
			emaitza = 0;
			bukatu_aux = 0;
			t++;
			while ((*(s2 + t) != '\0') && (bukatu_aux == 0)){
				if (*(s1 + i + t) == *(s2 + t)){
					if (emaitza == 0){
						ret = s1 + i + t;
					}
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
	return ret;

}