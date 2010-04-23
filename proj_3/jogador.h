#include "incudes.h"

class Jogador
{
public:
	string getName();
	unsigned short getPunt();
	vector<Peca> getHand();
	string setName(string name);
	unsigned short setScore(unsigned short pnt);

private:
	string JogadorNome;
	unsigned short JogadorPontuacao;
	vector<Peca> JogadorMao;
};