#include <stdio.h>
#include <stdlib.h>

int main()
{

    int tam = 3;

    int *vet1;
    vet1 = calloc(tam, sizeof(int));

    for (int i = 0; i < tam; i++)
    {
        vet1[i] = rand() % 100;
    }

    dobrar(tam, vet1);

    free(vet1);

    return 0;
}

int dobrar(int tam, int **vetToCopy)
{

    int dup = tam * 2;
    int i = 0;

    int *vetorDuplo;
    vetorDuplo = malloc(dup * sizeof(int));

    while (i < tam)
    {

        vetorDuplo[i] = vetToCopy[i];

        i++;
    }

    i = tam;

    while (i < dup)
    {
        vetorDuplo[i] = 0;

        i++;
    }

    for (int i = 0; i < dup; i++)
    {
        printf("[%i] ", vetorDuplo[i]);
    }

    return 0;
}