// main.c
#include <stdio.h>
#include <stdlib.h>
#include "libs/tad-vetor.c"

int main()
{
    Vetor *v = vet_criar();

    vet_anexar(v, 1);
    vet_anexar(v, 2);
    vet_anexar(v, 30);
    vet_anexar(v, 10);
    vet_anexar(v, 20);
    vet_anexar(v, 30);
    vet_anexar(v, 10);
    vet_anexar(v, 20);
    vet_anexar(v, 30);
    vet_anexar(v, 30);
    vet_anexar(v, 11);
    vet_imprimir(v); // [10,20,30]

    // vet_inserir(v, 15, 1);
    // vet_imprimir(v); // [10,15,20,30]

    // vet_inserir(v, 5, 0);
    // vet_imprimir(v); // [5,10,15,20,30]

    // int elemento;
    // if (vet_removerPosicao(v, 1, &elemento))
    // {
    //     printf("O elemento %d foi removido\n", elemento); // O elemento 10 foi removido
    //     vet_imprimir(v);                                  // [5,15,20,30]
    // }

    // // if (vet_removerPosicao(v, 10, &elemento) == false){
    // if (!vet_removerPosicao(v, 10, &elemento))
    // {
    //     printf("Remocao invalida\n");
    // }

    // char str[200];
    // vet_toString(v, str);
    // printf("%s", str); //[5,15,20,30]
}