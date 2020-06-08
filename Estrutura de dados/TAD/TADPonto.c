#include <stdlib.h>
#include <stdarg.h>
#include <tgmath.h>
#include "TADPonto.h"

/* ********************** */
/* Definicao da estrutura.*/

struct ponto {
    float x;
    float y;
};

/* ********************** */


/* ****************************************** */
/* Implementacao da funcao pto_cria. */

Ponto* pto_cria(float x, float y){
    Ponto* p = (Ponto*) malloc(sizeof(Ponto));
    if(p != NULL){
        p->x = x;
        p->y = y;
    }
    return p;
}

/* ****************************************** */


/* ************************************ */
/* Implementacao da funcao pto_libera. */

void pto_libera(Ponto* p){
    free(p);
}

/* ************************************ */


/* ************************************ */
/* Implementacao da funcao ptos_libera. */

void ptos_libera(int qnt_ptos, ...){
    int i;
    va_list list;
    va_start(list, qnt_ptos);
    for(i=0 ; i<qnt_ptos ; i++)
        free(va_arg(list, Ponto*));
    va_end(list);
}

/* ************************************ */


/* ***************************************** */
/* Implementacao da funcao pto_acessa. */

void pto_acessa(Ponto* p, float* x, float *y){
    *x = p->x;
    *y = p->y;
}

/* ***************************************** */


/* ***************************************** */
/* Implementacao da funcao pto_atribui. */

void pto_atribui(Ponto* p, float x, float y){
    p->x = x;
    p->y = y;
}

/* ***************************************** */


/* ************************************** */
/* Implementacao da funcao pto_distancia. */

float pto_distancia(Ponto* p1, Ponto* p2){
    float dx = p1->x - p2->x;
    float dy = p1->y - p2->y;
    return sqrt(pow(dx,2) + pow(dy,2));
}

/* ************************************** */
