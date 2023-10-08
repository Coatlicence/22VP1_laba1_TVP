#include <iostream>

#include "Language.h"
#include "Tree.h"

int main()
{
    Dictionary terminal;
    terminal.AddSymbol("c");
    terminal.AddSymbol("d");

    AuxiliaryDictionary auxiliary;
    auxiliary.AddSymbol("I");
    auxiliary.SetRootSymbol("I");

    Language myLanguage(terminal, auxiliary);
    myLanguage.AddRule("I", "ccd", "1");
    myLanguage.AddRule("I", "ccId", "2");

    Tree t;

    auto root = t.RootElement;

    root->AddElement("ccd", "1");
    root->AddElement("ccId", "2");
    
    auto next = root->NextElements[1];

    next.AddElement("ccccdd", "1");
}

