// SAT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "TableCase.h"
#include "Parser.h"
#include "TruthTable.h"

int main()
{
	Parser *p = new Parser("");
	Node* t = p->Parse("a.(b.c)");

	TableCase::GetInstance()->CreateTable();
	TruthTable *test = new TruthTable(t);
	
	test->Display();
	TableCase::GetInstance()->Display();
}
