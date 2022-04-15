#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{

    int firstNumber;
    int secondNumber;

    // ENTRDADA
    firstNumber = atoi(argv[1]);
    secondNumber = atoi(argv[2]);

    // PROCESSAMENTO
    int soma = firstNumber + secondNumber;

    // SAIDA
    printf("%i\n", soma);

    return 0;
}