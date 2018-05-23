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
	cout << "Prepare-se para a batalha!! Essa é a representação grafica do mapa do jogo, onde as linhas são onde você está, e as colunas onde quer chegar" <<endl<<endl;
	gerarMapa();
		
	cout <<endl<<endl<< "VOCÊ É CAPAZ?" << endl << endl;
	
	cout << endl << "VOCÊ CHEGOU AO LABIRINTO E O DESAFIO ACABA DE INICIAR!! " << endl;	
	do
	{
		localizacaoMapa(meuMapa,jogadorN1);
	} while (jogadorN1.myHeroPos != 13 && jogadorN1.sobreviver != false);

	if (jogadorN1.myHeroPos == 13)
	{
		cout << "PARABÉNS!!! VOCÊ É UM GRANDE JOGADOR, ECONTROU A ULTIMA SALA DO LABIRINTO E ENCONTROU A VITÓRIA." << endl << endl;
		cout << "VOCÊ ADQUIRIU " << jogadorN1.exp << " EXPERIÊNCIA." << endl;
		cout << "VOCÊ DERROTOU " << jogadorN1.monstrosDerrotados << " MONSTRO(S)." << endl;
		cout << "VOCÊ FUGIU " << jogadorN1.fulga << " VEZ(ES) DE UMA BATALHA." << endl;
		cout << "VOCÊ ADQUIRIU " << jogadorN1.inventarioJogador.escudo << " ESCUDO" <<  endl;
		cout << "VOCÊ ADQUIRIU " << jogadorN1.inventarioJogador.espada << " ESPADA"  << endl << endl;
	}
	if (jogadorN1.sobreviver == false)
	{
		cout << endl << "QUE DROGA!!! INFELIZMENTE VOCÊ NAO FOI CAPAZ DE ALCANÇAR A VITÓRIA. NA SUA PROXIMA JORNADA, TENTE SE EQUIPAR MELHOR" << endl << endl;
		cout << "VOCÊ ADQUIRIU " << jogadorN1.exp << " DE EXPERIÊNCIA." << endl;
		cout << "VOCÊ DERROTOU " << jogadorN1.monstrosDerrotados << " MONSTRO(S)." << endl;
		cout << "VOCÊ FUGIU " << jogadorN1.fulga << " VEZ(ES) DE UMA BATALHA." << endl;
		cout << "VOCÊ ADQUIRIU " << jogadorN1.inventarioJogador.escudo << " ESCUDO" <<endl;
		cout << "VOCÊ ADQUIRIU " << jogadorN1.inventarioJogador.espada << " ESPADA" << endl << endl;
	}
}

#endif 