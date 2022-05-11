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
Fila *fila_criar()
{

	Fila *aux;
	aux = (Fila *)malloc(sizeof(Fila));
	aux->vetor = (int *)calloc(TAM_INICIAL, sizeof(int));
	aux->tamVetor = TAM_INICIAL;
	aux->inicio = 0;
	aux->fim = 0;
	aux->qtdeElementos = 0;

	return aux;
}
void fila_destruir(Fila **enderecoFila)
{
	Fila *aux = (*enderecoFila);
	free(aux->vetor);
	aux->vetor = NULL;
	aux->tamVetor = NULL;
	aux->inicio = NULL;
	aux->fim = NULL;
	aux->qtdeElementos = NULL;
	free(aux);
	aux = NULL;
}
bool fila_inserir(Fila *f, TipoElemento elemento);
bool fila_remover(Fila *f, TipoElemento *saida);  // estratégia do scanf
bool fila_primeiro(Fila *f, TipoElemento *saida); // estratégia do scanf
bool fila_vazia(Fila *f)
{
	if (f->qtdeElementos == 0)
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
	return f->qtdeElementos;
}
void fila_imprimir(Fila *f);
Fila *fila_clone(Fila *f);
bool fila_toString(Fila *f, char *str);
bool fila_inserirTodos(Fila *f, TipoElemento *vetor, int tamVetor);
