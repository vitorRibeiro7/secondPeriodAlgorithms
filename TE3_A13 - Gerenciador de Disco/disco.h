#ifndef _DISCO_H_
#define _DISCO_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct nosetor
{
    unsigned long inicio;
    unsigned long fim;
    struct nosetor *prox;
    struct nosetor *ant;
} NoSetor;

typedef struct noarquivo
{
    char nome[40];
    unsigned long tam;
    NoSetor *setores;
    struct noarquivo *prox;
    struct noarquivo *ant;
} NoArquivo;

typedef struct
{
    char nome[40];
    void *disco;
    NoSetor *livres;
    NoArquivo *arquivos;
    unsigned long tamDisco;
    unsigned long espacoLivre;
    unsigned long qtdeArquivos;
} Disco;

// PROTÓTIPOS DAS FUNÇÕES

Disco *disco_cria(char *nome, unsigned long tamanho);
bool disco_grava(Disco *d, char *arquivo);                       // nome arquivo deve conter o caminho absoluto ou relativo do arquivo
bool disco_remove(Disco *d, char *nome);                         // somente o nome do arquivo sem o caminho
bool disco_recupera(Disco *d, char *nome, char *arquivoDestino); // nome arquivo deve conter o caminho absoluto ou relativo do arquivo
bool disco_lista(Disco *d, char *saida);

#endif