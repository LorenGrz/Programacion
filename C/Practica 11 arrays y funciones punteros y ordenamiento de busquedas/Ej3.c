//Ejemplo de busqueda secuencial
#include <stdio.h>

int main() {
  int numeros[] = {10, 20, 30, 40, 50};
  int n = 5;
  int valorBuscado = 30;
  int i;
  
  for (i = 0; i < n; i++) {
    if (numeros[i] == valorBuscado) {
      printf("El valor %d se encuentra en la posición %d del arreglo.\n", valorBuscado, i);
      break;
    }
  }
  
  if (i == n) {
    printf("El valor %d no se encuentra en el arreglo.\n", valorBuscado);
  }
  
  return 0;
}