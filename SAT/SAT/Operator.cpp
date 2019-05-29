#include "pch.h"
#include "Operator.h"

void Operator::AddNodeLeft(Node& _refNodeLeft)
{
	m_ptr_left = &_refNodeLeft;
}

void Operator::AddNodeRight(Node& _refNodeRight)
{
	m_ptr_right = &_refNodeRight;
}
