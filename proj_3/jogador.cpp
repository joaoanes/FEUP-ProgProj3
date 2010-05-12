#include "jogador.h"

Jogador::Jogador()
{

}

Jogador::Jogador( string nome, unsigned short punt, vector<Peca> mao )
{
	JogadorNome = nome;
	JogadorPontuacao = punt;
	JogadorMao = mao;
}
Jogador::~Jogador()
{

}

string Jogador::getName()
{
	return JogadorNome;
}
unsigned short Jogador::getPunt()
{
	return JogadorPontuacao;
}
vector<Peca> Jogador::getHand()
{
	return JogadorMao;
}
void Jogador::setName(string name)
{
	JogadorNome = name;
}
void Jogador::setPunt(unsigned short pnt)
{
	JogadorPontuacao = pnt;
}
bool Jogador::inHand(Peca pc) //check if 1 peca is in hand
{
	return (find(JogadorMao.begin(), JogadorMao.end(), pc) != JogadorMao.end());
}
bool Jogador::inHand(vector<Peca> pecas) //check if all pecas of vec pecas are in hand, false if not
{
	bool result = true;
	size_t i = 0;
	while ((i < pecas.size()) && result)
	{
		result = result && inHand(pecas[i]);
		++i;
	}
	return result;
}

bool Jogador::removePeca( Peca peca )
{
	for (vector<Peca>::iterator ite = JogadorMao.begin(); ite != JogadorMao.end(); ++ite)
	{
		if (*ite == peca)
		{
			JogadorMao.erase(ite);
			return true;
		}
	}
	return false;
}


bool Jogador::removePeca( vector<Peca> pecas )
{
	bool check = true;
	vector<Peca>::iterator ptr = pecas.begin();
	while((ptr != pecas.end()) && (check))
	{
		check = check && removePeca(*ptr);
		ptr++;
	}
	return check;
}