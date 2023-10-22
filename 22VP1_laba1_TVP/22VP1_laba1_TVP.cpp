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
string GetFirstAuxiliariSymbol(string, AuxiliaryDictionary);
string ApplyRule(string, Rule);
Tree BuildTree(Language);
void insert(Language lang, Tree::TreeElement* from, int maxCounter);

int main()
{
    setlocale(LC_ALL, "ru");

    Dictionary terminal;
    terminal.AddSymbol("c");
    terminal.AddSymbol("d");

    AuxiliaryDictionary auxiliary;
    auxiliary.AddSymbol("I");
    auxiliary.SetRootSymbol("I");
    auxiliary.AddSymbol("A");

    Language myLanguage(terminal, auxiliary);
    myLanguage.AddRule("I", "cdcc", "1");
    myLanguage.AddRule("I", "cAdcc", "2");
    myLanguage.AddRule("A", "Ad", "3");
    myLanguage.AddRule("A", "d", "4");
    
    /*
    Tree t;


    BuildTree(myLanguage);



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

Tree BuildTree(Language lang)
{
    int maxCounter = 10;

    Tree tree(auxiliary->GetRootSymbol(), "-");

    insert(lang, tree.RootElement, maxCounter);

    return tree;
}

void insert(Language lang, Tree::TreeElement* from, int maxCounter)
{
    if (maxCounter <= 0) return;

    auto rules = lang.GetRules(GetFirstAuxiliariSymbol(from->word, lang.GetAuxiliaryDictionary()));

    if (rules.size() <= 0) return;

    for (int i = 0; i < rules.size(); i++)
    {
        Tree::TreeElement* el = new Tree::TreeElement(ApplyRule(from->word, rules[i]), "1");

        from->AddElement(el);

        insert(lang, el, --maxCounter);
    }
}

string GetFirstAuxiliariSymbol(string word, AuxiliaryDictionary ad)
{
    for (char c : word)
    {
        for (string symbol : ad.GetSymbols())
        {
            if (string(1, c) == symbol) return string(1, c);
        }
    }

    return "";
}

string ApplyRule(string word, Rule rule)
{
    string newword = word;

    string fromsymbol = rule.GetFrom();

    int pos = newword.find(fromsymbol);

    newword.erase(pos, fromsymbol.size());
    newword.insert(pos, rule.GetTo());

    return newword;
}