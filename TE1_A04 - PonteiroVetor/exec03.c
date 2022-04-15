#include <stdio.h>

int main()
{

    int v1[3] = {1, 2, 3};
    int v2[3] = {4, 5, 6};
    int *p1 = v1;
    int *p2 = v2;
    int *m[2];
    m[0] = v1;
    m[1] = v2;
    int **pm = m;

    for (int i = 0; i < 3; i++)
    {
        printf("v1[%i] = %i\n", i, v1[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        printf("v2[%i] = %i\n", i, v2[i]);
    }

    return 0;
}