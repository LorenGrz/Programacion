#include <stdio.h>
#include <string.h>
//-----DEFINES-----//
#define n 4
#define m 6
#define descuentos 30

//-----STRUCT-----//
struct sucursal
{
    int id;
    char ciudad[30];
    float desc[descuentos], descMes, promDesc;
};

struct gerente
{
    int id;
    char nombre[30];
};

//-----FUNCIONES-----//
void cargaDatos(struct sucursal *sucursales, struct gerente *gerentes);
void cargaDesc(struct sucursal *sucursales);
void calculoDesc(struct sucursal *sucursales, float descSuc[][m]);
int almacenarDescMax(struct sucursal *sucursales, int *arr);
void ciudadGerente(struct sucursal *sucursales, struct gerente *gerentes, int *arr, int cantidad);
void ordenar(struct sucursal *sucursales);

int main()
{
    struct sucursal sucursales[n];
    struct gerente gerentes[n];

    //--SE INICIA EL ARRAY CON -1--//
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = -1;
    }

    //--ARRAY DE DESCUENTOS Y SUCURSALES--//
    float descuentosSucursales[n][m] = {
        {100, 150, 180, 210, 250, 230},
        {400, 200, 300, 250, 20, 150},
        {150, 200, 140 , 450, 150, 320},
        {180, 190, 320, 60, 180, 140},
    };

    //Se llenan los datos principales
    cargaDatos(sucursales, gerentes);
    //Se carga el descuento por dia
    cargaDesc(sucursales);
    //Se calcula el descuento promedio
    calculoDesc(sucursales, descuentosSucursales);
    //Se calcula cuales sucursales superaron el promedio anterior
    almacenarDescMax(sucursales, arr);
    //Se imprimen los datos de las sucursales que superaron el promedio anterior
    ciudadGerente(sucursales, gerentes, arr, almacenarDescMax(sucursales, arr));
    //Se ordena el array de sucursales
    ordenar(sucursales);
    
    
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", sucursales[i].ciudad);
    }
    return 0;
}

//-----LOGICA DE LAS FUNCIONES-----//
void cargaDatos(struct sucursal *sucursales, struct gerente *gerentes)
{
    //Se piden todos los datos de las sucursales
    for (int i = 0; i < n; i++)
    {
        printf("Ingrese el ID de la sucursal\n");
        scanf("%d", &sucursales[i].id);
        fflush(stdin);
        gerentes[i].id = sucursales[i].id;
        printf("Ingrese la ciudad de la sucursal:\n");
        gets(sucursales[i].ciudad);
        //Se ingresan los descuentos por dia
        for (int j = 0; j < descuentos; j++)
        {
            printf("Ingrese un descuento del dia  %d\n", j+1);
            scanf("%f", &sucursales[i].desc[j]);
            fflush(stdin);
        }
        printf("Ingrese el nombre del gerente\n");
        gets(gerentes[i].nombre);
    }
    
    return;
}

void cargaDesc(struct sucursal *sucursales)
{
    //Inicializamos el valor en 0
    for(int i=0;i<n;i++){sucursales[i].descMes=0;}

    //Se realiza la sumatoria
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < descuentos; j++)
        {
            sucursales[i].descMes += sucursales[i].desc[j];
        }
    }
    return;
}

void calculoDesc(struct sucursal *sucursales, float descSuc[][m])
{
    for (int i = 0; i < n; i++)
    {
        float totalDesc = 0;
        for (int j=0; j<m; j++)
        {
           totalDesc += descSuc[i][j];
        }
        sucursales[i].promDesc = totalDesc / m;
    }
    return;
}

int almacenarDescMax(struct sucursal *sucursales, int *arr)
{
    int sucMax = 0;
    for (int i = 0; i < n; i++)
    {
        if (sucursales[i].descMes > sucursales[i].promDesc)
        {
            arr[i] = i;
            sucMax++;
        }
    }
    return sucMax;
}

void ciudadGerente(struct sucursal *sucursales, struct gerente *gerentes, int *arr, int cantidad)
{
    printf("Ciudades que superaron el promedio y sus gerentes:\n");
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            printf("Ciudad: %s\n", sucursales[i].ciudad);
            printf("Gerente: %s\n", gerentes[i].nombre);
        }
    }
    return;
}   

void ordenar(struct sucursal *sucursales)
{
    struct sucursal aux;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if (strcmp(sucursales[j].ciudad, sucursales[j+1].ciudad) > 0)
            {
                aux = sucursales[j+1];
                sucursales[j+1] = sucursales[j];
                sucursales[j] = aux;
            }
        }
    }
    return;
}