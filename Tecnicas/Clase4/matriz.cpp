#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;




int main (void)

{
  system("clear");
  int Size= sizeof(int);
  int **mat, fil,col,i,j,k;
  cout<<"ingrese el numero de filas:  ";
  cin >>fil;
  cout<< "ingrese el numeron de columnas: ";
  cin >>col;

  mat = (int **) malloc(col*sizeof(int *));
  for (i=0; i<col; i++)
    {
      mat[i]= (int *) malloc(fil*Size);
    }

  system("clear");
  cout<<"\t Matriz \n";
  for (j=0;j<col; j++)
    {
      cout<<endl;
      for (k=0; k<fil; k++)
	{
	  mat[j][k]=(j+1)*(k+1);
	  cout<<"\t"<<mat[j][k];
	}
      cout<<endl;
    }

  for (i=0;i<col;i++)
    {
      free (mat[i]);
    }
  free (mat);
  return 0;
}
