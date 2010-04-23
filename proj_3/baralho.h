#include "includes.h"


class baralho
{
public:
	baralho(string filename); //constroi a partir de um txt as pecas uma a uma e randomiza
	virtual ~baralho();
	vector<Peca> getBaralho();
	vector<Peca> getFirstNPecas(unsigned short n); //max 7, change to list if necessary
	void addPecas(Peca peca);
	void addPecas(vector<Peca> pecas);
	void shuffleBaralho();


private:
	vector<Peca> BaralhoPecas; 
};
