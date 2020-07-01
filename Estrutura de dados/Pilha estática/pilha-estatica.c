#include <stdbool.h>
#include <stdlib.h>
#include "pilha-estatica.h"

#ifndef TAM
    #define TAM 0
#endif

struct pilhaEstatica_t {
    int qnt;
    Integer dados[TAM];
};


PilhaEstatica* cria_pe(){
    PilhaEstatica* pe = (PilhaEstatica*) malloc(sizeof(PilhaEstatica));
    if(pe != NULL) pe->qnt = 0;
    return pe;
}

void libera_pe(PilhaEstatica* pe){
    free(pe);
}

bool pe_cheia(PilhaEstatica* pe){
    if(pe == NULL) return false;
    return (pe->qnt == TAM);
}

bool pe_vazia(PilhaEstatica* pe){
    if(pe == NULL) return true;
    return (pe->qnt == 0);
}

int tamanho_pe(PilhaEstatica* pe){
    if(pe == NULL) return -1;
    return pe->qnt;
}

bool topo_pe(PilhaEstatica* pe, int* x){
    if(pe == NULL || pe_vazia(pe)) return false;
    *x = pe->dados[pe->qnt-1].value;
}

bool inserir_pe(PilhaEstatica* pe, int x){
    if(pe == NULL || pe_cheia(pe)) return false;
    pe->dados[pe->qnt] = (Integer){.value=x};
    pe->qnt++;
    return true;
}

bool remover_pe(PilhaEstatica* pe){
    if(pe == NULL || pe_vazia(pe)) return false;
    pe->qnt--;      // qnt diz a quantidade de elementos e a proxima posicao vaga; posicao podera ser sobrescrita, mas nao acessada
    return true;
}

void listar_pe(PilhaEstatica* pe){
    if(pe_vazia(pe)){
        printf("A pilha está vazia! \n");
        return;
    }
    for(int i=pe->qnt-1 ; i>=0 ; i--)
        printf("[%d] - %d \n", i, pe->dados[i].value);
}
