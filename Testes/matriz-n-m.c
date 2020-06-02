#include <stdio.h>

#define _TAM_L1_ 5
#define _TAM_L2_ 3
#define _TAM_L3_ 9
#define _TAM_L4_ 2
#define _TAM_L5_ 7
#define _TAM_MAT_ 5

#define _TAM_LINHA_(var, linha) {switch(linha){\
    case 0: var = _TAM_L1_; break;\
    case 1: var = _TAM_L2_; break;\
    case 2: var = _TAM_L3_; break;\
    case 3: var = _TAM_L4_; break;\
    case 4: var = _TAM_L5_; break;}}
// fim funcao macro


void main() {
#ifndef _TAM_MAT_
#define _TAM_MAT_ 3
    int* pvet[_TAM_MAT_];
#else
    int* pvet[_TAM_MAT_];
#endif

    int i, j;
    pvet[0] = (int []){1,2,3,4,5};
    pvet[1] = (int []){1,2,3};
    pvet[2] = (int []){1,2,3,4,5,6,7,8,9};
    pvet[3] = (int []){1,2};
    pvet[4] = (int []){1,2,3,4,5,6,7};

    for(i=0 ; i<_TAM_MAT_ ; i++){
        int aux;
#ifdef _TAM_LINHA_(var, linha)
    _TAM_LINHA_(aux,i);
#else
    printf("Função não definida");
    exit(0);
#endif
        for(j=0 ; j<aux; j++) printf("%d\t", pvet[i][j]);
        printf("\n");
    }
}
