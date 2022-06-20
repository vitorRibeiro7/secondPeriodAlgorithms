#include "disco.h"
#include <string.h>

/**************************************
 * DADOS
 **************************************/

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

/**************************************
 * IMPLEMENTAÇÃO
 **************************************/

Disco *disco_cria(char *nome, unsigned long tamanho)
{

    // ---------------------- Disco

    Disco *new = (Disco *)calloc(1, sizeof(Disco));

    // ---------------------- Vetor Disco

    int *vetorDisco = (int *)calloc(tamanho, sizeof(int));
    new->disco = vetorDisco; // new disco

    // ----------------------- livres

    NoSetor *sentinelaLivres = (NoSetor *)malloc(sizeof(NoSetor));
    sentinelaLivres->ant = sentinelaLivres;
    sentinelaLivres->prox = sentinelaLivres;

    NoSetor *firstLivres = (NoSetor *)malloc(sizeof(NoSetor));
    firstLivres->inicio = 0;
    firstLivres->fim = tamanho;

    firstLivres->prox = sentinelaLivres;
    firstLivres->ant = sentinelaLivres;

    sentinelaLivres->ant = firstLivres;

    new->livres = sentinelaLivres; // new livres

    // ---------------------- Arquivos

    NoArquivo *sentinelaArquivo = (NoArquivo *)malloc(sizeof(NoArquivo));
    sentinelaArquivo->ant = sentinelaArquivo;
    sentinelaArquivo->prox = sentinelaArquivo;

    new->arquivos = sentinelaArquivo; // new arquivos

    //----------------------- Disco - Paramentros

    strcpy(new->nome, "discoUm"); // new nome
    new->tamDisco = tamanho;      // new tamanho Disco
    new->espacoLivre = tamanho;   // new Espaço livre
    new->qtdeArquivos = 0;        // new quantidade arquivos
}
bool disco_grava(Disco *d, char *arquivo);                       // nome arquivo deve conter o caminho absoluto ou relativo do arquivo
bool disco_remove(Disco *d, char *nome);                         // somente o nome do arquivo sem o caminho
bool disco_recupera(Disco *d, char *nome, char *arquivoDestino); // nome arquivo deve conter o caminho absoluto ou relativo do arquivo
bool disco_lista(Disco *d, char *saida);

/**************************************
 * AUXILIARES
 **************************************/
