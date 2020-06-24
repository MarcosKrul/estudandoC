#include <stdio.h>
#include <stdbool.h>
#include "lista-din-encad-no.h"


typedef struct listaDinEncad_t {
    struct listaDinEncad_t* prox;
    Integer dado;
} ElementoLista;


struct noDescritor_t{
    struct listaDinEncad_t* primeiro;
    struct listaDinEncad_t* ultimo;
    int qnt;
};


ListaEncadNo* cria_len(){
    ListaEncadNo* len = (ListaEncadNo*) malloc(sizeof(ListaEncadNo));
    if(len != NULL){
        len->primeiro = NULL;
        len->ultimo = NULL;
        len->qnt = 0;
    }
    return len;
}

void libera_len(ListaEncadNo* len){
    if(len == NULL) return;
    ElementoLista* aux;
    while(len->primeiro != NULL){
        aux = len->primeiro;
        len->primeiro = (len->primeiro)->prox;
        free(aux);
    }
    free(len);
}

int tamanho_len(ListaEncadNo* len){
    if(len == NULL) return 0;
    return len->qnt;
}

bool len_vazia(ListaEncadNo* len){
    if(len == NULL || len->primeiro == NULL) return true;
    return false;
}

void listar_len(ListaEncadNo* len){
    if(len == NULL) return;
    if(len_vazia(len)){
        printf("A lista está vazia! \n");
        return;
    }
    ElementoLista* aux = len->primeiro;
    for(int i=0 ; i<len->qnt ; i++){
        printf("[%d] - %d \n", i, aux->dado.value);
        aux = aux->prox;
    }
}

bool inserir_len_inicio(ListaEncadNo* len, int x){
    if(len == NULL) return false;
    ElementoLista* elemento = (ElementoLista*) malloc(sizeof(ElementoLista));
    if(elemento == NULL) return false;
    elemento->dado = (Integer){.value=x};
    elemento->prox = len->primeiro;
    len->primeiro = elemento;
    if(len->qnt == 0) len->ultimo = elemento;
    len->qnt++;
    return true;
}

bool inserir_len_fim(ListaEncadNo* len, int x){
    if(len == NULL) return false;
    if(len->qnt == 0) return inserir_len_inicio(len, x);
    ElementoLista* elemento = (ElementoLista*) malloc(sizeof(ElementoLista));
    if(elemento == NULL) return false;
    elemento->dado = (Integer){.value=x};
    elemento->prox = NULL;
    (len->ultimo)->prox = elemento;
    len->ultimo = elemento;
    len->qnt++;
    return true;
}

bool inserir_len_pos(ListaEncadNo* len, int x, int pos){
    if(len == NULL || pos<0 || pos>tamanho_len(len)) return false;
    if(pos == 0) return inserir_len_inicio(len, x);
    if(pos == len->qnt) return inserir_len_fim(len, x);
    ElementoLista* elemento = (ElementoLista*) malloc(sizeof(ElementoLista));
    if(elemento == NULL) return false;
    elemento->dado = (Integer){.value=x};
    ElementoLista* aux = len->primeiro;
    while((pos-1)>0){
        aux = aux->prox;
        pos--;
    }
    elemento->prox = aux->prox;
    aux->prox = elemento;
    len->qnt++;
    return true;
}

bool remover_len_inicio(ListaEncadNo* len){
    if(len == NULL || len->qnt == 0) return false;
    ElementoLista* aux = len->primeiro;
    len->primeiro = (len->primeiro)->prox;
    if(len->qnt == 1) len->ultimo = NULL;
    len->qnt--;
    free(aux);
    return true;
}

bool remover_len_fim(ListaEncadNo* len){
    if(len == NULL || len->qnt == 0) return false;
    if(len->qnt == 1) return remover_len_inicio(len);
    ElementoLista* aux = len->primeiro, *penultimo;
    while(aux->prox != NULL){
        penultimo = aux;
        aux = aux->prox;
    }
    penultimo->prox = NULL;
    len->ultimo = penultimo;
    len->qnt--;
    free(aux);
    return true;
}

bool remover_len_elemento(ListaEncadNo* len, int x){
    if(len == NULL || len->qnt == 0) return false;
    ElementoLista* aux = len->primeiro, *anterior;
    while(aux != NULL && x != aux->dado.value){
        anterior = aux;
        aux = aux->prox;
    }
    if(aux == NULL) return false;
    if(aux == len->primeiro) return remover_len_inicio(len);
    if(aux->prox == NULL) return remover_len_fim(len);
    anterior->prox = aux->prox;
    free(aux);
    len->qnt--;
    return true;
}

bool buscar_indice_len(ListaEncadNo* len, int pos, int* x){
    if(len == NULL || pos<0 || pos>=len->qnt || len->qnt == 0) return false;
    ElementoLista* aux = len->primeiro;
    while(pos>0){
        aux = aux->prox;
        pos--;
    }
    *x = aux->dado.value;
    return true;
}

int buscar_len(ListaEncadNo* len, int x){
    if(len == NULL || len->qnt == 0) return -1;
    int index=0;
    ElementoLista* aux = len->primeiro;
    while(aux != NULL){
        if(aux->dado.value == x) return index;
        aux = aux->prox;
        index++;
    }
    if(index == len->qnt) return -1;
}








