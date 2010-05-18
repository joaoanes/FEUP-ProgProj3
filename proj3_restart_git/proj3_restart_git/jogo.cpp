#include "jogo.h"
const string DICIONARIO_FILENAME = "dicionario.txt";
const string DECK_FILENAME = "pecas.txt";
const string BOARD_FILENAME = "tabuleiro.txt";


//Montes, MOOONTES de constuctores redundantes se seguem. Limpam-se apos fazer versao decente do projecto.
Jogo::Jogo()
{
}
Jogo::Jogo(unsigned short index, string txt)
{
	//TODO
}
Jogo::Jogo(unsigned short index)
{
	JogoIndex = index;
}
Jogo::Jogo(unsigned short index, Dictionary &dic, Baralho &deck, Tabuleiro &board)
{
	JogoDicionario = dic;
	JogoIndex = index;
	JogoTabuleiro = board;
	JogoBaralho = deck;
}
Jogo::Jogo(unsigned short index, Jogador &player1, Jogador &player2, Tabuleiro &board, Dictionary &dic, unsigned short &handsize, Baralho &deck )
{
	JogoDicionario = dic;
	JogoJogador1 = player1;
	JogoJogador2 = player2;
	JogoTabuleiro = board;
	JogoIndex = index;
	JogoHandSize = handsize;
}
Jogo::Jogo( unsigned short index, unsigned short handsize )
{
		JogoIndex = index;
		JogoHandSize = handsize;
}
Jogo::~Jogo()
{

}
//STOLEN FROM PROG2
//////////////////////////////////////////////////////////////////////////
int  Jogo::handleChoice(int lower, int highernotinclusive) //o maior numero nao e incluido para podermos usar vector::size() sem ter que decrementar o resultado
//Esta funcao aje mais como uma subrotina, tratando de todas as operacoes que envolvam escolhas numericas
{
	string schoice;
	getline(cin, schoice);
	while (((intisizer(schoice) >= highernotinclusive) || (intisizer(schoice) < lower)) && stringIsNumber(schoice))
		//Este ciclo so se processa caso o que utilizador escreveu for realmente so constituido por algarismos e compara se 
		//esta se encontra entre as opcoes validas e se e uma escolha valida em termos de sintaxe
	{
		cout << "\nA sua escolha encontra-se fora das escolhas disponiveis. ";
		if (lower != (highernotinclusive - 1))
			//Caso exista mais de uma opcao por onde escolher, ele mostra os resultados possiveis
			cout << "Por favor escolha uma opcao de " << lower << " ate " << highernotinclusive-1 << ".\n";
		else 
			//Senao ele mostra o unico resultado possivel
			cout << "So pode escolher " << lower << ".\n";
		getline(cin, schoice);
	}
	//O que pode acontecer tambem e dentro do ciclo while o utilizador colocar algo que nao e um numero, tendo caracteres que nao sao algarismos
	//Nessa situacao o ciclo while termina, e e feita a verificacao neste if, que caso seja valido, tendo "escapado" o while, tem de
	//ser necessariamente um numero valido
	if (stringIsNumber(schoice))
	{
		return intisizer(schoice);
	}
	//caso nao o seja, a funcao e chamada recursivamente ate encontrar uma possivel.
	cout << "\nPor favor escolha so numeros para representar escolhas.\n";
	return handleChoice(lower, highernotinclusive);
}
bool Jogo::stringIsNumber(string& victim)
//Verifica se certa string pode representar um numero literal
{
	for (size_t i = 0; i < victim.size(); ++i)
	{
		char& aye = victim[i]; //define-se uma referencia para a letra a ser correntemente processada
		bool isit = ((aye < 48) || (aye > 57)); //e verifica se cada um e' um algarismo
		if (isit) return false; //se encontrar um char que nao seja um algarismo, a string nao e um numero, logo nao e necessario continuar
	}
	return true;
}
int	 Jogo::intisizer(string str)
//string -> int
{
	int output;
	stringstream sstr;
	sstr << str;
	sstr >> output;
	return output;
}
string Jogo::stringisizer(int i)
//int -> string
{
	stringstream hello;
	string str;	
	hello << i;
	hello >> str;
	return str;
}
//////////////////////////////////////////////////////////////////////////

void Jogo::startMenu()
{
	cout << "1. Novo jogo\n" 
		 << "2. Carregar jogo\n"
		 << "3. Ver melhores pontuacoes\n";
	
		string str;
		int choice = handleChoice(1, 4);
	switch (choice)
	{
	case 1:
		Jogo::start();
		break;
	case 2:
		getline(cin, str);
		Jogo::loadGame(str);
		break;
	case 3:
		Jogo::showHighScores();
		break;
	}
}
void Jogo::setGameIndex( unsigned short ngame )
{
	JogoIndex = ngame;
}
void Jogo::setJogador1( Jogador player1 )
{
	JogoJogador1 = player1;
}
void Jogo::setJogador2( Jogador player2 )
{
	JogoJogador2 = player2;
}
void Jogo::setTabuleiro( Tabuleiro board )
{
	JogoTabuleiro = board;
}
void Jogo::setDictionary( Dictionary dic )
{
	JogoDicionario = dic;
}
void Jogo::setHandSize( unsigned short num )
{
	JogoHandSize = num;
}
unsigned short Jogo::getGameIndex()
{
	return JogoIndex;
}
Jogador Jogo::getJogador1()
{
	return JogoJogador1;
}
Jogador Jogo::getJogador2()
{
	return JogoJogador2;
}
Tabuleiro Jogo::getTabuleiro()
{
	return JogoTabuleiro;
}
Dictionary Jogo::getDictionary()
{
	return JogoDicionario;
}
unsigned short Jogo::getHandSize()
{
	return JogoHandSize;
}

vector<Peca> Jogo::neededPecaForWord( string word, Pos position, char Orientation )
{
	//TODO
	return vector<Peca>(1, Peca());
}

void Jogo::loadGame( string txt )
{
	//TODO
}

void Jogo::showHighScores()
{
	//TODO
}

void Jogo::match(Jogador* curplayer)
{
	//TODO
}

void Jogo::start()
{
	JogoDicionario.buildDictionary(DICIONARIO_FILENAME);
	JogoBaralho.buildBaralho(DECK_FILENAME);
	JogoTabuleiro.buildTabuleiro(BOARD_FILENAME);
	cout << "Por favor indique o nome do primeiro jogador: ";
	string Jogador1Nome;
	getline(cin, Jogador1Nome);
	cout << "Por favor indique o nome do segundo jogador: ";
	string Jogador2Nome;
	getline(cin, Jogador2Nome);
	Jogador ONE(Jogador1Nome, 0, JogoBaralho.getFirstNPecas(JogoHandSize));
	Jogador TWO(Jogador2Nome, 0, JogoBaralho.getFirstNPecas(JogoHandSize));
	JogoJogador1 = ONE;
	JogoJogador2 = TWO;
	srand ((unsigned)time(NULL));
	if ((rand() % 2) == 0)
	{
		cout << "Foi determinado que o primeiro jogador sera o primeiro a jogar.\n";
	}
	else
		cout << "Foi determinado que o segundo jogador sera o primeiro a jogar.\n";
	system("pause");
	


}

Baralho Jogo::getBaralho()
{
	return JogoBaralho;
}

void Jogo::setBaralho(Baralho bar)
{
	JogoBaralho = bar;
}