#pragma once
#include "incudes.h"

class Dictionary
{
public:
	Dictionary();
	Dictionary(string filename);
	virtual ~Dictionary();
	void setDictionary(set<string> &dic);
	set<string> getDictionary();
	bool searchDictionary(string &word);
	void buildDictionary(string filename);
private:
	set<string> DictionaryContent;
};
