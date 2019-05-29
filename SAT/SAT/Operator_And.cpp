#include "pch.h"
#include "Operator_And.h"

Operator_And::Operator_And(Node& _refNodeLeft, Node& _refNodeRight)
{
	m_ptr_left = &_refNodeLeft;
	m_ptr_right = &_refNodeRight;
}

bool Operator_And::GetResult()
{
	if (m_ptr_left == nullptr || m_ptr_right == nullptr)
		throw; // todo NullException

	return m_ptr_left->GetResult() && m_ptr_right->GetResult();
}