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


int Count(FILE *f)//me trabe muchas veces buscando la forma de contar los elementos
{
    int band=0;
    uint16_t rize;
    struct HEADER A,AUX;
    do
    {
       fread(&A,sizeof(uint64_t),1,f);
       for()
    } while (band !=1);
    
}

void ShowIds();

void getRegister();