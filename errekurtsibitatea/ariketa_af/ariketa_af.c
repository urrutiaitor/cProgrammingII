#include<stdio.h>

void pausoak(int n, char aMakila, char bMakila, char cMakila);

int main(){
	int n = 0;
	char aMakila = 'A', bMakila = 'B', cMakila = 'C';

	printf("Zenbat disko dituzu?\n");
	scanf("%i", &n);
	pausoak(n, aMakila, bMakila, cMakila);

	printf("Sakatu ENTER bukatzeko\n");
	fflush(stdin);
	getchar();

	return 0;
}

void pausoak(int n, char aMakila, char bMakila, char cMakila){

	if (n == 1){
		printf("%c-tik %c-ra pasa diskoa\n", aMakila, cMakila);
	}
	else{
		pausoak(n - 1, aMakila, cMakila, bMakila);
		printf("%c-tik %c-ra pasa diskoa\n", aMakila, cMakila);
		pausoak(n - 1, bMakila, aMakila, cMakila);
	}
}

