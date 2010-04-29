#include "incudes.h"
#include "peca.h"


class Baralho
{
public:
	Baralho(); //constroi baralho com string vazia
	Baralho(string filename); //constroi a partir de um txt as pecas uma a uma e randomiza
	Baralho(vector<Peca> pecas); //constroi o baralho atraves de outro vector - load game
	virtual ~Baralho();
	vector<Peca> getBaralho();
	vector<Peca> getFirstNPecas(unsigned short n); //max 7, change to list if necessary
	void addPecas(Peca peca); //add 1 peca
	void addPecas(vector<Peca> pecas); //add 1+ peca
	void shuffleBaralho(); //yeah

private:
	vector <Peca> BaralhoPecas; 
};
