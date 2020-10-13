#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define __FROW__ 12
#define __EQ__ 2
#define __SCOMN__ 2

int** criarMatriz(int,int);
void gerarMatriz(int,int,int**);
void zerarMatriz(int,int,int**);
void imprimirMatriz(int,int,int**);
int** multiplicarMatrizes(int,int,int,int**,int**);

int main() {
    srand(time(NULL));

    printf("Matriz A\n");
    int** matrizA = criarMatriz(__FROW__, __EQ__);
    gerarMatriz(__FROW__, __EQ__, matrizA);
    imprimirMatriz(__FROW__, __EQ__, matrizA);

    printf("\n\nMatriz B\n");
    int** matrizB = criarMatriz(__EQ__, __SCOMN__);
    gerarMatriz(__EQ__, __SCOMN__, matrizB);
    imprimirMatriz(__EQ__, __SCOMN__, matrizB);

    printf("\n\nMatriz Multiplicação\n");
    matrizA = multiplicarMatrizes(__FROW__, __EQ__, __SCOMN__, matrizA, matrizB);
    imprimirMatriz(__FROW__, __SCOMN__, matrizA);

    free(matrizA);
    free(matrizB);
    return 0;
}

int** criarMatriz(int row, int column) {
    int** array = (int**) malloc(row * sizeof(int*));
    if(array != NULL) {
        for(int i=0 ; i<row ; i++)
            array[i] = (int*) malloc(column * sizeof(int));
    }
    return array;
}

void gerarMatriz(int row, int column, int** array) {
    for(int i=0 ; i<row ; i++)
        for(int j=0 ; j<column ; j++)
            array[i][j] = rand()%10;
}

void zerarMatriz(int row, int column, int** array){
    for(int i=0 ; i<row ; i++)
        for(int j=0 ; j<column ; j++)
            array[i][j] = 0;
}

void imprimirMatriz(int row, int column, int** array) {
    for(int i=0 ; i<row ; i++){
        for(int j=0 ; j<column ; j++)
            printf("%d\t", array[i][j]);
        printf("\n");
    }
}

int** multiplicarMatrizes(int fRow, int equals, int sColumn, int** a, int** b){
    int** array = criarMatriz(fRow, sColumn);
    zerarMatriz(fRow, sColumn, array);
    for(int i=0 ; i<fRow ; i++)
        for(int j=0 ; j<sColumn ; j++)
            for(int k=0 ; k<equals ; k++)
                array[i][j] += a[i][k]*b[k][j];
    return array;
}