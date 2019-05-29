#include "pch.h"
#include "Node_Not.h"

Node_Not::Node_Not(Node& _refValue)
{
	m_ptr_node_bottom = &_refValue;
}

bool Node_Not::GetResult()
{
	if (m_ptr_node_bottom == nullptr)
		throw; // TODO : NullException

	return !m_ptr_node_bottom->GetResult();
}

void Node_Not::AddBottom(Node& _refNode)
{
	m_ptr_node_bottom = &_refNode;
}