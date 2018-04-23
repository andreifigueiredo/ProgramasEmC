#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int linhaxcoluna = 1000;
	int *matriz1 = NULL, *matriz2 = NULL, *matriz3 = NULL;
	int capsula;
	int contador1, contador2, contador3;

	matriz1 = (int*) malloc(linhaxcoluna * linhaxcoluna * sizeof(int));
	matriz2 = (int*) malloc(linhaxcoluna * linhaxcoluna * sizeof(int));
	matriz3 = (int*) malloc(linhaxcoluna * linhaxcoluna * sizeof(int));

	printf("Executando...\n");

	for(contador1 = 0; contador1 < linhaxcoluna; contador1++)
	{
		for(contador2 = 0; contador2 < linhaxcoluna; contador2++)
			{
				capsula = 0;
				for(contador3 = 0; contador3 < linhaxcoluna; contador3)
				{
					capsula += matriz1[contador1 * linhaxcoluna + contador3] * matriz2[contador3 * linhaxcoluna + contador2];
					matriz3[contador1 * linhaxcoluna + contador2] = capsula;
				}
			}
	}
	printf("Fim da execucao\n"); 

	free(matriz1);
	free(matriz2);
	free(matriz3);

	return EXIT_SUCCESS;
}