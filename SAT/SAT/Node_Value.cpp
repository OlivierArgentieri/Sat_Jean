#include "pch.h"
#include <string>
#include "Node_Value.h"
#include "TableCase.h"

Node_Value::Node_Value(std::string _sKey)
{
	m_string_ = _sKey;
}

bool Node_Value::GetResult()
{
	TableCase::GetInstance()->GetValue(m_string_);
}