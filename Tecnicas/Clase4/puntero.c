#include <stdio.h>
#include <stdlib.h>


int Area( int longitud)
{
  return longitud*longitud;
}

void Area_ref (int *longitud)
{
  *longitud=*longitud*(*longitud);
}

int main (void)

{
  int *a;
  int b, Area;
  a=&b;
  b=1;
  printf("%d\n",*a);
  printf("%p\n",a);
  printf("%p\n",&b);
  *a=2;
  printf("%d\n",b);

  Area=Area(b);
  printf("Area por valor %d\n",Area);
  Area_ref(&b);
  printf("Area por referencia, se mueve todo a b: %d \n",b); 
  return 0;
}
