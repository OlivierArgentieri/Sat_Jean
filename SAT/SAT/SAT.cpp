// SAT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "TableCase.h"
#include "Parser.h"

int main()
{
	Parser *p = new Parser("a.(b+c)");
	p->Parse();

	TableCase::GetInstance()->Display();
}