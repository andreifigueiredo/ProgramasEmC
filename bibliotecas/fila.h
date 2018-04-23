#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;
typedef struct fila Fila;

struct lista{
	float info;
	Lista* prox;
};

struct fila{
	Lista* ini;
	Lista* fim;
};

Fila* filaCria(void){
	Fila* f = (Fila*) malloc(sizeof(Fila));
	f->ini = f->fim = NULL;
	return f;
}

void filaInsere(Fila* f, float v){
	Lista* n = (Lista*) malloc(sizeof(Lista));
	n->info = v;
	n->prox = NULL;
	if(f->fim != NULL)
		f->fim->prox = n;

	else
		f->ini = n;
	f->fim = n;	
}

float filaRetira(Fila* f){
	Lista* t;
	float v;
	if(filaVazia(f)){
		printf("Fila vazia.\n");
		exit(1);
	}

	t = f->ini;
	v = t->info;
	f->ini = t->prox;
	if(f->ini == NULL)
		f->fim = NULL;
	free(t);
	return v;
}

void filaLibera(Fila* f){
	Lista* q = f->ini;
	while(q != NULL){
		Lista* t = q->prox;
		free(q);
		q = t;
	}
	free(f);
}

