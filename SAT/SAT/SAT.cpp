// SAT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "TableCase.h"
#include "Parser.h"
#include "TruthTable.h"
#include <iostream>

int main()
{
	std::string input;

	std::cout << "Expression : " << std::endl;
	std::cin >> input;

	Parser *p = new Parser();
	Node* t = p->Parse(input);

	TableCase::GetInstance()->CreateTable();
	TruthTable *test = new TruthTable(t);
	
	test->Display();
	TableCase::GetInstance()->Display();

	delete p;
	delete test;
}