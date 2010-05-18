#include "dictionary.h"
#include <ctime>
#include <iomanip>


Dictionary::Dictionary()
{
}

Dictionary::Dictionary(string filename)
{
	ifstream file;
	file.open(filename.c_str());
	assert (file.is_open());
		cout << "Loading dicionario";
		time_t start = time(NULL)*1000;
		int nWords;
		string word;
		file >> nWords;
		char* curchar = NULL;
		char lastletter = 'A';
		for (int i = 0; i < nWords; ++i)
		{
			file >> word;
			curchar = &word[0];
			if (toupper(*curchar) != lastletter)
				{
					cout << ".";
					lastletter = toupper(*curchar);
				}
			while(*curchar != NULL)
				*curchar++ = toupper(*curchar);
			DictionaryContent.insert(word);
		}
		file.close();
		cout << "Loading complete.\n";
		time_t end = time(NULL)*1000;
		cout << "Loading done in " << difftime(end, start) << " seconds.\n";
}


Dictionary::~Dictionary()
{
}

void Dictionary::buildDictionary(string filename)
{
	ifstream file;
	file.open(filename.c_str());
	assert (file.is_open()); //assert(bool) crasha o programa com output do sitio onde crashou (ficheiro e linha) para cout, se bool for falso
	cout << "Loading dicionario";
	time_t start = time(NULL);
	int nWords;
	string word;
	file >> nWords;
	char* curchar = NULL; //inicializa o pointer para os caracteres
	char lastletter = 'A';
	for (int i = 0; i < nWords; ++i)
	{
		file >> word;
		curchar = &word[0]; //aponta o apontador para o primeiro caracter da palavra
		if (toupper(*curchar) != lastletter) //verifica se o primeiro caracter e igual ao primeiro caracter da palavra atras
		{
			cout << ".";
			lastletter = toupper(*curchar);
		}
		while(*curchar != NULL) //pensa em assembly. se o apontador chegar ao caracter "0" que termina a string, passa a palavra seguinte
			*curchar++ = toupper(*curchar); //entretanto, faz toupper do caracter
		DictionaryContent.insert(word); //e no fim espeta-o no set
	}
	file.close();
	cout << "Loading complete.\n";
	time_t end = time(NULL);
	cout << "Loading done in " << setprecision(10) << difftime(end, start) << " seconds.\n";
}
void Dictionary::setDictionary(set<string> &dic)
{
	DictionaryContent = dic;
}

set<string> Dictionary::getDictionary()
{
	return DictionaryContent;
}

bool Dictionary::searchDictionary( string &word )
{
		return binary_search(DictionaryContent.begin(),DictionaryContent.end(), word);
}