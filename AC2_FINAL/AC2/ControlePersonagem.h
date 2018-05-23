#pragma once

#ifndef CONTROLEPERSONAGEM_H
#define CONTROLEPERSONAGEM_H

#include <string>
#include<iostream>
#include "FuncaoJogo.h"
#include "Jogo.h"
#include <math.h>

//Dados do inventário do jogador
struct Inventario
{
	bool escudo = false;
	bool espada = false;
	bool chave = false;

};

//Dados do jogador
struct Jogador
{
	string nome;
	Inventario inventarioJogador;
	int exp = 0;
	int monstrosDerrotados = 0;
	int fulga = 0;
	int myHeroPos = 1;
	int direcao;
	int kill = 0;
	bool sobreviver = true;
};

Inventario mochila1;
Jogador jogadorN1;
Mapa meuMapa;

//Função que fara sorteios  para saber se o jogador sobreviveu ou nao
bool chanceSobreviver(Jogador &jogadorN1)
{

	int resultado;
	if (jogadorN1.inventarioJogador.espada == false && jogadorN1.inventarioJogador.escudo == false)
	{
		resultado = rand() % 100;
		if (resultado < 25 + jogadorN1.kill)
		{
			cout << endl << "QUE SORTE, MESMO SEM EQUIPAMENTOS VOCÊ CONSEGUIU SOBREVIVER!! "<< endl << endl;
			jogadorN1.sobreviver = true;
		}
		else
		{
			cout << endl;
			jogadorN1.sobreviver = false;
		}
	}
	if (jogadorN1.inventarioJogador.espada == false && jogadorN1.inventarioJogador.escudo == true)
	{
		resultado = rand() % 100;
		if (resultado < 40 + jogadorN1.kill)
		{
			cout << endl << "QUE SORTE, APENAS COM SEU ESCUDO VOCÊ CONSEGUIU SOBREVIVER!! " << endl << endl;
			jogadorN1.sobreviver = true;
		}
		else
		{
			cout << endl;
			jogadorN1.sobreviver = false;
		}
	}
	if (jogadorN1.inventarioJogador.espada == true && jogadorN1.inventarioJogador.escudo == false)
	{
		resultado = rand() % 100;
		if (resultado < 60 + jogadorN1.kill)
		{
			cout << endl << "FURIOSO!!! APENAS COM SUA ESPADA VOCÊ CONSEGUIU SOBREVIVER!! " << endl << endl;
			jogadorN1.sobreviver = true;
		}
		else
		{
			cout << endl;
			jogadorN1.sobreviver = false;
		}
	}
	if (jogadorN1.inventarioJogador.espada == true && jogadorN1.inventarioJogador.escudo == true)
	{
		resultado = rand() % 100;
		if (resultado < 70 + jogadorN1.kill)
		{
			cout << endl << "INCRIVEL!!! VOCÊ SE EQUIPOU MUITO BEM E FOI RECOMPENSADO COM A SOBREVIVENCIA!! " << endl << endl;
			jogadorN1.sobreviver = true;
		}
		else
		{
			cout << endl;
			jogadorN1.sobreviver = false;
		}
	}
	return jogadorN1.sobreviver;
}

//Função para pegar itens
Jogador pegarItem(Jogador &heroi, Mapa &meuJogo)
{
	meuJogo.matriz[heroi.myHeroPos][heroi.direcao];
	if (meuJogo.matriz[heroi.myHeroPos][heroi.direcao] == ESCUDO)
	{
		int pegarEscudo;
		cout << endl<< "PARABÉNS, VOCÊ ACABA DE ACHAR UM GRANDIOSO ESCUDO"<< endl
			<< endl << "VOCê DESEJA OBTE-LO? DIGITE 5 PARA SIM E DIGITE 0 PARA NÃO " << endl << endl;
		cin >>  pegarEscudo;
		if (pegarEscudo == 5)
		{
			heroi.inventarioJogador.escudo = true;
			meuMapa.matriz[1][2] = 1;
		}
		else
		{
			heroi.inventarioJogador.escudo = false;
		}
	}
	if (meuJogo.matriz[heroi.myHeroPos][heroi.direcao] == ESPADA)
	{
		int pegarEspada;
		cout << endl<< "PARABÉNS, VOCÊ ACABA DE ACHAR UMA BELISSIMA ESPADA"
			<< endl << endl << "VOCê DESEJA OBTE-LO? DIGITE 5 PARA SIM E DIGITE 0 PARA NÃO " << endl << endl;
		cin >> pegarEspada;
		if (pegarEspada == 5)
		{
			heroi.inventarioJogador.espada = true;
			for (int i = 1; i < meuMapa.tamanho; i++)
			{
				if (meuMapa.matriz[i][heroi.direcao] == ESPADA)
				{
					meuMapa.matriz[i][heroi.direcao] = VAZIA;
				}
			}
		}
		else
		{
			heroi.inventarioJogador.espada = false;
		}
	}
	if (meuJogo.matriz[heroi.myHeroPos][heroi.direcao] == MONSTRO_CHAVE)
	{
		cout << endl << "OLHA, O MONSTRO DEIXOU ALGO, PARECE SER UMA CHAVE, VAMOS PEGA-LA" << endl << endl;
		heroi.inventarioJogador.chave = true;
		for (int i = 1; i < meuMapa.tamanho; i++)
		{
			if (meuMapa.matriz[i][heroi.direcao] == MONSTRO_CHAVE)
			{
				meuMapa.matriz[i][heroi.direcao] = VAZIA;
			} 
		}		
	}
	return jogadorN1;	
}

//Função para fugir do monstro
bool fugir(Jogador &heroi, Mapa &meuMapa)
{
	chanceSobreviver(jogadorN1);
	
	return true;
}

//Função para atacar o monstro
bool atacar(Jogador &heroi, Mapa &meuMapa)
{
	chanceSobreviver(jogadorN1);
	if (jogadorN1.sobreviver == true)
	{
		for (int i = 1; i < meuMapa.tamanho; i++)
		{
			if (meuMapa.matriz[i][heroi.direcao] == MONSTRO)
			{
				meuMapa.matriz[i][heroi.direcao] = VAZIA;
			}
		}

		//Quantidade de monstros derrotados
		jogadorN1.monstrosDerrotados = jogadorN1.monstrosDerrotados + 1;

		//Valor referente ao adicional para o sorteio de sobrevivencia
		jogadorN1.kill = jogadorN1.kill + heroi.direcao;
		
		//experiencia
		int quadrado = pow(heroi.direcao, 2);
		jogadorN1.exp = jogadorN1.exp + cbrt(quadrado);
	}
	return true;
}

//Após escolha a direção que deseja ir, a função chamará outras funções que dirão oq acontecerá
bool irParaEsquerda(Jogador &heroi, int esquerda, Mapa &mapaJogo)
	{
		heroi.direcao = esquerda;
		if (meuMapa.matriz[heroi.myHeroPos][heroi.direcao] == ESCUDO || meuMapa.matriz[heroi.myHeroPos][heroi.direcao] == ESPADA)
		{
			pegarItem(jogadorN1, meuMapa);
		}

		meuMapa.matriz[heroi.myHeroPos][heroi.direcao];
		int opcaoMonstro;
		if (meuMapa.matriz[heroi.myHeroPos][heroi.direcao] == MONSTRO || meuMapa.matriz[heroi.myHeroPos][heroi.direcao] == MONSTRO_CHAVE )
		{
			do {
				cout << endl << "DROGA, UM MONSTRO!!" << endl << endl << "O QUE VOCÊ PRETENDE FAZER? DIGITE 5 PARA ATACAR OU 0 PARA FUGIR " << endl << endl;
				cin >> opcaoMonstro;
				if (opcaoMonstro == 5)
				{
					if (jogadorN1.inventarioJogador.escudo == true && jogadorN1.inventarioJogador.espada == false)
					{
						cout << endl << "VOCÊ NÃO PODE ATACAR POIS NÃO CONTEM UMA ESPADA, APENAS FUGIR, CORRA!!!" << endl << endl;
						fugir(jogadorN1, meuMapa);
						if (jogadorN1.sobreviver == true)
						{
							jogadorN1.fulga = jogadorN1.fulga + 1;
						}
						
					}
					else
					{
						atacar(jogadorN1, meuMapa);
						if (jogadorN1.sobreviver == true)
						{
							if (meuMapa.matriz[heroi.myHeroPos][heroi.direcao] == MONSTRO_CHAVE)
							{
								pegarItem(jogadorN1, meuMapa);
							}
						}
					}					
				}
				else
				{
					if (jogadorN1.inventarioJogador.espada == true && jogadorN1.inventarioJogador.escudo == false)
					{
						cout << endl << "VOCÊ NÃO PODE FUGIR POIS NÃO TEM UM ESCUDO, APENAS ATACAR!!!" << endl << endl;
						atacar(jogadorN1, meuMapa);
						if (true)
						{

						}
						if (jogadorN1.sobreviver == true)
						{
							if (meuMapa.matriz[heroi.myHeroPos][heroi.direcao] == MONSTRO_CHAVE)
							{
								pegarItem(jogadorN1, meuMapa);
							}
						}
					}
					else
					{
						fugir(jogadorN1, meuMapa);
						if (jogadorN1.sobreviver == true)
						{
							jogadorN1.fulga = jogadorN1.fulga + 1;
						}
					}
				}
			} while (opcaoMonstro != 5 && opcaoMonstro != 0);
		}

		heroi.myHeroPos = esquerda;
		return true;
	}

//Após escolha a direção que deseja ir, a função chamará outras funções que dirão oq acontecerá
bool irParaDireita(Jogador &heroi, int direita, Mapa &mapaJogo)
	{
		heroi.direcao = direita;
		if (meuMapa.matriz[heroi.myHeroPos][heroi.direcao] == ESCUDO || meuMapa.matriz[heroi.myHeroPos][heroi.direcao] == ESPADA)
		{
			pegarItem(jogadorN1, meuMapa);
		}
		meuMapa.matriz[heroi.myHeroPos][heroi.direcao];
		int opcaoMonstro;
		if (meuMapa.matriz[heroi.myHeroPos][heroi.direcao] == MONSTRO || meuMapa.matriz[heroi.myHeroPos][heroi.direcao] == MONSTRO_CHAVE)
		{
			do {
				cout << endl << "DROGA, UM MONSTRO!!" << endl << endl << "O QUE VOCÊ PRETENDE FAZER? DIGITE 5 PARA ATACAR OU 0 PARA FUGIR " << endl << endl;
				cin >> opcaoMonstro;
				if (opcaoMonstro == 5)
				{
					if (jogadorN1.inventarioJogador.escudo == true && jogadorN1.inventarioJogador.espada == false)
					{
						cout << endl << "VOCÊ NÃO PODE ATACAR POIS NÃO CONTEM UMA ESPADA, APENAS FUGIR, CORRA!!!" << endl;
						fugir(jogadorN1, meuMapa);
						if (jogadorN1.sobreviver == true)
						{
							jogadorN1.fulga = jogadorN1.fulga + 1;
						}
					}
					else
					{
						atacar(jogadorN1, meuMapa);
						if (jogadorN1.sobreviver == true)
						{
							if (meuMapa.matriz[heroi.myHeroPos][heroi.direcao] == MONSTRO_CHAVE)
							{
								pegarItem(jogadorN1, meuMapa);
							}
						}						
					}
				}
				else
				{
					if (jogadorN1.inventarioJogador.espada == true && jogadorN1.inventarioJogador.escudo == false)
					{
						cout << endl << "VOCÊ NÃO PODE FUGIR POIS NÃO TEM UM ESCUDO, APENAS ATACAR!!!" << endl;
						atacar(jogadorN1, meuMapa);
						if (jogadorN1.sobreviver == true)
						{
							if (meuMapa.matriz[heroi.myHeroPos][heroi.direcao] == MONSTRO_CHAVE)
							{
								pegarItem(jogadorN1, meuMapa);
							}
						}
					}
					else
					{
						fugir(jogadorN1, meuMapa);
						if (jogadorN1.sobreviver == true)
						{
							jogadorN1.fulga = jogadorN1.fulga + 1;
						}
					}
				}
			} while (opcaoMonstro != 5 && opcaoMonstro != 0);
		}
		heroi.myHeroPos = direita;
		return true;
	}

//Funnção para decidir se o jogador vai para direita ou esqueda
void escolherDestino(Jogador &heroi, int esq, int dir) {
	int opcao;

	do {
		cout << endl << "VOCÊ QUER IR PARA A SALA " << esq << " OU QUER IR PARA A SALA " << dir << " ? " << endl << endl;
		cin >> opcao;
	} while (opcao != esq && opcao != dir);
	
	if (opcao == esq) {

		if (meuMapa.matriz[11][esq] == PORTA_TRANCADA || meuMapa.matriz[12][esq] == PORTA_TRANCADA)
		{
			if (jogadorN1.inventarioJogador.chave == true)
			{
				irParaEsquerda(heroi, esq, meuMapa);
			}
			else
			{
				cout << endl << "PORTA TRANCADA!!! VOCê DEVE ENCONTRAR A CHAVE PARA QUE POSSA PASSAR..." << endl;
			}			
		}
		else
		{
			irParaEsquerda(heroi, esq, meuMapa);
		}
		
	}
	else if (opcao == dir) {
		if (meuMapa.matriz[11][dir] == PORTA_TRANCADA || meuMapa.matriz[12][dir] == PORTA_TRANCADA)
		{
			if (jogadorN1.inventarioJogador.chave == true)
			{
				irParaDireita(heroi, dir, meuMapa);
			}
			else
			{
				cout << endl << "PORTA TRANCADA!!! VOCê DEVE ENCONTRAR A CHAVE PARA QUE POSSA PASSAR..." << endl;
			}
		}
		else
		{
			irParaDireita(heroi, dir, meuMapa);
		}
		
	}

}

//Função que definirá a localização do jogador no mapa
void localizacaoMapa(Mapa meuMapa, Jogador &heroi){
		int dir = 0, esq = 0;
		for (int i = 1; i < meuMapa.tamanho; i++)
		{
			meuMapa.matriz[heroi.myHeroPos][i];
			if (meuMapa.matriz[heroi.myHeroPos][i] > 0 && esq == 0)
			{
				esq = i;
			}
			if (meuMapa.matriz[heroi.myHeroPos][i] > 0 && i != esq && dir == 0)
			{
				dir= i;
			}
		}
		escolherDestino(heroi, esq, dir);
	}

#endif 