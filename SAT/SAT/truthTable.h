#pragma once
#include <vector>
#include "Node.h"

class TruthTable
{
private:
	std::vector<bool> m_values_;

public:
	TruthTable(Node* _ref_head);
	void Display();
	void AddValue(bool _bResult);
	void WhatIsThis();
	bool IsTautology();
	bool IsSatisfaisable();
};