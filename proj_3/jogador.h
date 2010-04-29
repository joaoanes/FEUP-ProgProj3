#include "incudes.h"
#include "peca.h"

class Jogador
{
public:
	Jogador();
	Jogador(string nome, unsigned short punt, vector<Peca> mao);//load game
	string getName(); 
	unsigned short getPunt();
	vector<Peca> getHand();
	void setName(string name);
	void setScore(unsigned short pnt); 
	bool inHand(Peca); //check if 1 peca is in hand
	bool inHand(vector<Peca> pecas); //check if all pecas of vec pecas are in hand, false if not


private:
	string JogadorNome;
	unsigned short JogadorPontuacao;
	vector<Peca> JogadorMao;
};