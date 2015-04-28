#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

void alderantziz1(char *karaktereKatea_ptr);
char *alderantziz2(char *karaktereKatea_ptr, char *karaktereKateaOrdenatuta_ptr);


int main(){
	//aldagaiak
	char karaktereak[MAX];
	char karaktereakOrdenatuta[MAX];
	char *karaktereak_ptr = &karaktereak;
	char *karaktereakOrdenatuta_ptr = &karaktereakOrdenatuta;
	int karaktereKop = 0;
	
	//programa
	printf("Zein karaktere kate nahi duzu alderantziz jarri?\n");
	gets_s(karaktereak, MAX);
	karaktereKop = strlen(karaktereak);
	alderantziz1(karaktereak);
	alderantziz2(karaktereak, karaktereakOrdenatuta_ptr+ karaktereKop);
	printf("\n\n2. metodoa erabiliz:\n");
	printf("%s\n\n", karaktereakOrdenatuta);


	//bukaera
	printf("Sakatu ENTER programa bukatzeko");
	fflush(stdin);
	getchar();
	return 0;
}

void alderantziz1(char *karaktereKatea_ptr){
	//aldagaiak

	//programa
	if (*karaktereKatea_ptr != '\0'){
		alderantziz1(karaktereKatea_ptr + 1);
		printf("%c", *karaktereKatea_ptr);
	}

	//return
	return 0;
}

char *alderantziz2(char *karaktereKatea_ptr, char *karaktereKateaOrdenatuta_ptr){
	//aldagaiak
	

	//programa
	if (*karaktereKatea_ptr != '\0'){
		karaktereKateaOrdenatuta_ptr=alderantziz2(karaktereKatea_ptr + 1, karaktereKateaOrdenatuta_ptr);
		*karaktereKateaOrdenatuta_ptr = *karaktereKatea_ptr;
		return karaktereKateaOrdenatuta_ptr + 1;
	}
}