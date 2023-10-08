#include <iostream>

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
Dictionary terminal;

    AuxiliaryDictionary auxiliary;

    Language myLanguage(terminal, auxiliary);


int main()
{
    setlocale(LC_ALL, "ru");

    terminal.AddSymbol("c");
    terminal.AddSymbol("d");

    auxiliary.AddSymbol("I");
    auxiliary.SetRootSymbol("I");
    auxiliary.AddSymbol("A");


    myLanguage.AddRule("I", "cdcc", "1");
    myLanguage.AddRule("I", "cAdcc", "2");
    myLanguage.AddRule("A", "Ad", "3");
    myLanguage.AddRule("A", "d", "4");

// Convert(word, rule);
// I by rule 2 -> cAdcc 
// cAdcc by 4 -> cddcc


    /*
    Tree t;

    auto root = t.RootElement;

    root->AddElement("ccd", "1");
    root->AddElement("ccId", "2");
    
    auto next = root->NextElements[1];

    next->AddElement("ccccdd", "1");


    */

    ///////////////////////////////////

    /*
        myLanguage.GetRule("1"); // returns Rule with "I -> cdcc"
    */

    cout << "Работу выполнили Резяков, Васильев, Князев. Группа 22ВП1" << endl << endl;
    
    cout << "Введите слово: " << endl;

    string word;

    cin >> word;

    auto result = FindInLanguage(word, myLanguage);

    cout << result.rules << endl;
}

string Convert(int pos, string word, string rule)
{
    string newword = word;
    
    newword.insert(pos, myLanguage.GetRule(rule).GetTo());

    return newword;
}

Tree BuildTree(Tree::TreeElement* el, string word, string rule) 
{
    static int counter = 0;
    int maxCounter = 100;

    auto symbols = auxiliary.GetSymbols();

    auto rules = myLanguage.GetRules();

    for (int i = 0; i < word.size(); i++)
    {
        auto symbol = word[i]; 

        for (int j = 0; j < symbols.size(); j++)
        {
            if (symbol == symbols[j][0])
            {
                for (int k = 0; k < rules.size(); k++)
                {
                    if (symbol == rules[k].GetFrom()[0])
                    {
                        el->AddElement(Convert(i, word, rules[k].GetNum()), el->rules + rules[i].GetNum());
                        return Tree();
                        //BuildTree();
                    }
                }
            }
        }
    }

    
}

AlgorithmResult FindInLanguage(string word, Language lang)
{
    AlgorithmResult result;

    

    return result;
}