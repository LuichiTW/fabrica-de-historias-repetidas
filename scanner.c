#include "scanner.h"
#include <stdlib.h>

char *personajes[] = {"[A]","[B]","[C]","[D]","[E]","[F]","[G]","[H]","[I]","[J]","[K]"};

char *reemplazarPalabra(const char *str, const char *palabra, const char *reemplazo)
{
	char *resultado;
	int i, cnt = 0;
	int nuevaLongitud = strlen(reemplazo);
	int viejaLongitud = strlen(palabra);

	// Contar el número de veces que la palabra aparece en el string original
	for (i = 0; str[i] != '\0'; i++)
	{
		if (strstr(&str[i], palabra) == &str[i])
		{
			cnt++;
			i += viejaLongitud - 1;
		}
	}

	// Crear un nuevo string con el tamaño adecuado
	resultado = (char *)malloc(i + cnt * (nuevaLongitud - viejaLongitud) + 1);

	i = 0;
	while (*str)
	{
		// Comparar la palabra con el string original
		if (strstr(str, palabra) == str)
		{
			strcpy(&resultado[i], reemplazo);
			i += nuevaLongitud;
			str += viejaLongitud;
		}
		else
		{
			resultado[i++] = *str++;
		}
	}

	resultado[i] = '\0';
	return resultado;
}

void crearHistoria(char inputHistoria[5000], char *nombre, int cantNombres)
{
	char *historia = reemplazarPalabra(inputHistoria, personajes[0], nombre);
	int a = 1;
	for(int i = 0; i < cantNombres; i++){
		if (strcmp(indiceNombre(i), nombre) != 0)
		{
		historia = reemplazarPalabra(historia, personajes[a], indiceNombre(i));
		a++;
		}
	}
	printf("%s\n", historia);
}

void crearLista(){
	nombres = (struct listaNombres*)malloc(sizeof(struct listaNombres));
	nombres->siguiente = NULL;
}

void agregarNombre(char nombre[50]){
	struct listaNombres *nuevoNombre = (struct listaNombres*)malloc(sizeof(struct listaNombres));
	for (int i = 0; i < 50; i++) {
		nuevoNombre->nombre[i] = nombre[i];
	}
	nuevoNombre->siguiente = NULL;

	if(nombres == NULL){
		nombres = nuevoNombre;
	}else{
		struct listaNombres *cabeza = nombres;
		while (cabeza->siguiente != NULL) {
			cabeza = cabeza->siguiente;
		}
		cabeza->siguiente = nuevoNombre;
	}
}

char *indiceNombre(int indice){
	struct listaNombres *cabeza = nombres;
	for(int i = 0; i < indice; i++){
		cabeza = cabeza->siguiente;
	}
	return cabeza->nombre;
}

void limpiarLista(){
	struct listaNombres *cabeza = nombres;
	while (cabeza != NULL) {
		nombres = nombres->siguiente;
		free(cabeza);
		cabeza = nombres;
	}
}

