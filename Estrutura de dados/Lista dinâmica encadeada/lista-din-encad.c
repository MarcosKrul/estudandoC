#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista-din-encad.h"


typedef struct listaDinEncad_t {
    Integer dado;
    struct listaDinEncad_t* prox;
} ElementoLista;

ListaDinEncad* cria_lde(){
    ListaDinEncad* lde = (ListaDinEncad*) malloc(sizeof(ListaDinEncad));
    if(lde != NULL)
        *lde = NULL;
    return lde;
}

void libera_lde(ListaDinEncad* lde){
    if(lde == NULL) return;
    ElementoLista* elemento;
    while((*lde) != NULL){
        elemento = *lde;
        *lde = (*lde)->prox;        // *lde = (*(*lde)).prox
        free(elemento);
    }
    free(lde);
}

int tamanho_lde(ListaDinEncad* lde){
    if(lde == NULL) return 0;
    int soma=0;
    ElementoLista* elemento = *lde;
    while(elemento != NULL){
        soma++;
        elemento = elemento->prox;
    }
    return soma;
}

bool lde_vazia(ListaDinEncad* lde){
    if(lde == NULL || *lde == NULL) return true;
    return false;
}

void listar_lde(ListaDinEncad* lde){
    if(lde == NULL) return;
    if(lde_vazia(lde)) {
        printf("A lista está vazia! \n");
        return;
    }
    int i=0;
    ElementoLista* aux = (*lde);
    while(aux != NULL){
        printf("[%d] - %d \n", i, aux->dado.value);
        aux = aux->prox;
        i++;
    }
}

bool inserir_lde_inicio(ListaDinEncad* lde, int x){
    if(lde == NULL) return false;
    ElementoLista* elemento = (ElementoLista*) malloc(sizeof(ElementoLista));
    if(elemento == NULL) return false;
    elemento->dado = (Integer){.value=x};
    elemento->prox = (*lde);            // novo elemento aponta para o antigo primeiro elemento
    (*lde) = elemento;                 // lista aponta para o novo primeiro elemento
    return true;
}

bool inserir_lde_fim(ListaDinEncad* lde, int x){
    if(lde_vazia(lde)) return inserir_lde_inicio(lde, x);
    if(lde == NULL) return false;
    ElementoLista* elemento = (ElementoLista*) malloc(sizeof(ElementoLista));
    if(elemento == NULL) return false;
    elemento->dado = (Integer){.value=x};
    elemento->prox = NULL;
    ElementoLista* aux = (*lde);
    while(aux->prox != NULL) aux = aux->prox;
    aux->prox = elemento;
    return true;
}

bool inserir_lde_pos(ListaDinEncad* lde, int x, int pos){
    if(lde_vazia(lde)) return inserir_lde_inicio(lde, x);
    if(pos == tamanho_lde(lde)-1) return inserir_lde_fim(lde, x);
    if(lde == NULL || pos<0) return false;
    ElementoLista* elemento = (ElementoLista*) malloc(sizeof(ElementoLista));
    if(elemento == NULL) return false;
    elemento->dado = (Integer){.value=x};
    int i;
    ElementoLista* aux = (*lde);
    for(i=0 ; i<tamanho_lde(lde)-1 ; i++){
        if(i == pos){
            elemento->prox = aux->prox;
            aux->prox = elemento;
        } else aux = aux->prox;
    }
    return true;
}

bool remover_lde_inicio(ListaDinEncad* lde){
    if(lde == NULL || lde_vazia(lde)) return false;
    ElementoLista* aux = (*lde);
    if(tamanho_lde(lde) == 1){
        free(aux);
        *lde = NULL;
        return true;
    }
    (*lde) = aux->prox;
    free(aux);
    return true;
}

bool remover_lde_fim(ListaDinEncad* lde){
    if(lde == NULL || lde_vazia(lde)) return false;
    if(tamanho_lde(lde) == 1) return remover_lde_inicio(lde);
    ElementoLista* aux = (*lde);
    ElementoLista* penultimo;
    while(aux->prox != NULL) {
        penultimo = aux;
        aux = aux->prox;
    }
    penultimo->prox = NULL;
    free(aux);
    return true;
}

bool remover_lde_elemento(ListaDinEncad* lde, int x){
    if(lde == NULL || lde_vazia(lde)) return false;
    ElementoLista* elemento;
    ElementoLista* aux = (*lde);
    while(aux != NULL && x != aux->dado.value){
        elemento = aux;
        aux = aux->prox;
    }
    if(aux == NULL) return false;
    if(aux == (*lde)) return remover_lde_inicio(lde);
    if(aux->prox == NULL) return remover_lde_fim(lde);

    elemento->prox = aux->prox;
    free(aux);
    return true;
}

int buscar_lde(ListaDinEncad* lde, int x){
    if(lde == NULL || lde_vazia(lde)) return -1;
    int index = 0;
    ElementoLista* aux = (*lde);
    while(aux != NULL){
        if(x == aux->dado.value) return index;
        aux = aux->prox;
        index++;
    }
    if(index == tamanho_lde(lde)) return -1;
}

bool buscar_indice_lde(ListaDinEncad* lde, int pos, int* x){
    if(lde == NULL || lde_vazia(lde) || pos<0 || pos>=tamanho_lde(lde)) return false;
    ElementoLista* aux = (*lde);
    while(pos>0){
        aux = aux->prox;
        pos--;
    }
    *x = aux->dado.value;
    return true;
}

ListaDinEncad* arrayToLde(int tam, int* vet){
    ListaDinEncad* lde = cria_lde();
    if(lde == NULL) return lde;
    while(tam>0){
        inserir_lde_inicio(lde, vet[tam-1]);
        tam--;
    }
    return lde;
}

bool ldeToArray(ListaDinEncad* lde, int* vet){
    if(lde == NULL) return false;
    int i=0;
    while(i<tamanho_lde(lde)){
        buscar_indice_lde(lde, i, &vet[i]);
        i++;
    }
    return true;
}
