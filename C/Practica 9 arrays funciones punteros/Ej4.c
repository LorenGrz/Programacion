// Qué emite el siguiente programa?: 
#include <stdio.h> 

int main(){ 
    int x[3], *puntero;  
    x[0]=10;  
    x[1]=20;  
    x[2]=30; 
    puntero = x;  
    printf("%p\n",puntero); 
    puntero = &x[0];  
    printf("%p\n",puntero); 
    printf("%d\n\n",puntero[0]);  
    printf("%d\n\n",*puntero); 
    printf("%X\n\n",&puntero);  
    printf("%X\n\n",&puntero[1]);  
    printf("%d\n\n",puntero[1]); 
    printf("%d\n",*(puntero+1)); 
    printf("%d\n",*(puntero+2));  
    return 0; 
} 