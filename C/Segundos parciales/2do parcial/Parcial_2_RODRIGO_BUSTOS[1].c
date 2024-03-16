#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define FIL 6
#define COL 4

struct sucursales{
    int id;
    char provincia[30];
    float facturacion_diaria_del_mes_actual[30];
    float total_de_facturacion_del_mes_actual;
    float promedio_de_facturacion;
};

struct CEOS{
    int id_CEO;
    int id;
    char apellido[30];
};

void carga_tiempo(struct sucursales a[]);
void matriz(struct sucursales a[],float promensual[][COL]);
int superar(struct sucursales a[],int vauxiliar[]);
void emite_provincia(struct sucursales a[],struct CEOS b[], int vauxiliar[]);
void cargas(struct sucursales a[],struct CEOS b[]);


int main()
{

    struct sucursales a[FIL]={{1,"Salta",0,0,0},{2,"Tucuman",0,0,0},{3,"Mendoza",0,0,0},{4,"Chaco",0,0,0},{5,"Formosa",0,0,0},{6,"Jujuy",0,0,0}};

    struct CEOS b[FIL]={{999,1,"Perez"},{998,2,"Bustos"},{997,3,"Saenz"},{996,4,"Silvestri"},{995,5,"Salazar"},{994,6,"Felker"}};

    int vauxiliar[FIL]={-1,-1,-1,-1,-1,-1};
    float promensual[FIL][COL];

    srand(time(NULL));
    cargas(a,b);

    printf("***Punto 5***\n");
    carga_tiempo(a);

    printf("\n***Punto 6***\n");
    matriz(a,promensual);

    printf("\n***Punto 7 y 8***\n");
    emite_provincia(a,b,vauxiliar);

}

void carga_tiempo(struct sucursales a[])
{
    int i,j;
    float suma;
    
    for(i=0;i<FIL;i++){
        for(j=0;j<30;j++){
            a[i].facturacion_diaria_del_mes_actual[j]=rand()%15;
        }
    }


    for(i=0;i<FIL;i++){
        suma=0;

        for(j=0;j<30;j++){
            suma+=a[i].facturacion_diaria_del_mes_actual[j];
        }
        a[i].total_de_facturacion_del_mes_actual=suma;
    }

    for(i=0;i<FIL;i++){
        printf("\nSuc_%i\n",i+1);
        printf("Facturacion diaria: ");

        for(j=0;j<30;j++){
            printf("%.2f_",a[i].facturacion_diaria_del_mes_actual[j]);
        }
        printf("\nLA FACTURACION TOTAL ES: %.2f\n",a[i].total_de_facturacion_del_mes_actual);
    }
}

void matriz(struct sucursales a[],float promensual[][COL]){
    int i,j;
    float prom;
    for(i=0;i<FIL;i++)
    {
        for(j=0;j<COL;j++)
        {
            promensual[i][j]=rand()%400;
        }
    }

    for(i=0;i<FIL;i++)
    {
        printf("Suc_%i ",i+1);
        for(j=0;j<COL;j++)
        {
            printf("%10.2f |",promensual[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(i=0;i<FIL;i++)
    {
            prom=0;
        for(j=0;j<COL;j++)
        {
            prom+=promensual[i][j];
        }
        a[i].promedio_de_facturacion=prom/4;
        printf("El promedio de facturacion del mes %i es: %.2f\n",i+1,a[i].promedio_de_facturacion);
    }
}

int superar(struct sucursales a[],int vauxiliar[]){
int i,j=0;

for(i=0;i<FIL;i++)
{
    if(a[i].total_de_facturacion_del_mes_actual>a[i].promedio_de_facturacion)
    {
        vauxiliar[j]=i;
        j++;
    }
}
return j;
}

void emite_provincia(struct sucursales a[],struct CEOS b[], int vauxiliar[])
{
    superar(a,vauxiliar);
    int i,j;

    printf("Las provincias que el total de facturacion del mes superaron al promedio del mes son: \n");
    for(i=0;i<6;i++)
    {
        for(j=0;j<FIL;j++)
        {
            if(a[vauxiliar[i]].id==b[j].id){
            printf("%s - CEO:%s\n",a[vauxiliar[i]].provincia,b[vauxiliar[i]].apellido);
            }
        }
    }
}

void cargas(struct sucursales a[],struct CEOS b[])
{

    int i;

    for(i=0;i<FIL;i++)
    {
        printf("Sucursal %i\n",i+1);
        printf("Provincia: %s\n",a[i].provincia);
        printf("ID de sucursal: %i\n",a[i].id);
        printf("ID CEO: %i\n\n",b[i].id_CEO);
    }

}