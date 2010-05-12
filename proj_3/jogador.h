#pragma once
#include "incudes.h"
#include "peca.h"

class Jogador
{
public:
	Jogador();
	Jogador(string nome, unsigned short punt, vector<Peca> mao);//load game
	virtual ~Jogador();
	string getName(); 
	unsigned short getPunt();
	vector<Peca> getHand();
	void setName(string name);
	void setPunt(unsigned short pnt); 
	bool removePeca(Peca peca); //falso se peca nao existe
	bool removePeca( vector<Peca> pecas );
	void addPeca(Peca peca);
	bool inHand(Peca peca); //check if 1 peca is in hand
	bool inHand(vector<Peca> pecas); //check if all pecas of vec pecas are in hand, false if not


private:
	string JogadorNome;
	unsigned short JogadorPontuacao;
	vector<Peca> JogadorMao;
};
