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
	cout << "Prepare-se para a batalha!! Essa � a representa��o grafica do mapa do jogo, onde as linhas s�o onde voc� est�, e as colunas onde quer chegar" <<endl<<endl;
	gerarMapa();
		
	cout <<endl<<endl<< "VOC� � CAPAZ?" << endl << endl;
	
	cout << endl << "VOC� CHEGOU AO LABIRINTO E O DESAFIO ACABA DE INICIAR!! " << endl;	
	do
	{
		localizacaoMapa(meuMapa,jogadorN1);
	} while (jogadorN1.myHeroPos != 13 && jogadorN1.sobreviver != false);

	if (jogadorN1.myHeroPos == 13)
	{
		cout << "PARAB�NS!!! VOC� � UM GRANDE JOGADOR, ECONTROU A ULTIMA SALA DO LABIRINTO E ENCONTROU A VIT�RIA." << endl << endl;
		cout << "VOC� ADQUIRIU " << jogadorN1.exp << " EXPERI�NCIA." << endl;
		cout << "VOC� DERROTOU " << jogadorN1.monstrosDerrotados << " MONSTRO(S)." << endl;
		cout << "VOC� FUGIU " << jogadorN1.fulga << " VEZ(ES) DE UMA BATALHA." << endl;
		cout << "VOC� ADQUIRIU " << jogadorN1.inventarioJogador.escudo << " ESCUDO" <<  endl;
		cout << "VOC� ADQUIRIU " << jogadorN1.inventarioJogador.espada << " ESPADA"  << endl << endl;
	}
	if (jogadorN1.sobreviver == false)
	{
		cout << endl << "QUE DROGA!!! INFELIZMENTE VOC� NAO FOI CAPAZ DE ALCAN�AR A VIT�RIA. NA SUA PROXIMA JORNADA, TENTE SE EQUIPAR MELHOR" << endl << endl;
		cout << "VOC� ADQUIRIU " << jogadorN1.exp << " DE EXPERI�NCIA." << endl;
		cout << "VOC� DERROTOU " << jogadorN1.monstrosDerrotados << " MONSTRO(S)." << endl;
		cout << "VOC� FUGIU " << jogadorN1.fulga << " VEZ(ES) DE UMA BATALHA." << endl;
		cout << "VOC� ADQUIRIU " << jogadorN1.inventarioJogador.escudo << " ESCUDO" <<endl;
		cout << "VOC� ADQUIRIU " << jogadorN1.inventarioJogador.espada << " ESPADA" << endl << endl;
	}
}

#endif 