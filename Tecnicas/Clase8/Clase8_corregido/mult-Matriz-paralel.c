#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define M 10000

int main(){
  int ID, num,aux;
  int i,j,k;
  int **A,**B,**C;

  A = (int **)malloc(M*sizeof(int *));
  B = (int **)malloc(M*sizeof(int *));
  C = (int **)malloc(M*sizeof(int *));

  for (i=0;i<M;i++)
    {
      A[i] = (int *)malloc(M*sizeof(int));
      B[i] = (int *)malloc(M*sizeof(int));
      C[i] = (int *)malloc(M*sizeof(int));
    }
  for (i=0;i<M;i++)
    {
      for(j=0;j<M;j++)
	{
	  if (i==j)
	    {
	      A[i][j]=1;
	    }
	  B[i][j] = rand()%11;
	  C[i][j] = 0;
	}
    }
  
#pragma omp parallel default(shared) private(i,j,k,aux)
  {
#pragma omp for
    for (i=0;i<M;i++)
      {
	for (j=0;j<M;j++)
	  {
	    aux=0;
#pragma omp parallel  for reduction(+:aux) 
	    for (k=0;k<M;k++)
	      {
		aux +=  (A[i][k] * B[k][j]);
	      }
	    C[i][j]=aux;
	  }
      }
  }
  
  for (i=0;i<M;i++)
    {
      for (j=0;j<M;j++)
	{
	  if (C[i][j]!=B[i][j])
	    {
	      printf("error!!!\n");
	      exit(0);
	    }
	}
    }
  return 0;
}
