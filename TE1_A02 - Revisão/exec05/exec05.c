#include <stdio.h>
#include <string.h>

#define TAMANHO_MAXIMO 100

int main()
{

    struct horario
    {
        int hora;
        int minutos;
        int segundos;
    };

    struct horario agora;

    agora.hora = 15;
    agora.minutos = 17;
    agora.segundos = 30;

    printf("\n\nHORARIO: %i:%i:%i\n\n", agora.hora, agora.minutos, agora.segundos);

    struct data
    {
        int dia;
        char mes[TAMANHO_MAXIMO];
        int ano;
    };

    struct data hoje;

    strcpy(hoje.mes, "dezembro");
    hoje.dia = 13;
    hoje.ano = 2022;

    printf("DATA: %i de %s de %i\n\n", hoje.dia, hoje.mes, hoje.ano);

    typedef struct
    {
        int dia;
        char mes[TAMANHO_MAXIMO];
        int ano;
    } data;

    typedef struct
    {
        int horas;
        int minutos;
        int segundos;
    } horarioComp;

    struct compromisso
    {
        data data;
        horarioComp horario;
        char content[TAMANHO_MAXIMO];
    };

    struct compromisso comp = {{13, "marco", 2022}, {12, 40, 40}, "fazer alomoco"};

    printf("COMPROMISSO: %s\nDIA %i/%s/%i\nHORAS: %i:%i:%i\n\n\n", comp.content, comp.data.dia, comp.data.mes, comp.data.ano, comp.horario.horas, comp.horario.minutos, comp.horario.segundos);

    return 0;
}