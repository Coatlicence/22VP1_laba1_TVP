#include "Dictionary.h"

Dictionary::Dictionary() { }

void Dictionary::AddSymbol(string symbol)
{
    if (symbol.size() != 1) throw string("this is not a symbol");

    if (HasSymbol(symbol)) return;

    Symbols.push_back(symbol);
}

bool Dictionary::HasSymbol(string symbol)
{
    for (int i = 0; i < Symbols.size(); i++)
    {
        if (symbol == Symbols[i]) return true;
    }
    return false;
}
