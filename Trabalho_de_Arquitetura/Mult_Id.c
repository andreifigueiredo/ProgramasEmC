#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int linhaxcoluna = 1000;
	int *matriz1 = NULL;
	int capsula;
	int contador1, contador2;

	matriz1 = (int*) malloc(linhaxcoluna * linhaxcoluna * sizeof(int));

	for(contador1 = 0; contador1 < linhaxcoluna; contador1++)
	{
		matriz1[contador1][contador1] = 1;
	}

	printf("Executando...\n");

	for(contador1 = 0; contador1 < linhaxcoluna; contador1++)
	{
		capsula = 0;
		while(matriz[contador1][contador2] == 1 && capsula == 0 && contador2 < linhaxcoluna)
		{
			contador2 = 0;
			capsula = matriz1[contador1][contador1] * matriz1[contador1][contador2];
			
			if(contador1++ == contador2++)
				contador2 += 2;
			else
				contador2++;
		}
	}
	printf("Fim da execucao\n"); 

	free(matriz1);

	return EXIT_SUCCESS;
}