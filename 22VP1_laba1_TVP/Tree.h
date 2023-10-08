#pragma once

#include <vector>
#include <string>

using std::vector;
using std::string;

class Tree
{
	struct TreeElement
	{
		string word;

		string rules;

		vector<TreeElement> NextElements;
	};

	TreeElement Element;
};