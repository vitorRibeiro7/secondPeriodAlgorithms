#include <stdio.h>
#include <stdlib.h>

int main()
{

    char str[] = "batata";

    int tam1 = tamanhoString1(str);

    int tam2;

    tamanhoString2(str, &tam2);

    printf("tamanho1 da string: %i\n", tam1);
    printf("tamanho2 da string: %i\n", tam2);

    return 0;
}

int tamanhoString1(char *string1)
{

    int count = 0;

    for (int i = 0; string1[i] != '\0'; i++)
    {
        count++;
    }

    return count;
}

int tamanhoString2(char *string2, int *saida)
{

    int count = 0;

    for (int i = 0; string2[i] != '\0'; i++)
    {
        count++;
    }

    *saida = count;
}