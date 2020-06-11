#include <stdio.h>
#include <locale.h>
#include "lista-din-encad.c"

int menu();

void main (){
    setlocale(LC_ALL, "ptb");
    int escolhaMenu, aux;
    ListaDinEncad* lde;
    lde = cria_lde();
    if(lde == NULL) {
        printf("Ocorreu algum erro na cria��o da lista din�mica! \n");
        exit(0);
    }
    do {
        escolhaMenu = menu();
        switch(escolhaMenu){
            case 1:
                printf("Informe o elemento: "); scanf("%d", &aux);
                if(inserir_lde_fim(lde, aux)) printf("Elemento inserido com sucesso! \n");
                else printf("N�o foi poss�vel inserir o elemento! \n");
                if(getch()) system("cls"); break;
            case 2:
                printf("Informe o elemento: "); scanf("%d", &aux);
                if(inserir_lde_inicio(lde, aux))printf("Elemento inserido com sucesso! \n");
                else printf("N�o foi poss�vel inserir o elemento! \n");
                if(getch()) system("cls"); break;
            case 3:
                if(remover_lde_fim(lde))printf("Elemento removido com sucesso! \n");
                else printf("N�o foi poss�vel remover o elemento! \n");
                if(getch()) system("cls"); break;
            case 4:
                if(remover_lde_inicio(lde))printf("Elemento removido com sucesso! \n");
                else printf("N�o foi poss�vel remover o elemento! \n");
                if(getch()) system("cls"); break;
            case 5:
                printf("Informe o elemento: "); scanf("%d", &aux);
                if(remover_lde_elemento(lde, aux)) printf("Elemento removido com sucesso! \n");
                else printf("N�o foi poss�vel remover o elemento! \n");
                if(getch()) system("cls"); break;
            case 6:
                printf("\n"); listar_lde(lde); if(getch()) system("cls"); break;
            case 7:
                printf("Informe o elemento: "); scanf("%d", &aux);
                int pos;
                if((pos=buscar_lde(lde, aux)) == -1) printf("O elemento n�o foi encontrado na lista! \n");
                else printf("Elemento encontrado na posi��o %d \n", pos);
                if(getch()) system("cls"); break;
            case 8:
                printf("Informe a posi��o: "); scanf("%d", &aux);
                int value;
                if(buscar_indice_lde(lde, aux, &value)) printf("Elemento da posi��o %d = %d \n", aux, value);
                else printf("N�o foi poss�vel encontrar um elemento na posi��o %d \n", aux);
                if(getch()) system("cls"); break;
            case 9:
                printf("Quantidade de itens na lista: %d\n", tamanho_lde(lde));
                if(getch()) system("cls"); break;
            case 10: break;
            default: printf("Op��o inv�lida"); if(getch()) system("cls");
        }
    } while(escolhaMenu != 10);
    libera_lde(lde);
}

int menu() {
    int escolha;
    printf("======== Menu de escolha ======== \n");
    printf("[1] - Inserir no final\n");
    printf("[2] - Inserir no in�cio\n");
    printf("[3] - Remover ultimo elemento\n");
    printf("[4] - Remover primeiro elemento\n");
    printf("[5] - Remover elemento espec�fico\n");
    printf("[6] - Listar elementos\n");
    printf("[7] - Buscar elemento\n");
    printf("[8] - Buscar elemento pela posi��o\n");
    printf("[9] - Tamanho da lista\n");
    printf("[10] - Sair\n");
    printf("================================= \n");
    printf("Op��o escolhida: ");
    scanf("%d", &escolha);
    return escolha;
}

