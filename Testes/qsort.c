#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define TAM 10

int i;
void imprimeVetor(int vet[]);
int comparaCrescente(const void* p1, const void* p2);
int comparaDecrescente(const void* p1, const void* p2);

void main () {
    srand(time(NULL));
    int vet[TAM];
    for(i=0 ; i<TAM ; i++) vet[i] = rand()%100;
    printf("===Vetor original===\n"); imprimeVetor(vet);
    printf("===Ordenado crescente===\n");
    qsort(vet,TAM,sizeof(int),comparaCrescente);
    imprimeVetor(vet);
    printf("===Ordenado decrescente===\n");
    qsort(vet,TAM,sizeof(int),comparaDecrescente);
    imprimeVetor(vet);
}

void imprimeVetor(int vet[]){
    for(i=0 ; i<TAM ; i++) printf("[%d] = %d\n", i, vet[i]);
}

int comparaCrescente(const void* p1, const void* p2){
    int a = *(int*)p1, b = *(int*)p2;
    if(a == b) return 1;
    return a>b? 1 : -1;
}

int comparaDecrescente(const void* p1, const void* p2){
    int a = *(int*)p1, b = *(int*)p2;
    if(a == b) return 1;
    return a>b? -1 : 1;
}
