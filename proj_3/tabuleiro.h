#pragma once
#include "incudes.h"
#include "peca.h"

struct Celula 
{
	Peca peca;
	unsigned short Multiplier; //0 - normal; 1 - dupletra; 2 - triletra; 3 - duppal; 4 - tripal
};

struct Pos
{
	unsigned short x;
	unsigned short y;
};
class Tabuleiro
{
public:
	Tabuleiro(); //tabuleiro vazio, cheio de celulas vazias sem multipliers
	Tabuleiro(string txt); //load game from txt
	virtual ~Tabuleiro();
	vector<vector <Celula>> getTabuleiro();
	bool addPeca(Peca &piece, Pos &position) /*add peca to position, false if overwrite */;
	Celula accessCelula(Pos &position);


private:
	vector<vector <Celula>> TabuleiroCelulas;
};
