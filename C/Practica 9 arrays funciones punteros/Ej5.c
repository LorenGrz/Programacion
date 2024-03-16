// Escribe un programa en el que se defina un vector de 10 punteros a float, se lean diez números en las ubicaciones 
// en las que hacen referencia cada uno de los punteros del vector de punteros. Cuando este completo, se sumen 
// todos los números y se almacene el resultado en una dirección a la que haga referencia un puntero ajeno al vector. 
// El programa deberá mostrar el contenido de todas las variables, tanto los punteros como los datos de tipo float. 

#include <stdio.h>
#include <stdlib.h>

int main(){
    int i;
    float *vectorPunteros[10], vector[10], suma=0.0, *resultPunt;;
    
    for(i=0; i<10; i++){
        vectorPunteros[i] = &vector[i];
    }

    for(i=0; i<10; i++){
        printf("Ingrese un numero para la posicion %i:\n", i);
        scanf("%f", vectorPunteros[i]);
        fflush(stdin);
        suma += *vectorPunteros[i];
    }

    resultPunt = &suma;

    // Mostrar los contenidos de los punteros y los datos de tipo float
    printf("\nPunteros:\n");
    for (i = 0; i < 10; i++) {
        printf("vectorPunteros[%d]: %p\n", i, vectorPunteros[i]);
    }

    printf("\nDatos de tipo float:\n");
    for (i = 0; i < 10; i++) {
        printf("vector[%d]: %.2f\n", i, vector[i]);
    }

    printf("\nContenido del puntero 'resultPunt': %p\n", resultPunt);
    printf("Contenido de la direccion apuntada por 'resultPunt': %.2f\n", *resultPunt);

    return 0;
}