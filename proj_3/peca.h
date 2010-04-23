#include "incudes.h"

class Peca
{
public:
	void setLetter(char ch);
	void setPunt(unsigned short pnt);
	char getLetter();
	unsigned short getPunt();

private:
	char PecaLetra;
	unsigned short PecaPontuacao;
};