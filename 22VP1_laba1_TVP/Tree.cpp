#include "Tree.h"

Tree::TreeElement::TreeElement(string word, string rules)
{
	this->word = word;

	this->rules = rules;
}

void Tree::TreeElement::AddElement(TreeElement* el)
{
	NextElements.push_back(el);
}

void Tree::TreeElement::AddElement(string word, string rules)
{
	Tree::TreeElement* el = new Tree::TreeElement(word, rules);

	NextElements.push_back(el);
}

Tree::Tree(string word, string rules)
{
	RootElement = new Tree::TreeElement(word, rules);
}