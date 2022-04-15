#include <stdio.h>

int main()
{
    int firstNumber, secondNumber;

    // ENTRADA
    printf("firstNumber: \n");
    scanf("%d", &firstNumber);
    printf("scondNumber: \n");
    scanf("%d", &secondNumber);

    // PROCESSAMENTO
    int soma = firstNumber + secondNumber;

    printf("\n");

    // SAÍDA
    printf("soma: \n");
    printf("%d\n", soma);

    return 0;
}