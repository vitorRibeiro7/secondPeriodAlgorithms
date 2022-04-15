#include <stdio.h>
#include <stdlib.h>

int vet[] = {};

int main(void)
{

    int s = 10; // size
    int i = 0;
    int number = 7; // number to be found
    int count = 0;

    // ENTRADA

    catch_a_vetor(s, vet);

    // PROCESSAMENTO

    count = identfy_a_number(s, vet, number);

    // SAIDA

    print_a_vetor(s, vet, number, count);

    return 0;
}

void catch_a_vetor(int s, int vetor[])
{

    FILE *entrada;

    entrada = fopen("entrada.txt", "r");

    for (int i = 0; i < s; i++)
    {
        fscanf(entrada, "%i", &vetor[i]);
    }

    fclose(entrada);
}

int identfy_a_number(int s, int vetor[], int n)
{

    int count = 0;

    for (int i = 0; i < s; i++)
    {
        if (vetor[i] == n)
        {
            count++;
        }
    }

    return count;
}

void print_a_vetor(int s, int vetor[], int number, int count)
{

    FILE *saida;

    saida = fopen("saida.txt", "w");

    for (int i = 0; i < s; i++)
    {
        if (vetor[i] == number)
        {
            fprintf(saida, "|");
            fprintf(saida, "%i", vetor[i]);
            fprintf(saida, "| ");
        }
        else
        {
            fprintf(saida, "%i ", vetor[i]);
        }
    }

    fprintf(saida, "\n\n");

    if (count > 0)
    {
        fprintf(saida, "O numero %i aparece %i vezes no vetor", number, count);
    }
    else
    {
        fprintf(saida, "O numero %i não aparece no vetor", number);
    }

    printf("LOADED.\n");

    fclose(saida);
}