//programa que calcule e indique el indice de la masa corporal
#include <iostream>
#include <math.h>
#include <iomanip>
#include <conio.h>
#include <clocale>

using namespace std;

//funcion de calculo de ibm
float ibmfunc(float *p, float *a){
	return (*p / pow(*a,2));
}
 
int main(){
	setlocale(LC_CTYPE,"Spanish");
	//ingreso de variables
	float peso = 0;
	float altura = 0;
	float imc = 0;
	
	cout << "Calculadora de Indice de Masa Corporal (IMC)\n";
	cout << "Ingrese su peso en kg: ";
	cin >> peso;
	cout << "Ingrese su altura en metros �: ";
	cin >> altura;
	//calculando el IMC
	imc = ibmfunc(&peso, &altura);
	cout << "Su IBM es: " << setprecision(4)<< imc<<" kg/m^2";
	getch();
	
	return 0;
}
