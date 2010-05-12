#pragma once
#include "incudes.h"
#include "tabuleiro.h"
#include "highscores.h"
#include "jogador.h"
#include "dictionary.h"
#include "baralho.h"
#define ALPHABET_FILENAME

class Jogo
{
public:
	Jogo();
	Jogo(string txt); //load game
	Jogo(unsigned short ngame, Jogador player1, Jogador player2, Tabuleiro board, Dictionary dic, unsigned short handsize);
	virtual ~Jogo();

	void start();
	void setGameIndex(unsigned short ngame);
	void setJogador1(Jogador player1);
	void saveGame(string txt); //save game
	void loadGame(string txt);
	void showHighScores();
	void setJogador2 (Jogador player2);
	void setTabuleiro(Tabuleiro board);
	void setDictionary(Dictionary dic);
	void setHandSize(unsigned short num);
	unsigned short getGameIndex();
	Jogador getJogador1();
	Jogador getJogador2();
	Tabuleiro getTabuleiro();
	Dictionary getDictionary();
	unsigned short getHandSize();
	vector<Peca> neededPecaForWord(string word, Pos position, char Orientation);
	int handleChoice(int lower, int highernotinclusive) /*o maior numero nao e incluido para podermos usar vector::size() sem ter que decrementar o resultado */ /*Esta funcao aje mais como uma subrotina, tratando de todas as operacoes que envolvam escolhas numericas */;
	string stringisizer(int i) /*int -> string */;
	int intisizer(string str) /*string -> int */;
	bool stringIsNumber(string& victim) /*Verifica se certa string pode representar um numero literal */;
	void startMenu();
private:
	unsigned short JogoIndex;
	unsigned short JogoHandSize;
	Jogador JogoJogador1;
	Jogador JogoJogador2;
	Tabuleiro JogoTabuleiro;
	Dictionary JogoDicionario;
};
