#include "header.h"

using namespace std;

int main(){
	cout << "Esta es una prueba del include"<<"\n";
	int numero[]={4,5,6,7,8,9,10};
	for(int i=0; i<7; i++){
		cout<<numero[i]<<endl;
	}
	int arreglo2[5], a;
	cout << "Ingrese 5 valores\n";
	for (int i=0; i<5;i++){
		cin >> a;
		arreglo2[i]=a;
	}
	cout << "Valores: \n";
	for(int i=0; i<5; i++){
		cout<<arreglo2[i]<<endl;
	}
	
	
	return 0;
}
