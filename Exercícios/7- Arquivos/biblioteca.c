   // UEPG - Universidade Estadual de Ponta Grossa \\
  // Engenharia de Computação, 2019                 \\
 // By Marcos Renan Krul ;)                          \\
//=================== BIBLIOTECA =====================\\

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

struct regAlunos {
    char nomeAluno[100];
    int serie, matricula, valido;
}; // tam = 112 bytes

struct regLivros {
    char nomeLivro[100], editora[100], emprestado[100]; // emprestado - aluno que emprestou o livro
    int paginas;
    int estoque;         // 1- valido ; 0- inválido
    int situacao;       // 1- emprestado ; 0 - disponível
}; // tam = 312 bytes

int menus(int x);
int alunoExistente(int *mat, char *nome[100]);
int livroExistente(char *nome[100]);
void espacos(int x);
void cadastro(int x);
void listar(int x);
void alterar(int x);
void excluir(int x);
void emprestimo();
void devolucao();
void listarExc(int x);
void recuperar(int x);
void reorganizar(int x);
FILE* abreArquivo(char diretorio[100], char modoAbertura);

main ()
{
    setlocale(LC_ALL, "portuguese_brazil");
    int i, valorMenu[4];
    for(i=0 ; i<4 ; i++) valorMenu[i] = 0;
    do {
        valorMenu[0] = menus(1);
        switch(valorMenu[0]){
            case 1:
                system("cls");
                do{
                    valorMenu[1] = menus(2);
                    switch(valorMenu[1]){
                        case 1: cadastro(1);                if(getch()) system("cls"); break;
                        case 2: listar(1);                  if(getch()) system("cls"); break;
                        case 3: alterar(1);                 if(getch()) system("cls"); break;
                        case 4: excluir(1);                 if(getch()) system("cls"); break;
                        case 5: break;
                        default: printf("Opção inválida\n"); if(getch()) system("cls"); break;
                    }
                system("cls");
                } while(valorMenu[1] != 5);
                break;
            case 2:
                system("cls");
                do{
                    valorMenu[2] = menus(3);
                    switch(valorMenu[2]){
                        case 1: cadastro(2);                 if(getch()) system("cls"); break;
                        case 2: listar(2);                   if(getch()) system("cls"); break;
                        case 3: alterar(2);                  if(getch()) system("cls"); break;
                        case 4: excluir(2);                  if(getch()) system("cls"); break;
                        case 5: emprestimo();                if(getch()) system("cls"); break;
                        case 6: devolucao();                 if(getch()) system("cls"); break;
                        case 7: break;
                        default: printf("Opção inválida\n"); if(getch()) system("cls"); break;
                    }
                system("cls");
                } while(valorMenu[2] != 7);
                break;
            case 3:
                system("cls");
                do{
                    valorMenu[3] = menus(8);
                    switch(valorMenu[3]){
                        case 1:
                            switch(menus(9)){
                                case 1: listarExc(1); break;
                                case 2: listarExc(2); break;
                                case 3: break;
                                default: printf("Opção inválida\n");
                            }
                            if(getch()) system("cls"); break;
                        case 2:
                            printf("\nCaro Usuário!\nA recuperação de um registro não é um processo garantido.\n");
                            printf("Caso o sistema tenha passado por um processo de organização, todos os\nregistros excluídos foram armazenados");
                            printf(" em um arquivo backup!\n");
                            printf("Caso precise desses registros, contate o programador ;)\n\n");
                            switch(menus(9)){
                                case 1: recuperar(1); break;
                                case 2: recuperar(2); break;
                                case 3: break;
                                default: printf("Opção inválida\n");
                            }
                            if(getch()) system("cls"); break;
                        case 3:
                            switch(menus(9)){
                                case 1: reorganizar(1); break;
                                case 2: reorganizar(2); break;
                                case 3: break;
                                default: printf("Opção inválida\n");
                            }
                            if(getch()) system("cls"); break;
                        case 4: break;
                        default: printf("Opção inválida\n");
                    }
                    system("cls");
                } while(valorMenu[3] != 4);
                break;
            case 4: break;
            default: printf("Opção inválida\n"); if(getch()) system("cls"); break;
        }
    } while(valorMenu[0] != 4);
}

int menus(int x)
{
    int resposta;
    switch(x){
        case 1:
            printf("====== Menu principal ======\n");
            printf("[1] - Alunos\n");
            printf("[2] - Biblioteca\n");
            printf("[3] - Organização do arquivo\n");
            printf("[4] - Sair\n");
            printf("============================\n");
            break;
        case 2:
            printf("======= Menu de alunos =======\n");
            printf("[1] - Cadastro de alunos\n");
            printf("[2] - Listar alunos por série\n");
            printf("[3] - Alterar dados\n");
            printf("[4] - Excluir aluno\n");
            printf("[5] - Voltar ao menu principal\n");
            printf("==============================\n");
            break;
        case 3:
            printf("====== Menu da biblioteca ======\n");
            printf("[1] - Cadastrar livros\n");
            printf("[2] - Listar livros\n");
            printf("[3] - Alterar valores\n");
            printf("[4] - Excluir livro\n");
            printf("[5] - Empréstimo\n");
            printf("[6] - Devolução\n");
            printf("[7] - Voltar ao menu principal\n");
            printf("================================\n");
            break;
        case 4:
            printf("\n==== Opções de dados de alunos ====\n");
            printf("[1] - Informar o nome do aluno\n");
            printf("[2] - Informar a matrícula do aluno\n");
            printf("[3] - Voltar ao menu\n");
            printf("===================================\n");
            break;
        case 5:
            printf("=== Opções de alteração ===\n");
            printf("[1] - Alterar o nome\n");
            printf("[2] - Alterar a matrícula\n");
            printf("[3] - Alterar a série\n");
            printf("[4] - Voltar ao menu\n");
            printf("============================\n");
            break;
        case 6:
            printf("======= Opções de alteração =======\n");
            printf("[1] - Alterar o nome\n");
            printf("[2] - Alterar a editora\n");
            printf("[3] - Alterar a quantidade de páginas\n");
            printf("[4] - Voltar ao menu\n");
            printf("====================================\n");
            break;
        case 7:
            printf("\n========== Empréstimo ==========\n");
            printf("[1] - Listar livros emprestados\n");
            printf("[2] - Realizar um empréstimo\n");
            printf("[3] - Voltar ao menu\n");
            printf("================================\n");
            break;
        case 8:
            printf("================== Menu de escolha ==================\n");
            printf("[1] - Listar registros excluídos\n");
            printf("[2] - Recuperar registros excluídos\n");
            printf("[3] - Gerar um arquivo backup com registros excluídos\n");
            printf("[4] - Voltar ao menu principal\n");
            printf("=====================================================\n");
            break;
        case 9:
            printf("-------------------------\n");
            printf("[1] - Registros de alunos\n");
            printf("[2] - Registros de livros\n");
            printf("[3] - Voltar ao menu\n");
            printf("-------------------------\n");
            break;
    }
    printf("Opção escolhida: "); scanf("%d", &resposta);
    return resposta;
}

void espacos(int x)
{
    int i;
    for(i=0 ; i<x ; i++) printf(" ");
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
        printf("Não foi possível abrir o arquivo! \n");
        exit(0);
    } else return arquivo;
}

int alunoExistente(int *mat, char *nome[100])
{
    int logic = 0;
    struct regAlunos teste;
    FILE* arq = abreArquivo("alunos.bin", 'r');
    rewind(arq);
    while(!feof(arq)){
        fread(&teste, sizeof(struct regAlunos), 1, arq);
        if(strcasecmp(nome, teste.nomeAluno) == 0 || teste.matricula == *mat) {
            logic = 1;
            break;
        }
    }
    return logic;
}

int livroExistente(char *nome[100])
{
    int logic = 0;
    struct regLivros teste;
    FILE *arq = abreArquivo("biblioteca.bin", 'r');
    rewind(arq);
    while(!feof(arq)){
        fread(&teste, sizeof(struct regLivros), 1, arq);
        if(strcasecmp(nome, teste.nomeLivro) == 0){
            logic = 1;
            break;
        }
    }
    return logic;
}

void cadastro(int x)
{
    switch(x){
        case 1: {
            struct regAlunos teste;
            FILE *arq = abreArquivo("alunos.bin", 'a');
            fflush(stdin);
            printf("=== Cadastro de aluno === \n");
            printf("Informe o nome: ");         fgets(teste.nomeAluno, 100, stdin);
            printf("Informe a matrícula: ");    scanf("%d", &teste.matricula);
            printf("Informe a série: ");        scanf("%d", &teste.serie);
            teste.valido = 1;
            if(alunoExistente(&teste.matricula, teste.nomeAluno) == 0)
                fwrite(&teste, sizeof(struct regAlunos), 1, arq);
            else printf("Aluno já cadastrado! \n");
            fclose(arq);
            break;
        }
        case 2: {
            struct regLivros teste;
            FILE *arq = abreArquivo("biblioteca.bin", 'a');
            fflush(stdin);
            printf("=== Cadastro de livro === \n");
            printf("Informe o nome: ");                     fgets(teste.nomeLivro, 100, stdin);
            fflush(stdin);
            printf("Informe a editora: ");                  fgets(teste.editora, 100, stdin);
            printf("Informe a quantidade de páginas: ");    scanf("%d", &teste.paginas);
            teste.estoque = 1;
            teste.situacao = 0;
            if(livroExistente(teste.nomeLivro) == 0)
                fwrite(&teste, sizeof(struct regLivros), 1, arq);
            else printf("Livro já cadastrado! \n");
            fclose(arq);
            break;
        }
    }
}

void listar(int x)
{
    switch(x){
        case 1: {
            int buscaSerie;
            struct regAlunos teste;
            FILE *arq = abreArquivo("alunos.bin", 'r');
            printf("Informe a série desejada: ");       scanf("%d", &buscaSerie);
            printf("\nNome do aluno"); espacos(30 - strlen("Nome do aluno")); printf("Matrícula\n");
            while(1){
                fread(&teste, sizeof(struct regAlunos), 1, arq);
                if(feof(arq)) break;
                if(teste.valido == 1 && teste.serie == buscaSerie){
                    teste.nomeAluno[strlen(teste.nomeAluno)-1] = '\0';
                    printf("%s", teste.nomeAluno); espacos(30 - strlen(teste.nomeAluno)); printf("%d\n", teste.matricula);
                }
            }
            fclose(arq);
            break;
        }
        case 2: {
            struct regLivros teste;
            FILE *arq = abreArquivo("biblioteca.bin", 'r');
            while(1){
                fread(&teste, sizeof(struct regLivros), 1, arq);
                if(feof(arq)) break;
                if(teste.estoque == 1){
                    printf("\nNome do livro: %s", teste.nomeLivro);
                    printf("Editora: %s", teste.editora);
                    printf("Número de páginas: %d\n", teste.paginas);
                    switch(teste.situacao){
                        case 0: printf("Situação: disponível\n"); break;
                        case 1: printf("Situação: emprestado\n"); break;
                    }
                }
            }
            fclose(arq);
            break;
        }
    }
}

void alterar(int x)
{
    int nex = -1;
    char nomeBusca[100], novoNome[100];
    int pos = 0, opcoes;
    switch(x){
        case 1: {
            int valorMenu, buscaMat, novaMat;
            struct regAlunos teste;
            FILE *arq = abreArquivo("alunos.bin", 'k');
            valorMenu = menus(4);
            switch(valorMenu){
                case 1:{
                    fflush(stdin);
                    printf("Informe o nome do aluno: "); fgets(nomeBusca, 100, stdin);
                    system("cls");
                    while(!feof(arq)){
                        fread(&teste, sizeof(struct regAlunos), 1, arq);
                        if(teste.valido == 1 && strcasecmp(nomeBusca, teste.nomeAluno) == 0){
                            do {
                                opcoes = menus(5);
                                switch(opcoes){
                                    case 1:
                                        fflush(stdin);
                                        printf("Informe o novo nome: "); fgets(novoNome, 100, stdin);
                                        if(alunoExistente(&nex, novoNome) == 0) strcpy(teste.nomeAluno, novoNome);
                                        else printf("Aluno já cadastrado! \n");
                                        if(getch()) system("cls"); break;
                                    case 2:
                                        printf("Informe a nova matrícula: "); scanf("%d", &novaMat);
                                        if(alunoExistente(&novaMat, "NULL") == 0) teste.matricula = novaMat;
                                        else printf("Matrícula já cadastrada! \n");
                                        if(getch()) system("cls"); break;
                                    case 3:
                                        printf("Informe a nova série: "); scanf("%d", &teste.serie);
                                        if(getch()) system("cls"); break;
                                    case 4: break;
                                    default: printf("Opção inválida\n");
                                }
                            } while(opcoes != 4);
                            fseek(arq, pos*sizeof(struct regAlunos), SEEK_SET);
                            fwrite(&teste, sizeof(struct regAlunos), 1, arq);
                            printf("Atualização concluída com sucesso!\n");
                            break;
                        } else pos += 1;
                    }
                    break;
                }
                case 2:{
                    printf("Informe a matrícula do aluno: "); scanf("%d", &buscaMat);
                    system("cls");
                    while(!feof(arq)){
                        fread(&teste, sizeof(struct regAlunos), 1, arq);
                        if(teste.valido == 1 && buscaMat == teste.matricula){
                            do {
                                opcoes = menus(5);
                                switch(opcoes){
                                    case 1:
                                        fflush(stdin);
                                        printf("Informe o novo nome: "); fgets(novoNome, 100, stdin);
                                        if(alunoExistente(&nex, novoNome) == 0) strcpy(teste.nomeAluno, novoNome);
                                        else printf("Aluno já cadastrado! \n");
                                        if(getch()) system("cls"); break;
                                    case 2:
                                        printf("Informe a nova matrícula: "); scanf("%d", &novaMat);
                                        if(alunoExistente(&novaMat, "NULL") == 0) teste.matricula = novaMat;
                                        else printf("Matrícula já cadastrada! \n");
                                        if(getch()) system("cls"); break;
                                    case 3:
                                        printf("Informe a nova série: "); scanf("%d", &teste.serie);
                                        if(getch()) system("cls"); break;
                                    case 4: break;
                                    default: printf("Opção inválida\n");
                                }
                            } while(opcoes != 4);
                            fseek(arq, pos*sizeof(struct regAlunos), SEEK_SET);
                            fwrite(&teste, sizeof(struct regAlunos), 1, arq);
                            printf("Atualização concluída com sucesso!\n");
                            break;
                        } else pos += 1;
                    }
                    break;
                }
            }
            fseek(arq, sizeof(struct regAlunos), SEEK_END);
            if(pos == (ftell(arq)/sizeof(struct regAlunos))){
                printf("Aluno não encontrado! \n");
                rewind(arq);
            }
            fclose(arq);
            break;
        }
        case 2: {
            struct regLivros teste;
            FILE *arq = abreArquivo("biblioteca.bin", 'k');
            fflush(stdin);
            printf("Informe o nome do livro: "); fgets(nomeBusca, 100, stdin);
            system("cls");
            while(!feof(arq)){
                fread(&teste, sizeof(struct regLivros), 1, arq);
                if(teste.estoque == 1 && strcasecmp(nomeBusca, teste.nomeLivro) == 0){
                    do {
                        opcoes = menus(6);
                        switch(opcoes){
                            case 1:
                                fflush(stdin);
                                printf("Informe o novo nome: "); fgets(novoNome, 100, stdin);
                                if(livroExistente(novoNome) == 0) strcpy(teste.nomeLivro, novoNome);
                                else printf("Livro já cadastrado! \n");
                                if(getch()) system("cls"); break;
                            case 2:
                                fflush(stdin);
                                printf("Informe a nova editora: "); fgets(teste.editora, 100, stdin);
                                if(getch()) system("cls"); break;
                            case 3:
                                printf("Informe a nova quantidade de páginas: "); scanf("%d", &teste.paginas);
                                if(getch()) system("cls"); break;
                            case 4: break;
                            default: printf("Opção inválida\n");
                        }
                    } while(opcoes != 4);
                    fseek(arq, pos*sizeof(struct regLivros), SEEK_SET);
                    fwrite(&teste, sizeof(struct regLivros), 1, arq);
                    printf("Dados alterados com sucesso!\n");
                    break;
                } else pos += 1;
            }
            fseek(arq, sizeof(struct regLivros), SEEK_END);
            if(pos == (ftell(arq)/sizeof(struct regLivros))){
                printf("Livro não encontrado! \n");
                rewind(arq);
            }
            fclose(arq);
            break;
        }
    }
}

void excluir (int x)
{
    switch(x){
        case 1: {
            struct regAlunos teste;
            FILE *arq = abreArquivo("alunos.bin", 'k');
            int valorMenu = menus(4), pos = 0, buscaMat, logic;
            char nomeBusca[100];
            switch(valorMenu){
                case 1:
                    fflush(stdin);
                    printf("Informe o nome do aluno: "); fgets(nomeBusca, 100, stdin);
                    while(!feof(arq)){
                        fread(&teste, sizeof(struct regAlunos), 1, arq);
                        if(teste.valido == 1 && strcasecmp(nomeBusca, teste.nomeAluno) == 0){
                            printf("Você tem certeza que deseja excluir o aluno? [1-sim / 0-não]"); scanf("%d", &logic);
                            if(logic == 1){
                                teste.valido = 0;
                                fseek(arq, pos*sizeof(struct regAlunos), SEEK_SET);
                                fwrite(&teste, sizeof(struct regAlunos), 1, arq);
                                printf("Aluno excluído com sucesso! \n");
                                break;
                            } else break;
                        } else pos += 1;
                    }
                    break;
                case 2:
                    printf("Informe a matrícula do aluno: "); scanf("%d", &buscaMat);
                    while(!feof(arq)){
                        fread(&teste, sizeof(struct regAlunos), 1, arq);
                        if(teste.valido == 1 && buscaMat == teste.matricula){
                            printf("Você tem certeza que deseja excluir o aluno? [1-sim / 0-não]"); scanf("%d", &logic);
                            if(logic == 1){
                                teste.valido = 0;
                                fseek(arq, pos*sizeof(struct regAlunos), SEEK_SET);
                                fwrite(&teste, sizeof(struct regAlunos), 1, arq);
                                printf("Aluno excluído com sucesso! \n");
                                break;
                            } else break;
                        } else pos += 1;
                    }
                    break;
            }
            fseek(arq, sizeof(struct regAlunos), SEEK_END);
            if(pos == (ftell(arq)/sizeof(struct regAlunos))) {
                printf("Aluno não encontrado\n");
                rewind(arq);
            }
            fclose(arq);
            break;
        }
        case 2: {
            struct regLivros teste;
            FILE *arq = abreArquivo("biblioteca.bin", 'k');
            char buscaNome[100];
            int pos = 0, logic;
            printf("\nCaro usuário! \nSó poderão ser excluídos livros em estoque\ne livros que não estão emprestado!\n\n");
            fflush(stdin);
            printf("Informe o nome do livro: "); fgets(buscaNome, 100, stdin);
            while(!feof(arq)){
                fread(&teste, sizeof(struct regLivros), 1, arq);
                if(teste.estoque == 1 && teste.situacao == 0 && strcasecmp(buscaNome, teste.nomeLivro) == 0){
                    printf("Você tem certeza que deseja excluir o livro? [1- sim/ 0- não]"); scanf("%d", &logic);
                    if(logic == 1){
                        teste.estoque = 0;
                        fseek(arq, pos*sizeof(struct regLivros), SEEK_SET);
                        fwrite(&teste, sizeof(struct regLivros), 1, arq);
                        printf("Livro excluído com sucesso!\n");
                        break;
                    } else break;
                } else pos += 1;
            }
            fseek(arq, sizeof(struct regLivros), SEEK_END);
            if(pos == (ftell(arq)/sizeof(struct regLivros))){
                printf("Livro não encontrado ou não disponível para exclusão (emprestado)!\n");
                rewind(arq);
            }
            fclose(arq);
            break;
        }
    }
}

void emprestimo ()
{
    int valorMenu;
    do {
        valorMenu = menus(7);
        switch(valorMenu){
            case 1:{
                struct regLivros teste;
                FILE *arq = abreArquivo("biblioteca.bin", 'r');
                int logic = 0;
                while(1){
                    fread(&teste, sizeof(struct regLivros), 1, arq);
                    if(feof(arq)) break;
                    if(teste.estoque == 1 && teste.situacao == 1){
                        logic = 1;
                        printf("Nome do livro: %s", teste.nomeLivro);
                        printf("Aluno que emprestou o livro: %s\n", teste.emprestado);
                    }
                }
                if(logic == 0) printf("Não há livros emprestados!\n");
                fclose(arq);
                break;
            }
            case 2: {
                int pos = 0, buscaMat, logic = 0, valorM;
                struct regAlunos testeAluno;
                struct regLivros testeLivro;
                char nomeBusca[100], livroBusca[100];
                FILE *arqAluno = abreArquivo("alunos.bin", 'r');
                FILE *arqBiblio = abreArquivo("biblioteca.bin", 'k');
                fflush(stdin);
                printf("Informe o nome do livro: "); fgets(livroBusca, 100, stdin);
                while(!feof(arqBiblio)){
                    fread(&testeLivro, sizeof(struct regLivros), 1, arqBiblio);
                    if(testeLivro.estoque == 1 && testeLivro.situacao == 0 && strcasecmp(livroBusca, testeLivro.nomeLivro) == 0){
                        printf("Livro disponível para empréstimo! \n\n");
                        valorM = menus(4);
                        switch(valorM){
                            case 1:
                                fflush(stdin);
                                printf("Informe o nome do aluno: "); fgets(nomeBusca, 100, stdin);
                                while(!feof(arqAluno)){
                                    fread(&testeAluno, sizeof(struct regAlunos), 1, arqAluno);
                                    if(testeAluno.valido == 1 && strcasecmp(testeAluno.nomeAluno, nomeBusca) == 0){
                                        testeLivro.situacao = 1;
                                        strcpy(testeLivro.emprestado, testeAluno.nomeAluno);
                                        printf("Empréstimo realizado com sucesso!\n\n");
                                        logic = 1;
                                        break;
                                    }
                                }
                                if(logic == 0) {
                                    printf("Aluno não encontrado! \n");
                                    break;
                                }
                                break;
                            case 2:
                                printf("Informe a matrícula do aluno: "); scanf("%d", &buscaMat);
                                while(!feof(arqAluno)){
                                    fread(&testeAluno, sizeof(struct regAlunos), 1, arqAluno);
                                    if(testeAluno.valido == 1 && buscaMat == testeAluno.matricula){
                                        testeLivro.situacao = 1;
                                        strcpy(testeLivro.emprestado, testeAluno.nomeAluno);
                                        printf("Empréstimo realizado com sucesso!\n");
                                        logic = 1;
                                        break;
                                    }
                                }
                                if(logic == 0){
                                    printf("Aluno não encontrado! \n");
                                    break;
                                }
                                break;
                            case 3: break; break;
                            default: printf("Opção inválida!\n");
                        }
                        break;
                    } else pos += 1;
                }
                fseek(arqBiblio, sizeof(struct regLivros), SEEK_END);
                if(pos == (ftell(arqBiblio)/sizeof(struct regLivros))){
                    printf("Livro não disponível!\n");
                    break;
                } else {
                    fseek(arqBiblio, pos*sizeof(struct regLivros), SEEK_SET);
                    fwrite(&testeLivro, sizeof(struct regLivros), 1, arqBiblio);
                }
                fclose(arqAluno);
                fclose(arqBiblio);
                break;
            }
            case 3: break;
            default: printf("Opção inválida!\n");
        }
    } while(valorMenu != 3);
}

void devolucao ()
{
    struct regLivros teste;
    FILE *arq = abreArquivo("biblioteca.bin", 'k');
    int pos = 0;
    char nomeBusca[100];
    fflush(stdin);
    printf("Informe o nome do livro: "); fgets(nomeBusca, 100, stdin);
    rewind(arq);
    while(!feof(arq)){
        fread(&teste, sizeof(struct regLivros), 1, arq);
        if(strcasecmp(nomeBusca, teste.nomeLivro) == 0 && teste.estoque == 1 && teste.situacao == 1){
            teste.situacao = 0;
            fseek(arq, pos*sizeof(struct regLivros), SEEK_SET);
            fwrite(&teste, sizeof(struct regLivros), 1, arq);
            printf("Devolução concluída com sucesso! \n\n");
            break;
        } else pos += 1;
    }
    fseek(arq, sizeof(struct regLivros), SEEK_END);
    if(pos == (ftell(arq)/sizeof(struct regLivros))) printf("Livro não encontrado ou disponível\n");
}

void listarExc(int x)
{
    int logic = 0;
    switch(x){
        case 1:{
            struct regAlunos teste;
            FILE *arq = abreArquivo("alunos.bin", 'r');
            printf("Nome do aluno"); espacos(30 - strlen("Nome do aluno")); printf("Matrícula\n");
            while(1){
                fread(&teste, sizeof(struct regAlunos), 1, arq);
                if(feof(arq)) break;
                if(teste.valido == 0){
                    teste.nomeAluno[strlen(teste.nomeAluno)-1] = '\0';
                    printf("%s", teste.nomeAluno); espacos(30 - strlen(teste.nomeAluno)); printf("%d\n", teste.matricula);
                    logic = 1;
                }
            }
            fclose(arq);
            break;
        }
        case 2: {
            struct regLivros teste;
            FILE *arq = abreArquivo("biblioteca.bin", 'r');
            while(1){
                fread(&teste, sizeof(struct regLivros), 1, arq);
                if(feof(arq)) break;
                if(teste.estoque == 0){
                    printf("\nNome do livro: %s", teste.nomeLivro);
                    printf("Editora: %s", teste.editora);
                    printf("Número de páginas: %d\n", teste.paginas);
                    logic = 1;
                }
            }

        }
    }
    if(logic == 0) printf("Não há registros excluídos! \n");
}

void recuperar(int x)
{
    switch(x){
        case 1: {
            int pos = 0;
            char nomeBusca[100];
            struct regAlunos teste;
            FILE *arq = abreArquivo("alunos.bin", 'k');
            fflush(stdin);
            printf("Informe o nome do aluno: "); fgets(nomeBusca, 100, stdin);
            while(!feof(arq)){
                fread(&teste, sizeof(struct regAlunos), 1, arq);
                if(teste.valido == 0 && strcasecmp(nomeBusca, teste.nomeAluno) == 0){
                    teste.valido = 1;
                    fseek(arq, pos*sizeof(struct regAlunos), SEEK_SET);
                    fwrite(&teste, sizeof(struct regAlunos), 1, arq);
                    printf("Registro recuperado com sucesso! \n");
                    break;
                } else pos += 1;
            }
            fseek(arq, sizeof(struct regAlunos), SEEK_END);
            if(pos == (ftell(arq)/sizeof(struct regAlunos))) printf("Aluno não encontrado\n");
            fclose(arq); break;
        }
        case 2: {
            int pos = 0;
            char nomeBusca[100];
            struct regLivros teste;
            FILE *arq = abreArquivo("biblioteca.bin", 'k');
            fflush(stdin);
            printf("Informe o nome do livro: "); fgets(nomeBusca, 100, stdin);
            while(!feof(arq)){
                fread(&teste, sizeof(struct regLivros), 1, arq);
                if(teste.estoque == 0 && strcasecmp(nomeBusca, teste.nomeLivro) == 0){
                    teste.estoque = 1;
                    fseek(arq, pos*sizeof(struct regLivros), SEEK_SET);
                    fwrite(&teste, sizeof(struct regLivros), 1, arq);
                    printf("Registro recuperado com sucesso! \n");
                    break;
                } else pos += 1;
            }
            fseek(arq, sizeof(struct regLivros), SEEK_END);
            if(pos == (ftell(arq)/sizeof(struct regLivros))) printf("Livro não encontrado\n");
            fclose(arq); break;
        }
    }
}

void reorganizar (int x)
{
    switch(x){
        case 1: {
            struct regAlunos teste;
            FILE *arq = abreArquivo("alunos.bin", 'r');         // arquivo original
            FILE *arq1 = abreArquivo("backAlunos.bin", 'w');   // arquivo com registros excluídos
            FILE *arq2 = abreArquivo("newAlunos.bin", 'w');   // arquivo com registros válidos
            while(1){
                fread(&teste, sizeof(struct regAlunos), 1, arq);
                if(feof(arq)) break;
                if(teste.valido == 0) fwrite(&teste, sizeof(struct regAlunos), 1, arq1);
                if(teste.valido == 1) fwrite(&teste, sizeof(struct regAlunos), 1, arq2);
            }
            printf("Trabalhando nisso ..."); Sleep(3000);
            printf("\nArquivo reorganizado com sucesso! \n");
            printf("Registros excluídos foram armazenados em um arquivo backup de nome 'backAlunos'\n");
            printf("O arquivo pode ser armazenado ou excluído manualmente, caso tenha certeza que não os utilizará\n");
            printf("Caso precise dos registros excluídos, contate o programador ;)\n");
            fclose(arq); fclose(arq1); fclose(arq2);
            remove("alunos.bin");
            rename("newAlunos.bin", "alunos.bin");
            break;
        }
        case 2: {
            struct regLivros teste;
            FILE *arq = abreArquivo("biblioteca.bin", 'r');
            FILE *arq1 = abreArquivo("backLivros.bin", 'w');
            FILE *arq2 = abreArquivo("newLivros.bin", 'w');
            while(1){
                fread(&teste, sizeof(struct regLivros), 1, arq);
                if(feof(arq)) break;
                if(teste.estoque == 0) fwrite(&teste, sizeof(struct regLivros), 1, arq1);
                if(teste.estoque == 1) fwrite(&teste, sizeof(struct regLivros), 1, arq2);
            }
            printf("Trabalhando nisso ..."); Sleep(3000);
            printf("\nArquivo reorganizado com sucesso! \n");
            printf("Registros excluídos foram armazenados em um arquivo backup de nome 'backLivros'\n");
            printf("O arquivo pode ser armazenado ou excluído manualmente, caso tenha certeza que não os utilizará\n");
            printf("Caso precise dos registros excluídos, contate o programador ;)\n");
            fclose(arq); fclose(arq1); fclose(arq2);
            remove("biblioteca.bin");
            rename("newLivros.bin", "biblioteca.bin");
            break;
        }
    }
}
