#include <stdio.h>
#include <locale.h>
#include "lista-estatica.c"

int menu();

void main (){
    setlocale(LC_ALL, "ptb");
    int escolhaMenu, aux;
    ListaEstatica* le;
    le = cria_le();
    if(le == NULL) {
        printf("Ocorreu algum erro na criação da lista! \n");
        exit(0);
    }
    do {
        escolhaMenu = menu();
        switch(escolhaMenu){
            case 1:
                printf("Informe o elemento: "); scanf("%d", &aux);
                if(inserir_le(le, aux)) printf("Elemento inserido com sucesso! \n");
                else printf("Não foi possível inserir o elemento! \n");
                if(getch()) system("cls"); break;
            case 2:
                printf("Informe o elemento: "); scanf("%d", &aux);
                if(inserir_le_inicio(le, aux))printf("Elemento inserido com sucesso! \n");
                else printf("Não foi possível inserir o elemento! \n");
                if(getch()) system("cls"); break;
            case 3:
                if(remover_le(le))printf("Elemento removido com sucesso! \n");
                else printf("Não foi possível remover o elemento! \n");
                if(getch()) system("cls"); break;
            case 4:
                if(remover_le_inicio(le))printf("Elemento removido com sucesso! \n");
                else printf("Não foi possível remover o elemento! \n");
                if(getch()) system("cls"); break;
            case 5:
                printf("Informe o elemento: "); scanf("%d", &aux);
                if(remover_le_elemento(le, aux)) printf("Elemento removido com sucesso! \n");
                else printf("Não foi possível remover o elemento! \n");
                if(getch()) system("cls"); break;
            case 6:
                printf("\n"); listar_le(le); if(getch()) system("cls"); break;
            case 7:
                printf("Informe o elemento: "); scanf("%d", &aux);
                int pos;
                if((pos = busca_seq_le(le, aux)) == -1) printf("Elemento não encontrado! \n");
                else printf("Elemento encontrado na posição = %d \n", pos);
                if(getch()) system("cls"); break;
            case 8:
                printf("Informe a posição: "); scanf("%d", &aux);
                int value;
                if(buscar_indice_le(le, aux, &value)) printf("Elemento da posição %d = %d \n", aux, value);
                else printf("Não foi possível encontrar o elemento! \n");
                if(getch()) system("cls"); break;
            case 9: break;
            default: printf("Opção inválida"); if(getch()) system("cls");
        }
    } while(escolhaMenu != 9);
    libera_le(le);
}

int menu() {
    int escolha;
    printf("======== Menu de escolha ======== \n");
    printf("[1] - Inserir no final\n");
    printf("[2] - Inserir no início\n");
    printf("[3] - Remover ultimo elemento\n");
    printf("[4] - Remover primeiro elemento\n");
    printf("[5] - Remover elemento específico\n");
    printf("[6] - Listar elementos\n");
    printf("[7] - Buscar elemento\n");
    printf("[8] - Buscar elemento pela posição\n");
    printf("[9] - Sair\n");
    printf("================================= \n");
    printf("Opção escolhida: ");
    scanf("%d", &escolha);
    return escolha;
}
