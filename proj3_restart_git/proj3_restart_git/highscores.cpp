#include "highscores.h"


Highscores::Highscores()
{
}

Highscores::Highscores(vector<Score> &highscores, unsigned int &siez)
{
	HighscoresTable = highscores;
	HighscoresLength = siez;
}

Highscores::~Highscores()
{

}
bool Highscores::addScore(Score score) //falso se nao entrar no highscore, verdadeiro se entrar no sitio certo
{
	vector<Score>::iterator ptr;
	for (ptr = HighscoresTable.begin(); ((ptr != HighscoresTable.end()) || (score.ScorePunt >= ptr->ScorePunt)); ++ptr);
	if (ptr == HighscoresTable.end())
		return false;
	HighscoresTable.insert(ptr, score);
	while (HighscoresTable.size() > HighscoresLength)
		HighscoresTable.pop_back();
	return true;
}
vector<Score> Highscores::getHighscores() //devolve o vector HighscoresTable
{
	return HighscoresTable;
}
