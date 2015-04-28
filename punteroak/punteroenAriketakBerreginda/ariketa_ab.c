#include <stdio.h>
#include <string.h>

#define MAX 1024

int nire_strlen(const char *s);
void kateaPrintatu(char *katea_ptr, int tamaina);

int main(){
	//aldagaiak
	char katea[MAX];
	char *katea_ptr;
	int tamaina;

	//programa
	katea_ptr = katea;
	tamaina = nire_strlen(katea_ptr);
	printf("Kateak %i karaktere ditu\n", tamaina);

	//bukaera
	printf("Sakatu ENTER bukatzeko\n");
	getchar();
	fflush(stdin);
	return 0;
}

int nire_strlen(const char *s){
	//aldagaiak
	int i = 0;
	int kantitatea = 0;

	//programa
	printf("Idatzi zuk nahi duzun esaldia:\n");
	fflush(stdin);
	gets(s);

	for (i = 0; i < MAX; i++){
		if (s[i] == '\0'){
			kantitatea = i;
		}
	}

	return kantitatea;
}