   //Universidade Estadual de Ponta Grossa(UEPG) \\
  // Engenharia de Computação, 2019               \\
 // Algoritmos e programação                       \\
// By Marcos Renan Krul                             \\
/*=============== AGENDA ELETRÔNICA =============== */

#include <stdio.h>
#include <locale.h>
#include <string.h>

struct regAgenda {

    int phone, valid;
    char name[100];
};

void desenha(int x, int y);
void menus(int y);
void cadastra();
void limpaBuffer();
void listarContatos();
void busca(int y);
void alterarValores();
void exclusao();
void reorganizar();
void lixeira();
int existente(char *name, int *telefone);

main ()
{
    setlocale(LC_ALL, "portuguese_brazil");
    int resposta, valorMenu;
    do{
        menus(1);
        printf("\nOpção escolhida: "); scanf("%d", &resposta);
        switch(resposta){
            case 1: cadastra();                  if(getch()) system("cls"); break;
            case 2: listarContatos();            if(getch()) system("cls"); break;
            case 3: buscar(3);                   if(getch()) system("cls"); break;
            case 4: buscar(4);                   if(getch()) system("cls"); break;
            case 5: alterarValores();            if(getch()) system("cls"); break;
            case 6: exclusao();                  if(getch()) system("cls"); break;
            case 7: lixeira();                   if(getch()) system("cls"); break;
            case 8: reorganizar();               if(getch()) system("cls"); break;
            case 9:                                                         break;
        default: printf("Opção inválida\n"); 	 if(getch()) system("cls"); break;
        }
    } while (resposta != 9);
}
void desenha (int x, int y)
{
    int i;
    if (y==1) for(i=0 ; i<x ; i++) printf("-");
    if (y==2) for(i=0 ; i<x ; i++) printf(" ");
}
void menus (int y)
{
    if(y == 1){
        desenha(5, 1); printf("Menu de escolha"); desenha(5, 1);
        printf("\n[1] - Cadastro\n");
        printf("[2] - Consultar\n");
        printf("[3] - Buscar por nome\n");
        printf("[4] - Buscar por número\n");
        printf("[5] - Alterar valores\n");
        printf("[6] - Excluir contato\n");
        printf("[7] - Recuperar contato\n");
        printf("[8] - Organizar arquivo\n");
        printf("[9] - Sair\n");
        desenha((2*5 + strlen("Menu de escolha")), 1);
    }
    if(y == 2){
        desenha(30, 1);
        printf("\n[1] - Alterar nome do contato\n");
        printf("[2] - Alterar telefone do contato\n");
        printf("[3] - Voltar ao menu principal\n");
        desenha(30, 1);
    }
    if(y == 3){
        desenha(50, 1);
        printf("\n[1] - Informar o nome para exclusão do contato\n");
        printf("[2] - Informar o telefone para exclusão do contato\n");
        printf("[3] - Voltar ao menu principal\n");
        desenha(50, 1);
    }
    if(y == 4){
        desenha(50, 1);
        printf("\nCaro Usuário!\nA recuperação de um contato não é um processo garantido.\n");
        printf("Caso o sistema tenha passado por um processo de organização, todos os\ncontatos excluídos foram, definitivamente, excluídos!\n");
        printf("\n[1] - Informar o nome para recuperação do contato\n");
        printf("[2] - Informar o telefone para recuperação do contato\n");
        printf("[3] - Listar contatos excluídos\n");
        printf("[4] - Voltar ao menu principal\n");
        desenha(50, 1);
    }
}

void limpaBuffer ()
{
    char x;
    while((x = getchar() != '\n') && (x != EOF));
}

int existente (char *nome, int *telefone)
{
    int logic = 0;
    struct regAgenda teste;
    FILE *arq;
    arq = fopen("agendaV2.bin", "rb"); rewind(arq);
    while(!feof(arq) && logic == 0){
        fread(&teste, sizeof(struct regAgenda), 1, arq);
        if(strcmp(nome, teste.name) == 0 && teste.valid == 1) logic = 1;
        if(*telefone == teste.phone && teste.valid == 1)      logic = 2;
    }
    return logic;
    fclose(arq);
}

void cadastra ()
{
    struct regAgenda teste;
    FILE *arq;
    arq = fopen("agendaV2.bin", "ab");
    if(arq == NULL) {
        printf("Não foi possível abrir o arquivo! \n");
        exit(0);
    } else {
        limpaBuffer();
        printf("Informe o nome do contato: ");      fgets(teste.name, sizeof(teste.name), stdin);
        printf("Informe o telefone do contato: ");  scanf("%d", &teste.phone);
        teste.valid = 1;
        switch(existente(&teste.name, &teste.phone)){
            case 0:
                fwrite(&teste, sizeof(struct regAgenda), 1, arq);
                printf("Contato salvo com sucesso!\n");
                break;
            case 1:
                printf("Nome do contato já existente!\n");
                break;
            case 2:
                printf("Telefone do contato já existente!\n");
                break;
        }
    }
    fclose(arq);
}

void listarContatos ()
{
    struct regAgenda teste;
    FILE *arq;
    arq = fopen("agendaV2.bin", "rb"); rewind(arq);
    if(arq == NULL){
        printf("Não foi possível abrir o arquivo! \n");
        exit(0);
    } else {
        printf("Nome"); desenha((30-strlen("Nome")), 2); printf("Telefone\n");
        while(1){
            fread(&teste, sizeof(struct regAgenda), 1, arq);
            teste.name[strlen(teste.name)-1] = '\0';
            if(feof(arq)) break;
            if(teste.valid == 1){
                    printf("%s", teste.name); desenha((30-strlen(teste.name)), 2); printf("%d\n", teste.phone);
            }
        }
    }
    fclose(arq);
}

void buscar(int y)
{
    struct regAgenda teste;
    char buscaNome[100];
    int i=0, logic=0, buscaTelefone;
    FILE *arq;
    arq = fopen("agendaV2.bin", "rb"); rewind(arq);
    if(arq == NULL){
        printf("Não foi possível abrir o arquivo! \n");
        exit(0);
    } else {
        if(y==3){
            limpaBuffer();
            printf("Informe o nome a ser procurado: ");
            fgets(buscaNome, 100, stdin);
            while(feof(arq) == 0 && logic == 0){
                fread(&teste, sizeof(struct regAgenda), 1, arq);
                if(strcasecmp(buscaNome, teste.name) == 0){
                    printf("Contato encontrado! \n");
                    printf("Telefone: %d\n", teste.phone);
                    logic = 1;
                }
            }
        }
        if(y==4){
            printf("Informe o telefone a ser procurado: ");
            scanf("%d", &buscaTelefone);
            while(feof(arq) == 0 && logic == 0){
                fread(&teste, sizeof(struct regAgenda), 1, arq);
                if(buscaTelefone == teste.phone){
                    printf("Contato encontrado! \n");
                    printf("Nome: %s\n", teste.name);
                    logic = 1;
                }
            }
        }
        if(logic == 0) printf("Contato não encontrado! \n");
    }
    fclose(arq);
}

void alterarValores ()
{
    int resposta, telefone = -1;
    char nome[100];
    int N=0;
    struct regAgenda teste;
    FILE *arq;
    arq = fopen("agendaV2.bin", "rb+"); rewind(arq);
    if(arq == NULL){
        printf("Não foi possível abrir o arquivo! \n");
        exit(0);
    } else {
        do {
            menus(2);
            printf("\nOpção escolhida: "); scanf("%d", &resposta);
            switch(resposta){
                case 1:
                    limpaBuffer();
                    printf("Informe o antigo nome: "); fgets(nome, 100, stdin);
                    while(!feof(arq)){
                        fread(&teste, sizeof(struct regAgenda), 1, arq);
                        if(strcasecmp(nome, teste.name) == 0 && teste.valid == 1){
                            limpaBuffer();
                            printf("Informe o novo nome: "); fgets(nome, 100, stdin);
                            if(existente(nome, &telefone) == 0){
                                strcpy(teste.name, nome);
                                fseek(arq, (N)*sizeof(struct regAgenda), SEEK_SET);
                                fwrite(&teste, sizeof(struct regAgenda), 1, arq);
                                printf("Contato alterado com sucesso! \n");
                                break;
                            } else {
                                printf("Contato existente! \n");
                                break;
                            }
                        } else N += 1;
                    }
                    break;
                case 2:
                    printf("Informe o antigo número: "); scanf("%d", &telefone);
                    while(feof(arq) == 0){
                        fread(&teste, sizeof(struct regAgenda), 1, arq);
                        if(telefone == teste.phone && teste.valid == 1){
                            printf("Informe o novo número: "); scanf("%d", &telefone);
                            strcpy(nome, "NULL");
                            if(existente(nome, &telefone) == 0) {
                                teste.phone = telefone;
                                fseek(arq, (N)*sizeof(struct regAgenda), SEEK_SET);
                                fwrite(&teste, sizeof(struct regAgenda), 1, arq);
                                printf("Número alterado com sucesso!\n");
                                break;
                            } else {
                                printf("Contato existente! \n");
                                break;
                            }
                        } else N += 1;
                    }
                    break;
                case 3: break;
                default: printf("Opção inválida\n");
            }
        } while (resposta != 3);
    }
    fclose(arq);
}

void exclusao ()
{
    struct regAgenda teste;
    char nome[100];
    int N=0;
    int telefone, resposta, logic;
    FILE *arq;
    arq = fopen("agendaV2.bin", "rb+"); rewind(arq);
    if(arq == NULL){
        printf("Não foi possível abrir o arquivo! \n");
        exit(0);
    } else {
        do{
            menus(3);
            printf("\nOpção escolhida: "); scanf("%d", &resposta);
            switch(resposta){
                case 1:
                    limpaBuffer();
                    printf("Informe o nome: "); fgets(nome, 100, stdin);
                    while(!feof(arq)){
                        fread(&teste, sizeof(struct regAgenda), 1, arq);
                        if(strcasecmp(nome, teste.name) == 0 && teste.valid == 1){
                            printf("Tem certeza que deseja excluir o contato? [1-sim / 0-não]"); scanf("%d", &logic);
                            if(logic == 1){
                                teste.valid = 0;
                                fseek(arq, (N)*sizeof(struct regAgenda), SEEK_SET);
                                fwrite(&teste, sizeof(struct regAgenda), 1, arq);
                                printf("Contato excluído com sucesso! \n");
                                break;
                            } else break;
                        } else N += 1;
                    }
                    break;
                case 2:
                    printf("Informe o telefone: "); scanf("%d", &telefone);
                    while(!feof(arq)){
                        fread(&teste, sizeof(struct regAgenda), 1, arq);
                        if(telefone == teste.phone && teste.valid == 1){
                            printf("Tem certeza que deseja excluir o contato? [1-sim / 0-não]"); scanf("%d", &logic);
                            if(logic == 1){
                                teste.valid = 0;
                                fseek(arq, (N)*sizeof(struct regAgenda), SEEK_SET);
                                fwrite(&teste, sizeof(struct regAgenda), 1, arq);
                                printf("Contato excluído com sucesso! \n");
                                break;
                            } else break;
                        } else N += 1;
                    }
                    break;
                case 3: break;
                default: printf("Opção inválida\n");
            }
        } while (resposta != 3);
    }
    fclose(arq);
}

void reorganizar ()
{
    struct regAgenda teste;
    FILE *arq1 = fopen("agendaV2.bin", "rb");     rewind(arq1);
    FILE *arq2 = fopen("agenda.bin", "wb");       rewind(arq2);
    FILE *arq3 = fopen("backAgenda.bin", "wb");   rewind(arq3);
    while(1){
        fread(&teste, sizeof(struct regAgenda), 1, arq1);
        if(feof(arq1)) break;
        if(teste.valid == 1) fwrite(&teste, sizeof(struct regAgenda), 1, arq2);
        if(teste.valid == 0) fwrite(&teste, sizeof(struct regAgenda), 1, arq3);
    }
    fclose(arq1); fclose(arq2); fclose(arq3);
    remove("agendaV2.bin");
    rename("agenda.bin", "agendaV2.bin");
    printf("\nArquivo reorganizado com sucesso! \n");
    printf("Contatos excluídos foram armazenados em um arquivo backup nomeado\n");
    printf("como 'backAgenda'\n");
}

void lixeira()
{
    int posicao = 0, resposta, telefone, valorMenu;
    char nome[100];
    struct regAgenda teste;
    FILE *arq;
    arq = fopen("agendaV2.bin", "rb+"); rewind(arq);
    menus(4);
    printf("\nOpção escolhida: ");    scanf("%d", &valorMenu);
    switch(valorMenu){
        case 1:
            limpaBuffer();
            printf("Nome: ");       fgets(nome, 100, stdin);
            telefone = -1;
            break;
        case 2:
            printf("Telefone: ");   scanf("%d", &telefone);
            strcpy(nome, "null");
            break;
        case 3:
            printf("Nome"); desenha((30-strlen("Nome")), 2); printf("Telefone\n");
            while(1){
                fread(&teste, sizeof(struct regAgenda), 1, arq);
                teste.name[strlen(teste.name)-1] = '\0';
                if(feof(arq)) break;
                if(teste.valid == 0) {
                        printf("%s", teste.name); desenha((30-strlen(teste.name)), 2); printf("%d\n", teste.phone);
                }
            }
            break;
        case 4: break;
        default: printf("Opção inválida\n");
    }
    if(valorMenu != 4 && (valorMenu == 1 || valorMenu == 2)){
        while(!feof(arq)){
            fread(&teste, sizeof(struct regAgenda), 1, arq);
            if((teste.phone == telefone || strcmp(teste.name, nome) == 0) && teste.valid == 0){
                printf("Contato encontrado! \nDeseja recuperá-lo? [1- sim/ 0- não]");
                scanf("%d", &resposta);
                if(resposta == 1){
                    teste.valid = 1;
                    fseek(arq, posicao*sizeof(struct regAgenda), SEEK_SET);
                    fwrite(&teste, sizeof(struct regAgenda), 1, arq);
                    printf("Contato recuperado com sucesso!\n");
                    break;
                } else break;
            } else posicao += 1;
        }
    }
    fclose(arq);
}
