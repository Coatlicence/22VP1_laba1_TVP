#pragma once
#include <vector>
#include <string>

#include "AuxiliaryDictionary.h"

using namespace std;

class Rule
{
	string From;

	string To;

public:
	Rule(string From, string To) { this->From = From; this->To = To; }

	string GetFrom() { return From; }

	string GetTo() { return To; }

};

class Language
{
	vector<Rule> Rules;

	Dictionary* TDictionary;

	AuxiliaryDictionary* ADictionary;

public: 
	Language(Dictionary* td, AuxiliaryDictionary* ad);

	void AddRule(string from, string to);

	vector<Rule> GetRules();

	vector<Rule> GetRules(string FromSymbol);

	AuxiliaryDictionary GetAuxiliaryDictionary();
};

