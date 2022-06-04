#include "lista.h"

/**************************************
 * DADOS
 **************************************/
typedef struct lista
{
    No *inicio;
    No *fim;
    int qtde;
} Lista;

typedef struct no
{
    TipoElemento dado;
    struct no *ant;
    struct no *prox;
} No;

/**************************************
 * IMPLEMENTAÇÃO
 **************************************/
Lista *lista_criar() // OK
{

    Lista *new = (Lista *)malloc(sizeof(Lista));
    new->qtde = 0;
    new->inicio = NULL;
    new->fim = NULL;
}
void lista_destruir(Lista **endereco) // OK
{
    No *aux = (No *)malloc(sizeof(No));
    aux = (*endereco)->inicio;

    while (aux != NULL)
    {
        free(aux);
        aux = aux->prox;
    }

    aux = (*endereco);
    free(aux);
}

bool lista_anexar(Lista *l, TipoElemento elemento) // OK
{

    No *node = (No *)malloc(sizeof(No));
    node->ant = NULL;
    node->dado = elemento;
    node->prox = NULL;

    if (l->inicio == NULL)
    {
        l->inicio = node;
        l->fim = node;
    }

    node->ant = l->fim;
    l->fim->prox = node;
    l->fim = node;

    l->qtde++;

    return true;
}
bool lista_inserir(Lista *l, TipoElemento elemento, int posicao) // OK
{

    if (l == NULL || posicao > l->qtde)
    {
        return false;
    }

    No *node = (No *)malloc(sizeof(No));
    node->ant = NULL;
    node->prox = NULL;
    node->dado = elemento;

    No *aux2 = (No *)malloc(sizeof(No));

    No *aux = (No *)malloc(sizeof(No));
    aux = l->inicio;

    for (int i = 0; i < l->qtde; i++)
    {

        if (i == posicao)
        {

            aux2 = aux;

            aux = aux->ant;
            node->ant = aux;
            aux->prox = node;
            node->prox = aux2;
            aux2->ant = node;
        }

        aux = aux->prox;
    }

    l->qtde++;
}

bool lista_removerPosicao(Lista *l, int posicao, TipoElemento *endereco);
int lista_removerElemento(Lista *l, TipoElemento elemento);

bool lista_substituir(Lista *l, int posicao, TipoElemento novoElemento) // OK
{

    if (l == NULL)
    {
        return false;
    }

    No *aux = (No *)malloc(sizeof(No));
    aux = l->inicio;

    for (int i = 0; i < l->qtde; i++)
    {
        if (i == posicao)
        {
            aux->dado = novoElemento;
        }

        aux = aux->prox;
    }

    return true;
}
int lista_posicao(Lista *l, TipoElemento elemento) // OK
{

    if (l == NULL)
    {
        return false;
    }

    No *aux = (No *)malloc(sizeof(No));
    aux = l->inicio;

    TipoElemento pos = -1;

    for (int i = 0; i < l->qtde; i++)
    {
        if (aux->dado == elemento)
        {
            pos = i;
        }

        aux = aux->prox;
    }

    return pos;
}
bool lista_buscar(Lista *l, int posicao, TipoElemento *endereco)
{
    if (l == NULL || posicao > l->qtde)
    {
        return false;
    }

    No *aux = (No *)malloc(sizeof(No));
    aux = l->inicio;

    for (int i = 0; i < l->qtde; i++)
    {

        if (i == posicao)
        {
            *endereco = aux->dado;
        }

        aux = aux->prox;
    }

    return true;
}

int lista_tamanho(Lista *l);
bool lista_vazia(Lista *l);
bool lista_toString(Lista *l, char *str);

/**************************************
 * AUXILIARES
 **************************************/
void lista_imprimir(Lista *l) // OK
{

    No *aux = (No *)malloc(sizeof(No));
    aux = l->inicio;

    printf("[");
    for (int i = 0; i < l->qtde; i++)
    {
        printf("%i", aux->dado);

        if (i < l->qtde - 1)
        {
            printf(", ");
        }

        aux = aux->prox;
    }
    printf("]");
}