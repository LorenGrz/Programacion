#include <stdio.h>

int main(){
    int a=5;
    float b = 13.546; 
    char c = 'A';
    char d = 'a';
    int e = 5;

    printf ("a vale %d", a); 
    printf ("a vale %o", a); 
    printf ("a vale %x", a); 
    printf ("a vale %f", a); 
    printf ("a vale %c", a); 
    printf ("b vale %d", b);
    printf ("b vale %5.2f",b); 
    printf ("b vale %f", b); 
    printf ("b vale %.1f", b);
    printf ("b vale %.2f",b); 
    printf ("b vale %6.4f",b);
    printf ("b vale %6.1f",b); 
    printf ("b vale %c", b); 
    printf ("b vale %o", b); 
    printf ("b vale %x", b);
    printf ("c vale %f", c); 
    printf ("c vale %c", c); 
    printf ("c vale %o", c);
    printf ("c vale %x", c);
    printf ("d vale %d", d); 
    printf ("d vale %f", d); 
    printf ("d vale %c", d); 
    printf ("d vale %o", d); 
    printf ("d vale %x", d); 
    printf ("e vale %d", e); 
    printf ("e vale %f", e);
    printf ("e vale %c", e); 
    printf ("e vale %o", e);
    printf ("e vale %x", e);

    return 0;
}