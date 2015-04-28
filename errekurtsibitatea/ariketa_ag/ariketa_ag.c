#include <stdio.h>

#define MAX 200

float expon(float zenbakia);

int main(){
	//aldagaiak
	float zenbakia = 0;
	float emaitza = 0;

	//programa
	printf("e^x -> x = ");
	scanf("%f", &zenbakia);

	emaitza = expon(zenbakia);

	printf("e^%.2f = %.2f\n", zenbakia, emaitza);


	//bukaera
	printf("Sakatu ENTER programa bukatzeko");
	fflush(stdin);
	getchar();
	return 0;
}

float expon(float zenbakia){
	//aldagaiak
	float emaitza = 0;

	//programa
	if (zenbakia>=1){
		emaitza=expon(zenbakia / 2)*expon(zenbakia / 2);
	}
	if (zenbakia < 1){
		emaitza = 1 + zenbakia;
	}

	//return
	return emaitza;
}