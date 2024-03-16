//Carga de numeros random
#include <stdio.h>
#include <time.h>
#define N 1000 
int main(){
    int tnum[N], i;
    srand(time(NULL));
    // carga
    for(i=0;i<N;i++){
    tnum[i]=10+rand()%99;
    }
    return 0;
}