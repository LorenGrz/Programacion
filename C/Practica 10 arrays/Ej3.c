// 3. Construye un programa que permita ingresar un texto y resuelve:

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define DIM 100

void funcionDosLetras(char texto[], const int longitud){
    char letra1, letra2;
    int contPrecedencia=0, i=0;
    printf("Ingrese 2 letras: \n");
    printf("Primera: ");
    scanf("%c", &letra1);
    fflush(stdin);
    printf("\nSegunda: ");
    scanf("%c", &letra2);
    fflush(stdin);
    while(texto[i]!='.' && i != longitud){
        if(texto[i-1] == letra1 && texto[i] == letra2){
            contPrecedencia++;
        }
        i++;
    }

    printf("\nla primera letra precede a la segunda %i ", contPrecedencia);
    if(contPrecedencia<=1){
        printf("vez ");
    }else{
        printf("veces ");
    }
    printf("en el texto. \n");

    return;
}

void funcionPalabraMasLarga(char texto[], const int longitud){
    int i=0, palabraMax=-99999, palabra=0;
    while(texto[i]!='.' && i != longitud){
        palabra=0;
        while(isalpha(texto[i])!=0){//puedo usar isspace(caracter) para ver si es un espacio en blanco me devuelve 0 si no lo es.
            i++;
            palabra++;
        }
        if(palabra>palabraMax){
            palabraMax=palabra;
        }
        i++;
    }

    printf("\nLa palabra mas larga tiene %i Letras.\n", palabraMax);

    return;
}

void funcionLetraCuantas(char texto[], const int longitud){
    int contLetra=0, i=0;
    char letra;

    printf("Ingrese la letra a contar:\n");
    scanf("%c", &letra);
    fflush(stdin);

    while(i != longitud){
       if(toupper(letra)==texto[i] || tolower(letra)==texto[i]){
        contLetra++;
       }
       i++;
    }

    printf("\nLa cantidad de veces que aparece '%c' es: %i\n", letra, contLetra);

    return;
}

void funcionVocal(char texto[], const int longitud){
    int contA=0, contE=0, contI=0, contO=0, contU=0, i, mayor;
    char vocal;
    for(i=0; texto[i]!='.' && i != longitud; i++){
        if(texto[i]=='a'||texto[i]=='A'){
            contA++;
        }
        if(texto[i]=='e'||texto[i]=='E'){
            contE++;
        }
        if(texto[i]=='i'||texto[i]=='I'){
            contI++;
        }
        if(texto[i]=='o'||texto[i]=='O'){
            contO++;
        }
        if(texto[i]=='u'||texto[i]=='U'){
            contU++;
        }
    }
    mayor=-999999;

    if(contA>mayor){
        vocal='A';
        mayor=contA;
    }
    if(contE>mayor){
        vocal='E';
        mayor=contE;
    }
    if(contI>mayor){
        vocal='I';
        mayor=contI;
    }
    if(contO>mayor){
        vocal='O';
        mayor=contO;
    }
    if(contU>mayor){
        vocal='U';
        mayor=contU;
    }
    

    printf("\nLa vocal que mas se repite es la: %c\n", vocal);

    return;
}

void funcionContarPalabras(char texto[], const int longitud){
    int contP=0, i=0;
    while(texto[i]!='.' && i != longitud){
        while(isalpha(texto[i])!=0){//puedo usar isspace(caracter) para ver si es un espacio en blanco me devuelve 0 si no lo es.
            i++;
        }
        if(isalpha(texto[i-1])!=0){
            contP++;
            i++;
        }else{
            i++;
        }
        
    }

    printf("\nLa cantidad de Palabras es: %i", contP);

    return;
}

void funcionContLetras(char texto[], const int longitud){
    int contL=0, i=0;
    while(texto[i]!='.' && i != longitud){
        if(texto[i]!=' ' && isalpha(texto[i])!=0){//puedo usar isspace(caracter) para ver si es un espacio en blanco me devuelve 0 si no lo es.
            contL++;
        }
        i++;
    }

    printf("\nLa cantidad de letras hasta un punto es: %i\n", contL);

    return;
}

int main(){
    char texto[DIM]="";
    printf("Ingrese el texto: \n");
    gets(texto);
    fflush(stdin);
    int longitud = strlen(texto);
    texto[longitud+1]='\0';

    // a.  Contar la cantidad de letras de un texto que termina en punto (los textos se leen letra por letra).
    funcionContLetras(texto, longitud);
    // b.  Contar la cantidad de palabras, separadas por uno o más espacios, de un texto que termina en punto. 
    funcionContarPalabras(texto, longitud);
    // c.  Dado un texto terminado en punto, determinar cuál es la vocal que aparece con mayor frecuencia.
    funcionVocal(texto, longitud);
    // d.  Dado un texto se pide determinar cuántas veces aparece determinada letra, leída de teclado. 
    funcionLetraCuantas(texto, longitud);
    // e.  Dado un texto averiguar qué cantidad de letras tiene la palabra más larga.  
    funcionPalabraMasLarga(texto, longitud);
    // f. Leer dos letras de teclado y luego un texto. Se pide determinar la cantidad de veces que la primera letra 
    // precede a la segunda en el texto
    funcionDosLetras(texto, longitud);

    return 0;
}