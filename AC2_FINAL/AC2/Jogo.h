#pragma once

#ifndef JOGO_H
#define JOGO_H

#include "GeracaoMapa.h"
#include "ControlePersonagem.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

//Função que iniciará o jogo
void inicializarJogo()
{	
	cout << endl << "*****************EL MARRETITA AC2*****************" << endl << endl;
	cout << "PREPARE-SE PARA A BATALHA!! ESSA É A REPRESENTAÇÃO GRAFICA DO MAPA DO JOGO, ONDE AS LINHAS SÃO ONDE VOCÊ ESTÁ, E AS COLUNAS ONDE QUER CHEGAR" <<endl<<endl;
	gerarMapa();		
	cout <<endl<<endl<< "VOCÊ É CAPAZ?" << endl << endl;	
	cout << endl << "VOCÊ CHEGOU AO LABIRINTO E O DESAFIO ACABA DE INICIAR!! " << endl;	
	do
	{
		localizacaoMapa(variaveis.meuMapa, variaveis.jogadorN1);
	} while (variaveis.jogadorN1.myHeroPos != 13 && variaveis.jogadorN1.sobreviver != false);
	if (variaveis.jogadorN1.myHeroPos == 13)
	{
		//Novo Mapa
		cout << endl;
		cout << "VOCÊ ACABA DE CHEGAR EM UM NOVO MAPA, ONDE VOCE DEVE ENCONTRAR A SAÍDA PARA SER VITORIOSO." << endl;
		cout << "ENTRETANTO, VOCÊ PODE ENCONTRAR ALGUM OBSTÁCULO NO CAMINHO, CUIDADO!!" << endl << endl;
		gerarSubMapa();
		cout << endl;
		do
		{
			escolherDestinoNovoMapa(variaveis.jogadorN1, variaveis.novoMapa, variaveis.chefao);
		} while (variaveis.jogadorN1.ondeEstou != SAIDA && variaveis.jogadorN1.sobreviver != false);		

		if (variaveis.jogadorN1.ondeEstou == SAIDA)
		{
			cout << "PARABÉNS!!! VOCÊ É UM GRANDE JOGADOR, ECONTROU A ULTIMA SALA DO LABIRINTO E ENCONTROU A VITÓRIA." << endl << endl;
			cout << "VOCÊ ADQUIRIU " << variaveis.jogadorN1.exp << " EXPERIÊNCIA." << endl;
			cout << "VOCÊ DERROTOU " << variaveis.jogadorN1.monstrosDerrotados << " MONSTRO(S)." << endl;
			cout << "VOCÊ FUGIU " << variaveis.jogadorN1.fuga << " VEZ(ES) DE UMA BATALHA." << endl;
			cout << "VOCÊ ADQUIRIU " << variaveis.jogadorN1.inventarioJogador.escudo << " ESCUDO" << endl;
			cout << "VOCÊ ADQUIRIU " << variaveis.jogadorN1.inventarioJogador.espada << " ESPADA" << endl << endl;
		}
		if (variaveis.jogadorN1.life < 1)
		{
			cout << endl << "QUE DROGA!!! INFELIZMENTE VOCÊ NAO FOI CAPAZ DE ALCANÇAR A VITÓRIA. NA SUA PROXIMA JORNADA, TENTE SE EQUIPAR MELHOR" << endl << endl;
			cout << "VOCÊ ADQUIRIU " << variaveis.jogadorN1.exp << " DE EXPERIÊNCIA." << endl;
			cout << "VOCÊ DERROTOU " << variaveis.jogadorN1.monstrosDerrotados << " MONSTRO(S)." << endl;
			cout << "VOCÊ FUGIU " << variaveis.jogadorN1.fuga << " VEZ(ES) DE UMA BATALHA." << endl;
			cout << "VOCÊ ADQUIRIU " << variaveis.jogadorN1.inventarioJogador.escudo << " ESCUDO" << endl;
			cout << "VOCÊ ADQUIRIU " << variaveis.jogadorN1.inventarioJogador.espada << " ESPADA" << endl << endl;
		}
	}
	if (variaveis.jogadorN1.sobreviver == false)
	{
		cout << endl << "QUE DROGA!!! INFELIZMENTE VOCÊ NAO FOI CAPAZ DE ALCANÇAR A VITÓRIA. NA SUA PROXIMA JORNADA, TENTE SE EQUIPAR MELHOR" << endl << endl;
		cout << "VOCÊ ADQUIRIU " << variaveis.jogadorN1.exp << " DE EXPERIÊNCIA." << endl;
		cout << "VOCÊ DERROTOU " << variaveis.jogadorN1.monstrosDerrotados << " MONSTRO(S)." << endl;
		cout << "VOCÊ FUGIU " << variaveis.jogadorN1.fuga << " VEZ(ES) DE UMA BATALHA." << endl;
		cout << "VOCÊ ADQUIRIU " << variaveis.jogadorN1.inventarioJogador.escudo << " ESCUDO" <<endl;
		cout << "VOCÊ ADQUIRIU " << variaveis.jogadorN1.inventarioJogador.espada << " ESPADA" << endl << endl;
	}
}
#endif 