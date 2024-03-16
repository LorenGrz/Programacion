#include <stdio.h>
#include <string.h>
#define DIM 20

/* Escribe un programa que busque un carácter determinado en una cadena ingresada por teclado.
Debe emitir un número con la posición de la cadena en que fue encontrado el carácter
(la primera posición es la cero), si no se encontró mostrará -1.
Los datos de entrada serán la cadena y el carácter a buscar.
*/

int main(){

    char vec[DIM], c;
    int i;

    printf("Ingrese una palabra:\n");
    fgets(vec,sizeof(vec),stdin);
    printf("Ingrese un caracter:\n");
    scanf("%c", &c);

    for(i=0;i<DIM;i++){
        if(vec[i]==c){
            printf("Posicion: %i\n\n", i);
        }else{
            printf("-1\n\n");
        }
    }
}