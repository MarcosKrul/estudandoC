#include <stdio.h>
#include <locale.h>
#include <string.h>
#define N 30
int i;
int copia (char *orig, char *copia, int tam);
main ()
{
    setlocale(LC_ALL, "portuguese_brazil");
    int dimen_str=0, final_c;
    char original[N], copiados[N];
    printf("Informe uma frase (máximo de caractéres: %d):", N);
    scanf("%[^\n]s", &original);
    dimen_str = strlen(original);
    printf("Frase original: %s\nTamanho: %d\n", original, dimen_str);
    final_c = copia(&original, &copiados, dimen_str);
    printf("Caractéres copiados: %d\n", final_c);
    for (i=0 ; i<final_c ; i++) printf("%c", copiados[i]);
}

int copia (char *orig, char *copia, int tam)
{
    int soma=0;
    for (i=0 ; i<tam ; i++){
        if (orig[i] == ' ') break;
         else {
            copia[i] = orig[i];
            soma += 1;
         }
    }
    return soma;
}
