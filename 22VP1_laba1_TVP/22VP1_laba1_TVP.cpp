#include <iostream>

#include "Language.h"

int main()
{
    Dictionary terminal;
    terminal.AddSymbol("c");
    terminal.AddSymbol("d");

    AuxiliaryDictionary auxiliary;
    auxiliary.AddSymbol("I");
    auxiliary.SetRootSymbol("I");

    Language myLanguage(terminal, auxiliary);
    myLanguage.AddRule("I", "ccd");
    myLanguage.AddRule("I", "ccId");

    
}

