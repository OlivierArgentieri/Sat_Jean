#include "pch.h"
#include "Operator_Or.h"

bool Operator_Or::GetResult()
{
	if (m_ptr_left == nullptr || m_ptr_right == nullptr)
		throw; // todo NullException
	
	return  m_ptr_left->GetResult() || m_ptr_right->GetResult();
}
