#include "peca.h"

Peca::Peca()
{

}
Peca::Peca(char letra, unsigned short punt)
{
	PecaLetra = letra;
	PecaPontuacao = punt;
}
Peca::~Peca()
{

}
void Peca::setLetter(char ch)
{
	PecaLetra = ch;
}

void Peca::setPunt(unsigned short pnt)
{
	PecaPontuacao = pnt;
}
char Peca::getLetter()
{
	return PecaLetra;
}
unsigned short Peca::getPunt()
{
	return PecaPontuacao;
}
bool Peca::operator==(const Peca& pc)
{
	return ((PecaLetra == 
		pc.getLetter()) && 
		(PecaPontuacao == 
		pc.getPunt()));
}