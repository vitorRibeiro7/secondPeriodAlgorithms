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

    f->fim->prox = node;
    f->fim = node;

    f->qtde++;

    return true;
}
bool fila_remover(Fila *f, TipoElemento *saida)
{

    *saida = f->inicio->dado;

    No *aux = f->inicio;

    f->inicio = f->inicio->prox;

    free(aux);

    f->qtde--;

    return true;

} // estratégia do scanf
bool fila_primeiro(Fila *f, TipoElemento *saida)
{
    *saida = f->inicio->dado;
} // estratégia do scanf
bool fila_vazia(Fila *f)
{
    if (f->qtde == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int fila_tamanho(Fila *f)
{
    return f->qtde;
}
void fila_imprimir(Fila *f)
{

    No *aux = f->inicio;

    printf("[");

    for (int i = 0; i < f->qtde; i++)
    {
        printf("%i", aux->dado);
        aux = aux->prox;

        if (i < f->qtde - 1)
        {
            printf(",");
        }
    }

    printf("]");
}
Fila *fila_clone(Fila *f)
{
    Fila *clone;
    clone = fila_criar;

    No *aux = f->inicio;

    for (int i = 0; i < f->qtde; i++)
    {
        fila_inserir(clone, aux->dado);
        aux = aux->prox;
    }
}
bool fila_toString(Fila *f, char *str)
{
    if (f == NULL)
    {
        return false;
    }

    No *aux = f->inicio;

    str[0] = '\0';

    strcat(str, "["); // insere na string o valor passado

    for (int i = 0; i < f->qtde; i++)
    {
        char casting[50];

        sprintf(casting, "%d", aux->dado);
        strcat(str, casting);

        if (i < (f->qtde) - 1)
        {
            strcat(str, ",");
        }

        aux = aux->prox;
    }

    strcat(str, "]\n");

    return true;
}
bool fila_inserirTodos(Fila *f, TipoElemento *vetor, int tamVetor)
{

    for (int i = 0; i < tamVetor; i++)
    {
        fila_inserir(f, vetor[i]);
    }

    return true;
}
