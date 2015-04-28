#include <Windows.h>
#include <stdio.h>

static int getch_c (void);

int main (void) {
	char car;

	printf("Introduce un caracter: ");
	car = getch_c();
	printf("\n");
	printf("Lo leido:  %c\n", car);

	system("pause");
	return 0;
}

static int getch_c(void){  // lectura de caracter sin eco
    int car;   
    DWORD leidos, modo;    
    
    GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &modo);      
    SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), modo & !ENABLE_ECHO_INPUT & !ENABLE_PROCESSED_INPUT);
    ReadConsole(GetStdHandle(STD_INPUT_HANDLE), &car, 1, &leidos, NULL);   
    SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), modo);      
    
    return car;        
}