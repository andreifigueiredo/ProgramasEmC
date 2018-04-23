#include <stdio.h>

#define MAX 10
typedef struct 
{
	int numbers[MAX][MAX];
}MATRIZ;

//void imatriz(MATRIZ *, int *);

int main(void)
{
	char *nome = "teste7.txt";
	int i, j, mxn;
	FILE *pa;
	MATRIZ mtz;

	if((pa = fopen(nome, "w+")) == NULL)
	{
		puts("Não foi possivel abrir o aqruivo: \n");
		return 1;
	}

	puts("Insira quantas linhas x colunas deverá ter a matriz: \n");
	scanf("%d", &mxn);

	for(i = 0; i < mxn; i++)
	{
		for(j = 0; j < mxn; j++)
		{
			scanf("%d", &mtz.numbers[i][j]);
		}
	}

	for(i = 0; i < mxn; i++)
	{
		for(j = 0; j < mxn; j++)
		{
			fwrite(&mtz, sizeof(MATRIZ), 1, pa);
		}
	}

	rewind(pa);
	puts("Acabei de escrever #partiu ler\n");

	for(i = 0; i < mxn; i++)
	{
		for(j = 0; j < mxn; j++)
		{
			fread(&mtz, sizeof(MATRIZ), 1, pa);
		}
	}

	puts("A matriz é:\n");
	for(i = 0; i < mxn; i++)
	{
		for(j = 0; j < mxn; j++)
		{
			printf("--%d--", mtz.numbers[i][j]);
		}
		printf("\n");
	}

	fclose(pa);

	return 0;
}

/*void imatriz(MATRIZ *matriz, int *mxn)
{
	int i, j;

	for(i = 0; i < *mxn; i++)
	{
		for(j = 0; j < *mxn; j++)
		{
			printf("--%d--", matriz.numbers);
		}
		printf("\n");
	}

}*/