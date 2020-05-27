#include <stdio.h>

#define TROCA(x,y,t) {t aux=x; x=y; y=aux;}

void troca(int* a, int* b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void main() {
    int a = 10, b = 20;
    printf("A = %d\nB = %d\n", a, b);
#ifdef TROCA(x,y,t)
    printf("Valores trocados pela funcao macro\n");
    TROCA(a,b,int);
#else
    printf("Valores trocados pela funcao troca\n");
    troca(&a,&b);
#endif
    printf("A = %d\nB = %d\n", a, b);
}
