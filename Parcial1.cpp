#include<stdio.h>
#include<stdint.h>
#include"Parcial1Lib.hpp"


int main ()
{
  FILE *f;
  f=fopen("network_structure.dat","rb");
  if(f==NULL)
  {
    printf("Error al abrir el archivo 404");
  }
  
    Count(f);
    
    fclose(f);
    return 0;
}