#include <stdio.h>
#include <locale.h>
#include "pilha-estatica.c"

int menu();

void main (){
    setlocale(LC_ALL, "ptb");
    int escolhaMenu, aux;
    PilhaEstatica* pe;
    pe = cria_pe();
    if(pe == NULL) {
        printf("Ocorreu algum erro na criação da pilha! \n");
        exit(0);
    }
    do {
        escolhaMenu = menu();
        switch(escolhaMenu){
            case 1:
                printf("Informe o elemento: "); scanf("%d", &aux);
                if(inserir_pe(pe, aux)) printf("Elemento inserido com sucesso! \n");
                else printf("Não foi possível inserir o elemento! \n");
                if(getch()) system("cls"); break;
            case 2:
                if(remover_pe(pe)) printf("Primeiro da pilha removido com sucesso! \n");
                else printf("Não foi possível remover o elemento! \n");
                if(getch()) system("cls"); break;
            case 3:
                printf("\n");
                listar_pe(pe);
                if(getch()) system("cls"); break;
            case 4:
                if((aux = tamanho_pe(pe)) == -1) printf("Pilha vazia! \n");
                else printf("Quantidade atual de elementos na pilha: %d", aux);
                if(getch()) system("cls"); break;
            case 5:
                if(topo_pe(pe, &aux)) printf("Primeiro elemento da pilha: %d", aux);
                else printf("Fila vazia! \n");
                if(getch()) system("cls"); break;
            case 6: break;
            default: printf("Opção inválida"); if(getch()) system("cls");
        }
    } while(escolhaMenu != 6);
    libera_pe(pe);
}

int menu() {
    int escolha;
    printf("======== Menu de escolha ======== \n");
    printf("[1] - Inserir novo elemento\n");
    printf("[2] - Remover elemento\n");
    printf("[3] - Mostrar pilha\n");
    printf("[4] - Quantidade de elementos na pilha\n");
    printf("[5] - Primeiro da pilha\n");
    printf("[6] - Sair\n");
    printf("================================= \n");
    printf("Opção escolhida: ");
    scanf("%d", &escolha);
    return escolha;
}

