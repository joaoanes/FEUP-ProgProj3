#include "baralho.h"


Baralho::Baralho() //constroi baralho com string vazia
{

}
Baralho::Baralho(string filename) //constroi a partir de um txt as pecas uma a uma e randomiza
{
	ifstream fiel;
	fiel.open(filename.c_str());
	if (fiel.is_open())
	{
		char letra;
		unsigned short rep;
		unsigned short punt;

		while (! fiel.eof()) 
		{
			fiel >> letra;
			fiel >> rep;
			fiel >> punt;
			for (unsigned short i = rep; i > 0; ++i)
			{
				Peca temp(letra, punt);
				BaralhoPecas.push_back(temp);
			}
		}
	}
	random_shuffle(BaralhoPecas.begin(), BaralhoPecas.end());
}
Baralho::Baralho(vector<Peca> pecas)
{
	BaralhoPecas = pecas;
}

vector<Peca> Baralho::getBaralho()
{
	return BaralhoPecas;
}
vector<Peca> Baralho::getFirstNPecas(unsigned short n) //_removes_ n pieces and adds them to a temp vector
{
	vector<Peca> temp;
	copy((BaralhoPecas.end()-n), BaralhoPecas.end(), back_inserter(temp));
	BaralhoPecas.erase((BaralhoPecas.end()-n), BaralhoPecas.end());
	return temp;
}
void Baralho::addPecas(Peca peca) //add 1 peca
{
	BaralhoPecas.push_back(peca);
	shuffleBaralho();
}
void Baralho::addPecas(vector<Peca> pecas) //add 1+ peca
{
	copy(pecas.begin(), pecas.end(), back_inserter(BaralhoPecas));
	shuffleBaralho();
}
void Baralho::shuffleBaralho() //yeah
{
	random_shuffle(BaralhoPecas.begin(), BaralhoPecas.end());
}