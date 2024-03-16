/*
Ejercicio tipo primer parcial:
Datos:
Un empresa cuya actividad es la gestión de facturación, 
necesita una aplicación específica para la facturación generada por varios
grupos que son dueños de distintos medios de comunicación. 
Estos grupos tienen clientes que realizan publicidad en los medios que
dirige cada grupo. 
El criterio general que tienen es clasificar los medios por clase, a saber:
clase X: radio
clase Y: televisión
clase Z: redes sociales
Para resolver el problema de la facturación informatizando el sistema, 
lo seleccionan a Ud., y se reúnen para el análisis funcional. 
El escenario general es que existen muchos grupos -se desconoce la cantidad-. 
Cada grupo tiene clientes –también desconocen la cantidad- y,
que estos clientes tienen publicidad en algún medio de los mencionados, 
cuyos costos varían. Por lo tanto en la reunión
definen lo siguiente:
Requerimientos:
1. Construir una función que permita procesar cada grupo, identificando cada uno con un número entero positivo.
 Por cada grupo
se ingresan una serie de clientes, que también se identifican con un número entero positivo.
 Por cada cliente se ingresa: Clase (X, Y ó Z) -caracter-
Importe-número real 
Esta función debe emitir, durante el proceso de obtención de los resultados parciales 
y por cada grupo la facturación total por cada clase con su cantidad de clientes.
Ejemplo de la primera iteración de grupo:
Grupo 1 – Facturación:
X: 1266,89, 5 clientes
Y: 2154,69, 2 clientes
Z: 1987,50, 3 clientes
Ejemplo de la segunda iteración de grupo:
Grupo 2 – Facturación:
X: 1245,21, 3 clientes
Y: 4432,91, 5 clientes
Z: 2870,30, 2 clientes
…siguientes iteraciones….
2. Construir una función auxiliar que reciba -al menos- clase e importe y devuelva a la función del punto 1, 
el total acumulado por cada clase con su cantidad de clientes.
3. Mensaje final en main(), que emita los resultados finales:
 total de grupos y total de clientes.
 qué clase de medio facturó más y cuál fue el importe.
 el total general de facturación.
*/
#include <stdio.h>

void funcion2(const char *clase2,float *fact2, float *factx2, float *facty2, float *factz2, int *contx2, int *conty2, int *contz2 ){
    switch(*clase2){
        case 'x':
        case 'X':   (*contx2)++;
                    *factx2 += *fact2;
            break;
        case'y':
        case'Y':    (*conty2)++;
                    *facty2 += *fact2;
            break;
        case'z':
        case'Z':    (*contz2)++;
                    *factz2+= *fact2;
            break;
    }

    return;
}

void funcion1(int *tgrupos, int *tclientes, float *tfact, float *impmax, char *clasee){
    int cantgrupos, cantclientes=0, i, j, contx=0, conty=0, contz=0;
    char clase;
    float factx=0, facty=0, factz=0, fact=0;
    do{
        printf("Ingrese la cantidad de grupos: \n");
        scanf("%i", &cantgrupos);
        fflush(stdin);
        fflush(stdin);
        if(cantgrupos<=0){
            printf("Ingrese correctamente\n");
        }
    }while(cantgrupos<=0);
    *tgrupos = cantgrupos;
    for (i=1;i<=cantgrupos;i++){

        do{
            printf("Ingrese la cantidad de clientes: \n");
            scanf("%i", &cantclientes);
            fflush(stdin);
            fflush(stdin);
            if(cantclientes<=0){
                printf("Ingrese correctamente\n");
            }
        }while(cantclientes<=0);
        *tclientes += cantclientes;
        for (j=1;j<=cantclientes;j++){
            printf("Ingrese la clase de medio (que son X Y Z): \n");
            scanf("%c", &clase);
            fflush(stdin);
            fflush(stdin);
            printf("Ingrese la facturacion:\n");
            scanf("%f", &fact);
            fflush(stdin);
            fflush(stdin);
            funcion2(&clase,&fact, &factx, &facty, &factz, &contx, &conty, &contz);
            *tfact += fact;
            if (factx>facty && factx>factz){
                *clasee='X';
                *impmax=factx;
            }else if(facty>factx && facty>factz){
                *clasee='Y';
                *impmax=facty;
            }else if (factz>factx && factz>facty){
                *clasee='Z';
                *impmax=factz;
             }
        }
        printf("Grupo %i - facturacion:\nX:%.2f, %i clientes\nY:%.2f, %i clientes\nZ:%.2f, %i clientes\n\n", i, factx, contx, facty, conty, factz, contz);
    }
    return;
}

int main(){
    int totalgrupos=0, totalclientes=0;
    float importemax=0, totalfact=0;
    char clasemedio;

    funcion1(&totalgrupos,&totalclientes,&totalfact,&importemax,&clasemedio);

    printf("\nEl total de grupos es: %i \nEl total de clientes es: %i \nLa clase que mas facturo fue la '%c' y facturo un total de: $%.2f\nEl total de la facturacion: %.2f  ", totalgrupos ,totalclientes, clasemedio, importemax, totalfact);

    getchar();
    return 0;
}
