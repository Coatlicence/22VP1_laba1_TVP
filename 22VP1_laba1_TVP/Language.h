#pragma once
#include <vector>
#include <string>

#include "AuxiliaryDictionary.h"

using namespace std;

class Rule
{
	string From;

	string To;

	string NumberOfRule;

public:
	Rule(string From, string To, string NumberOfRule) { this->From = From; this->To = To; this->NumberOfRule = NumberOfRule; }

	string GetFrom() { return From; }

	string GetTo() { return To; }
};

class Language
{
	vector<Rule> Rules;

	Dictionary TDictionary;

	AuxiliaryDictionary ADictionary;

public: 
	Language(Dictionary td, AuxiliaryDictionary ad);

	void AddRule(string from, string to, string NumberOfRules);

};

