#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[];

int main()
{

    int count;

    // ENTRADA

    catch_a_string(str);

    // PROCESSAMENTO

    count = vogal_amount(str);

    // SAIDA

    print_on_output(count, str);

    return 0;
}

void catch_a_string(char str[])
{

    FILE *entrada;
    entrada = fopen("entrada.txt", "r");

    for (int i = 0; i != str; i++) // PERGUNTAR AO PROFESSOR POR QUE CARAIO ISSO FUNCIONOU
    {
        fscanf(entrada, "%c", &str[i]);
    }

    fclose(entrada);
}

int vogal_amount(char str[])
{

    int size = strlen(str);
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        switch (str[i])
        {
        case 'a':
            count++;
            break;
        case 'e':
            count++;
            break;
        case 'i':
            count++;
            break;
        case 'o':
            count++;
            break;
        case 'u':
            count++;
            break;
        case 'A':
            count++;
            break;
        case 'E':
            count++;
            break;
        case 'I':
            count++;
            break;
        case 'O':
            count++;
            break;
        case 'U':
            count++;
            break;
        }
    }
    

    return count;
}

void print_on_output(int count, char str[])
{

    FILE *saida;
    saida = fopen("saida.txt", "w");

    if (count > 1)
    {
        fprintf(saida, "A string: %s, tem %i vogais.\n\n", str, count);
    }
    else
    {
        fprintf(saida, "A string: %s, tem %i vogal.\n\n", str, count);
    }

    printf("loaded.\n");

    fclose(saida);
}