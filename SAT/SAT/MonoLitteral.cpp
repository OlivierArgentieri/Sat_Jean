#include "pch.h"
#include "MonoLitteral.h"

void MonoLitteral::AddNodeLeft(Node& _refNodeLeft)
{
	m_ptr_left = &_refNodeLeft;
}

void MonoLitteral::AddNodeRight(Node& _refNodeRight)
{
	m_ptr_right = &_refNodeRight;
}
