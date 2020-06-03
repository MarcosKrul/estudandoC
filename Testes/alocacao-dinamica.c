#include <stdio.h>
#include <stdlib.h>

int i;

void imprime(int tam, int* p){
    for(i=0 ; i<tam ; i++) printf("[%d] - %d\n", i, p[i]);
}

main(){
    int* vet = (int *) malloc(8*sizeof(int));
    for(i=1 ; i<=8 ; i++) vet[i-1] = i;
    imprime(8, vet);
    printf("\n\n");
    vet = (int *) realloc(vet, 10*sizeof(int));
    for(i=9 ; i<=10 ; i++) vet[i-1] = i;
    imprime(10, vet);
    free(vet);
}
