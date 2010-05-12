#pragma once
#include "incudes.h"

struct Score  
{
	string ScoreNome;
	unsigned int ScorePunt;
};

class Highscores
{
private:
	vector<Score> HighscoresTable;
	size_t HighscoresLength;
public:
	Highscores();
	Highscores(vector<Score> &highscores, unsigned int &siez);
	virtual ~Highscores();
	bool addScore(Score score); //falso se nao entrar no highscore, verdadeiro se entrar no sitio certo
	vector<Score> getHighscores(); //devolve o vector HighscoresTable

};
