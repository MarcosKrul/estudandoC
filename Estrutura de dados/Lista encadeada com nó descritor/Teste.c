#include <stdio.h>
#include <locale.h>
#include "lista-din-encad-no.c"

int menu();

void main (){
    setlocale(LC_ALL, "ptb");
    int escolhaMenu, aux, pos;
    ListaEncadNo* len;
    len = cria_len();
    if(len == NULL) {
        printf("Ocorreu algum erro na cria��o da lista din�mica! \n");
        exit(0);
    }
    do {
        escolhaMenu = menu();
        switch(escolhaMenu){
            case 1:
                printf("Informe o elemento: "); scanf("%d", &aux);
                if(inserir_len_fim(len, aux)) printf("Elemento inserido com sucesso! \n");
                else printf("N�o foi poss�vel inserir o elemento! \n");
                if(getch()) system("cls"); break;
            case 2:
                printf("Informe o elemento: "); scanf("%d", &aux);
                if(inserir_len_inicio(len, aux))printf("Elemento inserido com sucesso! \n");
                else printf("N�o foi poss�vel inserir o elemento! \n");
                if(getch()) system("cls"); break;
            case 3:
                printf("Informe o elemento: "); scanf("%d", &aux);
                printf("Informe a posi��o: ");  scanf("%d", &pos);
                if(inserir_len_pos(len, aux, pos)) printf("Elemento inserido com sucesso! \n");
                else printf("N�o foi poss�vel inserir o elemento! \n");
                if(getch()) system("cls"); break;
            case 4:
                if(remover_len_fim(len))printf("Elemento removido com sucesso! \n");
                else printf("N�o foi poss�vel remover o elemento! \n");
                if(getch()) system("cls"); break;
            case 5:
                if(remover_len_inicio(len))printf("Elemento removido com sucesso! \n");
                else printf("N�o foi poss�vel remover o elemento! \n");
                if(getch()) system("cls"); break;
            case 6:
                printf("Informe o elemento: "); scanf("%d", &aux);
                if(remover_len_elemento(len, aux)) printf("Elemento removido com sucesso! \n");
                else printf("N�o foi poss�vel remover o elemento! \n");
                if(getch()) system("cls"); break;
            case 7:
                printf("\n"); listar_len(len); if(getch()) system("cls"); break;
            case 8:
                printf("Informe o elemento: "); scanf("%d", &aux);
                if((pos=buscar_len(len, aux)) == -1) printf("O elemento n�o foi encontrado na lista! \n");
                else printf("Elemento encontrado na posi��o %d \n", pos);
                if(getch()) system("cls"); break;
            case 9:
                printf("Informe a posi��o: "); scanf("%d", &pos);
                if(buscar_indice_len(len, pos, &aux)) printf("Elemento da posi��o %d = %d \n", pos, aux);
                else printf("N�o foi poss�vel encontrar um elemento na posi��o %d \n", pos);
                if(getch()) system("cls"); break;
            case 10:
                printf("Quantidade de itens na lista: %d\n", tamanho_len(len));
                if(getch()) system("cls"); break;
            case 11: break;
            default: printf("Op��o inv�lida"); if(getch()) system("cls");
        }
    } while(escolhaMenu != 11);
    libera_len(len);
}

int menu() {
    int escolha;
    printf("======== Menu de escolha ======== \n");
    printf("[1] - Inserir no final\n");
    printf("[2] - Inserir no in�cio\n");
    printf("[3] - Inserir em posi��o\n");
    printf("[4] - Remover ultimo elemento\n");
    printf("[5] - Remover primeiro elemento\n");
    printf("[6] - Remover elemento espec�fico\n");
    printf("[7] - Listar elementos\n");
    printf("[8] - Buscar elemento\n");
    printf("[9] - Buscar elemento pela posi��o\n");
    printf("[10] - Tamanho da lista\n");
    printf("[11] - Sair\n");
    printf("================================= \n");
    printf("Op��o escolhida: ");
    scanf("%d", &escolha);
    return escolha;
}

