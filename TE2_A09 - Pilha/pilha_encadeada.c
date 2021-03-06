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

    int b;

    for (int i = 0; i < (*endereco)->qtdeElementos; i++)
    {
        pilha_desempilhar((*endereco), &b);
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
bool pilha_desempilhar(Pilha *p, TipoElemento *saida)
{

    No *aux = p->topo;
    No *aux2 = p->topo;

    if (p->topo->prox == NULL)
    {
        *saida = p->topo->dado;

        free(p->topo);
        p->topo = NULL;
        p->qtdeElementos = 0;

        return false;
    }

    for (int i = 0; i < p->qtdeElementos - 2; i++)
    {
        aux2 = aux2->prox;
    }

    for (int i = 0; i < p->qtdeElementos; i++)
    {

        if (aux->prox != NULL)
        {
            aux = aux->prox;
        }
    }

    *saida = aux->dado;

    aux2->prox = NULL;
    free(aux);
    aux = NULL;

    p->qtdeElementos--;

    return true;
}
bool pilha_topo(Pilha *p, TipoElemento *saida)
{

    if (p == NULL)
    {
        return false;
    }

    *saida = p->topo->dado;

    return true;
}
bool pilha_vazia(Pilha *p)
{

    if (p->topo == NULL)
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

    printf("hmm\n");

    No *aux = p->topo;

    if (p->qtdeElementos <= 0)
    {
        printf("Não ha nada pra imprimir.\n");
    }

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

    Pilha *clone;
    clone = pilha_criar();

    No *aux = p->topo;

    while (aux != NULL)
    {
        pilha_empilhar(clone, aux->dado);
        aux = aux->prox;
    }

    return clone;
}
void pilha_inverter(Pilha *p)
{

    No *aux = p->topo;
    Pilha *inverse = pilha_criar();

    int tam = p->qtdeElementos;
    int i = 0;

    int *vet = (int *)calloc(tam, sizeof(int));

    while (aux != NULL)
    {
        vet[i] = aux->dado;
        aux = aux->prox;
        i++;
    }

    for (int i = 0; i < p->qtdeElementos; i++)
    {
        int a;
        pilha_desempilhar(p, &a);
    }

    int j = p->qtdeElementos - 1;

    for (int i = 0; i < p->qtdeElementos; i++)
    {
        pilha_empilhar(inverse, vet[j]);
        j--;
    }

    p->topo = inverse->topo;
}
bool pilha_empilharTodos(Pilha *p, TipoElemento *vetor, int tamVetor)
{

    if (p == NULL)
    {
        return false;
    }

    for (int i = 0; i < tamVetor; i++)
    {
        pilha_empilhar(p, vetor[i]);
    }

    return true;
}
bool pilha_toString(Pilha *f, char *str);
