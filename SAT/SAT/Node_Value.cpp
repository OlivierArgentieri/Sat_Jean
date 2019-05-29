#include "pch.h"
#include <string>
#include "Node_Value.h"
#include "TableCase.h"

Node_Value::Node_Value(std::string _sKey)
{
	m_string_ = _sKey;
	TableCase::GetInstance()->AddRow(_sKey);
}

Node_Value::Node_Value(const Node_Value& _ref)
{
	m_string_ = _ref.m_string_;
	TableCase::GetInstance()->AddRow(_ref.m_string_);
}

bool Node_Value::GetResult()
{
	return TableCase::GetInstance()->GetValue(m_string_);
}
