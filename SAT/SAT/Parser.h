#pragma once
#include <string>
#include "Node.h"
#include <vector>
#include "Node_Value.h"

struct OperatorWithValue
{
	std::string LeftValue;
	std::string RightValue;
	char Operator;

};

struct OperatorByParenthesis
{
	OperatorWithValue m_operator_;
	int m_nb_parenthesis_;
};

class Parser
{
private:
	std::vector<OperatorByParenthesis> m_operator_by_parentheses_;
	std::vector<Node_Value> m_monolitteral_;

	std::string m_expression_;
	std::string m_working_string_;

	Node* m_head_;

	void RemoveUselessParenthesis(std::string& _sRef);
	bool ContainsUselessParenthesis(std::string& _sRef);
	int GetLessOperatorIndex(std::string _s);


	void SortOperators();
	Node* CreateTree();
	int GetMinParenthesisIndex();
public:
	Parser(std::string _sExpression);
	Node* Parse(std::string _s);
	bool IsOnlyLetter(std::string _s);
};
