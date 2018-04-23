#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "matriz.h"

class Matriz{
	public:
		int **matriz,n,m;
		Matriz(int m,int n);
		void multiplicaMatriz(Matriz *a,Matriz *b,Matriz *c);
		void preencheMatriz();
		void preencheIdentidade();
		void preencheNula();
		void printaMatriz();

		void chamaThread (Matriz *a,Matriz *b,Matriz *resultado){

			pthread_t threads[a->m][a->n];
			thread_arg args[a->m][a->n];

			for(int i=0;i<a->m;i++){
			 	for(int j=0;j<a->n;j++){
						args[i][j].linha=i;
						args[i][j].coluna=j;
						args[i][j].k_max=a->m;
						args[i][j].a=a->matriz;
						args[i][j].b=b->matriz;
						args[i][j].resultado=resultado->matriz;

						pthread_create(&(threads[i][j]),NULL,calculaElemento,&(args[i][j]));
						pthread_join(threads[i][j],NULL);
				 	}
				}
		}
		
};


Matriz::Matriz(int m,int n){
	int **mat = new int*[m];
	for(int i = 0; i < m; ++i) {
   	 	mat[i] = new int[n];
	}

	matriz=mat;
	this->m=m;
	this->n=n;
	preencheMatriz();
}

void Matriz::multiplicaMatriz (Matriz *a,Matriz *b,Matriz *c){
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				c->matriz[i][j]+=(a->matriz[i][k])*(b->matriz[k][j]);
			}
		}
	}
}


void Matriz::preencheMatriz(){
	int contador=1;

	for (int i=0;i<this->m;i++){
		for(int j=0;j<this->n;j++){
			this->matriz[i][j]=contador;
			contador++;
		}
	}
}

void Matriz::preencheNula(){

	for (int i=0;i<this->m;i++){
		for(int j=0;j<this->n;j++){
			this->matriz[i][j]=0;
		}
	}
}

void Matriz::preencheIdentidade(){

	for (int i=0;i<this->m;i++){
		for(int j=0;j<this->n;j++){
			if(i==j)
				this->matriz[i][j]=1;
			
			else
				this->matriz[i][j]=0;
		}
	}
}

void Matriz::printaMatriz(){
	for(int i=0;i<this->m;i++){
		for(int j=0;j<this->n;j++){
			printf("%d ",matriz[i][j]);	
		}
		printf("\n");
	}

	printf("\n");
}

int main(){

	Matriz *a = new Matriz(5,5);

	Matriz *b = new Matriz(5,5);
	b->preencheIdentidade();

	Matriz *resultado = new Matriz(5,5);
	resultado->preencheNula();

	a->chamaThread(a,b,resultado);

	resultado->printaMatriz();

	return 0;
}