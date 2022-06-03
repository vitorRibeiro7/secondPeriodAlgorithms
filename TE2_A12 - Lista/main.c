#include <stdio.h>
#include <string.h>

#include "lista.h"

int main()
{

        Lista *l = lista_criar();

        lista_anexar(l, 10);
        lista_anexar(l, 20);
        lista_anexar(l, 40);
        lista_inserir(l, 30, 2);

        printf("hmm\n");

        lista_imprimir(l);

        return 0;
}