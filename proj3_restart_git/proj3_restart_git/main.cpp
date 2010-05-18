#include "incudes.h"
#include "jogo.h"
const string DICIONARIO_FILENAME = "dicionario.txt";
const string DECK_FILENAME = "pecas.txt";
const string BOARD_FILENAME = "tabuleiro.txt";

//E ESTE, SIM

int main()
{
	Jogo game(1,7);
	game.startMenu();
	cout << "Bye!";
	//system("pause");
	exit(0);
	//substituindo por exit(0); termina o jogo imediatamente, nao ha esperas interminaveis e erros de heap no final dessas esperas
	//todo: o que e heap?
}