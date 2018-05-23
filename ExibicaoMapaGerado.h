#pragma once

#ifndef EXIBICAOMAPAGERADO_H
#define EXIBICAOMAPAGERADO_H
#include <iostream>

using namespace std;

#define PAREDE 0
#define VAZIA 1
#define MONSTRO 2
#define ESCUDO 3
#define ESPADA 4
#define MONSTRO_CHAVE 5
#define PORTA_TRANCADA 6
#define PERSONAGEM 7

//Propriedades do mapa do jogo
struct Mapa {
	const static int tamanho = 14;
	int matriz[tamanho][tamanho] = {
		{ 0,1,2,3,4,5,6,7,8,9,10,11,12, 13 },

	{ 1,0,3,2,0,0,0,0,0,0,0,0,0,0 },

	{ 2,0,0,0,4,2,0,0,0,0,0,0,0,0 },

	{ 3,0,0,0,0,2,1,0,0,0,0,0,0,0 },

	{ 4,0,0,0,0,2,1,0,0,0,0,0,0,0 },

	{ 5,0,0,0,0,0,1,5,0,0,0,0,0,0 },

	{ 6,0,0,0,0,0,0,5,1,0,0,0,0,0 },

	{ 7,0,0,0,0,0,0,0,0,1,1,0,0,0 },

	{ 8,0,0,0,0,0,0,0,0,0,1,2,0,0 },

	{ 9,0,0,0,0,0,0,0,0,0,1,2,0,0 },

	{ 10,0,0,0,0,0,0,0,0,0,0,2,1,0 },

	{ 11,0,0,0,0,0,0,0,0,0,0,0,1,6 },

	{ 12,0,0,0,4,0,0,0,0,0,0,0,0,6 },

	{ 13,0,0,0,0,0,0,0,0,0,0,0,0,0 }
	};;
};

//Função que exibirá o mapa do jogo
void exibirMapa(Mapa meuMapa)
{
	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			cout << meuMapa.matriz[i][j] << "\t";
		}
		cout << "\t" << endl;
	}	
}

#endif 