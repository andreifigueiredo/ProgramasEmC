#include <stdio.h>
#include <stdlib.h>

typedef struct pilha Pilha;
typedef struct elemento Elemento;

struct pilha{
	int prim;
};

struct elemento{
	int prox;
	float info;
}

float pilhaPop(Pilha* p){
	Elemento* t;
	float v;
	if (pilhaVazia(p)) 
		exit(1);

	t = p->prim;
	v = p->info;
	p->prim = t->prox;
	free(t);
	return v;
}

Pilha* pilhaCria(void){
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	p->prim = NULL;
	return p;
}

void pilhaPush(Pilha* p, float v){
	Elemento* n = (Elemento*) malloc(sizeof(Elemento));
	n->info = v;
	n->prox = p->prim;
	p->prim = n;
}

float pilhaLibera(Pilha* p){
	Elemento* t; 
	Elemento* q = p->prim;
	while(q =! NULL){
		t = q->prox;
		free(q);
		q = t;
	}
	free(p);
}

int pilhaVazia(Pilha* p){
	if(p->prim == NULL)
		return 1;

	return 0;
}