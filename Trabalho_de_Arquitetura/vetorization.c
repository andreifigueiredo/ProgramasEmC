#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef union
{
  int __attribute__((vector_size(1000000*sizeof(int)))) vec;
  int elem[1000][1000];
}intvec1000000;

int main()
{
   

  int linhaxcoluna = 1000;
  intvec1000000 matriz1, matriz2, matriz3;//matriz vetorizada
  int *matriza = NULL, *matrizb = NULL, *matrizc = NULL;//matriz q possui os valores que serao usados nas operacoes
  int contador1, contador2, contador3, capsula;

  matriza = (int*) malloc(linhaxcoluna * linhaxcoluna * sizeof(int));
  matrizb = (int*) malloc(linhaxcoluna * linhaxcoluna * sizeof(int));
  matrizc = (int*) malloc(linhaxcoluna * linhaxcoluna * sizeof(int));
  //manipulacao da matriz para quando ouver as operacoes vetorizadas, a multiplicacao da matriz seja correta
  for(contador1 = 0; contador1 < linhaxcoluna; contador1++)
  {
    for(contador2 = 0; contador2 < linhaxcoluna; contador2++)
      {
        for(contador3 = 0; contador3 < linhaxcoluna; contador3++)
        {
          matriz1.elem[contador1][contador2] = matriza[contador1 * linhaxcoluna + contador3];
          matriz2.elem[contador1][contador2] = matrizb[contador3 * linhaxcoluna + contador2];
          matriz3.elem[contador1][contador2] = matriz3[contador1 * linhaxcoluna + contador2];
        }
      }
  }

  printf("Executando...\n");
  capsula += matriz1.vec * matriz2.vec;
  matriz3.vec = capsula;

/*  for(int contador1 = 0; contador1 < linhaxcoluna; contador1++)
  {
      for(int contador2 = 0; contador2 < linhaxcoluna; contador2++)
      {
          capsula = 0;
          for(int contador3 = 0; contador3 < linhaxcoluna; contador3++)
          {
             capsula += matriz1.vec * matriz2.vec;
             matriz3.vec = capsula;
          }
          
          
      }
  }*/

  printf("Fim da execucao.\n");
  return EXIT_SUCCESS;
}