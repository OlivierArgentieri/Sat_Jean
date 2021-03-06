#pragma once
#include <string>
#include "Node.h"

class Node_Value : public Node
{
private:
	std::string m_string_;
public:
	Node_Value(std::string _sKey);
	Node_Value(const Node_Value& _ref);
	bool GetResult() override;
};