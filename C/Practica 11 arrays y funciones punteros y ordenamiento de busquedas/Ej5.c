//Ejemplo de burbujeo
#include <stdio.h>
#include <string.h>

void ordenamientoBurbuja(int arr[], int n) {
    int i, j, temp;

    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
            // Intercambiamos los elementos en las posiciones j y j+1
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    int n = 5;
    int i;

    printf("Arreglo original: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    ordenamientoBurbuja(arr, n);

    printf("\nArreglo ordenado: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}