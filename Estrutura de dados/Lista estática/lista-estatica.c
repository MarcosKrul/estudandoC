#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lista-estatica.h"

#ifdef _QNT_MAX_
struct listaEstatica_t{
    int quantidade;
    Integer dados[_QNT_MAX_];
};
#endif

ListaEstatica* cria_le(){
    ListaEstatica* lista = (ListaEstatica*) malloc(sizeof(ListaEstatica)) ;
    if(lista != NULL) lista->quantidade = 0;
    return lista;
}

void libera_le(ListaEstatica* le){
    free(le);
}

int tamanho_le(ListaEstatica* le){
    if(le == NULL) return -1;
    return le->quantidade;
}

bool le_cheia(ListaEstatica* le){
    if(le == NULL) return false;
    return (le->quantidade == _QNT_MAX_);
}

bool le_vazia(ListaEstatica* le){
    if(le == NULL) return false;
    return (le->quantidade == 0);
}

bool inserir_le(ListaEstatica* le, int x){
    if(le == NULL || le_cheia(le)) return false;
    le->dados[le->quantidade] = (Integer){.value = x};
    le->quantidade++;
    return true;
}

bool inserir_le_inicio(ListaEstatica*le, int x){
    if(le == NULL || le_cheia(le)) return false;
    int aux = tamanho_le(le);
    while(aux>=0) {
        le->dados[aux] = le->dados[aux-1];
        aux--;
    }
    le->dados[0] = (Integer){.value=x};
    le->quantidade++;
    return true;
}

bool remover_le(ListaEstatica* le){
    if(le == NULL || le_vazia(le)) return false;
    le->quantidade--;
    return true;
}

bool remover_le_inicio(ListaEstatica* le){
    if(le == NULL || le_vazia(le)) return false;
    int aux = 0;
    while(aux<tamanho_le(le)) {
        le->dados[aux] = le->dados[aux+1];
        aux++;
    }
    le->quantidade--;
    return true;
}

bool remover_le_elemento(ListaEstatica* le, int x){
    if(le == NULL || le_vazia(le)) return false;
    int i=0;
    while(i<tamanho_le(le) && x != le->dados[i].value) i++;
    if(i == tamanho_le(le)) return false;
    while(i<tamanho_le(le)) {
        le->dados[i] = le->dados[i+1];
        i++;
    }
    le->quantidade--;
    return true;
}

void listar_le(ListaEstatica* le){
    if(le == NULL) {
        printf("Não foi possível percorrer a lista! \n");
        return;
    }
    if(le_vazia(le)) {
        printf("A lista está vazia! \n");
        return;
    }
    int i;
    for(i=0 ; i<tamanho_le(le) ; i++)
        printf("[%d] - %d\n", i, le->dados[i]);
}

int busca_seq_le(ListaEstatica* le, int x){
    if(le == NULL || le_vazia(le)) return -1;
    int i;
    for(i=0 ; i<tamanho_le(le) ; i++)
        if(le->dados[i].value == x) return i;
    return -1;
}

int busca_bin_le(ListaEstatica* le, int x){
    if(le == NULL || le_vazia(le)) return -1;
    qsort(le->dados, le->quantidade, sizeof(Integer), comparaElementos);
    int baixo=0, medio, alto = tamanho_le(le);
    while(baixo<=alto){
        medio = (baixo+alto)/2;
        if(le->dados[medio].value == x) return medio;
        if(x < le->dados[medio].value) alto = medio-1;
        else baixo = medio+1;
    }
    return -1;
}

int comparaElementos(const void* p1, const void* p2){
    Integer a = *(Integer*)p1, b = *(Integer*)p2;
    if(a.value == b.value) return 0;
    return (a.value>b.value? 1: -1);
}

bool buscar_indice_le(ListaEstatica* le, int pos, int* x){
    if(le == NULL || pos<0 || pos>=tamanho_le(le) || le_vazia(le)) return false;
    *x = le->dados[pos].value;
    return true;
}
