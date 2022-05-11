#include <stdio.h>
#include <string.h>

#include "fila.h"

int main()
{

    Teste *t1 = teste_criar("Teste da FILA");
    char str[200];
    TipoElemento elemento;

    /**************************************
     * Teste insercao e primeiro
     **************************************/
    Fila *f1 = fila_criar();
    fila_inserir(f1, 10);
    fila_inserir(f1, 20);
    fila_inserir(f1, 30);
    fila_toString(f1, str);
    teste_verificar(t1, strcmp(str, "[10,20,30]") == 0, "Teste insercao");

    fila_primeiro(f1, &elemento);
    teste_verificar(t1, elemento == 10, "Teste primeiro");

    /**************************************
     * Teste remocao
     **************************************/
    fila_remover(f1, &elemento);
    teste_verificar(t1, elemento == 10, "Teste Remocao 1/4");

    fila_remover(f1, &elemento);
    teste_verificar(t1, elemento == 20, "Teste Remocao 2/4");

    fila_remover(f1, &elemento);
    teste_verificar(t1, elemento == 30, "Teste Remocao 3/4");

    bool resultado = fila_remover(f1, &elemento);
    teste_verificar(t1, resultado == false, "Teste Remocao 4/4 (fila vazia)");
    fila_destruir(&f1);

    /**************************************
     * Teste inserir todos e clone
     **************************************/
    int vetor[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    f1 = fila_criar();
    fila_inserirTodos(f1, vetor, 12);

    fila_toString(f1, str);
    teste_verificar(t1, strcmp(str, "[1,2,3,4,5,6,7,8,9,10,11,12]") == 0, "Teste inserir todos");

    Fila *f2 = fila_clone(f1);
    fila_remover(f2, &elemento);
    fila_remover(f2, &elemento);
    fila_remover(f2, &elemento);
    fila_inserir(f2, 20);
    fila_inserir(f2, 21);
    fila_inserir(f2, 22);

    fila_toString(f2, str);
    teste_verificar(t1, strcmp(str, "[4,5,6,7,8,9,10,11,12,20,21,22]") == 0, "Teste clone");

    fila_destruir(&f1);
    fila_destruir(&f2);

    teste_relatorio(t1);
    teste_desalocar(&t1);
}