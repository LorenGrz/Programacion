#include "header.h"

using namespace std;

//aqui van las clases
class Pokemon{
	//Estos son los atributos (variables)
	public:
		string nombre;
		float peso;
	//Estos son los metodos y el constructor
	public:
		Pokemon(string, float);//constructor
		void Saludo();//metodo(funcion)
};

//inicializo el constructor
Pokemon::Pokemon(string _nombre, float _peso){
	nombre = _nombre;
	peso = _peso;
}

//utilizo el metodo
void Pokemon::Saludo(){
	cout << "El pokemon que te saluda es: "<<nombre<<" y el pesa "<<peso<<" kg"<<endl;
}

//clase hija
class Pokemons_Fuego : public Pokemon{
	public:
		int vida;
		char genero;
	public:
		Pokemons_Fuego(string, float, int, char);
		void Saludo();
};

Pokemons_Fuego::Pokemons_Fuego(string _nombre, float _peso, int _vida, char _genero) : Pokemon(_nombre, _peso){
	vida =  _vida;
	genero = _genero;
}

void Pokemons_Fuego::Saludo(){
	Pokemon::Saludo();
	cout << "El pokemon tiene " << vida << " puntos de vida y su genero es: " << genero;
}


int main(){
	Pokemons_Fuego pokeobj("Charmander", 0.90, 60,'F');
	pokeobj.Saludo();
	
	return 0;
}
