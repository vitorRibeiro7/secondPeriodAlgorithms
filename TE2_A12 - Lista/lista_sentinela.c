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
        return true;
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
bool lista_inserir(Lista *l, TipoElemento elemento, int posicao);

bool lista_removerPosicao(Lista *l, int posicao, TipoElemento *endereco);
int lista_removerElemento(Lista *l, TipoElemento elemento);

bool lista_substituir(Lista *l, int posicao, TipoElemento novoElemento);
int lista_posicao(Lista *l, TipoElemento elemento);
bool lista_buscar(Lista *l, int posicao, TipoElemento *endereco);

int lista_tamanho(Lista *l);
bool lista_vazia(Lista *l);
bool lista_toString(Lista *l, char *str);

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