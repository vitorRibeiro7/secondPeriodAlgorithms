#include <stdio.h>
#include "pilha.h"

int main()
{

    // Pilha *p1 = pilha_criar();
    // Pilha *p2;

    // pilha_empilhar(p1, 10);
    // pilha_empilhar(p1, 20);
    // pilha_empilhar(p1, 30);
    // pilha_empilhar(p1, 40);
    // pilha_empilhar(p1, 50);

    // pilha_imprimir(p1);

    // int posic;

    // pilha_topo(p1, &posic);

    // printf("\n %i", posic);

    // int tam;

    // tam = pilha_tamanho(p1);

    // printf("\n %i", tam);

    // p2 = pilha_clone(p1);

    // printf("\n");

    // pilha_imprimir(p2);

    // int desempilhado;

    // pilha_desempilhar(p1, &desempilhado);

    // printf("\n");

    // pilha_imprimir(p1);

    // printf("\nInversão da pilha:\n");

    // pilha_imprimir(p1);

    // pilha_inverter(p1);

    // pilha_imprimir(p1);

    // printf("\nEmpilhar todos:\n");

    // int vet[4] = {60, 70, 80, 90};

    // pilha_empilharTodos(p1, vet, 4);

    // pilha_imprimir(p1);

    // printf("\nPilha to string:\n");

    // char str[100];

    // pilha_toString(p1, &str);

    // printf("%s", str);

    // ------------------------------------------------------------------------

    Pilha *p1 = pilha_criar();

    pilha_empilhar(p1, 10);
    pilha_empilhar(p1, 20);
    pilha_empilhar(p1, 30);
    pilha_empilhar(p1, 40);
    pilha_empilhar(p1, 50);

    pilha_imprimir(p1);

    pilha_destruir((p1));
    printf(" opa \n\n\n\n %u", &p1);

    return 0;
}