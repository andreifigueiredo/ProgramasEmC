int threadsGlobaisMagicasFelizes=0;

typedef struct{
		int linha,coluna,k_max;
		int** a;
		int** b;
		int** resultado;
}thread_arg,*ptr_thread_arg;

void *calculaElemento (void *parameter){
		ptr_thread_arg targ = (ptr_thread_arg)parameter;

		printf("Disparei a Thread %d que magicamente funciona. \n",threadsGlobaisMagicasFelizes);
		for(int k=0;k<targ->k_max;k++){
		 	targ->resultado[targ->linha][targ->coluna]+=(targ->a[targ->linha][k])*(targ->b[k][targ->coluna]);
		}

		threadsGlobaisMagicasFelizes++;
	}

