// Escribe una  función  inversa  que  recibe una  cadena como  parámetro y devuelve  los caracteres de la 
// misma en orden inverso. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DIM 50

void funcionInversa(char cadena[], const int longitud){
    char aux;
    int i;
    for(i=0;i<longitud/2;i++){
        aux=cadena[i];
        cadena[i]=cadena[longitud-(i+1)];
        cadena[longitud-(i+1)] = aux;
    }
    printf("%s\n",cadena);
    // printf("Cadena invertida:\n");
    // for(i=0;i<longitud;i++){
    //     printf("-  %c  -\n", cadena[i]);
    // }

    return;
}

int main(){
    char cadena[DIM]="";
    printf("Ingrese la cadena:\n");
    gets(cadena);
    fflush(stdin);
    int longitud = strlen(cadena);
    cadena[longitud]='\0';
    printf("Cadena inicial:\n");
    printf("%s\n", cadena);
    // for(int i=0;i<longitud;i++){
    //     printf("-  %c  -\n", cadena[i]);
    // }
    funcionInversa(cadena, longitud);

    return 0;
}