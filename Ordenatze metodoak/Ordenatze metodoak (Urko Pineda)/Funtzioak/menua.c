int *menua(int *punauk){
	printf("ORDENATZE METODOAK - URKO PINEDA\n");
	printf("\n");
	printf("Zenbakiak ordenatu...:\n");
	printf("	1-. ...hautaketa zuzena erabiliz.\n");
	printf("	2-. ...burbuila erabiliz.\n");
	printf("	3-. ...ShellShort erabiliz.\n");
	printf("	4-. ...QuickShort erabiliz.\n");
	printf("	0-. IRTEN.\n");
	printf("\n");
	printf("Sartu zure aukera --> \n");
	scanf_s("%i", punauk);
	return(punauk);
}