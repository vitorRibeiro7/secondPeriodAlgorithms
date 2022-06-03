#include "fila.h"
#include <string.h>

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
bool fila_inserir(Fila *f, TipoElemento elemento)
{

	if (f == NULL || elemento == NULL)
	{
		return false;
	}

	f->vetor[f->qtdeElementos] = elemento;
	f->qtdeElementos++;

	if (f->qtdeElementos > 0)
	{
		f->fim++;
		}

	return true;
}
bool fila_remover(Fila *f, TipoElemento *saida)
{

	int *aux = calloc(f->qtdeElementos, sizeof(int));

	*saida = f->vetor[0];

	for (int i = 0; i < f->qtdeElementos; i++)
	{
		aux[i] = f->vetor[i];
	}

	for (int i = 0; i < f->qtdeElementos; i++)
	{
		f->vetor[i] = 0;
	}

	int j = 1;

	for (int i = 0; i < f->qtdeElementos; i++)
	{
		f->vetor[i] = aux[j];
		j++;
	}

	if (f->qtdeElementos > 0)
	{
		f->fim--;
	}

	if (f->qtdeElementos == 0)
	{
		return false;
	}

	return true;
}
bool fila_primeiro(Fila *f, TipoElemento *saida)
{
	*saida = f->vetor[0];

	return true;
}
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
void fila_imprimir(Fila *f)
{

	for (int i = 0; i < f->tamVetor; i++)
	{
		printf("[");
		printf("%i");
		if (i < f->qtdeElementos - 1)
		{
			printf(", ");
		}
		printf("]");
	}
}
Fila *fila_clone(Fila *f)
{

	Fila *aux = (Fila *)malloc(sizeof(Fila));
	aux->vetor = (int *)calloc(f->tamVetor, sizeof(int));

	for (int i = 0; i < f->qtdeElementos; i++)
	{
		aux->vetor[i] = f->vetor[i];
	}

	aux->inicio = f->inicio;
	aux->fim = f->fim;
	aux->qtdeElementos = f->qtdeElementos;
	aux->tamVetor = f->tamVetor;

	return aux;
}
bool fila_toString(Fila *f, char *str)
{
	if (f == NULL)
	{
		return false;
	}

	str[0] = '\0';

	strcat(str, "["); // insere na string o valor passado

	for (int i = 0; i < f->qtdeElementos; i++)
	{
		char casting[50];

		sprintf(casting, "%d", f->vetor[i]);
		strcat(str, casting);

		if (i < (f->qtdeElementos) - 1)
		{
			strcat(str, ",");
		}
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
