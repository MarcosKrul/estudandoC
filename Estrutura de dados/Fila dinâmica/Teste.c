#include <stdio.h>
#include <locale.h>
#include "fila-dinamica.c"

int menu();

void main (){
    setlocale(LC_ALL, "ptb");
    int escolhaMenu, aux;
    FilaDinamica* fd;
    fd = cria_fd();
    if(fd == NULL) {
        printf("Ocorreu algum erro na criação da fila! \n");
        exit(0);
    }
    do {
        escolhaMenu = menu();
        switch(escolhaMenu){
            case 1:
                printf("Informe o elemento: "); scanf("%d", &aux);
                if(inserir_fd(fd, aux)) printf("Elemento inserido com sucesso! \n");
                else printf("Não foi possível inserir o elemento! \n");
                if(getch()) system("cls"); break;
            case 2:
                if(remover_fd(fd)) printf("Primeiro da fila removido com sucesso! \n");
                else printf("Não foi possível remover o elemento! \n");
                if(getch()) system("cls"); break;
            case 3:
                printf("\n");
                listar_fd(fd);
                if(getch()) system("cls"); break;
            case 4:
                if((aux = tamanho_fd(fd)) == -1) printf("Fila vazia! \n");
                else printf("Quantidade atual de elementos na fila: %d", aux);
                if(getch()) system("cls"); break;
            case 5:
                if(primeiro_fd(fd, &aux)) printf("Primeiro elemento da fila: %d", aux);
                else printf("Fila vazia! \n");
                if(getch()) system("cls"); break;
            case 6: break;
            default: printf("Opção inválida"); if(getch()) system("cls");
        }
    } while(escolhaMenu != 6);
    libera_fd(fd);
}

int menu() {
    int escolha;
    printf("======== Menu de escolha ======== \n");
    printf("[1] - Inserir novo elemento\n");
    printf("[2] - Remover elemento\n");
    printf("[3] - Listar fila\n");
    printf("[4] - Quantidade de elementos na fila\n");
    printf("[5] - Primeiro da fila\n");
    printf("[6] - Sair\n");
    printf("================================= \n");
    printf("Opção escolhida: ");
    scanf("%d", &escolha);
    return escolha;
}
