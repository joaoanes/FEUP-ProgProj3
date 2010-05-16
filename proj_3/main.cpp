#include "incudes.h"
#include "jogo.h"
const string DICIONARIO_FILENAME = "dicionario.txt";
const string DECK_FILENAME = "pecas.txt";
const string BOARD_FILENAME = "tabuleiro.txt";



int main()
{
	Jogo game(1);
	game.startMenu();
	cout << "Bye!";
	system("pause");
	game.~Jogo();
	return 0;
}