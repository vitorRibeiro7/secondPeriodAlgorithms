#include <stdio.h>
#include "pilha.h"

int main()
{

    Pilha *p1 = pilha_criar();
    Pilha *p2;

    pilha_empilhar(p1, 10);
    pilha_empilhar(p1, 20);
    pilha_empilhar(p1, 20);
    pilha_empilhar(p1, 20);
    pilha_empilhar(p1, 100);

    pilha_imprimir(p1);

    int posic;

    pilha_topo(p1, &posic);

    printf("\n %i", posic);

    int tam;

    tam = pilha_tamanho(p1);

    printf("\n %i", tam);

    p2 = pilha_clone(p1);

    printf("\n");

    pilha_imprimir(p2);

    int desempilhado;

    pilha_desempilhar(p1, &desempilhado);

    printf("\n");

    pilha_imprimir(p1);

    return 0;
}