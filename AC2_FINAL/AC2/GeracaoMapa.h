#pragma once

#ifndef GERACAOMAPA_H
#define GERACAOMAPA_H

#include "ExibicaoMapaGerado.h"

using namespace std;

//Fun��o que ir� gerar o mapa
Mapa gerarMapa()
{
	Mapa mapaJogo;
	exibirMapa(mapaJogo);
	return mapaJogo;
}

#endif 