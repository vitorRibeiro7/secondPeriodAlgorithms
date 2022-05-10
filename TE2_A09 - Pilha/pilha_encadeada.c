#include "pilha.h"

/**************************************
 * DADOS
 **************************************/
typedef struct no
{
    TipoElemento dado;
    struct no *prox;
} No;

struct pilha
{
    No *topo;
    int qtdeElementos;
};

/**************************************
 * IMPLEMENTAÇÃO
 **************************************/
// Desenvolva as funçõesu
Pilha *pilha_criar()
{

    Pilha *aux;
    aux = (Pilha *)malloc(sizeof(Pilha));

    aux->topo = NULL;
    aux->qtdeElementos = 0;

    return aux;
}
void pilha_destruir(Pilha **endereco)
{

    No *node = (*endereco)->topo;
    No *aux = node;

    while (aux->prox != NULL)
    {
        aux = aux->prox;
        free(aux);
    }

    free((*endereco)->topo);
    (*endereco)->topo = NULL;
    (*endereco)->qtdeElementos = NULL;
    free((*endereco));
}
bool pilha_empilhar(Pilha *p, TipoElemento elemento)
{
    No *node = (No *)malloc(sizeof(No));
    if (node == NULL)
    {
        printf("Erro de alocação. \n");
    }
    else
    {
        node->dado = elemento;
        node->prox = NULL;
    }

    if (p->topo == NULL)
    {
        p->topo = node;
    }
    else
    {
        No *aux = p->topo;

        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }

        aux->prox = node;
    }

    p->qtdeElementos++;

    return true;
}
bool pilha_desempilhar(Pilha *p, TipoElemento *saida);
bool pilha_topo(Pilha *p, TipoElemento *saida);
bool pilha_vazia(Pilha *p);
void pilha_imprimir(Pilha *p)
{

    printf("hmm\n");

    No *aux = p->topo;

    for (int i = 0; i < p->qtdeElementos; i++)
    {
        printf("%i ", aux->dado);
        aux = aux->prox;
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
    aux->qtdeElementos = p->qtdeElementos;
    aux->topo = p->topo;

    return aux;
}
void pilha_inverter(Pilha *p);
bool pilha_empilharTodos(Pilha *p, TipoElemento *vetor, int tamVetor);
bool pilha_toString(Pilha *f, char *str);