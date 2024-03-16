#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define CANT_EQUIPOS 4
#define CANT_MESES 6
#define CANT_TIEMPOS 10
#define LARGO_STR 30

// DECLARACION DE ESTRUCTURAS
typedef struct competidores
{
    int idCompetidor;
    char provincia[LARGO_STR];
    float tiempos[CANT_TIEMPOS];
    float promMes;
    float promMax;
} competidores;

typedef struct instructores
{
    int idInstructor;
    char nombreCompetidor[LARGO_STR];
    char nombreInstructor[LARGO_STR];
} instructores;

// PROTOTIPOS
void cargaCompetidores(competidores competidor[], instructores instructor[]);
void inicializaciones(competidores competidor[], int arrControl[], float promediosGenerales[][CANT_MESES]);
void promedioMensual(competidores competidor[]); // EJERCICIO 5
void promediosMensualesDestacados(competidores competidor[], float promediosGenerales[][CANT_MESES]); // EJERICIO 6
int promediosMensualesBajos(competidores competidor[], int arrControl[]); // EJERCICIO 7
void emitirEquipos(competidores competidor[], instructores instructor[], int arrControl[], int cont); // EJERCICIO 8
void ordenarProvincias(competidores competidor[]); // EJERCICIO 9
void muetra(competidores competidor[], instructores instructor[], int arrControl[], float promediosGenerales[][CANT_MESES]); // Testeo

// MAIN
int main()
{
    competidores competidor[CANT_EQUIPOS];
    instructores instructor[CANT_EQUIPOS];
    int arrControl[CANT_EQUIPOS];
    float promediosGenerales[CANT_EQUIPOS][CANT_MESES];

    cargaCompetidores(competidor, instructor);
    inicializaciones(competidor, arrControl, promediosGenerales); // REVISAR "promedios[][M]"
    promedioMensual(competidor); // EJERCICIO 5
    promediosMensualesDestacados(competidor, promediosGenerales); // EJERICIO 6
    int cont = promediosMensualesBajos(competidor, arrControl); // EJERCICIO 7
    emitirEquipos(competidor, instructor, arrControl, cont); // EJERCICIO 8
    ordenarProvincias(competidor); // EJERCICIO 9
    muetra(competidor,instructor,arrControl,promediosGenerales);
    getchar();
    return 0;
}

// CARGA DE COMPETIDORES
void cargaCompetidores(competidores competidor[], instructores instructor[])
{
    srand(time(NULL));
    int i, j;
    for(i = 0; i < CANT_EQUIPOS; i++)
    {
        printf("COMPETIDOR %d\n", i+1);
        printf("\tID: ");
//       scanf("%d", &competidor[i].idCompetidor);
        competidor[i].idCompetidor=i+1;
//        fflush(stdin);
        instructor[i].idInstructor = competidor[i].idCompetidor;
        printf("\tProvincia: ");
        gets(competidor[i].provincia);
        fflush(stdin);
        printf("\tNombre competidor: ");
        gets(instructor[i].nombreCompetidor);
        fflush(stdin);
        printf("\tNombre instructor: ");
        gets(instructor[i].nombreInstructor);
        fflush(stdin);
        for(j = 0; j < CANT_TIEMPOS; j++)
        {
            // LLENADO AUTOMATICO
            competidor[i].tiempos[j] = 10 + rand() % 40;
            // LLENADO MANUAL
            // printf("\tTiempo %d: ", j+1);
            // scanf("%f", &competidor[i].tiempos[j]);
            // fflush(stdin);
        }
        system("cls");
    }
};

// INICIALIZACIONES
void inicializaciones(competidores competidor[], int arrControl[], float promediosGenerales[][CANT_MESES])
{
    srand(time(NULL));
    int i, j;
    for(i = 0; i < CANT_EQUIPOS; i++)
    {
        competidor[i].promMes = 0; // PUNTO 1
        competidor[i].promMax = 0; // PUNTO 1
        arrControl[i] = -1; // PUNTO 3
        for(j = 0; j < CANT_MESES; j++)
            promediosGenerales[i][j] = 100 + rand() % 400; // PUNTO 4
    }
};

// EJERICIO 5
void promedioMensual(competidores competidor[])
{
    int i, j;
    float acum = 0;
    for(i = 0; i < CANT_EQUIPOS; i++)
    {
        acum=0; //faltaba reiniciar el acum
        for(j = 0; j < CANT_TIEMPOS; j++)
        {
            acum += competidor[i].tiempos[j];
        }
        competidor[i].promMes = acum / CANT_TIEMPOS;
    }
};

// EJERICIO 6
void promediosMensualesDestacados(competidores competidor[], float promediosGenerales[][CANT_MESES])
{
    int i, j;
    float max=-1;
    for(i = 0; i < CANT_EQUIPOS; i++)
    {//faltaban estas llaves, Ojo
        max = -1;// falto reiniciarlo, es diferente para cada competidor. Ojo Ojo
        for(j = 0; j < CANT_MESES; j++)
        {
            if(promediosGenerales[i][j] > max)
            {
                max = promediosGenerales[i][j]; //Ojo Ojo Ojo, falto actualizar el maximo
                competidor[i].promMax = max;
            }
        }
    }
};

// EJERCICIO 7
int promediosMensualesBajos(competidores competidor[], int arrControl[])
{
    int cont = 0, i;
    for(i = 0; i < CANT_EQUIPOS; i++)
        if(competidor[i].promMax > competidor[i].promMes)
        {
            arrControl[cont] = i;
            cont++;
        }
    return cont;
};

// EJERCICIO 8
void emitirEquipos(competidores competidor[], instructores instructor[], int arrControl[], int cont)
{
    int i;
    printf("Equipos que no batieron su record pesonal\n");
    for(i = 0; i < cont; i++)
    {
        printf("\n\tEQUIPO %d\n", arrControl[i]+1);
        printf("\t\tProvincia: %s\n", competidor[arrControl[i]].provincia);
        printf("\t\tInstructor: %s\n", instructor[arrControl[i]].nombreInstructor);
        printf("\t\tCompetidor: %s\n", instructor[arrControl[i]].nombreCompetidor);
    }
    getchar();
    system("cls");
};

// EJERCICIO 9
void ordenarProvincias(competidores competidor[])
{
    int i, j;
    competidores aux;
    for(i = 0; i < (CANT_EQUIPOS - 1); i++)
        for(j = 0; j < (CANT_EQUIPOS - (i+1)); j++)
            if (strcmp(competidor[j].provincia, competidor[j+1].provincia) > 0)
            {
                aux = competidor[j];
                competidor[j] = competidor[j+1];
                competidor[j+1] = aux;
            }
};

//Testeo
void muetra(competidores competidor[], instructores instructor[], int arrControl[], float promediosGenerales[][CANT_MESES])
{
    int i,j;
///Sucursal
    printf("---------Equipos---------\n");
    for(i=0; i<CANT_EQUIPOS; i++)
    {
        printf("___________________________\n");
        printf("Competidor: %d \n",i+1);
        printf("Id: %d\n",competidor[i].idCompetidor);
        printf("\t Ciudad: %s \n", competidor[i].provincia);
        printf("\t Valores Tiempos\n",161);
        for(j=0; j<2; j++)
        {
            printf("\t \t %.2f %.2f %.2f %.2f %.2f \n",competidor[i].tiempos[j],competidor[i].tiempos[j+1], competidor[i].tiempos[j+2], competidor[i].tiempos[j+3], competidor[i].tiempos[j+4]);
        }
        printf("\n");
        printf("\t Promedio Mes: %.2f \n",competidor[i].promMes);
        printf("\t Maximo promedio %.2f \n",competidor[i].promMax);
    }
    printf("______________________________________________\n \n");
///Gerencia
    printf("---------Instructores--------- \n");
    for(i=0; i<CANT_EQUIPOS; i++)
    {
        printf("___________________________\n ");
        printf("Valores del Instructor %d \n",i+1);
        printf("Id: %d\n",instructor[i].idInstructor);
        printf("\t Instructor: %s \n", instructor[i].nombreInstructor);
        printf("\t Competidor: %s \n", instructor[i].nombreCompetidor);
    }
    printf("______________________________________________\n \n");
///ArrayAux
    printf("---------Array Control--------- \n");
    for(i=0; i<CANT_EQUIPOS; i++)
    {
        printf(" %d", arrControl[i]);
    }
    printf("\n______________________________________________\n \n");
///Array bi dimensional
    printf("---------Matriz Bidimensional--------- \n");
    for(i=0; i<CANT_EQUIPOS; i++)
    {
        for(j=0; j<CANT_MESES; j++)
        {
            printf(" %.2f",promediosGenerales[i][j]);
        }
        printf(" \n");
    }
    printf("______________________________________________\n");
};


