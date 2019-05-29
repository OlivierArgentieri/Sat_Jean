#pragma once
#include "Operator.h"

class Operator_Or : public Operator
{
private:


public:
	Operator_Or(Node& _refNodeLeft, Node& _refNodeRight);
	bool GetResult() override;

};
