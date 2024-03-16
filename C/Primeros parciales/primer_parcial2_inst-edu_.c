/*
Datos
Una institución educativa de nivel primario, con dos grados por año, A y B, necesita un
programa que procese notas de alumnos. Para ello, la secretaria se reúne con usted y
definen los requerimientos.
Requerimiento:

1. Construir una función que permita procesar 7 años (1ero. a 7mo.). Por cada año se tiene
e ingresan una cantidad desconocida de números de legajos (mayores a 0) de
alumnos(no se sabe qué cantidad de alumnos hay por grado ya que hay alumnos nuevos
y otros que pidieron el pase a otra escuela). Finalizan los ingresos de este proceso con
legajo 0 (cero) y por cada legajo se ingresa:
 grado al cual pertenece el alumno, A ó B , tipo caracter, no están ordenados, es
decir que indistintamente pueden ingresarse tanto A como B
 nota, es un número real, de 1 a 10
Esta función debe emitir, por cada grado el promedio de notas por cada división. Ej.:
….
(*) Grado 1 – promedio general:
A = 6.89
B = 7.10
…..
(*) Grado 2 – promedio general:
A = 5.90
B = 9.80
…..
2. Construir una función que reciba (al menos) grado (A ó B) y nota, y acumule en función
de A y B, la suma total de notas por cada uno, contando además la cantidad. La finalidad
de esta función sólo es acumular y contar para que la función 1 pueda emitir el mensaje
del ejemplo del ítem anterior. En esta función no se ingresan valores por teclado, no
retorna un valor, ni se emiten mensajes.
3. Mensaje final en main(), que emita:
 total de legajos procesados.
 el mayor promedio de todos, año y grado (A ó B) que lo obtuvo.
*/
#include <stdio.h>

void funcion2(const char *grad, int *cA, int *cB, float *not, float *pA, float *pB){
    switch(*grad){
        case 'a':
        case 'A':   (*cA)++;
                    *pA += *not;
            break;
        case 'b':
        case 'B':   (*cB)++;
                    *pB += *not;
            break;
    }

    return;
}

void funcion1(int *tlegajos, int *aniO, float *mayorprom, char *gradO){
    int i, legajo=0, contA=0, contB=0;
    float nota=0, acumA=0, acumB=0, promA=0, promB=0;
    char gradoo = 'a';
    for (i=1;i<8;i++){
        do{
            do{
                if(legajo<0){
                    printf("El numero debe ser positivo.\n");
                }
                printf("Grado numero: %i\n", i);
                printf("Ingrese el numero de legajo, finaliza con 0:\n");
                scanf("%d",&legajo);
                fflush(stdin);
                fflush(stdin);
            }while(legajo<0);
            if(legajo!= 0){
                (*tlegajos)++;
                do{
                    if(gradoo!='a' && gradoo!='b' && gradoo!='A' && gradoo!='B'){
                        printf("Ingrese el caracter correctamente\n");
                    }
                    printf("Ingrese el grado (A o B):\n");
                    scanf("%c", &gradoo);
                    fflush(stdin);
                    fflush(stdin);
                }while(gradoo!='a' && gradoo!='b' && gradoo!='A' && gradoo!='B');
                do{
                    printf("Ingrese la nota del alumno:\n");
                    scanf("%f", &nota);
                    fflush(stdin);
                    fflush(stdin);
                }while(nota<1 || nota>10);
            }
        }while(legajo!=0);
        funcion2(&gradoo,&contA,&contB,&nota,&acumA,&acumB);
        promA = acumA/contA;
        promB = acumB/contB;
        if(promA>promB){
            *mayorprom = promA;
            *aniO = i;
            *gradO = 'A';
        }else if(promB>promA){
            *mayorprom = promB;
            *aniO = i;
            *gradO = 'B';
         }
        printf("(*) Grado %i - promedio general:\nA = %.2f\nB = %.2f\n\n", i, promA, promB);
    }

    return;
}

int main(){
    char grado;
    int totallegajos=0, anio=0;
    float prommayor=0.00;

    funcion1(&totallegajos, &anio, &prommayor, &grado);

    printf("El total de legajos procesados es: %i\n", totallegajos);
    printf("El mayor promedio es: %.2f su anio es: %i y su grado es: '%c'\n", prommayor, anio, grado);
    getchar();

    return 0;
}
