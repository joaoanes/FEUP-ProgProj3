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
char Peca::getLetter() const
{
	return PecaLetra;
}
unsigned short Peca::getPunt() const
{
	return PecaPontuacao;
}
bool const Peca::operator==(const Peca& pc)
{
	return ((PecaLetra == 
		pc.getLetter()) && 
		(PecaPontuacao == 
		pc.getPunt()));
}

bool const Peca::operator!=(const Peca& pc)
{
	return !(operator==(pc));
}