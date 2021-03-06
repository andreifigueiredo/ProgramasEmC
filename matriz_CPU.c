#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "papi.h"

#define NUM_EVENT 2
#define THRESHOLD 100000
#define ERROR_RETURN(retval) { fprintf(stderr, "Error %d %s:line %d: \n", retval,__FILE__,__LINE__);  exit(retval); }

void printMatrix(float *m, float w, float h){
   int i, j;

   printf("\n");

   for (j = 0; j < h; j++){
      for (i = 0; i < w; i++){
         int k = j * w + i;
         printf("%.2f ", m[k]);
      }
      printf("\n");
   }

}

int main (int argc, char **argv){
   float *A = NULL, *B = NULL, *C = NULL;
   int iA, jA, iB, jB, iC, jC;
   int width = atoi(argv[1]), height = atoi(argv[2]);// align = atoi(argv[3]);

   int i,retval,tmp;
   int EventSet = PAPI_NULL;
   int event_codes[NUM_EVENT]={PAPI_L1_DCM,PAPI_L2_DCM}; 
   char errstring[PAPI_MAX_STR_LEN];
   long long values[NUM_EVENT];

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
      for (iC = 0; iC < width; iC++){
         int kC = jC * width + iC;
         A[kC] = (float) kC + 1;
         if (jC == iC)
            B[kC] = 1.0f;
         else
            B[kC] = 0.0f;
         
      }
   }

   
   int steps= 0;
   for (jC = 0; jC < height; jC++){
      for (iC = 0; iC < width; iC++){
         int kC = jC * width + iC;
         float aux = 0.0f;
         jA = jC;
         for (iA = 0; iA < width; iA++){
            jB = iA;
            iB = iC;
            int kA = jA * width + iA;
            int kB = jB * width + iB;
            aux += A[kA] * B[kB];
             
            steps++;
         }
         C[kC] = aux;      
      }//end-      for (iC = 0; iC < 2; iC++){
   }//end-for (jC = 0; jC < 2; jC++){

    if((retval = PAPI_library_init(PAPI_VER_CURRENT)) != PAPI_VER_CURRENT )
   {
      fprintf(stderr, "Error: %s\n", errstring);
    exit(1);
   }

   
    /* Creating event set   */
  if ((retval=PAPI_create_eventset(&EventSet)) != PAPI_OK)
    ERROR_RETURN(retval);


    /* Add the array of events PAPI_TOT_INS and PAPI_TOT_CYC to the eventset*/
    if ((retval=PAPI_add_events(EventSet, event_codes, NUM_EVENT)) != PAPI_OK)
    ERROR_RETURN(retval);
  
       
    /* Start counting */
    if ( (retval=PAPI_start(EventSet)) != PAPI_OK)
    ERROR_RETURN(retval);
     
    /*** this is where your computation goes *********/
    for(i=0;i<1000;i++)
   {
    tmp = tmp+i;
   }  

    /* Stop counting, this reads from the counter as well as stop it. */
  if ( (retval=PAPI_stop(EventSet,values)) != PAPI_OK)
    ERROR_RETURN(retval);

    printf("\nThe total instructions executed are %lld, total cycles %lld\n",
  values[0],values[1]);

    
    if ( (retval=PAPI_remove_events(EventSet,event_codes, NUM_EVENT))!=PAPI_OK)
    ERROR_RETURN(retval);

    /* Free all memory and data structures, EventSet must be empty. */
  if ( (retval=PAPI_destroy_eventset(&EventSet)) != PAPI_OK)
    ERROR_RETURN(retval);

    /* free the resources used by PAPI */
  PAPI_shutdown();

   //printMatrix(C, width, height);
   printf("\n%d\n", steps);
   free (A);
   free (B);
   free (C);
   return EXIT_SUCCESS;
}
