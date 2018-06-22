#pragma once

#ifndef GERACAOMAPA_H
#define GERACAOMAPA_H

#include "ExibicaoMapaGerado.h"
#include "ControlePersonagem.h"

using namespace std;



//Função que irá gerar o mapa
Mapa gerarMapa()
{	
	exibirMeuMapa(variaveis.meuMapa);
	return variaveis.meuMapa;
}

SubMapa gerarSubMapa()
{	
	int cont = 0;
	int line, colun;
	srand(time(NULL));
	do
	{
		//Se as posições já estiverem preenchidas sai do looping principal
		if (cont == variaveis.novoMapa.tamanho * variaveis.novoMapa.tamanho) break;

		line = rand() % variaveis.novoMapa.tamanho;
		colun = rand() % variaveis.novoMapa.tamanho;
		int teste = true;
		do
		{
			if (variaveis.novoMapa.matriz[line][colun] == VAZIA && variaveis.novoMapa.matriz[line][colun] != MONSTRO )
			{
				variaveis.novoMapa.matriz[line][colun] = PAREDE;
				cont++;
				teste = false;			
			}
			else
			{
				line = rand() % variaveis.novoMapa.tamanho;
				colun = rand() % variaveis.novoMapa.tamanho;
			}
		} while (teste);

	} while (cont < 2);
	exibirNovoMapa(variaveis.novoMapa);
	return variaveis.novoMapa;
}
#endif 