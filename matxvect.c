int matxvect void(float mat[i][j], float vect[j], int n)
{
	int i, j;
	float somador[j];

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
				somador[j] = 0;
				somador[j] = somdor + (mat[i][j] * vect[j]);
				return somador[j];
		}
	}
}

int main void()
{
	int i, j, n;
	float mat[i][j], vect[j], somador[j];

	printf("Informe o número de linhas e colunas da matriz quadrada!\n");
	scanf("%d", &n);

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
				printf("Informe o valor da linha %d coluna %d da matriz!\n", &i, &j);
				scanf("%f", mat[i][j]);
		}
	}

	for(j = 0; j < n; j++)
	{
		printf("Informe o valor %d do vetor!", %j);
		scanf("%f", vect[j]);
	}

	somador[j] = matxvect(mat[i][j], vect[j], n);
}