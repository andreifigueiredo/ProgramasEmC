#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_EVENT 2
#define THRESHOLD 100000

void printMatrix(float *m, float w, float h)
{
   int i, j;

   printf("\n");

   for (j = 0; j < h; j++)
   {
      for (i = 0; i < w; i++)
      {
         int k = j * w + i;
         printf("%.2f ", m[k]);
      }
      printf("\n");
   }

}

int main (int argc, char **argv)
{
   float *A = NULL, *B = NULL, *C = NULL;
   int iA, jA, iB, jB, iC, jC;
   int width = atoi(argv[1]), height = atoi(argv[2]);// align = atoi(argv[3]);

   int i, tmp;

   A = (float*) malloc(width * height * sizeof(float));
   B = (float*) malloc(width * height * sizeof(float));
   C = (float*) malloc(width * height * sizeof(float));
/*
   posix_memalign((void*)&A, align, width * height * sizeof(float));
   posix_memalign((void*)&B, align, width * height * sizeof(float));
   posix_memalign((void*)&C, align, width * height * sizeof(float));
   
*/
   printf("\nMultiplicando matriz\n");
   for (jC = 0; jC < height; jC++){
      for (iC = 0; iC < width; iC++)
      {
         int kC = jC * width + iC;
         A[kC] = (float) kC + 1;
         if (jC == iC)
            B[kC] = 1.0f;
         else
            B[kC] = 0.0f;
         
      }
   }

   free (A);
   free (B);
   free (C);
   return EXIT_SUCCESS;
}
