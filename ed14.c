#include <stdio.h>
#include <stdlib.h>

typedef struct arv Arv;

struct arv{
	int val;
	char nome[81];
	char email[41];
	Arv* dir;
	Arv* esq;
};

Arv* insere(Arv* a, int mat, char* nome, char* email){

	if(a == NULL){
		a = (Arv*) malloc(sizeof(Arv));
		a->val = mat;
		strcpy(a->nome, nome);
		strcpy(a->email, email);
	}

	else if(strcmp(nome, a->nome) < 0)
		a->esq = insere(a->esq, mat, nome, email);

	else if(strcmp(nome, a->nome) > 0)
		a->dir = insere(a->dir, mat, nome, email);

	return a;
}