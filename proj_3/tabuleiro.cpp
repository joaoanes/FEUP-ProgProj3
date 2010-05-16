#pragma once
#include "tabuleiro.h"

Tabuleiro::Tabuleiro()
	{
		vector<Celula> temp1;
		TabuleiroCelulas = vector<vector<Celula>> (15, temp1);
	}
Tabuleiro::Tabuleiro(string txt) 
	{
		ifstream fiel;
		fiel.open(txt.c_str());
		assert (fiel.is_open());
			for (int i = 0; i < 14 ; ++i) //tabuleiro size == 15*15
			{
				vector<Celula>* curVector;
				curVector = &TabuleiroCelulas[i];
				string curline;
				getline(fiel, curline);
				cout << curline;
			}
	}
Tabuleiro::~Tabuleiro()
{
}
vector<vector <Celula>> Tabuleiro::getTabuleiro()
	{
		return TabuleiroCelulas;
	}
void Tabuleiro::buildTabuleiro(string txt)
{
	ifstream fiel;
	fiel.open(txt.c_str());
	assert (fiel.is_open());
	vector<Celula>* curVector;
	string curline;
	for (int i = 0; i < SIDELENGTH; ++i) //tabuleiro size == 15*15, SELECIONA vector 
	{
		curVector = &TabuleiroCelulas[i];
		getline(fiel, curline);
		fillLine(curVector, curline);
	}
}

Celula Tabuleiro::accessCelula(Pos &position)
	{
		return TabuleiroCelulas[position.y][position.x];
	}
void Tabuleiro::fillLine(vector<Celula>* ptrVec, string str)
{
	for (int i = 0; i < str.size() ; ++i)
	{
		char* curchar = &str[i];
		if (!(*curchar == ' '))
		{
				Celula curcelula;
				switch (*curchar) //0 - normal; 1 - dupletra; 2 - triletra; 3 - duppal; 4 - tripal
				{
				case '*':
					curcelula.Multiplier = 1;
					break;
				case '#':
					curcelula.Multiplier = 2;
					break;
				case '$':
					curcelula.Multiplier = 3;
					break;
				case '%':
					curcelula.Multiplier = 4;
					break;
				default:
					curcelula.Multiplier = 0;
				}
				Peca curpeca(*curchar, 0);
				curcelula.peca = curpeca;
				ptrVec->push_back(curcelula);
			}
		}
	}

bool Tabuleiro::addPeca(Peca &piece, Pos &position) //add peca to position, false if overwrite
	{
		if (accessCelula(position).peca != Peca(' ', 0))
			return false;
		accessCelula(position).peca = piece;
		return true;
	}

void Tabuleiro::showTabuleiro()
{
	for (unsigned short i = 0; i < TabuleiroCelulas.size() ; ++i)
	{
		for (unsigned short i2 = 0; i2 < TabuleiroCelulas[i].size() ; i2++)
		{
			cout << TabuleiroCelulas[i][i].peca.getLetter() << " ";
		}
		endl(cout);
	}
}

