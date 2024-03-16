// Escribe un programa que almacene en una matriz los números impares del 1 al 50 y los 
// imprima. 
#include <stdio.h>

#define FILAS 5
#define COLUMNAS 10

int main(){
    int matriz[FILAS][COLUMNAS]={0}, fil, col, cont=0;
    for(fil=0; fil<FILAS; fil++){
        for(col=0; col<COLUMNAS; col++){
            cont++;
            matriz[fil][col] = cont;
        }
    }
    for(fil=0; fil<FILAS; fil++){
        printf("\n");
        for(col=0; col<COLUMNAS; col++){
            printf("%i ", matriz[fil][col]);
        }
    }

    return 0;
}