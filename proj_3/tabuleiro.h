#include "incudes.h"

struct Celula 
{
	Peca peca;
	char multiplier;
};

struct Pos
{
	short x;
	short y;
};

class Tabuleiro
{
public:
	Tabuleiro();
	Tabuleiro(string txt);
	virtual ~Tabuleiro();
	void addPeca(Peca peca, Pos position);
	void showTabuleiro();

private:
	vector<vector <Celula> > TabuleiroCelulas
};