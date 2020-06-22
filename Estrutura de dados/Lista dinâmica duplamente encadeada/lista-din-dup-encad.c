#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista-din-dup-encad.h"

typedef struct listaDinEncadDup_t {
    struct listaDinEncadDup_t* ant;
    struct listaDinEncadDup_t* prox;
    Integer dado;
} ElementoLista;


ListaDinEncadDup* cria_lded(){
    ListaDinEncadDup* lded = (ListaDinEncadDup*) malloc(sizeof(ListaDinEncadDup));
    if(lded != NULL)
        *lded = NULL;
    return lded;
}

void libera_lded(ListaDinEncadDup* lded){
    if(lded == NULL) return;
    ElementoLista* aux;
    while((*lded) != NULL){
        aux = *lded;
        *lded = (*lded)->prox;
        free(aux);
    }
    free(lded);
}

bool lded_vazia(ListaDinEncadDup* lded){
    if(lded == NULL || (*lded) == NULL) return true;
    return false;
}

int tamanho_lded(ListaDinEncadDup* lded){
    if(lded == NULL) return 0;
    int soma=0;
    ElementoLista* aux = (*lded);
    while(aux != NULL) {
        soma++;
        aux = aux->prox;
    }
    return soma;
}

void listar_lded(ListaDinEncadDup* lded){
    if(lded == NULL) return;
    if(lded_vazia(lded)) {
        printf("A lista está vazia! \n");
        return;
    }
    int i=0;
    ElementoLista* aux = (*lded);
    while(aux != NULL){
        printf("[%d] = %d \n", i, aux->dado.value);
        aux = aux->prox;
        i++;
    }
}

bool inserir_lded_inicio(ListaDinEncadDup* lded, int x){
    if(lded == NULL) return false;
    ElementoLista* elemento = (ElementoLista*) malloc(sizeof(ElementoLista));
    if(elemento == NULL) return false;
    elemento->dado = (Integer){.value=x};
    elemento->ant = NULL;
    elemento->prox = (*lded);
    if(!lded_vazia(lded)) (*lded)->ant = elemento;
    (*lded) = elemento;
    return true;
}

bool inserir_lded_fim(ListaDinEncadDup* lded, int x){
    if(lded_vazia(lded)) return inserir_lded_inicio(lded, x);
    if(lded == NULL) return false;
    ElementoLista* elemento = (ElementoLista*) malloc(sizeof(ElementoLista));
    if(elemento == NULL) return false;
    elemento->dado = (Integer){.value=x};
    elemento->prox = NULL;
    ElementoLista* aux = (*lded);
    while(aux->prox != NULL) aux = aux->prox;
    aux->prox = elemento;
    elemento->ant = aux;
    return true;
}

bool inserir_lded_pos(ListaDinEncadDup* lded, int x, int pos){
    if(lded_vazia(lded) || pos == 0) return inserir_lded_inicio(lded, x);
    if(pos == tamanho_lded(lded)) return inserir_lded_fim(lded, x);
    if(lded == NULL || pos<0 || pos > tamanho_lded(lded)) return false;
    ElementoLista* elemento = (ElementoLista*) malloc(sizeof(ElementoLista));
    if(elemento == NULL) return false;
    elemento->dado = (Integer){.value=x};
    int i;
    ElementoLista* aux = (*lded);
    for(i=0 ; i<tamanho_lded(lded) ; i++){
        if(i == pos-1){
            elemento->prox = aux->prox;
            elemento->ant = aux;
            (aux->prox)->ant = elemento;
            aux->prox = elemento;
            break;
        } else aux = aux->prox;
    }
    return true;
}

bool remover_lded_inicio(ListaDinEncadDup* lded){
    if(lded_vazia(lded)) return false;
    ElementoLista* aux = (*lded);
    if(tamanho_lded(lded) == 1){
        free(aux);
        (*lded) = NULL;
        return true;
    }
    (*lded) = aux->prox;
    (aux->prox)->ant = NULL;
    free(aux);
    return true;
}

bool remover_lded_fim(ListaDinEncadDup* lded){
    if(lded_vazia(lded)) return false;
    if(tamanho_lded(lded) == 1) return remover_lded_inicio(lded);
    ElementoLista* aux = (*lded);
    while(aux->prox != NULL) aux = aux->prox;
    (aux->ant)->prox = NULL;
    free(aux);
    return true;
}

bool remover_lded_elemento(ListaDinEncadDup* lded, int x){
    if(lded_vazia(lded)) return false;
    ElementoLista* aux = (*lded);
    while(aux != NULL && x != aux->dado.value) aux = aux->prox;
    if(aux == NULL) return false;
    if(aux->prox == NULL) return remover_lded_fim(lded);
    if(aux == (*lded)) return remover_lded_inicio(lded);
    (aux->ant)->prox = aux->prox;
    (aux->prox)->ant = aux->ant;
    free(aux);
    return true;
}

int buscar_lded(ListaDinEncadDup* lded, int x){
    if(lded == NULL || lded_vazia(lded)) return -1;
    int index=0;
    ElementoLista* aux = (*lded);
    while(aux != NULL){
        if(aux->dado.value == x) return index;
        aux = aux->prox;
        index++;
    }
    if(index == tamanho_lded(lded)) return -1;
}

bool buscar_indice_lded(ListaDinEncadDup* lded, int pos, int* x){
    if(lded == NULL || lded_vazia(lded) || pos<0 || pos>=tamanho_lded(lded)) return false;
    ElementoLista* aux = (*lded);
    while(pos>0){
        aux = aux->prox;
        pos--;
    }
    *x = aux->dado.value;
    return true;
}
