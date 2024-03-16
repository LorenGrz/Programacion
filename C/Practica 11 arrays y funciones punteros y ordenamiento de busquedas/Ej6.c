/* Escribe un programa para ordenar un vector de 1000 números. 
Además de emitir la lista ordenada, el programa debe determinar si hubo repetición en el número máximo. 
Si lo hubo, deberá emitir cuántas veces se presento el número más grande. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
#define DIM 1000

int cantidadmax(int tnum[]){
    int contmax=0, i, maxnum=0;
    for (i=0; i<DIM; i++){
        if(tnum[i]>maxnum){
            maxnum=tnum[i];
        }
    }
    for (i=0; i<DIM; i++){
        if(tnum[i]==maxnum){
            contmax++;
        }
    }

    return contmax;
}

void ordenamiento(int tnum[], int i){
    int j, aux;

    for (i = 0; i < DIM-1; i++) {
        for (j = 0; j < DIM-i-1; j++) {
            if (tnum[j] > tnum[j+1]) {
                // Intercambiamos los elementos en las posiciones j y j+1
                aux = tnum[j];
                tnum[j] = tnum[j+1];
                tnum[j+1] = aux;
            }
        }
    }
}

void carga(int *tnum){
    int i;
    for(i=0;i<DIM;i++){
        tnum[i] = 10 + rand()%99;
    }

    return;
}

int main(){
    int tnum[DIM], i;
    //Inicializo el generador de numeros
    srand(time(NULL));
    //funcion carga
    carga(tnum);

    printf("\nArray desordenado:\n");
    for(i=0;i<DIM;i++){
        printf("%i - ", tnum[i]);
    }

    ordenamiento(tnum, i);
    printf("\n\nArray ordenado:\n");
    for(i=0;i<DIM;i++){
        printf("%i - ", tnum[i]);
    }
    int totalmax=cantidadmax(tnum);

    printf("\n\nEl valor maximo se repitio %i veces.\n", totalmax);
 
    return 0;
}