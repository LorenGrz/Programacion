// Una agencia tiene 5 vendedores. Cada uno se identifica con un número entero entre 
// 1 y 120. Cada vendedor vende en distintas zonas. Las zonas son ‘a’, ‘b’, ‘c’. Cada 
// uno realiza una o más ventas. Se quiere emitir el listado de las ventas máximas 
// por vendedor, es decir el listado de los vendedores con el mayor monto que hayan 
// alcanzado en una operación de venta. En esta lista no deben figurar quienes no 
// hayan vendido nada. También se quiere los totales por zona. Para ello, se ingresa 
// un número no determinado de veces una terna: número de vendedor, número de zona, 
// monto de la operación. Los datos no están ordenados de manera alguna. El fin de 
// datos se indica con número de vendedor –1 y no se lee para el ni zona ni venta. 
// Escribir el programa que resuelva el problema.  
#include <stdio.h>

#define MAX_VENDEDORES 5
#define MAX_ZONAS 3
#define DIM 10

// Estructura para almacenar los datos de cada venta
struct vendedores{
    int numeroVendedor;
    char zona;
    float venta[DIM];
};

// Estructura para almacenar los vendedores con el monto máximo de venta alcanzado
struct vendedorMaximo{
    int numeroVendedorMax;
    float montoMaximo;
};

void funcionCarga(struct vendedores Ven[], struct vendedorMaximo VenMax[]){
    int contVendedores=0, validacion, cantVentas=0, i, j;
    for(i=0;i<MAX_VENDEDORES;i++){
        VenMax[i].montoMaximo=0;
    }
    for(i=0;i<MAX_VENDEDORES;i++){
        for(j=0;j<DIM;j++){
            Ven[i].venta[j]=0.00;
        }
    }
    while(contVendedores<MAX_VENDEDORES){
        printf("Ingresa un vendedor?(|1: si||-1: no|)\n");
        scanf("%i", &validacion);
        if(validacion==-1){
            break;
        }
        do{
            printf("Ingrese el numero del vendedor: \n");
            scanf("%i", &Ven[contVendedores].numeroVendedor);
            fflush(stdin);
            if(Ven[contVendedores].numeroVendedor < 1 && Ven[contVendedores].numeroVendedor > 120){
                printf("Ingrese correctamente el numero del vendedor.\n");
            }   
        }while(Ven[contVendedores].numeroVendedor < 1 && Ven[contVendedores].numeroVendedor > 120);
        do{
            printf("Ingrese la zona del vendedor: (a, b, c):\n");
            scanf("%c", &Ven[contVendedores].zona);
            fflush(stdin);
            if(Ven[contVendedores].zona !='a' && Ven[contVendedores].zona != 'A'&&Ven[contVendedores].zona !='b' && Ven[contVendedores].zona != 'B'&&Ven[contVendedores].zona !='c' && Ven[contVendedores].zona != 'C'){
                printf("Ingrese la zona correctamente");
            }
        }while(Ven[contVendedores].zona !='a' && Ven[contVendedores].zona != 'A'&&Ven[contVendedores].zona !='b' && Ven[contVendedores].zona != 'B'&&Ven[contVendedores].zona !='c' && Ven[contVendedores].zona != 'C');

        do{
            printf("Quiere ingresar una venta?(|1: si||-1: no|)\n");
            scanf("%i", &validacion);
            fflush(stdin);
            if(validacion!=-1){
                printf("Ingrese el monto de la venta:\n");
                scanf("%f", &Ven[contVendedores].venta[cantVentas]);
                fflush(stdin);
                if(VenMax[contVendedores].montoMaximo<Ven[contVendedores].venta[cantVentas]){
                    VenMax[contVendedores].montoMaximo=Ven[contVendedores].venta[cantVentas];
                    VenMax[contVendedores].numeroVendedorMax=Ven[contVendedores].numeroVendedor;
                }
                cantVentas++;
            }
        }while(validacion!=-1);
        contVendedores++;
        cantVentas=0;
    }
    contVendedores=0;
    while(contVendedores<MAX_VENDEDORES){
        if(VenMax[contVendedores].montoMaximo!=0){
            printf("Vendedor %i: \n", contVendedores+1);
            printf("Numero de Vendedor: %i\n", VenMax[contVendedores].numeroVendedorMax);
            printf("Venta maxima: $%.2f\n", VenMax[contVendedores].montoMaximo);
        }

    contVendedores++;
    }

    return;
}

int main(){
    struct vendedores Ven[MAX_VENDEDORES];
    struct vendedorMaximo VenMax[MAX_VENDEDORES];

    funcionCarga(Ven, VenMax);

    return 0;
}
// int main() {
//     struct Venta ventas[MAX_VENDEDORES * MAX_ZONAS]; // Arreglo para almacenar las ventas
//     struct VendedorMaximo ventasMaximas[MAX_VENDEDORES]; // Arreglo para almacenar los vendedores con el monto máximo de venta alcanzado
//     float totalesPorZona[MAX_ZONAS] = {0.0}; // Arreglo para almacenar los totales por zona
//     int i, j;

//     // Inicializar las ventas máximas para cada vendedor a un valor negativo
//     for (i = 0; i < MAX_VENDEDORES; i++) {
//         ventasMaximas[i].numeroVendedor = i + 1;
//         ventasMaximas[i].montoMaximo = -1.0;
//     }

//     // Leer las ventas realizadas por cada vendedor en cada zona
//     int numeroVendedor;
//     char zona;
//     float venta;
//     printf("Ingrese el número de vendedor, número de zona y monto de la operación (-1 para terminar):\n");
//     while (1) {
//         scanf("%d", &numeroVendedor);
//         if (numeroVendedor == -1) {
//             break; // Terminar la lectura
//         }
//         scanf(" %c %f", &zona, &venta);

//         // Almacenar la venta
//         struct Venta nuevaVenta;
//         nuevaVenta.numeroVendedor = numeroVendedor;
//         nuevaVenta.zona = zona;
//         nuevaVenta.venta = venta;
//         ventas[(numeroVendedor - 1) * MAX_ZONAS + (zona - 'a')] = nuevaVenta;

//         // Actualizar el monto máximo de venta para el vendedor actual
//         if (venta > ventasMaximas[numeroVendedor - 1].montoMaximo) {
//             ventasMaximas[numeroVendedor - 1].montoMaximo = venta;
//         }

//         // Calcular los totales por zona
//         totalesPorZona[zona - 'a'] += venta;
//     }

//     // Imprimir el listado de las ventas máximas por vendedor
//     printf("Listado de las ventas máximas por vendedor:\n");
//     for (i = 0; i < MAX_VENDEDORES; i++) {
//         if (ventasMaximas[i].montoMaximo > 0.0) {
//             printf("Vendedor %d: $%.2f\n", ventasMaximas[i].numeroVendedor, ventasMaximas[i].montoMaximo);
//         }
//     }

//     // Imprimir los totales por zona
//     printf("Totales por zona:\n");
//     for (i = 0; i < MAX_ZONAS; i++) {
//         printf("Zona %c: $%.2f\n", 'a' + i, totalesPorZona[i]);
//     }

//     return 0;
// }