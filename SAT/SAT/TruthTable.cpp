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