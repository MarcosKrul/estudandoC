#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool ligar_a(int* vet) {
    return (vet[0] || vet[2] || (vet[1] && vet[3]) || (!vet[1] && !vet[3]));
}

bool ligar_b(int* vet){
    return (!vet[1] || (vet[2] && vet[3]) || (!vet[2] && !vet[3]));
}

bool ligar_c(int* vet){
    return (vet[1] || vet[3] || !vet[2]);
}

bool ligar_d(int* vet){
    return (vet[0] || (vet[2] && !vet[3]) || (!vet[1] && vet[2]) || (!vet[1] && !vet[3]) || (vet[1] && !vet[2] && vet[3]));
}

bool ligar_e(int* vet) {
    return ((vet[2] && !vet[3]) || (!vet[1] && !vet[3]));
}

bool ligar_f(int* vet){
    return (vet[0] || (vet[1] && !vet[3]) || (vet[1] && !vet[2]) || (!vet[2] && !vet[3]));
}

bool ligar_g(int* vet){
    return (vet[0] || (vet[1] && !vet[3]) || (vet[1] && !vet[2]) || (!vet[1] && vet[2]));
}

void decToBin(int dec, int tam, int* vet) {
    do {
        vet[tam-1] = dec%2;
        tam--;
    } while((dec = dec/2)>0 && tam>=0);
}

void main() {
    int i, value, *vet = (int[]){0,0,0,0};
    while(1){
        printf("\nInforme um valor: ");
        scanf("%d", &value);
        decToBin(value, 4, vet);
        for(i=0 ; i<4 ; i++) printf("%d", vet[i]);
        if(ligar_a(vet)) printf("\nLigar a");
        if(ligar_b(vet)) printf("\nLigar b");
        if(ligar_c(vet)) printf("\nLigar c");
        if(ligar_d(vet)) printf("\nLigar d");
        if(ligar_e(vet)) printf("\nLigar e");
        if(ligar_f(vet)) printf("\nLigar f");
        if(ligar_g(vet)) printf("\nLigar g");
    }
}
