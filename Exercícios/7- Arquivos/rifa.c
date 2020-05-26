   // UEPG - Universidade Estadual de Ponta Grossa \\
  // Engenharia de Computa��o, 2019                 \\
 // By Marcos Renan Krul ;)                          \\
//====================== RIFA ========================\\

#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#define __NUMRIFS__ 5          //diretiva para definir a quantidade de n�meros da rifa

struct regRifa {
    int valid;
    char name[100];
    int phone, choice, win;
}; // tam = 116 bytes

int menus(int x);
int existWinner();
int exist(int *number);
void end();
void toList();
void change();
void raffle();
void newBuyer();
void deletePurchase();
FILE* abreArquivo (char diretorio[100], char modoAbertura);

main ()
{
    setlocale(LC_ALL, "portuguese_brazil");
    int valorMenu[2];
#ifdef __NUMRIFS__
   do{
        valorMenu[0] = menus(1);
        switch(valorMenu[0]){
            case 1: newBuyer();                 if(getch()) system("cls"); break;
            case 2: toList();                   if(getch()) system("cls"); break;
            case 3: change();                   if(getch()) system("cls"); break;
            case 4: deletePurchase();           if(getch()) system("cls"); break;
            case 5: raffle();                   if(getch()) system("cls"); break;
            case 6: end();                      if(getch()) system("cls"); break;
            case 7: break;
            default: printf("Op��o inv�lida\n"); if(getch()) system("cls");
        }
    } while (valorMenu[0] != 7);
#else
    printf("DIRETIVA MACRO N�O DEFINIDA");
    exit(0);
#endif
}

int menus (int x)
{
    int awnser;
    switch (x){
        case 1:
            printf("======== Menu de escolha ========\n");
            printf("[1] - Cadastrar novo comprador\n");
            printf("[2] - Listar\n");
            printf("[3] - Alterar valores\n");
            printf("[4] - Excluir uma compra\n");
            printf("[5] - Sortear um vencedor\n");
            printf("[6] - Finalizar a edi��o\n");
            printf("[7] - Sair\n");
            printf("=================================\n");
            break;
        case 2:
            printf("\n====================================\n");
            printf("[1] - Informar o nome do comprador\n");
            printf("[2] - Informar o n�mero da compra\n");
            printf("[3] - Voltar ao menu principal\n");
            printf("====================================\n");
            break;
        case 3:
            printf("======== Alterar valores ========\n");
            printf("[1] - Alterar o nome\n");
            printf("[2] - Alterar o telefone\n");
            printf("[3] - Alterar o n�mero de compra\n");
            printf("[4] - Voltar ao menu principal\n");
            printf("=================================\n");
            break;
    }
    printf("Op��o escolhida: "); scanf("%d", &awnser);
    return awnser;
}

FILE* abreArquivo (char diretorio[100], char modoAbertura)
{
    FILE *arquivo;
    switch(modoAbertura){
        case 'r': case 'R': arquivo = fopen(diretorio, "rb");   break;
        case 'a': case 'A': arquivo = fopen(diretorio, "ab");   break;
        case 'w': case 'W': arquivo = fopen(diretorio, "wb");   break;
        case 'k': case 'K': arquivo = fopen(diretorio, "rb+");  break;
    }
    if(arquivo == NULL){
        printf("N�o foi poss�vel abrir o arquivo! \n");
        exit(0);
    } else return arquivo;
}

int exist (int *number)
{
    int logic = 1;                                        // 0 - numero j� comprado
    struct regRifa teste;                                // 1 - numero disponivel
    FILE *arq = abreArquivo("rifa.bin", 'r');
    rewind(arq);
    while(!feof(arq)){
        fread(&teste, sizeof(struct regRifa), 1, arq);
        if(*number == teste.choice && teste.valid == 1){
            logic = 0;
            break;
        }
    }
    fclose(arq);
    return logic;
}

int existWinner ()
{
    int value = 0;
    struct regRifa teste;
    FILE *arq = abreArquivo("rifa.bin", 'r');
    while(1){
        fread(&teste, sizeof(struct regRifa), 1, arq);
        if(feof(arq)) break;
        if(teste.valid == 1 && teste.win == 1) {
            value = 1;
            break;
        }
    }
    fclose(arq);
    return value;
}

void newBuyer ()
{
    struct regRifa teste;
    FILE *arq = abreArquivo("rifa.bin", 'a');
    printf("\nBem vindo � compra de rifa!\n");
    printf("O usu�rio pode comprar um n�mero entre 1 e %d\n", __NUMRIFS__);
    printf("Para verificar os n�meros dispon�veis, acesso o item '2' do menu\n\n");
    if(existWinner()) printf("Essa edi��o da rifa j� foi finalizada! \n");
    else
        do {
            printf("\nInforme o n�mero desejado pelo comprador: "); scanf("%d", &teste.choice);
            if(teste.choice == 0 || teste.choice > __NUMRIFS__) printf("N�mero n�o dispon�vel\n");
            else {
                if(exist(&teste.choice) == 1){
                    fflush(stdin);
                    printf("Informe o nome do comprador: ");        fgets(teste.name, 100, stdin);
                    printf("Informe o telefone do comprador: ");    scanf("%d", &teste.phone);
                    teste.name[strlen(teste.name)-1] = '\0';
                    teste.valid = 1; teste.win = 0;
                    fwrite(&teste, sizeof(struct regRifa), 1, arq);
                    printf("N�mero adquirido com sucesso! Boa sorte :) \n");
                    break;
                } else printf("O n�mero desejado j� foi adquirido! \n");
            }
        } while(teste.choice == 0 || teste.choice > __NUMRIFS__);
    fclose(arq);
}

void toList ()
{
    int i = 1, logic;
    struct regRifa teste;
    FILE *arq = abreArquivo("rifa.bin", 'r');
    printf("\n");
    while(i <= __NUMRIFS__){
        rewind(arq);
        logic = 0;
        while(1){
            fread(&teste, sizeof(struct regRifa), 1, arq);
            if(feof(arq)) break;
            if(teste.valid == 1 && teste.choice == i) {
                logic = 1;
                printf("[%d] - %s (Telefone: %d)\n", i, teste.name, teste.phone);
            }
        }
        if(logic == 0) printf("[%d] - \n", i);
        i += 1;
    }
    fclose(arq);
}

void change ()
{
    int pos = 0, value[2], search, logic;
    char nameSearch[100];
    struct regRifa teste;
    FILE *arq = abreArquivo("rifa.bin", 'k');
    value[0] = menus(2);
    switch(value[0]){
        case 1:
            fflush(stdin);
            printf("Informe o nome: "); fgets(nameSearch, 100, stdin);
            nameSearch[strlen(nameSearch)-1] = '\0';
            search = -1;
            break;
        case 2:
            printf("Informe o n�mero: "); scanf("%d", &search);
            strcpy(nameSearch, "NULL");
            break;
        case 3: break;
        default: printf("Op��o inv�lida! \n");
    }
    system("cls");
    rewind(arq);
    while(1){
        fread(&teste, sizeof(struct regRifa), 1, arq);
        if(feof(arq)) break;
        if(teste.valid == 1 && (search == teste.choice || strcasecmp(nameSearch, teste.name) == 0)){
            do{
                value[1] = menus(3);
                switch(value[1]){
                    case 1:
                        fflush(stdin);
                        printf("Informe o novo nome: "); fgets(teste.name, 100, stdin);
                        teste.name[strlen(teste.name)-1] = '\0';
                        if(getch()) system("cls"); break;
                    case 2:
                        printf("Informe o novo telefone: "); scanf("%d", &teste.phone);
                        if(getch()) system("cls"); break;
                    case 3:
                        printf("Informe o novo n�mero: "); scanf("%d", &logic);
                        if(exist(&logic) == 0) printf("N�mero indispon�vel!\n");
                        else teste.choice = logic;
                        if(getch()) system("cls"); break;
                    case 4: break;
                    default: printf("Op��o inv�lida! \n");
                }
            } while(value[1] != 4);
            fseek(arq, pos*sizeof(struct regRifa), SEEK_SET);
            fwrite(&teste, sizeof(struct regRifa), 1, arq);
            printf("Registro atualizado com sucesso! \n");
            break;
        } else pos += 1;
    }
    fseek(arq, sizeof(struct regRifa), SEEK_END);
    if(pos == ftell(arq)/sizeof(struct regRifa)-1) printf("Comprador n�o encontrado! \n");
    fclose(arq);
}

void deletePurchase ()
{
    int pos = 0, search, logic, value = menus(2);
    char nameSearch[100];
    struct regRifa teste;
    FILE *arq = abreArquivo("rifa.bin", 'k');
    printf("\n");
    switch(value){
        case 1:
            fflush(stdin);
            printf("Informe o nome: "); fgets(nameSearch, 100, stdin);
            nameSearch[strlen(nameSearch)-1] = '\0';
            break;
        case 2:
            printf("Informe o n�mero: "); scanf("%d", &search);
            break;
        case 3: break;
        default: printf("Op��o inv�lida\n");
    }
    if(value != 3) {
        while(!feof(arq)){
            fread(&teste, sizeof(struct regRifa), 1, arq);
            if((teste.choice == search || strcasecmp(nameSearch, teste.name) == 0) && teste.valid == 1){
                printf("Deseja mesmo excluir esse comprador? [1-sim / 0-n�o]"); scanf("%d", &logic);
                if(logic == 1){
                    teste.valid = 0;
                    fseek(arq, pos*sizeof(struct regRifa), SEEK_SET);
                    fwrite(&teste, sizeof(struct regRifa), 1, arq);
                    printf("Comprador exclu�do com sucesso! \n");
                    break;
                } else break;
            } else pos += 1;
        }
        fseek(arq, sizeof(struct regRifa), SEEK_END);
        if(ftell(arq)/sizeof(struct regRifa) == pos) printf("Comprador n�o encontrado ou n�mero dipon�vel\n");
    }
    fclose(arq);
}

void raffle ()
{
    int logic = 0, winner, soma;
    struct regRifa teste;
    FILE *arq = abreArquivo("rifa.bin", 'k');
    srand((unsigned)time(NULL));
    rewind(arq);
    while(!feof(arq)){
        fread(&teste, sizeof(struct regRifa), 1, arq);
        if(teste.valid == 1 && teste.win == 1) {
            logic = 1;
            printf("\nJ� h� um ganhador dessa edi��o da rifa! \n");
            printf("N�mero sorteado: %d\n", teste.choice);
            printf("Ganhador(a): %s\n", teste.name);
            printf("Telefone para contato: %d\n", teste.phone);
            break;
        }
    }
    while(logic == 0) {
        printf("\nSorteando um n�mero "); Sleep(1000); printf("."); Sleep(1000); printf("."); Sleep(1000); printf(".\n");
        Sleep(3000);
        winner = rand()% __NUMRIFS__ + 1;
        rewind(arq);
        soma = 0;
        while(1){
            fread(&teste, sizeof(struct regRifa), 1, arq);
            if(feof(arq)) break;
            if(teste.valid == 1 && teste.choice == winner){
                teste.win = 1;
                printf("\nTemos um ganhador(a) :)\n");
                printf("N�mero sorteado: %d\n", winner);
                printf("Nome do sorteado(a): %s\n", teste.name);
                printf("Telefone para contato: %d\n", teste.phone);
                fseek(arq, soma*sizeof(struct regRifa), SEEK_SET);
                fwrite(&teste, sizeof(struct regRifa), 1, arq);
                logic = 1;
                break;
            } else soma += 1;
        }
        if(logic == 0) {
            printf("O n�mero sorteado foi %d e n�o h� comprador registrado para o mesmo! \n", winner);
            printf("Um novo n�mero ser� sorteado\n");
            Sleep(3000);
        }
    }
    fclose(arq);
}

void end ()
{
    struct regRifa teste;
    FILE *arq = abreArquivo("rifa.bin", 'r');
    FILE *p = abreArquivo("regsRifa_'EDICAO_RIFA'.bin", 'w');
    printf("\nEncerramento da rifa!\n");
    printf("Os registros dos compradores ser�o armazenados em um arquivo backup\n");
    printf("O arquivo ser� nomeado como: regsRifa_'EDI��O_RIFA'\n");
    printf("A edi��o da rifa deve ser alterada manualmente pelo usu�rio!\n\n");
    printf("Trabalhando nisso ...\n"); Sleep(3000);
    while(1){
        fread(&teste, sizeof(struct regRifa), 1, arq);
        if(feof(arq)) break;
        if(teste.valid == 1) fwrite(&teste, sizeof(struct regRifa), 1, p);
    }
    printf("Edi��o finalizada com sucesso!! \n");
    fclose(arq); fclose(p);
    remove("rifa.bin");
}
