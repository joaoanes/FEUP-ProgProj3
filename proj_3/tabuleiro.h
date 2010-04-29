#include "incudes.h"
#include "peca.h"

struct Celula 
{
	Peca peca;
	unsigned short multiplier; //0 - normal; 1 - dupletra; 2 - triletra; 3 - duppal; 4 - tripal
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
	void addPeca(Peca peca, Pos position); //add peca to position
	void showTabuleiro();
	bool cmpPeca(Peca peca, Pos position);
	

private:
	vector<vector <Celula>> TabuleiroCelulas;
};