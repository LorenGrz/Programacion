#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define DIM 40
#define ALUMNOS 2

struct alumnos{
    char apellido[DIM];
    char nombre[DIM];
    char arrayConcatenado[DIM];
    float notas[5];
    float promedios;
    float mayorNota;
};

int funcionBusquedaBinaria(struct alumnos Arr[], char apellidoBusqueda[]){
    int inicio=0;
    int fin=DIM-1;
    int condicion, i, mitad;

    printf("Ingrese el apellido del alumno a buscar:\n");
    gets(apellidoBusqueda);
    fflush(stdin);

    int longitud = (strlen(apellidoBusqueda));
    apellidoBusqueda[longitud]='\0';

    for(i=0; i<longitud; i++){
        apellidoBusqueda[i] = toupper(apellidoBusqueda[i]);
    }

    while (inicio <= fin){
        mitad = inicio + ((fin - inicio) / 2);
        condicion = (strcmp(Arr[mitad].apellido, apellidoBusqueda));
        if (condicion == 0) {
            return mitad;
        } else if (condicion < 0) {
            inicio = mitad + 1;
            } else {
                fin = mitad - 1;
            }
    }

    return -1;
}
int main(){
    struct alumnos Arr[ALUMNOS];
    char apellidoBusqueda[DIM];
    int i, j;
    for(i=0; i<ALUMNOS; i++){
        printf("Ingrese el nombre del alumno N %i\n", i+1);
        gets(Arr[i].nombre);
        fflush(stdin);

        printf("Ingrese el apellido del alumno N %i\n", i+1);
        gets(Arr[i].apellido);
        fflush(stdin);

        int longAp = strlen(Arr[i].apellido);
        Arr[i].apellido[longAp]='\0';

        for(j=0;j<longAp;j++){
            Arr[i].apellido[j]=toupper(Arr[i].apellido[j]);
        }
    }
    struct alumnos aux;
    
    for (i = 0; i < ALUMNOS-1; i++) {
        for (j = 0; j < ALUMNOS-i-1; j++) {
            if (strcmp(Arr[i].apellido, Arr[i+1].apellido)>0){
                // Intercambiamos los elementos en las posiciones j y j+1
                aux = Arr[i];
                Arr[i] = Arr[i+1];
                Arr[i+1] = aux;
            }
        }
    }
    
    int posicion = funcionBusquedaBinaria(Arr, apellidoBusqueda);
    if(posicion!=-1){
        printf("El apellido %s se encuentra en la posicion %i.\n", apellidoBusqueda, posicion);
        printf("Sus datos son:\n");
        printf("Nombre y apellido: %s\n", Arr[posicion].arrayConcatenado);
        printf("Promedio: %.2f\n", Arr[posicion].promedios);
        printf("Mayor nota: %.2f\n", Arr[posicion].mayorNota);
    }else{
        printf("No se a encontrado el apellido\n");
    }
}