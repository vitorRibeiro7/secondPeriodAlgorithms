#include <stdio.h>
#include <string.h>

struct Alunos
{
    int ra;
    float notas[3];
    float media;
    char situation[];
};

int main()
{

    int biggestFirstNote;

    // ENTRADA

    FILE *entrada;

    int qtdAlunos = 4;

    struct Alunos aluno[25];

    entrada = fopen("entrada.txt", "r");

    for (int i = 0; i < qtdAlunos; i++)
    {
        fscanf(entrada, "%i", &aluno[i].ra);
        fscanf(entrada, "%f", &aluno[i].notas[0]);
        fscanf(entrada, "%f", &aluno[i].notas[1]);
        fscanf(entrada, "%f", &aluno[i].notas[2]);
    }

    fclose(entrada);

    // PROCESSAMENTO

    biggestFirst(aluno, qtdAlunos);
    biggestMedia(aluno, qtdAlunos);
    smallMedia(aluno, qtdAlunos);
    aproved(aluno, qtdAlunos);

    return 0;
}

int biggestFirst(struct Alunos aluno[], int s) // MAIOR NOTA PRIMEIRA PROVA
{

    float nota = 0;
    int ra = 0;

    nota = aluno[0].notas[0];
    ra = aluno[0].ra;

    for (int i = 0; i < s; i++)
    {

        if (aluno[i].notas[0] > nota)
        {
            nota = aluno[i].notas[0];
            ra = aluno[i].ra;
        }
    }

    printf("MAIOR NOTA DA PRIMEIRA PROVA: [%i] %.1f\n\n", ra, nota);

    return ra;
}

int biggestMedia(struct Alunos aluno[], int s) // MAIOR MEDIA
{

    for (int i = 0; i < s; i++)
    {
        aluno[i].media = (aluno[i].notas[0] + aluno[i].notas[1] + aluno[i].notas[2]) / 3;
    }

    float bigM = 0;
    int ra;

    bigM = aluno[0].media;

    for (int i = 0; i < s; i++)
    {
        if (aluno[i].media > bigM)
        {
            bigM = aluno[i].media;
            ra = aluno[i].ra;
        }
    }

    printf("MAIOR MEDIA DA TURMA: [%i] %.1f\n\n", ra, bigM);
}

int smallMedia(struct Alunos aluno[], int s) // MENOR MEDIA
{

    for (int i = 0; i < s; i++)
    {
        aluno[i].media = (aluno[i].notas[0] + aluno[i].notas[1] + aluno[i].notas[2]) / 3;
    }

    float smallM = 0;
    int ra;

    smallM = aluno[0].media;

    for (int i = 0; i < s; i++)
    {
        if (aluno[i].media < smallM)
        {
            smallM = aluno[i].media;
            ra = aluno[i].ra;
        }
    }

    printf("MENOR MEDIA DA TURMA: [%i] %.1f\n\n", ra, smallM);
}

void aproved(struct Alunos aluno[], int s) // APROVADO OU REPROVADO
{

    for (int i = 0; i < s; i++)
    {
        aluno[i].media = (aluno[i].notas[0] + aluno[i].notas[1] + aluno[i].notas[2]) / 3;
    }

    for (int i = 0; i < s; i++)
    {
        if (aluno[i].media > 6.0)
        {
            strcpy(aluno[i].situation, "Aprovado!");
        }
        else
        {
            strcpy(aluno[i].situation, "Reprovado!");
        }
    }

    printf("RESULTADOS FINAIS DA TURMA:\n");

    for (int i = 0; i < s; i++)
    {
        printf("[%.1f]: %s\n", aluno[i].media, aluno[i].situation);
    }
}