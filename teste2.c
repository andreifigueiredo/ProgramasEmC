#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *pa;
	int i = 1;
	char c = 'a';
	float f = 0.5;

	pa = fopen("teste2.txt", "w+");

	fprintf(pa, "Este é o segundo teste em C que faço no meu ubunbtu");
	fprintf(pa, "%d %c %f", i, c, f);

	rewind(pa);

	fscanf(pa, "%d", &i);
	fscanf(pa, "%c", &c);
	fscanf(pa, "%f", &f);
	printf("Eu escrevi no arquivo:\n -----%d-----%c-----%f-----", i, c, f);

	fclose(pa);

	return 0;
}