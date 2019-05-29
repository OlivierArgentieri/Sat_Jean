#include "pch.h"
#include "Operator_And.h"

bool Operator_And::GetResult()
{
	if (m_ptr_left == nullptr || m_ptr_right == nullptr)
		throw; // todo NullException

	return m_ptr_left->GetResult() && m_ptr_right->GetResult();
}
