#include "incudes.h"

class Peca
{
public:
	Peca();
	Peca(char letra, unsigned short punt);
	~Peca();
	void setLetter(char ch);
	void setPunt(unsigned short pnt);
	char getLetter();
	unsigned short getPunt();
	bool operator==(const Peca& pc);

private:
	char PecaLetra;
	unsigned short PecaPontuacao;
};