#pragma once
#include <vector>
#include <string>

#include "AuxiliaryDictionary.h"

using namespace std;

class Rule
{
	string From;

	string To;

	string NumOfRule;

public:
	Rule(string From, string To, string NumOfRule) 
	{
		this->From = From; 
		this->To = To; 
		this->NumOfRule = NumOfRule; 
	}

	string GetFrom() { return From; }

	string GetTo() { return To; }

	string GetNumOfRule() { return NumOfRule; }
};

class Language
{
	vector<Rule> Rules;

	Dictionary* TDictionary;

	AuxiliaryDictionary* ADictionary;

public: 
	Language(Dictionary* td, AuxiliaryDictionary* ad);

	void AddRule(string from, string to, string NumOfRule);

	vector<Rule> GetRules();

	vector<Rule> GetRules(string FromSymbol);

	AuxiliaryDictionary GetAuxiliaryDictionary();
};

