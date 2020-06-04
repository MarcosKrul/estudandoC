#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[52];
    int mat;
    float notas[];
} _Aluno;

void main () {
    int i, qntNotas;
    float soma=0;
    printf("Informe a quantidade de notas: ");  scanf("%d", &qntNotas);
    _Aluno *aluno = malloc(sizeof(_Aluno)+qntNotas*sizeof(float));
    fflush(stdin);
    printf("Nome do aluno: ");      fgets(&(*aluno).nome, 52, stdin);
    printf("Matricula do aluno: "); scanf("%d", &(*aluno).mat);
    for(i=0 ; i<qntNotas ; i++){
        printf("Nota %d: ", (i+1));
        scanf("%f", &(*aluno).notas[i]);
        soma += (*aluno).notas[i];
    }
    printf("\n\n");
    printf("Nome: %s", (*aluno).nome);
    printf("Matricula: %d\n", (*aluno).mat);
    for(i=0 ; i<qntNotas ; i++) printf("Nota %d = %.1f\n", (i+1), (*aluno).notas[i]);
    printf("Media: %.1f", soma/qntNotas);
}
