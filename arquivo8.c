#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARRAY 10
#define MAX_NOME 50

typedef struct
{
    char nome[MAX_NOME];
    int pontuacao;
} RECORDE;

typedef struct
{
    RECORDE vetor[MAX_ARRAY];
    int n;

} ARRAY;

RECORDE elemento(ARRAY *, int);
int tamanho(ARRAY *);
void insere(ARRAY *, RECORDE);

void remove_posicao(ARRAY *, int);
void imprime(ARRAY *);
void sort(ARRAY *);
void bubble_sort(RECORDE *, int);

int main(int argc, char *argv [])
{
    char *nome_arquivo = "recordes.dat";
    FILE *p_arquivo;

    ARRAY array;
    array.n = 0;

    if((p_arquivo = fopen(nome_arquivo, "r")) != NULL)
    {
        fread(&array, sizeof(ARRAY), 1, p_arquivo);
        fclose(p_arquivo);
    }

    imprime(&array);

    RECORDE rec1;
    
    printf("Nome do Recordista:");
    fgets(rec1.nome, MAX_NOME, stdin);

    rec1.nome[strlen(rec1.nome) - 1] = '\0';

    printf("Pontuação:");
    scanf("%d", &rec1.pontuacao);

    insere(&array, rec1);
    
    imprime(&array);

    if((p_arquivo = fopen(nome_arquivo, "w")) == NULL)
    {
        perror("fopen:");
        return 1;
    }

    fwrite(&array, sizeof(ARRAY), 1, p_arquivo);
    fclose(p_arquivo);

    return 0;
}

RECORDE elemento(ARRAY *array, int posicao)
{
	return array->vetor[posicao];
}

int tamanho(ARRAY *array)
{
	return array->n;
}

void insere(ARRAY *array, RECORDE recorde)
{
    if(tamanho(array) < MAX_ARRAY)
    {
        array->vetor[tamanho(array)] = recorde;
        array->n += 1;
    }
    else
    {
        RECORDE menor_recorde;
        menor_recorde = elemento(array, MAX_ARRAY - 1);
        
        if(menor_recorde.pontuacao >= recorde.pontuacao)
        {
            return;
        }
        else
        {
            remove_posicao(array, MAX_ARRAY - 1);
            insere(array, recorde);
            return;
        }
    }
    
    sort(array);
}

void remove_posicao(ARRAY *array, int posicao)
{
	if(tamanho(array) == 0)
	{
		return;
	}
	else if(tamanho(array) == 1)
	{
		array->n -= 1;
		return;
	}
	else
	{
		array->n -= 1;
		array->vetor[posicao] = array->vetor[tamanho(array)];
	}
    
    sort(array);
}

void imprime(ARRAY *array)
{
	int i;
    RECORDE recorde;

    printf("------------------------------\n");
	printf("Recordes:\n");

	for(i = 0; i < tamanho(array); i++)
	{
        recorde = elemento(array, i);
        printf("%d - %d :: %s \n", i+1, recorde.pontuacao, recorde.nome);
	}

	printf("------------------------------\n");
}

void sort(ARRAY *array)
{
	bubble_sort(array->vetor, array->n);
}

void bubble_sort(RECORDE list[], int n)
{
	int i, j;
    RECORDE swap;

	for(i = 0 ; i < ( n - 1 ); i++)
	{
		for(j = 0 ; j < n - i - 1; j++)
		{
			if(list[j].pontuacao < list[j+1].pontuacao)
			{ 
				swap = list[j];
				list[j] = list[j+1];
				list[j+1] = swap;
			}
		}
	}
}
