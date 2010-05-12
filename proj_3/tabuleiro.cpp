#pragma once
#include "tabuleiro.h"

Tabuleiro::Tabuleiro()
	{
		Celula temp2;
		temp2.peca = Peca(' ', 0); 
		temp2.Multiplier = 0;
		vector<Celula> temp1(15, temp2);
		vector<vector<Celula>> (15, temp1);
	}
Tabuleiro::Tabuleiro(string txt) //load game from txt
	{
		//TODO
	}
Tabuleiro::~Tabuleiro()
{
}
vector<vector <Celula>> Tabuleiro::getTabuleiro()
	{
		return TabuleiroCelulas;
	}
	
Celula Tabuleiro::accessCelula(Pos &position)
	{
		return TabuleiroCelulas[position.y][position.x];
	}

bool Tabuleiro::addPeca(Peca &piece, Pos &position) //add peca to position, false if overwrite
	{
		if (accessCelula(position).peca != Peca(' ', 0))
			return false;
		accessCelula(position).peca = piece;
		return true;
	}



