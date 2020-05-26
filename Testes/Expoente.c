#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int expoenteTrivial(int base, int expoente);
int expoenteRecursivo(int base, int expoente);

void main (int argc, char* argv[]) {
    setlocale(LC_ALL, "ptb");
    if(argc == 1) return;
    int base = atoi(argv[1]);
    int expoente = atoi(argv[2]);
    printf("Biblioteca:\t%d^%d = %.0f\n", base, expoente, pow(base,expoente));
    printf("Trivial:\t%d^%d = %d\n", base, expoente, expoenteTrivial(base, expoente));
    printf("Recursivo:\t%d^%d = %d\n", base, expoente, expoenteRecursivo(base, expoente));
}

int expoenteTrivial(int base, int expoente){
    if(expoente == 0 || base == 1) return 1;
    if(expoente == 1) return base;

    int i;
    int mul = 1;
    for(i=0 ; i<expoente ; i++)
        mul *= base;
    return mul;
}

int expoenteRecursivo(int base, int expoente){
    if(expoente == 0) return 1;
    if(expoente == 1) return base;
    else return (base*expoenteRecursivo(base, expoente-1));
}
