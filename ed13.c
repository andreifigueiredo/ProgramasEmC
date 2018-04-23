#include <stdio.h>
#include <stdlib.h>

typedef struct arv Arv;

struct arv{
	int val;
	Arv* dir;
	Arv* esq;
};

Arv* antecessor(Arv* a, int x){
	if(a == NULL)
		return NULL;

	antecessor(a->esq);
	antecessor(a->dir);

	else if(a->info < x){
		if(a->info < p->info){
			p = a;
			return a;
		}
	}

}