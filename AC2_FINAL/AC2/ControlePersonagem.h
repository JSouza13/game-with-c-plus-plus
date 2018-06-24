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

enum MovimentosCombateHeroi
{
	ATACAR, DEFENDER, MAGIA, FUGIR
};
enum MovimentosCombateBoss
{
	BOSSATACAR, BOSSDEFENDER, BOSSMAGIA
};
//Dados do jogador

struct Jogador
{
	string nome;
	Inventario inventarioJogador;
	int life = 100;
	int exp = 0;
	int monstrosDerrotados = 0;
	int fuga = 0;
	int myHeroPos = 1;
	int direcao;
	int kill = 0;
	bool sobreviver = true;
	int def = 15; // A ideia futuramente é por essa defesa e ataque como uma propriedade dos itens Espada e Escudo
	int atack = 25;
	int ondeEstou = ENTRADA;
	int linha = 0;
	int coluna = 0;
	bool fugiu = false;
	int atackEspecial = 0;
};

//Dados do boss
struct Boss
{
	int life = 100;
	int atack = 15;
	int def = 10;
	bool vivo = true;
	int movimentoBoss;
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

void escolherDestinoNovoMapa(Jogador &heroi, SubMapa &newMaps, Boss &chefao);
void verificaSaida(Jogador &heroi, SubMapa &newMaps, Boss &chefao);

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
							variaveis.jogadorN1.fuga = variaveis.jogadorN1.fuga + 1;
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
							variaveis.jogadorN1.fuga = variaveis.jogadorN1.fuga + 1;
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
							variaveis.jogadorN1.fuga = variaveis.jogadorN1.fuga + 1;
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
							variaveis.jogadorN1.fuga = variaveis.jogadorN1.fuga + 1;
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

//Função que verifica se onde quero ir está dentro ou fora do mapa
bool verificaForaMapa(Jogador &heroi, SubMapa newMaps)
{
	if  (heroi.linha < 0 or heroi.linha >= newMaps.tamanho or heroi.coluna < 0 or heroi.coluna >= newMaps.tamanho)
	{
		cout << "Local inexistente!! Escolha um destino diferente." << endl;
		return false;
	}
	return true;
}

//Função que verifica se onde quero ir, é uma parede
bool verificaParede(Jogador &heroi, SubMapa newMaps)
{
	if (newMaps.matriz[heroi.linha][heroi.coluna] == PAREDE)
	{
		cout << "De cara na parede!! Escolha um destino diferente. " << endl;;
		return false;
	}
	return true;
}

//Função para o heroi Atacar
bool heroiAtacar(Jogador &heroi, SubMapa &newMaps, Boss &chefao)
{
	cout << "VAMOS AO ATAQUE!!" << endl;
	//Dano = Atack do heroi - defesa do Boss
	int dano = heroi.atack - chefao.def;
	chefao.life = chefao.life - dano;
	cout << "VOCÊ DESFERIU " << dano << " DE DANO E DEIXOU ELE COM " << chefao.life << " DE VIDA." << endl << endl;
	if (chefao.life <= 0)
	{
		cout << "MONSTRO DERROTADO!! SIGA SEU CAMINHO." << endl << endl;
		newMaps.matriz[heroi.linha][heroi.coluna] = VAZIA;
		chefao.vivo = false;
		heroi.exp = heroi.exp * 2;
		heroi.monstrosDerrotados = heroi.monstrosDerrotados + 1;
	}	
	return true;
}

//Função para o heroi Defender
bool heroiDefender(Jogador &heroi, SubMapa newMaps, Boss &chefao)
{
	cout << "VAMOS NOS PROTEGER!! " << endl;
	//Dano = Atack do Boss - defesa do Heroi
	int dano = chefao.atack - heroi.def;
	heroi.life = heroi.life - dano;
	cout << "VOCÊ SOFREU " << dano << " DE DANO E FICOU COM " << heroi.life << " DE VIDA." << endl << endl;
	if (heroi.life < 1)
	{
		heroi.sobreviver = false;
	}
	return true;
}

//Função para o heroi usar sua Ultimate
bool heroiMagia(Jogador &heroi, SubMapa &newMaps, Boss &chefao)
{
	cout << "AQUI MALDITO, CONHEÇA MEU PODER!!!" << endl;
	//Magia = Atack do Heroi + defesa do Heroi + um valor aleatório
	int magia = heroi.atack + heroi.def + 25;
	//Dano = Magia - defesa do Boss
	int dano = magia - chefao.def;
	chefao.life = chefao.life - dano;
	cout << "VOCÊ DESFERIU " << dano << " DE DANO E DEIXOU ELE COM " << chefao.life << " DE VIDA." << endl << endl;
	if (chefao.life <= 0)
	{
		cout << "MONSTRO DERROTADO!! SIGA SEU CAMINHO." << endl << endl;
		newMaps.matriz[heroi.linha][heroi.coluna] = VAZIA;
		chefao.vivo = false;
		heroi.exp = heroi.exp * 2;
		heroi.monstrosDerrotados = heroi.monstrosDerrotados + 1;
	}
	return true;
}

//Função para o heroi tentar fugir
bool heroiFugir(Jogador &heroi, SubMapa newMaps, Boss &chefao)
{
	cout << "VAMOS TENTAR FUGIR DESSE MONSTRO!! " << endl;
	//utiliza a mesma fnção de sobrevivencia utilizada no primeiro labirinto
	chanceSobreviver(heroi);
	heroi.fugiu = true;
	heroi.fuga = heroi.fuga + 1;
	return true;
}

//Função que decidirao os movimentos do Boss aleatoriamente
bool movimentoBoss(Jogador &heroi, SubMapa &newMaps, Boss &chefao)
{
	srand(time(NULL));
	int movimentoBoss = rand() % 3;
	if (chefao.life > 0)
	{
		if (movimentoBoss == BOSSATACAR)
		{
			cout << "O BOSS LHE REVIDOU!! TOME ESSE DANO." << endl;
			//Dano = Ataque do Boss - Defesa do Heroi + valor aleatorio 
			int dano = chefao.atack - heroi.def + 10;;
			heroi.life = heroi.life - dano;
			cout << "VOCÊ SOFREU " << dano << " DE DANO E FICOU COM " << heroi.life << " DE VIDA." << endl << endl;
			chefao.movimentoBoss = BOSSATACAR;
			if (heroi.life < 1)
			{
				heroi.sobreviver = false;
			}
		}
		if (movimentoBoss == BOSSDEFENDER)
		{
			cout << "O BOSS SE DEFENDEU!!" << endl;
			//Dano = Ataque do Heroi - Defesa do Chefao + numero aleatorio
			int dano = heroi.atack - chefao.def - 15;
			chefao.life = chefao.life - dano;
			cout << "ELE SOFREU " << dano << " DE DANO E FICOU COM " << chefao.life << " DE VIDA." << endl << endl;
			chefao.movimentoBoss = BOSSDEFENDER;
			if (chefao.life <= 0)
			{
				cout << "MONSTRO DERROTADO!! SIGA SEU CAMINHO." << endl << endl;
				newMaps.matriz[heroi.linha][heroi.coluna] = VAZIA;
				chefao.vivo = false;
				heroi.exp = heroi.exp * 2;
				heroi.monstrosDerrotados = heroi.monstrosDerrotados + 1;
			}
		}
		if (movimentoBoss == BOSSMAGIA)
		{
			cout << "O BOSS LHE REVIDOU!! CARACA!!! ELE USOU UMA GRANDE MAGIA." << endl;
			//Magia = Ataque + Defesa do Boss
			int magia = chefao.atack + chefao.def + 15;
			//Dano = Magia - Defesa do Heroi
			int dano = magia - heroi.def;
			heroi.life = heroi.life - dano;
			cout << "VOCÊ SOFREU " << dano << " DE DANO E FICOU COM " << heroi.life << " DE VIDA." << endl << endl;
			chefao.movimentoBoss = BOSSMAGIA;
			if (heroi.life < 1)
			{
				heroi.sobreviver = false;
			}
		}
	}
	chefao.movimentoBoss = -1;
	return true;
}

//Função para decidir as ações do Heroi contra o Boss
void movimentoJogador(Jogador &heroi, SubMapa &newMaps, Boss &chefao)
{
	if (chefao.vivo == true)
	{
		int opcaoMonstro;
		do
		{
			cout << endl << "O QUE VOCÊ PRETENDE FAZER? DIGITE: ATACAR = 0; DEFENDER = 1; USAR MAGIA = 2; FUGIR = 3;  " << endl << endl;
			cin >> opcaoMonstro;
			if (opcaoMonstro == ATACAR)
			{
				heroi.atackEspecial = heroi.atackEspecial + 1;
				heroiAtacar(heroi, newMaps, chefao);
				movimentoBoss(heroi, newMaps, chefao);
			}
			if (opcaoMonstro == DEFENDER)
			{
				heroiDefender(heroi, newMaps, chefao);
				movimentoBoss(heroi, newMaps, chefao);
			}
			if (opcaoMonstro == MAGIA)
			{
				if (heroi.atackEspecial < 2)
				{
					cout << "VOCÊ AINDA NAO TEM PODER SUFICIENTE!! ATAQUE MAIS." << endl << endl;
				}
				else
				{
					heroiMagia(heroi, newMaps, chefao);
					heroi.atackEspecial = 0;
					movimentoBoss(heroi, newMaps, chefao);					
				}
			}
			if (opcaoMonstro == FUGIR)
			{
				heroiFugir(heroi, newMaps, chefao);
			}
		} while (opcaoMonstro != 0 && opcaoMonstro != 1 && opcaoMonstro != 2 && opcaoMonstro != 3);
	}
	else
	{
		verificaSaida(heroi, newMaps, chefao);
	}
}

//Função para verificar a saída do novo mapa do jogo
void verificaSaida(Jogador &heroi, SubMapa &newMaps, Boss &chefao)
{
	if (heroi.ondeEstou != SAIDA && heroi.ondeEstou == MONSTRO && chefao.vivo == true)
	{
		cout << endl << "ACHAMOS O CHEFÃO!! TEMOS QUE DERROTA-LO!!" << endl;
		do
		{
			movimentoJogador(heroi, newMaps, chefao);
		} while (heroi.ondeEstou == MONSTRO && heroi.fugiu == false);
		heroi.fugiu = false;		
	}
	if(heroi.ondeEstou != SAIDA)
	{
		escolherDestinoNovoMapa(heroi, newMaps, chefao);
	}
}

//Função para questionar destino no mapa
void escolherDestinoNovoMapa(Jogador &heroi, SubMapa &newMaps, Boss &chefao)
{
	int ondeIr;
	do {
		cout << "DIGITE O NUMERO PARA ONDE DESEJA IR..." << endl << endl;
		cout << "ONDE: CIMA = 0; BAIXO = 1; DIREITA = 2; ESQUERDA = 3" << endl;
		cout << "DIAGONAL SUP. DIR. = 4; DIAGONAL SUP. ESQ. = 5; DIAGONAL INF. DIR. = 6; DIAGONAL INF. ESQ. = 7;" << endl << endl;
		cin >> ondeIr;
	} while (ondeIr != BAIXO && ondeIr != CIMA && ondeIr != DIREITA && ondeIr != ESQUERDA && ondeIr != DIAG_SUP_DIR && ondeIr != DIAG_SUP_ESQ && ondeIr != DIAG_INF_DIR && ondeIr != DIAG_INF_ESQ);
	if (ondeIr == BAIXO)
	{
		heroi.linha = heroi.linha + 1;
		if (verificaForaMapa(heroi, newMaps) == true && verificaParede(heroi, newMaps) == true)
		{
			cout << "ESTOU EM: [" << heroi.linha << "]" << "[" << heroi.coluna << "]" << endl << endl;
			if (heroi.sobreviver == true)
			{
				heroi.ondeEstou = newMaps.matriz[heroi.linha][heroi.coluna];
			}
		}
		else
		{
			heroi.linha = heroi.linha - 1;
		}
		verificaSaida(heroi, newMaps, chefao);
	}
	if (ondeIr == CIMA)
	{
		heroi.linha = heroi.linha - 1;
		if (verificaForaMapa(heroi, newMaps) == true && verificaParede(heroi, newMaps) == true)
		{
			cout << "ESTOU EM: [" << heroi.linha << "]" << "[" << heroi.coluna << "]" << endl << endl;
			if (heroi.sobreviver == true)
			{
				heroi.ondeEstou = newMaps.matriz[heroi.linha][heroi.coluna];
			}
		}
		else
		{
			heroi.linha = heroi.linha + 1;
		}
		verificaSaida(heroi, newMaps, chefao);
	}
	if (ondeIr == DIREITA)
	{
		heroi.coluna = heroi.coluna + 1;
		if (verificaForaMapa(heroi, newMaps) == true && verificaParede(heroi, newMaps) == true)
		{			
			cout << "ESTOU EM: [" << heroi.linha << "]" << "[" << heroi.coluna << "]" << endl << endl;
			if (heroi.sobreviver == true)
			{
				heroi.ondeEstou = newMaps.matriz[heroi.linha][heroi.coluna];
			}
		}
		else
		{
			heroi.coluna = heroi.coluna - 1;
		}
		verificaSaida(heroi, newMaps, chefao);
	}
	if (ondeIr == ESQUERDA)
	{
		heroi.coluna = heroi.coluna - 1;
		if (verificaForaMapa(heroi, newMaps) == true && verificaParede(heroi, newMaps) == true)
		{			
			cout << "ESTOU EM: [" << heroi.linha << "]" << "[" << heroi.coluna << "]" << endl << endl;
			if (heroi.sobreviver == true)
			{
				heroi.ondeEstou = newMaps.matriz[heroi.linha][heroi.coluna];
			}
		}
		else
		{
			heroi.coluna = heroi.coluna + 1;
		}
		verificaSaida(heroi, newMaps, chefao);
	}
	if (ondeIr == DIAG_INF_DIR)
	{
		heroi.coluna = heroi.coluna + 1;
		heroi.linha = heroi.linha + 1;
		if (verificaForaMapa(heroi, newMaps) == true && verificaParede(heroi, newMaps) == true)
		{
			cout << "ESTOU EM: [" << heroi.linha << "]" << "[" << heroi.coluna << "]" << endl << endl;
			if (heroi.sobreviver == true)
			{
				heroi.ondeEstou = newMaps.matriz[heroi.linha][heroi.coluna];
			}
		}
		else
		{
			heroi.coluna = heroi.coluna - 1;
			heroi.linha = heroi.linha - 1;
		}
		verificaSaida(heroi, newMaps, chefao);
	}
	if (ondeIr == DIAG_INF_ESQ)
	{
		heroi.coluna = heroi.coluna - 1;
		heroi.linha = heroi.linha + 1;
		if (verificaForaMapa(heroi, newMaps) == true && verificaParede(heroi, newMaps) == true)
		{
			cout << "ESTOU EM: [" << heroi.linha << "]" << "[" << heroi.coluna << "]" << endl << endl;
			if (heroi.sobreviver == true)
			{
				heroi.ondeEstou = newMaps.matriz[heroi.linha][heroi.coluna];
			}
		}
		else
		{
			heroi.coluna = heroi.coluna + 1;
			heroi.linha = heroi.linha - 1;
		}
		verificaSaida(heroi, newMaps, chefao);
	}
	if (ondeIr == DIAG_SUP_DIR)
	{
		heroi.coluna = heroi.coluna + 1;
		heroi.linha = heroi.linha - 1;
		if (verificaForaMapa(heroi, newMaps) == true && verificaParede(heroi, newMaps) == true)
		{
			cout << "ESTOU EM: [" << heroi.linha << "]" << "[" << heroi.coluna << "]" << endl << endl;
			if (heroi.sobreviver == true)
			{
				heroi.ondeEstou = newMaps.matriz[heroi.linha][heroi.coluna];
			}
		}
		else
		{
			heroi.coluna = heroi.coluna - 1;
			heroi.linha = heroi.linha + 1;
		}
		verificaSaida(heroi, newMaps, chefao);
	}
	if (ondeIr == DIAG_SUP_ESQ)
	{
		heroi.coluna = heroi.coluna - 1;
		heroi.linha = heroi.linha - 1;
		if (verificaForaMapa(heroi, newMaps) == true && verificaParede(heroi, newMaps) == true)
		{
			cout << "ESTOU EM: [" << heroi.linha << "]" << "[" << heroi.coluna << "]" << endl << endl;
			if (heroi.sobreviver == true)
			{
				heroi.ondeEstou = newMaps.matriz[heroi.linha][heroi.coluna];
			}
		}
		else
		{
			heroi.coluna = heroi.coluna + 1;
			heroi.linha = heroi.linha + 1;
		}
		verificaSaida(heroi, newMaps, chefao);
	}
}


#endif 