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

bool disco_grava(Disco *d, char *arquivo)
{

    if (d == NULL)
    {
        return false;
    }

    FILE *arqOrigem;
    long int arqCopiado = 0;
    long int arqRestante;

    char caminho[200];
    caminho[0] = '\0';
    strcat(caminho, DIR);
    strcat(caminho, arquivo);

    arqOrigem = fopen(caminho, "rb");

    if (arqOrigem == NULL)
    {
        perror("Erro ao abrir...");
        return false;
    }

    long int tamArquivoOrigem = descobreTamanho(arqOrigem);

    void *buffer = (void *)calloc(tamArquivoOrigem, sizeof(void));

    if (buffer == NULL)
    {
        perror("Memoria insuficiente");
        return false;
    }

    fread(buffer, tamArquivoOrigem, 1, arqOrigem);

    long int espacoLivre;
    NoSetor *segmentoLivre = (NoSetor *)malloc(sizeof(NoSetor));
    arqRestante = tamArquivoOrigem;

    NoSetor *sentinela = (NoSetor *)malloc(sizeof(NoSetor));
    sentinela->ant = sentinela;
    sentinela->prox = sentinela;

    NoArquivo *arqAdd = (NoArquivo *)malloc(sizeof(NoArquivo));
    strcpy(arqAdd->nome, arquivo);

    arqAdd->prox = d->arquivos;
    arqAdd->ant = d->arquivos->ant;

    d->arquivos->ant->prox = arqAdd;
    d->arquivos->ant = arqAdd;

    arqAdd->setores = sentinela;
    arqAdd->tam = tamArquivoOrigem;

    while (arqCopiado < tamArquivoOrigem)
    {

        segmentoLivre = procuraEspacoLivre(arqRestante, d);

        espacoLivre = (segmentoLivre->fim - segmentoLivre->inicio);

        memcpy(d->disco + segmentoLivre->inicio, buffer + arqCopiado, espacoLivre);

        arqCopiado += espacoLivre;
        arqRestante -= espacoLivre;

        segmentoLivre->ant = sentinela->ant;
        segmentoLivre->prox = sentinela;

        sentinela->ant->prox = segmentoLivre;
        sentinela->ant = segmentoLivre;
    }

    fclose(arqOrigem);

    return true;
}

bool disco_remove(Disco *d, char *nome)
{
}

bool disco_recupera(Disco *d, char *nome, char *arquivoDestino)
{
}

bool disco_lista(Disco *d, char *saida)
{
}

/**************************************
 * AUXILIARES
 **************************************/

long int catchSize(FILE *arq)
{
    rewind(arq);
    fseek(arq, 0, SEEK_END);
    int tamanho = ftell(arq);
    rewind(arq);
    return tamanho;
}

bool agroupNode(Disco *d)
{
    NoSetor *auxAtual = d->livres->prox;
    NoSetor *aux;

    while (auxAtual != d->livres)
    {
        aux = d->livres->prox;

        while (aux != d->livres)
        {
            if (aux->inicio == auxAtual->fim)
            {
                auxAtual->fim = aux->fim;

                aux->prox->ant = aux->ant;
                aux->ant->prox = aux->prox;
                free(aux);
            }
            aux = aux->prox;
        }

        auxAtual = auxAtual->prox;
    }

    return true;
}

NoSetor *freeSpace(long int tamNecessario, Disco *d)
{
    NoSetor *aux = d->livres->prox;
    NoSetor *livre = (NoSetor *)malloc(sizeof(NoSetor));

    if (tamNecessario >= (aux->fim - aux->inicio))
    {
        // Passa o No para o Setor Livre
        livre = aux;

        // Desencadeando No Livre
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
    }
    else
    {
        // Copia os dados necessarios para o NoSetor livre
        livre->inicio = aux->inicio;
        livre->fim = (aux->inicio + tamNecessario);
        livre->prox = livre;
        livre->ant = livre;

        // Atualiza o primeiro no livre
        aux->inicio = (aux->inicio + tamNecessario);
    }

    return livre;
}