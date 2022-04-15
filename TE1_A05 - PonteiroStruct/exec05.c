#include <stdio.h>
#include <string.h>

int main()
{

    typedef struct produto
    {
        int codigo;
        char descricao[12];
        float preco;
    } Produto;

    Produto prodA = {1, "Teclado", 98.5};
    Produto prodB = {2, "Mouse", 65.0};
    Produto prodC = {3, "WebCam", 130.0};

    Produto vet[4];

    vet[0] = prodA;
    vet[1] = prodB;
    vet[2] = prodC;

    vet[2].codigo = 100;

    strcpy(vet[1].descricao, "Mouse sem fio");

    Produto prodD = {4, "HeadSet", 300.0};

    vet[3] = prodD;

    

    printf("%i, %s, %.1f", vet[3].codigo, vet[3].descricao, vet[3].preco);

    return 0;
}