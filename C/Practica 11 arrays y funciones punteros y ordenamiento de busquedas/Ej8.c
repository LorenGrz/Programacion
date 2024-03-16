// Escribe un programa para ordenar un vector de 1000 números. Además de emitir la lista ordenada, el programa debe 
// determinar si hubo repetición en el número máximo. Si lo hubo, deberá emitir cuántas veces se presento el número más 
// grande. 

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 1000

void cantMax(int vector[]){
    int i, max=-9999, contMax=0;
    for(i = 0; i < N-1; i++){
        if(vector[i]>max){
            max=vector[i];
        }
    }

    for(i = 0; i < N-1; i++){
        if(vector[i]==max){
            contMax++;
        }
    }
    printf("\nEl numero maximo se presento %i veces", contMax);

    return;
}

void ordenarVector(int vector[]){
    int i, j, aux;

    for (i = 0; i < N-1; i++) {
        for (j = 0; j < N-i-1; j++) {
            if (vector[j] > vector[j+1]) {
                // Intercambiamos los elementos en las posiciones j y j+1
                aux = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = aux;
            }
        }
    }
    printf("Array ordenado:\n\n");
    for(i = 0; i < N-1; i++){
        printf("- %i ",vector[i]);
    }
    printf("\n");

    return;
}

void carga(int vector[]){
    int i;
    for(i=0;i<N-1;i++){
        vector[i] = rand()%99;
    }
    printf("Array desordenado:\n\n");
    for(i = 0; i < N-1; i++){
        printf("- %i ",vector[i]);
    }
    printf("\n");

    return;
}

int main(){
    int vector[N];
    srand(time(NULL));
    carga(vector);
    ordenarVector(vector);
    cantMax(vector);

    return 0;
}