// Escribe un programa, con un menú de opciones, que permita calificar a un grupo de diez alumnos de la escuela secundaria. En 
// un array de struct, se ingresa para cada alumno: 
// a. Apellido  
// b. Nombre 
// c. Campo array de cadena inicialmente vacío  
// d. 5 calificaciones de cada alumno, (array de 5 elementos) 
// e. Campo float, para el promedio, inicialmente vacío. 
// f. Campo float, para la mayor nota, inicialmente vacío. 
// El programa debe: 
// a Permitir concatenar nombre y apellido y registrarlo en el campo correspondiente inicialmente vacío. 
// b Permitir calcular la media (promedio) de cada alumno y guardarla en el campo que inicialmente estará vacío hasta 
// que se calcule el dato y se registre. 
// c Permitir buscar la nota mayor de cada alumno y guardarla en el campo que inicialmente estará vacío hasta que se 
// realice el proceso de búsqueda y registro del dato.  
//  Posteriormente debe informar: 
// -. el promedio de cada alumno y nota máxima, emitir si está aprobado o no. Para aprobar se requiere un 
// promedio de 6 o más y haber obtenido al menos 6 en la última de las 5 calificaciones.  
// -. informar cuántos alumnos aprobaron y cuántos obtuvieron un promedio de al menos 8 puntos. 
// - Permitir la búsqueda (binaria) por Apellido de un alumno y emitir todos sus datos. 
// - Emitir el listado ordenado por nombre y apellido, con sus notas, promedio y nota máxima en forma encolumnada. 
// -.El programa debe emitir todos los mensajes necesarios para que el usuario opere en forma eficaz, 
// validar las notas ( >=0 y <=10), convertir el apellido de cada alumno a Mayúsculas (ver ejemplo empleo de toupper.c) 
// antes de guardarlo en el array  y controlar al menos 3 errores (ver ejemplo control de errores con cadenas.c). 
// -.Las búsquedas por nombre y/o apellido deben considerar que el usuario puede ingresar esos datos en minúsculas 
// por lo tanto hay que convertir la cadena antes de realizar el proceso.
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define DIM 40
#define ALUMNOS 2

struct alumnos{
    char apellido[DIM];
    char nombre[DIM];
    char arrayConcatenado[DIM];
    float notas[5];
    float promedios;
    float mayorNota;
};

void funcionImpresion(struct alumnos Arr[]){
    int i, j, contAprobados=0, contDesaprobados=0;
    for(i=0;i<ALUMNOS;i++){
        printf("%s:\n Notas: ", Arr[i].arrayConcatenado);
        for(j=0;j<5;j++){
            printf("|%.2f| ", Arr[i].notas[j]);
        }
        printf("\n");
        printf("Promedio: %.2f\n", Arr[i].promedios);
        printf("Mayor Nota: %.2f\n", Arr[i].mayorNota);
    }

    for(i=0;i<ALUMNOS;i++){
        if(Arr[i].promedios>5 && Arr[i].notas[5]>5){
            contAprobados++;
        }else{
            contDesaprobados++;
        }
    }

    printf("La cantidad de alumnos Aprobados es: %i\n", contAprobados);
    printf("La cantidad de alumnos Desaprobados es: %i\n", contDesaprobados);
    return;
}

int funcionBusquedaBinaria(struct alumnos Arr[], char apellidoBusqueda[]){
    int inicio=0;
    int fin=ALUMNOS;
    int condicion, i, mitad;

    printf("Ingrese el apellido del alumno a buscar:\n");
    gets(apellidoBusqueda);
    fflush(stdin);

    int longitud = (strlen(apellidoBusqueda));
    apellidoBusqueda[longitud]='\0';

    for(i=0; i<longitud; i++){
        apellidoBusqueda[i] = (toupper(apellidoBusqueda[i]));
    }

    while (inicio <= fin){
        mitad = inicio + ((fin - inicio) / 2);
        condicion = (strcmp(Arr[mitad].apellido, apellidoBusqueda));
        if (condicion == 0) {
            return mitad;
        } else if (condicion < 0) {
            inicio = mitad + 1;
            } else {
                fin = mitad - 1;
            }
    }

    return -1;
}

void funcionBusquedaMayor(struct alumnos Arr[]){
    int i, j; 
    for(i=0;i<ALUMNOS;i++){
        Arr[i].mayorNota=-999;
        for(j=0;j<5;j++){
            if(Arr[i].notas[j]>Arr[i].mayorNota){
                Arr[i].mayorNota = Arr[i].notas[j];
            }
        }
    }
    printf("Mayor nota Ingresada\n");
    
    return;
}

void funcionPromedio(struct alumnos Arr[]){
    int i, j;
    float acumNotas;
    for(i=0; i<ALUMNOS; i++){
        acumNotas=0;
        for(j=0; j<5; j++){
            acumNotas += Arr[i].notas[j];
        }
        Arr[i].promedios = (acumNotas / 5);
    }
    printf("Promedios Ingresados\n");
    
    return;
}

void funcionConcatenar(struct alumnos Arr[]){
    int i;

    for(i=0; i<ALUMNOS; i++){
        strcat(strcat((strcpy(Arr[i].arrayConcatenado, Arr[i].nombre))," "), Arr[i].apellido);
    }
    printf("Arreglo Ingresado\n");

    return;
}

void funcionCargaAlumnos(struct alumnos Arr[]){
    int i, j;
    for(i=0; i<ALUMNOS; i++){
        printf("Ingrese el nombre del alumno N %i\n", i+1);
        gets(Arr[i].nombre);
        fflush(stdin);

        printf("Ingrese el apellido del alumno N %i\n", i+1);
        gets(Arr[i].apellido);
        fflush(stdin);

        int longAp = strlen(Arr[i].apellido);
        Arr[i].apellido[longAp]='\0';

        for(j=0;j<longAp;j++){
            Arr[i].apellido[j]=toupper(Arr[i].apellido[j]);
        }

        printf("Ingrese 5 calificaciones:\n");
        for(j=0; j<5; j++){//( >=0 y <=10)
            do{
                printf("Nota N %i:\n", j+1);
                scanf("%f", &Arr[i].notas[j]);
                fflush(stdin);
                if(Arr[i].notas[j]<0 || Arr[i].notas[j] > 10){
                    printf("Ingrese la nota correctamente");
                }
            }while(Arr[i].notas[j]<0 || Arr[i].notas[j] > 10);
        }   
    }
    
    struct alumnos aux[DIM];
    
    for (i = 0; i < ALUMNOS; i++) {
        for (j = 0; j < ALUMNOS-i-1; j++) {
            if (strcmp(Arr[j].apellido, Arr[j+1].apellido)>0){
                // Intercambiamos los elementos en las posiciones j y j+1
                aux[j] = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = aux[j];
            }
        }
    }

    return;
}

void funcionMenu(struct alumnos Arr[]){
    char apellidoBusqueda[DIM];
    char opcion = '\0';
    printf("Ingrese un caracter para usar el menu:\n");
    while(opcion != 'g' && opcion != 'G'){
        printf("\nA: Cargar los datos de los alumnos.\n");
        printf("B: Concatenar nombre y apellido y alojarolo en el arreglo vacio.\n");
        printf("C: Calcular promedio de cada alumno. \n");//guardarlo en el arreglo 
        printf("D: Permitir buscar la nota mayor de cada alumno.\n");
        printf("E: Busqueda binaria por apellido de alumno e imprimir los datos.\n");
        printf("F: Emitir el listado ordenado por nombre y apellido.\n");
        printf("G: Cerrar el programa.\n");
        scanf("%c", &opcion);
        fflush(stdin);
        switch(opcion){
            case 'A':
            case 'a':   funcionCargaAlumnos(Arr);
                break;
            case 'B':
            case 'b':   funcionConcatenar(Arr);//strcat(strcat((strcopy(Arr[i].arrayConcatenado, Arr[i].nombre)),' '), Arr[i].apellido);
                break;
            case 'C':
            case 'c':   funcionPromedio(Arr);
                break;
            case 'D':
            case 'd':   funcionBusquedaMayor(Arr);
                break;
            case 'E':
            case 'e':   int posicion = funcionBusquedaBinaria(Arr, apellidoBusqueda);
                        if(posicion!=-1){
                            printf("El apellido %s se encuentra en la posicion %i.\n", apellidoBusqueda, posicion);
                            printf("Sus datos son:\n");
                            printf("Nombre y apellido: %s\n", Arr[posicion].arrayConcatenado);
                            printf("Promedio: %.2f\n", Arr[posicion].promedios);
                            printf("Mayor nota: %.2f\n", Arr[posicion].mayorNota);
                        }else{
                            printf("No se a encontrado el apellido\n");
                        }
                break;
            case 'F':
            case 'f':   funcionImpresion(Arr);
                break;
            case 'G':
            case 'g':   printf("Cerrando programa...");
                break;
        }
    }

    return;
}

int main(){
    struct alumnos Arr[ALUMNOS];
    printf("Programa para notas de alumnos: \n\n");
    funcionMenu(Arr);

    return 0;
}