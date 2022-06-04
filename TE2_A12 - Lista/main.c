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
        lista_anexar(l, 100);
        lista_anexar(l, 60);
        lista_anexar(l, 80);
        lista_inserir(l, 70, 6);
        lista_imprimir(l);
        printf(" substituido valor na posicao");
        printf("\n");

        lista_substituir(l, 4, 50);
        lista_imprimir(l);
        printf(" ----------------------------'");
        printf("\n");
        printf("\n");

        int elemento = 60; // ELEMENTO A SER PROCURADO
        int pos;
        pos = lista_posicao(l, elemento);
        if (pos != -1)
        {
                printf("Elemento %i encontrado na posicao %i", elemento, pos);
        }
        else
        {
                printf("Elemento não encontrado.");
        }

        // printf("\n");

        // int removido;
        // lista_removerPosicao(l, 1, &removido);
        // printf("removido: %i", removido);
        // printf("\n");
        // lista_imprimir(l);
        // lista_removerPosicao(l, 6, &removido);
        // printf("removido: %i", removido);
        // printf("\n");
        // lista_imprimir(l);

        // int retorno;
        // retorno = lista_removerElemento(l, 40);
        // if (retorno == 0)
        // {
        //         printf("\nO elemento não existe!");
        // }
        // else
        // {
        //         printf("\nElemento removido!");
        // }

        // printf("\n");
        // lista_imprimir(l);

        return 0;
}