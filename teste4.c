#include <stdio.h>

#define MAX 80

int main(void)
{
	FILE *pa;
	char frase[MAX];

	pa = fopen("teste4.txt","w+");

	fgets(frase, MAX, pa);
	while(!feof(stdin))
	{
		fputs(frase, pa);
		fgets(frase, MAX, stdin);
	}

	rewind(pa);

	printf("Terminei de escrever # partiu ler");
	
	fgets(frase, MAX, pa);
	while(!feof(pa))
	{
		puts(frase);
		fgets(frase, MAX, pa);
	}
	fclose(pa);

	return 0;
}
