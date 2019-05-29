#include "pch.h"
#include "Parser.h"
#include "Operator_And.h"
#include "Node_Value.h"
#include "Operator_Or.h"
#include "TruthTable.h"
#include "TableCase.h"
#include "Node_Not.h"

void Parser::RemoveUselessParenthesis(std::string& _sRef)
{
	if (ContainsUselessParenthesis(_sRef))
	{
		_sRef.erase(_sRef.size() - 1);
		_sRef.erase(0, 1);
	}
}

bool Parser::ContainsUselessParenthesis(std::string& _sRef)
{
	int count = 0;
	int parenthesis_index = 0;
	for (char c : _sRef)
	{
		if (c == '(')
			parenthesis_index++;

		if (c == ')')
			parenthesis_index--;

		if (count > 0 && parenthesis_index == 0 && count == _sRef.size() - 1)
			return true;
		else if (parenthesis_index == 0)
			return false;
		count++;
	}
	return false;
}

Parser::Parser(std::string _sExpression)
{
}

Node* Parser::Parse(std::string _s)
{
	RemoveUselessParenthesis(_s);
	if (IsOnlyLetter(_s))
	{
		// create litteral 
		return new Node_Value(_s);
	}
	int i = GetLessOperatorIndex(_s);


	Node *LeftValue = nullptr;
	Node *RightValue = nullptr;
	if (!_s.empty() && _s != "!" )
	{
		LeftValue = Parse(_s.substr(0, i));
		RightValue = Parse(_s.substr(i + 1, _s.size() - 1));
	}


	switch (_s[i])
	{

	case '.':
		return new Operator_And(*LeftValue, *RightValue);

	case '+':
		return new Operator_Or(*LeftValue, *RightValue);

	case '!':
		return new Node_Not(*RightValue);
	}
}

bool Parser::IsOnlyLetter(std::string _s)
{
	if (_s.empty())
		return false;

	for (char c : _s)
	{
		if (c == '+' | c == '.' | c == '!')
			return false;
	}
	return true;
}

int Parser::GetLessOperatorIndex(std::string _s)
{
	int less_index = 0;
	int parenthesis_index = 0, min_parenthesis_index = INT32_MAX;
	int index = 0;
	for (char c : _s)
	{
		if (c == '(')
			parenthesis_index++;
		if (c == ')')
			parenthesis_index--;

		if (c == '+' && min_parenthesis_index > parenthesis_index)
		{
			min_parenthesis_index = parenthesis_index;
			less_index = index;
		}

		else if (c == '.' && min_parenthesis_index > parenthesis_index)
		{
			min_parenthesis_index = parenthesis_index;
			less_index = index;
		}

		else if (c == '!' && min_parenthesis_index > parenthesis_index)
		{
			min_parenthesis_index = parenthesis_index;
			less_index = index;
		}
		index++;
	}

	return less_index;
}
