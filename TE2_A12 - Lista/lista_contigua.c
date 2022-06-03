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

bool lista_removerPosicao(Lista *l, int posicao, TipoElemento *endereco) // OK
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
int lista_removerElemento(Lista *l, TipoElemento elemento) // OK
{

	int pos = -1;

	printf("\nRemocao solicitada: %i", elemento);

	for (int i = 0; i < l->qtde; i++)
	{
		if (l->vetor[i] == elemento)
		{
			pos = i;
		}
	}

	if (pos == -1)
	{
		return 0;
	}

	lista_removerPosicao(l, pos, &elemento);

	return elemento;
}

bool lista_substituir(Lista *l, int posicao, TipoElemento novoElemento) // OK
{
	if (l->vetor == NULL)
	{
		return false;
	}

	l->vetor[posicao] = novoElemento;

	return true;
}
int lista_posicao(Lista *l, TipoElemento elemento) // OK
{

	int pos = -1;

	for (int i = 0; i < l->qtde; i++)
	{
		if (l->vetor[i] == elemento)
		{
			pos = i;
		}
	}

	return pos;
}
bool lista_buscar(Lista *l, int posicao, TipoElemento *endereco) // OK
{

	if (l->vetor == NULL)
	{
		return false;
	}

	if (posicao > l->qtde)
	{
		return false;
	}

	for (int i = 0; i < l->qtde; i++)
	{
		if (i == posicao)
		{
			*endereco = i;
		}
	}

	return true;
}

int lista_tamanho(Lista *l) // OK
{
	return l->qtde;
}

bool lista_vazia(Lista *l) // OK
{
	if (l->vetor == NULL)
	{
		return false;
	}

	if (l->qtde == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool lista_toString(Lista *l, char *str) // OK
{

	if (l->vetor == NULL)
	{
		return false;
	}

	str[0] = '\0';

	strcat(str, "["); // insere na string o valor passado

	for (int i = 0; i < l->qtde; i++)
	{
		char casting[50];

		sprintf(casting, "%d", l->vetor[i]);
		strcat(str, casting);

		if (i < (l->qtde) - 1)
		{
			strcat(str, ",");
		}
	}

	strcat(str, "]\n");

	return true;
}

/**************************************
 * AUXILIARES
 **************************************/
void lista_imprimir(Lista *l) // OK
{

	printf("[");
	for (int i = 0; i < l->qtde; i++)
	{
		printf("%i", l->vetor[i]);

		if (i < l->qtde - 1)
		{
			printf(", ");
		}
	}
	printf("]");
	printf("\n");
}