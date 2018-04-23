#include<stdio.h>

int main(void)
{
	int vetor[3];
	int resultado[3];
	int x, y ,z, i;

	for(i = 0; i <= 2; i++)
	{
		printf("Insira o vetor ---%d---: ", i+1);
		scanf("%d", &vetor[i]);
	}
	x = vetor[0];
	y = vetor[1];
	z = vetor[2];

	resultado[0] = x + y;
	resultado[1] = x + z;
	resultado[2] = y + z;

	for(i = 0; i <= 2; i++)
	{
		puts("Essas são as somas: ");
		printf("---%dª---: --%d--\n", i + 1, resultado[i]);
	}

	return 0;
}