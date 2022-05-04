#include <stdio.h>
#include "pilha.h"

int main()
{

    Pilha *p1 = pilha_criar();

    pilha_empilhar(p1, 10);
    pilha_empilhar(p1, 20);

    pilha_imprimir(p1);

    return 0;
}