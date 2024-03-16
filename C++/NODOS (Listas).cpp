#include <iostream>
#include <stdlib.h> //para reservar los nodos y espacios en memoria

using namespace std;

int main(){
	struct nodo{
		int n;
		nodo *sig;
	}*cab=NULL, *aux, *aux1;
	
	do{
		//reservo espacio en memoria con malloc
		aux= (nodo*)malloc(sizeof (struct nodo));
		cout << "Ingrese un numero: " << endl;
		cin >> aux->n;
		
		if(cab==NULL){
			cab=aux1=aux;
		}else{
			aux1->sig=aux;
			aux1=aux;
			aux->sig=NULL;
		} 
		
	}while(aux->n!=0);
	cout<<"Tu lista es: ";
	aux1=cab;
	while(aux1!=NULL){
		cout<<aux1->n<<"-";
		aux1=aux1->sig;
	}
	
	return 0;
}
