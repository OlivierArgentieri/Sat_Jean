#include "pch.h"
#include "TruthTable.h"
#include <iostream>
#include "TableCase.h"

TruthTable::TruthTable(Node* _ref_head)
{
	auto instance = TableCase::GetInstance();

	for (int i =0; i<instance->GetNbPossibility(); i++)
	{
		AddValue(_ref_head->GetResult());
		instance->NextCols();
	}
}


void TruthTable::Display()
{
	std::cout << std::endl << "[TRUTH TABLE]" << std::endl;
	WhatIsThis();
	
	for(bool b : m_values_)
	{
		std::cout << b << " ";
	}

	std::cout <<std::endl << std::endl;
}

void TruthTable::AddValue(bool _bResult)
{
	m_values_.push_back(_bResult);
}

void TruthTable::WhatIsThis()
{
	if(IsTautology())
		std::cout << " -> Tautology" << std::endl;
	else if(IsSatisfaisable())
		std::cout << " -> Satisfaisable" << std::endl;
	else
		std::cout << " -> Normal" << std::endl;
}

bool TruthTable::IsTautology()
{
	for (bool b : m_values_)
	{
		if (!b)
			return false;
	}
	return true;
}

bool TruthTable::IsSatisfaisable()
{
	for (bool b : m_values_)
	{
		if (b)
			return false;
	}
	return true;
}