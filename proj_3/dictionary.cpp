#include "dictionary.h"
#include <ctime>


Dictionary::Dictionary()
{
}

Dictionary::Dictionary(string filename)
{
	ifstream file;
	file.open(filename.c_str());
	assert (file.is_open());
		cout << "Loading dicionario";
		time_t start = time(NULL);
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
		time_t end = time(NULL);
		cout << "Loading done in " << difftime(end, start) << " seconds.\n";
}


Dictionary::~Dictionary()
{
}

void Dictionary::buildDictionary(string filename)
{
	ifstream file;
	file.open(filename.c_str());
	assert (file.is_open());
	cout << "Loading dicionario";
	time_t start = time(NULL);
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
	time_t end = time(NULL);
	cout << "Loading done in " << difftime(end, start) << " seconds.\n";
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