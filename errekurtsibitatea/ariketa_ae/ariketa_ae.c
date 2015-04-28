#include <stdio.h>

#define MAX 200

int hitzak(char *esaldia_ptr, int aurrekoa, int hitzKop);

int main(){
	//aldagaiak
	char esaldia[MAX];
	char *esaldia_ptr = &esaldia[0];
	int hitzKop = 0;

	//programa
	printf("Sartu nahi duzun esaldia:\n");
	gets_s(esaldia, MAX);
	hitzKop = hitzak(esaldia_ptr,0,hitzKop);

	printf("%i hitza ditu esaldiak\n", hitzKop);
	

	//bukaera
	printf("Sakatu ENTER programa bukatzeko");
	fflush(stdin);
	getchar();
	return 0;
}

int hitzak(char *esaldia_ptr, int aurrekoa, int hitzKop){
	//aldagaiak

	//programa
	if (*esaldia_ptr == ' '){
		hitzKop = hitzak(esaldia_ptr+1,0,hitzKop);	
	}
	if ((*esaldia_ptr != ' ') && (*esaldia_ptr != '\0') && (aurrekoa==0)){
		hitzKop = hitzak(esaldia_ptr + 1, 1, hitzKop+1);
	}
	if ((*esaldia_ptr != ' ') && (*esaldia_ptr != '\0') && (aurrekoa == 1)){
		hitzKop = hitzak(esaldia_ptr + 1, 1, hitzKop);
	}
	return hitzKop;
}