#include <stdio.h>
#include <string.h>

int catch_a_cords_one();
int catch_a_cords_two();
void string_catch(char str[]);

#define TAMANHO_MAXIMO 200

char str[TAMANHO_MAXIMO];
char final[TAMANHO_MAXIMO];

int main()
{

    int coordOne;
    int coordTwo;

    // ENTRADA

    coordOne = catch_a_cords_one();
    coordTwo = catch_a_cords_two();
    string_catch(str);

    // PROCESSAMENTO

    string_manipule(str, final, coordOne, coordTwo);

    // SAIDA

    print_on_output(final);

    return 0;
}

int catch_a_cords_one()
{

    int coordOne;
    int coordTwo;

    FILE *coordenadas;

    coordenadas = fopen("coords.txt", "r");

    fscanf(coordenadas, "%i %i", &coordOne, &coordTwo);

    fclose(coordenadas);

    return coordOne;
}

int catch_a_cords_two()
{

    int coordOne;
    int coordTwo;

    FILE *coordenadas;

    coordenadas = fopen("coords.txt", "r");

    fscanf(coordenadas, "%i %i", &coordOne, &coordTwo);

    fclose(coordenadas);

    return coordTwo;
}

void string_catch(char str[])
{

    FILE *entrada;
    entrada = fopen("entrada.txt", "r");

    for (int i = 0; i != str; i++)
    {
        fscanf(entrada, "%c", &str[i]);
    }

    fclose(entrada);
}

void string_manipule(char str[], char final[], int coordOne, int coordTwo)
{

    int i = 0;
    int j = 0;

    int size = strlen(str);

    for (i = 0; i < size; i++)
    {
        if (i >= coordOne)
        {
            if (i <= coordTwo)
            {
                final[j] = str[i];
                j++;

                if (i > coordTwo)
                {
                    final[j] = '\0';
                    break;
                }
            }
        }
    }
}

void print_on_output(char final[])
{

    FILE *saida;
    saida = fopen("saida.txt", "w");

    fprintf(saida, "%s", final);

    printf("\n\nLOADED.\n\n\n");

    int size = strlen(str);

    for (int i = 0; i < size; i++)
    {
        printf("[%i] = %c\n", i, str[i]);
    }

    printf("\n%s\n", final);

    fclose(saida);
}