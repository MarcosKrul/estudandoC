#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void main(int argc, char*argv[]) {
    setlocale(LC_ALL, "portuguese_brazil");
    if(argc == 1){
        printf("O programa %s não possui parâmetros externos", argv[0]);
        return;
    }
    int i, soma=0, qntAlfa=0;
    for(i=1 ; i<argc ; i++){
        int aux;
        if((aux = atoi(argv[i])) == 0) qntAlfa++;
        else soma += aux;
    }
    printf("Soma: %d\n", soma);
    printf("Quantidade de alfa e zeros: %d", qntAlfa);
}

