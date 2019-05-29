#pragma once
#include "Node.h"

class Node_Not : Node
{
private :
	Node* m_ptr_node_bottom;

public:
	Node_Not();
	bool GetResult() override;
	void AddBottom(Node& _refNode);


};