//Ejemplo de busqueda binaria
#include <stdio.h>

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

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int n = 10;
  int valorBuscado = 8;
  
  int indice = busquedaBinaria(arr, 0, n-1, valorBuscado);
  
  if (indice == -1) {
    printf("El valor %d no se encuentra en el arreglo.\n", valorBuscado);
  } else {
    printf("El valor %d se encuentra en la posición %d del arreglo.\n", valorBuscado, indice);
  }
  
  return 0;
}