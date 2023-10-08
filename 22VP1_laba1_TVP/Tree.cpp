#include "Tree.h"

Tree::TreeElement::TreeElement(string word, string rules)
{
	this->word = word;

	this->rules = rules;
}

void Tree::TreeElement::AddElement(TreeElement el)
{
	NextElements.push_back(el);
}

void Tree::TreeElement::AddElement(string word, string rules)
{
	Tree::TreeElement el(word, rules);

	NextElements.push_back(el);
}

Tree::Tree()
{
	RootElement = new TreeElement("I", "0");
}

void Tree::AddElement(TreeElement el, string word, string rule)
{
	el.AddElement(word, rule);
}

