#include <locale.h>
#include "lista-din-encad.c"


void main() {
    setlocale(LC_ALL, "ptb");
    int aux=0;
    ListaDinEncad* lde = cria_lde();
    if(lde == NULL) exit(0);
    while(aux!=-1) {
        printf("Elemento para inserir na lista: [-1 para sair] ");
        scanf("%d", &aux);
        if(aux!=-1) inserir_lde_fim(lde, aux);
    }

    int i, tam = tamanho_lde(lde);
    int* vet = (int*) malloc(tam*sizeof(int));
    if(ldeToArray(lde, vet)) {
        printf("Lista convertida em array! \n");
        libera_lde(lde);
    }else {
        printf("Não foi possível converter a lista em array! \n");
        libera_lde(lde);
        exit(0);
    }

    printf("Array: \n");
    for(i=0 ; i<tam ; i++) printf("[%d] - %d \n", i, vet[i]);

    if((lde = arrayToLde(tam, vet)) != NULL) printf("\nArray convertido em lista! \n");
    else {
        printf("Não foi possível converter o array em lista! \n");
        free(vet);
        exit(0);
    }
    free(vet);
    listar_lde(lde);
    libera_lde(lde);
}
