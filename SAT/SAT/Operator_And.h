#pragma once
#include "Operator.h"

class Operator_And : public Operator
{

private:

public:
	Operator_And(Node& _refNodeLeft, Node& _refNodeRight);
	bool GetResult() override;

};
