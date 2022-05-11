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
Fila *fila_criar();
void fila_destruir(Fila **enderecoFila);
bool fila_inserir(Fila *f, TipoElemento elemento);
bool fila_remover(Fila *f, TipoElemento *saida);  // estratégia do scanf
bool fila_primeiro(Fila *f, TipoElemento *saida); // estratégia do scanf
bool fila_vazia(Fila *f);
int fila_tamanho(Fila *f);
void fila_imprimir(Fila *f);
Fila *fila_clone(Fila *f);
bool fila_toString(Fila *f, char *str);
bool fila_inserirTodos(Fila *f, TipoElemento *vetor, int tamVetor);
