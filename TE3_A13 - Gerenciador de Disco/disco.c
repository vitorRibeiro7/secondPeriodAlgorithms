#include "disco.h"
#include <string.h>

/**************************************
 * IMPLEMENTAÇÃO
 **************************************/

Disco *disco_cria(char *nome, long int tamanho)
{

    // ---------------------- Disco

    Disco *new = (Disco *)calloc(1, sizeof(Disco));

    // ---------------------- Vetor Disco

    void *vetorDisco = (void *)calloc(tamanho, sizeof(void));
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
    sentinelaLivres->prox = firstLivres;

    new->livres = sentinelaLivres; // new livres

    // ---------------------- Arquivos

    NoArquivo *sentinelaArquivo = (NoArquivo *)malloc(sizeof(NoArquivo));
    sentinelaArquivo->ant = sentinelaArquivo;
    sentinelaArquivo->prox = sentinelaArquivo;

    new->arquivos = sentinelaArquivo; // new arquivos

    //----------------------- Disco - Paramentros

    strcpy(new->nome, nome);    // new nome
    new->tamDisco = tamanho;    // new tamanho Disco
    new->espacoLivre = tamanho; // new Espaço livre
    new->qtdeArquivos = 0;      // new quantidade arquivos

    return new;
}

bool disco_grava(Disco *d, char *arquivo)
{

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

    long int tamArquivoOrigem = catchSize(arqOrigem);

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

        segmentoLivre = freeSpace(arqRestante, d);

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
    NoArquivo *aux = d->arquivos->prox;
    NoSetor *livres = d->livres;

    while (aux != d->arquivos)
    {
        if (strcmp(nome, aux->nome) == 0)
        {
            break;
        }
        aux = aux->prox;
    }

    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;

    aux->setores->prox->ant = livres->ant;
    aux->setores->ant->prox = livres;
    livres->ant->prox = aux->setores->prox;
    livres->ant = aux->setores->ant;

    agroupNode(d);

    return true;
}

bool disco_recupera(Disco *d, char *nome, char *arquivoDestino)
{
    FILE *destino;
    NoArquivo *arquivo = d->arquivos->prox;

    while (arquivo != d->arquivos)
    {
        if (strcmp(nome, arquivo->nome) == 0)
        {
            break;
        }
        arquivo = arquivo->prox;
    }

    destino = fopen(arquivoDestino, "wb");

    NoSetor *setor = arquivo->setores->prox;

    long int tam;

    while (setor != arquivo->setores)
    {

        tam = (setor->fim - setor->inicio) + 1;

        fwrite(d->disco + (setor->inicio), tam, 1, destino);

        setor = setor->prox;
    }

    fclose(destino);

    return true;
}

bool disco_lista(Disco *d)
{
    printf("-----------------\n");
    imprimeSetoresLivres(d);
    printf("-----------------\n");
    printf("ARQUIVOS: \n");

    NoArquivo *arquivo = d->arquivos->prox;
    while (arquivo != d->arquivos)
    {
        printf("%-30s (%9ld) ", arquivo->nome, arquivo->tam);

        NoSetor *segmento = arquivo->setores->prox;
        while (segmento != arquivo->setores)
        {
            printf("[%ld,%ld] ", segmento->inicio, segmento->fim);
            segmento = segmento->prox;
        }
        printf("\n");
        arquivo = arquivo->prox;
    }
    printf("\n");
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
        livre = aux;

        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
    }
    else
    {
        livre->inicio = aux->inicio;
        livre->fim = (aux->inicio + tamNecessario);
        livre->prox = livre;
        livre->ant = livre;

        aux->inicio = (aux->inicio + tamNecessario);
    }

    return livre;
}

void imprimeSetoresLivres(Disco *d)
{
    printf("LIVRES: ");
    NoSetor *aux = d->livres->prox;
    while (aux != d->livres)
    {
        printf("[%ld,%ld] ", aux->inicio, aux->fim);
        aux = aux->prox;
    }
    printf("\n");
}