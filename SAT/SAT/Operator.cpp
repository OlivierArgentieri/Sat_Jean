#include "pch.h"
#include "Operator.h"

Operator::Operator()
{

	m_ptr_left = nullptr;
	m_ptr_right = nullptr;
}

Operator::Operator(const Operator& _ref)
{
	m_ptr_left = _ref.m_ptr_left;
	m_ptr_right= _ref.m_ptr_right;
}
