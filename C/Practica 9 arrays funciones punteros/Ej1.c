/* Escribe un programa con un menú que defina las siguientes funciones y emita los resultados:

a. Cargar un vector de m elementos por teclado. Debes considerar que no podrá superar el máximo de elementos de vector 
(m=dimensión).
b. Calcular y emitir la suma de sus elementos.
c. Calcular y emitir el mínimo del vector.
d. Calcular y emitir el promedio de los valores del vector
e. Emitir los valores de aquellos que superaron ese promedio.
f. Emitir los valores del vector que son múltiplos del último número ingresado en el mismo.
g. Emitir el valor máximo e indicar la cantidad de veces que apareció y el número de orden en que fue ingresado.
h. Emitir los valores que son pares.
i. Emitir los valores que están en posiciones impares.
j. Emitir aquellos que estén ubicados en posición par.
k. Recorrer los elementos del vector hasta encontrar el número entero a. 
Deberá retornar el número de elementos que ha leído hasta encontrar a.
l. Dado un elemento y dado un vector de enteros, 
realice una función que devuelva el número de apariciones del elemento en el vector. 
Utiliza el ciclo while para esta función.
m. Invertir los elementos del vector sin utilizar otro vector. Por ejemplo, 
el vector formado por los enteros: 1 2 3, debe quedar 3 2 1. */

#include <stdio.h>
#include <stdlib.h>

#define DIM 5

void funcionInvertir(int vector[]){
    int i, aux=0;
    for(i=0;i<=DIM/2;i++){
        if (i!=DIM/2){
            aux = vector[i];
            vector[i] = vector[DIM-(i+1)];
            vector[DIM-(i+1)] = aux;
        }
    }
    printf("\nVector Invertido: \n");
    for(i=0;i<DIM;i++){
        printf("%i\n", vector[i]);
    }

    return;
}

void funcioCantElemento(int vector[]){
    int a, contA=0, i=0;
    printf("\nIngrese el elemento que se contara: \n");
    scanf("%i", &a);
    fflush(stdin);
    while(i!=DIM){
        if(vector[i]==a){
            contA++;
        }
        i++;
    }
    printf("\nLa cantidad de veces que elemento aparece en el vector es: %i\n", contA);

    return;
}

void funcionBusqueda(int vector[]){
    int a, contElementos=0, i;
    printf("\nIngrese el elemento que corte la lectura del vector: \n");
    scanf("%i", &a);
    fflush(stdin);
    for(i=0;i<DIM;i++){
        contElementos++;
        if(vector[i]==a){
            i=DIM;
        }
    }
    printf("\nLa cantidad de elementos leidos hasta encontrar a es: %i\n", contElementos);

    return;
}

void funcionPospar(int vector[]){
    int i;
    printf("\nLos valores de las posiciones pares son: ");
    for(i=0; i<DIM; i++){
        if(i%2 == 0){
            printf("| %i |",vector[i]);
        }
    }
    printf("\n");

    return;
}

void funcionPosImpar(int vector[]){
    int i;
    printf("\nLos valores de las posiciones impares son: ");
    for(i=0; i<DIM; i++){
        if(i%2 != 0){
            printf("| %i |",vector[i]);
        }
    }
    printf("\n");

    return;
}

void funcionPares(int vector[]){
    int i;
    printf("\nLos valores pares son: ");
    for(i=0; i<DIM; i++){
        if(vector[i]%2==0){
            printf("| %i |",vector[i]);
        }
    }
    printf("\n");

    return;
}

void valorMaxCantidad(int vector[]){
    int i, max=-999999, contMax=0;
    for(i=0; i<DIM; i++){
        if(max<vector[i]){
            max=vector[i];
        }
    }
    printf("\nEl valor maximo es: %i, la posicion en la que fueron ingresados fueron: \n",max);
    for(i=0; i<DIM; i++){
        if(max==vector[i]){
            contMax++;
            printf("-  %i \n", i+1);
        }
    }
    printf("y se imprimi%c %i veces\n\n", 162, contMax);

    return;
}

void funcionMultiploUltimo(int vector[]){
    int i;
    printf("Numeros multiplos del ultimo numero:\n");
    for(i=0;i<DIM;i++){
        if(vector[i] % vector[DIM-1] == 0){
            printf("- %i\n", vector[i]);
        }
    }

    return;
}

int funcionMin(int vector[]){
    int minimo=9999999, i;

    for(i=0;i<DIM;i++){
         if(vector[i]<minimo){
            minimo=vector[i];
         }
    }

    return minimo;
}

int funcionSuma(int vector[]){
    int suma=0, i;
    for(i=0;i<DIM;i++){
        suma +=vector[i];
    }

    return suma;
}

float funcionProm(int vector[]){
    float prom, suma;
    suma = funcionSuma(vector);
    prom = suma / DIM;

    return prom;
}

void funcionSupProm(int vector[]){
    int i;
    float prom;
    printf("Superiores al promedio:\n");
    prom = funcionProm(vector);
    for(i=0;i<DIM;i++){
        if (vector[i]>prom){
            printf("- %i\n", vector[i]);
        }
    }

    return;
}

void funcionCarga(int vector[]){
    int i;
    printf("Ingrese 5 valores:\n");
    for(i=0;i<DIM;i++){
        scanf("%i", &vector[i]);
        fflush(stdin);
    }

    return;
}

void funcionPrincipal(){
    char caso, flag;
    int vector[DIM]={}, suma, i;
    float promedio;
    do{
        printf("\nQuiere utilizar el menu? N - S\n");
        scanf("%c", &flag);
        fflush(stdin);
        if(flag=='S' || flag=='s'){
            printf("\n\na: Cargar un vector de m elementos por teclado.\nb: Calcular y emitir la suma de sus elementos.\nc: Calcular y emitir el minimo del vector.\nd: Calcular y emitir el promedio de los valores del vector. \ne: Emitir los valores de aquellos que superaron ese promedio.\nf: Emitir los valores del vector que son multiplos del ultimo numero ingresado en el mismo.\ng: Emitir el valor maximo e indicar la cantidad de veces que aparecio y el numero de orden en que fue ingresado.\nh: Emitir los valores que son pares.\ni: Emitir los valores que estan en posiciones impares.\nj: Emitir aquellos que estan ubicados en posicion par.\nk: Recorrer los elementos del vector hasta encontrar el numero entero a. Debera retornar el numero de elementos que ha leido hasta encontrar a.\nl: Dado un elemento y dado un vector de enteros, realice una funcion que devuelva el numero de apariciones del elemento en el vector.\nm: Invertir los elementos del vector sin utilizar otro vector. Por ejemplo, el vector formado por los enteros: 1 2 3, debe quedar 3 2 1.\n");
            scanf("%c", &caso);
            fflush(stdin);
            switch(caso){
                case 'a': 
                case 'A':   funcionCarga(vector);
                            printf("Su vector es:\n");
                            for(i=0;i<DIM;i++){
                                printf("%i\n", vector[i]);
                            }
                    break;
                case 'b':  
                case 'B':   suma = funcionSuma(vector);
                            printf("La suma de los elementos del vector es: %i\n", suma);
                    break;
                case 'c':     
                case 'C':   
                            printf("El minimo del vector es: %i\n", funcionMin(vector));
                    break;
                case 'd':
                case 'D':   promedio = funcionProm(vector);
                            printf("El promedio de los valores del vector es: %.2f\n", promedio);
                    break;
                case 'e':
                case 'E':   funcionSupProm(vector);
                            //listo
                    break;
                case 'f':
                case 'F':   funcionMultiploUltimo(vector);
                            //listo
                    break;
                case 'g':
                case 'G':   valorMaxCantidad(vector);
                    break;
                case 'h':
                case 'H':   funcionPares(vector);
                    break;
                case 'i':
                case 'I':   funcionPosImpar(vector);
                    break;
                case 'J':
                case 'j':   funcionPospar(vector);
                    break;
                case 'k':   //k. Recorrer los elementos del vector hasta encontrar el número entero a. 
                case 'K':   funcionBusqueda(vector);
                    break;
                case 'l':   //l. Dado un elemento y dado un vector de enteros, realice una función que devuelva el número de apariciones del elemento en el vector. Utiliza el ciclo while para esta función.
                case 'L':   funcioCantElemento(vector);
                    break;
                case 'm':   //m. Invertir los elementos del vector sin utilizar otro vector. Por ejemplo, el vector formado por los enteros: 1 2 3, debe quedar 3 2 1.
                case 'M':   funcionInvertir(vector);
                    break;
                default: 
                    printf("Ingreso un caracter equivocado.\n");
            }
        }
    }while(flag!='n' && flag!='N');

    return;
}

int main(){
    printf("Programa menu: \n\n");
    funcionPrincipal();


    return 0;
}