#pragma once

#include <vector>
#include <string>

using std::vector;
using std::string;

class Tree
{
public:
	Tree();

	struct TreeElement
	{
		TreeElement(string word, string rules);

		string word;

		string rules;

		vector<TreeElement*> NextElements;

		void AddElement(TreeElement*);

		void AddElement(string word, string rules);
	};

	TreeElement* RootElement = NULL;
};