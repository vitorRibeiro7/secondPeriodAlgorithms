#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main()
{

    int *vet1;
    int *vet2;

    vet1 = criaVetorAleatorio1(10);

    criaVetorAleatorio2(5, &vet2);

    printVetor(vet1, vet2, 10, 5);

    return 0;
}

int criaVetorAleatorio1(int tam)
{

    int *vet1;
    vet1 = (int *)calloc(tam, sizeof(int));

    for (int i = 0; i < tam; i++)
    {
        vet1[i] = rand() % 100;
    }

    return vet1;
}

int criaVetorAleatorio2(int tam, int *saida)
{
    int *vet2;
    vet2 = calloc(tam, sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < tam; i++)
    {
        vet2[i] = rand() % (tam * 10);
    }

    *saida = vet2;
}

void printVetor(int *vet1, int *vet2, int tam1, int tam2)
{

    for (int i = 0; i < tam1; i++)
    {
        printf("[%i] ", vet1[i]);
    }

    printf("\n\n\n\n");

    for (int i = 0; i < tam2; i++)
    {
        printf("[%i] ", vet2[i]);
    }

    return 0;
}