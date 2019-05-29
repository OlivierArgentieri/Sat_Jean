#pragma once
#include <string>
#include "Node.h"

class Parser
{
private:
	std::string m_expression_;
	std::string m_working_string_;

	void RemoveUselessParenthesis();
	bool ContainsUselessParenthesis();
	int GetLessOperatorIndex();

public:
	Parser(std::string _sExpression);
	Node& Parse();




};
