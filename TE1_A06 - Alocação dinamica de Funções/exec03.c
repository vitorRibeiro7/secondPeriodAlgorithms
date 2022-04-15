#include <stdio.h>
#include <stdlib.h>

int main()
{

    int vet1[5] = {10, 20, 30, 40, 50};
    int *vet1Duplicado;
    int vet2[5] = {60, 70, 80, 90, 100};
    int *vet2Duplicado;

    vet1Duplicado = clonarVetor1(vet1);
    clonarVetor2(vet2, &vet2Duplicado);

    printVetor(vet1Duplicado, 5);
    printVetor(vet2Duplicado, 5);

    return 0;
}

int clonarVetor1(int *vet)
{

    int *vetor;
    vetor = calloc(5, sizeof(int));

    for (int i = 0; i < 5; i++)
    {
        vetor[i] = vet[i];
    }

    return vetor;
}

int clonarVetor2(int *vet, int *saida)
{

    int *vetor;
    vetor = calloc(5, sizeof(int));

    for (int i = 0; i < 5; i++)
    {
        vetor[i] = vet[i];
    }

    *saida = vetor;
}

void printVetor(int *vet, int tam)
{

    for (int i = 0; i < tam; i++)
    {
        printf("[%i] ", vet[i]);
    }

    puts("\n");
}