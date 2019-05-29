#pragma once
#include <string>
#include "Node.h"
#include <vector>

struct OperatorByParenthesis
{
	char m_operator_;
	int m_nb_parenthesis_;
};

class Parser
{
private:
	std::vector<OperatorByParenthesis> m_operator_by_parentheses_;

	std::string m_expression_;
	std::string m_working_string_;

	void RemoveUselessParenthesis();
	bool ContainsUselessParenthesis();
	int GetLessOperatorIndex();


	void SortOperators();
	Node* CreateTree();
	int GetMinParenthesisIndex();
public:
	Parser(std::string _sExpression);
	void Parse();




};
