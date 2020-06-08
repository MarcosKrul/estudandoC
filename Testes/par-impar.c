#include <stdio.h>
#include <stdbool.h>

inline bool eh_par(int* value) {
    return !(*value % 2);
}

void main () {
    int in;
    while(true) {
        printf("Informe o valor: ");
        scanf("%d", &in);
        if(in == 0) printf("O valor eh 0\n");
        else
            if(eh_par(&in)) printf("O valor eh par\n");
            else printf("O valor eh impar\n");
    }
}
