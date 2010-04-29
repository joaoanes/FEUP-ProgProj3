#include "incudes.h"

class Jogo
{
public:
	Jogo();
	Jogo(unsigned short ngame, Jogador player1, Jogador player2, Tabuleiro board, set<string> dictionary);
	Jogo(string txt); //load game
	~Jogo();
	void setGameIndex(unsigned short ngame);
	void setJogador1(Jogador player1);
	void setJogador2 (Jogador player2);
	void setTabuleiro(Tabuleiro board);
	void setDictionary(set<string> dictionary);
	unsigned short getGameIndex();
	Jogador getJogador1();
	Jogador getJogador2();
	Tabuleiro getTabuleiro();
	set<string> getDictionary();
	bool WordInDictionary(string word,const set<string>& dictionary);
	vector<Peca> neededPecaForWord(string word, Pos position, char Orientation);
	


private:
	unsigned short JogoIndex;
	Jogador JogoJogador1;
	Jogador JogoJogador2;
	Tabuleiro JogoTabuleiro;
	set<string> JogoDicionario;
};