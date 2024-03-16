#include "header.h"

using namespace std;

//aca se declaran las estructuras
struct pokemon{
	//variables de la estructura
	char nombre[50];
	char tipo[50];
	float peso;
	char genero;
}pokemon1;//Esto es una variable de tipo estructura

int main(){
	cout<<"ingrese el nombre de su pokemon"<<endl;
	cin.getline(pokemon1.nombre,50,'\n');
	cout<<"Ingrese el tipo del pokemon\n";
	cin.getline(pokemon1.tipo,50,'\n');
	cout<<"Ingrese el peso del pokemon\n";
	cin >> pokemon1.peso;
	cout<<"Ingrese el genero del pokemon\n";
	cin >> pokemon1.genero;
	
	cout<<"Nombre del pokemon "<<pokemon1.nombre<<endl;
	cout<<"Tipo del pokemon "<<pokemon1.tipo<<endl;
	cout<<"Peso del pokemon "<<pokemon1.peso<<endl;
	cout<<"Genero del pokemon "<<pokemon1.genero<<endl;
	
	return 0;
}
