#pragma once

#ifndef CONTROLEPERSONAGEM_H
#define CONTROLEPERSONAGEM_H

#include <string>
#include<iostream>
#include "FuncaoJogo.h"
#include "ExibicaoMapaGerado.h"
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
	int life = 100;
	int exp = 0;
	int monstrosDerrotados = 0;
	int fulga = 0;
	int myHeroPos = 1;
	int direcao;
	int kill = 0;
	bool sobreviver = true;
	int def;
	int atack;
	int ondeEstou = ENTRADA;
	int linha = 0;
	int coluna = 0;
};
struct Boss
{
	int life = 100;
	int atack = 25;
	int def = 10;
};
struct Variaveis
{
	Inventario mochila1;
	Jogador jogadorN1;
	Mapa meuMapa;
	SubMapa novoMapa;
	Boss chefao;
};
enum Movimentos
{
	CIMA, BAIXO, DIREITA, ESQUERDA, DIAG_SUP_DIR, DIAG_SUP_ESQ, DIAG_INF_DIR, DIAG_INF_ESQ
};
Variaveis variaveis;
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
			variaveis.meuMapa.matriz[1][2] = 1;
			heroi.def = 15;
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
			heroi.atack = 25;
			for (int i = 1; i < variaveis.meuMapa.tamanho; i++)
			{
				if (variaveis.meuMapa.matriz[i][heroi.direcao] == ESPADA)
				{
					variaveis.meuMapa.matriz[i][heroi.direcao] = VAZIA;
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
		for (int i = 1; i < variaveis.meuMapa.tamanho; i++)
		{
			if (variaveis.meuMapa.matriz[i][heroi.direcao] == MONSTRO_CHAVE)
			{
				variaveis.meuMapa.matriz[i][heroi.direcao] = VAZIA;
			} 
		}		
	}
	return variaveis.jogadorN1;
}

//Função para fugir do monstro
bool fugir(Jogador &heroi, Mapa &meuMapa)
{
	chanceSobreviver(variaveis.jogadorN1);
	
	return true;
}

//Função para atacar o monstro
bool atacar(Jogador &heroi, Mapa &meuMapa)
{
	chanceSobreviver(variaveis.jogadorN1);
	if (variaveis.jogadorN1.sobreviver == true)
	{
		for (int i = 1; i < meuMapa.tamanho; i++)
		{
			if (meuMapa.matriz[i][heroi.direcao] == MONSTRO)
			{
				meuMapa.matriz[i][heroi.direcao] = VAZIA;
			}
		}

		//Quantidade de monstros derrotados
		variaveis.jogadorN1.monstrosDerrotados = variaveis.jogadorN1.monstrosDerrotados + 1;

		//Valor referente ao adicional para o sorteio de sobrevivencia
		variaveis.jogadorN1.kill = variaveis.jogadorN1.kill + heroi.direcao;
		
		//experiencia
		int quadrado = pow(heroi.direcao, 2);
		variaveis.jogadorN1.exp = variaveis.jogadorN1.exp + cbrt(quadrado);
	}
	return true;
}

//Após escolha a direção que deseja ir, a função chamará outras funções que dirão oq acontecerá
bool irParaEsquerda(Jogador &heroi, int esquerda, Mapa &mapaJogo)
	{
		heroi.direcao = esquerda;
		if (variaveis.meuMapa.matriz[heroi.myHeroPos][heroi.direcao] == ESCUDO || variaveis.meuMapa.matriz[heroi.myHeroPos][heroi.direcao] == ESPADA)
		{
			pegarItem(variaveis.jogadorN1, variaveis.meuMapa);
		}

		variaveis.meuMapa.matriz[heroi.myHeroPos][heroi.direcao];
		int opcaoMonstro;
		if (variaveis.meuMapa.matriz[heroi.myHeroPos][heroi.direcao] == MONSTRO || variaveis.meuMapa.matriz[heroi.myHeroPos][heroi.direcao] == MONSTRO_CHAVE )
		{
			do {
				cout << endl << "DROGA, UM MONSTRO!!" << endl << endl << "O QUE VOCÊ PRETENDE FAZER? DIGITE 5 PARA ATACAR OU 0 PARA FUGIR " << endl << endl;
				cin >> opcaoMonstro;
				if (opcaoMonstro == 5)
				{
					if (variaveis.jogadorN1.inventarioJogador.escudo == true && variaveis.jogadorN1.inventarioJogador.espada == false)
					{
						cout << endl << "VOCÊ NÃO PODE ATACAR POIS NÃO CONTEM UMA ESPADA, APENAS FUGIR, CORRA!!!" << endl << endl;
						fugir(variaveis.jogadorN1, variaveis.meuMapa);
						if (variaveis.jogadorN1.sobreviver == true)
						{
							variaveis.jogadorN1.fulga = variaveis.jogadorN1.fulga + 1;
						}						
					}
					else
					{
						atacar(variaveis.jogadorN1, variaveis.meuMapa);
						if (variaveis.jogadorN1.sobreviver == true)
						{
							if (variaveis.meuMapa.matriz[heroi.myHeroPos][heroi.direcao] == MONSTRO_CHAVE)
							{
								pegarItem(variaveis.jogadorN1, variaveis.meuMapa);
							}
						}
					}					
				}
				else
				{
					if (variaveis.jogadorN1.inventarioJogador.espada == true && variaveis.jogadorN1.inventarioJogador.escudo == false)
					{
						cout << endl << "VOCÊ NÃO PODE FUGIR POIS NÃO TEM UM ESCUDO, APENAS ATACAR!!!" << endl << endl;
						atacar(variaveis.jogadorN1, variaveis.meuMapa);
						if (variaveis.jogadorN1.sobreviver == true)
						{
							if (variaveis.meuMapa.matriz[heroi.myHeroPos][heroi.direcao] == MONSTRO_CHAVE)
							{
								pegarItem(variaveis.jogadorN1, variaveis.meuMapa);
							}
						}
					}
					else
					{
						fugir(variaveis.jogadorN1, variaveis.meuMapa);
						if (variaveis.jogadorN1.sobreviver == true)
						{
							variaveis.jogadorN1.fulga = variaveis.jogadorN1.fulga + 1;
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
		if (variaveis.meuMapa.matriz[heroi.myHeroPos][heroi.direcao] == ESCUDO || variaveis.meuMapa.matriz[heroi.myHeroPos][heroi.direcao] == ESPADA)
		{
			pegarItem(variaveis.jogadorN1, variaveis.meuMapa);
		}
		variaveis.meuMapa.matriz[heroi.myHeroPos][heroi.direcao];
		int opcaoMonstro;
		if (variaveis.meuMapa.matriz[heroi.myHeroPos][heroi.direcao] == MONSTRO || variaveis.meuMapa.matriz[heroi.myHeroPos][heroi.direcao] == MONSTRO_CHAVE)
		{
			do {
				cout << endl << "DROGA, UM MONSTRO!!" << endl << endl << "O QUE VOCÊ PRETENDE FAZER? DIGITE 5 PARA ATACAR OU 0 PARA FUGIR " << endl << endl;
				cin >> opcaoMonstro;
				if (opcaoMonstro == 5)
				{
					if (variaveis.jogadorN1.inventarioJogador.escudo == true && variaveis.jogadorN1.inventarioJogador.espada == false)
					{
						cout << endl << "VOCÊ NÃO PODE ATACAR POIS NÃO CONTEM UMA ESPADA, APENAS FUGIR, CORRA!!!" << endl;
						fugir(variaveis.jogadorN1, variaveis.meuMapa);
						if (variaveis.jogadorN1.sobreviver == true)
						{
							variaveis.jogadorN1.fulga = variaveis.jogadorN1.fulga + 1;
						}
					}
					else
					{
						atacar(variaveis.jogadorN1, variaveis.meuMapa);
						if (variaveis.jogadorN1.sobreviver == true)
						{
							if (variaveis.meuMapa.matriz[heroi.myHeroPos][heroi.direcao] == MONSTRO_CHAVE)
							{
								pegarItem(variaveis.jogadorN1, variaveis.meuMapa);
							}
						}						
					}
				}
				else
				{
					if (variaveis.jogadorN1.inventarioJogador.espada == true && variaveis.jogadorN1.inventarioJogador.escudo == false)
					{
						cout << endl << "VOCÊ NÃO PODE FUGIR POIS NÃO TEM UM ESCUDO, APENAS ATACAR!!!" << endl;
						atacar(variaveis.jogadorN1, variaveis.meuMapa);
						if (variaveis.jogadorN1.sobreviver == true)
						{
							if (variaveis.meuMapa.matriz[heroi.myHeroPos][heroi.direcao] == MONSTRO_CHAVE)
							{
								pegarItem(variaveis.jogadorN1, variaveis.meuMapa);
							}
						}
					}
					else
					{
						fugir(variaveis.jogadorN1, variaveis.meuMapa);
						if (variaveis.jogadorN1.sobreviver == true)
						{
							variaveis.jogadorN1.fulga = variaveis.jogadorN1.fulga + 1;
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

		if (variaveis.meuMapa.matriz[11][esq] == PORTA_TRANCADA || variaveis.meuMapa.matriz[12][esq] == PORTA_TRANCADA)
		{
			if (variaveis.jogadorN1.inventarioJogador.chave == true)
			{
				irParaEsquerda(heroi, esq, variaveis.meuMapa);
			}
			else
			{
				cout << endl << "PORTA TRANCADA!!! VOCê DEVE ENCONTRAR A CHAVE PARA QUE POSSA PASSAR..." << endl;
			}			
		}
		else
		{
			irParaEsquerda(heroi, esq, variaveis.meuMapa);
		}		
	}
	else if (opcao == dir) {
		if (variaveis.meuMapa.matriz[11][dir] == PORTA_TRANCADA || variaveis.meuMapa.matriz[12][dir] == PORTA_TRANCADA)
		{
			if (variaveis.jogadorN1.inventarioJogador.chave == true)
			{
				irParaDireita(heroi, dir, variaveis.meuMapa);
			}
			else
			{
				cout << endl << "PORTA TRANCADA!!! VOCê DEVE ENCONTRAR A CHAVE PARA QUE POSSA PASSAR..." << endl;
			}
		}
		else
		{
			irParaDireita(heroi, dir, variaveis.meuMapa);
		}		
	}

}

//Função que definirá a localização do jogador no mapa
void localizacaoMapa(Mapa meuMapa, Jogador &heroi)
{
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

bool verificaForaMapa(Jogador &heroi, SubMapa newMaps)
{
	if  (heroi.linha < 0 or heroi.linha >= newMaps.tamanho or heroi.coluna < 0 or heroi.coluna >= newMaps.tamanho)
	{
		cout << "Local inexistente!! Escolha um destino diferente." << endl;
		return false;
	}
	return true;
}
bool verificaParede(Jogador &heroi, SubMapa newMaps)
{
	if (newMaps.matriz[heroi.linha][heroi.coluna] == PAREDE)
	{
		cout << "De cara na parede!! Escolha um destino diferente. " << endl;;
		return false;
	}
	return true;
}
bool heroiAtacar(Jogador &heroi, SubMapa &newMaps, Boss &chefao)
{
	int dano = heroi.atack - chefao.def;
	chefao.life = chefao.life - dano;
	if (chefao.life == 0)
	{
		newMaps.matriz[heroi.linha][heroi.coluna] = VAZIA;
	}	
	return true;
}

bool heroiDefender(Jogador &heroi, SubMapa &newMaps, Boss &chefao)
{
	int dano = chefao.atack - heroi.def;
	heroi.life = heroi.life - dano;
	if (heroi.life == 0)
	{
		heroi.sobreviver = false;
	}
	return true;
}

bool heroiMagia(Jogador &heroi, SubMapa &newMaps, Boss &chefao)
{
	int magia = heroi.atack + heroi.def;
	int dano = magia - chefao.def;
	chefao.life = chefao.life - dano;
	if (chefao.life == 0)
	{
		newMaps.matriz[heroi.linha][heroi.coluna] = VAZIA;
	}
	return true;
}

bool heroiFugir(Jogador &heroi, SubMapa &newMaps, Boss &chefao)
{
	chanceSobreviver(heroi);
	return true;
}

bool bossAtacar(Jogador &heroi, SubMapa &newMaps, Boss &chefao)
{
	int dano = chefao.atack - heroi.def;
	heroi.life = heroi.life - dano;
	return true;
}

bool bossDefender(Jogador &heroi, SubMapa &newMaps, Boss &chefao)
{
	int dano = heroi.atack - chefao.def;
	chefao.life = chefao.life - dano;
	return true;
}

void escolherDestinoNovoMapa(Jogador &heroi, SubMapa newMaps);

void verificaSaida(Jogador &heroi, SubMapa newMaps)
{
	if (heroi.ondeEstou != SAIDA)
	{
		escolherDestinoNovoMapa(heroi, newMaps);
	}
}

void escolherDestinoNovoMapa(Jogador &heroi, SubMapa newMaps)
{
	int ondeIr;
	do {
		cout << "Digite o numero para onde deseja ir..." << endl;
		cout << "Onde: CIMA = 0; BAIXO = 1; DIREITA = 2; ESQUERDA = 3" << endl;
		cout << "DIAGONAL SUP. DIR. = 4; DIAGONAL SUP. ESQ. = 5; DIAGONAL INF. DIR. = 6; DIAGONAL INF. ESQ. = 7;" << endl;
		cin >> ondeIr;
	} while (ondeIr != BAIXO && ondeIr != CIMA && ondeIr != DIREITA && ondeIr != ESQUERDA && ondeIr != DIAG_SUP_DIR && ondeIr != DIAG_SUP_ESQ && ondeIr != DIAG_INF_DIR && ondeIr != DIAG_INF_ESQ);
	if (ondeIr == BAIXO)
	{
		heroi.linha = heroi.linha + 1;
		if (verificaForaMapa(heroi, newMaps) == true && verificaParede(heroi, newMaps) == true)
		{
			cout << "Estou em: [" << heroi.linha << "]" << "[" << heroi.coluna << "]" << endl << endl;
			heroi.ondeEstou = newMaps.matriz[heroi.linha][heroi.coluna];
		}
		else
		{
			heroi.linha = heroi.linha - 1;
		}
		verificaSaida(heroi, newMaps);
	}
	if (ondeIr == CIMA)
	{
		heroi.linha = heroi.linha - 1;
		if (verificaForaMapa(heroi, newMaps) == true && verificaParede(heroi, newMaps) == true)
		{
			cout << "Estou em: [" << heroi.linha << "]" << "[" << heroi.coluna << "]" << endl << endl;
			heroi.ondeEstou = newMaps.matriz[heroi.linha][heroi.coluna];
		}
		else
		{
			heroi.linha = heroi.linha + 1;
		}
		verificaSaida(heroi, newMaps);
	}
	if (ondeIr == DIREITA)
	{
		heroi.coluna = heroi.coluna + 1;
		if (verificaForaMapa(heroi, newMaps) == true && verificaParede(heroi, newMaps) == true)
		{			
			cout << "Estou em: [" << heroi.linha << "]" << "[" << heroi.coluna << "]" << endl << endl;
			heroi.ondeEstou = newMaps.matriz[heroi.linha][heroi.coluna];
		}
		else
		{
			heroi.coluna = heroi.coluna - 1;
		}
		verificaSaida(heroi, newMaps);
	}
	if (ondeIr == ESQUERDA)
	{
		heroi.coluna = heroi.coluna - 1;
		if (verificaForaMapa(heroi, newMaps) == true && verificaParede(heroi, newMaps) == true)
		{			
			cout << "Estou em: [" << heroi.linha << "]" << "[" << heroi.coluna << "]" << endl << endl;
			heroi.ondeEstou = newMaps.matriz[heroi.linha][heroi.coluna];
		}
		else
		{
			heroi.coluna = heroi.coluna + 1;
		}
		verificaSaida(heroi, newMaps);
	}
	if (ondeIr == DIAG_INF_DIR)
	{
		heroi.coluna = heroi.coluna + 1;
		heroi.linha = heroi.linha + 1;
		if (verificaForaMapa(heroi, newMaps) == true && verificaParede(heroi, newMaps) == true)
		{
			cout << "Estou em: [" << heroi.linha << "]" << "[" << heroi.coluna << "]" << endl << endl;
			heroi.ondeEstou = newMaps.matriz[heroi.linha][heroi.coluna];
		}
		else
		{
			heroi.coluna = heroi.coluna - 1;
			heroi.linha = heroi.linha - 1;
		}
		verificaSaida(heroi, newMaps);
	}
	if (ondeIr == DIAG_INF_ESQ)
	{
		heroi.coluna = heroi.coluna - 1;
		heroi.linha = heroi.linha + 1;
		if (verificaForaMapa(heroi, newMaps) == true && verificaParede(heroi, newMaps) == true)
		{
			cout << "Estou em: [" << heroi.linha << "]" << "[" << heroi.coluna << "]" << endl << endl;
			heroi.ondeEstou = newMaps.matriz[heroi.linha][heroi.coluna];
		}
		else
		{
			heroi.coluna = heroi.coluna + 1;
			heroi.linha = heroi.linha - 1;
		}
		verificaSaida(heroi, newMaps);
	}
	if (ondeIr == DIAG_SUP_DIR)
	{
		heroi.coluna = heroi.coluna + 1;
		heroi.linha = heroi.linha - 1;
		if (verificaForaMapa(heroi, newMaps) == true && verificaParede(heroi, newMaps) == true)
		{
			cout << "Estou em: [" << heroi.linha << "]" << "[" << heroi.coluna << "]" << endl << endl;
			heroi.ondeEstou = newMaps.matriz[heroi.linha][heroi.coluna];
		}
		else
		{
			heroi.coluna = heroi.coluna - 1;
			heroi.linha = heroi.linha + 1;
		}
		verificaSaida(heroi, newMaps);
	}
	if (ondeIr == DIAG_SUP_ESQ)
	{
		heroi.coluna = heroi.coluna - 1;
		heroi.linha = heroi.linha - 1;
		if (verificaForaMapa(heroi, newMaps) == true && verificaParede(heroi, newMaps) == true)
		{
			cout << "Estou em: [" << heroi.linha << "]" << "[" << heroi.coluna << "]" << endl << endl;
			heroi.ondeEstou = newMaps.matriz[heroi.linha][heroi.coluna];
		}
		else
		{
			heroi.coluna = heroi.coluna + 1;
			heroi.linha = heroi.linha + 1;
		}
		verificaSaida(heroi, newMaps);
	}
}


#endif 