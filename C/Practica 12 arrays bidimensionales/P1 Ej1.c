// Escribe un programa de liquidación de pagos por servicios, para una pequeña compañía que tiene 8 empleados temporales. Con 
// un menú de opciones y para cada empleado/a, el programa recibe los siguientes datos en un array de struct: 
// a. el nombre y apellido,  
// b. sexo,  
// c. horas trabajadas y  
// d. sueldo por hora.  
// Por cada empleado ingresado, el programa deberá mostrar en pantalla en forma ordenada: 
//  el nombre  
//   el sueldo  
// Además debe permitir, mediante el menú acceder a la siguiente información:  
//  El total de pagos para cada sexo y  
//  el sueldo promedio de hombres y de mujeres.  
//  Búsqueda binaria de los datos de un empleado mediante el nombre. 
// El programa debe emitir todos los mensajes necesarios para que el usuario opere en forma eficaz, convertir el apellido de cada 
// empleado a Mayúsculas (ver ejemplo empleo de toupper.c) antes de guardarlo en el array, validar el sexo, permitiendo ingresar 
// minúsculas o mayúsculas indistintamente, horas trabajadas (> a 0 y <=50) y sueldo (base=$250.50 la hora) y controlar al menos 3 
// errores (ver ejemplo control de errores con cadenas.c). Las búsquedas por nombre y/o apellido deben considerar que el usuario 
// puede ingresar esos datos en minúsculas por lo tanto hay que convertir la cadena antes de realizar el proceso. 
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define EMPLEADOS 2
#define DIM 30

struct empleados{
    char nombre[DIM];
    char apellido[DIM];
    char sexo;
    int horas;
    float sueldoPorHora;
};

int funcionBusquedaBinaria(struct empleados A[], char nombreE[]){//  Búsqueda binaria de los datos de un empleado mediante el nombre.
    int inicio=0;
    int fin=EMPLEADOS;
    int condicion;

    printf("Ingrese el nombre del empleado a buscar:\n");
    gets(nombreE);
    fflush(stdin);
    int longitud = strlen(nombreE);
    nombreE[longitud]='\0';

    while (inicio <= fin) {
        int mitad = inicio + ((fin - inicio) / 2);
        condicion = (strcmp(A[mitad].nombre, nombreE));
        if  (condicion == 0) {
            return mitad;
        } else if (condicion < 0) {
            inicio = mitad + 1;
            } else {
                fin = mitad - 1;
            }
    }
    return -1;

}

void funcionPromedio(struct empleados A[]){// el sueldo promedio de hombres y de mujeres.
    int i, contM=0, contF=0;
    float acumM=0.00, acumF=0.00, promM, promF;

    for(i=0; i<EMPLEADOS; i++){
        if(A[i].sexo=='M' || A[i].sexo=='m'){
            acumM += (A[i].sueldoPorHora * A[i].horas);
            contM++;
        }
        if(A[i].sexo=='F' || A[i].sexo=='f'){
            acumF += (A[i].sueldoPorHora * A[i].horas);
            contF++;
        }
    }

    float cantM = contM;
    float cantF = contF;
    promM = acumM / cantM;
    promF = acumF / cantF;
    printf("El sueldo promedio de los hombres es: $%.2f\n", promM);
    printf("El sueldo promedio de las mujeres es: $%.2f\n", promF);

    return;
}

void funcionPagos(struct empleados A[]){//  El total de pagos para cada sexo 
    int i;
    float acumM=0.00, acumF=0.00;
    for(i=0; i<EMPLEADOS; i++){
        if(A[i].sexo=='M' || A[i].sexo=='m'){
            acumM += (A[i].sueldoPorHora * A[i].horas);
        }
        if(A[i].sexo=='F' || A[i].sexo=='f'){
            acumF += (A[i].sueldoPorHora * A[i].horas);
        }
    }
    printf("El total de pago para el sexo 'M' es: $%.2f\n", acumM);
    printf("El total de pago para el sexo 'F' es: $%.2f\n", acumF);
    
    return;
}

void funcionCarga(struct empleados A[]){
    int i, j;
    float sueldo[EMPLEADOS];

    for(i=0; i<EMPLEADOS; i++){
        printf("Ingrese el nombre del/la empleado/a:\n");
        gets(A[i].nombre);
        fflush(stdin);

        int longNo = strlen(A[i].nombre);
        A[i].nombre[longNo]='\0';

        printf("Ingrese el apellido del/la empleado/a:\n");
        gets(A[i].apellido);
        fflush(stdin);

        int longAp = strlen(A[i].apellido);
        // A[i].apellido[longAp]='\0';
        for(j=0; j<longAp;j++){
            A[i].apellido[j]=toupper(A[i].apellido[j]);
        }

        do{
            printf("Ingrese el sexo del empleado/a (M - F):\n");
            scanf("%c", &A[i].sexo);
            fflush(stdin);
            if(A[i].sexo != 'M' && A[i].sexo != 'm' && A[i].sexo != 'F' && A[i].sexo != 'f'){
                printf("Ingrese el caracter correctamente.\n\n");
            }
        }while(A[i].sexo != 'M' && A[i].sexo != 'm' && A[i].sexo != 'F' && A[i].sexo != 'f');
        int error=0;
        do{
            error++;
            printf("Ingrese Las Horas trabajadas:\n");
            scanf("%i", &A[i].horas);
            fflush(stdin);
            if(A[i].horas <= 0 && A[i].horas > 50){
                printf("Las horas deben ser > a 0 y <= a 50\n\n");
            }
            if(error>3){
                printf("Cerrando programa...");
                exit(1);
            }
        }while(A[i].horas <= 0 || A[i].horas > 50);
        error=0;
        do{
            error++;
            printf("Ingrese el sueldo por hora:\n$");
            scanf("%f", &A[i].sueldoPorHora);
            fflush(stdin);
            if(A[i].sueldoPorHora < 250.50){
                printf("El sueldo debe ser > $250.50\n");
            }
            if(error>3){
                printf("Cerrando programa...");
                exit(1);
            }
        }while(A[i].sueldoPorHora< 250.50);
    }

    struct empleados aux[DIM];
    //Ordeno por nombre
    for (i = 0; i < EMPLEADOS; i++) {
        for (j = 0; j < EMPLEADOS-i-1; j++) {
            if (strcmp(A[i].nombre, A[i+1].nombre)>0) {
                // Intercambiamos los elementos en las posiciones j y j+1
                aux[j] = A[j];
                A[j] = A[j+1];
                A[j+1] = aux[j];
            }
        }
    }

    for (i = 0; i < EMPLEADOS; i++){
        sueldo[i]= A[i].sueldoPorHora * A[i].horas;
    }

    for (i = 0; i < EMPLEADOS; i++){
        printf("Sueldo de %s: %.2f$\n", A[i].nombre, sueldo[i]);
    }

    return;
}

void funcionMenu(struct empleados A[]){
    char opcion='\0';

    while(opcion!='E' && opcion!='e'){
        printf("\n\nIngrese La opcion que desee:\n");
        printf("A: Carga de los datos de los empleados\n");// Carga de struct
        printf("B: Total de pagos por cada sexo\n");//  El total de pagos para cada sexo y 
        printf("C: Sueldo en promedio de hombres y mujeres\n");// el sueldo promedio de hombres y de mujeres.
        printf("D: Busqueda binaria de los datos mediante el nombre\n");//  Búsqueda binaria de los datos de un empleado mediante el nombre. 
        printf("E: Cerrar programa\n");
        scanf("%c", &opcion);
        fflush(stdin);
        switch(opcion){
            case 'A':
            case 'a':   funcionCarga(A);
                break;
            case 'B':
            case 'b':   funcionPagos(A);
                break;
            case 'C':   
            case 'c':   funcionPromedio(A);
                break;
            case 'D':
            case 'd':   char nombreE[DIM];
                        int indice = funcionBusquedaBinaria(A, nombreE);
                        if (indice != -1) {
                            printf("El nombre '%s' se encuentra en la posicion %d.\n", nombreE, indice);
                        } else {
                            printf("El nombre '%s' no se encuentra\n", nombreE);
                        }
                break;
            case 'E':
            case 'e':   printf("Cerrando programa...  ");
                break;
        }
    }
}

int main(){
    struct empleados A[EMPLEADOS];

    printf("Programa empleados:\n");
    funcionMenu(A);
    getchar();

    return 0;
}