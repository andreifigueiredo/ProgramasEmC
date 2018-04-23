#include <stdio.h>

void imprime(int *, char *, float *);

int main(void)
{
	FILE *pa;
	int numero;
	char letra;
	float ncomvirgula;

	pa = fopen("teste3.txt", "w+");

	printf("Insira uma letra: \n");
	scanf("%c", &letra);
	printf("Insira um numero: \n");
	scanf("%d", &numero);
	printf("Insira um float: \n");
	scanf("%f", &ncomvirgula);

	fprintf(pa, "%d \n%c \n%f\n", numero, letra, ncomvirgula);

	printf("Acabei se escrever agora vou imprimir\n");

	rewind(pa);

	fscanf(pa,"%d", &numero);
	fscanf(pa,"%c", &letra);
	fscanf(pa,"%f", &ncomvirgula);

	imprime(&numero, &letra, &ncomvirgula);

	fclose(pa);

	return 0;
}

void imprime(int *numero, char *letra, float *ncomvirgula)
{
	printf("Eu escrevi no arquivo: \n");
	printf("NUMERO: %d\n", *numero); 
	printf("LETRA: %c\n", *letra); 
	printf("FLOAT: %f\n", *ncomvirgula);
}
