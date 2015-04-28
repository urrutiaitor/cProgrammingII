#include <stdio.h>

int main(){
	//aldagaiak
	int tamaina = 0;
	int *helbidea_ptr = 0;
	int i = 0;

	//programa
	printf("Zenbateko arraya nahi duzu sortu (int motako zenbakiak sartzeko)?\n");
	scanf("%i", &tamaina);

	printf("Joan sartzen nahi dituzun zenbakiak:\n");
	for (i = 0; i < tamaina; i++){
		helbidea_ptr = (int *)malloc(sizeof(int));
		scanf("%i", helbidea_ptr);
		printf("%i\n", *helbidea_ptr);
	}
	//bukaera
	printf("Sakatu ENTER programa bukatzeko\n");
	fflush(stdin);
	getchar();
	return 0;
}