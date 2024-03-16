/* El acrónimo de un nombre consiste en una cadena formada por las letras 
iniciales mayúsculas de cada palabra que aparece en dicho nombre. 
Se pide escribir un programa que, a partir de un nombre introducido por el usuario, 
construya una nueva cadena con su acrónimo y la muestre por pantalla. Por ejemplo, 
para el nombre “Informática Básica” se emitirá la cadena “IB”, 
mientras que para el nombre “Fundamentos de Informática” se emitirá “FI”. */
#include <stdio.h>
#include <string.h>
#define DIM 20

int main(){
    char palabra[DIM]="";
    char acronimo[DIM]="";
    int i, j=0;
    printf("Introduzca su nombre tio:\n");
    gets(palabra);
    fflush(stdin);
    int longitud = strlen(palabra);

    for(i=0;i<longitud;i++){
        if(palabra[i-1]==' ' || palabra[i] == palabra[0]){
            if(palabra[i] >= 'A' && palabra[i] <= 'Z'){
                acronimo[j] = palabra[i];
                j++;
            }
        }
    }
    acronimo[j]='\0';
    
    for(i=0;i<longitud; i++){
        printf("%c", acronimo[i]);
    }

    return 0;
}
//Para los nombres DIM 20