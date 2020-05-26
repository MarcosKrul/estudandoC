#include <stdio.h>
#include <locale.h>

void desenha (int x);
main ()
{
    setlocale(LC_ALL, "portuguese_brazil");
    int i, x=0, value, soma=0;
    int vet[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    do {
        printf("Informe um número ímpar entre 1 e 9: ");
        scanf("%d", &value);
    } while(!(value % 2 != 0 && value>=1 && value<=9));
    while (value > 0){
        for (i=x ; i<value ; i++) {
            if (i == x) desenha(soma);
            printf("%d ", vet[i]);
        }
        printf("\n");
        value -= 1;
        soma += 2;
        x += 1;
    }
    printf("Enter para sair");
    if(getch()) exit(0);
}

void desenha (int x)
{
    int loop;
    for (loop = 0; loop < x ; loop++) printf(" ");
}


