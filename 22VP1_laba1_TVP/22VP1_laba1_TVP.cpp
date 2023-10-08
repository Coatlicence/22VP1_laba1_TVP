﻿#include <iostream>

#include "Language.h"
#include "Tree.h"

using namespace std;

struct AlgorithmResult
{
    bool result = 0;

    string word;

    string rules;
};

AlgorithmResult FindInLanguage(string, Language);

int main()
{
    setlocale(LC_ALL, "ru");

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

    next->AddElement("ccccdd", "1");
    

    ///////////////////////////////////

    cout << "Работу выполнили Резяков, Васильев, Князев. Группа 22ВП1" << endl << endl;
    
    cout << "Введите слово: " << endl;

    string word;

    cin >> word;

    auto result = FindInLanguage(word, myLanguage);

    cout << result.rules << endl;
}

AlgorithmResult FindInLanguage(string word, Language lang)
{
    AlgorithmResult result;

    ///

    return result;
}