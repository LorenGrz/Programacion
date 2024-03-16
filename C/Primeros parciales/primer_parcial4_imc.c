#include <stdio.h>

void funcionAux(int *cont, float *Alt, float *pesO, float *acum, float *IMCpuntero){
    *cont++;
    *IMCpuntero = (*pesO)/((*Alt) * (*Alt));
    *acum += *IMCpuntero;
    return;
}

void procesarPacientes(int *tPacientes, float *pImc){
    char flag='1', flag1='1';
    int edad=0, P=0, contPacientes=0;
    float altura=0, peso=0, IMC=0, acumIMC=0;
    printf("Si tiene pacientes para ingresar ingrese un caracter, de lo contrario ingresar 0: \n");
    scanf("%c", &flag);
    fflush(stdin);
    fflush(stdin);
    if(flag!='0'){
        do{
            P++;
            do{
                printf("Ingrese la edad del paciente: \n");
                scanf("%d", &edad);
                fflush(stdin);
                fflush(stdin);
                if(edad<=12){
                    printf("ingrese la edad correctamente\n");
                }
            }while(edad<=12);
            contPacientes++;

            printf("Ingrese la altura del paciente en metros: \n");
            scanf("%f", &altura);
            fflush(stdin);
            fflush(stdin);

            printf("Ingrese el peso del paciente en kilogramos: \n");
            scanf("%f", &peso);
            fflush(stdin);
            fflush(stdin);

            funcionAux(&contPacientes, &altura, &peso, &acumIMC, &IMC);

            *pImc= acumIMC/contPacientes;

            printf("El imc del paciente %i es: %.2f\n",P, IMC);

            printf("Ingresar un nuevo paciente?, si no ingresar 0\n");
            scanf("%c", &flag1);
            fflush(stdin);
            fflush(stdin);
        }while(flag1!='0');
     }else{
        printf("Fin del programa.");
        }
    *tPacientes = contPacientes;
    return;
}

int main(){
    int totalPacientes=0;
    float promImc=0;

    procesarPacientes(&totalPacientes, &promImc);

    if(totalPacientes>0){
        printf("El total de pacientes es: %i", totalPacientes);
        if(promImc >= 25){
            printf(", es un Grupo de riesgo");
        }else if(promImc < 25 && promImc >= 20){
            printf(", es un Grupo sin riesgo");
        }else if (promImc < 20){
            printf(", es un Grupo desnutrido");
        }
    }
    getchar();

    return 0;
}