#include <stdbool.h>
#include <stdlib.h>
#include "pilha-dinamica.h"

typedef struct pilhaDinamica_t{
    Integer dado;
    struct pilhaDinamica_t* prox;
} ElementoPilha;


PilhaDinamica* cria_pd(){
    PilhaDinamica* pd = (PilhaDinamica*) malloc(sizeof(PilhaDinamica));
    if(pd != NULL) (*pd) = NULL;
    return pd;
}

void libera_pd(PilhaDinamica* pd){
    if(pd == NULL) return;
    ElementoPilha* aux;
    while((*pd) != NULL){
        aux = (*pd);
        (*pd) = (*pd)->prox;
        free(aux);
    }
    free(pd);
}

bool pd_vazia(PilhaDinamica* pd){
    if(pd == NULL || (*pd) == NULL) return true;
    return false;
}

int tamanho_pd(PilhaDinamica* pd){
    if(pd == NULL) return 0;
    int cont = 0;
    ElementoPilha* aux = (*pd);
    while(aux != NULL){
        cont++;
        aux = aux->prox;
    }
    return cont;
}

bool topo_pd(PilhaDinamica* pd, int* x){
    if(pd == NULL || pd_vazia(pd)) return false;
    *x = (*pd)->dado.value;
    return true;
}

bool inserir_pd(PilhaDinamica* pd, int x){
    if(pd == NULL) return false;
    ElementoPilha* elemento = (ElementoPilha*) malloc(sizeof(ElementoPilha));
    if(elemento == NULL) return false;
    elemento->dado = (Integer){.value=x};
    elemento->prox = (*pd);
    (*pd) = elemento;
    return true;
}

bool remover_pd(PilhaDinamica* pd){
    if(pd_vazia(pd)) return false;
    ElementoPilha* aux = (*pd);
    (*pd) = (*pd)->prox;
    free(aux);
    return true;
}

void listar_pd(PilhaDinamica* pd){
    if(pd == NULL || pd_vazia(pd)){
        printf("Pilha vazia! \n");
        return;
    }
    ElementoPilha* aux = (*pd);
    for (int i=tamanho_pd(pd)-1 ; i>=0 ; i--){
        printf("[%d] - %d \n", i, aux->dado.value);
        aux = aux->prox;
    }
}
