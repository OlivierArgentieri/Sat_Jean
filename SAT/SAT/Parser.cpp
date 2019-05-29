#include "pch.h"
#include "Parser.h"

void Parser::RemoveUselessParenthesis()
{
	if (ContainsUselessParenthesis())
	{
		m_working_string_.erase(0);
		m_working_string_.erase(m_working_string_.size() - 1);
	}
}


bool Parser::ContainsUselessParenthesis()
{
	int count = 0;
	int parenthesis_index = 0;
	for (char c : m_expression_)
	{
		if (c == '(')
			parenthesis_index++;

		if (c == ')')
			parenthesis_index--;

		if (parenthesis_index == 0 && count == m_expression_.size() - 1)
			return true;
		else if (parenthesis_index == 0)
			return false;
		count++;
	}
	return false;
}

Parser::Parser(std::string _sExpression)
{
	m_expression_ = _sExpression;
	m_working_string_ = _sExpression;
}

int Parser::GetLessOperatorIndex()
{
	int less_index = 0;
	int parenthesis_index = 0, min_parenthesis_index = INT32_MAX;
	int index = 0;
	for (char c : m_working_string_)
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