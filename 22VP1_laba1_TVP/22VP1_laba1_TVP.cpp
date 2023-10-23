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

AlgorithmResult FindInTree(Language lang, Tree::TreeElement*, string);
string GetFirstAuxiliariSymbol(string, AuxiliaryDictionary);
string ApplyRule(string, Rule);
Tree BuildTree(Language, int);
void insert(Language lang, Tree::TreeElement* from, int maxCounter);

int main()
{
    setlocale(LC_ALL, "ru");

    Dictionary* terminal = new Dictionary();
    terminal->AddSymbol("c");
    terminal->AddSymbol("d");

    AuxiliaryDictionary* auxiliary = new AuxiliaryDictionary();
    auxiliary->AddSymbol("I");
    auxiliary->SetRootSymbol("I");
    auxiliary->AddSymbol("A");

    Language myLanguage = Language(terminal, auxiliary);
    myLanguage.AddRule("I", "cdcc", "1");
    myLanguage.AddRule("I", "cAdcc", "2");
    myLanguage.AddRule("A", "Ad", "3");
    myLanguage.AddRule("A", "d", "4");
    
    cout << "Работу выполнили Резяков, Васильев, Князев. Группа 22ВП1" << endl << endl << "Правила:" << endl;

    auto rules = myLanguage.GetRules();

    for (int i = 0; i < rules.size(); i++)
    {
        cout << rules[i].GetFrom() << " -> " << rules[i].GetTo() << endl;
    }
    cout << endl;

    auto tree = BuildTree(myLanguage, 15);    

    bool work = true;
    while (work)
    {
        cout << "Введите слово: ";

        string word;

        cin >> word;

        // Exit from while
        if ((word == "exit")  (word == "выход"))
        {
            work = false;
            
            cout << "Совершен выход из цикла программы" << endl;

            break;
        }
            

        auto result = FindInTree(myLanguage, tree.RootElement, word);

        // Results of work
        if (result.result)
        {
            cout << "Такое слово найдено в заданном языке" << endl;
            cout << "Правила составления слова: " << result.rules << endl;
        }
        else
            cout << "Такого слова нет в заданном языке" << endl;

        cout << result.word << endl << endl;
    }
    

}

AlgorithmResult FindInTree(Language lang, Tree::TreeElement* from, string word)
{
    AlgorithmResult result;

    result.result = false;
    result.word = word;
    result.rules = "";

    if (GetFirstAuxiliariSymbol(word, lang.GetAuxiliaryDictionary()) != "")
    {
        return result;
    }

    if (from == nullptr)
    {
        return result;
    }

    if (from->word == word)
    {
        result.result = true;
        result.rules = from->rules;

        return result;
    }
    
    for (int i = 0; i < from->NextElements.size(); i++)
    {
        auto result = FindInTree(lang, from->NextElements[i], word);

        if (result.result) return result;
    }

    return result;
}

Tree BuildTree(Language lang, int depth)
{
    int maxCounter = depth;

    Tree tree(lang.GetAuxiliaryDictionary().GetRootSymbol(), "-");

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
        Tree::TreeElement* el = new Tree::TreeElement(ApplyRule(from->word, rules[i]), string(from->rules + rules[i].GetNumOfRule()));

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