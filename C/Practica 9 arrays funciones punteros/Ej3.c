// Completa e implementa el siguiente programa. Después de cada asignación emite dirección y contenido. Comenta 
// el código: 
// int v[5];  
// int *p;  
// ... 
// p = &v[0];  
// *p = 1;  
// *(p+1) = 2;  
// *(p+2) = 3;  

#include <stdio.h>

#define DIM 50

int main(){
    int v[5];  
    int *p;  

    p = &v[0];  
    *p = 1;  
    *(p+1) = 2;  
    *(p+2) = 3;  
    return 0;
}