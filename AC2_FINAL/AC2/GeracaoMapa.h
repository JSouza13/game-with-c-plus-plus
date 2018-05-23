#pragma once

#ifndef GERACAOMAPA_H
#define GERACAOMAPA_H

#include "ExibicaoMapaGerado.h"

using namespace std;

//Função que irá gerar o mapa
Mapa gerarMapa()
{
	Mapa mapaJogo;
	exibirMapa(mapaJogo);
	return mapaJogo;
}

#endif 