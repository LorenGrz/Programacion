// Se ingresa una matriz de NxM componentes enteras. La computadora muestra las sumatorias 
// de las columnas y emite los elementos de cada una ordenados de menor a mayor. 
#include <stdio.h>
#define FILAS 10
#define COLUMNAS 2

int main(){
    int matriz[FILAS][COLUMNAS]={{9,5},{6,8},{3,5},{4,3},{7,4},{1,2},{3,4},{5,6},{7,8},{9,1}};
    int suma[COLUMNAS];
    int fila, col;
    printf("Matriz:\n");
    for(fila=0; fila<FILAS; fila++){
        for(col=0; col<COLUMNAS; col++){
            printf("|%i| ", matriz[fila][col]);
        }
        printf("\n");
    }

    for (col = 0; col < COLUMNAS;col++){
        suma[col]=0;
        for(fila = 0; fila < FILAS;fila++){
            suma[col] += matriz[fila][col];
        }
    }

    printf("Elementos suma desordenados:\n");
 
    for(col=0; col<COLUMNAS; col++){
        printf("|%i| ", suma[col]);
        printf("\n");
    }
    int aux[COLUMNAS];
    for (col = 0; col < COLUMNAS-1; col++){
        aux[col]=0;
        for(fila = 0; fila < FILAS-col-1; fila++){
            if(suma[col]>suma[col+1]){
                aux[col]=suma[col];
                suma[col]=suma[col+1];
                suma[col+1]=aux[col];
            }  
        }
    }
    printf("\n");
    printf("Elementos suma ordenados:\n");
    for(col=0; col<COLUMNAS; col++){
        printf("|%i| ", suma[col]);
        printf("\n");
    }

    return 0;
}