#include "pch.h"
#include "Operator_Or.h"

Operator_Or::Operator_Or(Node& _refNodeLeft, Node& _refNodeRight)
{
	m_ptr_left = &_refNodeLeft;
	m_ptr_right =&_refNodeRight;
}

bool Operator_Or::GetResult()
{
	if (m_ptr_left == nullptr || m_ptr_right == nullptr)
		throw; // todo NullException


	return  m_ptr_left->GetResult() || m_ptr_right->GetResult();
}