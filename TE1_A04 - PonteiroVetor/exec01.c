#include <stdio.h>

int main()
{

    int v[4] = {1, 2, 3, 4};

    int *p = v;

    int *w = p + 2;

    int i = 30;
    int *x = i;

    printf("%i\n", *p);
    printf("%i\n", *p + 1);
    printf("%i\n", *p + 2);
    printf("%i\n", *p + 3);

    return 0;
}