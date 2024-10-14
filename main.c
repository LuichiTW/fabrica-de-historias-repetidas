#include <stdio.h>
#include <stdlib.h>
#include <string.h>    
#include <dirent.h>    

#include "scanner.h"

struct listaNombres *nombres;

char input[50]; // Buffer para almacenar la entrada del usuario
char inputHistoria[5000];


int main(){
  int cantNombres = 0;

  //crearLista();
  while (1) {

    printf("Ingresar nombres (vacio para terminar):");
    fgets(input, sizeof(input), stdin);

    // Verificar si el string está vacío
    if (input[0] == '\n') {
      break;
    }

    // Eliminar el salto de línea al final del string
    input[strcspn(input, "\n")] = 0;

    agregarNombre(input);
    cantNombres++;
  }

  for (int i = 0; i < cantNombres; i++) {
    printf("%s\n", indiceNombre(i));
  }

  printf("Ingresar historia(ej: [A] es amigo de [B]):");
  fgets(inputHistoria, sizeof(inputHistoria), stdin);

  // Verificar si el string está vacío
  if (inputHistoria[0] == '\n') {
    return 0;
  }

  // Eliminar el salto de línea al final del string
  inputHistoria[strcspn(inputHistoria, "\n")] = 0;

  for (int i = 0; i < cantNombres; i++) {
    printf("Capitulo %d:  \n", i+1);
    crearHistoria(inputHistoria, indiceNombre(i), cantNombres);
  }

  limpiarLista();
  return 0;
}
