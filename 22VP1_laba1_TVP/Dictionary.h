#pragma once

#include <string>
#include <vector>

using namespace std;

class Dictionary
{
protected:
	vector<string> Symbols;

public:
	Dictionary();

	void AddSymbol(string symbol);

	bool HasSymbol(string symbol);

	vector<string> GetSymbols() { return vector<string>(Symbols); }
};

