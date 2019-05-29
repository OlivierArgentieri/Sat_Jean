#pragma once
#include <string>
#include "Node.h"
#include <vector>
#include "Node_Value.h"


class Parser
{
private:
	std::vector<Node*> m_nodes_;


	void RemoveUselessParenthesis(std::string& _sRef);
	bool ContainsUselessParenthesis(std::string& _sRef);
	int GetLessOperatorIndex(std::string _s);

	bool IsOnlyLetter(std::string _s);

public:
	Parser();
	~Parser();
	Node* Parse(std::string _s);
};