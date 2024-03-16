/* Desarrolla un algoritmo que le permita leer un valor cualquiera N 
y escribir en la pantalla si dicho número es Positivo, Negativo o 0 (cero). */
#include <stdio.h>

int main(){
    float valor;

    printf("Ingrese un valor cualquiera\n\n");
    scanf("%f", &valor);
    fflush(stdin);
    fflush(stdin);

    if(valor>0){
        printf("El valor es positivo\n\n");
    }else if(valor<0){
        printf("El valor es negativo\n\n");
    }else{
        printf("El valor es cero\n\n");
    }
    
    printf("Ingrese cualquier caracter para terminar el programa\n");
    getchar();

    return 0;
}
