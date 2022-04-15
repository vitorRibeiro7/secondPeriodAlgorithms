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

    Produto prod = {1, "Tecido", 98.5};
    Produto *p = &prod;

    int *pi = &prod.codigo;
    char *pc = &prod.descricao;
    float *pf = &prod.preco;

    *pi = 23;
    strcpy(pc, "Abobora");
    *pf = 73.6;

    printf("%i\n", *pi);
    printf("%s\n", pc);
    printf("%f\n", *pf);

    return 0;
}