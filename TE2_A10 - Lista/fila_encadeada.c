#include "fila.h"

/**************************************
 * DADOS
 **************************************/
typedef struct no
{
    int dado;
    struct no *prox;
} No;

struct fila
{
    No *inicio;
    No *fim;
    int qtde;
};

/**************************************
 * IMPLEMENTAÇÃO
 **************************************/
Fila *fila_criar()
{
    Fila *aux = (Fila *)malloc(sizeof(Fila));
    aux->fim = NULL;
    aux->inicio = NULL;
    aux->qtde = 0;

    return aux;
}
void fila_destruir(Fila **enderecoFila)
{
    No *aux;
    Fila *f = enderecoFila;

    while (f->inicio != NULL)
    {
        aux = f->inicio;
        f->inicio = f->inicio->prox;
        free(aux);
    }

    free(*enderecoFila);

    return true;
}
bool fila_inserir(Fila *f, TipoElemento elemento)
{

    if (f == NULL)
    {
        return false;
    }

    No *node = (No *)malloc(sizeof(No));
    node->dado = elemento;
    node->prox = NULL;

    if (f->inicio == NULL)
    {
        f->inicio = node;
        f->fim = node;
    }
    else
    {
        f->fim->prox = node;
        f->fim = node;
    }

    return true;
}
bool fila_remover(Fila *f, TipoElemento *saida);  // estratégia do scanf
bool fila_primeiro(Fila *f, TipoElemento *saida); // estratégia do scanf
bool fila_vazia(Fila *f);
int fila_tamanho(Fila *f);
void fila_imprimir(Fila *f);
Fila *fila_clone(Fila *f);
bool fila_toString(Fila *f, char *str);
bool fila_inserirTodos(Fila *f, TipoElemento *vetor, int tamVetor);
