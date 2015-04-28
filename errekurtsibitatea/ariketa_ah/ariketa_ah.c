#include <stdio.h>

#define MAX 200

float sin(float zenbakia);
float cos(float zenbakia);

int main(){
	//aldagaiak
	float zenbakia = 0;
	float emaitza = 0;
	int aukera = 0;

	//programa
	printf("1. cos(x)\n");
	printf("2. sin(x)\n");
	scanf("%i", &aukera);
	printf("(Radianetan)\nx = ");
	scanf("%f", &zenbakia);

	if (aukera == 1){
		emaitza = cos(zenbakia);
		printf("cos(%.2f) = %.2f\n", zenbakia, emaitza);
	}
	if (aukera == 2){
		emaitza = sin(zenbakia);
		printf("sin(%.2f) = %.2f\n", zenbakia, emaitza);
	}


	//bukaera
	printf("Sakatu ENTER programa bukatzeko");
	fflush(stdin);
	getchar();
	return 0;
}

float cos(float zenbakia){
	//aldagaiak
	float emaitza = 0;

	//programa
	if (zenbakia >= 1){
		emaitza = (cos(zenbakia / 2)*cos(zenbakia / 2)) - (sin(zenbakia / 2)*sin(zenbakia / 2));
	}
	if (zenbakia < 1){
		emaitza = 1 - 0.5*(zenbakia*zenbakia);
	}

	//return
	return emaitza;
}

float sin(float zenbakia){
	//aldagaiak
	float emaitza = 0;

	//programa
	if (zenbakia >= 1){
		emaitza = 2*sin(zenbakia/2)*cos(zenbakia/2);
	}
	if (zenbakia < 1){
		emaitza = zenbakia;
	}

	//return
	return emaitza;
}