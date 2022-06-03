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
        lista_anexar(l, 50);
        lista_anexar(l, 60);
        lista_anexar(l, 80);
        lista_inserir(l, 70, 6);

        int removido;
        lista_removerPosicao(l, 1, &removido);
        printf("%i", removido);
        lista_removerPosicao(l, 4, &removido);
        printf("%i", removido);

        lista_imprimir(l);

        return 0;
}