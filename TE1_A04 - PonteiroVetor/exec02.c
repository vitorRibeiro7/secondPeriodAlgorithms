#include <stdio.h>

int main()
{

    int a = 10;
    int b = 20;
    int c = 30;
    int d = 40;

    int *vet[4] = {&a, &b, &c, &d};

    for (int i = 0; i < 4; i++)
    {
        printf("v[i] = %i \n", *vet[i]);
    }

    int **p = vet;

    printf("%u\n", p);
    printf("%u", vet);

    printf("\n");

    for (int i = 0; i < 4; i++)
    {
        printf("vet[i] = %i \n", *vet[i]);
    }

    return 0;
}