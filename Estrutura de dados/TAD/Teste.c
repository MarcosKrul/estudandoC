#include <stdio.h>
#include "TADPonto.c"
//#include "TADPonto.h"


void main() {
    Ponto *p1 = pto_cria(10.9, 20.5),
          *p2 = pto_cria(50.2, 11);

    float coordenadas[4];
    pto_acessa(p1, &coordenadas[0], &coordenadas[1]);
    pto_acessa(p2, &coordenadas[2], &coordenadas[3]);

    float distancia = pto_distancia(p1,p2);

    printf("Distancia entre (%.2f, %.2f) e (%.2f, %.2f) = %.2f \n",
           coordenadas[0], coordenadas[1], coordenadas[2], coordenadas[3], distancia);

    pto_atribui(p1, 11.5f, 23.4);
    pto_acessa(p1, &coordenadas[0], &coordenadas[1]);
    printf("Novas coordenadas de p1: (%.2f, %.2f)\n", coordenadas[0], coordenadas[1]);

    ptos_libera(2, p1, p2);
//    pto_libera(p1);
//    pto_libera(p2);
}
