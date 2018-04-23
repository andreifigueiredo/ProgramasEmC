#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	int vetor[10][10], soma[10];
}MATRIZ;

void somamatriz(int *, int *)
{
	int i, j;
	int soma1 = 0;
	for(i = 0; i < 10; i++)
	{
		soma1 = pointer + celula[i][j];
		pointer[i] = soma1;
	}
	soma1 = 0;
}

int main(void)
{
	MATRIZ mtz;
	char *nome_arquivo = "matrizin.txt";
	int i, j, celulas, resposta;
	FILE *pa;

	pa = fopen(nome_arquivo, "w+");

	scanf("%d", &celulas);

	for(i = 0; i < celulas; i++)
	{
		for(j = 0; j < celulas; j++)
		{
			scanf("%d", mtz.vetor[i][j]);
		}
	}

	fwrite(mtz.vetor, sizeof(10 * 10 * int), 1, pa);

	rewind(pa);

	fread(mtz.vetor, sizeof(10 * 10 * int), 1, pa);

	
}