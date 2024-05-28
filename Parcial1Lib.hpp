#pragma once
#include<stdio.h>

/**
 * @file fUNCIONES
 * @author Gadiel Pardo
 * @date 27/05/2024
 * @version 0.0.3
 *
*/
 
 /**
 * @brief Funcion que cuenta la cantidad de Bits
 * @param f file con el que se trabaja
 * @return devuelve el numero de bits del archivo 
*/
int Cantbits(FILE *F);//indica taaño del archivo

/**
 * @brief  funcion que cuenta la cantidad de dispositivos
 * @param f recive el fichero
 * @return retorna la cantidad de dispositivos de la red (retorna en una variable, no 
 * muestra en consola). 
*/
int CountDevices(FILE *f);//indica cantidad de IDS

/**
 * @brief Muestra en consola todos los IDs
 * @param 
 * @return muestra valores de IDs
*/
void ShowIds();


/**
 * @brief  Crea y devuelve un vector de estructuras.
 * @param Id ID del equipo
 * @return dado como argumento el ID del equipo, esta función devuelve el 
registro completo de ese equipo en forma de una estructura. 
*/
void getRegister();

 





