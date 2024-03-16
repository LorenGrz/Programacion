// Declara una matriz de número reales de tamaño DIMxDIM (DIM constante con valor 5). 
// Escribir las siguientes funciones: 
// a. Función Simetrica: Dada una matriz indica si la matriz es simétrica (1) o si no 
// lo es (0). 
// int simetrica(float mat[]); 
// b. Funcion Suma: Dadas dos matrices, calcular la suma de éstas. 
// void sumaMat(float mat1[],float mat2[], res[]); 
// c. Funcion Resta: Dadas dos matrices, calcular la resta de éstas. Piensa esta 
// respuesta utilizando el procedimiento de suma de matrices, definido anteriormente. 
// d. Función Multiplica: Dadas dos matrices, devuelve el producto de ellas. 
// void multiMat(float mat1[],float mat2[], res[]); 
#include <stdio.h>

#define DIM 5

// Función para comprobar si una matriz es simétrica
int simetrica(float mat[]) {
    int fila, col;
    for (fila = 0; fila < DIM; fila++) {
        for (col = 0; col < DIM; col++) {
            if (mat[fila * DIM + col] != mat[col * DIM + fila]) {
                return 0; // No es simétrica
            }
        }
    }
    return 1; // Es simétrica
}

// Función para calcular la suma de dos matrices
void sumaMat(float mat1[][DIM], float mat2[][DIM], float res[][DIM]) {
    int i;
    for (i = 0; i < DIM * DIM; i++) {
        res[i][i] = mat1[i][i] + mat2[i][i];
    }
}

// Función para calcular la resta de dos matrices
void restaMat(float mat1[][DIM], float mat2[][DIM], float res[][DIM]) {
    int i;
    for (i = 0; i < DIM * DIM; i++) {
        res[i][i] = mat1[i][i] - mat2[i][i];
    }
}

// Función para calcular el producto de dos matrices
void multiMat(float mat1[], float mat2[], float res[]) {
    int i, j, k;
    for (i = 0; i < DIM; i++) {
        for (j = 0; j < DIM; j++) {
            res[i * DIM + j] = 0;
            for (k = 0; k < DIM; k++) {
                res[i * DIM + j] += mat1[i * DIM + k] * mat2[k * DIM + j];
            }
        }
    }
}

int main() {
    // Declaración de la matriz
    float matriz[DIM][DIM];

    // Ejemplo de uso de las funciones
    int i, j;
    float resultado[DIM][DIM];

    // Inicialización de la matriz
    for (i = 0; i < DIM; i++) {
        for (j = 0; j < DIM; j++) {
            matriz[i][j] = i + j + 1; // Solo como ejemplo, puedes modificar los valores
        }
    }

    // Comprobación si la matriz es simétrica
    int esSimetrica = simetrica(matriz[0]);
    printf("La matriz es ");
    if(esSimetrica!=-1){
        printf("simetrica");
    }else{
        printf("no simetrica");
    }

    // Suma de dos matrices
    float matriz2[DIM][DIM];
    // Inicialización de la segunda matriz
    for (i = 0; i < DIM; i++) {
        for (j = 0; j < DIM; j++) {
            matriz2[i][j] = i - j - 1; // Solo como ejemplo, puedes modificar los valores
        }
    }
    sumaMat(matriz, matriz2, resultado);

    // Resta de dos matrices
    float resultadoResta[DIM][DIM];
    restaMat(matriz, matriz2, resultadoResta);

    // Producto de dos matrices
    float resultadoMulti[DIM][DIM];
    multiMat(matriz[0], matriz2[0], resultadoMulti[0]);

    return 0;
}