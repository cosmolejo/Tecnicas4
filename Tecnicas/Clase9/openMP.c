#include <stdio.h>
#include <stdlib.h>

#include <omp.h> // libreria open mp

#define Nt 50
#define CHUNK 2

int main (void)

{
  int total=8,id=0,np,i,chunk;
  double *a, *b, *c, dot;

  //int hilos=omp_get_num_threads(); //busca el numero de hilos en ejecucion
  
  system("clear");
  omp_set_num_threads(total);  // establece el numero de hilos a usar
  
   a= (double *)malloc (Nt*sizeof(double));
   b= (double *)malloc (Nt*sizeof(double));
   c= (double *)malloc (Nt*sizeof(double));
   
   for (i=0;i<Nt;i++)
     {
       a[i]=rand()%11;
       b[i]=rand()%11;
       c[i]=0.0;
     }

#pragma omp parallel default(shared) private(id,np,i,CHUNK) //num_threads(3) 
   {
     id=omp_get_thread_num();
     np=omp_get_num_threads();
#pragma omp for reduction(+:dot)  schedule(dynamic,CHUNK)//inicia el entorno para paralelizar un for,
                                  //reparte las iteraciones en orden
                                  //reduction hace operaciones de reduccion,
                                  //hace las operaciones parciales para  hilo paralelizado,
                                  //la variable es privada
       for (i=0;i<Nt;i++)
	 {
	   printf("hola mundo, soy el hilo %d de %d, iteracion: %d\n",id,np,i);
	   c[i]=a[i]+b[i];
	   dot+=c[i];
	 }
       
   }

   printf("producto punto: %.2f \n",dot);
   /*
   for (i=0;i<Nt;i++)
     {
       printf("c[%d] = %.1f \n",i,c[i]);
     }
   */
  return 0;
}
