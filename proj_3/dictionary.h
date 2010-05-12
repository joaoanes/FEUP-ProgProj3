#pragma once
#include "incudes.h"
using namespace tr1;

class Dictionary
{
public:
	Dictionary();
	Dictionary(string &filename);
	virtual ~Dictionary();
	void setDictionary(set<string> &dic);
	set<string> getDictionary();
	bool searchDictionary(string &word);
private:
	set<string> DictionaryContent;
};
