#pragma once
#include "Node.h"

class Node_Not : public Node
{
private :
	Node* m_ptr_node_bottom;

public:
	Node_Not(Node& _refValue);
	bool GetResult() override;
	void AddBottom(Node& _refNode);
};