#include <stdio.h>
#include <stdlib.h>

#define MAX 100

char palindromoa(char *karaktereaIniziala_ptr, char *karaktereaFinala_ptr, int buklea);

int main(){
	//aldagaiak
	char karaktereak[MAX];
	char *karaktereaIniziala_ptr;
	char *karaktereaFinala_ptr;
	int emaitza = 0;
	int karaktereKop = 0;

	//programa
	printf("Zein karaktere kate nahi duzu konprobatu palindromoa den edo ez?\n");
	gets_s(karaktereak, MAX);
	karaktereKop = strlen(karaktereak);
	karaktereaFinala_ptr = &karaktereak[karaktereKop - 1];
	karaktereaIniziala_ptr = &karaktereak;
	emaitza = palindromoa(karaktereaIniziala_ptr,karaktereaFinala_ptr, karaktereKop);
	if (emaitza == 0){
		printf("Zuk idatzitako karaktere katea ez da palindromoa\n");
	}
	else{
		printf("Zuk idatzitzako karaktere katea palindromoa da\n");
	}


	//bukaera
	printf("Sakatu ENTER programa bukatzeko");
	fflush(stdin);
	getchar();
	return 0;
}

char palindromoa(char *karaktereaIniziala_ptr, char *karaktereaFinala_ptr, int buklea){

	//aldagaiak
	int ret = 1;

	//programa
	while (*karaktereaIniziala_ptr == ' '){
		karaktereaIniziala_ptr++;
		buklea--;
	}
	while (*karaktereaFinala_ptr == ' '){
		karaktereaFinala_ptr--;
		buklea--;
	}
	if (buklea>0){
		ret = palindromoa(karaktereaIniziala_ptr + 1, karaktereaFinala_ptr - 1, buklea-2);
	}
	if (*karaktereaFinala_ptr == *karaktereaIniziala_ptr){
		ret = ret * 1;
	}
	else{
		ret = 0;
	}

	//return
	return ret;
}