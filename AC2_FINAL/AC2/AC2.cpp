// AC2.cpp : define o ponto de entrada para o aplicativo do console.
//
#include "stdafx.h"
#include <time.h>
#include <string>
#include "Jogo.h"

int main()
{
	setlocale(LC_ALL, "Portuguese");
	srand(time(NULL));

	inicializarJogo();

    return 0;
}

