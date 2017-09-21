#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define M 1000

int main(){
  int ID, num;
  int i,j,k;
  int **A,**B,**C;

  A = (int **)malloc(M*sizeof(int *));
  B = (int **)malloc(M*sizeof(int *));
  C = (int **)malloc(M*sizeof(int *));

  for (i=0;i<M;i++){
    A[i] = (int *)malloc(M*sizeof(int));     
  }
  for (i=0;i<M;i++){
    for(j=0;j<M;j++){
      A[i][j] = rand();
    }
  }
  for (i=0;i<M;i++){
    B[i] = (int *)malloc(M*sizeof(int));
  }
  for (i=0;i<M;i++){
    for (j=0;j<M;j++){
      B[i][j] = rand();
    }
  }
  for (i=0;i<M;i++){
    C[i] = (int *)malloc(M*sizeof(int));
  }
  for (i=0;i<M;i++){
    for (j=0;j<M;j++){
      C[i][j] = 0;
      for (k=0;k<M;k++){
	C[i][j] = C[i][j] + (A[i][k] * B[k][j]);
      }
    }
  }
  for (i=0;i<M;i++){
    printf("\n\n\t");
    for (j=0;j<M;j++){
      printf("%6d", C[i][j]);
    }
  }
  return 0;
}
