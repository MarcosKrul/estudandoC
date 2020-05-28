#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define __QNT 3

struct regPessoa {
    int idade;
    char nome[50];
};

int menu();
void espacos(int x);
void imprimeVetor(int qnt, struct regPessoa vet[]);
int cadastro(struct regPessoa vet[]);
int comparaIdadeCrescente(const void* p1, const void* p2);
int comparaIdadeDecrescente(const void* p1, const void* p2);
int comparaNomes(const void* p1, const void* p2);

void main () {
    setlocale(LC_ALL, "ptb");
    struct regPessoa vet[__QNT];
    int valorMenu, qntCadastrados;
    do {
        valorMenu = menu();
        switch(valorMenu){
            case 1:
                qntCadastrados = cadastro(vet);
                if(getch()) system("cls"); break;
            case 2:
                qsort(vet,qntCadastrados,sizeof(struct regPessoa),comparaNomes);
                imprimeVetor(qntCadastrados, vet);
                if(getch()) system("cls"); break;
            case 3:
                qsort(vet,qntCadastrados,sizeof(struct regPessoa),comparaIdadeCrescente);
                imprimeVetor(qntCadastrados, vet);
                if(getch()) system("cls"); break;
            case 4:
                qsort(vet,qntCadastrados,sizeof(struct regPessoa),comparaIdadeDecrescente);
                imprimeVetor(qntCadastrados, vet);
                if(getch()) system("cls"); break;
            case 5: break;
            default: printf("Opção inválida"); if(getch()) system("cls"); break;
        }
    } while (valorMenu != 5);
}

int menu() {
    int resposta;
    printf("==== Menu de escolha ====\n");
    printf("[1] - Cadastrar\n");
    printf("[2] - Ordem alfabética\n");
    printf("[3] - Por idade crescente\n");
    printf("[4] - Por idade decrescente\n");
    printf("[5] - Sair\n");
    printf("=========================\n");
    printf("Opção escolhida: ");
    scanf("%d", &resposta);
    return resposta;
}

void espacos(int x){
    int i;
    for(i=0 ; i<x ; i++) printf(" ");
}

void imprimeVetor(int qnt, struct regPessoa vet[]) {
    int i;
    char nomeAux[50];
    printf("\nNome"); espacos(30-strlen("Nome")); printf("Idade\n");
    for(i=0 ; i<qnt ; i++){
        strcpy(nomeAux, vet[i].nome);
        nomeAux[strlen(nomeAux)-1] = '\0';
        printf("%s", nomeAux); espacos(30-strlen(nomeAux)); printf("%d\n", vet[i].idade);
    }
}

int cadastro(struct regPessoa vet[]) {
    static int qntMax = 0;
    if(qntMax < __QNT){
        fflush(stdin);
        printf("\nInforme o nome: ");     fgets(vet[qntMax].nome, 50, stdin);
        printf("Informe a idade: ");    scanf("%d", &vet[qntMax].idade);
        printf("Usuario cadastrado com sucesso!\n");
        qntMax++;
    } else printf("Não é possível cadastrar mais usuários\n");
    return qntMax;
}

int comparaIdadeCrescente(const void* p1, const void* p2){
    struct regPessoa a = *(struct regPessoa*)p1, b = *(struct regPessoa*)p2;
    if(a.idade == b.idade) return 0;
    return a.idade>b.idade? 1 : -1;
}

int comparaIdadeDecrescente(const void* p1, const void* p2){
    struct regPessoa a = *(struct regPessoa*)p1, b = *(struct regPessoa*)p2;
    if(a.idade == b.idade) return 0;
    return a.idade>b.idade? -1 : 1;
}

int comparaNomes(const void* p1, const void* p2){
    return strcasecmp((*(struct regPessoa*)p1).nome, (*(struct regPessoa*)p2).nome);
}
