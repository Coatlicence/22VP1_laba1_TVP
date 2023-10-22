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


Dictionary* terminal = new Dictionary();
AuxiliaryDictionary* auxiliary = new AuxiliaryDictionary();
Language myLanguage(terminal, auxiliary);


int main()
{
    setlocale(LC_ALL, "ru");

    terminal->AddSymbol("c");
    terminal->AddSymbol("d");

    auxiliary->AddSymbol("I");
    auxiliary->SetRootSymbol("I");
    auxiliary->AddSymbol("A");

    myLanguage.AddRule("I", "cdcc");
    myLanguage.AddRule("I", "cAdcc");
    myLanguage.AddRule("A", "Ad");
    myLanguage.AddRule("A", "d");
    


    BuildTree(myLanguage);



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