#include <stdio.h>

int vet[] = {};

int main()
{

    int s = 5; // size
    int amount;

    // ENTRADA
    catch_a_vetor(s, vet);

    // PROCESSAMENTO
    amount = add_a_vetor(s, vet);

    // SAIDA
    print_a_numbers(amount);

    return 0;
}

void catch_a_vetor(int s, int vet[s])
{
    FILE *entrada;
    entrada = fopen("entrada.txt", "r");

    for (int i = 0; i < s; i++)
    {
        fscanf(entrada, "%i", &vet[i]);
    }

    fclose(entrada);
}

int add_a_vetor(int s, int vet[s])
{
    int amount = 0;

    for (int i = 0; i < s; i++)
    {
        amount += vet[i];
    }


    return amount;
}

void print_a_numbers(int amount)
{
    FILE *saida;
    saida = fopen("saida.txt", "w");

    fprintf(saida, "Valor da soma = %i\n\n", amount);

    fclose(saida);
}