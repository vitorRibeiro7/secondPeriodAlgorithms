#include "pilha.h"

#define TAM_INICIAL 5

/**************************************
 * DADOS
 **************************************/
struct pilha
{
    TipoElemento *vetor;
    int tamVetor;
    int qtdeElementos;
};

/**************************************
 * IMPLEMENTAÇÃO
 **************************************/
// Desenvolva as funções
Pilha *pilha_criar()
{
    Pilha *p;

    p = (Pilha *)malloc(sizeof(Pilha));
    p->vetor = (int *)malloc(TAM_INICIAL * sizeof(int));
    p->tamVetor = TAM_INICIAL;
    p->qtdeElementos = 0;

    return p;
}
void pilha_destruir(Pilha **endereco)
{

    Pilha *b = *endereco;
    free(b->vetor);
    b->vetor = NULL;
    free(b);
    b = NULL;
}
bool pilha_empilhar(Pilha *p, TipoElemento elemento)
{

    if (p == NULL)
    {
        return false;
    }

    p->vetor[p->qtdeElementos] = elemento;
    p->qtdeElementos++;

    return true;
}
bool pilha_desempilhar(Pilha *p, TipoElemento *saida)
{
    for (int i = 0; i < p->qtdeElementos; i++)
    {
        if (i == p->qtdeElementos - 1)
        {
            *saida = p->vetor[i];
            p->vetor[i] = NULL;
            p->qtdeElementos--;
        }
    }
}
bool pilha_topo(Pilha *p, TipoElemento *saida)
{

    *saida = p->vetor[p->qtdeElementos - 1];

    return true;
}
bool pilha_vazia(Pilha *p)
{
    if (!p->vetor[0])
    {
        return true;
    }
    else
    {
        return false;
    }
}
void pilha_imprimir(Pilha *p)
{
    for (int i = 0; i < p->qtdeElementos; i++)
    {
        printf("%i ", p->vetor[i]);
    }
}
int pilha_tamanho(Pilha *p)
{
    return p->qtdeElementos;
}
Pilha *pilha_clone(Pilha *p)
{
    Pilha *aux;
    aux = (Pilha *)malloc(sizeof(Pilha));
    aux->vetor = (int *)malloc(p->tamVetor * sizeof(int));
    aux->qtdeElementos = p->qtdeElementos;

    for (int i = 0; i < p->qtdeElementos; i++)
    {
        aux->vetor[i] = p->vetor[i];
    }

    return aux;
}
void pilha_inverter(Pilha *p);
bool pilha_empilharTodos(Pilha *p, TipoElemento *vetor, int tamVetor);
bool pilha_toString(Pilha *f, char *str);