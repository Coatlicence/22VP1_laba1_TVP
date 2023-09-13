#pragma once

#include "Dictionary.h"

class AuxiliaryDictionary : public Dictionary
{
	string RootSymbol;

public:
	AuxiliaryDictionary();

	void SetRootSymbol(string NewRootSymbol);
};

