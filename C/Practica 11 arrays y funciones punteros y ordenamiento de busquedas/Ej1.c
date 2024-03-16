/*Se desea comparar el funcionamiento de los diferentes métodos de búsqueda. 
Para ello se pretende buscar el número 27 en el siguiente vector: 1 4 5 12 25 27 31 42 43 56 73 76 78 80 99. 
Indica los pasos que seguirían los siguientes algoritmos:
a) Búsqueda secuencial. b) Búsqueda binaria.*/
#include <stdio.h>
#include <string.h>
#define DIM 20

void busquedaSecuencial(int arr[],int valorBuscado ){
    int i;
    for (i = 0; i < DIM; i++) {
        if (arr[i] == valorBuscado) {
            printf("El valor %d se encuentra en la posicion %d del arreglo.\n", valorBuscado, i);
            break;
        }
    }
  
    if (i == DIM) {
        printf("El valor %d no se encuentra en el arreglo.\n", valorBuscado);
    }

    return;
}

int busquedaBinaria(int arr[], int inicio, int fin, int valorBuscado) {
    while (inicio <= fin) {
        int mitad = inicio + (fin - inicio) / 2;
        
        if (arr[mitad] == valorBuscado) {
            return mitad;
        } else if (arr[mitad] < valorBuscado) {
            inicio = mitad + 1;
            } else {
                fin = mitad - 1;
            }
    }
    return -1;
}

int main(){
    int arr[DIM]={1, 4, 5, 12, 25, 27, 31, 42, 43, 56, 73, 76, 78, 80, 99,};
    int valorBuscado=27;

    printf("A)\n");
    
    busquedaSecuencial(arr, valorBuscado);

    printf("B)\n");

    int indice= busquedaBinaria(arr, 0, DIM-1, valorBuscado);

    if (indice == -1) {
    printf("El valor %d no se encuentra en el arreglo.\n", valorBuscado);
  } else {
    printf("El valor %d se encuentra en la posicion %d del arreglo.\n", valorBuscado, indice);
  }

    getchar();
    return 0;
}