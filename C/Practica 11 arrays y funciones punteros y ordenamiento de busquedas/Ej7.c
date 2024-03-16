/* La moda o valor modal de una lista de números se define como aquel número 
que tiene el máximo valor de apariciones en la lista. 
Por ejemplo para el conjunto: 72,72,72,75,75,75,78,82,82,82,82,85,85,85,89, la moda es el valor: 82. 
Escribe una función que determine el valor modal para un vector de enteros ordenado 
y una función de búsqueda secuencial de un valor. */
#include <stdio.h>

void busquedaSecuencial(int arr[], const int size){
    int i, valorBuscado;
    printf("Ingrese el valor buscado:\n");
    scanf("%i", &valorBuscado);
    fflush(stdin);

    for (i = 0; i < size; i++) {
        if (arr[i] == valorBuscado) {
            printf("El valor %d se encuentra en la posicion %d del arreglo.\n", valorBuscado, i);
        }
    }

    return;
}

int moda(int arr[], int size) {
    int count[size]; 
    int i, j, maxCount = 0, mode;

    for (i = 0; i < size; i++) {
        count[i] = 0;
    }

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (arr[i] == arr[j]) {
                count[i]++;
            }
        }
    }

    mode = arr[0]; // Valor modal inicialmente asumido como el primer elemento del vector

    for (i = 1; i < size; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
            mode = arr[i];
        }
    }

    return mode;
}

int main() {
    int vector[] = {72, 72, 72, 75, 75, 75, 78, 82, 82, 82, 82, 85, 85, 85, 89};
    int size = sizeof(vector) / sizeof(vector[0]);
    
    // Determinar la moda del vector
    int valorModal = moda(vector, size);
    printf("La moda del vector es: %d\n", valorModal);
    
    busquedaSecuencial(vector, size);

    return 0;
}