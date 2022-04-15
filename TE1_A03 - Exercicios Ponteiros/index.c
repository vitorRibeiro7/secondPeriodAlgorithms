#include <stdio.h>

int main()
{

    // EXEC 01

    int i2 = 20;
    float f = 2.5;
    int *p1 = &i2;
    short int si = 30;
    short int *psi = &si;
    int **x = &p1;

    // EXEC 02

    int i1 = 15;
    int *p2 = i1;
    int **w = *p1;
    int ***z = **w;

    char c = 'b';
    char *pc = c;

    // EXEC 03

    return 0;
}