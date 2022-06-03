#include "lista.h"
#include <string.h>

#define TAM_INICIAL 10

/**************************************
 * DADOS
 **************************************/
struct lista
{
	TipoElemento *vetor;
	int tam;
	int qtde;
};

/**************************************
 * IMPLEMENTAÇÃO
 **************************************/
Lista *lista_criar() // OK
{
	Lista *new = (Lista *)malloc(sizeof(Lista));
	new->vetor = (int *)calloc(TAM_INICIAL, sizeof(int));
	new->qtde = 0;
	new->tam = TAM_INICIAL;

	return new;
}
void lista_destruir(Lista **endereco) // OK
{

	Lista *aux = *endereco;
	free(aux->vetor);
	free(aux);
}

bool lista_anexar(Lista *l, TipoElemento elemento) // OK
{

	if (l->vetor == NULL)
	{
		return false;
	}

	l->vetor[l->qtde] = elemento;

	l->qtde++;

	return true;
}
bool lista_inserir(Lista *l, TipoElemento elemento, int posicao) // OK
{

	if (l->vetor == NULL)
	{
		return false;
	}

	int *v2 = (int *)calloc(l->tam, sizeof(int));

	int aux;

	for (int i = 0; i < l->tam; i++)
	{
		if (i < posicao)
		{
			v2[i] = l->vetor[i];
		}
		if (i == posicao)
		{
			aux = l->vetor[i];
			v2[i] = elemento;
		}
		if (i > posicao)
		{
			v2[i] = aux;
			aux = l->vetor[i];
		}
	}

	l->vetor = v2;
	l->qtde++;

	return true;
}

bool lista_removerPosicao(Lista *l, int posicao, TipoElemento *endereco)
{

	if (l->vetor == NULL)
	{
		return false;
	}

	*endereco = l->vetor[posicao];
	l->vetor[posicao] = NULL;

	int *v2 = (int *)calloc(l->tam, sizeof(int));

	int aux;

	for (int i = 0; i < l->qtde; i++)
	{
		if (i < posicao)
		{
			v2[i] = l->vetor[i];
		}
		if (i == posicao)
		{
			v2[i] = l->vetor[i + 1];
		}
		if (i > posicao)
		{
			aux = l->vetor[i + 1];
			v2[i] = aux;
		}
	}

	l->vetor = v2;
	l->qtde--;

	return true;
}
int lista_removerElemento(Lista *l, TipoElemento elemento);

bool lista_substituir(Lista *l, int posicao, TipoElemento novoElemento);
int lista_posicao(Lista *l, TipoElemento elemento);
bool lista_buscar(Lista *l, int posicao, TipoElemento *endereco);

int lista_tamanho(Lista *l);
bool lista_vazia(Lista *l);
bool lista_toString(Lista *l, char *str);

void lista_imprimir(Lista *l)
{

	printf("[");
	for (int i = 0; i < l->tam; i++)
	{
		printf("%i", l->vetor[i]);

		if (i < l->tam - 1)
		{
			printf(", ");
		}
	}
	printf("]");
}