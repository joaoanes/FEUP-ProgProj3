#include "jogador.h"


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
void Jogador::setScore(unsigned short pnt)
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