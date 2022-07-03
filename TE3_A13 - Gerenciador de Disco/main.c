#include <stdio.h>

#include "disco.h"

int main()
{

    Disco *disco = disco_cria("dados", 770000);

    disco_grava(disco, "mario.jpeg");

    disco_lista(disco);

    disco_recupera(disco, "mario.jpeg", "./backup/marioback.jpeg");

    return 0;
}