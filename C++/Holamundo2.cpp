//programa que calcule e indique el indice de la masa corporal
#include <iostream>
#include <math.h>

using namespace std;

int main(){
	//ingreso de variables
	float peso = 0;
	float altura = 0;
	float imc = 0;
	
	cout << "Calculadora de Indice de Masa Corporal (IMC)\n";
	cout << "Ingrese su peso en kg: ";
	cin >> peso;
	cout << "Ingrese su altura en metros: ";
	cin >> altura;
	//calculando el IMC
	imc = peso / pow(altura,2);
	cout << "Su IBM es: " << imc;
	
	return 0;
}
