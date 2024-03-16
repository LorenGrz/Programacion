/*Dado un vector de dimensión N. Se debe pedir un valor x (float) y la posición i al usuario para almacenar x en la 
posición i de un vector. Los valores no se ingresan ordenados por posición. Se debe completar el tamaño del vector. 
Si la posición está ocupada se vuelve a pedir el ingreso. Al finalizar, emitir el contenido del vector indicando también 
la posición ocupada por cada número. Utiliza el ciclo while y funciones. */

#include <stdio.h>
#define N 50

void funcionVector(float vector[]){
    char B='S';
    float valor;
    int posicion;
    printf("Quiere ingresar un valor? S-N:\n");
    scanf("%c", &B);
    fflush(stdin);
    while(B != 'N' && B != 'n'){
        printf("\nIngrese un valor fotante:\n");
        scanf("%f", &valor);
        fflush(stdin);
        do{
        printf("\nIngrese una posicion:\n");
        scanf("%i", &posicion);
        fflush(stdin);
        }while(vector[posicion]!=0);
        vector[posicion]=valor;
        printf("Quiere ingresar un valor? S-N:\n");
        scanf("%c", &B);
        fflush(stdin);
    }

    return;
}

int main(){
    int i;
    float vector[N]={0};
    funcionVector(vector);
    printf("\nPosicion y contenido de los elementos del vector:");

    for(i=0; i<N;i++){
        if(vector[i]!=0){
            printf("posicion %i: %.2f \n", i, vector[i]);
        }
    }

    return 0;
}