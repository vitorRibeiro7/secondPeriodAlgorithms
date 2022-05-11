#include "fila.h"

#define TAM_INICIAL 5
/**************************************
 * DADOS
 **************************************/
struct fila
{
	TipoElemento *vetor;
	int tamVetor;
	int inicio;
	int fim;
	int qtdeElementos;
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
