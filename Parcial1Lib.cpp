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

struct HEADER//Mapa de Bits//Header tamaño 64bit
{
    uint32_t ULD  :16;//Upper Level Device ID
    uint32_t Info :8;//Informacion
    uint32_t DT   :8;//Device Type
    uint32_t LLDC :16;//Lower Level Device Count
    uint32_t ID   :16;//ID device

};


int Cantbits(FILE *F)
{
   int n =0;
   fseek(F,0,SEEK_END);
   n=ftell(F);
   fseek(F,0,SEEK_SET);
   return n;
}




int Count(FILE *f)
{
    struct HEADER A;
    int band=0,cant=0,i=0,rest=Cantbits(f);
   while(band!=1)
   {
      fread(&A,sizeof(uint64_t),1,f);
     // i=i+A.LLDC;//contador de disposit
      fread(&A,sizeof(uint16_t),A.LLDC,f);
      cant=cant+1;//contador de headers
     if(rest!=0)
    {
      rest= rest-(sizeof(uint16_t)*A.LLDC)-(sizeof(struct HEADER)*64);
      i++;
    }
    else
    {
        band=1;
    }

   }
   printf("Cantidad de Headers [%d]",i);
   return i;
}

void ShowIds();

void getRegister();