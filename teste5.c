#include <stdio.h>

void imprime(int *);
void ordena(int *);

int main(void)
{
	char *nome = "teste5.txt";
	FILE *pa;
	int numeros[5], i;

	pa = fopen(nome, "w+");

	for(i = 0; i < 5; i++)
	{
		printf("InSIRA O NUMERO %d\n", i);
		scanf("%d", &numeros[i]);
	}

	ordena(numeros);

	for(i = 0; i < 5; i++)
	{
		fwrite(&numeros, sizeof(int), 1, pa);
	}

	fclose(pa);

	pa = fopen(nome, "r+");

	for(i = 0; i < 5; i++)
	{
		fread(&numeros, sizeof(int), 1, pa);
	}	

	printf("Os números são: \n");
	imprime(numeros);

	fclose(pa);

	return 0;
}

void imprime(int numeros[])
{
	int i;

	for(i = 0; i < 5; i++)
	{
		printf("%d\n",numeros[i]);
	}
}

void ordena(int numeros[])
{
	int i, j, apoiador = 0;

	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5 - i; j++)
		{
			if(numeros[i] > numeros[i+1])
			{
				apoiador = numeros[j];
				numeros[j] = numeros[j+1];
				numeros[j+1] = apoiador;
			}
		}
	}
}	
