#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#define MAX 30

int main(){    
    
    FILE *fd;
    int kont = 0;
    char fitxIzena[MAX];
    
    printf("\n\nEman fitxategiaren izena:  ");
    gets(fitxIzena);  
     
    if((fd = fopen(fitxIzena, "rb")) == NULL)
        printf("\n\n\n Fitxategia ez dago.\n");
    
    else{
        while(fgetc(fd)!= EOF) 
            kont++;
    
        fclose(fd);
        printf("\n\n \"%s\" fitxategiaren tamaina = %i byte\n\n", fitxIzena, kont);
    }
    
    system("PAUSE");	
    return 0;
}
