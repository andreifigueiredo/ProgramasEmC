#include <stdio.h>
#include <stdlib.h>nore

typedef struct arv Arv;

struct arv{
	int val;
	Arv* dir;
	Arv* esq;
};

int menores_x(Arv* a, int x){
	int contador = 0;

	if(a == NULL)
		return 0;

	else if(a->info >= x)
		return menores_x(a->esq, x);
	else
		return 1 + menores_x(a->esq,x) + menores_x(a->dir, x);

}