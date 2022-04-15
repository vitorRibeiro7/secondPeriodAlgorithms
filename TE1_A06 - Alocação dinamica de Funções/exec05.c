#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
        int codigo;
        char nome[50];
        float preco;
} produto;

void createProduct(int codigo, char nome[], float preco, produto **saida);
void printProduct(produto *product);

int main()
{

        int codigo = 2399121;
        char nome[] = "VITOR <3";
        float preco = 3.14;

        produto *produtoOne;

        createProduct(codigo, nome, preco, &produtoOne);

        printf("Nome: %s\n", produtoOne->nome);
        printf("Codigo: %i\n", produtoOne->codigo);
        printf("preco: %f\n", produtoOne->preco);

        printProduct(produtoOne);

        return 0;
}

void createProduct(int codigo, char nome[], float preco, produto **saida)
{

        produto *product = (produto *)calloc(1, sizeof(produto));

        product->codigo = codigo;
        strcpy(product->nome, nome);
        product->preco = preco;

        // printf("Nome: %s\n", product->nome);
        // printf("Codigo: %i\n", product->codigo);
        // printf("preco: %1.f\n", product->preco);

        *saida = product;
}

void printProduct(produto *product)
{

        printf("Nome: %s\n", product->nome);
        printf("Codigo: %i\n", product->codigo);
        printf("preco: %f\n", product->preco);
}