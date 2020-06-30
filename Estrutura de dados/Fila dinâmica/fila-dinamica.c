#include <stdbool.h>
#include <stdlib.h>
#include "fila-dinamica.h"


typedef struct filaDinamica_t{
    struct filaDinamica_t* prox;
    Integer dado;
} ElementoFila;

struct noDescritor_t {
    struct filaDinamica_t* primeiro;
    struct filaDinamica_t* ultimo;
    int qnt;
};


FilaDinamica* cria_fd(){
    FilaDinamica* fd = (FilaDinamica*) malloc(sizeof(FilaDinamica));
    if(fd != NULL){
        fd->primeiro = NULL;
        fd->ultimo = NULL;
        fd->qnt = 0;
    }
    return fd;
}

void libera_fd(FilaDinamica* fd){
    if(fd == NULL) return;
    ElementoFila* aux;
    while(fd->primeiro != NULL){
        aux = fd->primeiro;
        fd->primeiro = (fd->primeiro)->prox;
        free(aux);
    }
    free(fd);
}

bool fd_vazia(FilaDinamica* fd){
    if(fd == NULL || fd->qnt == 0) return true;
    return false;
}

int tamanho_fd(FilaDinamica* fd){
    if(fd == NULL) return -1;
    return fd->qnt;
}

bool primeiro_fd(FilaDinamica* fd, int* x){
    if(fd_vazia(fd)) return false;
    *x = (fd->primeiro)->dado.value;
    return true;
}

bool inserir_fd(FilaDinamica* fd, int x){
    if(fd == NULL) return false;
    ElementoFila* elemento = (ElementoFila*) malloc(sizeof(ElementoFila));
    if(elemento == NULL) return false;
    elemento->dado = (Integer){.value=x};
    elemento->prox = NULL;
    if(fd->qnt == 0) fd->primeiro = elemento;
    else (fd->ultimo)->prox = elemento;
    fd->ultimo = elemento;
    fd->qnt++;
    return true;
}

bool remover_fd(FilaDinamica* fd){
    if(fd_vazia(fd)) return false;
    ElementoFila* aux = fd->primeiro;
    fd->primeiro = (fd->primeiro)->prox;
    if(fd->primeiro == NULL) fd->ultimo = NULL;
    free(aux);
    fd->qnt--;
    return true;
}

void listar_fd(FilaDinamica* fd){
    if(fd_vazia(fd)) {
        printf("A fila está vazia! \n");
        return;
    }
    ElementoFila* aux = fd->primeiro;
    for(int i=0 ; i<tamanho_fd(fd) ; i++){
        printf("[%d] - %d \n", i, aux->dado.value);
        aux = aux->prox;
    }
}

