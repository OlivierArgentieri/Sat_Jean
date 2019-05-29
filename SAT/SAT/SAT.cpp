// SAT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "TableCase.h"

int main()
{
	TableCase::GetInstance()->AddRow("A");
	TableCase::GetInstance()->AddRow("B");
	TableCase::GetInstance()->AddRow("C");

	TableCase::GetInstance()->CreateTable();

	TableCase::GetInstance()->Display();
}