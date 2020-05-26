#include <stdarg.h>

int soma_varargs(int qnt, ...){
    int i, soma = 0;
    va_list lista;
    va_start(lista, qnt);
    for(i=0 ; i<qnt ; i++) soma += va_arg(lista, int);
    va_end(lista);
    return soma;
}

void main () {
    printf("%d\n", soma_varargs(3,3,5,6));
    printf("%d\n", soma_varargs(2,10,20));
    printf("%d\n", soma_varargs(5,9,6,7,8,2));
    printf("%d\n", soma_varargs(1,5));
}
