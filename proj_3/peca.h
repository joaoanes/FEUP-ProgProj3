#pragma once
#include "incudes.h"

class Peca
{
public:
	Peca();
	Peca(char letra, unsigned short punt);
	virtual ~Peca();
	void setLetter(char ch);
	void setPunt(unsigned short pnt);
	char getLetter() const;
	unsigned short getPunt() const;
	bool const operator==(const Peca& pc);
	bool const operator!=(const Peca& pc);

private:
	char PecaLetra;
	unsigned short PecaPontuacao;
};