#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <omp.h>

#define Nt 10
#define Nx 10000
#define Ny 10000

using namespace std;

// hacer una suma de matrices en paraleo usando el codigo de openMP


int main (void)

{
  
  int Size= sizeof(int);
  int **A,**B, **C,fil,col,i,j,k;
  /*
    cout<<"ingrese el numero de filas:  ";
    cin >>fil;
    cout<< "ingrese el numeron de columnas: ";
    cin >>col;
  */
  A = (int **) malloc(Nx*sizeof(int *));
  B = (int **) malloc(Nx*sizeof(int *));
  C = (int **) malloc(Nx*sizeof(int *));
   for (i=0; i<Ny; i++)
    {
      A[i]= (int *) malloc(Ny*Size);
      B[i]= (int *) malloc(Ny*Size);
      C[i]= (int *) malloc(Ny*Size);
   
    }
   

  

#pragma omp parallel for default(shared) private(j,k) 
   for (j=0;j<Ny; j++)
       {
	 
	 
	 
	 
	#pragma omp parallel for private(k)
	 for (k=0; k<Nx; k++)
	     {
	       A[j][k]=1;
	       B[j][k]=2;
	       C[j][k]=A[j][k]+B[j][k];
	       
	     }
	 
      
       }
   

  for (j=0;j<Ny; j++)
    {
	
      for (k=0; k<Nx; k++)
	  {

	    if (C[j][k] !=3)
	      {
		cout<<"error!!"<<endl;
		exit(0);
	      }
	  }
    }
  

  for (i=0;i<Ny;i++)
    {
      free (A[i]);
      free (B[i]);
      free (C[i]);
    }
  free (A);
  free (B);
  free (C);
  return 0;
}
