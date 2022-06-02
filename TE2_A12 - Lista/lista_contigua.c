#include "lista.h"
#include <string.h>

#define TAM_INICIAL 10

/**************************************
 * DADOS
 **************************************/
typedef struct
{
	TipoElemento *vetor;
	int tam;
	int qtde;
} Lista;

/**************************************
 * IMPLEMENTAÇÃO
 **************************************/
Lista *lista_criar()
{
	Lista *new = (Lista *)malloc(sizeof(Lista));
	new->vetor = (int *)calloc(TAM_INICIAL, sizeof(int));
	new->qtde = 0;
	new->tam = TAM_INICIAL;

	return new;
}
void lista_destruir(Lista **endereco)
{

	Lista *aux = *endereco;
	free(aux->vetor);
	free(aux);
}

bool lista_anexar(Lista *l, TipoElemento elemento)
{

	if (l->vetor == NULL)
	{
		return false;
	}

	l->vetor[l->qtde] = elemento;

	l->qtde++;

	return true;
}
bool lista_inserir(Lista *l, TipoElemento elemento, int posicao)
{

	if (l->vetor == NULL)
	{
		/* code */
	}
}

bool lista_removerPosicao(Lista *l, int posicao, TipoElemento *endereco);
int lista_removerElemento(Lista *l, TipoElemento elemento);

bool lista_substituir(Lista *l, int posicao, TipoElemento novoElemento);
int lista_posicao(Lista *l, TipoElemento elemento);
bool lista_buscar(Lista *l, int posicao, TipoElemento *endereco);

int lista_tamanho(Lista *l);
bool lista_vazia(Lista *l);
bool lista_toString(Lista *l, char *str);