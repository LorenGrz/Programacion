#include <stdio.h>
#include <string.h>
//-----DEFINE-----//
#define n 3
#define tiemposAnteriores 4
//-----STRUCTS-----//
struct nadadores
{
    int id;
    char apellido[15];
    float mejorTiempo;
};

//-----FUNCIONES-----//
void cargaDatos(struct nadadores *nadador);
void cargaTiempo(struct nadadores *nadador, float *tiempoActual);
float buscarMejorTiempo(float tiemposAnt[][tiemposAnteriores], int i);
void supera(struct nadadores *nadador, int *vecPos, float tiempo, int *cantidad);
void emitirMejoresTiempos(struct nadadores *nadador, int *vecPos, int cantidad);
void ordenar(struct nadadores *nadador);

int main()
{
    //DECLARACION DE VARIALBES
    struct nadadores nadador[n];
    float tiempoActual[n];
    int vecPos[n], cantNadadoresSup=0;

    //MATRIZ CON DATOS ANTERIORES
    float tiemposAnt[n][tiemposAnteriores] = {
       {240, 292, 214, 292},
       {250, 174, 160, 224},
       {289, 261, 184, 280}
    };

    //Carga de datos de los nadadores
    cargaDatos(nadador);
    cargaTiempo(nadador, tiempoActual);
    //Cargar menor tiempo
    for (int i = 0; i < n; i++)
    {
        nadador[i].mejorTiempo = buscarMejorTiempo(tiemposAnt, i);
    }
    //Buscamos a los nadadores que superen el tiempo pasado como parametro
    supera(nadador, vecPos, 200, &cantNadadoresSup);

    //ORDENAMOS A LOS NADADORES ALFABETICAMENTE ANTES DE IMPRIMIRLOS
    ordenar(nadador);

    //PRINT TEST
    printf("\nNADADORES:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Apellido: %s\n", nadador[i].apellido);
        printf("ID: %d\n", nadador[i].id);
        printf("Mejor tiempo:%.2f\n", nadador[i].mejorTiempo);
        printf("\n");
    }
    printf("Cantidad de nadadores que superaron el tiempo establecido: %d\n", cantNadadoresSup);
    //Imprimimos los mejores tiemops
    emitirMejoresTiempos(nadador, vecPos, cantNadadoresSup);
    
    return 0;
}

//--DESARROLLO DE FUNCIONES--//
void cargaDatos(struct nadadores *nadador)
{
    for (int i = 0; i < n; i++)
    {
        nadador[i].id = i+1;
        printf("Ingrese el apellido del nadador:\n");
        gets(nadador[i].apellido);
        fflush(stdin);
        nadador[i].mejorTiempo = -1;
    }
    return;
}

void cargaTiempo(struct nadadores *nadador, float *tiempoActual)
{
    for (int i = 0; i < n; i++)
    {
        printf("Ingrese el tiempo de %s:\n", nadador[i].apellido);
        scanf("%f", &tiempoActual[i]);
    }
    return;
}

float buscarMejorTiempo(float tiemposAnt[][tiemposAnteriores], int i)
{
    //Se inicializa el mejor tiempo como el primer tiempo del nadador
    int mejorTiempo = tiemposAnt[i][0];
    //Se busca si hay un tiempo menor
    for (int j = 1; j < 4; j++)
    {
        if (tiemposAnt[i][j] < mejorTiempo)
        {
            mejorTiempo = tiemposAnt[i][j];
        }
    }
    return mejorTiempo;
}

void supera(struct nadadores *nadador, int *vecPos, float tiempo, int *cantidad)
{
    //Inicializamos las variables
    for(int i=0; i < n; i++){vecPos[i]=-1;}

    //Filtramos por nadadores que superen el tiempo
    for (int i = 0; i < n; i++)
    {
        if (nadador[i].mejorTiempo < tiempo)
        {
            vecPos[i] = i;
            (*cantidad)++;
        }
    }
    return;
}

void emitirMejoresTiempos(struct nadadores *nadador, int *vecPos, int cantidad)
{
    int aux[cantidad], j=0;
    for(int i = 0; i < n; i++)
    {
        if (vecPos[i] != -1)
        {
            aux[j] = vecPos[i];
            j++;
        }
    }

    printf("Nadadores con mejores tiempos!\n");
    for (int i = 0; i < cantidad; i++)
    {
        printf("%s, ", nadador[aux[i]].apellido);
    }
    return;
}

void ordenar(struct nadadores *nadador)
{
    struct nadadores aux;

    for (int i = 0; i < n-1; i++)
    {
        if (strcmp(nadador[i].apellido, nadador[i+1].apellido) > 0)
        {
            aux = nadador[i+1];
            nadador[i+1] = nadador[i];
            nadador[i] = aux;
        }
    }
    return;   
}