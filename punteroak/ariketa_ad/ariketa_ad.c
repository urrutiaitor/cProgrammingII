#include <stdio.h>
#include <string.h>

#define MAX 1024

void kateaJaso(char *katea_ptr);
int nire_strcmp(const char *s1, const char *s2);

int main(){
	//aldagaiak
	char katea_1[MAX];
	char katea_2[MAX];
	char *katea_ptr_1;
	char *katea_ptr_2;
	int tamaina;
	int i = 0;
	int emaitza = 0;

	//programa

	katea_ptr_1 = &katea_1;
	katea_ptr_2 = &katea_2;
	kateaJaso(katea_ptr_1);
	kateaJaso(katea_ptr_2);

	emaitza=nire_strcmp(katea_ptr_1,katea_ptr_2);
	if (emaitza > 0){
		printf("Lehenengo katea handiagoa da\n");
	}
	if (emaitza < 0){
		printf("Bigarren katea handiagoa da\n");
	}
	if (emaitza == 0){
		printf("Kate biak baliokideak dira\n");
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

int nire_strcmp(const char *s1, const char *s2){
	//aldagaiak
	int i = 0, bukatu = 0;
	int emaitza = 0;

	//programa
	while ((i < MAX) && (bukatu == 0)){
		if ((*(s1 + i) == '\0') && (*(s2 + i) == '\0')){
			emaitza = 0;
			bukatu = 1;
		}
		if ((*(s1 + i) == '\0') && (*(s2 + i) != '\0')){
			emaitza = -1;
			bukatu = 1;
		}
		if ((*(s1 + i) != '\0') && (*(s2 + i) == '\0')){
			emaitza = +1;
			bukatu = 1;
		}
		if (*(s1 + i) > *(s2 + i)){
			emaitza = +1;
			bukatu = 1;
		}
		if (*(s1 + i) < *(s2 + i)){
			emaitza = -1;
			bukatu = 1;
		}
		i++;

	}

	//return
	return emaitza;
}