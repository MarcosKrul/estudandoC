#include <stdbool.h>
#include <stdlib.h>
#include "fila-estatica.h"

#ifndef TAM
    #define TAM 0
#endif

struct filaEstatica_t {
    int primeiro;
    int ultimo;
    int qnt;
    Integer dados[TAM];
};


FilaEstatica* cria_fe(){
    FilaEstatica* fe = (FilaEstatica*) malloc(sizeof(FilaEstatica));
    if(fe != NULL){
        fe->primeiro = 0;
        fe->ultimo = 0;
        fe->qnt = 0;
    }
    return fe;
}

void libera_fe(FilaEstatica* fe){
    free(fe);
}

bool fe_vazia(FilaEstatica* fe){
    if(fe == NULL) return false;
    return (fe->qnt == 0);
}

bool fe_cheia(FilaEstatica* fe){
    if(fe == NULL) return false;
    return (fe->qnt == TAM);
}

int tamanho_fe(FilaEstatica* fe){
    if(fe == NULL) return -1;
    return fe->qnt;
}

bool inserir_fe(FilaEstatica* fe, int x){
    if(fe == NULL || fe_cheia(fe)) return false;
    fe->dados[fe->ultimo] = (Integer){.value=x};
    if((fe->ultimo += 1) == TAM) fe->ultimo = 0;
    fe->qnt++;
    return true;
}

bool remover_fe(FilaEstatica* fe){
    if(fe == NULL || fe_vazia(fe)) return false;
    if((fe->primeiro += 1) == TAM) fe->primeiro = 0;
    fe->qnt--;
    return true;
}

bool primeiro_fe(FilaEstatica* fe, int* x){
    if(fe == NULL  || fe_vazia(fe)) return false;
    *x = fe->dados[fe->primeiro].value;
    return true;
}

void listar_fe(FilaEstatica* fe){
    if(fe_vazia(fe)){
        printf("A fila está vazia! \n");
        return;
    }
    int j=fe->primeiro;
    for(int i=0 ; i<tamanho_fe(fe) ; i++){
        printf("[%d] - %d \n", i, fe->dados[j].value);
        if(j == TAM-1) j = 0;
        else j++;
    }
}

void no_descritor(FilaEstatica* fe){
    if(fe == NULL) return;
    printf("Primeiro: %d \n", fe->primeiro);
    printf("Último: %d \n", fe->ultimo);
    printf("Quantidade: %d \n", fe->qnt);
}

