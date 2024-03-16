//. Se ingresa una matriz de NxM componentes. Se emite por pantalla:
//a. la cantidad de ceros que contiene
//b. el valor máximo de cada columna.
//c. el elemento mínimo de toda la matriz y las posiciones en que aparece.
//d. el promedio de la matriz
//e. el promedio de cada columna
//f. los promedios de cada fila, e indica qué filas tienen el promedio máximo.
//g. el menor y mayor elemento de esa matriz y sus posiciones.
//h. devuelva el número de elementos negativos, iguales a cero y positivos que hay en
//ella.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILAS 5
#define COLUMNAS 4

void maximoPorColumna(int array[][COLUMNAS]){//NO FUNCIONA
    int arrayMax[COLUMNAS]={0}, col, fila, max;

    for (col = 0; col < COLUMNAS;col++){
        max = array[0][col];

        for(fila = 1; fila < FILAS;fila++){
            if (max<array[fila][col]){
                max=array[fila][col];
            }
        }
        arrayMax[col] = max;
    }
    
    for(int i=0; i<COLUMNAS; i++){
        printf("Max de columna %i: %i\n", i+1, arrayMax[i]);
    }

    return;
}

void cantidadCeros(int array[][COLUMNAS]){
    int contCeros=0,fila,col;
    for (fila=0; fila<FILAS;fila++){ 
        for(col=0; col<COLUMNAS; col++){
            if(array[fila][col]==0){
                contCeros++;
            }
        }
    }
    printf("\nEn el array hay %i ceros\n\n", contCeros);

    return;
}

void funcionCarga(int array[][COLUMNAS]){
    int i, j;
    srand(time(NULL));
    for (i=0; i < FILAS;i++){
        for(j=0; j < COLUMNAS;j++){
            array[i][j]=rand()%20;
        }
    }
    printf("Array cargado: \n\n");
    for (i=0; i < FILAS; i++){
        for(j=0; j < COLUMNAS; j++){
            printf("-%i ",array[i][j]);
        }
        printf("\n");
    }

    return;
}

int main(){
    int array[FILAS][COLUMNAS];
    funcionCarga(array);
    cantidadCeros(array);
    maximoPorColumna(array);

    return 0;
}