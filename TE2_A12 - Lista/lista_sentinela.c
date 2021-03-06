#include "lista.h"

/**************************************
 * DADOS
 **************************************/

typedef struct lista
{
    No *sentinela;
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

Lista *lista_criar()
{

    Lista *new = (Lista *)malloc(sizeof(Lista));
    new->qtde = 0;
    No *sent = (No *)malloc(sizeof(No));
    new->sentinela = sent;
    sent->ant = sent;
    sent->prox = sent;

    return new;
}
void lista_destruir(Lista **endereco)
{
    No *lista = (*endereco);
    No *aux = (*endereco)->sentinela;
    No *aux2 = (*endereco)->sentinela;
    aux = aux->prox;

    while (aux != (*endereco)->sentinela)
    {
        free(aux);
        aux = aux->prox;
    }

    free(aux2);
    free(lista);
}

bool lista_anexar(Lista *l, TipoElemento elemento)
{

    if (l == NULL)
    {
        return false;
    }

    No *node = (No *)malloc(sizeof(No));
    node->ant = NULL;
    node->prox = NULL;
    node->dado = elemento;

    No *sent = l->sentinela;

    if (l->qtde == 0)
    {
        sent->prox = node;
        sent->ant = node;
        node->prox = sent;
        node->ant = sent;
    }
    else
    {
        sent->ant->prox = node;
        node->ant = sent->ant;
        sent->ant = node;
        node->prox = sent;
    }

    l->qtde++;

    return true;
}
bool lista_inserir(Lista *l, TipoElemento elemento, int posicao)
{

    if (l == NULL)
    {
        return false;
    }

    No *node = (No *)malloc(sizeof(No));
    node->ant = NULL;
    node->prox = NULL;
    node->dado = elemento;

    No *sent = l->sentinela;

    No *aux = l->sentinela;

    if (posicao == 0)
    {
        aux->prox = node;
        aux->ant = node;
        node->prox = aux;
        node->ant = aux;
    }
    else if (posicao == l->qtde)
    {
        lista_anexar(l, elemento);
    }

    aux = aux->prox;

    for (int i = 0; i < posicao; i++)
    {
        aux = aux->prox;
    }

    node->ant = aux->ant;
    aux->ant->prox = node;
    aux->ant = node;
    node->prox = aux;

    l->qtde++;

    return true;
}

bool lista_removerPosicao(Lista *l, int posicao, TipoElemento *endereco)
{
    if (l == NULL)
    {
        return false;
    }

    No *sent = l->sentinela;

    No *aux = l->sentinela;
    aux = aux->prox;

    if (l->qtde == 0)
    {
        *endereco = aux->dado;

        free(aux);
        sent->ant = sent;
        sent->prox = sent;

        l->qtde--;

        return true;
    }
    else if (posicao == l->qtde)
    {

        aux = sent->ant;

        sent->ant = aux->ant;
        aux->ant->prox = sent;

        *endereco = aux->dado;

        free(aux);

        l->qtde--;

        return true;
    }
    else
    {

        aux = sent->prox;

        for (int i = 0; i < posicao; i++)
        {
            aux = aux->prox;
        }

        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;

        *endereco = aux->dado;
        free(aux);

        l->qtde--;
    }

    return true;
}
int lista_removerElemento(Lista *l, TipoElemento elemento)
{

    No *sent = l->sentinela;

    No *aux = l->sentinela;
    aux = aux->prox;

    int elem = 0;

    for (int i = 0; i < l->qtde; i++)
    {
        if (aux->dado == elemento)
        {
            lista_removerPosicao(l, i, &elem);
        }

        aux = aux->prox;
    }

    return elem;
}

bool lista_substituir(Lista *l, int posicao, TipoElemento novoElemento)
{
    if (l == NULL)
    {
        return false;
    }

    No *aux = l->sentinela;
    aux = aux->prox;

    if (posicao == 0)
    {
        aux->dado = novoElemento;
    }

    for (int i = 0; i < posicao; i++)
    {
        aux = aux->prox;
    }

    aux->dado = novoElemento;

    return true;
}
int lista_posicao(Lista *l, TipoElemento elemento)
{
    if (l == NULL)
    {
        return false;
    }

    int pos = -1;

    No *aux = l->sentinela;
    aux = aux->prox;

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
    if (l == NULL)
    {
        return true;
    }

    No *aux = l->sentinela;
    aux = aux->prox;

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

int lista_tamanho(Lista *l)
{
    return l->qtde;
}
bool lista_vazia(Lista *l)
{
    if (l->qtde == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool lista_toString(Lista *l, char *str)
{
    if (l == NULL)
    {
        return false;
    }

    No *aux = l->sentinela;
    aux = aux->prox;

    str[0] = '\0';

    strcat(str, "["); // insere na string o valor passado

    for (int i = 0; i < l->qtde; i++)
    {
        char casting[50];

        sprintf(casting, "%d", aux->dado);
        strcat(str, casting);

        if (i < (l->qtde) - 1)
        {
            strcat(str, ",");
        }

        aux = aux->prox;
    }

    strcat(str, "]\n");

    return true;
}

/**************************************
 * AUXILIARES
 **************************************/
void lista_imprimir(Lista *l)
{

    No *aux = l->sentinela;
    aux = aux->prox;

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