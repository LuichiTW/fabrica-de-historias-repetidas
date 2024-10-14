#ifndef SCANNER
#define SCANNER 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>    
#include <dirent.h>    


struct listaNombres{
    char nombre[50];
    struct listaNombres *siguiente;
};


extern struct listaNombres *nombres;

void crearHistoria(char inputHistoria[5000], char *nombre, int cantNombres);
char *reemplazarPalabra(const char *str, const char *palabra, const char *reemplazo);
void crearLista();
void agregarNombre(char nombre[50]);
char *indiceNombre(int indice);
void limpiarLista();

#endif
