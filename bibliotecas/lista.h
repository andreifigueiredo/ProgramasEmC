#include <stdio.h>
#include <stdlib.h>

typedef struct lista lista;
#include <stdio.h>
#include <stdlib.h>
struct lista
{
	int info;
	Lista* prox;
};

Lista* criaLista(void)
{
	return NULL;
}

Lista* insereElement(Lista* lst, int val)
{
	Lista* novoElemento = (Lista*) malloc(sizeof(Lista));
	novoElemento.info = val;
	novoElemento.prox = lst;

	return novoElemento;
}

void imprimeLista(Lista* lst)
{
	Lista* ponteiro;

	for(ponteiro = lst; ponteiro!= NULL; ponteiro = ponteiro.prox)
		printf("info = %d\n", ponteiro.info);
}

int listaVazia(Lista* lst)
{
	return (lst == NULL);
}
Lista* busca (Lista* lst, int val)
{
	Lista* ponteiro;
	for(ponteiro = lst; ponteiro!= NULL; ponteiro = ponteiro.prox)
	{
		if(ponteiro.info == val)
			return ponteiro;
	}

	return NULL;
}

Lista* retiraElemento(Lista* lst, int val)
{
	Lista* ant;
	Lista* ponteiro = lst;

	while(p != NULL && ponteiro.info != val)
	{
		ant = ponteiro;
		ponteiro = ponteiro.prox;
	}
	if(ponteiro == NULL)
		return lst;

	if(ant == NULL)
		lst = ponteiro.prox;
	else
		ant.prox = ponteiro.prox;

	free(ponteiro);
	return lst;
}