// tad_vetor.c
#include "tad-vetor.h"
#define TAMANHO 10
#include <stdio.h>

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

    v->vet[posicao] = elemento;
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
}
int vet_tamanho(Vetor *v);
bool vet_elemento(Vetor *v, int posicao, int *saida);
int vet_posicao(Vetor *v, int elemento);
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

void vet_desalocar(Vetor **endVetor);
bool vet_toString(Vetor *v, char *saida);