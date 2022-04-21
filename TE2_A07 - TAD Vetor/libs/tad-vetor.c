// tad_vetor.c
#include "tad-vetor.h"
#define TAMANHO 5
#include <stdio.h>
#include <string.h>

/********************************************
 * Especificação dos dados
 *******************************************/
struct vetor
{
    int *vet;
    int tam;
    int qtd;
};

/********************************************
 * Implementação das funções
 *******************************************/
Vetor *vet_criar()
{

    Vetor *v = (Vetor *)malloc(sizeof(Vetor));
    v->vet = (int *)calloc(TAMANHO, sizeof(int));
    v->tam = TAMANHO;
    v->qtd = 0;

    return v;
}

bool vet_anexar(Vetor *v, int elemento)
{

    if (v->qtd >= v->tam)
    {

        int tamAux = v->tam * 2;

        int *v2;
        v2 = (int *)calloc(tamAux, sizeof(int));

        for (int i = 0; i < v->tam; i++)
        {
            v2[i] = v->vet[i];
        }

        v->tam = tamAux;
        free(v->vet);
        v->vet = v2;
    }

    v->vet[v->qtd] = elemento;
    v->qtd++;

    return true;
}

bool vet_inserir(Vetor *v, int elemento, int posicao)
{

    if (v->qtd >= v->tam)
    {

        int tamAux = v->tam * 2;

        int *v2;
        v2 = (int *)calloc(tamAux, sizeof(int));

        for (int i = 0; i < v->tam; i++)
        {
            v2[i] = v->vet[i];
        }

        v->tam = tamAux;
        free(v->vet);
        v->vet = v2;
    }

    int *v2 = (int *)calloc(v->tam, sizeof(int));

    int aux;

    for (int i = 0; i < v->tam; i++)
    {
        if (i < posicao)
        {
            v2[i] = v->vet[i];
        }
        if (i == posicao)
        {
            aux = v->vet[i];
            v2[i] = elemento;
        }
        if (i > posicao)
        {
            v2[i] = aux;
            aux = v->vet[i];
        }
    }

    v->vet = v2;
    v->qtd++;

    return true;
}

bool vet_substituir(Vetor *v, int posicao, int novoElemento)
{
    v->vet[posicao] = novoElemento;

    return true;
}

bool vet_removerPosicao(Vetor *v, int posicao, int *endereco)
{
    *endereco = v->vet[posicao];
    free(v->vet[posicao]);
    v->vet[posicao] = NULL;

    return true;
}

int vet_removerElemento(Vetor *v, int elemento)
{

    int pos = -1;

    for (int i = 0; i < v->qtd; i++)
    {
        if (v->vet[i] == elemento)
        {
            pos = i;
            v->vet[i] = NULL;
            free(v->vet[i]);
        }
    }

    return pos;
}
int vet_tamanho(Vetor *v)
{
    return v->qtd;
}
bool vet_elemento(Vetor *v, int posicao, int *saida)
{

    if (v->vet[posicao] == NULL)
    {
        return false;
    }

    *saida = v->vet[posicao];
    return true;
}
int vet_posicao(Vetor *v, int elemento)
{

    for (int i = 0; i < v->qtd; i++)
    {
        if (v->vet[i] == elemento)
        {
            return i;
        }
    }
}
void vet_imprimir(Vetor *v)
{

    printf("[");
    for (int i = 0; i < v->tam; i++)
    {

        printf("%i", v->vet[i]);

        if (i < v->tam - 1)
        {
            printf(", ");
        }
    }
    printf("]");
}

void vet_desalocar(Vetor **endVetor)
{
    free(endVetor);
    endVetor = NULL;
}

bool vet_toString(Vetor *v, char *saida)
{
    if (v == NULL)
    {
        return false;
    }

    saida[0] = '\0';

    strcat(saida, "["); // insere na string o valor passado

    for (int i = 0; i < v->tam; i++)
    {
        char casting[50];

        sprintf(casting, "%d", v->vet[i]);
        strcat(saida, casting);

        if (i < (v->tam) - 1)
        {
            strcat(saida, ",");
        }
    }

    strcat(saida, "]\n");

    return true;
}