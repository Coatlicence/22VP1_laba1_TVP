#include "Language.h"

Language::Language(Dictionary td, AuxiliaryDictionary ad)
{
	auto TerminalSymbols = td.GetSymbols();
	auto AuxiliarySymbols = ad.GetSymbols();

	for (int i = 0; i < TerminalSymbols.size(); i++)
	{
		string tsymbol = TerminalSymbols[i];

		for (int j = 0; j < AuxiliarySymbols.size(); j++)
		{
			string asymbol = AuxiliarySymbols[j];

			if (tsymbol == asymbol) 
				throw string("TerminalDictionary has same symbol on AuxiliaryDictionary: " + tsymbol);
		}
	}

	TDictionary = td;
	ADictionary = ad;
}

void Language::AddRule(string from, string to)
{
	if (!ADictionary.HasSymbol(from)) 
		throw string("Auxiliary Dictionary doesnt have this symbol: " + from);

	for (char c : to) 
	{
		if ((!ADictionary.HasSymbol(string(1, c))) && (!TDictionary.HasSymbol(string(1, c))))
			throw string("ADictionary and TDictionary doesnt have this symbol: " + c);
	}

	Rules.push_back(Rule(from, to));
}
