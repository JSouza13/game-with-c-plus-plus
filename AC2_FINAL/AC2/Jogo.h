#pragma once

#ifndef JOGO_H
#define JOGO_H

#include "GeracaoMapa.h"
#include "ControlePersonagem.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

//Fun��o que iniciar� o jogo
void inicializarJogo()
{	
	cout << endl << "*****************EL MARRETITA AC2*****************" << endl << endl;
	cout << "PREPARE-SE PARA A BATALHA!! ESSA � A REPRESENTA��O GRAFICA DO MAPA DO JOGO, ONDE AS LINHAS S�O ONDE VOC� EST�, E AS COLUNAS ONDE QUER CHEGAR" <<endl<<endl;
	gerarMapa();		
	cout <<endl<<endl<< "VOC� � CAPAZ?" << endl << endl;	
	cout << endl << "VOC� CHEGOU AO LABIRINTO E O DESAFIO ACABA DE INICIAR!! " << endl;	
	do
	{
		localizacaoMapa(variaveis.meuMapa, variaveis.jogadorN1);
	} while (variaveis.jogadorN1.myHeroPos != 13 && variaveis.jogadorN1.sobreviver != false);
	if (variaveis.jogadorN1.myHeroPos == 13)
	{
		//Novo Mapa
		cout << endl;
		cout << "VOC� ACABA DE CHEGAR EM UM NOVO MAPA, ONDE VOCE DEVE ENCONTRAR A SA�DA PARA SER VITORIOSO." << endl;
		cout << "ENTRETANTO, VOC� PODE ENCONTRAR ALGUM OBST�CULO NO CAMINHO, CUIDADO!!" << endl << endl;
		gerarSubMapa();
		cout << endl;
		do
		{
			escolherDestinoNovoMapa(variaveis.jogadorN1, variaveis.novoMapa, variaveis.chefao);
		} while (variaveis.jogadorN1.ondeEstou != SAIDA && variaveis.jogadorN1.sobreviver != false);		

		if (variaveis.jogadorN1.ondeEstou == SAIDA)
		{
			cout << "PARAB�NS!!! VOC� � UM GRANDE JOGADOR, ECONTROU A ULTIMA SALA DO LABIRINTO E ENCONTROU A VIT�RIA." << endl << endl;
			cout << "VOC� ADQUIRIU " << variaveis.jogadorN1.exp << " EXPERI�NCIA." << endl;
			cout << "VOC� DERROTOU " << variaveis.jogadorN1.monstrosDerrotados << " MONSTRO(S)." << endl;
			cout << "VOC� FUGIU " << variaveis.jogadorN1.fuga << " VEZ(ES) DE UMA BATALHA." << endl;
			cout << "VOC� ADQUIRIU " << variaveis.jogadorN1.inventarioJogador.escudo << " ESCUDO" << endl;
			cout << "VOC� ADQUIRIU " << variaveis.jogadorN1.inventarioJogador.espada << " ESPADA" << endl << endl;
		}
		if (variaveis.jogadorN1.life < 1)
		{
			cout << endl << "QUE DROGA!!! INFELIZMENTE VOC� NAO FOI CAPAZ DE ALCAN�AR A VIT�RIA. NA SUA PROXIMA JORNADA, TENTE SE EQUIPAR MELHOR" << endl << endl;
			cout << "VOC� ADQUIRIU " << variaveis.jogadorN1.exp << " DE EXPERI�NCIA." << endl;
			cout << "VOC� DERROTOU " << variaveis.jogadorN1.monstrosDerrotados << " MONSTRO(S)." << endl;
			cout << "VOC� FUGIU " << variaveis.jogadorN1.fuga << " VEZ(ES) DE UMA BATALHA." << endl;
			cout << "VOC� ADQUIRIU " << variaveis.jogadorN1.inventarioJogador.escudo << " ESCUDO" << endl;
			cout << "VOC� ADQUIRIU " << variaveis.jogadorN1.inventarioJogador.espada << " ESPADA" << endl << endl;
		}
	}
	if (variaveis.jogadorN1.sobreviver == false)
	{
		cout << endl << "QUE DROGA!!! INFELIZMENTE VOC� NAO FOI CAPAZ DE ALCAN�AR A VIT�RIA. NA SUA PROXIMA JORNADA, TENTE SE EQUIPAR MELHOR" << endl << endl;
		cout << "VOC� ADQUIRIU " << variaveis.jogadorN1.exp << " DE EXPERI�NCIA." << endl;
		cout << "VOC� DERROTOU " << variaveis.jogadorN1.monstrosDerrotados << " MONSTRO(S)." << endl;
		cout << "VOC� FUGIU " << variaveis.jogadorN1.fuga << " VEZ(ES) DE UMA BATALHA." << endl;
		cout << "VOC� ADQUIRIU " << variaveis.jogadorN1.inventarioJogador.escudo << " ESCUDO" <<endl;
		cout << "VOC� ADQUIRIU " << variaveis.jogadorN1.inventarioJogador.espada << " ESPADA" << endl << endl;
	}
}
#endif 