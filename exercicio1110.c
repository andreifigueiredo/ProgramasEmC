#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char nome[50];
	float nota1;
	float nota2;
}ALUNO;

typedef struct
{
	ALUNO vetor[10];
	int n;
}ARRAY;

int tamanho(ARRAY *array)
{
	return array->n;
}

ALUNO elemento(ARRAY *, int);
void imprime(ARRAY *);
void insere(ARRAY *, ALUNO);

int main(void)
{
	char *nome_arquivo = "arquivo1110.txt";
	FILE *pa;

	ARRAY array;
	int i;

	if((pa = fopen(nome_arquivo, "r")) != NULL)
	{
		fread(&array, sizeof(ARRAY), 1, pa);
		fclose(pa);
	}

	imprime(&array);

	ALUNO aln1;

	printf("Nome do Aluno");
	fgets(aln1.nome, 50, stdin);

	aln1.nome[strlen(aln1.nome) - 1] = '\0';

	printf("NOTA 1: ");
	scanf("%f", &aln1.nota1);

	printf("NOTA 2: ");
	scanf("%f", &aln1.nota2);

	insere(&array, aln1);

	imprime(&array);

	if((pa = fopen(nome_arquivo, "w")) == NULL)
	{
		perror("fopen:");
		return 1;
	}

	fwrite(&array, sizeof(ARRAY), 1, pa);
	fclose(pa);

	return 0;
}

void imprime(ARRAY *array)
{
	int i;
	ALUNO aluno;

	printf("------------------------------------\n");
	printf("Alunos:\n");

	for(i = 0; i < tamanho(array); i++)
	{

		aluno = elemento(array, i);
		printf(" 0%d - %s \n NOTA1: %f \n NOTA2: %f", i+1, aluno.nome, aluno.nota1, aluno.nota2);

	}

	printf("------------------------------------\n");

}

ALUNO elemento(ARRAY *array, int posicao)
{

	return array->vetor[posicao];

}

void insere(ARRAY *array, ALUNO aluno)
{

	array->vetor[tamanho(array)] = aluno;
	array->n ++;

}