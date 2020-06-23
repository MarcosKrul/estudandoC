#include <stdio.h>
#include <locale.h>
#include "lista-circular.c"

int menu();

void main (){
    setlocale(LC_ALL, "ptb");
    int escolhaMenu, aux, pos;
    ListaCircular* lc;
    lc = cria_lc();
    if(lc == NULL) {
        printf("Ocorreu algum erro na criação da lista dinâmica! \n");
        exit(0);
    }
    do {
        escolhaMenu = menu();
        switch(escolhaMenu){
            case 1:
                printf("Informe o elemento: "); scanf("%d", &aux);
                if(inserir_lc_fim(lc, aux)) printf("Elemento inserido com sucesso! \n");
                else printf("Não foi possível inserir o elemento! \n");
                if(getch()) system("cls"); break;
            case 2:
                printf("Informe o elemento: "); scanf("%d", &aux);
                if(inserir_lc_inicio(lc, aux))printf("Elemento inserido com sucesso! \n");
                else printf("Não foi possível inserir o elemento! \n");
                if(getch()) system("cls"); break;
            case 3:
                printf("Informe o elemento: "); scanf("%d", &aux);
                printf("Informe a posição: ");  scanf("%d", &pos);
                if(inserir_lc_pos(lc, aux, pos)) printf("Elemento inserido com sucesso! \n");
                else printf("Não foi possível inserir o elemento! \n");
                if(getch()) system("cls"); break;
            case 4:
                if(remover_lc_fim(lc))printf("Elemento removido com sucesso! \n");
                else printf("Não foi possível remover o elemento! \n");
                if(getch()) system("cls"); break;
            case 5:
                if(remover_lc_inicio(lc))printf("Elemento removido com sucesso! \n");
                else printf("Não foi possível remover o elemento! \n");
                if(getch()) system("cls"); break;
            case 6:
                printf("Informe o elemento: "); scanf("%d", &aux);
                if(remover_lc_elemento(lc, aux)) printf("Elemento removido com sucesso! \n");
                else printf("Não foi possível remover o elemento! \n");
                if(getch()) system("cls"); break;
            case 7:
                printf("\n"); listar_lc(lc); if(getch()) system("cls"); break;
            case 8:
                printf("Informe o elemento: "); scanf("%d", &aux);
                if((pos=buscar_lc(lc, aux)) == -1) printf("O elemento não foi encontrado na lista! \n");
                else printf("Elemento encontrado na posição %d \n", pos);
                if(getch()) system("cls"); break;
            case 9:
                printf("Informe a posição: "); scanf("%d", &pos);
                if(busca_indice_lc(lc,pos,&aux)) printf("Elemento da posição %d = %d \n", pos, aux);
                else printf("Não foi possível encontrar um elemento na posição %d \n", pos);
                if(getch()) system("cls"); break;
            case 10:
                printf("Quantidade de itens na lista: %d\n", tamanho_lc(lc));
                if(getch()) system("cls"); break;
            case 11: break;
            default: printf("Opção inválida"); if(getch()) system("cls");
        }
    } while(escolhaMenu != 11);
    libera_lc(lc);
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

