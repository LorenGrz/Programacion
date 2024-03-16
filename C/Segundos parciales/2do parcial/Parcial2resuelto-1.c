#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define FIL 4
#define COL 6

struct competidores{
  int id;
  char provincia[30];
  float tiempo[10];
  float promtiempo;
  float max_prom;
};

struct instructores{
    int id;
    char nombre_competidor[30];
    char instructor[30];
};

//carga en forma aleatoria los 30 tiempos de cada competidor del struct
void carga_tiempos(struct competidores a[]){
    int i,j;
    for (i=0;i<FIL ;i++ ){
        for (j=0;j<10;j++ )
        {
            a[i].tiempo[j]=rand()%180;
        }
    }
}

void muestra(struct competidores a[],struct instructores b[], int vauxiliar[],float promensual[][COL]){
    int i,j;
///emite struct competidores
    printf("Competidores:\n");
    printf("-------------\n");
    for (i=0;i<FIL ;i++ )
    {
        printf("\nID competidor: %d\n",a[i].id);
        printf("Provincia: %s\n",a[i].provincia);
        printf("\nTiempos:\n");

        for (j=0;j<10;j++ ){
            printf ("%.2f - ",a[i].tiempo[j]);
        }
        printf("\n");
        printf("\nPromedio de tiempos del mes: %.2f\n",a[i].promtiempo);
        printf("M�ximo promedio: %.2f\n",a[i].max_prom);
        printf("\n______________________________\n");
    }

///emite struct instructores
    printf("Instructores:\n");
    printf("------------\n");
    for (i=0;i<FIL ;i++ )
    {
        printf("\nID competidor: %d\n",b[i].id);
        printf("Nombre del competidor: %s\n",b[i].nombre_competidor);
        printf ("Nombre del instructor: %s\n",b[i].instructor);
        printf("\n______________________________\n");
    }

///emite array auxiliar de -1
    printf("Vector auxiliar:\n");
    printf("-----------------\n");
    for (i=0;i<FIL ;i++ )
    {
        printf("%d ; ",vauxiliar[i]);
    }
        printf("\n \n");

///emite la matriz de tiempos
    printf("Promedios Mensuales:\n");
    printf("\n____________________\n");
    for (i=0;i<FIL;i++){
        for(j=0;j<COL;j++){
            printf("%.2f - ",promensual[i][j]);
        }
        printf("\n");
    }
        printf("\n______________________________\n");
}

// punto 5.Funci�n que reciba  el vector de competidores y
//cargue en el campo �Promedio_de_tiempos_del_mes�, el promedio del array �Tiempos�
void promedio_mes(struct competidores a[]){
    int i,j;
    float sum;

    for (i=0;i<FIL;i++){
        sum=0;
        for (j=0;j<10;j++){
            sum+=a[i].tiempo[j];
        }
        a[i].promtiempo=sum/10;
    }
}

// punto 6.Funci�n que reciba  el vector de competidores, la matriz de tiempos mensuales y cargue en el campo
//�maximo_promedio�, el m�ximo promedio de los tiempos de los meses procesados.
void maximo_promedio(struct competidores a[],float promensual[][COL]){
    int i,j;
    float max;

    for (i=0;i<FIL;i++){
        max=-9999;
        for(j=0;j<COL;j++){
            if (promensual[i][j]>max){
                max = promensual[i][j];
            }
        }
        a[i].max_prom=max;
    }
}
// punto 7.Funci�n que reciba  el vector de competidores, el vector de enteros y cargue en este vector,
//las posiciones de los registros del vector de competidores,  cuyo  �Promedio_de_tiempos_del_mes�,
//no supere al �Promedio_General� . Los datos deben almacenarse en forma
int no_supera(struct competidores a[],int vauxiliar[]){
    int i,j=0;
    for (i=0;i<FIL;i++ ) {
        if (a[i].promtiempo<a[i].max_prom) {
            vauxiliar[j]=i;
            j++;
        }
    }
    return j;
}

// punto 8.Funci�n que reciba  el vector de competidores, vector de instructores, vector de posiciones
//y la cantidad retornada en la funci�n anterior y emita el campo �Provincia� de las competidores
//obtenidos en la funci�n anterior y el campo �Nombre_del instructor�
void emitir_provincia(struct competidores a[],struct instructores b[],int vauxiliar[],int cant){
    int i, j;
    printf("Las provincias donde el promedio de tiempos del mes no supero a el promedio general fueron:\n");
        for(i=0;i<cant;i++){
            for (j = 0; j < FIL; j++)
            if (a[vauxiliar[i]].id == b[j].id)
            printf("%s  - cuyo instructor fue:%s y su competidor fue %s\n",a[vauxiliar[i]].provincia,b[vauxiliar[i]].instructor, b[vauxiliar[i]].nombre_competidor);
        }
}

// punto 9.Funci�n que reciba el vector de competidores y lo ordene por provincia en forma ascendente.
void ordenar(struct competidores a[]){
    int i,j,flag;
    struct competidores aux;

    for (i=0;i<FIL-1;i++) {
        flag = 0;
        for (j = 0; j < FIL-(i+1); j++)    {
            if (strcmp(a[j].provincia,a[j+1].provincia)>0) {
                aux = a[j];
                a[j] = a[j+1];
                a[j+1] = aux;
                flag = 1;
            }
        }
    }
}

//punto 4. Por otra parte, se almacenan en una array bidimensional de N filas por M columnas,
//los promedios mensuales -obtenidos con anterioridad- por competidor
void carga_matriz(float promensual[][COL]){
    int i,j;
    for (i=0;i<FIL;i++){
        for(j=0;j<COL;j++){
            promensual[i][j]=rand()%100;
          }
    }
}

int main()
{   // carga del array de struct de competidores punto 1 de la consigna
    struct competidores a[FIL]={{1,"Santa Cruz",0,0,0},{2,"Entre Rios",0,0,0},{3,"Buenos Aires",0,0,0},{4,"Corrientes",0,0,0}};
    // carga del array de struct de instructores punto 2 de la consigna
    struct instructores b[FIL]={{1,"Juan","Martin"},{2,"Pedro","Pablo"},{3,"Maria","Magdalena"},{4,"Diego","Armando"}};
    // carga del array con -1 punto 3 de la consigna
    int vauxiliar[FIL]={-1,-1,-1,-1},cant;
    // declaracion de la matriz de tiempos
    float promensual[FIL][COL];
    srand(time(NULL));

//emite todo los datos cargados antes de empezar el proceso
    muestra(a,b,vauxiliar,promensual);
    getchar();

//cargamos en forma aleatoria los 10 tiempos de cada competidor del struct
    carga_tiempos(a);

//punto 4.Por otra parte, se almacenan en una array bidimensional de N filas por M columnas,
//los promedios mensuales -obtenidos con anterioridad- por competidor
    carga_matriz(promensual);
//emite todo los datos cargados
    muestra(a,b,vauxiliar,promensual);
    getchar();

//punto 5.Funci�n que reciba  el vector de competidores y cargue en el campo �promedio_de_tiempos_del_mes�,
//el promedio del campo del struct de 10 tiempos.

    printf("**Punto 5**\n");

    promedio_mes(a);
    muestra(a,b,vauxiliar,promensual);
    getchar();

// punto 6.Funci�n que reciba  el vector de competidores, la matriz de tiempos mensuales y cargue en el campo
//�maximo_promedio�, el m�ximo promedio de los tiempos de los meses procesados.

    printf("**Punto 6**\n");

    maximo_promedio(a,promensual);
    muestra(a,b,vauxiliar,promensual);
    getchar();

// punto 7.Funci�n que reciba  el vector de competidores, el vector de enteros y cargue en este vector,
//las posiciones de los registros del vector de competidores,  cuyo  �Promedio_de_tiempos_del_mes�,
//no supere al �Promedio_General� . Los datos deben almacenarse en forma

    printf("**Punto 7**\n");

    cant=no_supera(a,vauxiliar);
    getchar();

// punto 8.Funci�n que reciba  el vector de competidores, vector de instructores, vector de posiciones
//y la cantidad retornada en la funci�n anterior y emita el campo �Provincia� de las competidores
//obtenidos en la funci�n anterior y el campo �Nombre_del instructor�

    printf("**Punto 8**\n");

    emitir_provincia(a,b,vauxiliar,cant);
    getchar();

// punto 9.Funci�n que reciba el vector de competidores y lo ordene por provincia en forma ascendente.

    printf("**Punto 9*\n");

    ordenar(a);
    muestra(a,b,vauxiliar,promensual);
    getchar();

    return 0;
}