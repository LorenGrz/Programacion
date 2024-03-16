#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define FIL 4
#define COL 6

struct sucursal {
    int Id_Sucursal;
    char Ciudad[30];
    float Descuentos_del_mes[30];
    float Total_de_descuentos_del_mes;
    float Promedio_Descuentos;
};

struct gerentes {
    int Id_Sucursal;
    char Nombre_de_gerente[30];
};

void FuncionCargaSucursal(struct sucursal ArraySucursal[FIL]);

void FuncionCargaGerente(struct gerentes ArrayGerente[FIL]);

void Ejercicio1(struct sucursal ArraySucursal[FIL]);

void Ejercicio2(struct sucursal ArraySucursal[FIL], float ArrayDescuentos[FIL][COL]);

int Ejercicio3(struct sucursal ArraySucursal[FIL], int ArrayMenosUno[FIL]);

void Ejercicio4(struct sucursal ArraySucursal[FIL], struct gerentes ArrayGerente[FIL], int ArrayMenosUno[FIL], int Sucursales_prom_superado);

void Ejercicio5(struct sucursal ArraySucursal[FIL]);

int main (){
    struct sucursal ArraySucursal[FIL];
    struct gerentes ArrayGerente[FIL];
    int ArrayMenosUno[FIL] = {-1,-1,-1,-1};
    float ArrayDescuentos[FIL][COL] = {{100,150,180,210,150,230},{400,200,300,250,20,150},{150,200,140,450,150,320},{180,190,320,60,180,140}};
    FuncionCargaSucursal(ArraySucursal);
    FuncionCargaGerente(ArrayGerente);
    Ejercicio1(ArraySucursal);
    Ejercicio2(ArraySucursal,ArrayDescuentos);
    int Sucursales_prom_superado = Ejercicio3(ArraySucursal,ArrayMenosUno);
    Ejercicio4(ArraySucursal,ArrayGerente,ArrayMenosUno,Sucursales_prom_superado);
    for(int i=0; i<FIL; i++){
        printf("\n Ciudad: %s",ArraySucursal[i].Ciudad);
        printf("\n Id sucursal: %d",ArraySucursal[i].Id_Sucursal);
        printf("\n Total de descuentos mes: %.2f",ArraySucursal[i].Total_de_descuentos_del_mes);
        printf("\n Promedio descuentos: %.2f",ArraySucursal[i].Promedio_Descuentos);
    }
    Ejercicio5(ArraySucursal);
    for(int i=0; i<FIL; i++){
        printf("\n Ciudad: %s",ArraySucursal[i].Ciudad);
        printf("\n Id sucursal: %d",ArraySucursal[i].Id_Sucursal);
        printf("\n Total de descuentos mes: %.2f",ArraySucursal[i].Total_de_descuentos_del_mes);
        printf("\n Promedio descuentos: %.2f",ArraySucursal[i].Promedio_Descuentos);
    }
    return 0;
}

void FuncionCargaSucursal(struct sucursal ArraySucursal[FIL]){
    int i,j;
    for (i=0; i<FIL; i++){
        printf("Sucursal: %d\n", i+1);
        ArraySucursal[i].Id_Sucursal = i+1;
        printf("Ingrese ciudades:\n");
        gets (ArraySucursal[i].Ciudad);
        //fflush(stdin);
        for (j=0; j<30; j++){
            //printf("Descuento dia %d", j+1);
            //scanf("%f", &ArraySucursal[i].Descuentos_del_mes[j]);
            //fflush(stdin);
            ArraySucursal[i].Descuentos_del_mes[j] = rand() % 50;
        }
        ArraySucursal[i].Total_de_descuentos_del_mes = 0;
        ArraySucursal[i].Promedio_Descuentos = 0;
    }
}

void FuncionCargaGerente(struct gerentes ArrayGerente[FIL]){
    int i,j;
    for (i=0; i<FIL; i++){
        printf("Sucursal: %d\n", i+1);
        ArrayGerente[i].Id_Sucursal = i+1;
        printf("Ingrese gerente %d\n:",i+1);
        gets (ArrayGerente[i].Nombre_de_gerente);
        //fflush(stdin);
        }
}

void Ejercicio1(struct sucursal ArraySucursal[FIL]){
    int i,j;
    float acum;
    for (i=0; i<FIL; i++){
        acum=0;
        for (j=0; j<30; j++){
            //ArraySucursal[i].Total_de_descuentos_del_mes += ArraySucursal[i].Descuentos_del_mes[j];
            acum += ArraySucursal[i].Descuentos_del_mes[j];
        }
        ArraySucursal[i].Total_de_descuentos_del_mes = acum;
    }
}

void Ejercicio2(struct sucursal ArraySucursal[FIL], float ArrayDescuentos[FIL][COL]){
    int i,j;
    float acum;
    for (i=0; i<FIL; i++){
        acum=0;
        for (j=0; j<COL; j++){
            acum += ArrayDescuentos[i][j];
        }
        ArraySucursal[i].Promedio_Descuentos = acum / COL;
    }
}

int Ejercicio3(struct sucursal ArraySucursal[FIL], int ArrayMenosUno[FIL]){
    int i,j=0;
    for (i=0; i<FIL; i++){
        if(ArraySucursal[i].Total_de_descuentos_del_mes>ArraySucursal[i].Promedio_Descuentos){
            ArrayMenosUno[j] = i;
            j++;
        }
    }
    return j;
}

void Ejercicio4(struct sucursal ArraySucursal[FIL], struct gerentes ArrayGerente[FIL], int ArrayMenosUno[FIL], int Sucursales_prom_superado){
    int i,j;
    printf("sucursales que superaron el proemdio del mes:\n");
    for(i=0; i<Sucursales_prom_superado; i++){
        printf("%s\n", ArraySucursal[ArrayMenosUno[i]].Ciudad);
        printf("%s\n", ArrayGerente[ArrayMenosUno[i]].Nombre_de_gerente);
    }
}

void Ejercicio5(struct sucursal ArraySucursal[FIL]){
    int i,j,z;
    struct sucursal aux;
    for(i=FIL-1; i>=0 ; i--){
        for(j=0; j<i; j++){
            if((strncmp(ArraySucursal[j].Ciudad,ArraySucursal[j+1].Ciudad,30))==1){
                aux = ArraySucursal[j];
                ArraySucursal[j] = ArraySucursal[j+1];
                ArraySucursal[j+1] = aux;
//                aux.Id_Sucursal = ArraySucursal[j].Id_Sucursal;
//                strncpy(aux.Ciudad,ArraySucursal[j].Ciudad,30);
//                aux.Total_de_descuentos_del_mes = ArraySucursal[j].Total_de_descuentos_del_mes;
//                aux.Promedio_Descuentos = ArraySucursal[j].Promedio_Descuentos;
//                for(z=0; z<30; z++){
//                   aux.Descuentos_del_mes[z] = ArraySucursal[j].Descuentos_del_mes[z];
//                }
//
//                ArraySucursal[j].Id_Sucursal = ArraySucursal[j+1].Id_Sucursal;
//                strncpy(ArraySucursal[j].Ciudad,ArraySucursal[j+1].Ciudad,30);
//                ArraySucursal[j].Total_de_descuentos_del_mes = ArraySucursal[j+1].Total_de_descuentos_del_mes;
//                ArraySucursal[j].Promedio_Descuentos = ArraySucursal[j+1].Promedio_Descuentos;
//                for(z=0; z<30; z++){
//                   ArraySucursal[j].Descuentos_del_mes[z] = ArraySucursal[j+1].Descuentos_del_mes[z];
//                }
//
//                ArraySucursal[j+1].Id_Sucursal = aux.Id_Sucursal;
//                strncpy(ArraySucursal[j+1].Ciudad,aux.Ciudad,30);
//                ArraySucursal[j+1].Total_de_descuentos_del_mes = aux.Total_de_descuentos_del_mes;
//                ArraySucursal[j+1].Promedio_Descuentos = aux.Promedio_Descuentos;
//                for(z=0; z<30; z++){
//                   ArraySucursal[j+1].Descuentos_del_mes[z] = aux.Descuentos_del_mes[z];
//                }
            }
        }
    }
}
