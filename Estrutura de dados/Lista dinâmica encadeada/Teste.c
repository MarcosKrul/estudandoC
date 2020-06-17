#include <stdio.h>
#include <locale.h>
#include "lista-din-encad.c"

int menu();

void main (){
    setlocale(LC_ALL, "ptb");
    int escolhaMenu, aux, pos;
    ListaDinEncad* lde;
    lde = cria_lde();
    if(lde == NULL) {
        printf("Ocorreu algum erro na criação da lista dinâmica! \n");
        exit(0);
    }
    do {
        escolhaMenu = menu();
        switch(escolhaMenu){
            case 1:
                printf("Informe o elemento: "); scanf("%d", &aux);
                if(inserir_lde_fim(lde, aux)) printf("Elemento inserido com sucesso! \n");
                else printf("Não foi possível inserir o elemento! \n");
                if(getch()) system("cls"); break;
            case 2:
                printf("Informe o elemento: "); scanf("%d", &aux);
                if(inserir_lde_inicio(lde, aux))printf("Elemento inserido com sucesso! \n");
                else printf("Não foi possível inserir o elemento! \n");
                if(getch()) system("cls"); break;
            case 3:
                printf("Informe o elemento: "); scanf("%d", &aux);
                printf("Informe a posição: ");  scanf("%d", &pos);
                if(inserir_lde_pos(lde, aux, pos)) printf("Elemento inserido com sucesso! \n");
                else printf("Não foi possível inserir o elemento! \n");
                if(getch()) system("cls"); break;
            case 4:
                if(remover_lde_fim(lde))printf("Elemento removido com sucesso! \n");
                else printf("Não foi possível remover o elemento! \n");
                if(getch()) system("cls"); break;
            case 5:
                if(remover_lde_inicio(lde))printf("Elemento removido com sucesso! \n");
                else printf("Não foi possível remover o elemento! \n");
                if(getch()) system("cls"); break;
            case 6:
                printf("Informe o elemento: "); scanf("%d", &aux);
                if(remover_lde_elemento(lde, aux)) printf("Elemento removido com sucesso! \n");
                else printf("Não foi possível remover o elemento! \n");
                if(getch()) system("cls"); break;
            case 7:
                printf("\n"); listar_lde(lde); if(getch()) system("cls"); break;
            case 8:
                printf("Informe o elemento: "); scanf("%d", &aux);
                if((pos=buscar_lde(lde, aux)) == -1) printf("O elemento não foi encontrado na lista! \n");
                else printf("Elemento encontrado na posição %d \n", pos);
                if(getch()) system("cls"); break;
            case 9:
                printf("Informe a posição: "); scanf("%d", &aux);
                int value;
                if(buscar_indice_lde(lde, aux, &value)) printf("Elemento da posição %d = %d \n", aux, value);
                else printf("Não foi possível encontrar um elemento na posição %d \n", aux);
                if(getch()) system("cls"); break;
            case 10:
                printf("Quantidade de itens na lista: %d\n", tamanho_lde(lde));
                if(getch()) system("cls"); break;
            case 11: break;
            default: printf("Opção inválida"); if(getch()) system("cls");
        }
    } while(escolhaMenu != 11);
    libera_lde(lde);
}

int menu() {
    int escolha;
    printf("======== Menu de escolha ======== \n");
    printf("[1] - Inserir no final\n");
    printf("[2] - Inserir no início\n");
    printf("[3] - Inserir em posição\n");
    printf("[4] - Remover ultimo elemento\n");
    printf("[5] - Remover primeiro elemento\n");
    printf("[6] - Remover elemento específico\n");
    printf("[7] - Listar elementos\n");
    printf("[8] - Buscar elemento\n");
    printf("[9] - Buscar elemento pela posição\n");
    printf("[10] - Tamanho da lista\n");
    printf("[11] - Sair\n");
    printf("================================= \n");
    printf("Opção escolhida: ");
    scanf("%d", &escolha);
    return escolha;
}

