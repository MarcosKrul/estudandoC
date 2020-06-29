#include <stdio.h>
#include <locale.h>
#include "fila-estatica.c"

int menu();

void main (){
    setlocale(LC_ALL, "ptb");
    int escolhaMenu, aux;
    FilaEstatica* fe;
    fe = cria_fe();
    if(fe == NULL) {
        printf("Ocorreu algum erro na criação da fila! \n");
        exit(0);
    }
    do {
        escolhaMenu = menu();
        switch(escolhaMenu){
            case 1:
                printf("Informe o elemento: "); scanf("%d", &aux);
                if(inserir_fe(fe, aux)) printf("Elemento inserido com sucesso! \n");
                else printf("Não foi possível inserir o elemento! \n");
                if(getch()) system("cls"); break;
            case 2:
                if(remover_fe(fe)) printf("Primeiro da fila removido com sucesso! \n");
                else printf("Não foi possível remover o elemento! \n");
                if(getch()) system("cls"); break;
            case 3:
                printf("\n");
                listar_fe(fe);
                if(getch()) system("cls"); break;
            case 4:
                if((aux = tamanho_fe(fe)) == -1) printf("Fila vazia! \n");
                else printf("Quantidade atual de elementos na fila: %d", aux);
                if(getch()) system("cls"); break;
            case 5:
                if(primeiro_fe(fe, &aux)) printf("Primeiro elemento da fila: %d", aux);
                else printf("Fila vazia! \n");
                if(getch()) system("cls"); break;
            case 6:
                no_descritor(fe);
                if(getch()) system("cls"); break;
            case 7: break;
            default: printf("Opção inválida"); if(getch()) system("cls");
        }
    } while(escolhaMenu != 7);
    libera_fe(fe);
}

int menu() {
    int escolha;
    printf("======== Menu de escolha ======== \n");
    printf("[1] - Inserir novo elemento\n");
    printf("[2] - Remover elemento\n");
    printf("[3] - Listar fila\n");
    printf("[4] - Quantidade de elementos na fila\n");
    printf("[5] - Primeiro da fila\n");
    printf("[6] - Nó descritor\n");
    printf("[7] - Sair\n");
    printf("================================= \n");
    printf("Opção escolhida: ");
    scanf("%d", &escolha);
    return escolha;
}

