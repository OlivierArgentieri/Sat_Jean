
#include "pch.h"
#include "Node_Not.h"

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