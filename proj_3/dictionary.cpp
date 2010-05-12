#include "dictionary.h"

Dictionary::Dictionary()
{
}

Dictionary::Dictionary(string &filename)
{
	set<string> dic;
	ifstream file;
	file.open(filename.c_str());
	if (file.is_open())
	{
		int nWords;
		string word;
		file >> nWords;
		for (int i = 0; i < nWords; ++i)
		{
			file >> word;
			for (size_t i = 0 ; i != word.size(); ++i)
			{
				char* curchar = &word[0];
				for (size_t i = 0; i != word.size(); ++i)
				{
					toupper(*curchar);
					++curchar;
				}
			}
			DictionaryContent.insert(word);
		}
		file.close();
	}
}

Dictionary::~Dictionary()
{
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