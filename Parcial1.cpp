#include<stdio.h>
#include<stdint.h>

struct SDevicet // tamaño 8 bits
{
   uint8_t TIPE : 2;//Dispositivo
   uint8_t nul  : 6;//no importa
};
struct Sinfo //tamaño 8 bits
{
    uint8_t no   :4;//no sirve
    uint8_t info :2;//SENSORES 
    uint8_t Nope :1;//no sirve este bit
    uint8_t Act  :1;//ACTUADOR
};

struct HLSB//Mapa de Bits//Header less significal bit tamaño 32bit
{
    uint32_t ULD  :16;//Upper Level Device ID
    uint32_t Info :8;//Informacion
    uint32_t DT   :8;//Device Type
};
struct HMSB//Header Most significant Bits tamaño 32bits
{
    uint32_t LLDC : 16;//Lower Level Device Count
    uint32_t ID   : 16;//ID device

};

struct HEADER
{
    struct HMSB ppal;
    struct HLSB lower;
};


int main ()
{
  FILE *f;
  struct HEADER master;//variable Que almacena el header copleto.
  f=fopen("network_structure.dat","rb");
  if(f==NULL)
  {
    printf("Error al abrir el archivo 404");
  }
  fread(&master.ppal,sizeof(struct HLSB),1,f);
  fread(&master.lower,sizeof(struct HLSB),1,f);
  printf("Id del dispositivo %u\n", master.ppal.ID);
  printf("cantidad de dispositvos %u\n",master.ppal.LLDC);
  struct SDevicet Knloer;
  Knloer.TIPE = master.lower.Info;
  printf("tipo de deispositivo %u\n",Knloer.TIPE);







    fclose(f);
    return 0;
}