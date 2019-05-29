#include "pch.h"
#include "Parser.h"
#include "Operator_And.h"
#include "Node_Value.h"
#include "Operator_Or.h"
#include "TruthTable.h"
#include "TableCase.h"

void Parser::RemoveUselessParenthesis(std::string& _sRef)
{
	if (ContainsUselessParenthesis(_sRef))
	{
		_sRef.erase(_sRef.size() - 1);
		_sRef.erase(0,1);
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
	m_expression_ = _sExpression;
	m_working_string_ = _sExpression;
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


	
	Node *LeftValue = Parse(_s.substr(0, i));
	Node *RightValue = Parse(_s.substr(i+1, _s.size() - 1));

	switch (_s[i])
	{

	case '.':
		return new Operator_And(*LeftValue, *RightValue);

	case '+':
		return new Operator_Or(*LeftValue, *RightValue);

	case '!':
		break;

	}




	//SortOperators();

	//Node *head = CreateTree();

	//TruthTable *t = new TruthTable(head);

	//t->Display();
	return nullptr;
}

bool Parser::IsOnlyLetter(std::string _s)
{
	for(char c : _s)
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

void Parser::SortOperators()
{
	int parenthesis_index = 0;
	int index = 0;
	for (char c : m_working_string_)
	{
		if (c == '(')
			parenthesis_index++;
		if (c == ')')
			parenthesis_index--;

		if (c == '+' || c == '.' || c == '!')
		{
			OperatorWithValue opv;
			opv.Operator = c;

			OperatorByParenthesis op;
			op.m_operator_ = opv;
			op.m_nb_parenthesis_ = parenthesis_index;
			m_operator_by_parentheses_.push_back(op);
		}
		index++;
	}
}

Node* Parser::CreateTree()
{
	Node_Value *A = new Node_Value("A");
	Node_Value *B = new  Node_Value("B");
	Node_Value *C = new Node_Value("C");


	Operator_And *child = new Operator_And(*A, *B);
	Operator_Or *head = new Operator_Or(*child, *C);


	TableCase::GetInstance()->CreateTable();

	return head;
}

int Parser::GetMinParenthesisIndex()
{
	int min_index = INT32_MIN;

	for (OperatorByParenthesis op : m_operator_by_parentheses_)
	{
		if (min_index > op.m_nb_parenthesis_)
			min_index = op.m_nb_parenthesis_;
	}
	return min_index;
}