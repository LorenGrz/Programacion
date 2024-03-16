//Primer Parcial
#include <stdio.h>

void funcion2(const char servicio, int *cF, int *cE, int *cV, float *fF, float *fE, float *fV, float importe){
    switch(servicio){
        case'f':
        case'F':
            (*cF)++;
            *fF += importe;
            break;
        case'e':
        case'E':
            (*cE)++;
            *fE += importe;
            break;
        case'v':
        case'V':
            (*cV)++;
            *fV += importe;
            break;
    }

    return;
}

void funcion1(char *servicioMax, int *tPasajeros, float *impMax, float *pGeneral){
    char servicio, pasajero;
    int dias, i, contF=0, contE=0, contV=0;
    float importe=0, factF=0, factE=0, factV=0, totalFact=0;
    dias=7;

    for(i=1; i<dias+1; i++){
        printf("D%ca n%cmero %i:\n\n",161, 163, i);
        factF=0; factE=0; factV=0;
        contF=0; contE=0; contV=0;
        do{
            printf("Ingrese un pasajero, de lo contrario ingresar '*':\n");
            scanf("%c", &pasajero);
            fflush(stdin);
            fflush(stdin);
            if (pasajero != '*'){
                (*tPasajeros)++;
                do{
                    printf("Ingrese el servicio ('F' 'E' 'V'):\n");
                    scanf("%c", &servicio);
                    fflush(stdin);
                    fflush(stdin);
                    if(servicio != 'F' && servicio != 'E' && servicio !='V' && servicio != 'f' && servicio != 'e' && servicio != 'v'){
                        printf("Ingrese el servicio correctamente:\n");
                    }
                }while(servicio != 'F' && servicio != 'E' && servicio !='V' && servicio != 'f' && servicio != 'e' && servicio != 'v');

                printf("Ingrese el importe de la factura:\n");
                scanf("%f", &importe);
                fflush(stdin);
                fflush(stdin);
                totalFact += importe;

                funcion2(servicio, &contF, &contE, &contV, &factF, &factE, &factV, importe);

                if(factF>*impMax){
                    *impMax = factF;
                    *servicioMax = 'F';
                }
                if(factE>*impMax){
                    *impMax = factE;
                    *servicioMax = 'E';
                }
                if(factV>*impMax){
                    *impMax = factV;
                    *servicioMax = 'V';
                }
            }
        }while(pasajero !='*');
        printf("D%ca %i:\nF: %.2f - %i pasajeros \nE: %.2f - %i pasajeros \nV: %.2f - %i pasajeros\n\n\n", 161, i, factF, contF, factE, contE, factV, contV);
    }
    *pGeneral = totalFact/dias;
    return;
}

int main(){
    int totalPasajeros=0;
    float importeMax=0.00, promGeneral=0.00;
    char servicioMax;

    printf("Programa para el hotel:\n\n");

    funcion1(&servicioMax, &totalPasajeros, &importeMax, &promGeneral);

    printf("Cantidad de pasajeros recibidos:%i\n", totalPasajeros);
    printf("El servicio que facturo m%cs fue: '%c' y el importe m%cximo fue: %.2f\n", 160, servicioMax, 160, importeMax);
    printf("El promedio general de facturaci%cn es: %.2f\n", 162, promGeneral);
    getchar();

    return 0;
}