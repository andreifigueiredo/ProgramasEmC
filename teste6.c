#include <stdio.h>

int main(void)
{
	char *nome = "teste6.txt";
	char c;
	FILE *pa;

	if((pa = fopen(nome, "w+")) == NULL)
	{
		printf("Não foi possivel abrir o arquivo\n");
		return 1;
	}

	c = getchar();
	while(!feof(stdin))
	{
		fputc(c, pa);
		c = getchar();
	}

	rewind(pa);

	printf("Terminei de ler #partiu escrever\n");

	c = fgetc(pa);
	while(!feof(pa))
	{
		putchar(c);
		c = fgetc(pa);
	}

	fclose(pa);

	return 0;
}