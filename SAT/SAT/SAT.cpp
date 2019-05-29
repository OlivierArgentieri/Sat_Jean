// SAT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "TableCase.h"
#include "Parser.h"

int main()
{
	TableCase::GetInstance()->AddRow("A");
	TableCase::GetInstance()->AddRow("B");
	TableCase::GetInstance()->AddRow("C");
	TableCase::GetInstance()->AddRow("D");
	TableCase::GetInstance()->AddRow("E");

	TableCase::GetInstance()->CreateTable();

	TableCase::GetInstance()->Display();


	Parser *p = new Parser("a.b+c");
	
}
