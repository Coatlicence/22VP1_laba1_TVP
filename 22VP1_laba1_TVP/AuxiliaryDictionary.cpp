#include "AuxiliaryDictionary.h"

AuxiliaryDictionary::AuxiliaryDictionary()
{
}

void AuxiliaryDictionary::SetRootSymbol(string NewRootSymbol)
{
	if (HasSymbol(NewRootSymbol))
		RootSymbol = NewRootSymbol;
	else
		throw string("This symbol: " + NewRootSymbol + " doesnt exist on dictionary");
}
