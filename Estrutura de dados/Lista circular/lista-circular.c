#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista-circular.h"

typedef struct listaCircular_t{
    struct listaCircular_t* prox;
    Integer dado;
} ElementoLista;


ListaCircular* cria_lc(){
    ListaCircular* lc = (ListaCircular*) malloc(sizeof(ListaCircular));
    if(lc != NULL)
        (*lc) = NULL;
    return lc;
}

bool lc_vazia(ListaCircular* lc){
    if(lc == NULL || (*lc) == NULL) return true;
    return false;
}

void libera_lc(ListaCircular* lc){
    if(!lc_vazia(lc)){
        ElementoLista* aux = (*lc), *aux_liberar;
        while(aux->prox != (*lc)){
            aux_liberar = aux;
            aux = aux->prox;
            free(aux_liberar);
        }
        free(aux);
    }
    free(lc);
}

int tamanho_lc(ListaCircular* lc){
    if(lc_vazia(lc)) return 0;
    int soma=0;
    ElementoLista* aux = (*lc);
    while(aux->prox != (*lc)){
        aux = aux->prox;
        soma++;
    }
    return (soma+1);
}

bool inserir_lc_inicio(ListaCircular* lc, int x){
    if(lc == NULL) return false;
    ElementoLista* elemento = (ElementoLista*) malloc(sizeof(ElementoLista));
    if(elemento == NULL) return false;
    elemento->dado = (Integer){.value=x};
    if(lc_vazia(lc)) {
        (*lc) = elemento;
        elemento->prox = elemento;
        return true;
    }
    ElementoLista* aux = (*lc);
    elemento->prox = aux;
    while(aux->prox != (*lc)) aux = aux->prox;
    aux->prox = elemento;
    (*lc) = elemento;
    return true;
}

bool inserir_lc_fim(ListaCircular* lc, int x){
    if(lc_vazia(lc)) return inserir_lc_inicio(lc, x);
    if(lc == NULL) return false;
    ElementoLista* elemento = (ElementoLista*) malloc(sizeof(ElementoLista));
    if(elemento == NULL) return false;
    elemento->dado = (Integer){.value=x};
    ElementoLista* aux = (*lc);
    elemento->prox = aux;
    while(aux->prox != (*lc)) aux = aux->prox;
    aux->prox = elemento;
    return true;
}

bool inserir_lc_pos(ListaCircular* lc, int x, int pos){
    if(pos == 0 || lc_vazia(lc)) return inserir_lc_inicio(lc, x);
    if(pos == tamanho_lc(lc)) return inserir_lc_fim(lc, x);
    if(lc == NULL || pos<0 || pos>tamanho_lc(lc)) return false;
    ElementoLista* elemento = (ElementoLista*) malloc(sizeof(ElementoLista));
    if(elemento == NULL) return false;
    elemento->dado = (Integer){.value=x};
    ElementoLista* aux = (*lc);
    for(int i=0 ; i<tamanho_lc(lc) ; i++){
        if(i == pos-1){
            elemento->prox = aux->prox;
            aux->prox = elemento;
        } else aux = aux->prox;
    }
    return true;
}

void listar_lc(ListaCircular* lc){
    if(lc == NULL) return;
    if(lc_vazia(lc)) {
        printf("A lista está vazia! \n");
        return;
    }
    int i=0;
    ElementoLista* aux = (*lc);
    do {
        printf("[%d] = %d \n", i, aux->dado.value);
        i++;
    } while((aux = aux->prox) != (*lc));
}

bool remover_lc_inicio(ListaCircular* lc){
    if(lc_vazia(lc)) return false;
    ElementoLista* primeiro = (*lc);
    if(tamanho_lc(lc) == 1) (*lc) = NULL;
    else {
        ElementoLista* aux = (*lc);
        while(aux->prox != (*lc)) aux = aux->prox;
        aux->prox = primeiro->prox;
        (*lc) = primeiro->prox;
    }
    free(primeiro);
}

bool remover_lc_fim(ListaCircular* lc){
    if(lc_vazia(lc)) return false;
    if(tamanho_lc(lc) == 1) return remover_lc_inicio(lc);
    ElementoLista* aux = (*lc), *penultimo;
    while(aux->prox != (*lc)) {
        penultimo = aux;
        aux = aux->prox;
    }
    penultimo->prox = aux->prox;
    free(aux);
    return true;
}

bool remover_lc_elemento(ListaCircular* lc, int x){
    if(lc_vazia(lc)) return false;
    ElementoLista* aux = (*lc), *anterior;
    while(aux->prox != (*lc) && x != aux->dado.value){
        anterior = aux;
        aux = aux->prox;
    }
    if(x != aux->dado.value) return false;
    if(aux == (*lc)) return remover_lc_inicio(lc);
    if(aux->prox == (*lc)) return remover_lc_fim(lc);
    anterior->prox = aux->prox;
    free(aux);
    return true;
}

int buscar_lc(ListaCircular* lc, int x){
    if(lc_vazia(lc)) return -1;
    ElementoLista* aux = (*lc);
    int index=0;
    do {
        if(aux->dado.value == x) return index;
        index++;
        aux = aux->prox;
    } while(aux != (*lc));
    return -1;
}

bool busca_indice_lc(ListaCircular* lc, int pos, int* x){
    if(lc_vazia(lc) || pos<0 || pos>=tamanho_lc(lc)) return false;
    ElementoLista* aux = (*lc);
    while(pos>0){
        aux = aux->prox;
        pos--;
    }
    *x = aux->dado.value;
    return true;
}
