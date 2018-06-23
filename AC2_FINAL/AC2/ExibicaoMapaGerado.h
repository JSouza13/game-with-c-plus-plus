#pragma once

#ifndef EXIBICAOMAPAGERADO_H
#define EXIBICAOMAPAGERADO_H
#include <iostream>

using namespace std;

//Propriedades do mapa do jogo
enum Cenario
{
	PAREDE, VAZIA, MONSTRO, ESCUDO, ESPADA, MONSTRO_CHAVE, PORTA_TRANCADA, ENTRADA, SAIDA
};
enum POSICAO
{
	ONDE_ESTOU, ONDE_IR, NADA
};
struct Mapa {
	const static int tamanho = 14;
	int matriz[tamanho][tamanho] = 
	{
		{ NADA,		   ONDE_IR,   ONDE_IR,   ONDE_IR,   ONDE_IR,   ONDE_IR,   ONDE_IR,   ONDE_IR,			ONDE_IR,    ONDE_IR,    ONDE_IR,	ONDE_IR,	ONDE_IR,	ONDE_IR },
		{ ONDE_ESTOU,  PAREDE,    ESCUDO,	 MONSTRO,	PAREDE,	   PAREDE,	  PAREDE,	 PAREDE,			PAREDE,		PAREDE,		PAREDE,		PAREDE,		PAREDE,		PAREDE },
		{ ONDE_ESTOU,  PAREDE,    PAREDE,	 PAREDE,	ESPADA,	   MONSTRO,	  PAREDE,	 PAREDE,			PAREDE,		PAREDE,		PAREDE,		PAREDE,		PAREDE,		PAREDE },
		{ ONDE_ESTOU,  PAREDE,    PAREDE,	 PAREDE,	PAREDE,    MONSTRO,	  VAZIA,	 PAREDE,			PAREDE,		PAREDE,		PAREDE,		PAREDE,		PAREDE,		PAREDE },
		{ ONDE_ESTOU,  PAREDE,    PAREDE,	 PAREDE,	PAREDE,	   MONSTRO,	  VAZIA,	 PAREDE,			PAREDE,		PAREDE,		PAREDE,		PAREDE,		PAREDE,		PAREDE },
		{ ONDE_ESTOU,  PAREDE,    PAREDE,	 PAREDE,	PAREDE,	   PAREDE,	  VAZIA,	 MONSTRO_CHAVE,		PAREDE,		PAREDE,		PAREDE,		PAREDE,		PAREDE,		PAREDE },
		{ ONDE_ESTOU,  PAREDE,	  PAREDE,	 PAREDE,	PAREDE,	   PAREDE,	  PAREDE,	 MONSTRO_CHAVE,		VAZIA,		PAREDE,		PAREDE,		PAREDE,		PAREDE,		PAREDE },
		{ ONDE_ESTOU,  PAREDE,	  PAREDE,	 PAREDE,	PAREDE,	   PAREDE,	  PAREDE,	 PAREDE,			PAREDE,		VAZIA,		VAZIA,		PAREDE,		PAREDE,		PAREDE },
		{ ONDE_ESTOU,  PAREDE,	  PAREDE,	 PAREDE,	PAREDE,	   PAREDE,	  PAREDE,	 PAREDE,			PAREDE,		PAREDE,		VAZIA,		MONSTRO,	PAREDE,		PAREDE },
		{ ONDE_ESTOU,  PAREDE,	  PAREDE,	 PAREDE,	PAREDE,	   PAREDE,	  PAREDE,	 PAREDE,			PAREDE,		PAREDE,		VAZIA,		MONSTRO,	PAREDE,		PAREDE },
		{ ONDE_ESTOU,  PAREDE,	  PAREDE,	 PAREDE,	PAREDE,	   PAREDE,	  PAREDE,	 PAREDE,			PAREDE,		PAREDE,		PAREDE,		MONSTRO,	VAZIA,		PAREDE },
		{ ONDE_ESTOU,  PAREDE,	  PAREDE,	 PAREDE,	PAREDE,	   PAREDE,	  PAREDE,	 PAREDE,			PAREDE,		PAREDE,		PAREDE,		PAREDE,		VAZIA,		PORTA_TRANCADA },
		{ ONDE_ESTOU,  PAREDE,	  PAREDE,	 PAREDE,	ESPADA,	   PAREDE,	  PAREDE,	 PAREDE,			PAREDE,		PAREDE,		PAREDE,		PAREDE,		PAREDE,		PORTA_TRANCADA },
		{ ONDE_ESTOU,  PAREDE,	  PAREDE,	 PAREDE,	PAREDE,	   PAREDE,	  PAREDE,	 PAREDE,			PAREDE,		PAREDE,		PAREDE,		PAREDE,		PAREDE,		SAIDA }
	};;
};

struct SubMapa
{
	const static int tamanho = 5;
	int matriz[tamanho][tamanho] = 
	{	
		{ ENTRADA,	 VAZIA,    VAZIA,    VAZIA,    VAZIA },
		{ VAZIA,     VAZIA,    VAZIA,    VAZIA,    VAZIA },
		{ VAZIA,     VAZIA,    MONSTRO,  VAZIA,    VAZIA },
		{ VAZIA,     VAZIA,    VAZIA,    VAZIA,    VAZIA },
		{ VAZIA,     VAZIA,    VAZIA,    VAZIA,    SAIDA }
	};;
};

//Função que exibirá o mapa do jogo
void exibirMeuMapa(Mapa meuMapa)
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
void exibirNovoMapa(SubMapa novoMapa)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << novoMapa.matriz[i][j] << "\t";
		}
		cout << "\t" << endl;
	}
}
#endif 